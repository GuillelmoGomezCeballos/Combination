#!/bin/sh

export PARAM="";
export ADDTEXT="_obs";
export PARAMGOF="";

if [ $# -lt 4 ]; then
   echo "TOO FEW PARAMETERS"
   exit
fi

cd $1;
RESULT=$?
if [ $RESULT -ne 0 ]; then
  echo "$1: failed"
  exit;
fi

ls workspace_$2.root;
RESULT=$?
if [ $RESULT -ne 0 ]; then
  echo "$2: failed"
  exit;
fi

if [ $4 = "exp" ]; then
  PARAM="--setParameters r_s0=1 -t -1"; #--toysFrequentist
  PARAML="--noFitAsimov";
  ADDTEXT="_exp";
  PARAMGOF="-t 300";
elif [ $4 = "expnosig" ]; then
  PARAM="--setParameters r_s0=0 -t -1"; #--toysFrequentist
  PARAML="--noFitAsimov";
  ADDTEXT="_expnosig";
  PARAMGOF="-t 300";
fi

if [ $3 = "mu" ]; then
  combine -M MultiDimFit workspace_$2.root -n $2${ADDTEXT} --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP --saveFitResult --saveWorkspace $PARAM

elif [ $3 = "impacts" ]; then
  # run on t3btch051 or t3btch053
  combineTool.py -M Impacts -d workspace_$2.root -m 125 -n $2${ADDTEXT} --robustFit 1 --X-rtd FITTER_DYN_STEP --rMin=-2 --rMax=3 --doInitialFit $PARAM;
  #combineTool.py -M Impacts -d workspace_$2.root -m 125 -n $2${ADDTEXT} --robustFit 1 --X-rtd FITTER_DYN_STEP --rMin=-2 --rMax=3 --doFits --parallel 15 $PARAM;
  combineTool.py -M Impacts -d workspace_$2.root -m 125 -n $2${ADDTEXT} --robustFit 1 --X-rtd FITTER_DYN_STEP --rMin=-2 --rMax=3 --doFits $PARAM;
  combineTool.py -M Impacts -d workspace_$2.root -m 125 -n $2${ADDTEXT} -o impacts$2${ADDTEXT}.json $PARAM;
  plotImpacts.py -i impacts$2${ADDTEXT}.json -o impacts$2${ADDTEXT};

elif [ $3 = "mlf" ]; then
 #combine -M FitDiagnostics workspace_$2.root -n $2${ADDTEXT} --plots --saveNorm --saveShapes --saveWithUncertainties --saveOverall --ignoreCovWarning --rMin=-2 --rMax=3 --robustFit=1 --X-rtd FITTER_DYN_STEP $PARAM $5
  combine -M FitDiagnostics workspace_$2.root -n $2${ADDTEXT}         --saveNorm --saveShapes --saveWithUncertainties --saveOverall --ignoreCovWarning --rMin=-1 --rMax=3 --robustFit=1 --X-rtd FITTER_DYN_STEP $PARAM $5

elif [ $3 = "significance" ]; then
  combine workspace_$2.root -M Significance --significance -n $2${ADDTEXT} $PARAM

elif [ $3 = "significanceToys" ]; then
  combine workspace_$2.root -M GenerateOnly --setParameters r_s0=1 -t -1 --toysFrequentist --saveToys -n $2${ADDTEXT} --cminDefaultMinimizerStrategy 0
  combine workspace_$2.root -M Significance --significance --toysFrequentist -t -1 --toysFile higgsCombine$2${ADDTEXT}.GenerateOnly.mH120.123456.root --cminDefaultMinimizerStrategy 0

elif [ $3 = "limit" ]; then
  combine -M AsymptoticLimits workspace_$2.root --newExpected=1 -n $2${ADDTEXT} --rMax 1.0 $PARAML

elif [ $3 = "limitToys" ]; then
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_obs --LHCmode LHC-limits --rAbsAcc=0.05
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_exp0p025 --LHCmode LHC-limits --rAbsAcc=0.05 --expectedFromGrid=0.025
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_exp0p160 --LHCmode LHC-limits --rAbsAcc=0.05 --expectedFromGrid=0.160
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_exp0p500 --LHCmode LHC-limits --rAbsAcc=0.05 --expectedFromGrid=0.500
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_exp0p840 --LHCmode LHC-limits --rAbsAcc=0.05 --expectedFromGrid=0.840
  combine -M HybridNew workspace_$2.root -n $2${ADDTEXT}_exp0p975 --LHCmode LHC-limits --rAbsAcc=0.05 --expectedFromGrid=0.975

elif [ $3 = "scan" ]; then
combine -M MultiDimFit workspace_$2.root -n $2${ADDTEXT} --algo=grid --robustFit=1 --X-rtd FITTER_DYN_STEP --points=400 -P r_s0 --floatOtherPOIs=1 --setParameterRanges r_s0=0,2 $5

elif [ $3 = "gof" ]; then
combine -M GoodnessOfFit workspace_$2.root -n $2${ADDTEXT} --algo=saturated $PARAMGOF

else
  echo "wrong option"

fi

rm -f combine_logger.out;
