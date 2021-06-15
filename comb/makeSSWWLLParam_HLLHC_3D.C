void makeSSWWLLParam_HLLHC_3D(
  int dependentBin,
  int fidAna,
  TString lumStr
) {

  int numberOfGenBins = 3;

  // This will be the string for the dependent parameterization 1 + sum((1-r_i)N_i)/ N_m
  TString paramStr = Form("FR%d rateParam * Signal%d (",dependentBin,dependentBin);
  if     (dependentBin == 0 && fidAna == 5) paramStr = Form("FR%d rateParam * BSM (",dependentBin);
  else if(dependentBin == 1 && fidAna == 5) paramStr = Form("FR%d rateParam * Signal%d (",dependentBin,1);
  else if(dependentBin == 0 && fidAna == 9) paramStr = Form("FR%d rateParam * Signal%d (",dependentBin,3);
  else if(dependentBin == 1 && fidAna == 9) paramStr = Form("FR%d rateParam * Signal%d (",dependentBin,2);
  vector<TString> vars; // list of variables corresponding to the counter
 
  const int nGenBins = numberOfGenBins;

  // Start building the numerator term, it does not contain the stats from the dependent fiducial bin
  double sumGenBins[nGenBins]; double sumGenTotal = 0;
  for(int i=0; i<nGenBins; i++) {
    sumGenBins[i] = 0;
  }
  for(int year=2016; year<=2018; year++) {
    TString theFileName = Form("ssww_%d_fiducial%d_%s_input.root",year,fidAna,lumStr.Data());
    if(gSystem->AccessPathName(theFileName.Data()) == 1) continue;
    TFile *f=TFile::Open(theFileName.Data());
    TH1D *nominal1 = (TH1D*)f->Get(Form("histo_Signal%d",1));
    TH1D *nominal2 = (TH1D*)f->Get(Form("histo_Signal%d",2));
    TH1D *nominal3 = (TH1D*)f->Get(Form("histo_Signal%d",3));
    sumGenBins[0] += nominal1->GetSumOfWeights();
    sumGenBins[1] += nominal2->GetSumOfWeights();
    sumGenBins[2] += nominal3->GetSumOfWeights();
  }
  sumGenTotal = sumGenBins[0] + sumGenBins[1] + sumGenBins[2];

  char outputName[200];                                     
  sprintf(outputName,"datacard_add.txt");
  ofstream addCardShape;
  addCardShape.open(outputName);
  if     (dependentBin == 1 && fidAna == 5){
    addCardShape << Form("REWK2 extArg 1.0 [0.0,2.0]\n");
    addCardShape << Form("REWK3 extArg 1.0 [0.0,2.0]\n");
    addCardShape << Form("FR1 rateParam * Signal1 (%f-%f*@0-%f*@1)/%f REWK2,REWK3\n",sumGenTotal,sumGenBins[1],sumGenBins[2],sumGenBins[0]);
    addCardShape << Form("FR2 rateParam * Signal2  @0 REWK2\n");
    addCardShape << Form("FR3 rateParam * Signal3  @0 REWK3\n");
  }
  else if(dependentBin == 2 && fidAna == 5){
    addCardShape << Form("REWK1 extArg 1.0 [0.0,2.0]\n");
    addCardShape << Form("REWK3 extArg 1.0 [0.0,2.0]\n");
    addCardShape << Form("FR1 rateParam * Signal1  @0 REWK1\n");
    addCardShape << Form("FR2 rateParam * Signal2 (%f-%f*@0-%f*@1)/%f REWK1,REWK3\n",sumGenTotal,sumGenBins[0],sumGenBins[2],sumGenBins[1]);
    addCardShape << Form("FR3 rateParam * Signal3  @0 REWK3\n");
  }
}
