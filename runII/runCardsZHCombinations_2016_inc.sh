#! /bin/bash

#grep -e combine -e Observed -e "cted 50" log|awk '{if(NR%3==1)printf("%80s ",$9);if(NR%3!=1)printf(" %6.2f ",$5);if(NR%3==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%120s ",$11);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%120s ",$11);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}' |grep mh|awk '{a=0.8839-0.1227;printf("%6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f\n",a*$2,a*$5,a*$5,a*$3,a*$4,a*$6,a*$7)}'

source ~/EVAL_SH66 7_4_7;

export option=$1;

if  [ $option == -1 ] 
then

echo "dummy"

else
# 0+1-jet
cd $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv/$option;
ls histo_limits_zll1hinvll1j_*_shape_13TeV2016_bin0.txt > kkk0
cp kkk0 kkk1
sed -i 's/_shape_13TeV2016_bin0.txt/*.txt/' kkk0;sed -i 's/zll1hinvll1j/zll1hinvll?j/' kkk0;
sed -i 's/_shape_13TeV2016_bin0.txt/.text/' kkk1;sed -i 's/zll1hinvll1j/zll1hinvllnj/' kkk1;
paste kkk0 kkk1 > kkk2
awk '{print"combineCards.py -S histo_limits_wz3l3l_13TeV2016_bin*.txt histo_limits_zz4l1hinvllll1j_shape_13TeV2016_bin*.txt "$1" > "$2}' kkk2 > kkk3
chmod a+x kkk3;./kkk3;

ls histo_limits_zll1hinvllnj_*.text > kkk4
sed -i 's/.text//' kkk4;sed -i 's/zll1hinvll1j/zll1hinvllnj/' kkk4;
awk '{printf("./computeLimit.sh %s %d exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv\n",$1,ENVIRON["option"])}' kkk4 > kkk5
chmod a+x kkk5;
cd -
$HOME/releases/CMSSW_7_4_7/src/cards/cards_inv/$option/kkk5;

rm $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv/$option/kkk*;
fi
