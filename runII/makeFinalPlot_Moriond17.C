void makeFinalPlot_Moriond17(int nsel = 0){

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
  histo_Data->SetBinContent( 1,  15);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,  14);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,  12);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,   4);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,   4);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,   5);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,   1);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
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

  histo_ZZ->SetBinContent( 1,12.638);  histo_ZZ->SetBinError( 1,1.387);
  histo_ZZ->SetBinContent( 2,12.264);  histo_ZZ->SetBinError( 2,1.378);
  histo_ZZ->SetBinContent( 3, 9.340);  histo_ZZ->SetBinError( 3,1.059);
  histo_ZZ->SetBinContent( 4, 6.671);  histo_ZZ->SetBinError( 4,0.793);
  histo_ZZ->SetBinContent( 5, 4.557);  histo_ZZ->SetBinError( 5,0.590);
  histo_ZZ->SetBinContent( 6, 5.100);  histo_ZZ->SetBinError( 6,0.699);
  histo_ZZ->SetBinContent( 7, 2.095);  histo_ZZ->SetBinError( 7,0.294);
  histo_ZZ->SetBinContent( 8, 1.169);  histo_ZZ->SetBinError( 8,0.192);
  histo_ZZ->SetBinContent( 9, 0.652);  histo_ZZ->SetBinError( 9,0.116);
  histo_ZZ->SetBinContent(10, 0.418);  histo_ZZ->SetBinError(10,0.078);
  histo_ZZ->SetBinContent(11, 0.286);  histo_ZZ->SetBinError(11,0.063);

  histo_VVV->SetBinContent( 1,0.044);  histo_VVV->SetBinError( 1,0.017);
  histo_VVV->SetBinContent( 2,0.113);  histo_VVV->SetBinError( 2,0.041);
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

  histo_EM->SetBinContent( 1, 26.310);  histo_EM->SetBinError( 1,   6.790); 
  histo_EM->SetBinContent( 2, 19.820);  histo_EM->SetBinError( 2,   7.090); 
  histo_EM->SetBinContent( 3,  9.130);  histo_EM->SetBinError( 3,   4.070); 
  histo_EM->SetBinContent( 4,  6.670);  histo_EM->SetBinError( 4,   3.060); 
  histo_EM->SetBinContent( 5,  6.090);  histo_EM->SetBinError( 5,   3.270); 
  histo_EM->SetBinContent( 6,  3.880);  histo_EM->SetBinError( 6,   2.450); 
  histo_EM->SetBinContent( 7,  0.035);  histo_EM->SetBinError( 7,   0.032);
  histo_EM->SetBinContent( 8,  0.621);  histo_EM->SetBinError( 8,   0.562);
  histo_EM->SetBinContent( 9,  0.044);  histo_EM->SetBinError( 9,   0.739);
  histo_EM->SetBinContent(10,  0.000);  histo_EM->SetBinError(10,   0.051);
  histo_EM->SetBinContent(11,  0.260);  histo_EM->SetBinError(11,   0.218);

  histo_Zjets->SetBinContent( 1, 2.187);  histo_Zjets->SetBinError( 1, 0.969);
  histo_Zjets->SetBinContent( 2, 3.768);  histo_Zjets->SetBinError( 2, 1.624);
  histo_Zjets->SetBinContent( 3, 5.226);  histo_Zjets->SetBinError( 3, 1.605);
  histo_Zjets->SetBinContent( 4, 2.786);  histo_Zjets->SetBinError( 4, 1.112);
  histo_Zjets->SetBinContent( 5, 0.704);  histo_Zjets->SetBinError( 5, 0.788);
  histo_Zjets->SetBinContent( 6, 1.113);  histo_Zjets->SetBinError( 6, 0.925);
  histo_Zjets->SetBinContent( 7, 0.416);  histo_Zjets->SetBinError( 7, 1.157);
  histo_Zjets->SetBinContent( 8, 0.397);  histo_Zjets->SetBinError( 8, 0.423);
  histo_Zjets->SetBinContent( 9, 0.000);  histo_Zjets->SetBinError( 9, 0.000);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);
  histo_Zjets->SetBinContent(11, 0.359);  histo_Zjets->SetBinError(11, 0.374);

  histo_WZ->SetBinContent( 1,78.890);  histo_WZ->SetBinError( 1,7.150);
  histo_WZ->SetBinContent( 2,80.722);  histo_WZ->SetBinError( 2,7.095);
  histo_WZ->SetBinContent( 3,67.177);  histo_WZ->SetBinError( 3,6.053);
  histo_WZ->SetBinContent( 4,45.124);  histo_WZ->SetBinError( 4,4.397);
  histo_WZ->SetBinContent( 5,28.166);  histo_WZ->SetBinError( 5,2.794);
  histo_WZ->SetBinContent( 6,32.882);  histo_WZ->SetBinError( 6,3.151);
  histo_WZ->SetBinContent( 7,15.315);  histo_WZ->SetBinError( 7,1.775);
  histo_WZ->SetBinContent( 8, 8.802);  histo_WZ->SetBinError( 8,1.046);
  histo_WZ->SetBinContent( 9, 4.033);  histo_WZ->SetBinError( 9,0.625);
  histo_WZ->SetBinContent(10, 3.133);  histo_WZ->SetBinError(10,0.556);
  histo_WZ->SetBinContent(11, 2.079);  histo_WZ->SetBinError(11,0.377);

  histo_ZZ->SetBinContent( 1,7.104);  histo_ZZ->SetBinError( 1,0.378);
  histo_ZZ->SetBinContent( 2,6.745);  histo_ZZ->SetBinError( 2,0.360);
  histo_ZZ->SetBinContent( 3,5.344);  histo_ZZ->SetBinError( 3,0.302);
  histo_ZZ->SetBinContent( 4,3.180);  histo_ZZ->SetBinError( 4,0.237);
  histo_ZZ->SetBinContent( 5,1.977);  histo_ZZ->SetBinError( 5,0.156);
  histo_ZZ->SetBinContent( 6,2.051);  histo_ZZ->SetBinError( 6,0.139);
  histo_ZZ->SetBinContent( 7,0.823);  histo_ZZ->SetBinError( 7,0.087);
  histo_ZZ->SetBinContent( 8,0.389);  histo_ZZ->SetBinError( 8,0.054);
  histo_ZZ->SetBinContent( 9,0.193);  histo_ZZ->SetBinError( 9,0.037);
  histo_ZZ->SetBinContent(10,0.130);  histo_ZZ->SetBinError(10,0.029);
  histo_ZZ->SetBinContent(11,0.044);  histo_ZZ->SetBinError(11,0.015);
  
  histo_VVV->SetBinContent( 1,0.517);  histo_VVV->SetBinError( 1,0.107);
  histo_VVV->SetBinContent( 2,0.713);  histo_VVV->SetBinError( 2,0.117);
  histo_VVV->SetBinContent( 3,0.994);  histo_VVV->SetBinError( 3,0.201);
  histo_VVV->SetBinContent( 4,0.505);  histo_VVV->SetBinError( 4,0.104);
  histo_VVV->SetBinContent( 5,0.548);  histo_VVV->SetBinError( 5,0.116);
  histo_VVV->SetBinContent( 6,0.690);  histo_VVV->SetBinError( 6,0.116);
  histo_VVV->SetBinContent( 7,0.401);  histo_VVV->SetBinError( 7,0.088);
  histo_VVV->SetBinContent( 8,0.260);  histo_VVV->SetBinError( 8,0.067);
  histo_VVV->SetBinContent( 9,0.189);  histo_VVV->SetBinError( 9,0.062);
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

  histo_EM->SetBinContent( 1, 223.811);  histo_EM->SetBinError( 1, 58.650);
  histo_EM->SetBinContent( 2,  52.102);  histo_EM->SetBinError( 2, 14.243);
  histo_EM->SetBinContent( 3,  15.542);  histo_EM->SetBinError( 3,  4.296);
  histo_EM->SetBinContent( 4,   3.562);  histo_EM->SetBinError( 4,  1.226);
  histo_EM->SetBinContent( 5,   1.174);  histo_EM->SetBinError( 5,  0.507);
  histo_EM->SetBinContent( 6,   0.802);  histo_EM->SetBinError( 6,  0.503);
  histo_EM->SetBinContent( 7,   0.000);  histo_EM->SetBinError( 7,  0.000);
  histo_EM->SetBinContent( 8,   0.314);  histo_EM->SetBinError( 8,  0.243);
  histo_EM->SetBinContent( 9,   0.000);  histo_EM->SetBinError( 9,  0.000);
  histo_EM->SetBinContent(10,   0.000);  histo_EM->SetBinError(10,  0.000);
  histo_EM->SetBinContent(11,   0.000);  histo_EM->SetBinError(11,  0.000);
 
  histo_Zjets->SetBinContent( 1,969.902);  histo_Zjets->SetBinError( 1, 65.372);
  histo_Zjets->SetBinContent( 2, 61.540);  histo_Zjets->SetBinError( 2, 27.317);
  histo_Zjets->SetBinContent( 3,  4.405);  histo_Zjets->SetBinError( 3,  5.099);
  histo_Zjets->SetBinContent( 4,  5.627);  histo_Zjets->SetBinError( 4,  6.653);
  histo_Zjets->SetBinContent( 5,  2.675);  histo_Zjets->SetBinError( 5,  3.081);
  histo_Zjets->SetBinContent( 6,  0.000);  histo_Zjets->SetBinError( 6,  0.000);
  histo_Zjets->SetBinContent( 7,  0.000);  histo_Zjets->SetBinError( 7,  0.000);
  histo_Zjets->SetBinContent( 8,  0.000);  histo_Zjets->SetBinError( 8,  0.000);
  histo_Zjets->SetBinContent( 9,  0.000);  histo_Zjets->SetBinError( 9,  0.000);
  histo_Zjets->SetBinContent(10,  0.000);  histo_Zjets->SetBinError(10,  0.000);
  histo_Zjets->SetBinContent(11,  0.000);  histo_Zjets->SetBinError(11,  0.000);

  histo_WZ->SetBinContent( 1,103.296);  histo_WZ->SetBinError( 1, 9.527);
  histo_WZ->SetBinContent( 2, 65.542);  histo_WZ->SetBinError( 2, 6.182);
  histo_WZ->SetBinContent( 3, 44.393);  histo_WZ->SetBinError( 3, 4.456);
  histo_WZ->SetBinContent( 4, 22.426);  histo_WZ->SetBinError( 4, 2.306);
  histo_WZ->SetBinContent( 5, 14.325);  histo_WZ->SetBinError( 5, 1.703);
  histo_WZ->SetBinContent( 6, 13.840);  histo_WZ->SetBinError( 6, 1.693);
  histo_WZ->SetBinContent( 7,  3.855);  histo_WZ->SetBinError( 7, 0.605);
  histo_WZ->SetBinContent( 8,  1.991);  histo_WZ->SetBinError( 8, 0.419);
  histo_WZ->SetBinContent( 9,  1.089);  histo_WZ->SetBinError( 9, 0.332);
  histo_WZ->SetBinContent(10,  0.464);  histo_WZ->SetBinError(10, 0.186);
  histo_WZ->SetBinContent(11,  0.189);  histo_WZ->SetBinError(11, 0.126);

  histo_ZZ->SetBinContent( 1,151.326);  histo_ZZ->SetBinError( 1,16.857);
  histo_ZZ->SetBinContent( 2,130.775);  histo_ZZ->SetBinError( 2,15.143);
  histo_ZZ->SetBinContent( 3, 97.079);  histo_ZZ->SetBinError( 3,11.716);
  histo_ZZ->SetBinContent( 4, 63.745);  histo_ZZ->SetBinError( 4, 8.066);
  histo_ZZ->SetBinContent( 5, 39.315);  histo_ZZ->SetBinError( 5, 5.336);
  histo_ZZ->SetBinContent( 6, 39.668);  histo_ZZ->SetBinError( 6, 5.682);
  histo_ZZ->SetBinContent( 7, 17.070);  histo_ZZ->SetBinError( 7, 2.668);
  histo_ZZ->SetBinContent( 8,  7.946);  histo_ZZ->SetBinError( 8, 1.336);
  histo_ZZ->SetBinContent( 9,  3.963);  histo_ZZ->SetBinError( 9, 0.718);
  histo_ZZ->SetBinContent(10,  3.264);  histo_ZZ->SetBinError(10, 0.659);
  histo_ZZ->SetBinContent(11,  1.577);  histo_ZZ->SetBinError(11, 0.365);

  histo_VVV->SetBinContent( 1,0.502);  histo_VVV->SetBinError( 1,0.083);
  histo_VVV->SetBinContent( 2,0.547);  histo_VVV->SetBinError( 2,0.100);
  histo_VVV->SetBinContent( 3,0.558);  histo_VVV->SetBinError( 3,0.097);
  histo_VVV->SetBinContent( 4,0.386);  histo_VVV->SetBinError( 4,0.094);
  histo_VVV->SetBinContent( 5,0.366);  histo_VVV->SetBinError( 5,0.080);
  histo_VVV->SetBinContent( 6,0.206);  histo_VVV->SetBinError( 6,0.057);
  histo_VVV->SetBinContent( 7,0.242);  histo_VVV->SetBinError( 7,0.059);
  histo_VVV->SetBinContent( 8,0.125);  histo_VVV->SetBinError( 8,0.055);
  histo_VVV->SetBinContent( 9,0.067);  histo_VVV->SetBinError( 9,0.034);
  histo_VVV->SetBinContent(10,0.044);  histo_VVV->SetBinError(10,0.033);
  histo_VVV->SetBinContent(11,0.042);  histo_VVV->SetBinError(11,0.015);
  
  histo_ZH_hinv->SetBinContent( 1,32.192);  histo_ZH_hinv->SetBinError( 1,2.882);
  histo_ZH_hinv->SetBinContent( 2,37.198);  histo_ZH_hinv->SetBinError( 2,3.281);
  histo_ZH_hinv->SetBinContent( 3,33.182);  histo_ZH_hinv->SetBinError( 3,2.906);
  histo_ZH_hinv->SetBinContent( 4,25.992);  histo_ZH_hinv->SetBinError( 4,2.032);
  histo_ZH_hinv->SetBinContent( 5,17.750);  histo_ZH_hinv->SetBinError( 5,1.431);
  histo_ZH_hinv->SetBinContent( 6,20.853);  histo_ZH_hinv->SetBinError( 6,1.449);
  histo_ZH_hinv->SetBinContent( 7,10.986);  histo_ZH_hinv->SetBinError( 7,0.845);
  histo_ZH_hinv->SetBinContent( 8, 5.446);  histo_ZH_hinv->SetBinError( 8,0.505);
  histo_ZH_hinv->SetBinContent( 9, 2.682);  histo_ZH_hinv->SetBinError( 9,0.311);
  histo_ZH_hinv->SetBinContent(10, 2.908);  histo_ZH_hinv->SetBinError(10,0.299);
  histo_ZH_hinv->SetBinContent(11, 1.551);  histo_ZH_hinv->SetBinError(11,0.214);

  histo_ggZH_hinv->SetBinContent( 1, 4.873);  histo_ggZH_hinv->SetBinError( 1,1.229);
  histo_ggZH_hinv->SetBinContent( 2, 8.319);  histo_ggZH_hinv->SetBinError( 2,2.096);
  histo_ggZH_hinv->SetBinContent( 3,10.308);  histo_ggZH_hinv->SetBinError( 3,2.722);
  histo_ggZH_hinv->SetBinContent( 4, 8.822);  histo_ggZH_hinv->SetBinError( 4,2.368);
  histo_ggZH_hinv->SetBinContent( 5, 5.926);  histo_ggZH_hinv->SetBinError( 5,1.636);
  histo_ggZH_hinv->SetBinContent( 6, 5.888);  histo_ggZH_hinv->SetBinError( 6,1.699);
  histo_ggZH_hinv->SetBinContent( 7, 2.126);  histo_ggZH_hinv->SetBinError( 7,0.657);
  histo_ggZH_hinv->SetBinContent( 8, 0.782);  histo_ggZH_hinv->SetBinError( 8,0.252);
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
