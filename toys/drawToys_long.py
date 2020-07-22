from __future__ import print_function
from ROOT import TFile, TCanvas, TLegend, TLatex, TColor, gStyle, gPad
from sys import argv
import pandas as pd
import matplotlib.pyplot as plt
import subprocess

bestfit = pd.read_csv("bestfit.txt")

fname = argv[1]
tfile = TFile.Open(fname)

regions = []
processes = []
allkeys = []

nToys = 0

processes = ['NonPrompt','Other','QCDSSWW','Signal1','Signal2','Signal3','TVX','WZ','ZZ','qqWW']
regions = ['SSWW_2016', 'SSWW_2017', 'SSWW_2018']

print(processes)
print(regions)

tt = tfile.Get("tree_fit_sb")
nToys = tt.GetEntries()

bins_to_region = {'sr':[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25], 'fake':[26,27,28,29], 'zz':[30,31,32,33], 'wzb':[34,35,36,37], 'wz':[38,39,40,41]}
#bins_to_region = {'sr':[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25]}

bkg_yields = {}

for rr in bins_to_region.iterkeys():
    for p in processes:
        if rr+"_"+p not in bkg_yields:
            bkg_yields[rr+"_"+p] = []        
        for t in range(nToys):
            tt.GetEntry(t)    

            if (t%500==0):
                print("%i / %i" %(t,nToys))
            toy_yield = 0
            for r in regions:#triggers/year
                for b in bins_to_region[rr]:
                    try:
                    	val = getattr(tt, 'n_exp_final_bin%s_proc_%s_%i' % (r,p,b))
                    	if val > 0.:
                    	    toy_yield += val
                    	    #print val, r, p
                    except:
                    	pass

            bkg_yields[rr+"_"+p].append(toy_yield)
            
bkg_yields = pd.DataFrame.from_dict(bkg_yields)

bkg_yields = bkg_yields[(bkg_yields > 0.).all(1)]

#print(bkg_yields['wg_Top'])

for rr in bins_to_region.iterkeys():
    bkg_yields['%s_total'%rr] = bkg_yields['%s_NonPrompt'%rr] + bkg_yields['%s_Other'%rr] + bkg_yields['%s_QCDSSWW'%rr] + bkg_yields['%s_Signal1'%rr] + bkg_yields['%s_Signal2'%rr] + bkg_yields['%s_Signal3'%rr] + bkg_yields['%s_TVX'%rr] + bkg_yields['%s_WZ'%rr] + bkg_yields['%s_ZZ'%rr] + bkg_yields['%s_qqWW'%rr]

print(bkg_yields)

print("Region               stddev")
print(bkg_yields.std(axis = 0, skipna = True))

f1=open('./testfile', 'w+')
print("Region               stddev",file=f1)
print(bkg_yields.std(axis = 0, skipna = True),file=f1)
f1.close()

outp = './testfile2'
out_file = open(outp, "w")

subprocess.call("cat ./testfile | rev | sed 's/ //2g' | sed 's/ /,/' | rev",shell=True,stdout=out_file)
subprocess.call("sed -i '$d' testfile2",shell=True)

bestfits = {}

summed_processes = ['NonPrompt','Other','QCDSSWW','Signal1','Signal2','Signal3','TVX','WZ','ZZ','qqWW', 'total']

for rr in bins_to_region.iterkeys():
    for p in summed_processes:
        try:
            bf = bestfit[bestfit['ch'] == rr]
            bf = bf[bf['proc'] == p]
            bestfits[rr+"_"+p] = bf['bfit'].values.tolist()[0]
        except:
            bestfits[rr+"_"+p] = 0

print(bestfits)

bkg_yields.to_csv("bkg_yields.txt",index=False)

for c in bkg_yields.columns:
    fig, ax = plt.subplots()
    bkg_yields.hist(c, ax=ax, facecolor='aquamarine', color='aquamarine', edgecolor='aquamarine')
    ax.set_xlabel('Background yield')
    ax.set_ylabel('Toys')
    plt.text(0.06,0.82,"%s"%c,transform=ax.transAxes,fontsize=18)
    ax.set_title("")
    plt.axvline(x=bestfits[c], color='darkmagenta',label='best fit')
    plt.legend()
    fig.savefig('/home/ceballos/public_html/toys/%s.png'%c)


