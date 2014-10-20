#! /bin/bash

#combine -M AsymptoticNew ${workspace} -m ${mass} --scanMin=0.01 --scanMax=5 --nPoints=100 -n hWW${tag} | tee limit${tag}.txt;

# set env
source ~/EVAL_SH66 6_1_1;

tag=$1;
mass=$2;
baseDir=$4;

#workspace=$baseDir/$mass/hww_${tag}.text;
workspace=$baseDir/$mass/${tag}.text;

seed=$RANDOM
mkdir -p /tmp/$USER/${seed}/;
cd /tmp/$USER/${seed}/;

if [ $3 = "exp" ]; then
  # --expectSignal=1
  echo "combine -M Asymptotic ${workspace} --newExpected=1 -t -1 -m ${mass} -n hWWExp${tag} -s ${seed} | tee limitExp${tag}.txt";
        combine -M Asymptotic ${workspace} --newExpected=1 -t -1 -m ${mass} -n hWWExp${tag} -s ${seed} | tee limitExp${tag}.txt;
  mv limitExp${tag}.txt $baseDir/$mass/;
  mv higgsCombinehWWExp${tag}.Asymptotic.mH${mass}.${seed}.root $baseDir/$mass/higgsCombinehWWExp${tag}.Asymptotic.mH${mass}.root;
elif [ $3 = "obs" ]; then
  echo "combine -M Asymptotic ${workspace} --newExpected=1 -m ${mass} -n hWW${tag} -s ${seed} | tee limit${tag}.txt";
        combine -M Asymptotic ${workspace} --newExpected=1 -m ${mass} -n hWW${tag} -s ${seed} | tee limit${tag}.txt;
  mv limit${tag}.txt $baseDir/$mass/;
  mv higgsCombinehWW${tag}.Asymptotic.mH${mass}.${seed}.root $baseDir/$mass/higgsCombinehWW${tag}.Asymptotic.mH${mass}.root;
elif [ $3 = "toy" ]; then
    combine -M HybridNew --frequentist $workspace -m ${mass} -n Toy${tag} --saveToys --fullBToys --saveHybridResult -T 10000 -s ${seed}                        | tee limitToyA${tag}.txt;
    combine -M HybridNew --frequentist $workspace -m ${mass} -n Toy${tag} --grid=higgsCombineToy${tag}.HybridNew.mH${mass}.${seed}.root --expectedFromGrid=0.5 | tee limitToyB${tag}.txt;
    combine -M HybridNew --frequentist $workspace -m ${mass} -n Toy${tag} --grid=higgsCombineToy${tag}.HybridNew.mH${mass}.${seed}.root                        | tee limitToyC${tag}.txt;
    mv higgsCombineToy${tag}.HybridNew.mH${mass}.quant0.500.root higgsCombineToy${tag}.HybridNew.mH${mass}.root limitToy?${tag}.txt $baseDir/$mass/;
else
    echo "don't know what to do for $3";
fi
