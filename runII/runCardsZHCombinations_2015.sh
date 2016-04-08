 #! /bin/bash

#grep -e combine -e Observed -e "cted 50" log|awk '{if(NR%3==1)printf("%80s ",$9);if(NR%3!=1)printf(" %6.2f ",$5);if(NR%3==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%80s ",$9);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%80s ",$9);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}' |grep mh|awk '{a=0.8839-0.1227;printf("%6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f\n",a*$2,a*$5,a*$5,a*$3,a*$4,a*$6,a*$7)}'

source ~/EVAL_SH66 7_1_5;

option=$1;

if  [ $option == 0 ] 
then

echo "dummy"

else
# 0-jet
cd cards_inv/0;
ls histo_limits_zllhinvll0j_*_shape_13TeV2015_bin0.txt > kkk0
cp kkk0 kkk1
sed -i 's/_shape_13TeV2015_bin0.txt/*.txt/' kkk0
sed -i 's/_shape_13TeV2015_bin0.txt/.text/' kkk1
paste kkk0 kkk1 > kkk2
awk '{print"combineCards.py -S "$1" > "$2}' kkk2 > kkk3
chmod a+x kkk3;./kkk3;

ls histo_limits_zllhinvll0j_*.text > kkk4
sed -i 's/.text//' kkk4
awk '{print"./computeLimit.sh "$1" 0 obs $PWD/cards_inv"}' kkk4 > kkk5
chmod a+x kkk5;
cd ../..
./cards_inv/0/kkk5;

# 1-jet
cd cards_inv/0;
ls histo_limits_zllhinvll1j_*_shape_13TeV2015_bin0.txt > kkk0
cp kkk0 kkk1
sed -i 's/_shape_13TeV2015_bin0.txt/*.txt/' kkk0
sed -i 's/_shape_13TeV2015_bin0.txt/.text/' kkk1
paste kkk0 kkk1 > kkk2
awk '{print"combineCards.py -S "$1" > "$2}' kkk2 > kkk3
chmod a+x kkk3;./kkk3;

ls histo_limits_zllhinvll1j_*.text > kkk4
sed -i 's/.text//' kkk4
awk '{print"./computeLimit.sh "$1" 0 obs $PWD/cards_inv"}' kkk4 > kkk5
chmod a+x kkk5;
cd ../..
./cards_inv/0/kkk5;

# 0+1-jet
cd cards_inv/0;
ls histo_limits_zllhinvll1j_*_shape_13TeV2015_bin0.txt > kkk0
cp kkk0 kkk1
sed -i 's/_shape_13TeV2015_bin0.txt/*.txt/' kkk0;sed -i 's/zllhinvll1j/zllhinvll?j/' kkk0;
sed -i 's/_shape_13TeV2015_bin0.txt/.text/' kkk1;sed -i 's/zllhinvll1j/zllhinvllnj/' kkk1;
paste kkk0 kkk1 > kkk2
awk '{print"combineCards.py -S "$1" > "$2}' kkk2 > kkk3
chmod a+x kkk3;./kkk3;

ls histo_limits_zllhinvll1j_*.text > kkk4
sed -i 's/.text//' kkk4;sed -i 's/zllhinvll1j/zllhinvllnj/' kkk4;
awk '{print"./computeLimit.sh "$1" 0 obs $PWD/cards_inv"}' kkk4 > kkk5
chmod a+x kkk5;
cd ../..
./cards_inv/0/kkk5;

rm cards_inv/0/kkk*;
fi
