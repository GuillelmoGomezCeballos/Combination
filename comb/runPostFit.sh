#!/bin/sh

if [ $# -lt 1 ]; then
   echo "TOO FEW PARAMETERS";
   exit;
fi

source /cvmfs/cms.cern.ch/cmsset_default.sh;
cd ~/releases/CMSSW_10_6_27/src/;
eval `scramv1 runtime -sh`;
cd -;

PostFitShapesFromWorkspace -w workspace_$1.root -o postfit_$2.root --postfit --print -f fitDiagnostics$1.root:$3
