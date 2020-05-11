void makeSSWWLLParam(
  int dependentBin,
  int fidAna
) {

  int numberOfGenBins = 2;

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
    TString theFileName = Form("ssww_%d_fiducial%d_input.root",year,fidAna);
    if(gSystem->AccessPathName(theFileName.Data()) == 1) continue;
    TFile *f=TFile::Open(theFileName.Data());
    if     (fidAna == 5) {
      TH1D *nominal0 = (TH1D*)f->Get(Form("histo_BSM")); 
      TH1D *nominal1 = (TH1D*)f->Get(Form("histo_Signal%d",1));
      sumGenBins[0] += nominal0->GetSumOfWeights();
      sumGenBins[1] += nominal1->GetSumOfWeights();
    }
    else if(fidAna == 9) {
      TH1D *nominal0 = (TH1D*)f->Get(Form("histo_Signal%d",3));
      TH1D *nominal1 = (TH1D*)f->Get(Form("histo_Signal%d",2));
      sumGenBins[0] += nominal0->GetSumOfWeights();
      sumGenBins[1] += nominal1->GetSumOfWeights();
    }
  }
  sumGenTotal = sumGenBins[0] + sumGenBins[1];

  paramStr+=Form("%.3f", sumGenTotal);
  if     (dependentBin == 0) {
    paramStr+=Form("-%.3f*@%d", sumGenBins[1], 0);
  }
  else if(dependentBin == 1) {
    paramStr+=Form("-%.3f*@%d", sumGenBins[0], 0);
  }
  paramStr+=Form(")/%.3f", sumGenBins[dependentBin]);
  paramStr+=Form(" REWK_%d",dependentBin);

  char outputName[200];                                     
  sprintf(outputName,"datacard_add.txt");
  ofstream addCardShape;
  addCardShape.open(outputName);
  addCardShape << Form("REWK_%d extArg 1.0 [0.0,2.0]\n", dependentBin);
  addCardShape << Form("%s\n",paramStr.Data());
  if     (dependentBin == 0 && fidAna == 5) addCardShape << Form("FR%d rateParam * Signal%d @0 REWK_%d\n", 1, 1, dependentBin);
  else if(dependentBin == 1 && fidAna == 5) addCardShape << Form("FR%d rateParam * BSM      @0 REWK_%d\n", 0,    dependentBin);
  else if(dependentBin == 0 && fidAna == 9) addCardShape << Form("FR%d rateParam * Signal%d @0 REWK_%d\n", 1, 2, dependentBin);
  else if(dependentBin == 1 && fidAna == 9) addCardShape << Form("FR%d rateParam * Signal%d @0 REWK_%d\n", 0, 3, dependentBin);
}
