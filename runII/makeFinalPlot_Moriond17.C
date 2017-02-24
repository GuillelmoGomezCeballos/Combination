void makeFinalPlot_Moriond17(int nsel = 0){

  double dmSF = 0.339*3;
  
  const int nBinMVA = 11; Float_t xbins[nBinMVA+1] = {50, 100, 125, 150, 175, 200, 250, 300, 350, 400, 500, 600};
  TH1D* histoMVA = new TH1D("histos", "histos", nBinMVA, xbins);
    
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

  histo_ZZ->SetBinContent( 1,12.492);  histo_ZZ->SetBinError( 1,1.615);
  histo_ZZ->SetBinContent( 2,13.577);  histo_ZZ->SetBinError( 2,1.534);
  histo_ZZ->SetBinContent( 3, 8.947);  histo_ZZ->SetBinError( 3,0.878);
  histo_ZZ->SetBinContent( 4, 6.803);  histo_ZZ->SetBinError( 4,0.749);
  histo_ZZ->SetBinContent( 5, 3.839);  histo_ZZ->SetBinError( 5,0.538);
  histo_ZZ->SetBinContent( 6, 5.034);  histo_ZZ->SetBinError( 6,0.652);
  histo_ZZ->SetBinContent( 7, 1.498);  histo_ZZ->SetBinError( 7,0.289);
  histo_ZZ->SetBinContent( 8, 1.171);  histo_ZZ->SetBinError( 8,0.284);
  histo_ZZ->SetBinContent( 9, 0.699);  histo_ZZ->SetBinError( 9,0.217);
  histo_ZZ->SetBinContent(10, 0.446);  histo_ZZ->SetBinError(10,0.161);
  histo_ZZ->SetBinContent(11, 0.060);  histo_ZZ->SetBinError(11,0.052);

  histo_VVV->SetBinContent( 1,0.044);  histo_VVV->SetBinError( 1,0.016);
  histo_VVV->SetBinContent( 2,0.112);  histo_VVV->SetBinError( 2,0.037);
  histo_VVV->SetBinContent( 3,0.055);  histo_VVV->SetBinError( 3,0.028);
  histo_VVV->SetBinContent( 4,0.045);  histo_VVV->SetBinError( 4,0.017);
  histo_VVV->SetBinContent( 5,0.070);  histo_VVV->SetBinError( 5,0.028);
  histo_VVV->SetBinContent( 6,0.057);  histo_VVV->SetBinError( 6,0.022);
  histo_VVV->SetBinContent( 7,0.081);  histo_VVV->SetBinError( 7,0.045);
  histo_VVV->SetBinContent( 8,0.005);  histo_VVV->SetBinError( 8,0.003);
  histo_VVV->SetBinContent( 9,0.003);  histo_VVV->SetBinError( 9,0.003);
  histo_VVV->SetBinContent(10,0.030);  histo_VVV->SetBinError(10,0.024);
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

  histo_EM->SetBinContent( 1, 26.265);  histo_EM->SetBinError( 1,  6.96175); 
  histo_EM->SetBinContent( 2, 18.580);  histo_EM->SetBinError( 2,  5.93321); 
  histo_EM->SetBinContent( 3,  9.289);  histo_EM->SetBinError( 3,  3.70970); 
  histo_EM->SetBinContent( 4,  6.261);  histo_EM->SetBinError( 4,  3.86856); 
  histo_EM->SetBinContent( 5,  6.421);  histo_EM->SetBinError( 5,  3.86134); 
  histo_EM->SetBinContent( 6,  3.809);  histo_EM->SetBinError( 6,  2.32584); 
  histo_EM->SetBinContent( 7,  0.000);  histo_EM->SetBinError( 7,  0.00000);
  histo_EM->SetBinContent( 8,  0.598);  histo_EM->SetBinError( 8,  0.86200);
  histo_EM->SetBinContent( 9,  0.045);  histo_EM->SetBinError( 9,  0.06700);
  histo_EM->SetBinContent(10,  0.000);  histo_EM->SetBinError(10,  0.00000);
  histo_EM->SetBinContent(11,  0.261);  histo_EM->SetBinError(11,  0.35600);
  
  histo_Zjets->SetBinContent( 1, 2.171);  histo_Zjets->SetBinError( 1, 1.093);
  histo_Zjets->SetBinContent( 2, 3.661);  histo_Zjets->SetBinError( 2, 1.538);
  histo_Zjets->SetBinContent( 3, 5.276);  histo_Zjets->SetBinError( 3, 1.353);
  histo_Zjets->SetBinContent( 4, 2.726);  histo_Zjets->SetBinError( 4, 1.262);
  histo_Zjets->SetBinContent( 5, 0.718);  histo_Zjets->SetBinError( 5, 0.922);
  histo_Zjets->SetBinContent( 6, 1.120);  histo_Zjets->SetBinError( 6, 1.024);
  histo_Zjets->SetBinContent( 7, 0.471);  histo_Zjets->SetBinError( 7, 0.942);
  histo_Zjets->SetBinContent( 8, 0.393);  histo_Zjets->SetBinError( 8, 0.389);
  histo_Zjets->SetBinContent( 9, 0.000);  histo_Zjets->SetBinError( 9, 0.000);
  histo_Zjets->SetBinContent(10, 0.000);  histo_Zjets->SetBinError(10, 0.000);
  histo_Zjets->SetBinContent(11, 0.357);  histo_Zjets->SetBinError(11, 0.300);

  histo_WZ->SetBinContent( 1,78.696);  histo_WZ->SetBinError( 1,9.495);
  histo_WZ->SetBinContent( 2,89.547);  histo_WZ->SetBinError( 2,9.771);
  histo_WZ->SetBinContent( 3,64.858);  histo_WZ->SetBinError( 3,6.229);
  histo_WZ->SetBinContent( 4,46.297);  histo_WZ->SetBinError( 4,5.713);
  histo_WZ->SetBinContent( 5,24.160);  histo_WZ->SetBinError( 5,3.591);
  histo_WZ->SetBinContent( 6,32.842);  histo_WZ->SetBinError( 6,4.350);
  histo_WZ->SetBinContent( 7,11.298);  histo_WZ->SetBinError( 7,2.212);
  histo_WZ->SetBinContent( 8, 8.889);  histo_WZ->SetBinError( 8,2.227);
  histo_WZ->SetBinContent( 9, 4.370);  histo_WZ->SetBinError( 9,1.323);
  histo_WZ->SetBinContent(10, 3.363);  histo_WZ->SetBinError(10,1.321);
  histo_WZ->SetBinContent(11, 0.466);  histo_WZ->SetBinError(11,0.372);

  histo_ZZ->SetBinContent( 1,7.100);  histo_ZZ->SetBinError( 1,0.386);
  histo_ZZ->SetBinContent( 2,6.753);  histo_ZZ->SetBinError( 2,0.373);
  histo_ZZ->SetBinContent( 3,5.332);  histo_ZZ->SetBinError( 3,0.293);
  histo_ZZ->SetBinContent( 4,3.187);  histo_ZZ->SetBinError( 4,0.195);
  histo_ZZ->SetBinContent( 5,1.987);  histo_ZZ->SetBinError( 5,0.161);
  histo_ZZ->SetBinContent( 6,2.040);  histo_ZZ->SetBinError( 6,0.146);
  histo_ZZ->SetBinContent( 7,0.830);  histo_ZZ->SetBinError( 7,0.085);
  histo_ZZ->SetBinContent( 8,0.388);  histo_ZZ->SetBinError( 8,0.049);
  histo_ZZ->SetBinContent( 9,0.194);  histo_ZZ->SetBinError( 9,0.038);
  histo_ZZ->SetBinContent(10,0.130);  histo_ZZ->SetBinError(10,0.026);
  histo_ZZ->SetBinContent(11,0.044);  histo_ZZ->SetBinError(11,0.013);
  
  histo_VVV->SetBinContent( 1,0.519);  histo_VVV->SetBinError( 1,0.106);
  histo_VVV->SetBinContent( 2,0.721);  histo_VVV->SetBinError( 2,0.113);
  histo_VVV->SetBinContent( 3,0.993);  histo_VVV->SetBinError( 3,0.198);
  histo_VVV->SetBinContent( 4,0.506);  histo_VVV->SetBinError( 4,0.099);
  histo_VVV->SetBinContent( 5,0.559);  histo_VVV->SetBinError( 5,0.115);
  histo_VVV->SetBinContent( 6,0.687);  histo_VVV->SetBinError( 6,0.120);
  histo_VVV->SetBinContent( 7,0.404);  histo_VVV->SetBinError( 7,0.084);
  histo_VVV->SetBinContent( 8,0.262);  histo_VVV->SetBinError( 8,0.070);
  histo_VVV->SetBinContent( 9,0.189);  histo_VVV->SetBinError( 9,0.053);
  histo_VVV->SetBinContent(10,0.133);  histo_VVV->SetBinError(10,0.044);
  histo_VVV->SetBinContent(11,0.075);  histo_VVV->SetBinError(11,0.041);
  
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
