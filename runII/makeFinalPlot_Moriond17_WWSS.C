// 16 bins sig, 4 bins wz
void makeFinalPlot_Moriond17_WWSS(){

  const int nBinMVA = 20; Float_t xbins[nBinMVA+1] = { 0,    1,    2,	 3,    4,
                                                             5,    6,	 7,    8,
							     9,   10,	11,   12,
							    13,   14,	15,   16,
							    17,   18,	19,   20};
  const int nBinMJJ = 4; Float_t xbinsMJJ[nBinMJJ+1] = {500, 800, 1100, 1500, 2000};
  const int nBinMLL = 4; Float_t xbinsMLL[nBinMLL+1] = {20, 100, 180, 400, 600};

  TH1D* histoMVA    = new TH1D("histoMVA"   , "histoMVA"   , nBinMVA, xbins);
  TH1D* histoMVAMJJ = new TH1D("histoMVAMJJ", "histoMVAMJJ", nBinMJJ, xbinsMJJ);
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

  TH1D *histoWZ_MJJ_Data   = (TH1D*) histoMVAMJJ->Clone("histo0");
  TH1D *histoWZ_MJJ_EWK    = (TH1D*) histoMVAMJJ->Clone("histo1");    
  TH1D *histoWZ_MJJ_QCD    = (TH1D*) histoMVAMJJ->Clone("histo2");	  
  TH1D *histoWZ_MJJ_WZ     = (TH1D*) histoMVAMJJ->Clone("histo3");	
  TH1D *histoWZ_MJJ_ZZ     = (TH1D*) histoMVAMJJ->Clone("histo4");
  TH1D *histoWZ_MJJ_VVV    = (TH1D*) histoMVAMJJ->Clone("histo5");   
  TH1D *histoWZ_MJJ_WS     = (TH1D*) histoMVAMJJ->Clone("histo6");
  TH1D *histoWZ_MJJ_WG     = (TH1D*) histoMVAMJJ->Clone("histo7");
  TH1D *histoWZ_MJJ_DPS    = (TH1D*) histoMVAMJJ->Clone("histo8");
  TH1D *histoWZ_MJJ_FakeM  = (TH1D*) histoMVAMJJ->Clone("histo9");
  TH1D *histoWZ_MJJ_FakeE  = (TH1D*) histoMVAMJJ->Clone("histo10");
  TH1D *histoWZ_MJJ_Higgs0 = (TH1D*) histoMVAMJJ->Clone("histo11");
  TH1D *histoWZ_MJJ_Higgs1 = (TH1D*) histoMVAMJJ->Clone("histo12");

  TH1D *histoSig_MJJ_Data   = (TH1D*) histoMVAMJJ->Clone("histo0");
  TH1D *histoSig_MJJ_EWK    = (TH1D*) histoMVAMJJ->Clone("histo1");    
  TH1D *histoSig_MJJ_QCD    = (TH1D*) histoMVAMJJ->Clone("histo2");	  
  TH1D *histoSig_MJJ_WZ     = (TH1D*) histoMVAMJJ->Clone("histo3");	
  TH1D *histoSig_MJJ_ZZ     = (TH1D*) histoMVAMJJ->Clone("histo4");
  TH1D *histoSig_MJJ_VVV    = (TH1D*) histoMVAMJJ->Clone("histo5");   
  TH1D *histoSig_MJJ_WS     = (TH1D*) histoMVAMJJ->Clone("histo6");
  TH1D *histoSig_MJJ_WG     = (TH1D*) histoMVAMJJ->Clone("histo7");
  TH1D *histoSig_MJJ_DPS    = (TH1D*) histoMVAMJJ->Clone("histo8");
  TH1D *histoSig_MJJ_FakeM  = (TH1D*) histoMVAMJJ->Clone("histo9");
  TH1D *histoSig_MJJ_FakeE  = (TH1D*) histoMVAMJJ->Clone("histo10");
  TH1D *histoSig_MJJ_Higgs0 = (TH1D*) histoMVAMJJ->Clone("histo11");
  TH1D *histoSig_MJJ_Higgs1 = (TH1D*) histoMVAMJJ->Clone("histo12");

  TH1D *histoTop_MJJ_Data   = (TH1D*) histoMVAMJJ->Clone("histo0");
  TH1D *histoTop_MJJ_EWK    = (TH1D*) histoMVAMJJ->Clone("histo1");    
  TH1D *histoTop_MJJ_QCD    = (TH1D*) histoMVAMJJ->Clone("histo2");	  
  TH1D *histoTop_MJJ_WZ     = (TH1D*) histoMVAMJJ->Clone("histo3");	
  TH1D *histoTop_MJJ_ZZ     = (TH1D*) histoMVAMJJ->Clone("histo4");
  TH1D *histoTop_MJJ_VVV    = (TH1D*) histoMVAMJJ->Clone("histo5");   
  TH1D *histoTop_MJJ_WS     = (TH1D*) histoMVAMJJ->Clone("histo6");
  TH1D *histoTop_MJJ_WG     = (TH1D*) histoMVAMJJ->Clone("histo7");
  TH1D *histoTop_MJJ_DPS    = (TH1D*) histoMVAMJJ->Clone("histo8");
  TH1D *histoTop_MJJ_FakeM  = (TH1D*) histoMVAMJJ->Clone("histo9");
  TH1D *histoTop_MJJ_FakeE  = (TH1D*) histoMVAMJJ->Clone("histo10");
  TH1D *histoTop_MJJ_Higgs0 = (TH1D*) histoMVAMJJ->Clone("histo11");
  TH1D *histoTop_MJJ_Higgs1 = (TH1D*) histoMVAMJJ->Clone("histo12");

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

  histo_Data->SetBinContent( 1,47);  histo_Data->SetBinError( 1, sqrt(histo_Data->GetBinContent( 1)));
  histo_Data->SetBinContent( 2,19);  histo_Data->SetBinError( 2, sqrt(histo_Data->GetBinContent( 2)));
  histo_Data->SetBinContent( 3,10);  histo_Data->SetBinError( 3, sqrt(histo_Data->GetBinContent( 3)));
  histo_Data->SetBinContent( 4, 9);  histo_Data->SetBinError( 4, sqrt(histo_Data->GetBinContent( 4)));
  histo_Data->SetBinContent( 5,26);  histo_Data->SetBinError( 5, sqrt(histo_Data->GetBinContent( 5)));
  histo_Data->SetBinContent( 6,22);  histo_Data->SetBinError( 6, sqrt(histo_Data->GetBinContent( 6)));
  histo_Data->SetBinContent( 7, 7);  histo_Data->SetBinError( 7, sqrt(histo_Data->GetBinContent( 7)));
  histo_Data->SetBinContent( 8,11);  histo_Data->SetBinError( 8, sqrt(histo_Data->GetBinContent( 8)));
  histo_Data->SetBinContent( 9,10);  histo_Data->SetBinError( 9, sqrt(histo_Data->GetBinContent( 9)));
  histo_Data->SetBinContent(10, 7);  histo_Data->SetBinError(10, sqrt(histo_Data->GetBinContent(10)));
  histo_Data->SetBinContent(11, 5);  histo_Data->SetBinError(11, sqrt(histo_Data->GetBinContent(11)));
  histo_Data->SetBinContent(12, 8);  histo_Data->SetBinError(12, sqrt(histo_Data->GetBinContent(12)));
  histo_Data->SetBinContent(13, 7);  histo_Data->SetBinError(13, sqrt(histo_Data->GetBinContent(13)));
  histo_Data->SetBinContent(14, 4);  histo_Data->SetBinError(14, sqrt(histo_Data->GetBinContent(14)));
  histo_Data->SetBinContent(15, 4);  histo_Data->SetBinError(15, sqrt(histo_Data->GetBinContent(15)));
  histo_Data->SetBinContent(16, 5);  histo_Data->SetBinError(16, sqrt(histo_Data->GetBinContent(16)));
  histo_Data->SetBinContent(17,45);  histo_Data->SetBinError(17, sqrt(histo_Data->GetBinContent(17)));
  histo_Data->SetBinContent(18,32);  histo_Data->SetBinError(18, sqrt(histo_Data->GetBinContent(18)));
  histo_Data->SetBinContent(19,17);  histo_Data->SetBinError(19, sqrt(histo_Data->GetBinContent(19)));
  histo_Data->SetBinContent(20,19);  histo_Data->SetBinError(19, sqrt(histo_Data->GetBinContent(20)));

  histo_EWK->SetBinContent( 1,4.968);  histo_EWK->SetBinError( 1,1.253);
  histo_EWK->SetBinContent( 2,4.314);  histo_EWK->SetBinError( 2,1.062);
  histo_EWK->SetBinContent( 3,4.396);  histo_EWK->SetBinError( 3,1.067);
  histo_EWK->SetBinContent( 4,7.213);  histo_EWK->SetBinError( 4,1.695);
  histo_EWK->SetBinContent( 5,4.766);  histo_EWK->SetBinError( 5,1.212);
  histo_EWK->SetBinContent( 6,3.929);  histo_EWK->SetBinError( 6,0.958);
  histo_EWK->SetBinContent( 7,4.289);  histo_EWK->SetBinError( 7,1.038);
  histo_EWK->SetBinContent( 8,8.097);  histo_EWK->SetBinError( 8,1.882);
  histo_EWK->SetBinContent( 9,2.156);  histo_EWK->SetBinError( 9,0.521);
  histo_EWK->SetBinContent(10,2.413);  histo_EWK->SetBinError(10,0.627);
  histo_EWK->SetBinContent(11,2.547);  histo_EWK->SetBinError(11,0.626);
  histo_EWK->SetBinContent(12,5.712);  histo_EWK->SetBinError(12,1.369);
  histo_EWK->SetBinContent(13,1.128);  histo_EWK->SetBinError(13,0.282);
  histo_EWK->SetBinContent(14,1.218);  histo_EWK->SetBinError(14,0.315);
  histo_EWK->SetBinContent(15,1.754);  histo_EWK->SetBinError(15,0.420);
  histo_EWK->SetBinContent(16,3.660);  histo_EWK->SetBinError(16,0.853);
  histo_EWK->SetBinContent(17,0.000);  histo_EWK->SetBinError(17,0.000);
  histo_EWK->SetBinContent(18,0.000);  histo_EWK->SetBinError(18,0.000);
  histo_EWK->SetBinContent(19,0.000);  histo_EWK->SetBinError(19,0.000);
  histo_EWK->SetBinContent(20,0.000);  histo_EWK->SetBinError(20,0.000);

  histo_QCD->SetBinContent( 1,0.551);  histo_QCD->SetBinError( 1,0.154);
  histo_QCD->SetBinContent( 2,0.220);  histo_QCD->SetBinError( 2,0.068);
  histo_QCD->SetBinContent( 3,0.114);  histo_QCD->SetBinError( 3,0.040);
  histo_QCD->SetBinContent( 4,0.050);  histo_QCD->SetBinError( 4,0.023);
  histo_QCD->SetBinContent( 5,0.851);  histo_QCD->SetBinError( 5,0.210);
  histo_QCD->SetBinContent( 6,0.386);  histo_QCD->SetBinError( 6,0.120);
  histo_QCD->SetBinContent( 7,0.217);  histo_QCD->SetBinError( 7,0.069);
  histo_QCD->SetBinContent( 8,0.144);  histo_QCD->SetBinError( 8,0.051);
  histo_QCD->SetBinContent( 9,0.627);  histo_QCD->SetBinError( 9,0.165);
  histo_QCD->SetBinContent(10,0.353);  histo_QCD->SetBinError(10,0.094);
  histo_QCD->SetBinContent(11,0.166);  histo_QCD->SetBinError(11,0.056);
  histo_QCD->SetBinContent(12,0.164);  histo_QCD->SetBinError(12,0.066);
  histo_QCD->SetBinContent(13,0.384);  histo_QCD->SetBinError(13,0.103);
  histo_QCD->SetBinContent(14,0.324);  histo_QCD->SetBinError(14,0.097);
  histo_QCD->SetBinContent(15,0.196);  histo_QCD->SetBinError(15,0.067);
  histo_QCD->SetBinContent(16,0.273);  histo_QCD->SetBinError(16,0.084);
  histo_QCD->SetBinContent(17,0.000);  histo_QCD->SetBinError(17,0.000);
  histo_QCD->SetBinContent(18,0.000);  histo_QCD->SetBinError(18,0.000);
  histo_QCD->SetBinContent(19,0.000);  histo_QCD->SetBinError(19,0.000);
  histo_QCD->SetBinContent(20,0.000);  histo_QCD->SetBinError(20,0.000);

  histo_WZ->SetBinContent( 1, 4.610);  histo_WZ->SetBinError( 1,1.167);
  histo_WZ->SetBinContent( 2, 3.390);  histo_WZ->SetBinError( 2,0.864);
  histo_WZ->SetBinContent( 3, 1.812);  histo_WZ->SetBinError( 3,0.555);
  histo_WZ->SetBinContent( 4, 1.255);  histo_WZ->SetBinError( 4,0.405);
  histo_WZ->SetBinContent( 5, 3.397);  histo_WZ->SetBinError( 5,0.861);
  histo_WZ->SetBinContent( 6, 2.493);  histo_WZ->SetBinError( 6,0.625);
  histo_WZ->SetBinContent( 7, 1.197);  histo_WZ->SetBinError( 7,0.367);
  histo_WZ->SetBinContent( 8, 1.224);  histo_WZ->SetBinError( 8,0.381);
  histo_WZ->SetBinContent( 9, 1.501);  histo_WZ->SetBinError( 9,0.375);
  histo_WZ->SetBinContent(10, 1.242);  histo_WZ->SetBinError(10,0.317);
  histo_WZ->SetBinContent(11, 0.680);  histo_WZ->SetBinError(11,0.227);
  histo_WZ->SetBinContent(12, 0.779);  histo_WZ->SetBinError(12,0.238);
  histo_WZ->SetBinContent(13, 0.633);  histo_WZ->SetBinError(13,0.162);
  histo_WZ->SetBinContent(14, 0.697);  histo_WZ->SetBinError(14,0.193);
  histo_WZ->SetBinContent(15, 0.555);  histo_WZ->SetBinError(15,0.189);
  histo_WZ->SetBinContent(16, 0.590);  histo_WZ->SetBinError(16,0.192);
  histo_WZ->SetBinContent(17,30.464);  histo_WZ->SetBinError(17,7.251);
  histo_WZ->SetBinContent(18,26.045);  histo_WZ->SetBinError(18,6.215);
  histo_WZ->SetBinContent(19,12.787);  histo_WZ->SetBinError(19,3.836);
  histo_WZ->SetBinContent(20,14.579);  histo_WZ->SetBinError(20,4.480);
  
  histo_ZZ->SetBinContent( 1,0.042);  histo_ZZ->SetBinError( 1,0.011);
  histo_ZZ->SetBinContent( 2,0.015);  histo_ZZ->SetBinError( 2,0.005);
  histo_ZZ->SetBinContent( 3,0.008);  histo_ZZ->SetBinError( 3,0.002);
  histo_ZZ->SetBinContent( 4,0.005);  histo_ZZ->SetBinError( 4,0.002);
  histo_ZZ->SetBinContent( 5,0.027);  histo_ZZ->SetBinError( 5,0.007);
  histo_ZZ->SetBinContent( 6,0.014);  histo_ZZ->SetBinError( 6,0.004);
  histo_ZZ->SetBinContent( 7,0.006);  histo_ZZ->SetBinError( 7,0.002);
  histo_ZZ->SetBinContent( 8,0.005);  histo_ZZ->SetBinError( 8,0.001);
  histo_ZZ->SetBinContent( 9,0.012);  histo_ZZ->SetBinError( 9,0.003);
  histo_ZZ->SetBinContent(10,0.005);  histo_ZZ->SetBinError(10,0.002);
  histo_ZZ->SetBinContent(11,0.005);  histo_ZZ->SetBinError(11,0.001);
  histo_ZZ->SetBinContent(12,0.004);  histo_ZZ->SetBinError(12,0.001);
  histo_ZZ->SetBinContent(13,0.007);  histo_ZZ->SetBinError(13,0.002);
  histo_ZZ->SetBinContent(14,0.004);  histo_ZZ->SetBinError(14,0.001);
  histo_ZZ->SetBinContent(15,0.003);  histo_ZZ->SetBinError(15,0.001);
  histo_ZZ->SetBinContent(16,0.003);  histo_ZZ->SetBinError(16,0.001);
  histo_ZZ->SetBinContent(17,1.021);  histo_ZZ->SetBinError(17,0.250);
  histo_ZZ->SetBinContent(18,0.449);  histo_ZZ->SetBinError(18,0.105);
  histo_ZZ->SetBinContent(19,0.281);  histo_ZZ->SetBinError(19,0.062);
  histo_ZZ->SetBinContent(20,0.301);  histo_ZZ->SetBinError(20,0.063);

  histo_VVV->SetBinContent( 1,0.932);  histo_VVV->SetBinError( 1,0.352);
  histo_VVV->SetBinContent( 2,0.463);  histo_VVV->SetBinError( 2,0.265);
  histo_VVV->SetBinContent( 3,0.334);  histo_VVV->SetBinError( 3,0.134);
  histo_VVV->SetBinContent( 4,0.108);  histo_VVV->SetBinError( 4,0.101);
  histo_VVV->SetBinContent( 5,1.377);  histo_VVV->SetBinError( 5,0.293);
  histo_VVV->SetBinContent( 6,0.256);  histo_VVV->SetBinError( 6,0.195);
  histo_VVV->SetBinContent( 7,0.300);  histo_VVV->SetBinError( 7,0.103);
  histo_VVV->SetBinContent( 8,0.156);  histo_VVV->SetBinError( 8,0.046);
  histo_VVV->SetBinContent( 9,0.697);  histo_VVV->SetBinError( 9,0.166);
  histo_VVV->SetBinContent(10,0.342);  histo_VVV->SetBinError(10,0.123);
  histo_VVV->SetBinContent(11,0.196);  histo_VVV->SetBinError(11,0.156);
  histo_VVV->SetBinContent(12,0.090);  histo_VVV->SetBinError(12,0.057);
  histo_VVV->SetBinContent(13,0.171);  histo_VVV->SetBinError(13,0.064);
  histo_VVV->SetBinContent(14,0.198);  histo_VVV->SetBinError(14,0.063);
  histo_VVV->SetBinContent(15,0.158);  histo_VVV->SetBinError(15,0.046);
  histo_VVV->SetBinContent(16,0.111);  histo_VVV->SetBinError(16,0.066);
  histo_VVV->SetBinContent(17,7.128);  histo_VVV->SetBinError(17,0.842);
  histo_VVV->SetBinContent(18,3.487);  histo_VVV->SetBinError(18,0.534);
  histo_VVV->SetBinContent(19,1.891);  histo_VVV->SetBinError(19,0.267);
  histo_VVV->SetBinContent(20,1.463);  histo_VVV->SetBinError(20,0.258);

  histo_WS->SetBinContent( 1,0.725);  histo_WS->SetBinError( 1,0.294);
  histo_WS->SetBinContent( 2,0.100);  histo_WS->SetBinError( 2,0.097);
  histo_WS->SetBinContent( 3,0.352);  histo_WS->SetBinError( 3,0.205);
  histo_WS->SetBinContent( 4,0.598);  histo_WS->SetBinError( 4,0.477);
  histo_WS->SetBinContent( 5,0.954);  histo_WS->SetBinError( 5,0.353);
  histo_WS->SetBinContent( 6,0.877);  histo_WS->SetBinError( 6,0.389);
  histo_WS->SetBinContent( 7,0.115);  histo_WS->SetBinError( 7,0.076);
  histo_WS->SetBinContent( 8,0.107);  histo_WS->SetBinError( 8,0.090);
  histo_WS->SetBinContent( 9,0.742);  histo_WS->SetBinError( 9,0.258);
  histo_WS->SetBinContent(10,0.093);  histo_WS->SetBinError(10,0.103);
  histo_WS->SetBinContent(11,0.109);  histo_WS->SetBinError(11,0.135);
  histo_WS->SetBinContent(12,0.063);  histo_WS->SetBinError(12,0.055);
  histo_WS->SetBinContent(13,0.237);  histo_WS->SetBinError(13,0.113);
  histo_WS->SetBinContent(14,0.119);  histo_WS->SetBinError(14,0.089);
  histo_WS->SetBinContent(15,0.000);  histo_WS->SetBinError(15,0.000);
  histo_WS->SetBinContent(16,0.058);  histo_WS->SetBinError(16,0.044);
  histo_WS->SetBinContent(17,0.280);  histo_WS->SetBinError(17,0.221);
  histo_WS->SetBinContent(18,0.144);  histo_WS->SetBinError(18,0.092);
  histo_WS->SetBinContent(19,0.051);  histo_WS->SetBinError(19,0.028);
  histo_WS->SetBinContent(20,0.008);  histo_WS->SetBinError(20,0.003);

  histo_WG->SetBinContent( 1,1.308);  histo_WG->SetBinError( 1,0.593);
  histo_WG->SetBinContent( 2,0.908);  histo_WG->SetBinError( 2,0.484);
  histo_WG->SetBinContent( 3,1.200);  histo_WG->SetBinError( 3,0.493);
  histo_WG->SetBinContent( 4,0.201);  histo_WG->SetBinError( 4,0.207);
  histo_WG->SetBinContent( 5,0.787);  histo_WG->SetBinError( 5,0.376);
  histo_WG->SetBinContent( 6,1.017);  histo_WG->SetBinError( 6,0.567);
  histo_WG->SetBinContent( 7,1.438);  histo_WG->SetBinError( 7,0.543);
  histo_WG->SetBinContent( 8,0.453);  histo_WG->SetBinError( 8,0.375);
  histo_WG->SetBinContent( 9,0.369);  histo_WG->SetBinError( 9,0.299);
  histo_WG->SetBinContent(10,0.193);  histo_WG->SetBinError(10,0.207);
  histo_WG->SetBinContent(11,0.202);  histo_WG->SetBinError(11,0.192);
  histo_WG->SetBinContent(12,0.000);  histo_WG->SetBinError(12,0.000);
  histo_WG->SetBinContent(13,0.227);  histo_WG->SetBinError(13,0.224);
  histo_WG->SetBinContent(14,0.000);  histo_WG->SetBinError(14,0.000);
  histo_WG->SetBinContent(15,0.207);  histo_WG->SetBinError(15,0.207);
  histo_WG->SetBinContent(16,0.000);  histo_WG->SetBinError(16,0.000);
  histo_WG->SetBinContent(17,0.217);  histo_WG->SetBinError(17,0.231);
  histo_WG->SetBinContent(18,0.000);  histo_WG->SetBinError(18,0.000);
  histo_WG->SetBinContent(19,0.224);  histo_WG->SetBinError(19,0.231);
  histo_WG->SetBinContent(20,0.000);  histo_WG->SetBinError(20,0.000);

  histo_DPS->SetBinContent( 1,0.244);  histo_DPS->SetBinError( 1,0.040);
  histo_DPS->SetBinContent( 2,0.056);  histo_DPS->SetBinError( 2,0.019);
  histo_DPS->SetBinContent( 3,0.030);  histo_DPS->SetBinError( 3,0.012);
  histo_DPS->SetBinContent( 4,0.027);  histo_DPS->SetBinError( 4,0.012);
  histo_DPS->SetBinContent( 5,0.110);  histo_DPS->SetBinError( 5,0.023);
  histo_DPS->SetBinContent( 6,0.051);  histo_DPS->SetBinError( 6,0.016);
  histo_DPS->SetBinContent( 7,0.020);  histo_DPS->SetBinError( 7,0.011);
  histo_DPS->SetBinContent( 8,0.012);  histo_DPS->SetBinError( 8,0.008);
  histo_DPS->SetBinContent( 9,0.051);  histo_DPS->SetBinError( 9,0.016);
  histo_DPS->SetBinContent(10,0.017);  histo_DPS->SetBinError(10,0.009);
  histo_DPS->SetBinContent(11,0.025);  histo_DPS->SetBinError(11,0.010);
  histo_DPS->SetBinContent(12,0.000);  histo_DPS->SetBinError(12,0.000);
  histo_DPS->SetBinContent(13,0.013);  histo_DPS->SetBinError(13,0.009);
  histo_DPS->SetBinContent(14,0.012);  histo_DPS->SetBinError(14,0.007);
  histo_DPS->SetBinContent(15,0.011);  histo_DPS->SetBinError(15,0.007);
  histo_DPS->SetBinContent(16,0.000);  histo_DPS->SetBinError(16,0.000);
  histo_DPS->SetBinContent(17,0.000);  histo_DPS->SetBinError(17,0.000);
  histo_DPS->SetBinContent(18,0.000);  histo_DPS->SetBinError(18,0.000);
  histo_DPS->SetBinContent(19,0.000);  histo_DPS->SetBinError(19,0.000);
  histo_DPS->SetBinContent(20,0.000);  histo_DPS->SetBinError(20,0.000);

  histo_FakeM->SetBinContent( 1,30.856);  histo_FakeM->SetBinError( 1,4.811);
  histo_FakeM->SetBinContent( 2,12.668);  histo_FakeM->SetBinError( 2,2.721);
  histo_FakeM->SetBinContent( 3, 5.398);  histo_FakeM->SetBinError( 3,1.603);
  histo_FakeM->SetBinContent( 4, 3.344);  histo_FakeM->SetBinError( 4,1.267);
  histo_FakeM->SetBinContent( 5,13.149);  histo_FakeM->SetBinError( 5,2.970);
  histo_FakeM->SetBinContent( 6, 9.628);  histo_FakeM->SetBinError( 6,2.214);
  histo_FakeM->SetBinContent( 7, 1.608);  histo_FakeM->SetBinError( 7,1.096);
  histo_FakeM->SetBinContent( 8, 0.892);  histo_FakeM->SetBinError( 8,1.401);
  histo_FakeM->SetBinContent( 9, 8.819);  histo_FakeM->SetBinError( 9,1.899);
  histo_FakeM->SetBinContent(10, 3.212);  histo_FakeM->SetBinError(10,1.161);
  histo_FakeM->SetBinContent(11, 1.761);  histo_FakeM->SetBinError(11,0.744);
  histo_FakeM->SetBinContent(12, 0.108);  histo_FakeM->SetBinError(12,0.089);
  histo_FakeM->SetBinContent(13, 2.078);  histo_FakeM->SetBinError(13,0.902);
  histo_FakeM->SetBinContent(14, 0.549);  histo_FakeM->SetBinError(14,0.572);
  histo_FakeM->SetBinContent(15, 0.072);  histo_FakeM->SetBinError(15,0.068);
  histo_FakeM->SetBinContent(16, 0.108);  histo_FakeM->SetBinError(16,0.083);
  histo_FakeM->SetBinContent(17, 6.874);  histo_FakeM->SetBinError(17,3.475);
  histo_FakeM->SetBinContent(18, 2.663);  histo_FakeM->SetBinError(18,1.806);
  histo_FakeM->SetBinContent(19, 1.493);  histo_FakeM->SetBinError(19,1.372);
  histo_FakeM->SetBinContent(20, 3.381);  histo_FakeM->SetBinError(20,1.992);

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
  histo_FakeE->SetBinContent(11,0.000);  histo_FakeE->SetBinError(11,0.000);
  histo_FakeE->SetBinContent(12,0.000);  histo_FakeE->SetBinError(12,0.000);
  histo_FakeE->SetBinContent(13,0.000);  histo_FakeE->SetBinError(13,0.000);
  histo_FakeE->SetBinContent(14,0.000);  histo_FakeE->SetBinError(14,0.000);
  histo_FakeE->SetBinContent(15,0.000);  histo_FakeE->SetBinError(15,0.000);
  histo_FakeE->SetBinContent(16,0.000);  histo_FakeE->SetBinError(16,0.000);
  histo_FakeE->SetBinContent(17,0.000);  histo_FakeE->SetBinError(17,0.000);
  histo_FakeE->SetBinContent(18,0.000);  histo_FakeE->SetBinError(18,0.000);
  histo_FakeE->SetBinContent(19,0.000);  histo_FakeE->SetBinError(19,0.000);
  histo_FakeE->SetBinContent(20,0.000);  histo_FakeE->SetBinError(20,0.000);

  histo_Higgs0->SetBinContent( 1,4.105);  histo_Higgs0->SetBinError( 1,0.287);
  histo_Higgs0->SetBinContent( 2,3.183);  histo_Higgs0->SetBinError( 2,0.269);
  histo_Higgs0->SetBinContent( 3,2.720);  histo_Higgs0->SetBinError( 3,0.282);
  histo_Higgs0->SetBinContent( 4,4.202);  histo_Higgs0->SetBinError( 4,0.664);
  histo_Higgs0->SetBinContent( 5,1.752);  histo_Higgs0->SetBinError( 5,0.148);
  histo_Higgs0->SetBinContent( 6,1.166);  histo_Higgs0->SetBinError( 6,0.100);
  histo_Higgs0->SetBinContent( 7,0.943);  histo_Higgs0->SetBinError( 7,0.117);
  histo_Higgs0->SetBinContent( 8,1.738);  histo_Higgs0->SetBinError( 8,0.267);
  histo_Higgs0->SetBinContent( 9,0.000);  histo_Higgs0->SetBinError( 9,0.000);
  histo_Higgs0->SetBinContent(10,0.000);  histo_Higgs0->SetBinError(10,0.000);
  histo_Higgs0->SetBinContent(11,0.000);  histo_Higgs0->SetBinError(11,0.000);
  histo_Higgs0->SetBinContent(12,0.000);  histo_Higgs0->SetBinError(12,0.000);
  histo_Higgs0->SetBinContent(13,0.000);  histo_Higgs0->SetBinError(13,0.000);
  histo_Higgs0->SetBinContent(14,0.000);  histo_Higgs0->SetBinError(14,0.000);
  histo_Higgs0->SetBinContent(15,0.000);  histo_Higgs0->SetBinError(15,0.000);
  histo_Higgs0->SetBinContent(16,0.000);  histo_Higgs0->SetBinError(16,0.000);
  histo_Higgs0->SetBinContent(17,0.000);  histo_Higgs0->SetBinError(17,0.000);
  histo_Higgs0->SetBinContent(18,0.000);  histo_Higgs0->SetBinError(18,0.000);
  histo_Higgs0->SetBinContent(19,0.000);  histo_Higgs0->SetBinError(19,0.000);
  histo_Higgs0->SetBinContent(20,0.000);  histo_Higgs0->SetBinError(20,0.000);

  histo_Higgs1->SetBinContent( 1,0.287);  histo_Higgs1->SetBinError( 1,0.040);
  histo_Higgs1->SetBinContent( 2,0.357);  histo_Higgs1->SetBinError( 2,0.046);
  histo_Higgs1->SetBinContent( 3,0.344);  histo_Higgs1->SetBinError( 3,0.052);
  histo_Higgs1->SetBinContent( 4,0.738);  histo_Higgs1->SetBinError( 4,0.120);
  histo_Higgs1->SetBinContent( 5,1.758);  histo_Higgs1->SetBinError( 5,0.168);
  histo_Higgs1->SetBinContent( 6,1.807);  histo_Higgs1->SetBinError( 6,0.175);
  histo_Higgs1->SetBinContent( 7,2.027);  histo_Higgs1->SetBinError( 7,0.224);
  histo_Higgs1->SetBinContent( 8,4.143);  histo_Higgs1->SetBinError( 8,0.642);
  histo_Higgs1->SetBinContent( 9,3.134);  histo_Higgs1->SetBinError( 9,0.284);
  histo_Higgs1->SetBinContent(10,3.181);  histo_Higgs1->SetBinError(10,0.309);
  histo_Higgs1->SetBinContent(11,3.671);  histo_Higgs1->SetBinError(11,0.401);
  histo_Higgs1->SetBinContent(12,7.165);  histo_Higgs1->SetBinError(12,1.121);
  histo_Higgs1->SetBinContent(13,3.540);  histo_Higgs1->SetBinError(13,0.320);
  histo_Higgs1->SetBinContent(14,3.562);  histo_Higgs1->SetBinError(14,0.326);
  histo_Higgs1->SetBinContent(15,3.913);  histo_Higgs1->SetBinError(15,0.410);
  histo_Higgs1->SetBinContent(16,8.158);  histo_Higgs1->SetBinError(16,1.253);
  histo_Higgs1->SetBinContent(17,0.000);  histo_Higgs1->SetBinError(17,0.000);
  histo_Higgs1->SetBinContent(18,0.000);  histo_Higgs1->SetBinError(18,0.000);
  histo_Higgs1->SetBinContent(19,0.000);  histo_Higgs1->SetBinError(19,0.000);
  histo_Higgs1->SetBinContent(20,0.000);  histo_Higgs1->SetBinError(20,0.000);

  //histo_Higgs1->SetBinContent( 1, 0.135);  histo_Higgs1->SetBinError( 1,0.025);
  //histo_Higgs1->SetBinContent( 2, 0.135);  histo_Higgs1->SetBinError( 2,0.025);
  //histo_Higgs1->SetBinContent( 3, 0.123);  histo_Higgs1->SetBinError( 3,0.025);
  //histo_Higgs1->SetBinContent( 4, 0.331);  histo_Higgs1->SetBinError( 4,0.067);
  //histo_Higgs1->SetBinContent( 5, 0.627);  histo_Higgs1->SetBinError( 5,0.083);
  //histo_Higgs1->SetBinContent( 6, 0.628);  histo_Higgs1->SetBinError( 6,0.093);
  //histo_Higgs1->SetBinContent( 7, 0.849);  histo_Higgs1->SetBinError( 7,0.113);
  //histo_Higgs1->SetBinContent( 8, 2.263);  histo_Higgs1->SetBinError( 8,0.423);
  //histo_Higgs1->SetBinContent( 9, 1.639);  histo_Higgs1->SetBinError( 9,0.211);
  //histo_Higgs1->SetBinContent(10, 2.091);  histo_Higgs1->SetBinError(10,0.267);
  //histo_Higgs1->SetBinContent(11, 2.449);  histo_Higgs1->SetBinError(11,0.327);
  //histo_Higgs1->SetBinContent(12, 6.034);  histo_Higgs1->SetBinError(12,1.111);
  //histo_Higgs1->SetBinContent(13, 5.957);  histo_Higgs1->SetBinError(13,0.696);
  //histo_Higgs1->SetBinContent(14, 6.962);  histo_Higgs1->SetBinError(14,0.849);
  //histo_Higgs1->SetBinContent(15, 8.848);  histo_Higgs1->SetBinError(15,1.137);
  //histo_Higgs1->SetBinContent(16,21.344);  histo_Higgs1->SetBinError(16,3.968);
  //histo_Higgs1->SetBinContent(17, 0.000);  histo_Higgs1->SetBinError(17,0.000);
  //histo_Higgs1->SetBinContent(18, 0.000);  histo_Higgs1->SetBinError(18,0.000);
  //histo_Higgs1->SetBinContent(19, 0.000);  histo_Higgs1->SetBinError(19,0.000);
  //histo_Higgs1->SetBinContent(20, 0.000);  histo_Higgs1->SetBinError(20,0.000);

  // ALL
  for(int np=1; np<=nBinMVA; np++) {
    double sumMC = histo_EWK   ->GetBinContent(np) + histo_QCD   ->GetBinContent(np) + histo_WZ    ->GetBinContent(np) +
                   histo_ZZ    ->GetBinContent(np) + histo_VVV   ->GetBinContent(np) + histo_WS    ->GetBinContent(np) +
                   histo_WG    ->GetBinContent(np) + histo_DPS   ->GetBinContent(np) + histo_FakeM ->GetBinContent(np) +
                   histo_FakeE ->GetBinContent(np);
    printf("data/bck(%2d): %3d / %5.1f\n",np,(int)histo_Data->GetBinContent(np),sumMC);
  }

  // WZ MJJ
  for(int np=nBinMVA-4+1; np<=nBinMVA; np++) {
    histoWZ_MJJ_Data  ->SetBinContent(np-(nBinMVA-4),histo_Data  ->GetBinContent(np));histoWZ_MJJ_Data  ->SetBinError(np-(nBinMVA-4),histo_Data  ->GetBinError(np));
    histoWZ_MJJ_EWK   ->SetBinContent(np-(nBinMVA-4),histo_EWK	 ->GetBinContent(np));histoWZ_MJJ_EWK   ->SetBinError(np-(nBinMVA-4),histo_EWK   ->GetBinError(np));
    histoWZ_MJJ_QCD   ->SetBinContent(np-(nBinMVA-4),histo_QCD	 ->GetBinContent(np));histoWZ_MJJ_QCD   ->SetBinError(np-(nBinMVA-4),histo_QCD   ->GetBinError(np));
    histoWZ_MJJ_WZ    ->SetBinContent(np-(nBinMVA-4),histo_WZ	 ->GetBinContent(np));histoWZ_MJJ_WZ    ->SetBinError(np-(nBinMVA-4),histo_WZ    ->GetBinError(np));
    histoWZ_MJJ_ZZ    ->SetBinContent(np-(nBinMVA-4),histo_ZZ	 ->GetBinContent(np));histoWZ_MJJ_ZZ    ->SetBinError(np-(nBinMVA-4),histo_ZZ    ->GetBinError(np));
    histoWZ_MJJ_VVV   ->SetBinContent(np-(nBinMVA-4),histo_VVV	 ->GetBinContent(np));histoWZ_MJJ_VVV   ->SetBinError(np-(nBinMVA-4),histo_VVV   ->GetBinError(np));
    histoWZ_MJJ_WS    ->SetBinContent(np-(nBinMVA-4),histo_WS	 ->GetBinContent(np));histoWZ_MJJ_WS    ->SetBinError(np-(nBinMVA-4),histo_WS    ->GetBinError(np));
    histoWZ_MJJ_WG    ->SetBinContent(np-(nBinMVA-4),histo_WG	 ->GetBinContent(np));histoWZ_MJJ_WG    ->SetBinError(np-(nBinMVA-4),histo_WG    ->GetBinError(np));
    histoWZ_MJJ_DPS   ->SetBinContent(np-(nBinMVA-4),histo_DPS	 ->GetBinContent(np));histoWZ_MJJ_DPS   ->SetBinError(np-(nBinMVA-4),histo_DPS   ->GetBinError(np));
    histoWZ_MJJ_FakeM ->SetBinContent(np-(nBinMVA-4),histo_FakeM ->GetBinContent(np));histoWZ_MJJ_FakeM ->SetBinError(np-(nBinMVA-4),histo_FakeM ->GetBinError(np));
    histoWZ_MJJ_FakeE ->SetBinContent(np-(nBinMVA-4),histo_FakeE ->GetBinContent(np));histoWZ_MJJ_FakeE ->SetBinError(np-(nBinMVA-4),histo_FakeE ->GetBinError(np));
    histoWZ_MJJ_Higgs0->SetBinContent(np-(nBinMVA-4),histo_Higgs0->GetBinContent(np));histoWZ_MJJ_Higgs0->SetBinError(np-(nBinMVA-4),histo_Higgs0->GetBinError(np));
    histoWZ_MJJ_Higgs1->SetBinContent(np-(nBinMVA-4),histo_Higgs1->GetBinContent(np));histoWZ_MJJ_Higgs1->SetBinError(np-(nBinMVA-4),histo_Higgs1->GetBinError(np));
  }
  cout << histoWZ_MJJ_Data->GetSumOfWeights() << endl;

  // Sig MJJ
  for(int np=1; np<=4; np++) {
    histoSig_MJJ_Data  ->SetBinContent(np,histo_Data  ->GetBinContent(np+0)+histo_Data  ->GetBinContent(np+4)+histo_Data  ->GetBinContent(np+8)+histo_Data  ->GetBinContent(np+12));histoSig_MJJ_Data  ->SetBinError(np,sqrt(histo_Data  ->GetBinError(np+0)*histo_Data  ->GetBinError(np+0)+histo_Data  ->GetBinError(np+4)*histo_Data  ->GetBinError(np+4)+histo_Data  ->GetBinError(np+8)*histo_Data  ->GetBinError(np+8)+histo_Data  ->GetBinError(np+12)*histo_Data  ->GetBinError(np+12)));
    histoSig_MJJ_EWK   ->SetBinContent(np,histo_EWK   ->GetBinContent(np+0)+histo_EWK	->GetBinContent(np+4)+histo_EWK   ->GetBinContent(np+8)+histo_EWK   ->GetBinContent(np+12));histoSig_MJJ_EWK   ->SetBinError(np,sqrt(histo_EWK   ->GetBinError(np+0)*histo_EWK   ->GetBinError(np+0)+histo_EWK   ->GetBinError(np+4)*histo_EWK   ->GetBinError(np+4)+histo_EWK   ->GetBinError(np+8)*histo_EWK   ->GetBinError(np+8)+histo_EWK   ->GetBinError(np+12)*histo_EWK   ->GetBinError(np+12)));
    histoSig_MJJ_QCD   ->SetBinContent(np,histo_QCD   ->GetBinContent(np+0)+histo_QCD	->GetBinContent(np+4)+histo_QCD   ->GetBinContent(np+8)+histo_QCD   ->GetBinContent(np+12));histoSig_MJJ_QCD   ->SetBinError(np,sqrt(histo_QCD   ->GetBinError(np+0)*histo_QCD   ->GetBinError(np+0)+histo_QCD   ->GetBinError(np+4)*histo_QCD   ->GetBinError(np+4)+histo_QCD   ->GetBinError(np+8)*histo_QCD   ->GetBinError(np+8)+histo_QCD   ->GetBinError(np+12)*histo_QCD   ->GetBinError(np+12)));
    histoSig_MJJ_WZ    ->SetBinContent(np,histo_WZ    ->GetBinContent(np+0)+histo_WZ	->GetBinContent(np+4)+histo_WZ    ->GetBinContent(np+8)+histo_WZ    ->GetBinContent(np+12));histoSig_MJJ_WZ    ->SetBinError(np,sqrt(histo_WZ	 ->GetBinError(np+0)*histo_WZ	 ->GetBinError(np+0)+histo_WZ	 ->GetBinError(np+4)*histo_WZ	 ->GetBinError(np+4)+histo_WZ	 ->GetBinError(np+8)*histo_WZ	 ->GetBinError(np+8)+histo_WZ	 ->GetBinError(np+12)*histo_WZ    ->GetBinError(np+12)));
    histoSig_MJJ_ZZ    ->SetBinContent(np,histo_ZZ    ->GetBinContent(np+0)+histo_ZZ	->GetBinContent(np+4)+histo_ZZ    ->GetBinContent(np+8)+histo_ZZ    ->GetBinContent(np+12));histoSig_MJJ_ZZ    ->SetBinError(np,sqrt(histo_ZZ	 ->GetBinError(np+0)*histo_ZZ	 ->GetBinError(np+0)+histo_ZZ	 ->GetBinError(np+4)*histo_ZZ	 ->GetBinError(np+4)+histo_ZZ	 ->GetBinError(np+8)*histo_ZZ	 ->GetBinError(np+8)+histo_ZZ	 ->GetBinError(np+12)*histo_ZZ    ->GetBinError(np+12)));
    histoSig_MJJ_VVV   ->SetBinContent(np,histo_VVV   ->GetBinContent(np+0)+histo_VVV	->GetBinContent(np+4)+histo_VVV   ->GetBinContent(np+8)+histo_VVV   ->GetBinContent(np+12));histoSig_MJJ_VVV   ->SetBinError(np,sqrt(histo_VVV   ->GetBinError(np+0)*histo_VVV   ->GetBinError(np+0)+histo_VVV   ->GetBinError(np+4)*histo_VVV   ->GetBinError(np+4)+histo_VVV   ->GetBinError(np+8)*histo_VVV   ->GetBinError(np+8)+histo_VVV   ->GetBinError(np+12)*histo_VVV   ->GetBinError(np+12)));
    histoSig_MJJ_WS    ->SetBinContent(np,histo_WS    ->GetBinContent(np+0)+histo_WS	->GetBinContent(np+4)+histo_WS    ->GetBinContent(np+8)+histo_WS    ->GetBinContent(np+12));histoSig_MJJ_WS    ->SetBinError(np,sqrt(histo_WS	 ->GetBinError(np+0)*histo_WS	 ->GetBinError(np+0)+histo_WS	 ->GetBinError(np+4)*histo_WS	 ->GetBinError(np+4)+histo_WS	 ->GetBinError(np+8)*histo_WS	 ->GetBinError(np+8)+histo_WS	 ->GetBinError(np+12)*histo_WS    ->GetBinError(np+12)));
    histoSig_MJJ_WG    ->SetBinContent(np,histo_WG    ->GetBinContent(np+0)+histo_WG	->GetBinContent(np+4)+histo_WG    ->GetBinContent(np+8)+histo_WG    ->GetBinContent(np+12));histoSig_MJJ_WG    ->SetBinError(np,sqrt(histo_WG	 ->GetBinError(np+0)*histo_WG	 ->GetBinError(np+0)+histo_WG	 ->GetBinError(np+4)*histo_WG	 ->GetBinError(np+4)+histo_WG	 ->GetBinError(np+8)*histo_WG	 ->GetBinError(np+8)+histo_WG	 ->GetBinError(np+12)*histo_WG    ->GetBinError(np+12)));
    histoSig_MJJ_DPS   ->SetBinContent(np,histo_DPS   ->GetBinContent(np+0)+histo_DPS	->GetBinContent(np+4)+histo_DPS   ->GetBinContent(np+8)+histo_DPS   ->GetBinContent(np+12));histoSig_MJJ_DPS   ->SetBinError(np,sqrt(histo_DPS   ->GetBinError(np+0)*histo_DPS   ->GetBinError(np+0)+histo_DPS   ->GetBinError(np+4)*histo_DPS   ->GetBinError(np+4)+histo_DPS   ->GetBinError(np+8)*histo_DPS   ->GetBinError(np+8)+histo_DPS   ->GetBinError(np+12)*histo_DPS   ->GetBinError(np+12)));
    histoSig_MJJ_FakeM ->SetBinContent(np,histo_FakeM ->GetBinContent(np+0)+histo_FakeM ->GetBinContent(np+4)+histo_FakeM ->GetBinContent(np+8)+histo_FakeM ->GetBinContent(np+12));histoSig_MJJ_FakeM ->SetBinError(np,sqrt(histo_FakeM ->GetBinError(np+0)*histo_FakeM ->GetBinError(np+0)+histo_FakeM ->GetBinError(np+4)*histo_FakeM ->GetBinError(np+4)+histo_FakeM ->GetBinError(np+8)*histo_FakeM ->GetBinError(np+8)+histo_FakeM ->GetBinError(np+12)*histo_FakeM ->GetBinError(np+12)));
    histoSig_MJJ_FakeE ->SetBinContent(np,histo_FakeE ->GetBinContent(np+0)+histo_FakeE ->GetBinContent(np+4)+histo_FakeE ->GetBinContent(np+8)+histo_FakeE ->GetBinContent(np+12));histoSig_MJJ_FakeE ->SetBinError(np,sqrt(histo_FakeE ->GetBinError(np+0)*histo_FakeE ->GetBinError(np+0)+histo_FakeE ->GetBinError(np+4)*histo_FakeE ->GetBinError(np+4)+histo_FakeE ->GetBinError(np+8)*histo_FakeE ->GetBinError(np+8)+histo_FakeE ->GetBinError(np+12)*histo_FakeE ->GetBinError(np+12)));
    histoSig_MJJ_Higgs0->SetBinContent(np,histo_Higgs0->GetBinContent(np+0)+histo_Higgs0->GetBinContent(np+4)+histo_Higgs0->GetBinContent(np+8)+histo_Higgs0->GetBinContent(np+12));histoSig_MJJ_Higgs0->SetBinError(np,sqrt(histo_Higgs0->GetBinError(np+0)*histo_Higgs0->GetBinError(np+0)+histo_Higgs0->GetBinError(np+4)*histo_Higgs0->GetBinError(np+4)+histo_Higgs0->GetBinError(np+8)*histo_Higgs0->GetBinError(np+8)+histo_Higgs0->GetBinError(np+12)*histo_Higgs0->GetBinError(np+12)));
    histoSig_MJJ_Higgs1->SetBinContent(np,histo_Higgs1->GetBinContent(np+0)+histo_Higgs1->GetBinContent(np+4)+histo_Higgs1->GetBinContent(np+8)+histo_Higgs1->GetBinContent(np+12));histoSig_MJJ_Higgs1->SetBinError(np,sqrt(histo_Higgs1->GetBinError(np+0)*histo_Higgs1->GetBinError(np+0)+histo_Higgs1->GetBinError(np+4)*histo_Higgs1->GetBinError(np+4)+histo_Higgs1->GetBinError(np+8)*histo_Higgs1->GetBinError(np+8)+histo_Higgs1->GetBinError(np+12)*histo_Higgs1->GetBinError(np+12)));
  }
  cout << histoSig_MJJ_Data->GetSumOfWeights() << endl;

  // Sig MLL
  for(int np=1; np<=4; np++) {
    int nCount = 4*np-3;
    histoSig_MLL_Data  ->SetBinContent(np,histo_Data  ->GetBinContent(nCount+0)+histo_Data  ->GetBinContent(nCount+1)+histo_Data  ->GetBinContent(nCount+2)+histo_Data  ->GetBinContent(nCount+3));histoSig_MLL_Data  ->SetBinError(np,sqrt(histo_Data  ->GetBinError(nCount+0)*histo_Data  ->GetBinError(nCount+0)+histo_Data  ->GetBinError(nCount+1)*histo_Data   ->GetBinError(nCount+1)+histo_Data ->GetBinError(nCount+2)*histo_Data  ->GetBinError(nCount+2)+histo_Data  ->GetBinError(nCount+3)*histo_Data  ->GetBinError(nCount+3)));
    histoSig_MLL_EWK   ->SetBinContent(np,histo_EWK   ->GetBinContent(nCount+0)+histo_EWK   ->GetBinContent(nCount+1)+histo_EWK   ->GetBinContent(nCount+2)+histo_EWK	->GetBinContent(nCount+3));histoSig_MLL_EWK   ->SetBinError(np,sqrt(histo_EWK   ->GetBinError(nCount+0)*histo_EWK   ->GetBinError(nCount+0)+histo_EWK	->GetBinError(nCount+1)*histo_EWK    ->GetBinError(nCount+1)+histo_EWK  ->GetBinError(nCount+2)*histo_EWK   ->GetBinError(nCount+2)+histo_EWK	->GetBinError(nCount+3)*histo_EWK   ->GetBinError(nCount+3)));
    histoSig_MLL_QCD   ->SetBinContent(np,histo_QCD   ->GetBinContent(nCount+0)+histo_QCD   ->GetBinContent(nCount+1)+histo_QCD   ->GetBinContent(nCount+2)+histo_QCD	->GetBinContent(nCount+3));histoSig_MLL_QCD   ->SetBinError(np,sqrt(histo_QCD   ->GetBinError(nCount+0)*histo_QCD   ->GetBinError(nCount+0)+histo_QCD	->GetBinError(nCount+1)*histo_QCD    ->GetBinError(nCount+1)+histo_QCD  ->GetBinError(nCount+2)*histo_QCD   ->GetBinError(nCount+2)+histo_QCD	->GetBinError(nCount+3)*histo_QCD   ->GetBinError(nCount+3)));
    histoSig_MLL_WZ    ->SetBinContent(np,histo_WZ    ->GetBinContent(nCount+0)+histo_WZ    ->GetBinContent(nCount+1)+histo_WZ    ->GetBinContent(nCount+2)+histo_WZ	->GetBinContent(nCount+3));histoSig_MLL_WZ    ->SetBinError(np,sqrt(histo_WZ    ->GetBinError(nCount+0)*histo_WZ    ->GetBinError(nCount+0)+histo_WZ	->GetBinError(nCount+1)*histo_WZ     ->GetBinError(nCount+1)+histo_WZ	->GetBinError(nCount+2)*histo_WZ    ->GetBinError(nCount+2)+histo_WZ	->GetBinError(nCount+3)*histo_WZ    ->GetBinError(nCount+3)));
    histoSig_MLL_ZZ    ->SetBinContent(np,histo_ZZ    ->GetBinContent(nCount+0)+histo_ZZ    ->GetBinContent(nCount+1)+histo_ZZ    ->GetBinContent(nCount+2)+histo_ZZ	->GetBinContent(nCount+3));histoSig_MLL_ZZ    ->SetBinError(np,sqrt(histo_ZZ    ->GetBinError(nCount+0)*histo_ZZ    ->GetBinError(nCount+0)+histo_ZZ	->GetBinError(nCount+1)*histo_ZZ     ->GetBinError(nCount+1)+histo_ZZ	->GetBinError(nCount+2)*histo_ZZ    ->GetBinError(nCount+2)+histo_ZZ	->GetBinError(nCount+3)*histo_ZZ    ->GetBinError(nCount+3)));
    histoSig_MLL_VVV   ->SetBinContent(np,histo_VVV   ->GetBinContent(nCount+0)+histo_VVV   ->GetBinContent(nCount+1)+histo_VVV   ->GetBinContent(nCount+2)+histo_VVV	->GetBinContent(nCount+3));histoSig_MLL_VVV   ->SetBinError(np,sqrt(histo_VVV   ->GetBinError(nCount+0)*histo_VVV   ->GetBinError(nCount+0)+histo_VVV	->GetBinError(nCount+1)*histo_VVV    ->GetBinError(nCount+1)+histo_VVV  ->GetBinError(nCount+2)*histo_VVV   ->GetBinError(nCount+2)+histo_VVV	->GetBinError(nCount+3)*histo_VVV   ->GetBinError(nCount+3)));
    histoSig_MLL_WS    ->SetBinContent(np,histo_WS    ->GetBinContent(nCount+0)+histo_WS    ->GetBinContent(nCount+1)+histo_WS    ->GetBinContent(nCount+2)+histo_WS	->GetBinContent(nCount+3));histoSig_MLL_WS    ->SetBinError(np,sqrt(histo_WS    ->GetBinError(nCount+0)*histo_WS    ->GetBinError(nCount+0)+histo_WS	->GetBinError(nCount+1)*histo_WS     ->GetBinError(nCount+1)+histo_WS	->GetBinError(nCount+2)*histo_WS    ->GetBinError(nCount+2)+histo_WS	->GetBinError(nCount+3)*histo_WS    ->GetBinError(nCount+3)));
    histoSig_MLL_WG    ->SetBinContent(np,histo_WG    ->GetBinContent(nCount+0)+histo_WG    ->GetBinContent(nCount+1)+histo_WG    ->GetBinContent(nCount+2)+histo_WG	->GetBinContent(nCount+3));histoSig_MLL_WG    ->SetBinError(np,sqrt(histo_WG    ->GetBinError(nCount+0)*histo_WG    ->GetBinError(nCount+0)+histo_WG	->GetBinError(nCount+1)*histo_WG     ->GetBinError(nCount+1)+histo_WG	->GetBinError(nCount+2)*histo_WG    ->GetBinError(nCount+2)+histo_WG	->GetBinError(nCount+3)*histo_WG    ->GetBinError(nCount+3)));
    histoSig_MLL_DPS   ->SetBinContent(np,histo_DPS   ->GetBinContent(nCount+0)+histo_DPS   ->GetBinContent(nCount+1)+histo_DPS   ->GetBinContent(nCount+2)+histo_DPS	->GetBinContent(nCount+3));histoSig_MLL_DPS   ->SetBinError(np,sqrt(histo_DPS   ->GetBinError(nCount+0)*histo_DPS   ->GetBinError(nCount+0)+histo_DPS	->GetBinError(nCount+1)*histo_DPS    ->GetBinError(nCount+1)+histo_DPS  ->GetBinError(nCount+2)*histo_DPS   ->GetBinError(nCount+2)+histo_DPS	->GetBinError(nCount+3)*histo_DPS   ->GetBinError(nCount+3)));
    histoSig_MLL_FakeM ->SetBinContent(np,histo_FakeM ->GetBinContent(nCount+0)+histo_FakeM ->GetBinContent(nCount+1)+histo_FakeM ->GetBinContent(nCount+2)+histo_FakeM ->GetBinContent(nCount+3));histoSig_MLL_FakeM ->SetBinError(np,sqrt(histo_FakeM ->GetBinError(nCount+0)*histo_FakeM ->GetBinError(nCount+0)+histo_FakeM ->GetBinError(nCount+1)*histo_FakeM ->GetBinError(nCount+1)+histo_FakeM ->GetBinError(nCount+2)*histo_FakeM ->GetBinError(nCount+2)+histo_FakeM ->GetBinError(nCount+3)*histo_FakeM ->GetBinError(nCount+3)));
    histoSig_MLL_FakeE ->SetBinContent(np,histo_FakeE ->GetBinContent(nCount+0)+histo_FakeE ->GetBinContent(nCount+1)+histo_FakeE ->GetBinContent(nCount+2)+histo_FakeE ->GetBinContent(nCount+3));histoSig_MLL_FakeE ->SetBinError(np,sqrt(histo_FakeE ->GetBinError(nCount+0)*histo_FakeE ->GetBinError(nCount+0)+histo_FakeE ->GetBinError(nCount+1)*histo_FakeE ->GetBinError(nCount+1)+histo_FakeE ->GetBinError(nCount+2)*histo_FakeE ->GetBinError(nCount+2)+histo_FakeE ->GetBinError(nCount+3)*histo_FakeE ->GetBinError(nCount+3)));
    histoSig_MLL_Higgs0->SetBinContent(np,histo_Higgs0->GetBinContent(nCount+0)+histo_Higgs0->GetBinContent(nCount+1)+histo_Higgs0->GetBinContent(nCount+2)+histo_Higgs0->GetBinContent(nCount+3));histoSig_MLL_Higgs0->SetBinError(np,sqrt(histo_Higgs0->GetBinError(nCount+0)*histo_Higgs0->GetBinError(nCount+0)+histo_Higgs0->GetBinError(nCount+1)*histo_Higgs0->GetBinError(nCount+1)+histo_Higgs0->GetBinError(nCount+2)*histo_Higgs0->GetBinError(nCount+2)+histo_Higgs0->GetBinError(nCount+3)*histo_Higgs0->GetBinError(nCount+3)));
    histoSig_MLL_Higgs1->SetBinContent(np,histo_Higgs1->GetBinContent(nCount+0)+histo_Higgs1->GetBinContent(nCount+1)+histo_Higgs1->GetBinContent(nCount+2)+histo_Higgs1->GetBinContent(nCount+3));histoSig_MLL_Higgs1->SetBinError(np,sqrt(histo_Higgs1->GetBinError(nCount+0)*histo_Higgs1->GetBinError(nCount+0)+histo_Higgs1->GetBinError(nCount+1)*histo_Higgs1->GetBinError(nCount+1)+histo_Higgs1->GetBinError(nCount+2)*histo_Higgs1->GetBinError(nCount+2)+histo_Higgs1->GetBinError(nCount+3)*histo_Higgs1->GetBinError(nCount+3)));
  }
  cout << histoSig_MLL_Data->GetSumOfWeights() << endl;

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_full_unroll.root"),"recreate");
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
  TFile* outFilePlotsNote = new TFile(Form("histo_wz_mjj.root"),"recreate");
  outFilePlotsNote->cd();
  histoWZ_MJJ_Data  ->Write();
  histoWZ_MJJ_EWK   ->Write();
  histoWZ_MJJ_QCD   ->Write();
  histoWZ_MJJ_WZ    ->Write();
  histoWZ_MJJ_ZZ    ->Write();
  histoWZ_MJJ_VVV   ->Write();
  histoWZ_MJJ_WS    ->Write();
  histoWZ_MJJ_WG    ->Write();
  histoWZ_MJJ_DPS   ->Write();
  histoWZ_MJJ_FakeM ->Write();
  histoWZ_MJJ_FakeE ->Write();
  histoWZ_MJJ_Higgs0->Write();
  histoWZ_MJJ_Higgs1->Write();
  outFilePlotsNote->Close();
  }

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_sig_mjj.root"),"recreate");
  outFilePlotsNote->cd();
  histoSig_MJJ_Data  ->Write();
  histoSig_MJJ_EWK   ->Write();
  histoSig_MJJ_QCD   ->Write();
  histoSig_MJJ_WZ    ->Write();
  histoSig_MJJ_ZZ    ->Write();
  histoSig_MJJ_VVV   ->Write();
  histoSig_MJJ_WS    ->Write();
  histoSig_MJJ_WG    ->Write();
  histoSig_MJJ_DPS   ->Write();
  histoSig_MJJ_FakeM ->Write();
  histoSig_MJJ_FakeE ->Write();
  histoSig_MJJ_Higgs0->Write();
  histoSig_MJJ_Higgs1->Write();
  outFilePlotsNote->Close();
  }

  {
  TFile* outFilePlotsNote = new TFile(Form("histo_sig_mll.root"),"recreate");
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
}
