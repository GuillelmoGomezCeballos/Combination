void makeFinalPlot_Moriond17_ZH(int nsel = 0){ // 0 (ZZ), 1(WZ), 2(ZH), 3(ZH-DM)

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

  histo_ZZ->SetBinContent( 1,12.770);  histo_ZZ->SetBinError( 1,1.230);
  histo_ZZ->SetBinContent( 2,12.394);  histo_ZZ->SetBinError( 2,1.247);
  histo_ZZ->SetBinContent( 3, 9.436);  histo_ZZ->SetBinError( 3,0.985);
  histo_ZZ->SetBinContent( 4, 6.747);  histo_ZZ->SetBinError( 4,0.747);
  histo_ZZ->SetBinContent( 5, 4.610);  histo_ZZ->SetBinError( 5,0.571);
  histo_ZZ->SetBinContent( 6, 5.159);  histo_ZZ->SetBinError( 6,0.662);
  histo_ZZ->SetBinContent( 7, 2.119);  histo_ZZ->SetBinError( 7,0.292);
  histo_ZZ->SetBinContent( 8, 1.182);  histo_ZZ->SetBinError( 8,0.189);
  histo_ZZ->SetBinContent( 9, 0.660);  histo_ZZ->SetBinError( 9,0.115);
  histo_ZZ->SetBinContent(10, 0.424);  histo_ZZ->SetBinError(10,0.082);
  histo_ZZ->SetBinContent(11, 0.290);  histo_ZZ->SetBinError(11,0.070);

  histo_VVV->SetBinContent( 1,0.044);  histo_VVV->SetBinError( 1,0.018);
  histo_VVV->SetBinContent( 2,0.113);  histo_VVV->SetBinError( 2,0.038);
  histo_VVV->SetBinContent( 3,0.057);  histo_VVV->SetBinError( 3,0.022);
  histo_VVV->SetBinContent( 4,0.045);  histo_VVV->SetBinError( 4,0.018);
  histo_VVV->SetBinContent( 5,0.071);  histo_VVV->SetBinError( 5,0.027);
  histo_VVV->SetBinContent( 6,0.057);  histo_VVV->SetBinError( 6,0.029);
  histo_VVV->SetBinContent( 7,0.082);  histo_VVV->SetBinError( 7,0.036);
  histo_VVV->SetBinContent( 8,0.005);  histo_VVV->SetBinError( 8,0.003);
  histo_VVV->SetBinContent( 9,0.003);  histo_VVV->SetBinError( 9,0.003);
  histo_VVV->SetBinContent(10,0.031);  histo_VVV->SetBinError(10,0.029);
  histo_VVV->SetBinContent(11,0.013);  histo_VVV->SetBinError(11,0.012);
  
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

  histo_Zjets->SetBinContent( 1, 2.193);  histo_Zjets->SetBinError( 1, 0.961);
  histo_Zjets->SetBinContent( 2, 3.779);  histo_Zjets->SetBinError( 2, 1.319);
  histo_Zjets->SetBinContent( 3, 5.214);  histo_Zjets->SetBinError( 3, 1.240);
  histo_Zjets->SetBinContent( 4, 2.820);  histo_Zjets->SetBinError( 4, 1.252);
  histo_Zjets->SetBinContent( 5, 0.705);  histo_Zjets->SetBinError( 5, 0.831);
  histo_Zjets->SetBinContent( 6, 1.101);  histo_Zjets->SetBinError( 6, 1.088);
  histo_Zjets->SetBinContent( 7, 0.421);  histo_Zjets->SetBinError( 7, 0.344);
  histo_Zjets->SetBinContent( 8, 0.400);  histo_Zjets->SetBinError( 8, 0.388);
  histo_Zjets->SetBinContent( 9, 0.000);  histo_Zjets->SetBinError( 9, 0.000);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);
  histo_Zjets->SetBinContent(11, 0.358);  histo_Zjets->SetBinError(11, 0.319);

  histo_WZ->SetBinContent( 1,81.876);  histo_WZ->SetBinError( 1,5.985);
  histo_WZ->SetBinContent( 2,83.701);  histo_WZ->SetBinError( 2,6.117);
  histo_WZ->SetBinContent( 3,69.666);  histo_WZ->SetBinError( 3,5.085);
  histo_WZ->SetBinContent( 4,46.974);  histo_WZ->SetBinError( 4,3.567);
  histo_WZ->SetBinContent( 5,29.122);  histo_WZ->SetBinError( 5,2.378);
  histo_WZ->SetBinContent( 6,34.032);  histo_WZ->SetBinError( 6,2.661);
  histo_WZ->SetBinContent( 7,15.821);  histo_WZ->SetBinError( 7,1.559);
  histo_WZ->SetBinContent( 8, 9.108);  histo_WZ->SetBinError( 8,0.965);
  histo_WZ->SetBinContent( 9, 4.170);  histo_WZ->SetBinError( 9,0.566);
  histo_WZ->SetBinContent(10, 3.245);  histo_WZ->SetBinError(10,0.493);
  histo_WZ->SetBinContent(11, 2.147);  histo_WZ->SetBinError(11,0.399);

  histo_ZZ->SetBinContent( 1,7.100);  histo_ZZ->SetBinError( 1,0.365);
  histo_ZZ->SetBinContent( 2,6.739);  histo_ZZ->SetBinError( 2,0.360);
  histo_ZZ->SetBinContent( 3,5.337);  histo_ZZ->SetBinError( 3,0.310);
  histo_ZZ->SetBinContent( 4,3.177);  histo_ZZ->SetBinError( 4,0.199);
  histo_ZZ->SetBinContent( 5,1.974);  histo_ZZ->SetBinError( 5,0.155);
  histo_ZZ->SetBinContent( 6,2.051);  histo_ZZ->SetBinError( 6,0.155);
  histo_ZZ->SetBinContent( 7,0.822);  histo_ZZ->SetBinError( 7,0.085);
  histo_ZZ->SetBinContent( 8,0.389);  histo_ZZ->SetBinError( 8,0.050);
  histo_ZZ->SetBinContent( 9,0.193);  histo_ZZ->SetBinError( 9,0.037);
  histo_ZZ->SetBinContent(10,0.130);  histo_ZZ->SetBinError(10,0.028);
  histo_ZZ->SetBinContent(11,0.044);  histo_ZZ->SetBinError(11,0.015);
  
  histo_VVV->SetBinContent( 1,0.515);  histo_VVV->SetBinError( 1,0.114);
  histo_VVV->SetBinContent( 2,0.707);  histo_VVV->SetBinError( 2,0.126);
  histo_VVV->SetBinContent( 3,0.992);  histo_VVV->SetBinError( 3,0.211);
  histo_VVV->SetBinContent( 4,0.506);  histo_VVV->SetBinError( 4,0.107);
  histo_VVV->SetBinContent( 5,0.541);  histo_VVV->SetBinError( 5,0.130);
  histo_VVV->SetBinContent( 6,0.687);  histo_VVV->SetBinError( 6,0.115);
  histo_VVV->SetBinContent( 7,0.398);  histo_VVV->SetBinError( 7,0.089);
  histo_VVV->SetBinContent( 8,0.260);  histo_VVV->SetBinError( 8,0.069);
  histo_VVV->SetBinContent( 9,0.190);  histo_VVV->SetBinError( 9,0.068);
  histo_VVV->SetBinContent(10,0.133);  histo_VVV->SetBinError(10,0.049);
  histo_VVV->SetBinContent(11,0.076);  histo_VVV->SetBinError(11,0.034);

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
  else if(nsel == 2 || nsel == 3){
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

  histo_EM->SetBinContent( 1, 228.978);  histo_EM->SetBinError( 1, 58.431);
  histo_EM->SetBinContent( 2,  53.458);  histo_EM->SetBinError( 2, 13.531);
  histo_EM->SetBinContent( 3,  15.978);  histo_EM->SetBinError( 3,  4.290);
  histo_EM->SetBinContent( 4,   3.637);  histo_EM->SetBinError( 4,  1.093);
  histo_EM->SetBinContent( 5,   1.192);  histo_EM->SetBinError( 5,  0.613);
  histo_EM->SetBinContent( 6,   0.831);  histo_EM->SetBinError( 6,  0.447);
  histo_EM->SetBinContent( 7,   0.000);  histo_EM->SetBinError( 7,  0.000);
  //histo_EM->SetBinContent( 8,   0.329);  histo_EM->SetBinError( 8,  0.234);
  histo_EM->SetBinContent( 8,   0.000);  histo_EM->SetBinError( 8,  0.000);
  histo_EM->SetBinContent( 9,   0.000);  histo_EM->SetBinError( 9,  0.000);
  histo_EM->SetBinContent(10,   0.000);  histo_EM->SetBinError(10,  0.000);
  histo_EM->SetBinContent(11,   0.000);  histo_EM->SetBinError(11,  0.000);
 
  histo_Zjets->SetBinContent( 1,963.300);  histo_Zjets->SetBinError( 1, 70.044);
  histo_Zjets->SetBinContent( 2, 58.758);  histo_Zjets->SetBinError( 2, 29.561);
  histo_Zjets->SetBinContent( 3,  4.371);  histo_Zjets->SetBinError( 3,  5.796);
  histo_Zjets->SetBinContent( 4,  5.583);  histo_Zjets->SetBinError( 4,  5.660);
  histo_Zjets->SetBinContent( 5,  2.622);  histo_Zjets->SetBinError( 5,  3.183);
  histo_Zjets->SetBinContent( 6,  0.000);  histo_Zjets->SetBinError( 6,  0.000);
  histo_Zjets->SetBinContent( 7,  0.000);  histo_Zjets->SetBinError( 7,  0.000);
  histo_Zjets->SetBinContent( 8,  0.000);  histo_Zjets->SetBinError( 8,  0.000);
  histo_Zjets->SetBinContent( 9,  0.000);  histo_Zjets->SetBinError( 9,  0.000);
  histo_Zjets->SetBinContent(10,  0.000);  histo_Zjets->SetBinError(10,  0.000);
  histo_Zjets->SetBinContent(11,  0.000);  histo_Zjets->SetBinError(11,  0.000);

  histo_WZ->SetBinContent( 1,104.233);  histo_WZ->SetBinError( 1, 8.433);
  histo_WZ->SetBinContent( 2, 66.146);  histo_WZ->SetBinError( 2, 5.404);
  histo_WZ->SetBinContent( 3, 44.787);  histo_WZ->SetBinError( 3, 3.825);
  histo_WZ->SetBinContent( 4, 22.624);  histo_WZ->SetBinError( 4, 2.119);
  histo_WZ->SetBinContent( 5, 14.454);  histo_WZ->SetBinError( 5, 1.556);
  histo_WZ->SetBinContent( 6, 13.961);  histo_WZ->SetBinError( 6, 1.528);
  histo_WZ->SetBinContent( 7,  3.888);  histo_WZ->SetBinError( 7, 0.591);
  histo_WZ->SetBinContent( 8,  2.007);  histo_WZ->SetBinError( 8, 0.440);
  histo_WZ->SetBinContent( 9,  1.096);  histo_WZ->SetBinError( 9, 0.352);
  histo_WZ->SetBinContent(10,  0.469);  histo_WZ->SetBinError(10, 0.190);
  histo_WZ->SetBinContent(11,  0.192);  histo_WZ->SetBinError(11, 0.133);

  histo_ZZ->SetBinContent( 1,152.928);  histo_ZZ->SetBinError( 1,15.240);
  histo_ZZ->SetBinContent( 2,132.159);  histo_ZZ->SetBinError( 2,13.858);
  histo_ZZ->SetBinContent( 3, 98.122);  histo_ZZ->SetBinError( 3,10.950);
  histo_ZZ->SetBinContent( 4, 64.437);  histo_ZZ->SetBinError( 4, 7.618);
  histo_ZZ->SetBinContent( 5, 39.756);  histo_ZZ->SetBinError( 5, 5.105);
  histo_ZZ->SetBinContent( 6, 40.112);  histo_ZZ->SetBinError( 6, 5.563);
  histo_ZZ->SetBinContent( 7, 17.267);  histo_ZZ->SetBinError( 7, 2.657);
  histo_ZZ->SetBinContent( 8,  8.042);  histo_ZZ->SetBinError( 8, 1.357);
  histo_ZZ->SetBinContent( 9,  4.013);  histo_ZZ->SetBinError( 9, 0.737);
  histo_ZZ->SetBinContent(10,  3.307);  histo_ZZ->SetBinError(10, 0.669);
  histo_ZZ->SetBinContent(11,  1.599);  histo_ZZ->SetBinError(11, 0.384);

  histo_VVV->SetBinContent( 1,0.499);  histo_VVV->SetBinError( 1,0.086);
  histo_VVV->SetBinContent( 2,0.542);  histo_VVV->SetBinError( 2,0.099);
  histo_VVV->SetBinContent( 3,0.558);  histo_VVV->SetBinError( 3,0.097);
  histo_VVV->SetBinContent( 4,0.383);  histo_VVV->SetBinError( 4,0.077);
  histo_VVV->SetBinContent( 5,0.367);  histo_VVV->SetBinError( 5,0.076);
  histo_VVV->SetBinContent( 6,0.206);  histo_VVV->SetBinError( 6,0.066);
  histo_VVV->SetBinContent( 7,0.240);  histo_VVV->SetBinError( 7,0.058);
  histo_VVV->SetBinContent( 8,0.125);  histo_VVV->SetBinError( 8,0.057);
  histo_VVV->SetBinContent( 9,0.067);  histo_VVV->SetBinError( 9,0.032);
  histo_VVV->SetBinContent(10,0.044);  histo_VVV->SetBinError(10,0.034);
  histo_VVV->SetBinContent(11,0.042);  histo_VVV->SetBinError(11,0.015);
  
  if(nsel == 2){
  histo_ZH_hinv->SetBinContent( 1,31.174);  histo_ZH_hinv->SetBinError( 1,2.812);
  histo_ZH_hinv->SetBinContent( 2,35.980);  histo_ZH_hinv->SetBinError( 2,3.057);
  histo_ZH_hinv->SetBinContent( 3,32.057);  histo_ZH_hinv->SetBinError( 3,2.702);
  histo_ZH_hinv->SetBinContent( 4,25.080);  histo_ZH_hinv->SetBinError( 4,1.987);
  histo_ZH_hinv->SetBinContent( 5,17.065);  histo_ZH_hinv->SetBinError( 5,1.230);
  histo_ZH_hinv->SetBinContent( 6,19.883);  histo_ZH_hinv->SetBinError( 6,1.404);
  histo_ZH_hinv->SetBinContent( 7,10.334);  histo_ZH_hinv->SetBinError( 7,0.807);
  histo_ZH_hinv->SetBinContent( 8, 5.040);  histo_ZH_hinv->SetBinError( 8,0.526);
  histo_ZH_hinv->SetBinContent( 9, 2.435);  histo_ZH_hinv->SetBinError( 9,0.271);
  histo_ZH_hinv->SetBinContent(10, 2.587);  histo_ZH_hinv->SetBinError(10,0.280);
  histo_ZH_hinv->SetBinContent(11, 1.359);  histo_ZH_hinv->SetBinError(11,0.179);

  histo_ggZH_hinv->SetBinContent( 1, 4.873);  histo_ggZH_hinv->SetBinError( 1,1.264);
  histo_ggZH_hinv->SetBinContent( 2, 8.319);  histo_ggZH_hinv->SetBinError( 2,2.174);
  histo_ggZH_hinv->SetBinContent( 3,10.308);  histo_ggZH_hinv->SetBinError( 3,2.776);
  histo_ggZH_hinv->SetBinContent( 4, 8.821);  histo_ggZH_hinv->SetBinError( 4,2.397);
  histo_ggZH_hinv->SetBinContent( 5, 5.926);  histo_ggZH_hinv->SetBinError( 5,1.653);
  histo_ggZH_hinv->SetBinContent( 6, 5.888);  histo_ggZH_hinv->SetBinError( 6,1.678);
  histo_ggZH_hinv->SetBinContent( 7, 2.126);  histo_ggZH_hinv->SetBinError( 7,0.648);
  histo_ggZH_hinv->SetBinContent( 8, 0.782);  histo_ggZH_hinv->SetBinError( 8,0.242);
  histo_ggZH_hinv->SetBinContent( 9, 0.298);  histo_ggZH_hinv->SetBinError( 9,0.099);
  histo_ggZH_hinv->SetBinContent(10, 0.164);  histo_ggZH_hinv->SetBinError(10,0.056);
  histo_ggZH_hinv->SetBinContent(11, 0.039);  histo_ggZH_hinv->SetBinError(11,0.014);
  }
  else if(nsel == 3){
  histo_ZH_hinv->SetBinContent( 1,48.456*0.30);  histo_ZH_hinv->SetBinError( 1,4.706*0.30);
  histo_ZH_hinv->SetBinContent( 2,12.964*0.30);  histo_ZH_hinv->SetBinError( 2,2.447*0.30);
  histo_ZH_hinv->SetBinContent( 3, 4.133*0.30);  histo_ZH_hinv->SetBinError( 3,1.905*0.30);
  histo_ZH_hinv->SetBinContent( 4,58.544*0.30);  histo_ZH_hinv->SetBinError( 4,5.901*0.30);
  histo_ZH_hinv->SetBinContent( 5,55.756*0.30);  histo_ZH_hinv->SetBinError( 5,5.302*0.30);
  histo_ZH_hinv->SetBinContent( 6,46.408*0.30);  histo_ZH_hinv->SetBinError( 6,5.508*0.30);
  histo_ZH_hinv->SetBinContent( 7,38.070*0.30);  histo_ZH_hinv->SetBinError( 7,4.528*0.30);
  histo_ZH_hinv->SetBinContent( 8,50.587*0.30);  histo_ZH_hinv->SetBinError( 8,5.355*0.30);
  histo_ZH_hinv->SetBinContent( 9,26.270*0.30);  histo_ZH_hinv->SetBinError( 9,3.451*0.30);
  histo_ZH_hinv->SetBinContent(10,21.088*0.30);  histo_ZH_hinv->SetBinError(10,3.174*0.30);
  histo_ZH_hinv->SetBinContent(11,13.519*0.30);  histo_ZH_hinv->SetBinError(11,2.384*0.30);
  }
 
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
