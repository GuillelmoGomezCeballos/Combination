void makeFinalPlot_Moriond17_ZH_BDT(int nsel = 0){

  const int nBinMVA = 10; Float_t xbins[nBinMVA+1] = {0.2, 0.3, 0.4, 0.5, 0.6, 0.65, 0.70, 0.75, 0.80, 0.9, 1.0};
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
  histo_Data->SetBinContent( 1,   0);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,   3);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,   3);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,   6);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,   4);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,  10);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,   6);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,   6);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,   1);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,   1);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

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

  histo_ZZ->SetBinContent( 1,0.174);  histo_ZZ->SetBinError( 1,0.029);
  histo_ZZ->SetBinContent( 2,1.445);  histo_ZZ->SetBinError( 2,0.114);
  histo_ZZ->SetBinContent( 3,4.220);  histo_ZZ->SetBinError( 3,0.311);
  histo_ZZ->SetBinContent( 4,6.160);  histo_ZZ->SetBinError( 4,0.430);
  histo_ZZ->SetBinContent( 5,3.945);  histo_ZZ->SetBinError( 5,0.302);
  histo_ZZ->SetBinContent( 6,7.434);  histo_ZZ->SetBinError( 6,0.530);
  histo_ZZ->SetBinContent( 7,8.303);  histo_ZZ->SetBinError( 7,0.573);
  histo_ZZ->SetBinContent( 8,6.127);  histo_ZZ->SetBinError( 8,0.473);
  histo_ZZ->SetBinContent( 9,3.567);  histo_ZZ->SetBinError( 9,0.330);
  histo_ZZ->SetBinContent(10,0.370);  histo_ZZ->SetBinError(10,0.054);

  histo_VVV->SetBinContent( 1,0.000);  histo_VVV->SetBinError( 1,0.000);
  histo_VVV->SetBinContent( 2,0.005);  histo_VVV->SetBinError( 2,0.003);
  histo_VVV->SetBinContent( 3,0.014);  histo_VVV->SetBinError( 3,0.010);
  histo_VVV->SetBinContent( 4,0.037);  histo_VVV->SetBinError( 4,0.019);
  histo_VVV->SetBinContent( 5,0.048);  histo_VVV->SetBinError( 5,0.028);
  histo_VVV->SetBinContent( 6,0.089);  histo_VVV->SetBinError( 6,0.037);
  histo_VVV->SetBinContent( 7,0.121);  histo_VVV->SetBinError( 7,0.040);
  histo_VVV->SetBinContent( 8,0.101);  histo_VVV->SetBinError( 8,0.031);
  histo_VVV->SetBinContent( 9,0.055);  histo_VVV->SetBinError( 9,0.026);
  histo_VVV->SetBinContent(10,0.003);  histo_VVV->SetBinError(10,0.002);
  
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
  histo_Data->SetBinContent( 1,   1);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,  24);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,  36);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,  55);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,  25);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,  60);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,  77);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,  54);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,  29);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,   5);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

  histo_EM->SetBinContent( 1, 0.001);  histo_EM->SetBinError( 1, 0.001); 
  histo_EM->SetBinContent( 2, 2.808);  histo_EM->SetBinError( 2, 3.130); 
  histo_EM->SetBinContent( 3, 8.102);  histo_EM->SetBinError( 3, 3.169); 
  histo_EM->SetBinContent( 4, 7.249);  histo_EM->SetBinError( 4, 3.835); 
  histo_EM->SetBinContent( 5, 4.061);  histo_EM->SetBinError( 5, 1.957); 
  histo_EM->SetBinContent( 6, 8.808);  histo_EM->SetBinError( 6, 3.507); 
  histo_EM->SetBinContent( 7, 9.806);  histo_EM->SetBinError( 7, 4.457);
  histo_EM->SetBinContent( 8, 3.558);  histo_EM->SetBinError( 8, 3.094);
  histo_EM->SetBinContent( 9, 0.557);  histo_EM->SetBinError( 9, 0.852);
  histo_EM->SetBinContent(10, 0.406);  histo_EM->SetBinError(10, 1.116);

  histo_Zjets->SetBinContent( 1, 0.379);  histo_Zjets->SetBinError( 1, 0.423);
  histo_Zjets->SetBinContent( 2, 0.458);  histo_Zjets->SetBinError( 2, 1.764);
  histo_Zjets->SetBinContent( 3, 1.922);  histo_Zjets->SetBinError( 3, 0.700);
  histo_Zjets->SetBinContent( 4, 2.211);  histo_Zjets->SetBinError( 4, 0.912);
  histo_Zjets->SetBinContent( 5, 0.334);  histo_Zjets->SetBinError( 5, 0.458);
  histo_Zjets->SetBinContent( 6, 2.764);  histo_Zjets->SetBinError( 6, 1.173);
  histo_Zjets->SetBinContent( 7, 1.789);  histo_Zjets->SetBinError( 7, 1.820);
  histo_Zjets->SetBinContent( 8, 3.507);  histo_Zjets->SetBinError( 8, 1.307);
  histo_Zjets->SetBinContent( 9, 0.717);  histo_Zjets->SetBinError( 9, 0.797);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);

  histo_WZ->SetBinContent( 1, 1.196);  histo_WZ->SetBinError( 1,0.321);
  histo_WZ->SetBinContent( 2,13.195);  histo_WZ->SetBinError( 2,1.243);
  histo_WZ->SetBinContent( 3,26.684);  histo_WZ->SetBinError( 3,2.005);
  histo_WZ->SetBinContent( 4,38.870);  histo_WZ->SetBinError( 4,2.976);
  histo_WZ->SetBinContent( 5,26.070);  histo_WZ->SetBinError( 5,2.057);
  histo_WZ->SetBinContent( 6,49.984);  histo_WZ->SetBinError( 6,3.479);
  histo_WZ->SetBinContent( 7,57.632);  histo_WZ->SetBinError( 7,4.052);
  histo_WZ->SetBinContent( 8,45.276);  histo_WZ->SetBinError( 8,3.422);
  histo_WZ->SetBinContent( 9,29.898);  histo_WZ->SetBinError( 9,2.178);
  histo_WZ->SetBinContent(10, 2.403);  histo_WZ->SetBinError(10,0.494);

  histo_ZZ->SetBinContent( 1,0.213);  histo_ZZ->SetBinError( 1,0.034);
  histo_ZZ->SetBinContent( 2,1.054);  histo_ZZ->SetBinError( 2,0.081);
  histo_ZZ->SetBinContent( 3,2.263);  histo_ZZ->SetBinError( 3,0.143);
  histo_ZZ->SetBinContent( 4,3.157);  histo_ZZ->SetBinError( 4,0.189);
  histo_ZZ->SetBinContent( 5,2.482);  histo_ZZ->SetBinError( 5,0.160);
  histo_ZZ->SetBinContent( 6,3.743);  histo_ZZ->SetBinError( 6,0.212);
  histo_ZZ->SetBinContent( 7,3.743);  histo_ZZ->SetBinError( 7,0.215);
  histo_ZZ->SetBinContent( 8,2.642);  histo_ZZ->SetBinError( 8,0.172);
  histo_ZZ->SetBinContent( 9,1.377);  histo_ZZ->SetBinError( 9,0.109);
  histo_ZZ->SetBinContent(10,0.080);  histo_ZZ->SetBinError(10,0.020);

  histo_VVV->SetBinContent( 1,0.093);  histo_VVV->SetBinError( 1,0.053);
  histo_VVV->SetBinContent( 2,0.207);  histo_VVV->SetBinError( 2,0.128);
  histo_VVV->SetBinContent( 3,0.262);  histo_VVV->SetBinError( 3,0.069);
  histo_VVV->SetBinContent( 4,0.442);  histo_VVV->SetBinError( 4,0.097);
  histo_VVV->SetBinContent( 5,0.390);  histo_VVV->SetBinError( 5,0.088);
  histo_VVV->SetBinContent( 6,0.729);  histo_VVV->SetBinError( 6,0.125);
  histo_VVV->SetBinContent( 7,0.817);  histo_VVV->SetBinError( 7,0.128);
  histo_VVV->SetBinContent( 8,0.748);  histo_VVV->SetBinError( 8,0.129);
  histo_VVV->SetBinContent( 9,0.778);  histo_VVV->SetBinError( 9,0.130);
  histo_VVV->SetBinContent(10,0.051);  histo_VVV->SetBinError(10,0.028);
  
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

  histo_Data->SetBinContent( 1,   777);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,   359);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,   182);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,   176);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,   114);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,   146);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,   117);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,    62);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,    39);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10,     5);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

  histo_EM->SetBinContent( 1, 441.492);  histo_EM->SetBinError( 1, 50.954);
  histo_EM->SetBinContent( 2, 111.370);  histo_EM->SetBinError( 2, 13.254);
  histo_EM->SetBinContent( 3,  32.619);  histo_EM->SetBinError( 3,  3.823);
  histo_EM->SetBinContent( 4,  10.177);  histo_EM->SetBinError( 4,  1.611);
  histo_EM->SetBinContent( 5,   2.687);  histo_EM->SetBinError( 5,  0.576);
  histo_EM->SetBinContent( 6,   3.019);  histo_EM->SetBinError( 6,  0.690);
  histo_EM->SetBinContent( 7,   1.293);  histo_EM->SetBinError( 7,  0.458);
  histo_EM->SetBinContent( 8,   0.077);  histo_EM->SetBinError( 8,  0.063);
  histo_EM->SetBinContent( 9,   0.170);  histo_EM->SetBinError( 9,  0.131);
  histo_EM->SetBinContent(10,   0.000);  histo_EM->SetBinError(10,  0.000);
 
  histo_Zjets->SetBinContent( 1,205.646);  histo_Zjets->SetBinError( 1, 64.098);
  histo_Zjets->SetBinContent( 2, 74.547);  histo_Zjets->SetBinError( 2, 27.300);
  histo_Zjets->SetBinContent( 3, 31.272);  histo_Zjets->SetBinError( 3, 13.962);
  histo_Zjets->SetBinContent( 4, 30.116);  histo_Zjets->SetBinError( 4, 14.589);
  histo_Zjets->SetBinContent( 5, 18.227);  histo_Zjets->SetBinError( 5, 20.122);
  histo_Zjets->SetBinContent( 6,  3.165);  histo_Zjets->SetBinError( 6,  3.165);
  histo_Zjets->SetBinContent( 7,  3.274);  histo_Zjets->SetBinError( 7,  2.587);
  histo_Zjets->SetBinContent( 8,  1.464);  histo_Zjets->SetBinError( 8,  1.443);
  histo_Zjets->SetBinContent( 9,  0.000);  histo_Zjets->SetBinError( 9,  0.000);
  histo_Zjets->SetBinContent(10,  0.000);  histo_Zjets->SetBinError(10,  0.000);

  histo_WZ->SetBinContent( 1,59.065);  histo_WZ->SetBinError( 1, 5.673);
  histo_WZ->SetBinContent( 2,56.206);  histo_WZ->SetBinError( 2, 4.848);
  histo_WZ->SetBinContent( 3,41.824);  histo_WZ->SetBinError( 3, 3.420);
  histo_WZ->SetBinContent( 4,40.314);  histo_WZ->SetBinError( 4, 3.283);
  histo_WZ->SetBinContent( 5,25.793);  histo_WZ->SetBinError( 5, 2.617);
  histo_WZ->SetBinContent( 6,36.205);  histo_WZ->SetBinError( 6, 3.031);
  histo_WZ->SetBinContent( 7,37.237);  histo_WZ->SetBinError( 7, 3.103);
  histo_WZ->SetBinContent( 8,19.901);  histo_WZ->SetBinError( 8, 2.073);
  histo_WZ->SetBinContent( 9, 8.629);  histo_WZ->SetBinError( 9, 1.184);
  histo_WZ->SetBinContent(10, 0.334);  histo_WZ->SetBinError(10, 0.202);

  histo_ZZ->SetBinContent( 1, 91.262);  histo_ZZ->SetBinError( 1,6.615);
  histo_ZZ->SetBinContent( 2,105.672);  histo_ZZ->SetBinError( 2,6.700);
  histo_ZZ->SetBinContent( 3, 79.880);  histo_ZZ->SetBinError( 3,4.664);
  histo_ZZ->SetBinContent( 4, 81.779);  histo_ZZ->SetBinError( 4,5.003);
  histo_ZZ->SetBinContent( 5, 53.090);  histo_ZZ->SetBinError( 5,3.347);
  histo_ZZ->SetBinContent( 6, 83.005);  histo_ZZ->SetBinError( 6,5.513);
  histo_ZZ->SetBinContent( 7, 88.344);  histo_ZZ->SetBinError( 7,6.042);
  histo_ZZ->SetBinContent( 8, 58.462);  histo_ZZ->SetBinError( 8,4.445);
  histo_ZZ->SetBinContent( 9, 28.858);  histo_ZZ->SetBinError( 9,2.764);
  histo_ZZ->SetBinContent(10,  2.679);  histo_ZZ->SetBinError(10,0.303);

  histo_VVV->SetBinContent( 1,1.059);  histo_VVV->SetBinError( 1,0.154);
  histo_VVV->SetBinContent( 2,0.825);  histo_VVV->SetBinError( 2,0.119);
  histo_VVV->SetBinContent( 3,0.575);  histo_VVV->SetBinError( 3,0.105);
  histo_VVV->SetBinContent( 4,0.564);  histo_VVV->SetBinError( 4,0.108);
  histo_VVV->SetBinContent( 5,0.436);  histo_VVV->SetBinError( 5,0.098);
  histo_VVV->SetBinContent( 6,0.725);  histo_VVV->SetBinError( 6,0.129);
  histo_VVV->SetBinContent( 7,0.679);  histo_VVV->SetBinError( 7,0.125);
  histo_VVV->SetBinContent( 8,0.486);  histo_VVV->SetBinError( 8,0.106);
  histo_VVV->SetBinContent( 9,0.256);  histo_VVV->SetBinError( 9,0.071);
  histo_VVV->SetBinContent(10,0.052);  histo_VVV->SetBinError(10,0.029);
  
  histo_ZH_hinv->SetBinContent( 1,12.716);  histo_ZH_hinv->SetBinError( 1,1.083);
  histo_ZH_hinv->SetBinContent( 2,18.699);  histo_ZH_hinv->SetBinError( 2,1.621);
  histo_ZH_hinv->SetBinContent( 3,17.826);  histo_ZH_hinv->SetBinError( 3,1.502);
  histo_ZH_hinv->SetBinContent( 4,20.464);  histo_ZH_hinv->SetBinError( 4,1.685);
  histo_ZH_hinv->SetBinContent( 5,15.534);  histo_ZH_hinv->SetBinError( 5,1.290);
  histo_ZH_hinv->SetBinContent( 6,28.905);  histo_ZH_hinv->SetBinError( 6,2.155);
  histo_ZH_hinv->SetBinContent( 7,37.291);  histo_ZH_hinv->SetBinError( 7,2.633);
  histo_ZH_hinv->SetBinContent( 8,32.982);  histo_ZH_hinv->SetBinError( 8,2.178);
  histo_ZH_hinv->SetBinContent( 9,23.516);  histo_ZH_hinv->SetBinError( 9,1.704);
  histo_ZH_hinv->SetBinContent(10, 3.265);  histo_ZH_hinv->SetBinError(10,0.378);

  histo_ggZH_hinv->SetBinContent( 1, 2.937);  histo_ggZH_hinv->SetBinError( 1,0.773);
  histo_ggZH_hinv->SetBinContent( 2, 3.787);  histo_ggZH_hinv->SetBinError( 2,1.022);
  histo_ggZH_hinv->SetBinContent( 3, 4.461);  histo_ggZH_hinv->SetBinError( 3,1.238);
  histo_ggZH_hinv->SetBinContent( 4, 6.527);  histo_ggZH_hinv->SetBinError( 4,1.827);
  histo_ggZH_hinv->SetBinContent( 5, 5.855);  histo_ggZH_hinv->SetBinError( 5,1.624);
  histo_ggZH_hinv->SetBinContent( 6,10.639);  histo_ggZH_hinv->SetBinError( 6,3.072);
  histo_ggZH_hinv->SetBinContent( 7,13.725);  histo_ggZH_hinv->SetBinError( 7,3.969);
  histo_ggZH_hinv->SetBinContent( 8,10.551);  histo_ggZH_hinv->SetBinError( 8,3.170);
  histo_ggZH_hinv->SetBinContent( 9, 4.512);  histo_ggZH_hinv->SetBinError( 9,1.453);
  histo_ggZH_hinv->SetBinContent(10, 0.318);  histo_ggZH_hinv->SetBinError(10,0.107);

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
