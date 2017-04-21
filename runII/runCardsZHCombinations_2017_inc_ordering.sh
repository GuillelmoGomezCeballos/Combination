#! /bin/bash

#grep -e combine -e Observed -e "cted 50" log|awk '{if(NR%3==1)printf("%80s ",$9);if(NR%3!=1)printf(" %6.2f ",$5);if(NR%3==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%80s ",$9);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}'
#grep -e combine -e Observed -e "Expected " log|awk '{if(NR%7==1)printf("%80s ",$9);if(NR%7!=1)printf(" %f ",$5);if(NR%7==0)printf("\n");}' |grep mh|awk '{a=0.8839-0.1227;printf("%6.2f %6.2f %6.2f %6.2f %6.2f %6.2f %6.2f\n",a*$2,a*$5,a*$5,a*$3,a*$4,a*$6,a*$7)}'

#source ~/EVAL_SH66 7_4_7;

#option=$1;
#
if  [ $option == 0 ] 
then

echo "dummy"

else
#cat `ls cards_inv/330/histo_limits_zz4l3hinvllllnj_shape_13TeV2016_bin*.txt | sort -V` `ls cards_inv/330/histo_limits_wz3l3l_13TeV2016_bin*.txt | sort -V` `ls cards_inv/330/histo_limits_zll3hinvll?j_sm_shape_13TeV2016_bin*.txt | sort -V` histo_limits_zll3hinvllnj_sm.text
## 0+1-jet
cd $CMSSW_BASE/src/Combination/runII/cards_inv/$2;
rm -rf emptybins
mkdir emptybins
for i in `grep "0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000" histo_limits_zll3hinvll1j_*_shape_13TeV2016_bin*.txt -l`
do
  mv $i emptybins
done
for i in `grep "0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000" histo_limits_zz4l3hinvllll1j_shape_13TeV2016_bin*.txt -l`
do
  mv $i emptybins
done
for i in `grep "0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000 \+0.00000" histo_limits_wz3l3l_13TeV2016_bin*.txt -l`
do
  mv $i emptybins
done
mv histo_limits_zz4l3hinvllll1j_shape_13TeV2016_bin0.txt emptybins 2> /dev/null
mv histo_limits_wz3l3l_13TeV2016_bin0.txt emptybins 2> /dev/null
#
ls histo_limits_zll3hinvll1j_*_shape_13TeV2016_bin0.txt -1 > kkk0
cp kkk0 kkk1
sed -i 's/_shape_13TeV2016_bin0.txt/*.txt/' kkk0;sed -i 's/zll3hinvll1j/zll3hinvll?j/' kkk0;
sed -i 's/_shape_13TeV2016_bin0.txt/.text/' kkk1;sed -i 's/zll3hinvll1j/zll3hinvllnj/' kkk1;
paste kkk0 kkk1 > kkk2
#awk '{print"combineCards.py -S "$1" > "$2}' kkk2 > kkk3
#awk '{print"combineCards.py -S histo_limits_zz4l3hinvllll1j_shape_13TeV2016_bin*.txt histo_limits_wz3l3l_13TeV2016_bin*.txt "$1" > "$2}' kkk2 > kkk3
#chmod a+x kkk3;./kkk3;
rm kkk3 2> /dev/null
while read line
do
  tokens=( $line )
  combineCards.py -S `ls histo_limits_zz4l3hinvllll1j_shape_13TeV2016_bin*.txt | sort -V | paste -sd " " -` `ls histo_limits_wz3l3l_13TeV2016_bin*.txt | sort -V | paste -sd " " -` `ls $line | sed -n 's/bin/bin/p' | sort -V | paste -sd " " -` > ${tokens[${#tokens[@]}-1]}
done < kkk2

ls histo_limits_zll3hinvllnj_*.text > kkk4
sed -i 's/.text//' kkk4;sed -i 's/zll3hinvll1j/zll3hinvllnj/' kkk4;
awk '{print"./computeLimit.sh "$1" "'"$2"'" obs $CMSSW_BASE/src/Combination/runII/cards_inv"}' kkk4 > kkk5
chmod a+x kkk5;
cd -
$CMSSW_BASE/src/Combination/runII/cards_inv/$2/kkk5;

#rm $CMSSW_BASE/src/Combination/runII/cards_inv/$2/kkk*;
fi
