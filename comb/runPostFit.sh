#!/bin/sh

if [ $# -lt 1 ]; then
   echo "TOO FEW PARAMETERS";
   exit;
fi

source /cvmfs/cms.cern.ch/cmsset_default.sh;
cd ~/releases/CMSSW_10_6_27/src/;
eval `scramv1 runtime -sh`;
cd -;

PostFitShapesFromWorkspace -w workspace_$1.root -o postfit_$2.root \
-f fitDiagnostics$2.root:$3 --postfit --print 1 --total-shapes 1 --covariance 1

#https://github.com/cms-analysis/CombineHarvester/compare/main...DickyChant:CombineHarvester:sqian_wwg_test_total_cor_total_var
#/home/submit/ceballos/ana_area/Combination/comb/runPostFit.sh ssww_comb_wwwz ssww_comb_wwwz_obs fit_s
