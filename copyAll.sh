#! /bin/bash

rm -rf ana_Combination;
mkdir -p ana_Combination;

for mass in 110 115 120 125 130 135 140 150 160 170 180 190 200 250 300 350 400 450 500 550 600
do
  mkdir -p ana_Combination/$mass;
  scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/couplings/vhww/$mass/* ana_Combination/$mass/;
  scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/couplings/hww2l2v/$mass/* ana_Combination/$mass/;
done

mkdir -p ana_Combination/126;
scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/couplings/vhww/125.6/* ana_Combination/126/;
scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/couplings/hww2l2v/125.6/* ana_Combination/126/;


rm -rf ana_Combination_SMH;
mkdir -p ana_Combination_SMH;

for mass in 110 115 120 125 130 135 140 150 160 170 180 190 200 250 300 350 400 450 500 550 600
do
  mkdir -p ana_Combination_SMH/$mass;
  scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/searches/vhww/$mass/* ana_Combination_SMH/$mass/;
  scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/searches/hww2l2v/$mass/* ana_Combination_SMH/$mass/;
done

mkdir -p ana_Combination_SMH/126;
scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/searches/vhww/125.6/* ana_Combination_SMH/126/;
scp -r dtmit02:/build/ceballos/cmshcg/trunk/summer2013/searches/hww2l2v/125.6/* ana_Combination_SMH/126/;
