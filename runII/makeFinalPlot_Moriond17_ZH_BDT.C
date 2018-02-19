void makeFinalPlot_Moriond17_ZH_BDT(int nsel = 0){

  const int nBinMVA = 10; Float_t xbins[nBinMVA+1] = {0.20,0.30,0.40,0.50,0.60,0.65,0.70,0.75,0.80,0.85,0.90};
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
  histo_Data->SetBinContent( 1,0);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,4);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,7);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,5);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,6);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,4);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,5);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,6);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,3);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,0);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

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

  histo_ZZ->SetBinContent( 1,1.050);  histo_ZZ->SetBinError( 1,0.109);
  histo_ZZ->SetBinContent( 2,3.694);  histo_ZZ->SetBinError( 2,0.352);
  histo_ZZ->SetBinContent( 3,5.345);  histo_ZZ->SetBinError( 3,0.545);
  histo_ZZ->SetBinContent( 4,6.612);  histo_ZZ->SetBinError( 4,0.642);
  histo_ZZ->SetBinContent( 5,4.793);  histo_ZZ->SetBinError( 5,0.462);
  histo_ZZ->SetBinContent( 6,6.594);  histo_ZZ->SetBinError( 6,0.659);
  histo_ZZ->SetBinContent( 7,7.395);  histo_ZZ->SetBinError( 7,0.780);
  histo_ZZ->SetBinContent( 8,6.875);  histo_ZZ->SetBinError( 8,0.784);
  histo_ZZ->SetBinContent( 9,4.206);  histo_ZZ->SetBinError( 9,0.536);
  histo_ZZ->SetBinContent(10,0.082);  histo_ZZ->SetBinError(10,0.022);

  histo_VVV->SetBinContent( 1,0.000);  histo_VVV->SetBinError( 1,0.000);
  histo_VVV->SetBinContent( 2,0.017);  histo_VVV->SetBinError( 2,0.014);
  histo_VVV->SetBinContent( 3,0.031);  histo_VVV->SetBinError( 3,0.015);
  histo_VVV->SetBinContent( 4,0.027);  histo_VVV->SetBinError( 4,0.011);
  histo_VVV->SetBinContent( 5,0.076);  histo_VVV->SetBinError( 5,0.040);
  histo_VVV->SetBinContent( 6,0.077);  histo_VVV->SetBinError( 6,0.036);
  histo_VVV->SetBinContent( 7,0.048);  histo_VVV->SetBinError( 7,0.021);
  histo_VVV->SetBinContent( 8,0.134);  histo_VVV->SetBinError( 8,0.044);
  histo_VVV->SetBinContent( 9,0.054);  histo_VVV->SetBinError( 9,0.029);
  histo_VVV->SetBinContent(10,0.000);  histo_VVV->SetBinError(10,0.000);
  
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

  }
  else if(nsel == 1){
  histo_Data->SetBinContent( 1,20);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,27);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,41);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,49);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,41);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,45);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,61);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,55);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,27);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10, 0);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));
      
  histo_EM->SetBinContent( 1, 0.33);  histo_EM->SetBinError( 1, 0.25); 
  histo_EM->SetBinContent( 2, 6.37);  histo_EM->SetBinError( 2, 2.42); 
  histo_EM->SetBinContent( 3, 3.41);  histo_EM->SetBinError( 3, 1.70); 
  histo_EM->SetBinContent( 4, 3.62);  histo_EM->SetBinError( 4, 2.68); 
  histo_EM->SetBinContent( 5, 6.23);  histo_EM->SetBinError( 5, 2.65); 
  histo_EM->SetBinContent( 6, 6.99);  histo_EM->SetBinError( 6, 2.96); 
  histo_EM->SetBinContent( 7, 3.88);  histo_EM->SetBinError( 7, 2.55);
  histo_EM->SetBinContent( 8, 1.77);  histo_EM->SetBinError( 8, 1.07);
  histo_EM->SetBinContent( 9, 1.89);  histo_EM->SetBinError( 9, 1.66);
  histo_EM->SetBinContent(10, 0.00);  histo_EM->SetBinError(10, 0.00);

  histo_Zjets->SetBinContent( 1, 0.866);  histo_Zjets->SetBinError( 1, 0.680);
  histo_Zjets->SetBinContent( 2, 1.562);  histo_Zjets->SetBinError( 2, 0.774);
  histo_Zjets->SetBinContent( 3, 1.457);  histo_Zjets->SetBinError( 3, 1.025);
  histo_Zjets->SetBinContent( 4, 1.322);  histo_Zjets->SetBinError( 4, 0.761);
  histo_Zjets->SetBinContent( 5, 2.043);  histo_Zjets->SetBinError( 5, 0.899);
  histo_Zjets->SetBinContent( 6, 1.050);  histo_Zjets->SetBinError( 6, 1.111);
  histo_Zjets->SetBinContent( 7, 1.437);  histo_Zjets->SetBinError( 7, 0.777);
  histo_Zjets->SetBinContent( 8, 3.218);  histo_Zjets->SetBinError( 8, 1.277);
  histo_Zjets->SetBinContent( 9, 0.748);  histo_Zjets->SetBinError( 9, 0.726);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);

  histo_WZ->SetBinContent( 1,13.269);  histo_WZ->SetBinError( 1,1.205);
  histo_WZ->SetBinContent( 2,25.392);  histo_WZ->SetBinError( 2,1.872);
  histo_WZ->SetBinContent( 3,31.633);  histo_WZ->SetBinError( 3,2.505);
  histo_WZ->SetBinContent( 4,42.581);  histo_WZ->SetBinError( 4,3.260);
  histo_WZ->SetBinContent( 5,29.767);  histo_WZ->SetBinError( 5,2.381);
  histo_WZ->SetBinContent( 6,43.295);  histo_WZ->SetBinError( 6,3.128);
  histo_WZ->SetBinContent( 7,49.693);  histo_WZ->SetBinError( 7,3.536);
  histo_WZ->SetBinContent( 8,49.615);  histo_WZ->SetBinError( 8,3.413);
  histo_WZ->SetBinContent( 9,29.052);  histo_WZ->SetBinError( 9,2.388);
  histo_WZ->SetBinContent(10, 0.310);  histo_WZ->SetBinError(10,0.148);

  histo_ZZ->SetBinContent( 1,0.973);  histo_ZZ->SetBinError( 1,0.079);
  histo_ZZ->SetBinContent( 2,1.877);  histo_ZZ->SetBinError( 2,0.132);
  histo_ZZ->SetBinContent( 3,2.423);  histo_ZZ->SetBinError( 3,0.164);
  histo_ZZ->SetBinContent( 4,3.154);  histo_ZZ->SetBinError( 4,0.182);
  histo_ZZ->SetBinContent( 5,2.303);  histo_ZZ->SetBinError( 5,0.161);
  histo_ZZ->SetBinContent( 6,2.998);  histo_ZZ->SetBinError( 6,0.197);
  histo_ZZ->SetBinContent( 7,3.025);  histo_ZZ->SetBinError( 7,0.179);
  histo_ZZ->SetBinContent( 8,2.520);  histo_ZZ->SetBinError( 8,0.147);
  histo_ZZ->SetBinContent( 9,1.187);  histo_ZZ->SetBinError( 9,0.105);
  histo_ZZ->SetBinContent(10,0.015);  histo_ZZ->SetBinError(10,0.009);

  histo_VVV->SetBinContent( 1,0.085);  histo_VVV->SetBinError( 1,0.044);
  histo_VVV->SetBinContent( 2,0.317);  histo_VVV->SetBinError( 2,0.124);
  histo_VVV->SetBinContent( 3,0.393);  histo_VVV->SetBinError( 3,0.091);
  histo_VVV->SetBinContent( 4,0.390);  histo_VVV->SetBinError( 4,0.076);
  histo_VVV->SetBinContent( 5,0.384);  histo_VVV->SetBinError( 5,0.078);
  histo_VVV->SetBinContent( 6,0.659);  histo_VVV->SetBinError( 6,0.133);
  histo_VVV->SetBinContent( 7,0.731);  histo_VVV->SetBinError( 7,0.106);
  histo_VVV->SetBinContent( 8,0.738);  histo_VVV->SetBinError( 8,0.131);
  histo_VVV->SetBinContent( 9,0.675);  histo_VVV->SetBinError( 9,0.117);
  histo_VVV->SetBinContent(10,0.001);  histo_VVV->SetBinError(10,0.001);
  
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
  }

  TFile* outFilePlotsNote = new TFile(Form("histo_%d_bdt.root",nsel),"recreate");
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

  histo_Data->SetBinContent( 1,652);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,215);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,152);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,152);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,101);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,118);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7, 95);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8, 69);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9, 32);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,  0);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

  histo_EM->SetBinContent( 1, 296.733);  histo_EM->SetBinError( 1, 46.089);
  histo_EM->SetBinContent( 2,  52.210);  histo_EM->SetBinError( 2,  8.604);
  histo_EM->SetBinContent( 3,  16.948);  histo_EM->SetBinError( 3,  3.230);
  histo_EM->SetBinContent( 4,   6.821);  histo_EM->SetBinError( 4,  1.444);
  histo_EM->SetBinContent( 5,   2.952);  histo_EM->SetBinError( 5,  0.886);
  histo_EM->SetBinContent( 6,   1.007);  histo_EM->SetBinError( 6,  0.364);
  histo_EM->SetBinContent( 7,   1.156);  histo_EM->SetBinError( 7,  0.508);
  histo_EM->SetBinContent( 8,   0.322);  histo_EM->SetBinError( 8,  0.230);
  histo_EM->SetBinContent( 9,   0.206);  histo_EM->SetBinError( 9,  0.264);
  histo_EM->SetBinContent(10,   0.000);  histo_EM->SetBinError(10,  0.000);
 
  histo_Zjets->SetBinContent( 1,134.212);  histo_Zjets->SetBinError( 1, 58.794);
  histo_Zjets->SetBinContent( 2, 27.951);  histo_Zjets->SetBinError( 2, 15.096);
  histo_Zjets->SetBinContent( 3,  8.874);  histo_Zjets->SetBinError( 3, 22.945);
  histo_Zjets->SetBinContent( 4, 13.576);  histo_Zjets->SetBinError( 4,  8.199);
  histo_Zjets->SetBinContent( 5,  2.368);  histo_Zjets->SetBinError( 5,  6.097);
  histo_Zjets->SetBinContent( 6,  2.925);  histo_Zjets->SetBinError( 6,  4.108);
  histo_Zjets->SetBinContent( 7,  2.835);  histo_Zjets->SetBinError( 7,  1.919);
  histo_Zjets->SetBinContent( 8,  0.236);  histo_Zjets->SetBinError( 8,  0.305);
  histo_Zjets->SetBinContent( 9,  0.000);  histo_Zjets->SetBinError( 9,  0.000);
  histo_Zjets->SetBinContent(10,  0.000);  histo_Zjets->SetBinError(10,  0.000);

  histo_WZ->SetBinContent( 1,85.140);  histo_WZ->SetBinError( 1, 8.374);
  histo_WZ->SetBinContent( 2,49.721);  histo_WZ->SetBinError( 2, 4.110);
  histo_WZ->SetBinContent( 3,35.778);  histo_WZ->SetBinError( 3, 3.294);
  histo_WZ->SetBinContent( 4,41.844);  histo_WZ->SetBinError( 4, 3.766);
  histo_WZ->SetBinContent( 5,26.291);  histo_WZ->SetBinError( 5, 2.468);
  histo_WZ->SetBinContent( 6,31.992);  histo_WZ->SetBinError( 6, 3.199);
  histo_WZ->SetBinContent( 7,31.868);  histo_WZ->SetBinError( 7, 3.124);
  histo_WZ->SetBinContent( 8,21.347);  histo_WZ->SetBinError( 8, 2.073);
  histo_WZ->SetBinContent( 9, 7.850);  histo_WZ->SetBinError( 9, 1.041);
  histo_WZ->SetBinContent(10, 0.000);  histo_WZ->SetBinError(10, 0.000);

  histo_ZZ->SetBinContent( 1,153.364);  histo_ZZ->SetBinError( 1,17.634);
  histo_ZZ->SetBinContent( 2, 96.232);  histo_ZZ->SetBinError( 2, 9.267);
  histo_ZZ->SetBinContent( 3, 77.063);  histo_ZZ->SetBinError( 3, 7.533);
  histo_ZZ->SetBinContent( 4, 89.018);  histo_ZZ->SetBinError( 4, 8.855);
  histo_ZZ->SetBinContent( 5, 60.318);  histo_ZZ->SetBinError( 5, 6.295);
  histo_ZZ->SetBinContent( 6, 79.516);  histo_ZZ->SetBinError( 6, 8.578);
  histo_ZZ->SetBinContent( 7, 78.396);  histo_ZZ->SetBinError( 7, 8.874);
  histo_ZZ->SetBinContent( 8, 65.576);  histo_ZZ->SetBinError( 8, 8.065);
  histo_ZZ->SetBinContent( 9, 31.787);  histo_ZZ->SetBinError( 9, 4.568);
  histo_ZZ->SetBinContent(10,  0.350);  histo_ZZ->SetBinError(10, 0.071);

  histo_VVV->SetBinContent( 1,1.221);  histo_VVV->SetBinError( 1,0.163);
  histo_VVV->SetBinContent( 2,0.692);  histo_VVV->SetBinError( 2,0.108);
  histo_VVV->SetBinContent( 3,0.457);  histo_VVV->SetBinError( 3,0.108);
  histo_VVV->SetBinContent( 4,0.658);  histo_VVV->SetBinError( 4,0.120);
  histo_VVV->SetBinContent( 5,0.406);  histo_VVV->SetBinError( 5,0.111);
  histo_VVV->SetBinContent( 6,0.576);  histo_VVV->SetBinError( 6,0.098);
  histo_VVV->SetBinContent( 7,0.802);  histo_VVV->SetBinError( 7,0.139);
  histo_VVV->SetBinContent( 8,0.449);  histo_VVV->SetBinError( 8,0.161);
  histo_VVV->SetBinContent( 9,0.254);  histo_VVV->SetBinError( 9,0.061);
  histo_VVV->SetBinContent(10,0.013);  histo_VVV->SetBinError(10,0.012);
  
  histo_ZH_hinv->SetBinContent( 1,21.806);  histo_ZH_hinv->SetBinError( 1,2.321);
  histo_ZH_hinv->SetBinContent( 2,18.000);  histo_ZH_hinv->SetBinError( 2,1.690);
  histo_ZH_hinv->SetBinContent( 3,15.213);  histo_ZH_hinv->SetBinError( 3,1.514);
  histo_ZH_hinv->SetBinContent( 4,20.851);  histo_ZH_hinv->SetBinError( 4,1.815);
  histo_ZH_hinv->SetBinContent( 5,16.536);  histo_ZH_hinv->SetBinError( 5,1.394);
  histo_ZH_hinv->SetBinContent( 6,24.137);  histo_ZH_hinv->SetBinError( 6,2.098);
  histo_ZH_hinv->SetBinContent( 7,27.760);  histo_ZH_hinv->SetBinError( 7,2.041);
  histo_ZH_hinv->SetBinContent( 8,32.185);  histo_ZH_hinv->SetBinError( 8,2.472);
  histo_ZH_hinv->SetBinContent( 9,21.625);  histo_ZH_hinv->SetBinError( 9,1.681);
  histo_ZH_hinv->SetBinContent(10, 0.491);  histo_ZH_hinv->SetBinError(10,0.153);

  histo_ggZH_hinv->SetBinContent( 1, 4.027);  histo_ggZH_hinv->SetBinError( 1,1.040);
  histo_ggZH_hinv->SetBinContent( 2, 4.152);  histo_ggZH_hinv->SetBinError( 2,1.095);
  histo_ggZH_hinv->SetBinContent( 3, 4.706);  histo_ggZH_hinv->SetBinError( 3,1.271);
  histo_ggZH_hinv->SetBinContent( 4, 7.330);  histo_ggZH_hinv->SetBinError( 4,1.983);
  histo_ggZH_hinv->SetBinContent( 5, 6.662);  histo_ggZH_hinv->SetBinError( 5,1.833);
  histo_ggZH_hinv->SetBinContent( 6,10.246);  histo_ggZH_hinv->SetBinError( 6,2.834);
  histo_ggZH_hinv->SetBinContent( 7,11.387);  histo_ggZH_hinv->SetBinError( 7,3.169);
  histo_ggZH_hinv->SetBinContent( 8,10.007);  histo_ggZH_hinv->SetBinError( 8,2.881);
  histo_ggZH_hinv->SetBinContent( 9, 4.094);  histo_ggZH_hinv->SetBinError( 9,1.231);
  histo_ggZH_hinv->SetBinContent(10, 0.039);  histo_ggZH_hinv->SetBinError(10,0.013);

  TFile* outFilePlotsNote = new TFile(Form("histo_%d_bdt.root",nsel),"recreate");
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
