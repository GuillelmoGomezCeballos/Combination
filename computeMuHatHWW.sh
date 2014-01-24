#! /bin/bash

# set env
source ~/EVAL_SH66 6_1_1;

tag=$1;
mass=$2;
baseDir=$3;

#workspace=$baseDir/$mass/hww_${tag}.text
workspace=$baseDir/$mass/${tag}.text

seed=$RANDOM
mkdir -p /tmp/$USER/${seed}/
cd /tmp/$USER/${seed}/

echo "combine -M MaxLikelihoodFit ${workspace} -m ${mass} --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWW${tag} | tee mlf${tag}.txt"
      combine -M MaxLikelihoodFit ${workspace} -m ${mass} --rMin=-2 --rMax=4 --robustFit=1 --X-rtd FITTER_DYN_STEP -n hWW${tag} | tee mlf${tag}.txt;
mv higgsCombinehWW${tag}.MaxLikelihoodFit.mH${mass}.root mlf${tag}.txt $baseDir/$mass/;
mv mlfithWW${tag}.root $baseDir/$mass/;
# --expectSignal=1 -t -1
