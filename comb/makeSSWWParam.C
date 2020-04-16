void makeSSWWParam(
  int dependentBin,
  int fidAna,
  TString process = "SSWW",
  int numberOfGenBins = 4
) {

  // This will be the string for the dependent parameterization 1 + sum((1-r_i)N_i)/ N_m
  TString paramStr = Form("FR%d rateParam * Signal%d (",dependentBin,dependentBin);
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
    for(int i=0; i<=nGenBins; i++) { // gen bins
      TH1D *nominal;
      if(i != nGenBins) nominal = (TH1D*)f->Get(Form("histo_Signal%d",i)); 
      else              nominal = (TH1D*)f->Get(Form("histo_EWK%s",process.Data())); 
      if(!nominal) continue;
      sumGenBins[i] += nominal->GetSumOfWeights();
      sumGenTotal   += nominal->GetSumOfWeights();
    }
  }

  paramStr+=Form("%.3f", sumGenTotal);
  int var = 0;
  for(int i=0; i<=nGenBins; i++) {
    if(i==dependentBin || sumGenBins[i] <= 0) continue;
    if(i != nGenBins){
      vars.push_back(Form("REWK_%d",i));
      paramStr+=Form("-%.3f*@%d", sumGenBins[i], var);
      var++;
    }
    else {
      paramStr+=Form("-%.3f", sumGenBins[i]);
    }
  }
  paramStr+=Form(")/%.3f",sumGenBins[dependentBin]);
/*
  	if(firstNumeratorTerm) firstNumeratorTerm=false;
  	else		       paramStr+="+";
  paramStr+=Form("(1-@%d)*(%.3f",var,weight); var+=1; vars.push_back(Form("RWW_%d",i-1)); // (1-r)x(the expectation...
        if(binWeight<=0) { if(debug) printf("histo_DY_%d bin %d has 0 entries, skipping\n",i-1,j); continue; }
      if(binError/binWeight<0.005) { if(debug) printf("histo_DY_%d bin %d has less than 0.5%% unc, skipping\n",i-1,j); continue; }
      if(debug) printf("histo_DY_%d bin %d has %.3f entries, %.1f%% unc\n",i-1,j,binWeight,binError/binWeight*100.);
      paramStr+=Form("+%.3f*(@%d)", binError, var); // statistical variations on reco bin
      var+=1; vars.push_back(Form("DYStat_%d_%d%s",i-1,j,channel.Data()));
    }
    paramStr+=")"; // (1-r)x(the expectation +/- bin stats)

        if(i==dependentBin) continue; 
        TH1D *nominal = (TH1D*)f->Get(Form("histoOneBin_qqWW%d",i)); assert(nominal);
        float weight = nominal->Integral();
        if(firstNumeratorTerm) firstNumeratorTerm=false;
        else                   paramStr+="+";
        paramStr+=Form("(1-@%d)*(%.3f",var,weight); var+=1; vars.push_back(Form("RWW_%d",i)); // (1-r)x(the expectation...
        paramStr+=")"; // (1-r)x(the expectation +/- bin stats)
      }
    }
*/
  // list out the independent bin scalings and the stat nuisances in the order in which they appear in the formula
  paramStr+=Form(" %s", vars[0].Data()); 
  for(int iVar=1; iVar<vars.size(); iVar++) {
    paramStr+=Form(",%s",vars[iVar].Data());
  }
  // Done building the paramStr, now print out the parameterization for the datacard
  // printf("###### copy and paste lines below at the bottom of the datacard ######\n");
  char outputName[200];                                     
  sprintf(outputName,"datacard_add.txt");
  ofstream addCardShape;
  addCardShape.open(outputName);
  for(int i=0; i<nGenBins; i++) {
    if(i==dependentBin || sumGenBins[i] <= 0) continue;
    addCardShape << Form("REWK_%d extArg 1.0 [0.0,2.0]\n", i);
  }
  for(int i=0; i<nGenBins; i++) { 
    if(i!=dependentBin && sumGenBins[i] <= 0) continue;
    if(i==dependentBin) 
      addCardShape << Form("%s\n",paramStr.Data());
    else
      addCardShape << Form("FR%d rateParam * Signal%d @0 REWK_%d\n", i, i, i);
  }
}
