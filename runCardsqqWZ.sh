#!/bin/bash

source ~/EVAL_SH66 6_1_1;

cd ~/releases/CMSSW_6_1_1/src/Combination/;

for mass in 500 900; do
  for fn in 0 1 2 9 19; do
    cd cards_qqwz/$mass/$fn;
    combineCards.py -S histo_limits_qqwzll_shape_8TeV_Bin*txt > qqwz.text;
    cd -;
    ./computeLimit.sh qqwz $fn obs $PWD/cards_qqwz/$mass;
  done
done

cd -;

