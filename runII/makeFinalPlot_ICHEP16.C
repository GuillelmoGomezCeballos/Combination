void makeFinalPlot_ICHEP16(int nsel = 0){

  double dmSF = 0.339*3;
  
  const int nBinMVA = 6; Float_t xbins[nBinMVA+1] = {100, 125, 150, 175, 200, 250, 350};
  TH1D* histoMVA = new TH1D("histos", "histos", nBinMVA, xbins);
    
  TH1D *histo_Data     = (TH1D*) histoMVA->Clone("histo0");
  TH1D *histo_EM       = (TH1D*) histoMVA->Clone("histo1");    
  TH1D *histo_Zjets    = (TH1D*) histoMVA->Clone("histo2");         
  TH1D *histo_WZ       = (TH1D*) histoMVA->Clone("histo3");    
  TH1D *histo_ZZ       = (TH1D*) histoMVA->Clone("histo4");
  TH1D *histo_VVV      = (TH1D*) histoMVA->Clone("histo5");   
  TH1D *histo_ZH_hinv  = (TH1D*) histoMVA->Clone("histo6"); 
  TH1D *histo_ggZH_hinv= (TH1D*) histoMVA->Clone("histo7");
  
  histo_Data->SetBinContent(1, 134);  histo_Data->SetBinError(1, sqrt(histo_Data->GetBinContent(1)));
  histo_Data->SetBinContent(2,  59);  histo_Data->SetBinError(2, sqrt(histo_Data->GetBinContent(2)));
  histo_Data->SetBinContent(3,  31);  histo_Data->SetBinError(3, sqrt(histo_Data->GetBinContent(3)));
  histo_Data->SetBinContent(4,   9);  histo_Data->SetBinError(4, sqrt(histo_Data->GetBinContent(4)));
  histo_Data->SetBinContent(5,  18);  histo_Data->SetBinError(5, sqrt(histo_Data->GetBinContent(5)));
  histo_Data->SetBinContent(6,  16);  histo_Data->SetBinError(6, sqrt(histo_Data->GetBinContent(6)));

  if(nsel == 0 || nsel == 1){
  histo_EM->SetBinContent(1,42.439);  histo_EM->SetBinError(1,10.596);
  histo_EM->SetBinContent(2, 9.310);  histo_EM->SetBinError(2, 2.578);
  histo_EM->SetBinContent(3, 2.991);  histo_EM->SetBinError(3, 1.225);
  histo_EM->SetBinContent(4, 0.122);  histo_EM->SetBinError(4, 0.128);
  histo_EM->SetBinContent(5, 0.128);  histo_EM->SetBinError(5, 0.125);
  histo_EM->SetBinContent(6, 0.000);  histo_EM->SetBinError(6, 0.000);
  
  histo_Zjets->SetBinContent(1,11.335);  histo_Zjets->SetBinError(1,18.716);
  histo_Zjets->SetBinContent(2, 0.869);  histo_Zjets->SetBinError(2, 1.961);
  histo_Zjets->SetBinContent(3, 0.000);  histo_Zjets->SetBinError(3, 0.000);
  histo_Zjets->SetBinContent(4, 0.537);  histo_Zjets->SetBinError(4, 0.694);
  histo_Zjets->SetBinContent(5, 0.000);  histo_Zjets->SetBinError(5, 0.000);
  histo_Zjets->SetBinContent(6, 0.000);  histo_Zjets->SetBinError(6, 0.000);
  
  histo_WZ->SetBinContent(1,24.032);  histo_WZ->SetBinError(1,2.717);
  histo_WZ->SetBinContent(2,13.549);  histo_WZ->SetBinError(2,1.498);
  histo_WZ->SetBinContent(3, 6.660);  histo_WZ->SetBinError(3,0.878);
  histo_WZ->SetBinContent(4, 4.732);  histo_WZ->SetBinError(4,0.573);
  histo_WZ->SetBinContent(5, 3.937);  histo_WZ->SetBinError(5,0.528);
  histo_WZ->SetBinContent(6, 2.928);  histo_WZ->SetBinError(6,0.490);
  
  histo_ZZ->SetBinContent(1,50.010);  histo_ZZ->SetBinError(1,3.775);
  histo_ZZ->SetBinContent(2,30.630);  histo_ZZ->SetBinError(2,2.467);
  histo_ZZ->SetBinContent(3,18.603);  histo_ZZ->SetBinError(3,1.596);
  histo_ZZ->SetBinContent(4,11.597);  histo_ZZ->SetBinError(4,1.086);
  histo_ZZ->SetBinContent(5,11.785);  histo_ZZ->SetBinError(5,1.210);
  histo_ZZ->SetBinContent(6,10.124);  histo_ZZ->SetBinError(6,1.349);
  
  histo_VVV->SetBinContent(1,0.131);  histo_VVV->SetBinError(1,0.033);
  histo_VVV->SetBinContent(2,0.140);  histo_VVV->SetBinError(2,0.040);
  histo_VVV->SetBinContent(3,0.106);  histo_VVV->SetBinError(3,0.028);
  histo_VVV->SetBinContent(4,0.120);  histo_VVV->SetBinError(4,0.037);
  histo_VVV->SetBinContent(5,0.054);  histo_VVV->SetBinError(5,0.021);
  histo_VVV->SetBinContent(6,0.128);  histo_VVV->SetBinError(6,0.030);
  
  histo_ZH_hinv->SetBinContent(1,13.850);  histo_ZH_hinv->SetBinError(1,1.601);
  histo_ZH_hinv->SetBinContent(2,10.851);  histo_ZH_hinv->SetBinError(2,1.355);
  histo_ZH_hinv->SetBinContent(3, 8.038);  histo_ZH_hinv->SetBinError(3,1.049);
  histo_ZH_hinv->SetBinContent(4, 5.331);  histo_ZH_hinv->SetBinError(4,0.734);
  histo_ZH_hinv->SetBinContent(5, 6.840);  histo_ZH_hinv->SetBinError(5,0.874);
  histo_ZH_hinv->SetBinContent(6, 7.238);  histo_ZH_hinv->SetBinError(6,0.744);

  if(nsel == 1){
    histo_ZH_hinv->SetBinContent(1,17.014);  histo_ZH_hinv->SetBinError(1,0.115596*histo_ZH_hinv->GetBinContent(1));
    histo_ZH_hinv->SetBinContent(2,14.966);  histo_ZH_hinv->SetBinError(2,0.124873*histo_ZH_hinv->GetBinContent(2));
    histo_ZH_hinv->SetBinContent(3,12.336);  histo_ZH_hinv->SetBinError(3,0.130505*histo_ZH_hinv->GetBinContent(3));
    histo_ZH_hinv->SetBinContent(4,10.552);  histo_ZH_hinv->SetBinError(4,0.137685*histo_ZH_hinv->GetBinContent(4));
    histo_ZH_hinv->SetBinContent(5,15.042);  histo_ZH_hinv->SetBinError(5,0.127778*histo_ZH_hinv->GetBinContent(5));
    histo_ZH_hinv->SetBinContent(6,25.966);  histo_ZH_hinv->SetBinError(6,0.102791*histo_ZH_hinv->GetBinContent(6));
 }

  histo_ggZH_hinv->SetBinContent(1,2.594);  histo_ggZH_hinv->SetBinError(1,0.664);
  histo_ggZH_hinv->SetBinContent(2,3.116);  histo_ggZH_hinv->SetBinError(2,0.801);
  histo_ggZH_hinv->SetBinContent(3,2.588);  histo_ggZH_hinv->SetBinError(3,0.662);
  histo_ggZH_hinv->SetBinContent(4,1.752);  histo_ggZH_hinv->SetBinError(4,0.448);
  histo_ggZH_hinv->SetBinContent(5,1.778);  histo_ggZH_hinv->SetBinError(5,0.453);
  histo_ggZH_hinv->SetBinContent(6,1.053);  histo_ggZH_hinv->SetBinError(6,0.267);
  } else if(nsel == 2 || nsel == 3){
  histo_EM->SetBinContent(1,35.861);  histo_EM->SetBinError(1, 9.145);
  histo_EM->SetBinContent(2, 7.797);  histo_EM->SetBinError(2, 2.045);
  histo_EM->SetBinContent(3, 2.503);  histo_EM->SetBinError(3, 0.931);
  histo_EM->SetBinContent(4, 0.108);  histo_EM->SetBinError(4, 0.126);
  histo_EM->SetBinContent(5, 0.108);  histo_EM->SetBinError(5, 0.125);
  histo_EM->SetBinContent(6, 0.000);  histo_EM->SetBinError(6, 0.000);
  
  histo_Zjets->SetBinContent(1, 9.640);  histo_Zjets->SetBinError(1,12.100);
  histo_Zjets->SetBinContent(2, 0.766);  histo_Zjets->SetBinError(2, 1.439);
  histo_Zjets->SetBinContent(3, 0.000);  histo_Zjets->SetBinError(3, 0.000);
  histo_Zjets->SetBinContent(4, 0.547);  histo_Zjets->SetBinError(4, 1.349);
  histo_Zjets->SetBinContent(5, 0.000);  histo_Zjets->SetBinError(5, 0.000);
  histo_Zjets->SetBinContent(6, 0.000);  histo_Zjets->SetBinError(6, 0.000);
  
  histo_WZ->SetBinContent(1,22.964);  histo_WZ->SetBinError(1,3.029);
  histo_WZ->SetBinContent(2,12.928);  histo_WZ->SetBinError(2,1.900);
  histo_WZ->SetBinContent(3, 6.349);  histo_WZ->SetBinError(3,0.967);
  histo_WZ->SetBinContent(4, 4.616);  histo_WZ->SetBinError(4,0.751);
  histo_WZ->SetBinContent(5, 3.748);  histo_WZ->SetBinError(5,0.615);
  histo_WZ->SetBinContent(6, 2.775);  histo_WZ->SetBinError(6,0.512);
  
  histo_ZZ->SetBinContent(1,47.473);  histo_ZZ->SetBinError(1,4.800);
  histo_ZZ->SetBinContent(2,28.972);  histo_ZZ->SetBinError(2,3.186);
  histo_ZZ->SetBinContent(3,17.533);  histo_ZZ->SetBinError(3,2.104);
  histo_ZZ->SetBinContent(4,10.896);  histo_ZZ->SetBinError(4,1.440);
  histo_ZZ->SetBinContent(5,11.013);  histo_ZZ->SetBinError(5,1.595);
  histo_ZZ->SetBinContent(6, 9.326);  histo_ZZ->SetBinError(6,1.768);
  
  histo_VVV->SetBinContent(1,0.127);  histo_VVV->SetBinError(1,0.030);
  histo_VVV->SetBinContent(2,0.135);  histo_VVV->SetBinError(2,0.031);
  histo_VVV->SetBinContent(3,0.103);  histo_VVV->SetBinError(3,0.028);
  histo_VVV->SetBinContent(4,0.117);  histo_VVV->SetBinError(4,0.036);
  histo_VVV->SetBinContent(5,0.053);  histo_VVV->SetBinError(5,0.020);
  histo_VVV->SetBinContent(6,0.124);  histo_VVV->SetBinError(6,0.029);
  
  histo_ZH_hinv->SetBinContent(1,13.850);  histo_ZH_hinv->SetBinError(1,1.601);
  histo_ZH_hinv->SetBinContent(2,10.851);  histo_ZH_hinv->SetBinError(2,1.355);
  histo_ZH_hinv->SetBinContent(3, 8.038);  histo_ZH_hinv->SetBinError(3,1.049);
  histo_ZH_hinv->SetBinContent(4, 5.331);  histo_ZH_hinv->SetBinError(4,0.734);
  histo_ZH_hinv->SetBinContent(5, 6.840);  histo_ZH_hinv->SetBinError(5,0.874);
  histo_ZH_hinv->SetBinContent(6, 7.238);  histo_ZH_hinv->SetBinError(6,0.744);

  if(nsel == 3){
    histo_ZH_hinv->SetBinContent(1,17.014);  histo_ZH_hinv->SetBinError(1,0.115596*histo_ZH_hinv->GetBinContent(1));
    histo_ZH_hinv->SetBinContent(2,14.966);  histo_ZH_hinv->SetBinError(2,0.124873*histo_ZH_hinv->GetBinContent(2));
    histo_ZH_hinv->SetBinContent(3,12.336);  histo_ZH_hinv->SetBinError(3,0.130505*histo_ZH_hinv->GetBinContent(3));
    histo_ZH_hinv->SetBinContent(4,10.552);  histo_ZH_hinv->SetBinError(4,0.137685*histo_ZH_hinv->GetBinContent(4));
    histo_ZH_hinv->SetBinContent(5,15.042);  histo_ZH_hinv->SetBinError(5,0.127778*histo_ZH_hinv->GetBinContent(5));
    histo_ZH_hinv->SetBinContent(6,25.966);  histo_ZH_hinv->SetBinError(6,0.102791*histo_ZH_hinv->GetBinContent(6));
  }

  histo_ggZH_hinv->SetBinContent(1,2.594);  histo_ggZH_hinv->SetBinError(1,0.664);
  histo_ggZH_hinv->SetBinContent(2,3.116);  histo_ggZH_hinv->SetBinError(2,0.801);
  histo_ggZH_hinv->SetBinContent(3,2.588);  histo_ggZH_hinv->SetBinError(3,0.662);
  histo_ggZH_hinv->SetBinContent(4,1.752);  histo_ggZH_hinv->SetBinError(4,0.448);
  histo_ggZH_hinv->SetBinContent(5,1.778);  histo_ggZH_hinv->SetBinError(5,0.453);
  histo_ggZH_hinv->SetBinContent(6,1.053);  histo_ggZH_hinv->SetBinError(6,0.267);
  }

  if(nsel == 1 || nsel == 3) histo_ZH_hinv->Scale(dmSF);

  TFile* outFilePlotsNote = new TFile(Form("histo_%d.root",nsel),"recreate");
  outFilePlotsNote->cd();
  histo_Data	 ->Write();
  histo_EM	 ->Write();
  histo_Zjets	 ->Write();
  histo_WZ	 ->Write();
  histo_ZZ	 ->Write();
  histo_VVV	 ->Write();
  histo_ZH_hinv  ->Write();
  histo_ggZH_hinv->Write();
  outFilePlotsNote->Close();
}
