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

signal = "BSM"
nToys = 0


'''
for key in tfile.GetListOfKeys():
    h = key.ReadObj()
    if h.GetName() != "tree_fit_b":
        continue
    nToys = h.GetEntries()
    #print("Found tree with %i toys." % nToys)
    for l in h.GetListOfBranches():
        #print(l.GetName())
        if "proc_%s" % signal in l.GetName():
            continue
        
        if not l.GetName().startswith("n_exp_final_bin"):
            continue
        print(l.GetName())
        isthere = False
        for ak in allkeys:
            if ak != l.GetName() and ak in l.GetName():
                isthere = True
                break
        if isthere:
            continue

        allkeys.append(l.GetName())
        
        print(l.GetName())
        if l.GetName().endswith("_"):
            continue
        if l.GetName().split("n_exp_final_bin")[-1].split("_proc")[0] not in regions:
            print(l.GetName().split("n_exp_final_bin")[-1].split("_proc")[0])
            regions.append(l.GetName().split("n_exp_final_bin")[-1].split("_proc")[0])
        if l.GetName().split("n_exp_final_bin")[-1].split("proc_")[-1] not in processes:
            processes.append(l.GetName().split("n_exp_final_bin")[-1].split("proc_")[-1])

'''


processes = ['PhotonE0', 'PhotonE1', 'DY', 'GJ0', 'GJ1', 'NonPrompt', 'Top', 'VV', 'VVV', 'WG', 'WJ0', 'WJ1', 'WJ2', 'WJ3', 'WJ4', 'WJ5', 'ZG']
regions = ['VBFG_2016_trigger0', 'VBFG_2017_trigger0', 'VBFG_2017_trigger1', 'VBFG_2018_trigger0', 'VBFG_2018_trigger1']

print(processes)
print(regions)

tt = tfile.Get("tree_fit_b")
nToys = tt.GetEntries()

bins_to_region = {'sr':[1,2,3,4,5,6,13,14,15,16,17,18], 'wj':[7,8,9,19,20,21], 'wg':[10,22], 'gj':[11,23], 'zj':[12,24]}

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
                    if "Photon" not in p:
                        try:
                            val = getattr(tt, 'n_exp_final_bin%s_proc_%s_%i' % (r,p,b))
                            if val > 0.:
                                toy_yield += val
                                #print val, r, p
                        except:
                            pass
                    else:
                        try:
                            val = getattr(tt, 'n_exp_bin%s_proc_%s_%i' % (r,p,b))
                            if val > 0.:
                                toy_yield += val                            
                        except:
                            pass

            bkg_yields[rr+"_"+p].append(toy_yield)
            
bkg_yields = pd.DataFrame.from_dict(bkg_yields)

bkg_yields = bkg_yields[(bkg_yields > 0.).all(1)]

#print(bkg_yields['wg_Top'])

for rr in bins_to_region.iterkeys():
    bkg_yields['%s_WJ'%rr] = bkg_yields['%s_WJ0'%rr] + bkg_yields['%s_WJ1'%rr] + bkg_yields['%s_WJ2'%rr] + bkg_yields['%s_WJ3'%rr] + bkg_yields['%s_WJ4'%rr] + bkg_yields['%s_WJ5'%rr]
    bkg_yields['%s_GJ'%rr] = bkg_yields['%s_GJ0'%rr] + bkg_yields['%s_GJ1'%rr]
    bkg_yields['%s_PhotonE'%rr] = bkg_yields['%s_PhotonE0'%rr] + bkg_yields['%s_PhotonE1'%rr]
    bkg_yields = bkg_yields.drop(['%s_WJ0'%rr,'%s_WJ1'%rr,'%s_WJ2'%rr,'%s_WJ3'%rr,'%s_WJ4'%rr,'%s_WJ5'%rr], axis=1)
    bkg_yields = bkg_yields.drop(['%s_GJ0'%rr,'%s_GJ1'%rr], axis=1)
    bkg_yields = bkg_yields.drop(['%s_PhotonE0'%rr,'%s_PhotonE1'%rr], axis=1)


for rr in bins_to_region.iterkeys():
    bkg_yields['%s_total'%rr] = bkg_yields['%s_PhotonE'%rr] + bkg_yields['%s_DY'%rr] + bkg_yields['%s_GJ'%rr] + bkg_yields['%s_NonPrompt'%rr] + bkg_yields['%s_Top'%rr] + bkg_yields['%s_VV'%rr] + bkg_yields['%s_VVV'%rr] + bkg_yields['%s_WG'%rr] + bkg_yields['%s_WJ'%rr] + bkg_yields['%s_ZG'%rr]

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

summed_processes = ['PhotonE', 'DY', 'GJ', 'NonPrompt', 'Top', 'VV', 'VVV', 'WG', 'WJ', 'ZG', 'total']

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


