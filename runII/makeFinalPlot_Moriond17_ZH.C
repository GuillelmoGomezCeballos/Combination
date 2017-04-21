void makeFinalPlot_Moriond17_ZH(int nsel = 0){

  double dmSF = 0.339*3;
  
  const int nBinMVA = 11; Float_t xbins[nBinMVA+1] = {50, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500, 600};
  TH1D* histoMVA = new TH1D("histos", "histos", nBinMVA, xbins);
    
  if(nsel == 0 || nsel == 1){
  TH1D *histo_Data  = (TH1D*) histoMVA->Clone("histo0");
  TH1D *histo_EM    = (TH1D*) histoMVA->Clone("histo1");    
  TH1D *histo_Zjets = (TH1D*) histoMVA->Clone("histo2");	 
  TH1D *histo_WZ    = (TH1D*) histoMVA->Clone("histo3");    
  TH1D *histo_ZZ    = (TH1D*) histoMVA->Clone("histo4");
  TH1D *histo_VVV   = (TH1D*) histoMVA->Clone("histo5");   
  TH1D *histo_Higgs = (TH1D*) histoMVA->Clone("histo6");

  if(nsel == 0){
  histo_Data->SetBinContent( 1,  16);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,  14);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,  12);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,   4);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,   4);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,   5);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,   0);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,   1);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,   0);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,   0);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));
  histo_Data->SetBinContent(11,   0);  histo_Data->SetBinError(11, sqrt(histo_Data->GetBinContent(11)));

  histo_EM->SetBinContent( 1, 0.000);  histo_EM->SetBinError( 1, 0.000);
  histo_EM->SetBinContent( 2, 0.000);  histo_EM->SetBinError( 2, 0.000);
  histo_EM->SetBinContent( 3, 0.000);  histo_EM->SetBinError( 3, 0.000);
  histo_EM->SetBinContent( 4, 0.000);  histo_EM->SetBinError( 4, 0.000);
  histo_EM->SetBinContent( 5, 0.000);  histo_EM->SetBinError( 5, 0.000);
  histo_EM->SetBinContent( 6, 0.000);  histo_EM->SetBinError( 6, 0.000);
  histo_EM->SetBinContent( 7, 0.000);  histo_EM->SetBinError( 7, 0.000);
  histo_EM->SetBinContent( 8, 0.000);  histo_EM->SetBinError( 8, 0.000);
  histo_EM->SetBinContent( 9, 0.000);  histo_EM->SetBinError( 9, 0.000);
  histo_EM->SetBinContent(10, 0.000);  histo_EM->SetBinError(10, 0.000);
  histo_EM->SetBinContent(11, 0.000);  histo_EM->SetBinError(11, 0.000);
  
  histo_Zjets->SetBinContent( 1, 0.000);  histo_Zjets->SetBinError( 1, 0.000);
  histo_Zjets->SetBinContent( 2, 0.000);  histo_Zjets->SetBinError( 2, 0.000);
  histo_Zjets->SetBinContent( 3, 0.000);  histo_Zjets->SetBinError( 3, 0.000);
  histo_Zjets->SetBinContent( 4, 0.000);  histo_Zjets->SetBinError( 4, 0.000);
  histo_Zjets->SetBinContent( 5, 0.000);  histo_Zjets->SetBinError( 5, 0.000);
  histo_Zjets->SetBinContent( 6, 0.000);  histo_Zjets->SetBinError( 6, 0.000);
  histo_Zjets->SetBinContent( 7, 0.000);  histo_Zjets->SetBinError( 7, 0.000);
  histo_Zjets->SetBinContent( 8, 0.000);  histo_Zjets->SetBinError( 8, 0.000);
  histo_Zjets->SetBinContent( 9, 0.000);  histo_Zjets->SetBinError( 9, 0.000);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);
  histo_Zjets->SetBinContent(11, 0.000);  histo_Zjets->SetBinError(11, 0.000);
  
  histo_WZ->SetBinContent( 1, 0.000);  histo_WZ->SetBinError( 1, 0.000);
  histo_WZ->SetBinContent( 2, 0.000);  histo_WZ->SetBinError( 2, 0.000);
  histo_WZ->SetBinContent( 3, 0.000);  histo_WZ->SetBinError( 3, 0.000);
  histo_WZ->SetBinContent( 4, 0.000);  histo_WZ->SetBinError( 4, 0.000);
  histo_WZ->SetBinContent( 5, 0.000);  histo_WZ->SetBinError( 5, 0.000);
  histo_WZ->SetBinContent( 6, 0.000);  histo_WZ->SetBinError( 6, 0.000);
  histo_WZ->SetBinContent( 7, 0.000);  histo_WZ->SetBinError( 7, 0.000);
  histo_WZ->SetBinContent( 8, 0.000);  histo_WZ->SetBinError( 8, 0.000);
  histo_WZ->SetBinContent( 9, 0.000);  histo_WZ->SetBinError( 9, 0.000);
  histo_WZ->SetBinContent(10, 0.000);  histo_WZ->SetBinError(10, 0.000);
  histo_WZ->SetBinContent(11, 0.000);  histo_WZ->SetBinError(11, 0.000);

  histo_ZZ->SetBinContent( 1,12.760);  histo_ZZ->SetBinError( 1,1.311);
  histo_ZZ->SetBinContent( 2,12.390);  histo_ZZ->SetBinError( 2,1.317);
  histo_ZZ->SetBinContent( 3, 9.444);  histo_ZZ->SetBinError( 3,1.022);
  histo_ZZ->SetBinContent( 4, 6.748);  histo_ZZ->SetBinError( 4,0.771);
  histo_ZZ->SetBinContent( 5, 4.616);  histo_ZZ->SetBinError( 5,0.583);
  histo_ZZ->SetBinContent( 6, 5.168);  histo_ZZ->SetBinError( 6,0.694);
  histo_ZZ->SetBinContent( 7, 2.126);  histo_ZZ->SetBinError( 7,0.295);
  histo_ZZ->SetBinContent( 8, 1.188);  histo_ZZ->SetBinError( 8,0.195);
  histo_ZZ->SetBinContent( 9, 0.664);  histo_ZZ->SetBinError( 9,0.118);
  histo_ZZ->SetBinContent(10, 0.426);  histo_ZZ->SetBinError(10,0.080);
  histo_ZZ->SetBinContent(11, 0.293);  histo_ZZ->SetBinError(11,0.065);

  histo_VVV->SetBinContent( 1,0.045);  histo_VVV->SetBinError( 1,0.017);
  histo_VVV->SetBinContent( 2,0.114);  histo_VVV->SetBinError( 2,0.041);
  histo_VVV->SetBinContent( 3,0.057);  histo_VVV->SetBinError( 3,0.029);
  histo_VVV->SetBinContent( 4,0.045);  histo_VVV->SetBinError( 4,0.017);
  histo_VVV->SetBinContent( 5,0.071);  histo_VVV->SetBinError( 5,0.023);
  histo_VVV->SetBinContent( 6,0.057);  histo_VVV->SetBinError( 6,0.027);
  histo_VVV->SetBinContent( 7,0.082);  histo_VVV->SetBinError( 7,0.035);
  histo_VVV->SetBinContent( 8,0.005);  histo_VVV->SetBinError( 8,0.003);
  histo_VVV->SetBinContent( 9,0.003);  histo_VVV->SetBinError( 9,0.003);
  histo_VVV->SetBinContent(10,0.031);  histo_VVV->SetBinError(10,0.025);
  histo_VVV->SetBinContent(11,0.013);  histo_VVV->SetBinError(11,0.010);
  
  histo_Higgs->SetBinContent( 1,0.000);  histo_Higgs->SetBinError( 1,0.000);
  histo_Higgs->SetBinContent( 2,0.000);  histo_Higgs->SetBinError( 2,0.000);
  histo_Higgs->SetBinContent( 3,0.000);  histo_Higgs->SetBinError( 3,0.000);
  histo_Higgs->SetBinContent( 4,0.000);  histo_Higgs->SetBinError( 4,0.000);
  histo_Higgs->SetBinContent( 5,0.000);  histo_Higgs->SetBinError( 5,0.000);
  histo_Higgs->SetBinContent( 6,0.000);  histo_Higgs->SetBinError( 6,0.000);
  histo_Higgs->SetBinContent( 7,0.000);  histo_Higgs->SetBinError( 7,0.000);
  histo_Higgs->SetBinContent( 8,0.000);  histo_Higgs->SetBinError( 8,0.000);
  histo_Higgs->SetBinContent( 9,0.000);  histo_Higgs->SetBinError( 9,0.000);
  histo_Higgs->SetBinContent(10,0.000);  histo_Higgs->SetBinError(10,0.000);
  histo_Higgs->SetBinContent(11,0.000);  histo_Higgs->SetBinError(11,0.000);

  }
  else if(nsel == 1){
  histo_Data->SetBinContent( 1, 110);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2, 111);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,  81);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,  72);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,  32);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,  38);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,  15);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,  10);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,   5);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,   2);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));
  histo_Data->SetBinContent(11,   0);  histo_Data->SetBinError(11, sqrt(histo_Data->GetBinContent(11)));

  histo_EM->SetBinContent( 1,22.110);  histo_EM->SetBinError( 1,6.080); 
  histo_EM->SetBinContent( 2,17.210);  histo_EM->SetBinError( 2,6.760); 
  histo_EM->SetBinContent( 3, 6.310);  histo_EM->SetBinError( 3,3.890); 
  histo_EM->SetBinContent( 4, 3.440);  histo_EM->SetBinError( 4,4.450); 
  histo_EM->SetBinContent( 5, 6.350);  histo_EM->SetBinError( 5,2.940); 
  histo_EM->SetBinContent( 6, 3.620);  histo_EM->SetBinError( 6,2.040); 
  histo_EM->SetBinContent( 7, 0.300);  histo_EM->SetBinError( 7,0.280);
  histo_EM->SetBinContent( 8, 0.492);  histo_EM->SetBinError( 8,0.547);
  histo_EM->SetBinContent( 9, 0.004);  histo_EM->SetBinError( 9,0.004);
  histo_EM->SetBinContent(10, 0.000);  histo_EM->SetBinError(10,0.000);
  histo_EM->SetBinContent(11, 0.354);  histo_EM->SetBinError(11,0.278);

  histo_Zjets->SetBinContent( 1, 2.203);  histo_Zjets->SetBinError( 1, 0.970);
  histo_Zjets->SetBinContent( 2, 3.788);  histo_Zjets->SetBinError( 2, 1.604);
  histo_Zjets->SetBinContent( 3, 5.246);  histo_Zjets->SetBinError( 3, 1.590);
  histo_Zjets->SetBinContent( 4, 2.831);  histo_Zjets->SetBinError( 4, 1.126);
  histo_Zjets->SetBinContent( 5, 0.707);  histo_Zjets->SetBinError( 5, 0.712);
  histo_Zjets->SetBinContent( 6, 1.110);  histo_Zjets->SetBinError( 6, 0.914);
  histo_Zjets->SetBinContent( 7, 0.423);  histo_Zjets->SetBinError( 7, 0.590);
  histo_Zjets->SetBinContent( 8, 0.403);  histo_Zjets->SetBinError( 8, 0.417);
  histo_Zjets->SetBinContent( 9, 0.000);  histo_Zjets->SetBinError( 9, 0.000);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);
  histo_Zjets->SetBinContent(11, 0.360);  histo_Zjets->SetBinError(11, 0.372);

  histo_WZ->SetBinContent( 1,81.677);  histo_WZ->SetBinError( 1,6.293);
  histo_WZ->SetBinContent( 2,83.477);  histo_WZ->SetBinError( 2,6.151);
  histo_WZ->SetBinContent( 3,69.494);  histo_WZ->SetBinError( 3,5.335);
  histo_WZ->SetBinContent( 4,46.845);  histo_WZ->SetBinError( 4,3.712);
  histo_WZ->SetBinContent( 5,29.067);  histo_WZ->SetBinError( 5,2.571);
  histo_WZ->SetBinContent( 6,33.942);  histo_WZ->SetBinError( 6,2.816);
  histo_WZ->SetBinContent( 7,15.784);  histo_WZ->SetBinError( 7,1.681);
  histo_WZ->SetBinContent( 8, 9.090);  histo_WZ->SetBinError( 8,1.004);
  histo_WZ->SetBinContent( 9, 4.167);  histo_WZ->SetBinError( 9,0.625);
  histo_WZ->SetBinContent(10, 3.235);  histo_WZ->SetBinError(10,0.553);
  histo_WZ->SetBinContent(11, 2.147);  histo_WZ->SetBinError(11,0.386);

  histo_ZZ->SetBinContent( 1,7.106);  histo_ZZ->SetBinError( 1,0.373);
  histo_ZZ->SetBinContent( 2,6.744);  histo_ZZ->SetBinError( 2,0.355);
  histo_ZZ->SetBinContent( 3,5.341);  histo_ZZ->SetBinError( 3,0.300);
  histo_ZZ->SetBinContent( 4,3.182);  histo_ZZ->SetBinError( 4,0.235);
  histo_ZZ->SetBinContent( 5,1.975);  histo_ZZ->SetBinError( 5,0.156);
  histo_ZZ->SetBinContent( 6,2.052);  histo_ZZ->SetBinError( 6,0.137);
  histo_ZZ->SetBinContent( 7,0.824);  histo_ZZ->SetBinError( 7,0.086);
  histo_ZZ->SetBinContent( 8,0.389);  histo_ZZ->SetBinError( 8,0.054);
  histo_ZZ->SetBinContent( 9,0.193);  histo_ZZ->SetBinError( 9,0.037);
  histo_ZZ->SetBinContent(10,0.130);  histo_ZZ->SetBinError(10,0.029);
  histo_ZZ->SetBinContent(11,0.044);  histo_ZZ->SetBinError(11,0.015);
  
  histo_VVV->SetBinContent( 1,0.516);  histo_VVV->SetBinError( 1,0.106);
  histo_VVV->SetBinContent( 2,0.708);  histo_VVV->SetBinError( 2,0.117);
  histo_VVV->SetBinContent( 3,0.995);  histo_VVV->SetBinError( 3,0.200);
  histo_VVV->SetBinContent( 4,0.507);  histo_VVV->SetBinError( 4,0.103);
  histo_VVV->SetBinContent( 5,0.542);  histo_VVV->SetBinError( 5,0.115);
  histo_VVV->SetBinContent( 6,0.687);  histo_VVV->SetBinError( 6,0.115);
  histo_VVV->SetBinContent( 7,0.399);  histo_VVV->SetBinError( 7,0.086);
  histo_VVV->SetBinContent( 8,0.261);  histo_VVV->SetBinError( 8,0.066);
  histo_VVV->SetBinContent( 9,0.190);  histo_VVV->SetBinError( 9,0.062);
  histo_VVV->SetBinContent(10,0.134);  histo_VVV->SetBinError(10,0.043);
  histo_VVV->SetBinContent(11,0.076);  histo_VVV->SetBinError(11,0.036);
  
  histo_Higgs->SetBinContent( 1,0.000);  histo_Higgs->SetBinError( 1,0.000);
  histo_Higgs->SetBinContent( 2,0.000);  histo_Higgs->SetBinError( 2,0.000);
  histo_Higgs->SetBinContent( 3,0.000);  histo_Higgs->SetBinError( 3,0.000);
  histo_Higgs->SetBinContent( 4,0.000);  histo_Higgs->SetBinError( 4,0.000);
  histo_Higgs->SetBinContent( 5,0.000);  histo_Higgs->SetBinError( 5,0.000);
  histo_Higgs->SetBinContent( 6,0.000);  histo_Higgs->SetBinError( 6,0.000);
  histo_Higgs->SetBinContent( 7,0.000);  histo_Higgs->SetBinError( 7,0.000);
  histo_Higgs->SetBinContent( 8,0.000);  histo_Higgs->SetBinError( 8,0.000);
  histo_Higgs->SetBinContent( 9,0.000);  histo_Higgs->SetBinError( 9,0.000);
  histo_Higgs->SetBinContent(10,0.000);  histo_Higgs->SetBinError(10,0.000);
  histo_Higgs->SetBinContent(11,0.000);  histo_Higgs->SetBinError(11,0.000);
  }

  TFile* outFilePlotsNote = new TFile(Form("histo_%d.root",nsel),"recreate");
  outFilePlotsNote->cd();
  histo_Data	 ->Write();
  histo_EM	 ->Write();
  histo_Zjets	 ->Write();
  histo_WZ	 ->Write();
  histo_ZZ	 ->Write();
  histo_VVV	 ->Write();
  histo_Higgs    ->Write();
  outFilePlotsNote->Close();
  }
  else if(nsel == 2){
  TH1D *histo_Data     = (TH1D*) histoMVA->Clone("histo0");
  TH1D *histo_EM       = (TH1D*) histoMVA->Clone("histo1");    
  TH1D *histo_Zjets    = (TH1D*) histoMVA->Clone("histo2");         
  TH1D *histo_WZ       = (TH1D*) histoMVA->Clone("histo3");    
  TH1D *histo_ZZ       = (TH1D*) histoMVA->Clone("histo4");
  TH1D *histo_VVV      = (TH1D*) histoMVA->Clone("histo5");   
  TH1D *histo_ZH_hinv  = (TH1D*) histoMVA->Clone("histo6"); 
  TH1D *histo_ggZH_hinv= (TH1D*) histoMVA->Clone("histo7");

  histo_Data->SetBinContent( 1,  1439);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,   311);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,   155);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,    87);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,    50);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,    56);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,    15);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,    11);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,     6);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,     6);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));
  histo_Data->SetBinContent(11,     1);  histo_Data->SetBinError(11, sqrt(histo_Data->GetBinContent(11)));

  histo_EM->SetBinContent( 1, 229.409);  histo_EM->SetBinError( 1, 56.922);
  histo_EM->SetBinContent( 2,  53.541);  histo_EM->SetBinError( 2, 13.873);
  histo_EM->SetBinContent( 3,  16.016);  histo_EM->SetBinError( 3,  4.213);
  histo_EM->SetBinContent( 4,   3.638);  histo_EM->SetBinError( 4,  1.197);
  histo_EM->SetBinContent( 5,   1.192);  histo_EM->SetBinError( 5,  0.497);
  histo_EM->SetBinContent( 6,   0.832);  histo_EM->SetBinError( 6,  0.499);
  histo_EM->SetBinContent( 7,   0.000);  histo_EM->SetBinError( 7,  0.000);
  histo_EM->SetBinContent( 8,   0.329);  histo_EM->SetBinError( 8,  0.244);
  histo_EM->SetBinContent( 9,   0.000);  histo_EM->SetBinError( 9,  0.000);
  histo_EM->SetBinContent(10,   0.000);  histo_EM->SetBinError(10,  0.000);
  histo_EM->SetBinContent(11,   0.000);  histo_EM->SetBinError(11,  0.000);
 
  histo_Zjets->SetBinContent( 1,962.870);  histo_Zjets->SetBinError( 1, 64.863);
  histo_Zjets->SetBinContent( 2, 59.537);  histo_Zjets->SetBinError( 2, 27.168);
  histo_Zjets->SetBinContent( 3,  4.332);  histo_Zjets->SetBinError( 3,  4.936);
  histo_Zjets->SetBinContent( 4,  5.510);  histo_Zjets->SetBinError( 4,  6.491);
  histo_Zjets->SetBinContent( 5,  2.606);  histo_Zjets->SetBinError( 5,  3.055);
  histo_Zjets->SetBinContent( 6,  0.000);  histo_Zjets->SetBinError( 6,  0.000);
  histo_Zjets->SetBinContent( 7,  0.000);  histo_Zjets->SetBinError( 7,  0.000);
  histo_Zjets->SetBinContent( 8,  0.000);  histo_Zjets->SetBinError( 8,  0.000);
  histo_Zjets->SetBinContent( 9,  0.000);  histo_Zjets->SetBinError( 9,  0.000);
  histo_Zjets->SetBinContent(10,  0.000);  histo_Zjets->SetBinError(10,  0.000);
  histo_Zjets->SetBinContent(11,  0.000);  histo_Zjets->SetBinError(11,  0.000);

  histo_WZ->SetBinContent( 1,103.892);  histo_WZ->SetBinError( 1, 8.307);
  histo_WZ->SetBinContent( 2, 65.882);  histo_WZ->SetBinError( 2, 5.428);
  histo_WZ->SetBinContent( 3, 44.623);  histo_WZ->SetBinError( 3, 3.938);
  histo_WZ->SetBinContent( 4, 22.536);  histo_WZ->SetBinError( 4, 2.114);
  histo_WZ->SetBinContent( 5, 14.403);  histo_WZ->SetBinError( 5, 1.569);
  histo_WZ->SetBinContent( 6, 13.913);  histo_WZ->SetBinError( 6, 1.565);
  histo_WZ->SetBinContent( 7,  3.878);  histo_WZ->SetBinError( 7, 0.581);
  histo_WZ->SetBinContent( 8,  2.004);  histo_WZ->SetBinError( 8, 0.411);
  histo_WZ->SetBinContent( 9,  1.094);  histo_WZ->SetBinError( 9, 0.333);
  histo_WZ->SetBinContent(10,  0.468);  histo_WZ->SetBinError(10, 0.188);
  histo_WZ->SetBinContent(11,  0.191);  histo_WZ->SetBinError(11, 0.127);

  histo_ZZ->SetBinContent( 1,152.815);  histo_ZZ->SetBinError( 1,15.940);
  histo_ZZ->SetBinContent( 2,132.139);  histo_ZZ->SetBinError( 2,14.503);
  histo_ZZ->SetBinContent( 3, 98.158);  histo_ZZ->SetBinError( 3,11.331);
  histo_ZZ->SetBinContent( 4, 64.505);  histo_ZZ->SetBinError( 4, 7.894);
  histo_ZZ->SetBinContent( 5, 39.822);  histo_ZZ->SetBinError( 5, 5.281);
  histo_ZZ->SetBinContent( 6, 40.210);  histo_ZZ->SetBinError( 6, 5.679);
  histo_ZZ->SetBinContent( 7, 17.328);  histo_ZZ->SetBinError( 7, 2.699);
  histo_ZZ->SetBinContent( 8,  8.080);  histo_ZZ->SetBinError( 8, 1.366);
  histo_ZZ->SetBinContent( 9,  4.036);  histo_ZZ->SetBinError( 9, 0.739);
  histo_ZZ->SetBinContent(10,  3.329);  histo_ZZ->SetBinError(10, 0.682);
  histo_ZZ->SetBinContent(11,  1.614);  histo_ZZ->SetBinError(11, 0.379);

  histo_VVV->SetBinContent( 1,0.499);  histo_VVV->SetBinError( 1,0.083);
  histo_VVV->SetBinContent( 2,0.543);  histo_VVV->SetBinError( 2,0.099);
  histo_VVV->SetBinContent( 3,0.560);  histo_VVV->SetBinError( 3,0.097);
  histo_VVV->SetBinContent( 4,0.384);  histo_VVV->SetBinError( 4,0.093);
  histo_VVV->SetBinContent( 5,0.367);  histo_VVV->SetBinError( 5,0.080);
  histo_VVV->SetBinContent( 6,0.206);  histo_VVV->SetBinError( 6,0.057);
  histo_VVV->SetBinContent( 7,0.240);  histo_VVV->SetBinError( 7,0.059);
  histo_VVV->SetBinContent( 8,0.126);  histo_VVV->SetBinError( 8,0.055);
  histo_VVV->SetBinContent( 9,0.068);  histo_VVV->SetBinError( 9,0.034);
  histo_VVV->SetBinContent(10,0.044);  histo_VVV->SetBinError(10,0.033);
  histo_VVV->SetBinContent(11,0.043);  histo_VVV->SetBinError(11,0.015);
  
  histo_ZH_hinv->SetBinContent( 1,32.190);  histo_ZH_hinv->SetBinError( 1,2.868);
  histo_ZH_hinv->SetBinContent( 2,37.201);  histo_ZH_hinv->SetBinError( 2,3.266);
  histo_ZH_hinv->SetBinContent( 3,33.180);  histo_ZH_hinv->SetBinError( 3,2.890);
  histo_ZH_hinv->SetBinContent( 4,25.990);  histo_ZH_hinv->SetBinError( 4,2.021);
  histo_ZH_hinv->SetBinContent( 5,17.752);  histo_ZH_hinv->SetBinError( 5,1.424);
  histo_ZH_hinv->SetBinContent( 6,20.847);  histo_ZH_hinv->SetBinError( 6,1.439);
  histo_ZH_hinv->SetBinContent( 7,10.984);  histo_ZH_hinv->SetBinError( 7,0.841);
  histo_ZH_hinv->SetBinContent( 8, 5.444);  histo_ZH_hinv->SetBinError( 8,0.503);
  histo_ZH_hinv->SetBinContent( 9, 2.682);  histo_ZH_hinv->SetBinError( 9,0.311);
  histo_ZH_hinv->SetBinContent(10, 2.908);  histo_ZH_hinv->SetBinError(10,0.299);
  histo_ZH_hinv->SetBinContent(11, 1.550);  histo_ZH_hinv->SetBinError(11,0.214);

  histo_ggZH_hinv->SetBinContent( 1, 4.873);  histo_ggZH_hinv->SetBinError( 1,1.229);
  histo_ggZH_hinv->SetBinContent( 2, 8.319);  histo_ggZH_hinv->SetBinError( 2,2.095);
  histo_ggZH_hinv->SetBinContent( 3,10.308);  histo_ggZH_hinv->SetBinError( 3,2.722);
  histo_ggZH_hinv->SetBinContent( 4, 8.821);  histo_ggZH_hinv->SetBinError( 4,2.368);
  histo_ggZH_hinv->SetBinContent( 5, 5.926);  histo_ggZH_hinv->SetBinError( 5,1.635);
  histo_ggZH_hinv->SetBinContent( 6, 5.888);  histo_ggZH_hinv->SetBinError( 6,1.698);
  histo_ggZH_hinv->SetBinContent( 7, 2.126);  histo_ggZH_hinv->SetBinError( 7,0.657);
  histo_ggZH_hinv->SetBinContent( 8, 0.782);  histo_ggZH_hinv->SetBinError( 8,0.253);
  histo_ggZH_hinv->SetBinContent( 9, 0.298);  histo_ggZH_hinv->SetBinError( 9,0.100);
  histo_ggZH_hinv->SetBinContent(10, 0.164);  histo_ggZH_hinv->SetBinError(10,0.059);
  histo_ggZH_hinv->SetBinContent(11, 0.039);  histo_ggZH_hinv->SetBinError(11,0.016);

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
}
