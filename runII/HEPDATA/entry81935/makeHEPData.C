#include <TFile.h>
#include <TSystem.h>
#include <TString.h>
#include <TH1D.h>
#include <TMath.h>
#include <iostream>
#include <fstream>

// nsel == 1 --> cross sections
// nsel == 2 --> mll vs. mjj
// nsel == 3 --> mll
// nsel == 4 --> aQGC limits
// nsel == 5 --> H++ cross section limits
// nsel == 6 --> H++ sH limits
// nsel == 7 --> systematics
// nsel == 8 --> gen to reco efficiency

void makeHEPData(int nsel = 1){

char theOutputName[200];						
char theMainSentence[200];						
int binsToRemove = 0;
TFile *_file0;

if     (nsel == 1) {}
else if(nsel == 2) {_file0 = TFile::Open("histo_full_unroll.root"); binsToRemove = 4;sprintf(theOutputName,"Table2.yaml");sprintf(theMainSentence,"Yields of two dimensional dijet-dilepton mass distribution");}
else if(nsel == 3) {_file0 = TFile::Open("histo_aqgc_sig_mll.root");binsToRemove = 0;sprintf(theOutputName,"Table3.yaml");sprintf(theMainSentence,"Yields of one dimensional dilepton mass distribution");}
else if(nsel == 4) {}
else if(nsel == 5) {}
else if(nsel == 6) {}
else if(nsel == 7) {}
else if(nsel == 8) {}
else return;

if     (nsel == 1){
ofstream newcardShape;
newcardShape.open("Table1.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: LO Prediction}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 4.25 +/- 0.27 fb}\n");
newcardShape << Form("  - {value: 1}\n");
newcardShape << Form("- header: {name: Observation}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 3.83 +/- 0.66 (stat.) +/- 0.35 (syst.) fb}\n");
newcardShape << Form("  - {value: 0.90 +/- 0.22}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Value}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: Fiducial cross section}\n");
newcardShape << Form("  - {value: Signal strength}\n");
}
else if(nsel == 2 || nsel == 3){
TH1D *histo_Data = (TH1D*)(_file0->Get("histo0")); assert(histo_Data); histo_Data->SetDirectory(0);
TH1D *histo_EWK  = (TH1D*)(_file0->Get("histo1")); assert(histo_EWK ); histo_EWK ->SetDirectory(0);
TH1D *histo_QCD  = (TH1D*)(_file0->Get("histo2")); assert(histo_QCD ); histo_QCD ->SetDirectory(0);
TH1D *histo_WZ   = (TH1D*)(_file0->Get("histo3")); assert(histo_WZ  ); histo_WZ  ->SetDirectory(0);
TH1D *histo_ZZ   = (TH1D*)(_file0->Get("histo4")); assert(histo_ZZ  ); histo_ZZ  ->SetDirectory(0);
TH1D *histo_VVV  = (TH1D*)(_file0->Get("histo5")); assert(histo_VVV ); histo_VVV ->SetDirectory(0);
TH1D *histo_WS   = (TH1D*)(_file0->Get("histo6")); assert(histo_WS  ); histo_WS  ->SetDirectory(0);
TH1D *histo_WG   = (TH1D*)(_file0->Get("histo7")); assert(histo_WG  ); histo_WG  ->SetDirectory(0);
TH1D *histo_DPS  = (TH1D*)(_file0->Get("histo8")); assert(histo_DPS ); histo_DPS ->SetDirectory(0);
TH1D *histo_Fake = (TH1D*)(_file0->Get("histo9")); assert(histo_Fake); histo_Fake->SetDirectory(0);

ofstream newcardShape;
newcardShape.open(theOutputName);
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: Data}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_Data->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - {value: %2d}\n",(int)histo_Data->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: WW EWK}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_EWK->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_EWK->GetBinError(i),histo_EWK->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_EWK->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: WW QCD}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_QCD->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_QCD->GetBinError(i),histo_QCD->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_QCD->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: WZ}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_WZ->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_WZ->GetBinError(i),histo_WZ->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_WZ->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: ZZ}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_ZZ->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_ZZ->GetBinError(i),histo_ZZ->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_ZZ->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: Triboson}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_VVV->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_VVV->GetBinError(i),histo_VVV->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_VVV->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: Wrong-sign}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_WS->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_WS->GetBinError(i),histo_WS->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_WS->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: Wgamma}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_WG->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_WG->GetBinError(i),histo_WG->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_WG->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: WW DPS}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_DPS->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_DPS->GetBinError(i),histo_DPS->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_DPS->GetBinContent(i));
}

newcardShape << Form("- header: {name: %s}\n",theMainSentence);
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Process, value: Non-prompt}\n");
newcardShape << Form("  values:\n");
for(int i=1; i<=histo_Fake->GetNbinsX()-binsToRemove; i++) {
newcardShape << Form("  - errors:\n");
newcardShape << Form("    - asymerror: {minus: -%.3f, plus: %.3f}\n",histo_Fake->GetBinError(i),histo_Fake->GetBinError(i));
newcardShape << Form("    value: %.3f\n",histo_Fake->GetBinContent(i));
}

if     (nsel == 2){
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Mjj/Mll, units: GeV/GeV}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 500-800/20-100}\n");
newcardShape << Form("  - {value: 800-1100/20-100}\n");
newcardShape << Form("  - {value: 1100-1500/20-100}\n");
newcardShape << Form("  - {value: 1500-inf/20-100}\n");
newcardShape << Form("  - {value: 500-800/100-180}\n");
newcardShape << Form("  - {value: 800-1100/100-180}\n");
newcardShape << Form("  - {value: 1100-1500/100-180}\n");
newcardShape << Form("  - {value: 1500-inf/100-180}\n");
newcardShape << Form("  - {value: 500-800/180-300}\n");
newcardShape << Form("  - {value: 800-1100/180-300}\n");
newcardShape << Form("  - {value: 1100-1500/180-300}\n");
newcardShape << Form("  - {value: 1500-inf/180-300}\n");
newcardShape << Form("  - {value: 500-800/300-inf}\n");
newcardShape << Form("  - {value: 800-1100/300-inf}\n");
newcardShape << Form("  - {value: 1100-1500/300-inf}\n");
newcardShape << Form("  - {value: 1500-inf/300-inf}\n");
}
else if(nsel == 3){
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Mll, units: GeV}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 20-100}\n");
newcardShape << Form("  - {value: 100-200}\n");
newcardShape << Form("  - {value: 200-300}\n");
newcardShape << Form("  - {value: 300-400}\n");
newcardShape << Form("  - {value: 400-inf}\n");
}
} // end nsel if 2/3
else if(nsel == 4){
ofstream newcardShape;
newcardShape.open("Table4.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: Observed limits (TeV^-4)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value:  -7.7/ 7.7}\n");
newcardShape << Form("  - {value: -21.6/21.8}\n");
newcardShape << Form("  - {value:  -6.0/ 5.9}\n");
newcardShape << Form("  - {value:  -8.7/ 9.1}\n");
newcardShape << Form("  - {value: -11.9/11.8}\n");
newcardShape << Form("  - {value: -13.3/12.9}\n");
newcardShape << Form("  - {value: -0.62/0.65}\n");
newcardShape << Form("  - {value: -0.28/0.31}\n");
newcardShape << Form("  - {value: -0.89/1.02}\n");
newcardShape << Form("- header: {name: Expected limits (TeV^-4)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value:  -7.0/ 7.2}\n");
newcardShape << Form("  - {value: -19.9/20.2}\n");
newcardShape << Form("  - {value:  -5.6/ 5.5}\n");
newcardShape << Form("  - {value:  -7.9/ 8.5}\n");
newcardShape << Form("  - {value: -11.1/11.0}\n");
newcardShape << Form("  - {value: -12.4/11.8}\n");
newcardShape << Form("  - {value: -0.58/0.61}\n");
newcardShape << Form("  - {value: -0.26/0.29}\n");
newcardShape << Form("  - {value: -0.80/0.95}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Value}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: fS0 / Lambda^4}\n");
newcardShape << Form("  - {value: fS1 / Lambda^4}\n");
newcardShape << Form("  - {value: fM0 / Lambda^4}\n");
newcardShape << Form("  - {value: fM1 / Lambda^4}\n");
newcardShape << Form("  - {value: fM6 / Lambda^4}\n");
newcardShape << Form("  - {value: fM7 / Lambda^4}\n");
newcardShape << Form("  - {value: fT0 / Lambda^4}\n");
newcardShape << Form("  - {value: fT1 / Lambda^4}\n");
newcardShape << Form("  - {value: fT2 / Lambda^4}\n");
} // end nsel if 4
else if(nsel == 5){
ofstream newcardShape;
newcardShape.open("Table5.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: Observed limits (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 108.82}\n");
newcardShape << Form("  - {value:  91.46}\n");
newcardShape << Form("  - {value:  70.81}\n");
newcardShape << Form("  - {value:  62.72}\n");
newcardShape << Form("  - {value:  52.38}\n");
newcardShape << Form("  - {value:  43.86}\n");
newcardShape << Form("  - {value:  37.29}\n");
newcardShape << Form("  - {value:  32.65}\n");
newcardShape << Form("  - {value:  29.43}\n");
newcardShape << Form("- header: {name: Expected limits -2sigma (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 83.70}\n");
newcardShape << Form("  - {value: 60.63}\n");
newcardShape << Form("  - {value: 39.83}\n");
newcardShape << Form("  - {value: 28.99}\n");
newcardShape << Form("  - {value: 20.96}\n");
newcardShape << Form("  - {value: 16.59}\n");
newcardShape << Form("  - {value: 13.66}\n");
newcardShape << Form("  - {value: 11.63}\n");
newcardShape << Form("  - {value: 10.40}\n");
newcardShape << Form("- header: {name: Expected limits -1sigma (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 113.57}\n");
newcardShape << Form("  - {value:  82.21}\n");
newcardShape << Form("  - {value:  54.34}\n");
newcardShape << Form("  - {value:  39.40}\n");
newcardShape << Form("  - {value:  28.62}\n");
newcardShape << Form("  - {value:  22.79}\n");
newcardShape << Form("  - {value:  18.84}\n");
newcardShape << Form("  - {value:  16.12}\n");
newcardShape << Form("  - {value:  14.48}\n");
newcardShape << Form("- header: {name: Expected limits (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 161.72}\n");
newcardShape << Form("  - {value: 117.58}\n");
newcardShape << Form("  - {value:  78.12}\n");
newcardShape << Form("  - {value:  56.45}\n");
newcardShape << Form("  - {value:  41.60}\n");
newcardShape << Form("  - {value:  33.30}\n");
newcardShape << Form("  - {value:  27.64}\n");
newcardShape << Form("  - {value:  23.73}\n");
newcardShape << Form("  - {value:  21.39}\n");
newcardShape << Form("- header: {name: Expected limits +1sigma (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 235.85}\n");
newcardShape << Form("  - {value: 171.48}\n");
newcardShape << Form("  - {value: 114.56}\n");
newcardShape << Form("  - {value:  83.22}\n");
newcardShape << Form("  - {value:  61.33}\n");
newcardShape << Form("  - {value:  49.63}\n");
newcardShape << Form("  - {value:  41.63}\n");
newcardShape << Form("  - {value:  35.93}\n");
newcardShape << Form("  - {value:  32.47}\n");
newcardShape << Form("- header: {name: Expected limits +2sigma (fb)}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: Cross section times branching ratio upper limits at the 95\%% CL}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 330.82}\n");
newcardShape << Form("  - {value: 241.98}\n");
newcardShape << Form("  - {value: 162.13}\n");
newcardShape << Form("  - {value: 118.10}\n");
newcardShape << Form("  - {value:  88.57}\n");
newcardShape << Form("  - {value:  72.42}\n");
newcardShape << Form("  - {value:  61.01}\n");
newcardShape << Form("  - {value:  53.06}\n");
newcardShape << Form("  - {value:  48.12}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Mass (GeV)}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 200 }\n");
newcardShape << Form("  - {value: 300 }\n");
newcardShape << Form("  - {value: 400 }\n");
newcardShape << Form("  - {value: 500 }\n");
newcardShape << Form("  - {value: 600 }\n");
newcardShape << Form("  - {value: 700 }\n");
newcardShape << Form("  - {value: 800 }\n");
newcardShape << Form("  - {value: 900 }\n");
newcardShape << Form("  - {value: 1000}\n");
} // end nsel if 5
else if(nsel == 6){
ofstream newcardShape;
newcardShape.open("Table6.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: Observed limits}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.175}\n");
newcardShape << Form("  - {value: 0.214}\n");
newcardShape << Form("  - {value: 0.240}\n");
newcardShape << Form("  - {value: 0.280}\n");
newcardShape << Form("  - {value: 0.309}\n");
newcardShape << Form("  - {value: 0.337}\n");
newcardShape << Form("  - {value: 0.365}\n");
newcardShape << Form("  - {value: 0.398}\n");
newcardShape << Form("  - {value: 0.436}\n");
newcardShape << Form("- header: {name: Expected limits -2sigma}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.153}\n");
newcardShape << Form("  - {value: 0.174}\n");
newcardShape << Form("  - {value: 0.180}\n");
newcardShape << Form("  - {value: 0.190}\n");
newcardShape << Form("  - {value: 0.195}\n");
newcardShape << Form("  - {value: 0.207}\n");
newcardShape << Form("  - {value: 0.221}\n");
newcardShape << Form("  - {value: 0.237}\n");
newcardShape << Form("  - {value: 0.259}\n");
newcardShape << Form("- header: {name: Expected limits -1sigma}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.179}\n");
newcardShape << Form("  - {value: 0.203}\n");
newcardShape << Form("  - {value: 0.210}\n");
newcardShape << Form("  - {value: 0.222}\n");
newcardShape << Form("  - {value: 0.228}\n");
newcardShape << Form("  - {value: 0.243}\n");
newcardShape << Form("  - {value: 0.259}\n");
newcardShape << Form("  - {value: 0.279}\n");
newcardShape << Form("  - {value: 0.306}\n");
newcardShape << Form("- header: {name: Expected limits}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.213}\n");
newcardShape << Form("  - {value: 0.243}\n");
newcardShape << Form("  - {value: 0.252}\n");
newcardShape << Form("  - {value: 0.265}\n");
newcardShape << Form("  - {value: 0.276}\n");
newcardShape << Form("  - {value: 0.293}\n");
newcardShape << Form("  - {value: 0.314}\n");
newcardShape << Form("  - {value: 0.339}\n");
newcardShape << Form("  - {value: 0.372}\n");
newcardShape << Form("- header: {name: Expected limits +1sigma}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.258}\n");
newcardShape << Form("  - {value: 0.293}\n");
newcardShape << Form("  - {value: 0.306}\n");
newcardShape << Form("  - {value: 0.322}\n");
newcardShape << Form("  - {value: 0.335}\n");
newcardShape << Form("  - {value: 0.358}\n");
newcardShape << Form("  - {value: 0.386}\n");
newcardShape << Form("  - {value: 0.417}\n");
newcardShape << Form("  - {value: 0.458}\n");
newcardShape << Form("- header: {name: Expected limits +2sigma}\n");
newcardShape << Form("  qualifiers:\n");
newcardShape << Form("  - {name: Value, value: 95\%% CL upper limits on $s_H$}\n");
newcardShape << Form("  - {name: SQRT(S), units: GeV, value: '13000.0'}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 0.305}\n");
newcardShape << Form("  - {value: 0.349}\n");
newcardShape << Form("  - {value: 0.364}\n");
newcardShape << Form("  - {value: 0.384}\n");
newcardShape << Form("  - {value: 0.402}\n");
newcardShape << Form("  - {value: 0.433}\n");
newcardShape << Form("  - {value: 0.467}\n");
newcardShape << Form("  - {value: 0.507}\n");
newcardShape << Form("  - {value: 0.558}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Mass (GeV)}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 200 }\n");
newcardShape << Form("  - {value: 300 }\n");
newcardShape << Form("  - {value: 400 }\n");
newcardShape << Form("  - {value: 500 }\n");
newcardShape << Form("  - {value: 600 }\n");
newcardShape << Form("  - {value: 700 }\n");
newcardShape << Form("  - {value: 800 }\n");
newcardShape << Form("  - {value: 900 }\n");
newcardShape << Form("  - {value: 1000}\n");
} // end nsel if 6
else if(nsel == 7){
ofstream newcardShape;
newcardShape.open("Table7.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: Value (\%%)}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 2.5}\n");
newcardShape << Form("  - {value: 2.0}\n");
newcardShape << Form("  - {value: 2.0}\n");
newcardShape << Form("  - {value: 3.0}\n");
newcardShape << Form("  - {value: 4.0}\n");
newcardShape << Form("  - {value: 10.0}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Source}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: Integrated luminosity}\n");
newcardShape << Form("  - {value: Muon selection}\n");
newcardShape << Form("  - {value: Electron selection}\n");
newcardShape << Form("  - {value: Jet energy scale}\n");
newcardShape << Form("  - {value: PDFs}\n");
newcardShape << Form("  - {value: QCD scales}\n");
} // end nsel if 7
else if(nsel == 8){
ofstream newcardShape;
newcardShape.open("Table8.yaml");
newcardShape << Form("dependent_variables:\n");
newcardShape << Form("- header: {name: Efficiency (\%%)}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 38}\n");
newcardShape << Form("  - {value: 51}\n");
newcardShape << Form("  - {value: 62}\n");
newcardShape << Form("  - {value: 66}\n");
newcardShape << Form("  - {value: 66}\n");
newcardShape << Form("independent_variables:\n");
newcardShape << Form("- header: {name: Mll, units: GeV}\n");
newcardShape << Form("  values:\n");
newcardShape << Form("  - {value: 20-100}\n");
newcardShape << Form("  - {value: 100-200}\n");
newcardShape << Form("  - {value: 200-300}\n");
newcardShape << Form("  - {value: 300-400}\n");
newcardShape << Form("  - {value: 400-inf}\n");
} // end nsel if 8

}
