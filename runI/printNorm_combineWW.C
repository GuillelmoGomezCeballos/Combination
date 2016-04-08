//#include <iostream>
//#include <fstream> 
//#include <sstream>
//#include "TFile.h"
//#include "TString.h"
//#include "RooArgSet.h"
//#include "RooRealVar.h"

using namespace std;

void printtableline(TString process, float Npre, float Npost) {
    cout.width(15); cout << process << " & ";
    cout.width(10); cout << Form("%5.1f", Npre) << " & ";
    cout.width(10); cout << Form("%5.1f", (Npre ? Npost : 0.0)) << " & ";
    cout.width(10); cout << Form("%5.1f", (Npre ? (Npost - Npre) : 0.0)) << " & ";
    //cout.width(10); cout << Form("%5.1f", (Npre ? (Npost - Npre)/Npre*100 : 0.0));
    cout.width(10); cout << Form("%5.3f", (Npre ? Npost/Npre : 0.0));
    cout.width(10); cout << "\\\\" << endl;
}
//main
void printNorm_combineWW(TString mlfit="mlfit.root", TString card="cards/test/125/hwwof_0j_shape_8TeV.txt") {

    // ---------------------
    //      PRE-FIT 
    // ---------------------

    // get prefit normalization from a card   
    string line;
    ifstream incard(card.Data()); 

    char* tmp   =   "";
    float pre_qqWW   = 0.; float post_qqWW   = 0.;
    float pre_ggWW   = 0.; float post_ggWW   = 0.;
    float pre_Higgs  = 0.; float post_Higgs  = 0.;
    float pre_VV     = 0.; float post_VV     = 0.;
    float pre_VVV    = 0.; float post_VVV    = 0.;
    float pre_Top    = 0.; float post_Top    = 0.;
    float pre_Zjets  = 0.; float post_Zjets  = 0.;
    float pre_Ztt    = 0.; float post_Ztt    = 0.;
    float pre_Wg3l   = 0.; float post_Wg3l   = 0.;
    float pre_Wgamma = 0.; float post_Wgamma = 0.;
    float pre_WjetsE = 0.; float post_WjetsE = 0.;
    float pre_WjetsM = 0.; float post_WjetsM = 0.;

    if (incard.is_open())
    {
        while ( incard.good() )
        { 
            // get a line from input file
            getline (incard,line);

            // skip the line if it does not contain "rate" 
            if( line.find("rate")==string::npos ) continue;
              
            stringstream stream(line);
            stream >> tmp;
            stream >> pre_qqWW;
            stream >> pre_ggWW;
            stream >> pre_Higgs;
            stream >> pre_VV;
            stream >> pre_VVV;
            stream >> pre_Top;
            stream >> pre_Zjets;
            stream >> pre_Ztt;
            stream >> pre_Wg3l;
            stream >> pre_Wgamma;
            stream >> pre_WjetsE;
            stream >> pre_WjetsM; 

            if( !incard.good() ) continue;
        }
    } else { cout << "problem reading, exiting..." << endl; return;}
    incard.close(); 

    cout << "have read prefit yields..." << endl;

    // ---------------------
    //      POST-FIT 
    // ---------------------
    TFile *postFile = TFile::Open(mlfit.Data(), "READ"); 
    postFile->ls(); 
    RooArgSet *norm_fit_s = (RooArgSet*)postFile->Get("norm_fit_s");
    norm_fit_s->Print("v"); // for debugging  
    RooRealVar *r; 
    
    if(pre_qqWW  ) { r =  (RooRealVar*) norm_fit_s->find("ch1/qqWW");   post_qqWW   =   (float)r->getVal(); } 
    if(pre_ggWW  ) { r =  (RooRealVar*) norm_fit_s->find("ch1/ggWW");   post_ggWW   =   (float)r->getVal(); } 
    if(pre_Higgs ) { r =  (RooRealVar*) norm_fit_s->find("ch1/Higgs");  post_Higgs  =   (float)r->getVal(); } 
    if(pre_VV	 ) { r =  (RooRealVar*) norm_fit_s->find("ch1/VV");     post_VV	    =   (float)r->getVal(); } 
    if(pre_VVV   ) { r =  (RooRealVar*) norm_fit_s->find("ch1/VVV");    post_VVV    =   (float)r->getVal(); } 
    if(pre_Top   ) { r =  (RooRealVar*) norm_fit_s->find("ch1/Top");    post_Top    =   (float)r->getVal(); } 
    if(pre_Zjets ) { r =  (RooRealVar*) norm_fit_s->find("ch1/Zjets");  post_Zjets  =   (float)r->getVal(); } 
    if(pre_Ztt   ) { r =  (RooRealVar*) norm_fit_s->find("ch1/Ztt");    post_Ztt    =   (float)r->getVal(); } 
    if(pre_Wg3l  ) { r =  (RooRealVar*) norm_fit_s->find("ch1/Wg3l");   post_Wg3l   =   (float)r->getVal(); } 
    if(pre_Wgamma) { r =  (RooRealVar*) norm_fit_s->find("ch1/Wgamma"); post_Wgamma =   (float)r->getVal(); } 
    if(pre_WjetsE) { r =  (RooRealVar*) norm_fit_s->find("ch1/WjetsE"); post_WjetsE =   (float)r->getVal(); } 
    if(pre_WjetsM) { r =  (RooRealVar*) norm_fit_s->find("ch1/WjetsM"); post_WjetsM =   (float)r->getVal(); } 

    // 
    // print table 
    // 
    // -------------------------------------------------------------------------------
    //      print table 
    // -------------------------------------------------------------------------------
    cout << "\\begin{table}[ht!]" << endl;
    cout << "\\begin{center}" << endl;
    cout << "\\begin{tabular}{c|cc|cc}" << endl;
    cout << "\\hline" << endl;   cout << "\\hline" << endl;
    cout << "        Process &    N(prefit) &   N(postfit) & Difference(raw) &  Difference(\\%)  \\\\  " << endl;
    cout << "\\hline" << endl;   cout << "\\hline" << endl;
    printtableline("qqWW",          pre_qqWW,   post_qqWW);
    printtableline("ggWW",          pre_ggWW,   post_ggWW);
    cout << "\\hline" << endl;
    printtableline("Higgs",         pre_Higgs,  post_Higgs);
    printtableline("VV",            pre_VV,     post_VV);
    printtableline("VVV",           pre_VVV,    post_VVV);
    printtableline("Top",           pre_Top,    post_Top);
    printtableline("Zjets",         pre_Zjets,  post_Zjets);
    printtableline("Ztt",           pre_Ztt,    post_Ztt);
    printtableline("W$\\gamma$*",   pre_Wg3l,   post_Wg3l);
    printtableline("W$\\gamma$",    pre_Wgamma, post_Wgamma);
    printtableline("Wjets($e$)",    pre_WjetsE, post_WjetsE);
    printtableline("Wjets($\\mu$)", pre_WjetsM, post_WjetsM);
    cout << "\\hline" << endl;   cout << "\\hline" << endl;
    cout << "\\end{tabular}" << endl;
    //cout << "\\caption{ }" << endl;
    cout << "\\end{center}" << endl;
    cout << "\\end{table}" << endl;
}
