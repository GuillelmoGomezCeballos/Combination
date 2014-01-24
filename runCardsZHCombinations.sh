
#! /bin/bash

source ~/EVAL_SH66 6_1_1;

baseDir=$1;
ls $baseDir >& /dev/null;
if [ $? != 0 ]; then
  echo "Wrong folder";
  echo "e.g. /afs/cern.ch/user/c/ceballos/releases/CMSSW_4_2_8/src/Smurf/cards/HWW2l/ana_test";
  exit;
fi

for mass in 105 115 125 135 145 175 200 300
  do
  cd $baseDir/${mass}
  echo "combine cards for MH=${mass} "
  combineCards.py -S z??hinv_nj0_cut_?TeV.txt > zh0_cut.text
  combineCards.py -S z??hinv_nj1_cut_?TeV.txt > zh1_cut.text
  combineCards.py -S z??hinv_nj?_cut_?TeV.txt > zhn_cut.text
  combineCards.py -S z??hinv_nj0_shape_?TeV.txt > zh0_shape.text
  combineCards.py -S z??hinv_nj1_shape_?TeV.txt > zh1_shape.text
  combineCards.py -S z??hinv_nj?_shape_?TeV.txt > zhn_shape.text
done
