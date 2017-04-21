#include <TROOT.h>
#include <TH1F.h>
#include <TFile.h>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;
const int totalChannels=34;
const int zzBins=11;
const int wzBins=11;
const int zhBins=12;
//const int nBinMVA = 12; Double_t xbins[nBinMVA+1] =  {-2, -1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9}; // BDT
const int nBinMVA = 12; Double_t xbins[nBinMVA+1] = {0, 50, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500, 600}; // MET

void postfitYieldsToHistos(TString postfit_yields="postfit_yields.txt", TString datacard="histo_limits_zll3hinvllnj_sm.text") {
  // Set up histogram objects
  TFile *histo_zz_postfit_nice = TFile::Open("histozz_postfit_nice.root", "RECREATE");
  TH1F *histo_zz[7], *histo_wz[7], *histo_zh[8];
  for(int i=0; i<7; i++)  histo_zz[i] = new TH1F(Form("histo%d_zz",i), Form("histo%d",i), nBinMVA, xbins);
  TFile *histo_wz_postfit_nice = TFile::Open("histowz_postfit_nice.root", "RECREATE");
  for(int i=0; i<7; i++)  histo_wz[i] = new TH1F(Form("histo%d_wz",i), Form("histo%d",i), nBinMVA, xbins);
  TFile *histo_zh_postfit_nice = TFile::Open("histozh_postfit_nice.root", "RECREATE");
  for(int i=0; i<8; i++)  histo_zh[i] = new TH1F(Form("histo%d_zh",i), Form("histo%d",i), nBinMVA, xbins);

  // Read in information from text files
  ifstream postfit_yields_file(postfit_yields.Data());
  assert(postfit_yields_file.is_open());
  ifstream datacard_file(datacard.Data());
  assert(datacard_file.is_open());
  string line;
  while( getline(datacard_file, line ) ) {
    if( line.find("observation") == string::npos ) continue;
    else {
      istringstream iss(line);
      string junk;
      double dataEvents;
      iss >> junk;
      int theChannel=1, theBin;
      while(iss >> dataEvents) {
        if(theChannel <= zzBins) {
          theBin = theChannel+1;
          histo_zz[0]->SetBinContent(theBin, (double)((int)dataEvents));
        } else if(theChannel > zzBins && theChannel <= zzBins+wzBins) {
          theBin = theChannel-zzBins+1;
          histo_wz[0]->SetBinContent(theBin, (double)((int)dataEvents));
        } else if(theChannel > zzBins+wzBins && theChannel <= totalChannels) {
          theBin = theChannel - zzBins - wzBins;
          histo_zh[0]->SetBinContent(theBin, (double)((int)dataEvents));
        }
        theChannel++;
      }
      break;
    }
  }
  datacard_file.close();
  getline( postfit_yields_file, line ); // throwaway line
  string chstr, process, pm1, pm2, pm3;
  double N_pre, dN_pre, N_SB, dN_SB, N_B, dN_B;
  while( getline(postfit_yields_file, line ) ) {
    // parse postfit yield lines e.g.
    // ch13 FakeE 2.313 +/-   2.021     1.683 +/-   1.365    1.742 +/-   1.516
    istringstream iss(line);
    iss >> chstr >> process >> N_pre >> pm1 >> dN_pre >> N_SB >> pm2 >> dN_SB >> N_B >> dN_B;
    
    // Assign the channel
    chstr = chstr.substr(2);
    istringstream ich(chstr);
    int theChannel, theBin, theHisto=-1;
    ich >> theChannel;
    bool usePostFit=true;

    // Assign the histo number based on process
    if(theChannel <= zzBins+wzBins) {
      if     (process=="EM"   ) theHisto=1;
      else if(process=="Zg"   ) theHisto=2;
      else if(process=="WZ"   ) theHisto=3;
      else if(process=="ZZ"   ) theHisto=4;
      else if(process=="VVV"  ) theHisto=5;
      else if(process=="Higgs") theHisto=6;
    } else if(theChannel <= totalChannels) {
      if     (process=="EM"       ) theHisto=1;
      else if(process=="Zjets"    ) theHisto=2;
      else if(process=="WZ"       ) theHisto=3;
      else if(process=="ZZ"       ) theHisto=4;
      else if(process=="VVV"      ) theHisto=5;
      else if(process=="ZH_hinv"  ) { theHisto=6; usePostFit=false; }
      else if(process=="ggZH_hinv") { theHisto=7; usePostFit=false; }
    }
    if(theHisto<0) continue;
    // cout << line << std::endl;
    // cout << theChannel << " " << theHisto << std::endl;
    // Fill the appropriate histogram with the yield and error
    if(theChannel <= zzBins) {
      theBin = theChannel+1;
      histo_zz[theHisto]->SetBinContent( theBin, N_SB  );
      histo_zz[theHisto]->SetBinError  ( theBin, dN_SB );
    } else if(theChannel > zzBins && theChannel <= zzBins+wzBins) {
      theBin = theChannel-zzBins+1;
      histo_wz[theHisto]->SetBinContent( theBin, N_SB  );
      histo_wz[theHisto]->SetBinError  ( theBin, dN_SB );
    } else if(theChannel > zzBins+wzBins && theChannel <= totalChannels) {
      theBin = theChannel - zzBins - wzBins;
      //cout << chstr << " " << theChannel << " " << theBin << std::endl;
      histo_zh[theHisto]->SetBinContent( theBin, usePostFit ? N_SB   : N_pre  );
      histo_zh[theHisto]->SetBinError  ( theBin, usePostFit ? dN_SB  : dN_pre );
    }
  }
  histo_zz_postfit_nice->cd();
  for(int i=0; i<7; i++)  histo_zz[i]->Write( Form("histo%d",i) );
  histo_wz_postfit_nice->cd();
  for(int i=0; i<7; i++)  histo_wz[i]->Write( Form("histo%d",i) );
  histo_zh_postfit_nice->cd();
  for(int i=0; i<8; i++)  histo_zh[i]->Write( Form("histo%d",i) );
  histo_zz_postfit_nice->Close();
  histo_wz_postfit_nice->Close();
  histo_zh_postfit_nice->Close();
 
}
