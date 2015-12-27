
#! /bin/bash

source ~/EVAL_SH66 6_1_1;

option=$1;

cd /home/ceballos/releases/CMSSW_6_1_1/src/Combination;

if  [ $option == 0 ] 
then

cd /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh/0;
for mass in 110 125 150 200 300 400 500 600
  do
  combineCards.py -S histo_limits_zllhinvll0j_mh${mass}_shape_13TeV2015_bin?.txt > zh${mass}_0j.text
  combineCards.py -S histo_limits_zllhinvll1j_mh${mass}_shape_13TeV2015_bin?.txt > zh${mass}_1j.text
  combineCards.py -S histo_limits_zllhinvll?j_mh${mass}_shape_13TeV2015_bin?.txt > zh${mass}_nj.text
done
cd -;

for mass in 110 125 150 200 300 400 500 600
  do
  ./computeLimit.sh zh${mass}_0j 0 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
done

for mass in 110 125 150 200 300 400 500 600
  do
  ./computeLimit.sh zh${mass}_1j 0 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
done

for mass in 110 125 150 200 300 400 500 600
  do
  ./computeLimit.sh zh${mass}_nj 0 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
done

else

cd /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh/2;
cp histo_limits_zllhinvll0j_mh125_shape_13TeV2015_bin11.txt zh_0j_aux.text
cp histo_limits_zllhinvll1j_mh125_shape_13TeV2015_bin11.txt zh_1j_aux.text 
cd -

for mass in 10 9 8 7 6 5 4 3 2 1 0
  do
  echo "MASS "$mass
  cd /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh/2;
  combineCards.py -S histo_limits_zllhinvll0j_mh125_shape_13TeV2015_bin$mass.txt zh_0j_aux.text > zh_0j.text
  combineCards.py -S histo_limits_zllhinvll1j_mh125_shape_13TeV2015_bin$mass.txt zh_1j_aux.text > zh_1j.text
  combineCards.py -S histo_limits_zllhinvll?j_mh125_shape_13TeV2015_bin$mass.txt zh_?j_aux.text > zh_nj.text
  cp zh_0j.text zh_0j_aux.text
  cp zh_1j.text zh_1j_aux.text
  cd -;
  ./computeLimit.sh zh_0j 2 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
  ./computeLimit.sh zh_1j 2 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
  ./computeLimit.sh zh_nj 2 exp /home/ceballos/releases/CMSSW_6_1_1/src/Combination/cards/zh
done

fi
