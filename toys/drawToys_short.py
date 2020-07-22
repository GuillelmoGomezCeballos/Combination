from __future__ import print_function
from ROOT import TFile, TCanvas, TLegend, TLatex, TColor, gStyle, gPad
from sys import argv
import pandas as pd
import matplotlib.pyplot as plt
import subprocess

bestfit = pd.read_csv("bestfit.txt")
bkg_yields = pd.read_csv("bkg_yields.txt")

bestfits = {}

summed_processes = ['PhotonE', 'DY', 'GJ', 'NonPrompt', 'Top', 'VV', 'VVV', 'WG', 'WJ', 'ZG', 'total']
bins_to_region = {'sr':[1,2,3,4,5,6,13,14,15,16,17,18], 'wj':[7,8,9,19,20,21], 'wg':[10,22], 'gj':[11,23], 'zj':[12,24]}

for rr in bins_to_region.iterkeys():
    for p in summed_processes:
        try:
            bf = bestfit[bestfit['proc'] == p]
            bf = bf[bf['ch'] == rr]
            bestfits[rr+"_"+p] = bf['bfit'].values.tolist()[0]
        except:
            bestfits[rr+"_"+p] = 0

print(bestfits)

for c in bkg_yields.columns:
    fig, ax = plt.subplots()
    bkg_yields.hist(c, ax=ax, facecolor='aquamarine', color='aquamarine', edgecolor='aquamarine')
    ax.set_xlabel('Background yield')
    ax.set_ylabel('Toys')
    plt.text(0.06,0.82,"%s"%c,transform=ax.transAxes,fontsize=18)
    ax.set_title("")
    print(bestfits[c])
    plt.axvline(x=bestfits[c], color='darkmagenta',label='best fit')
    plt.legend()
    fig.savefig('/home/bmaier/public_html/figs/darkg/vbf/toys/%s.png'%c)


