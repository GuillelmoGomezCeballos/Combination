#! /bin/bash

# set env
source ~/EVAL_SH66 7_1_5;

tag=$1;
mass=$2;
baseDir=$4;

#workspace=$baseDir/$mass/hww_${tag}.text
workspace=$baseDir/$mass/${tag}.text

seed=$RANDOM
mkdir -p /tmp/$USER/${seed}/
cd /tmp/$USER/${seed}/

if [ $3 = "exp" ]; then
  echo "combine -M MaxLikelihoodFit ${workspace} -m ${mass} --expectSignal=1 -t -1 --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWWExp${tag} | tee mlfExp${tag}.txt"
        combine -M MaxLikelihoodFit ${workspace} -m ${mass} --expectSignal=1 -t -1 --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWWExp${tag} | tee mlfExp${tag}.txt;
  mv higgsCombinehWWExp${tag}.MaxLikelihoodFit.mH${mass}.root mlfExp${tag}.txt $baseDir/$mass/;
  mv mlfithWWExp${tag}.root $baseDir/$mass/;
elif [ $3 = "obs" ]; then
  echo "combine -M MaxLikelihoodFit ${workspace} -m ${mass} --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWW${tag} | tee mlf${tag}.txt"
       #combine -M MaxLikelihoodFit ${workspace} -m ${mass} --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWW${tag} | tee mlf${tag}.txt;
        combine -M MaxLikelihoodFit ${workspace} -m ${mass} --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWW${tag} | tee mlf${tag}.txt;
  mv higgsCombinehWW${tag}.MaxLikelihoodFit.mH${mass}.root mlf${tag}.txt $baseDir/$mass/;
  mv mlfithWW${tag}.root $baseDir/$mass/;
else
    echo "don't know what to do for $3";
fi
