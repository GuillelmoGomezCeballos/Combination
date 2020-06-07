#!/usr/bin/env python
import os, time, sys, getopt
import shutil
import json
import glob
import multiprocessing
import datetime
import fileinput
import socket

#grep -e Obs -e Exp log_runFits_monoz|awk '{printf("%f ",$5);if($2=="97.5%:")printf("\n")}'|awk '(NR%2==0){print$0}'
# lll1 (uparticle cross section), lll2 (cross section limits): 16 lines
#paste lll1 lll2|awk '{printf("%10.7f %15.11f %10.7f %10.7f %10.7f %10.7f %10.7f\n",$2*$1,$1,$5*$1,$3*$1,$4*$1,$6*$1,$7*$1)}'
# lll1 (ADD cross section), lll2 (cross section limits): 18 lines
#paste lll1 lll2|awk '{printf("%9.7f %13.11f %9.7f %9.7f %9.7f %9.7f %9.7f\n",$2*$1,$1,$5*$1,$3*$1,$4*$1,$6*$1,$7*$1)}'

def doAnalysis(n):

    print "n = ",n
    print "*********"
    cross_section_Dict = dict()
    with open("add_cross_sections.txt", 'r') as fout:
    	content = fout.read().splitlines()
        for nChan in range(0, len(content)):
    	    theString = content[nChan].split(' ')
	    if(float(theString[1]) != n): continue
            key = theString[0]
            cross_section_Dict.update({key:[theString[2]]})
    #print cross_section_Dict

    cross_section_limits_Dict = dict()
    with open("add_cross_sections_limits.txt", 'r') as fout:
    	content = fout.read().splitlines()
        for nChan in range(0, len(content)):
    	    theString = content[nChan].split(' ')
	    if(float(theString[1]) != n): continue
            key = theString[0]
                                                  #obs          xs           mean         -2sig        -1sig        +1sig        +2sig
            cross_section_limits_Dict.update({key:[theString[2],theString[3],theString[4],theString[5],theString[6],theString[7],theString[8]]})
    #print cross_section_limits_Dict

    obs   = [0,0,0]
    mean  = [0,0,0]
    sigm2 = [0,0,0]
    sigm1 = [0,0,0]
    sigp1 = [0,0,0]
    sigp2 = [0,0,0]
    cross_section_limits_new_Dict = dict()
    for key in sorted(cross_section_Dict):
        left = 1.0
        right = 3.0
        for keyl in cross_section_limits_Dict:
            if(float(keyl) <= float(key) and float(key)- float(keyl) < left): 
	        left =  float(keyl)
 	        obs[0]   = float(cross_section_limits_Dict[keyl][0])
  	        mean[0]  = float(cross_section_limits_Dict[keyl][2]) 
  	        sigm2[0] = float(cross_section_limits_Dict[keyl][3])
  	        sigm1[0] = float(cross_section_limits_Dict[keyl][4]) 
  	        sigp1[0] = float(cross_section_limits_Dict[keyl][5]) 
  	        sigp2[0] = float(cross_section_limits_Dict[keyl][6]) 
            if(float(keyl) >  float(key) and float(keyl)- float(key) < right):
	        right =  float(keyl)
 	        obs[1]   = float(cross_section_limits_Dict[keyl][0])
  	        mean[1]  = float(cross_section_limits_Dict[keyl][2]) 
  	        sigm2[1] = float(cross_section_limits_Dict[keyl][3])
  	        sigm1[1] = float(cross_section_limits_Dict[keyl][4]) 
  	        sigp1[1] = float(cross_section_limits_Dict[keyl][5]) 
  	        sigp2[1] = float(cross_section_limits_Dict[keyl][6]) 
        dist = (float(key)-left)/(right-left)
        obs[2]   = obs[0]   + (obs[1]  -obs[0]  )*dist
        mean[2]  = mean[0]  + (mean[1] -mean[0] )*dist
        sigm2[2] = sigm2[0] + (sigm2[1]-sigm2[0])*dist
        sigm1[2] = sigm1[0] + (sigm1[1]-sigm1[0])*dist
        sigp1[2] = sigp1[0] + (sigp1[1]-sigp1[0])*dist
        sigp2[2] = sigp2[0] + (sigp2[1]-sigp2[0])*dist
        print key,obs[2],cross_section_Dict[key][0],mean[2],sigm2[2],sigm1[2],sigp1[2],sigp2[2]
        cross_section_limits_new_Dict.update({key:[obs[2],cross_section_Dict[key][0],mean[2],sigm2[2],sigm1[2],sigp1[2],sigp2[2]]})

    print "*********"
    for key in sorted(cross_section_limits_new_Dict):
        print '%.1f %.3f %.3f %.3f %.3f %.3f %.3f' % (float(key),
	      float(cross_section_limits_new_Dict[key][0])/float(cross_section_limits_new_Dict[key][1]),
	      float(cross_section_limits_new_Dict[key][2])/float(cross_section_limits_new_Dict[key][1]),
	      float(cross_section_limits_new_Dict[key][3])/float(cross_section_limits_new_Dict[key][1]),
	      float(cross_section_limits_new_Dict[key][4])/float(cross_section_limits_new_Dict[key][1]),
	      float(cross_section_limits_new_Dict[key][5])/float(cross_section_limits_new_Dict[key][1]),
	      float(cross_section_limits_new_Dict[key][6])/float(cross_section_limits_new_Dict[key][1]))
    print "*********"
    left = [30.0,30.0,30.0,30.0,30.0,30.0]
    right = [-30.0,-30.0,-30.0,-30.0,-30.0,-30.0]
    leftmass = [1,1,1,1,1,1]
    rightmass = [3,3,3,3,3,3]
    for key in sorted(cross_section_limits_new_Dict):
        for thenr in 0,1,2,3,4,5,6:
	    if(thenr == 1): continue
	    nr = thenr
	    if(thenr >= 1): nr = thenr - 1
	    obs = float(cross_section_limits_new_Dict[key][thenr])/float(cross_section_limits_new_Dict[key][1])
            if(obs >= 1 and obs-1 < left[nr]-1):
	        left[nr] = obs
	        leftmass[nr] = float(key)
            if(obs < 1 and 1-obs < 1-right[nr]):
	        right[nr] = obs
	        rightmass[nr] = float(key)
    print left,right,leftmass,rightmass
    obsList = []
    for nr in 0,1,5,4,3,2:
        obs = 3
	if(left[nr] != 30):
           dist = (1-left[nr])/(right[nr]-left[nr])
	   obs  = leftmass[nr]  + (rightmass[nr]-leftmass[nr])*dist
	obsList.append(obs)
    print obsList[0],obsList[1],obsList[2],obsList[3],obsList[4],obsList[5]
     
"""
Main
"""
valid = ['dim=','help']

usage =  "Usage: listdir.py --dim=<n>\n"

try:
   opts, args = getopt.getopt(sys.argv[1:], "", valid)
except getopt.GetoptError, ex:
   print usage
   print str(ex)
   sys.exit(1)

n = 2

for opt, arg in opts:
   if opt == "--help":
      print usage
      sys.exit(1)
   if opt == "--dim":
      n = float(arg)

doAnalysis(n)
