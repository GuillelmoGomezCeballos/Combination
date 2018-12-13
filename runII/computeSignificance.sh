#! /bin/bash

# set env
source ~/EVAL_SH66 8_1_0;

tag=$1;
mass=$2;
baseDir=$4;

#workspace=$baseDir/$mass/hww_${tag}.text
workspace=$baseDir/$mass/${tag}.text

seed=$RANDOM
mkdir -p /tmp/$USER/${seed}/
cd /tmp/$USER/${seed}/

if [ $3 = "exp" ]; then
    echo "combine $workspace -M ProfileLikelihood --significance --expectSignal=1 -t -1 -m ${mass} -n Expected${tag} -s ${seed} | tee expected${tag}.txt";
          combine $workspace -M ProfileLikelihood --significance --expectSignal=1 -t -1 -m ${mass} -n Expected${tag} -s ${seed} | tee expected${tag}.txt;
    mv expected${tag}.txt $baseDir/$mass/;
    mv higgsCombineExpected${tag}.ProfileLikelihood.mH${mass}.${seed}.root $baseDir/$mass/higgsCombineExpected${tag}.ProfileLikelihood.mH${mass}.root;
elif [ $3 = "obs" ]; then
    echo "combine $workspace -M ProfileLikelihood --significance -m ${mass} -n Observed${tag} -s ${seed} | tee observed${tag}.txt";
          combine $workspace -M ProfileLikelihood --significance -m ${mass} -n Observed${tag} -s ${seed} | tee observed${tag}.txt;
    mv observed${tag}.txt $baseDir/$mass/;
    mv higgsCombineObserved${tag}.ProfileLikelihood.mH${mass}.${seed}.root $baseDir/$mass/higgsCombineObserved${tag}.ProfileLikelihood.mH${mass}.root;
elif [ $3 = "toy" ]; then
    combine -M HybridNew --frequentist $workspace --significance -m ${mass} -n SigniToy${tag} --saveToys --fullBToys --saveHybridResult -T 2000 -i 10 -s ${seed} 			      | tee SigniToyA${tag}.txt;
    combine -M HybridNew --frequentist $workspace --significance -m ${mass} -n SigniToy${tag} --readHybridResult --toysFile=higgsCombineSigniToy${tag}.HybridNew.mH${mass}.${seed}.root --expectedFromGrid=0.5 | tee SigniToyB${tag}.txt;
    combine -M HybridNew --frequentist $workspace --significance -m ${mass} -n SigniToy${tag} --readHybridResult --toysFile=higgsCombineSigniToy${tag}.HybridNew.mH${mass}.${seed}.root  		 | tee SigniToyC${tag}.txt;
    mv higgsCombineSigniToy${tag}.HybridNew.mH${mass}.quant0.500.root higgsCombineSigniToy${tag}.HybridNew.mH${mass}.root SigniToy?${tag}.txt $baseDir/$mass/;
else
    echo "don't know what to do for $3";
fi
