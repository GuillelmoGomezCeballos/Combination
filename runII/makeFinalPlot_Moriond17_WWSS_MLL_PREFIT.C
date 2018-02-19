// 16 bins sig, 4 bins wz
void makeFinalPlot_Moriond17_WWSS_MLL_PREFIT(){

  const int nBinMVA = 10; Float_t xbins[nBinMVA+1] = { 0,    1,    2,	 3,    4,    5,    
                                                             6,	   7,    8,    9,   10};
  const int nBinMLL = 5; Float_t xbinsMLL[nBinMLL+1] = {20, 100, 200, 300, 400, 600};

  TH1D* histoMVA    = new TH1D("histoMVA"   , "histoMVA"   , nBinMVA, xbins);
  TH1D* histoMVAMLL = new TH1D("histoMVAMLL", "histoMVAMLL", nBinMLL, xbinsMLL);

  TH1D *histo_Data   = (TH1D*) histoMVA->Clone("histo0");
  TH1D *histo_EWK    = (TH1D*) histoMVA->Clone("histo1");    
  TH1D *histo_QCD    = (TH1D*) histoMVA->Clone("histo2");	  
  TH1D *histo_WZ     = (TH1D*) histoMVA->Clone("histo3");	
  TH1D *histo_ZZ     = (TH1D*) histoMVA->Clone("histo4");
  TH1D *histo_VVV    = (TH1D*) histoMVA->Clone("histo5");   
  TH1D *histo_WS     = (TH1D*) histoMVA->Clone("histo6");
  TH1D *histo_WG     = (TH1D*) histoMVA->Clone("histo7");
  TH1D *histo_DPS    = (TH1D*) histoMVA->Clone("histo8");
  TH1D *histo_FakeM  = (TH1D*) histoMVA->Clone("histo9");
  TH1D *histo_FakeE  = (TH1D*) histoMVA->Clone("histo10");
  TH1D *histo_Higgs0 = (TH1D*) histoMVA->Clone("histo11");
  TH1D *histo_Higgs1 = (TH1D*) histoMVA->Clone("histo12");

  TH1D *histoSig_MLL_Data   = (TH1D*) histoMVAMLL->Clone("histo0");
  TH1D *histoSig_MLL_EWK    = (TH1D*) histoMVAMLL->Clone("histo1");    
  TH1D *histoSig_MLL_QCD    = (TH1D*) histoMVAMLL->Clone("histo2");	  
  TH1D *histoSig_MLL_WZ     = (TH1D*) histoMVAMLL->Clone("histo3");	
  TH1D *histoSig_MLL_ZZ     = (TH1D*) histoMVAMLL->Clone("histo4");
  TH1D *histoSig_MLL_VVV    = (TH1D*) histoMVAMLL->Clone("histo5");   
  TH1D *histoSig_MLL_WS     = (TH1D*) histoMVAMLL->Clone("histo6");
  TH1D *histoSig_MLL_WG     = (TH1D*) histoMVAMLL->Clone("histo7");
  TH1D *histoSig_MLL_DPS    = (TH1D*) histoMVAMLL->Clone("histo8");
  TH1D *histoSig_MLL_FakeM  = (TH1D*) histoMVAMLL->Clone("histo9");
  TH1D *histoSig_MLL_FakeE  = (TH1D*) histoMVAMLL->Clone("histo10");
  TH1D *histoSig_MLL_Higgs0 = (TH1D*) histoMVAMLL->Clone("histo11");
  TH1D *histoSig_MLL_Higgs1 = (TH1D*) histoMVAMLL->Clone("histo12");

  TH1D *histoWZ_MLL_Data   = (TH1D*) histoMVAMLL->Clone("histo0");
  TH1D *histoWZ_MLL_EWK    = (TH1D*) histoMVAMLL->Clone("histo1");    
  TH1D *histoWZ_MLL_QCD    = (TH1D*) histoMVAMLL->Clone("histo2");	  
  TH1D *histoWZ_MLL_WZ     = (TH1D*) histoMVAMLL->Clone("histo3");	
  TH1D *histoWZ_MLL_ZZ     = (TH1D*) histoMVAMLL->Clone("histo4");
  TH1D *histoWZ_MLL_VVV    = (TH1D*) histoMVAMLL->Clone("histo5");   
  TH1D *histoWZ_MLL_WS     = (TH1D*) histoMVAMLL->Clone("histo6");
  TH1D *histoWZ_MLL_WG     = (TH1D*) histoMVAMLL->Clone("histo7");
  TH1D *histoWZ_MLL_DPS    = (TH1D*) histoMVAMLL->Clone("histo8");
  TH1D *histoWZ_MLL_FakeM  = (TH1D*) histoMVAMLL->Clone("histo9");
  TH1D *histoWZ_MLL_FakeE  = (TH1D*) histoMVAMLL->Clone("histo10");
  TH1D *histoWZ_MLL_Higgs0 = (TH1D*) histoMVAMLL->Clone("histo11");
  TH1D *histoWZ_MLL_Higgs1 = (TH1D*) histoMVAMLL->Clone("histo12");

  histo_Data->SetBinContent( 1,85);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,74);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,22);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4,12);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5, 8);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,59);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7,34);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,14);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9, 4);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10, 2);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));

  histo_EWK->SetBinContent( 1,22.437);  histo_EWK->SetBinError( 1,2.508);
  histo_EWK->SetBinContent( 2,25.807);  histo_EWK->SetBinError( 2,3.011);
  histo_EWK->SetBinContent( 3,10.419);  histo_EWK->SetBinError( 3,1.326);
  histo_EWK->SetBinContent( 4, 4.391);  histo_EWK->SetBinError( 4,0.631);
  histo_EWK->SetBinContent( 5, 3.811);  histo_EWK->SetBinError( 5,0.565);
  histo_EWK->SetBinContent( 6, 0.000);  histo_EWK->SetBinError( 6,0.000);
  histo_EWK->SetBinContent( 7, 0.000);  histo_EWK->SetBinError( 7,0.000);
  histo_EWK->SetBinContent( 8, 0.000);  histo_EWK->SetBinError( 8,0.000);
  histo_EWK->SetBinContent( 9, 0.000);  histo_EWK->SetBinError( 9,0.000);
  histo_EWK->SetBinContent(10, 0.000);  histo_EWK->SetBinError(10,0.000);

  histo_QCD->SetBinContent( 1,0.898);  histo_QCD->SetBinError( 1,0.227);
  histo_QCD->SetBinContent( 2,1.820);  histo_QCD->SetBinError( 2,0.466);
  histo_QCD->SetBinContent( 3,0.971);  histo_QCD->SetBinError( 3,0.252);
  histo_QCD->SetBinContent( 4,0.566);  histo_QCD->SetBinError( 4,0.155);
  histo_QCD->SetBinContent( 5,0.556);  histo_QCD->SetBinError( 5,0.156);
  histo_QCD->SetBinContent( 6,0.000);  histo_QCD->SetBinError( 6,0.000);
  histo_QCD->SetBinContent( 7,0.000);  histo_QCD->SetBinError( 7,0.000);
  histo_QCD->SetBinContent( 8,0.000);  histo_QCD->SetBinError( 8,0.000);
  histo_QCD->SetBinContent( 9,0.000);  histo_QCD->SetBinError( 9,0.000);
  histo_QCD->SetBinContent(10,0.000);  histo_QCD->SetBinError(10,0.000);

  histo_WZ->SetBinContent( 1,10.776);  histo_WZ->SetBinError( 1,1.532);
  histo_WZ->SetBinContent( 2, 9.206);  histo_WZ->SetBinError( 2,1.340);
  histo_WZ->SetBinContent( 3, 2.868);  histo_WZ->SetBinError( 3,0.446);
  histo_WZ->SetBinContent( 4, 1.286);  histo_WZ->SetBinError( 4,0.212);
  histo_WZ->SetBinContent( 5, 0.987);  histo_WZ->SetBinError( 5,0.166);
  histo_WZ->SetBinContent( 6,40.958);  histo_WZ->SetBinError( 6,5.982);
  histo_WZ->SetBinContent( 7,21.512);  histo_WZ->SetBinError( 7,3.253);
  histo_WZ->SetBinContent( 8, 9.280);  histo_WZ->SetBinError( 8,1.432);
  histo_WZ->SetBinContent( 9, 4.118);  histo_WZ->SetBinError( 9,0.610);
  histo_WZ->SetBinContent(10, 3.000);  histo_WZ->SetBinError(10,0.630);
  
  histo_ZZ->SetBinContent( 1,0.068);  histo_ZZ->SetBinError( 1,0.018);
  histo_ZZ->SetBinContent( 2,0.055);  histo_ZZ->SetBinError( 2,0.014);
  histo_ZZ->SetBinContent( 3,0.019);  histo_ZZ->SetBinError( 3,0.004);
  histo_ZZ->SetBinContent( 4,0.010);  histo_ZZ->SetBinError( 4,0.003);
  histo_ZZ->SetBinContent( 5,0.007);  histo_ZZ->SetBinError( 5,0.002);
  histo_ZZ->SetBinContent( 6,0.854);  histo_ZZ->SetBinError( 6,0.205);
  histo_ZZ->SetBinContent( 7,0.539);  histo_ZZ->SetBinError( 7,0.129);
  histo_ZZ->SetBinContent( 8,0.297);  histo_ZZ->SetBinError( 8,0.068);
  histo_ZZ->SetBinContent( 9,0.137);  histo_ZZ->SetBinError( 9,0.031);
  histo_ZZ->SetBinContent(10,0.152);  histo_ZZ->SetBinError(10,0.034);

  histo_VVV->SetBinContent( 1,1.807);  histo_VVV->SetBinError( 1,0.441);
  histo_VVV->SetBinContent( 2,2.399);  histo_VVV->SetBinError( 2,0.453);
  histo_VVV->SetBinContent( 3,0.953);  histo_VVV->SetBinError( 3,0.284);
  histo_VVV->SetBinContent( 4,0.324);  histo_VVV->SetBinError( 4,0.102);
  histo_VVV->SetBinContent( 5,0.298);  histo_VVV->SetBinError( 5,0.091);
  histo_VVV->SetBinContent( 6,7.497);  histo_VVV->SetBinError( 6,0.980);
  histo_VVV->SetBinContent( 7,3.656);  histo_VVV->SetBinError( 7,0.538);
  histo_VVV->SetBinContent( 8,1.603);  histo_VVV->SetBinError( 8,0.255);
  histo_VVV->SetBinContent( 9,0.534);  histo_VVV->SetBinError( 9,0.110);
  histo_VVV->SetBinContent(10,0.532);  histo_VVV->SetBinError(10,0.120);

  histo_WS->SetBinContent( 1,1.796);  histo_WS->SetBinError( 1,0.714);
  histo_WS->SetBinContent( 2,2.279);  histo_WS->SetBinError( 2,0.700);
  histo_WS->SetBinContent( 3,0.731);  histo_WS->SetBinError( 3,0.355);
  histo_WS->SetBinContent( 4,0.303);  histo_WS->SetBinError( 4,0.146);
  histo_WS->SetBinContent( 5,0.101);  histo_WS->SetBinError( 5,0.063);
  histo_WS->SetBinContent( 6,0.100);  histo_WS->SetBinError( 6,0.065);
  histo_WS->SetBinContent( 7,0.322);  histo_WS->SetBinError( 7,0.257);
  histo_WS->SetBinContent( 8,0.054);  histo_WS->SetBinError( 8,0.060);
  histo_WS->SetBinContent( 9,0.002);  histo_WS->SetBinError( 9,0.002);
  histo_WS->SetBinContent(10,0.004);  histo_WS->SetBinError(10,0.002);

  histo_WG->SetBinContent( 1,3.549);  histo_WG->SetBinError( 1,1.349);
  histo_WG->SetBinContent( 2,3.949);  histo_WG->SetBinError( 2,1.321);
  histo_WG->SetBinContent( 3,0.374);  histo_WG->SetBinError( 3,0.269);
  histo_WG->SetBinContent( 4,0.208);  histo_WG->SetBinError( 4,0.270);
  histo_WG->SetBinContent( 5,0.191);  histo_WG->SetBinError( 5,0.176);
  histo_WG->SetBinContent( 6,0.428);  histo_WG->SetBinError( 6,0.307);
  histo_WG->SetBinContent( 7,0.000);  histo_WG->SetBinError( 7,0.000);
  histo_WG->SetBinContent( 8,0.000);  histo_WG->SetBinError( 8,0.000);
  histo_WG->SetBinContent( 9,0.000);  histo_WG->SetBinError( 9,0.000);
  histo_WG->SetBinContent(10,0.000);  histo_WG->SetBinError(10,0.000);

  histo_DPS->SetBinContent( 1,0.354);  histo_DPS->SetBinError( 1,0.059);
  histo_DPS->SetBinContent( 2,0.221);  histo_DPS->SetBinError( 2,0.037);
  histo_DPS->SetBinContent( 3,0.060);  histo_DPS->SetBinError( 3,0.021);
  histo_DPS->SetBinContent( 4,0.017);  histo_DPS->SetBinError( 4,0.009);
  histo_DPS->SetBinContent( 5,0.019);  histo_DPS->SetBinError( 5,0.012);
  histo_DPS->SetBinContent( 6,0.000);  histo_DPS->SetBinError( 6,0.000);
  histo_DPS->SetBinContent( 7,0.000);  histo_DPS->SetBinError( 7,0.000);
  histo_DPS->SetBinContent( 8,0.000);  histo_DPS->SetBinError( 8,0.000);
  histo_DPS->SetBinContent( 9,0.000);  histo_DPS->SetBinError( 9,0.000);
  histo_DPS->SetBinContent(10,0.000);  histo_DPS->SetBinError(10,0.000);

  histo_FakeM->SetBinContent( 1,49.538);  histo_FakeM->SetBinError( 1,15.063);
  histo_FakeM->SetBinContent( 2,25.948);  histo_FakeM->SetBinError( 2, 8.008);
  histo_FakeM->SetBinContent( 3,10.281);  histo_FakeM->SetBinError( 3, 3.617);
  histo_FakeM->SetBinContent( 4, 0.827);  histo_FakeM->SetBinError( 4, 0.777);
  histo_FakeM->SetBinContent( 5, 1.273);  histo_FakeM->SetBinError( 5, 0.948);
  histo_FakeM->SetBinContent( 6,10.310);  histo_FakeM->SetBinError( 6, 3.695);
  histo_FakeM->SetBinContent( 7, 2.255);  histo_FakeM->SetBinError( 7, 1.535);
  histo_FakeM->SetBinContent( 8, 1.569);  histo_FakeM->SetBinError( 8, 0.998);
  histo_FakeM->SetBinContent( 9, 0.807);  histo_FakeM->SetBinError( 9, 0.665);
  histo_FakeM->SetBinContent(10, 0.001);  histo_FakeM->SetBinError(10, 0.001);

  histo_FakeE->SetBinContent( 1,0.000);  histo_FakeE->SetBinError( 1,0.000);
  histo_FakeE->SetBinContent( 2,0.000);  histo_FakeE->SetBinError( 2,0.000);
  histo_FakeE->SetBinContent( 3,0.000);  histo_FakeE->SetBinError( 3,0.000);
  histo_FakeE->SetBinContent( 4,0.000);  histo_FakeE->SetBinError( 4,0.000);
  histo_FakeE->SetBinContent( 5,0.000);  histo_FakeE->SetBinError( 5,0.000);
  histo_FakeE->SetBinContent( 6,0.000);  histo_FakeE->SetBinError( 6,0.000);
  histo_FakeE->SetBinContent( 7,0.000);  histo_FakeE->SetBinError( 7,0.000);
  histo_FakeE->SetBinContent( 8,0.000);  histo_FakeE->SetBinError( 8,0.000);
  histo_FakeE->SetBinContent( 9,0.000);  histo_FakeE->SetBinError( 9,0.000);
  histo_FakeE->SetBinContent(10,0.000);  histo_FakeE->SetBinError(10,0.000);

  histo_Higgs0->SetBinContent( 1,0.000);  histo_Higgs0->SetBinError( 1,0.000);
  histo_Higgs0->SetBinContent( 2,0.000);  histo_Higgs0->SetBinError( 2,0.000);
  histo_Higgs0->SetBinContent( 3,0.000);  histo_Higgs0->SetBinError( 3,0.000);
  histo_Higgs0->SetBinContent( 4,0.000);  histo_Higgs0->SetBinError( 4,0.000);
  histo_Higgs0->SetBinContent( 5,0.000);  histo_Higgs0->SetBinError( 5,0.000);
  histo_Higgs0->SetBinContent( 6,0.000);  histo_Higgs0->SetBinError( 6,0.000);
  histo_Higgs0->SetBinContent( 7,0.000);  histo_Higgs0->SetBinError( 7,0.000);
  histo_Higgs0->SetBinContent( 8,0.000);  histo_Higgs0->SetBinError( 8,0.000);
  histo_Higgs0->SetBinContent( 9,0.000);  histo_Higgs0->SetBinError( 9,0.000);
  histo_Higgs0->SetBinContent(10,0.000);  histo_Higgs0->SetBinError(10,0.000);

  histo_Higgs1->SetBinContent( 1,0.000);  histo_Higgs1->SetBinError( 1,0.000);
  histo_Higgs1->SetBinContent( 2,0.000);  histo_Higgs1->SetBinError( 2,0.000);
  histo_Higgs1->SetBinContent( 3,0.000);  histo_Higgs1->SetBinError( 3,0.000);
  histo_Higgs1->SetBinContent( 4,0.000);  histo_Higgs1->SetBinError( 4,0.000);
  histo_Higgs1->SetBinContent( 5,0.000);  histo_Higgs1->SetBinError( 5,0.000);
  histo_Higgs1->SetBinContent( 6,0.000);  histo_Higgs1->SetBinError( 6,0.000);
  histo_Higgs1->SetBinContent( 7,0.000);  histo_Higgs1->SetBinError( 7,0.000);
  histo_Higgs1->SetBinContent( 8,0.000);  histo_Higgs1->SetBinError( 8,0.000);
  histo_Higgs1->SetBinContent( 9,0.000);  histo_Higgs1->SetBinError( 9,0.000);
  histo_Higgs1->SetBinContent(10,0.000);  histo_Higgs1->SetBinError(10,0.000);

  // ALL
  for(int np=1; np<=nBinMVA; np++) {
    double sumMC = histo_EWK   ->GetBinContent(np) + histo_QCD   ->GetBinContent(np) + histo_WZ    ->GetBinContent(np) +
                   histo_ZZ    ->GetBinContent(np) + histo_VVV   ->GetBinContent(np) + histo_WS    ->GetBinContent(np) +
                   histo_WG    ->GetBinContent(np) + histo_DPS   ->GetBinContent(np) + histo_FakeM ->GetBinContent(np) +
                   histo_FakeE ->GetBinContent(np);
    printf("data/bck(%2d): %3d / %5.1f\n",np,(int)histo_Data->GetBinContent(np),sumMC);
  }

  // Sig MLL
  for(int np=1; np<=5; np++) {
    histoSig_MLL_Data  ->SetBinContent(np,histo_Data  ->GetBinContent(np+0));histoSig_MLL_Data  ->SetBinError(np,sqrt(histo_Data  ->GetBinError(np+0)*histo_Data  ->GetBinError(np+0)));
    histoSig_MLL_EWK   ->SetBinContent(np,histo_EWK   ->GetBinContent(np+0));histoSig_MLL_EWK	->SetBinError(np,sqrt(histo_EWK   ->GetBinError(np+0)*histo_EWK   ->GetBinError(np+0)));
    histoSig_MLL_QCD   ->SetBinContent(np,histo_QCD   ->GetBinContent(np+0));histoSig_MLL_QCD	->SetBinError(np,sqrt(histo_QCD   ->GetBinError(np+0)*histo_QCD   ->GetBinError(np+0)));
    histoSig_MLL_WZ    ->SetBinContent(np,histo_WZ    ->GetBinContent(np+0));histoSig_MLL_WZ	->SetBinError(np,sqrt(histo_WZ    ->GetBinError(np+0)*histo_WZ    ->GetBinError(np+0)));
    histoSig_MLL_ZZ    ->SetBinContent(np,histo_ZZ    ->GetBinContent(np+0));histoSig_MLL_ZZ	->SetBinError(np,sqrt(histo_ZZ    ->GetBinError(np+0)*histo_ZZ    ->GetBinError(np+0)));
    histoSig_MLL_VVV   ->SetBinContent(np,histo_VVV   ->GetBinContent(np+0));histoSig_MLL_VVV	->SetBinError(np,sqrt(histo_VVV   ->GetBinError(np+0)*histo_VVV   ->GetBinError(np+0)));
    histoSig_MLL_WS    ->SetBinContent(np,histo_WS    ->GetBinContent(np+0));histoSig_MLL_WS	->SetBinError(np,sqrt(histo_WS    ->GetBinError(np+0)*histo_WS    ->GetBinError(np+0)));
    histoSig_MLL_WG    ->SetBinContent(np,histo_WG    ->GetBinContent(np+0));histoSig_MLL_WG	->SetBinError(np,sqrt(histo_WG    ->GetBinError(np+0)*histo_WG    ->GetBinError(np+0)));
    histoSig_MLL_DPS   ->SetBinContent(np,histo_DPS   ->GetBinContent(np+0));histoSig_MLL_DPS	->SetBinError(np,sqrt(histo_DPS   ->GetBinError(np+0)*histo_DPS   ->GetBinError(np+0)));
    histoSig_MLL_FakeM ->SetBinContent(np,histo_FakeM ->GetBinContent(np+0));histoSig_MLL_FakeM ->SetBinError(np,sqrt(histo_FakeM ->GetBinError(np+0)*histo_FakeM ->GetBinError(np+0)));
    histoSig_MLL_FakeE ->SetBinContent(np,histo_FakeE ->GetBinContent(np+0));histoSig_MLL_FakeE ->SetBinError(np,sqrt(histo_FakeE ->GetBinError(np+0)*histo_FakeE ->GetBinError(np+0)));
    histoSig_MLL_Higgs0->SetBinContent(np,histo_Higgs0->GetBinContent(np+0));histoSig_MLL_Higgs0->SetBinError(np,sqrt(histo_Higgs0->GetBinError(np+0)*histo_Higgs0->GetBinError(np+0)));
    histoSig_MLL_Higgs1->SetBinContent(np,histo_Higgs1->GetBinContent(np+0));histoSig_MLL_Higgs1->SetBinError(np,sqrt(histo_Higgs1->GetBinError(np+0)*histo_Higgs1->GetBinError(np+0)));
  }
  cout << histoSig_MLL_Data->GetSumOfWeights() << endl;

  // WZ MLL
  for(int np=1; np<=5; np++) {
    histoWZ_MLL_Data  ->SetBinContent(np,histo_Data  ->GetBinContent(np+5));histoWZ_MLL_Data    ->SetBinError(np,sqrt(histo_Data  ->GetBinError(np+5)*histo_Data  ->GetBinError(np+5)));
    histoWZ_MLL_EWK   ->SetBinContent(np,histo_EWK   ->GetBinContent(np+5));histoWZ_MLL_EWK	->SetBinError(np,sqrt(histo_EWK   ->GetBinError(np+5)*histo_EWK   ->GetBinError(np+5)));
    histoWZ_MLL_QCD   ->SetBinContent(np,histo_QCD   ->GetBinContent(np+5));histoWZ_MLL_QCD	->SetBinError(np,sqrt(histo_QCD   ->GetBinError(np+5)*histo_QCD   ->GetBinError(np+5)));
    histoWZ_MLL_WZ    ->SetBinContent(np,histo_WZ    ->GetBinContent(np+5));histoWZ_MLL_WZ	->SetBinError(np,sqrt(histo_WZ    ->GetBinError(np+5)*histo_WZ    ->GetBinError(np+5)));
    histoWZ_MLL_ZZ    ->SetBinContent(np,histo_ZZ    ->GetBinContent(np+5));histoWZ_MLL_ZZ	->SetBinError(np,sqrt(histo_ZZ    ->GetBinError(np+5)*histo_ZZ    ->GetBinError(np+5)));
    histoWZ_MLL_VVV   ->SetBinContent(np,histo_VVV   ->GetBinContent(np+5));histoWZ_MLL_VVV	->SetBinError(np,sqrt(histo_VVV   ->GetBinError(np+5)*histo_VVV   ->GetBinError(np+5)));
    histoWZ_MLL_WS    ->SetBinContent(np,histo_WS    ->GetBinContent(np+5));histoWZ_MLL_WS	->SetBinError(np,sqrt(histo_WS    ->GetBinError(np+5)*histo_WS    ->GetBinError(np+5)));
    histoWZ_MLL_WG    ->SetBinContent(np,histo_WG    ->GetBinContent(np+5));histoWZ_MLL_WG	->SetBinError(np,sqrt(histo_WG    ->GetBinError(np+5)*histo_WG    ->GetBinError(np+5)));
    histoWZ_MLL_DPS   ->SetBinContent(np,histo_DPS   ->GetBinContent(np+5));histoWZ_MLL_DPS	->SetBinError(np,sqrt(histo_DPS   ->GetBinError(np+5)*histo_DPS   ->GetBinError(np+5)));
    histoWZ_MLL_FakeM ->SetBinContent(np,histo_FakeM ->GetBinContent(np+5));histoWZ_MLL_FakeM ->SetBinError(np,sqrt(histo_FakeM   ->GetBinError(np+5)*histo_FakeM ->GetBinError(np+5)));
    histoWZ_MLL_FakeE ->SetBinContent(np,histo_FakeE ->GetBinContent(np+5));histoWZ_MLL_FakeE ->SetBinError(np,sqrt(histo_FakeE   ->GetBinError(np+5)*histo_FakeE ->GetBinError(np+5)));
    histoWZ_MLL_Higgs0->SetBinContent(np,histo_Higgs0->GetBinContent(np+5));histoWZ_MLL_Higgs0->SetBinError(np,sqrt(histo_Higgs0  ->GetBinError(np+5)*histo_Higgs0->GetBinError(np+5)));
    histoWZ_MLL_Higgs1->SetBinContent(np,histo_Higgs1->GetBinContent(np+5));histoWZ_MLL_Higgs1->SetBinError(np,sqrt(histo_Higgs1  ->GetBinError(np+5)*histo_Higgs1->GetBinError(np+5)));
  }
  cout << histoWZ_MLL_Data->GetSumOfWeights() << endl;

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_aqgc_full_unroll_prefit.root"),"recreate");
  outFilePlotsNote->cd();
  histo_Data  ->Write();
  histo_EWK   ->Write();
  histo_QCD   ->Write();
  histo_WZ    ->Write();
  histo_ZZ    ->Write();
  histo_VVV   ->Write();
  histo_WS    ->Write();
  histo_WG    ->Write();
  histo_DPS   ->Write();
  histo_FakeM ->Write();
  histo_FakeE ->Write();
  histo_Higgs0->Write();
  histo_Higgs1->Write();
  outFilePlotsNote->Close();
  }

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_aqgc_sig_mll_prefit.root"),"recreate");
  outFilePlotsNote->cd();
  histoSig_MLL_Data  ->Write();
  histoSig_MLL_EWK   ->Write();
  histoSig_MLL_QCD   ->Write();
  histoSig_MLL_WZ    ->Write();
  histoSig_MLL_ZZ    ->Write();
  histoSig_MLL_VVV   ->Write();
  histoSig_MLL_WS    ->Write();
  histoSig_MLL_WG    ->Write();
  histoSig_MLL_DPS   ->Write();
  histoSig_MLL_FakeM ->Write();
  histoSig_MLL_FakeE ->Write();
  histoSig_MLL_Higgs0->Write();
  histoSig_MLL_Higgs1->Write();
  outFilePlotsNote->Close();
  }

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_aqgc_wz_mll_prefit.root"),"recreate");
  outFilePlotsNote->cd();
  histoWZ_MLL_Data  ->Write();
  histoWZ_MLL_EWK   ->Write();
  histoWZ_MLL_QCD   ->Write();
  histoWZ_MLL_WZ    ->Write();
  histoWZ_MLL_ZZ    ->Write();
  histoWZ_MLL_VVV   ->Write();
  histoWZ_MLL_WS    ->Write();
  histoWZ_MLL_WG    ->Write();
  histoWZ_MLL_DPS   ->Write();
  histoWZ_MLL_FakeM ->Write();
  histoWZ_MLL_FakeE ->Write();
  histoWZ_MLL_Higgs0->Write();
  histoWZ_MLL_Higgs1->Write();
  outFilePlotsNote->Close();
  }
}
