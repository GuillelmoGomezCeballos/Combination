#/!/bin/sh

cat > list_chan <<EOF
mh800
DarkMatter_MonoZToLL_A_Mx-50_Mv-200_gDMgQ-1
DarkMatter_MonoZToLL_V_Mx-50_Mv-200_gDMgQ-1
DarkMatter_MonoZToLL_A_Mx-150_Mv-200_gDMgQ-1
DarkMatter_MonoZToLL_V_Mx-150_Mv-200_gDMgQ-1
sm
EOF

for i in `cat list_chan`; do
./computeMuHatHWW.sh histo_limits_zll1hinvllnj_$i 0 obs $CMSSW_BASE/src/cards/cards_inv;
./computeMuHatHWW.sh histo_limits_zll1hinvmmnj_$i 0 obs $CMSSW_BASE/src/cards/cards_inv;
./computeMuHatHWW.sh histo_limits_zll1hinveenj_$i 0 obs $CMSSW_BASE/src/cards/cards_inv;
python $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/mlfitNormsToText.py -u $CMSSW_BASE/src/cards/cards_inv/0/mlfithWWhisto_limits_zll1hinvllnj_$i.root > lll_ll
python $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/mlfitNormsToText.py -u $CMSSW_BASE/src/cards/cards_inv/0/mlfithWWhisto_limits_zll1hinvmmnj_$i.root > lll_mm
python $CMSSW_BASE/src/HiggsAnalysis/CombinedLimit/test/mlfitNormsToText.py -u $CMSSW_BASE/src/cards/cards_inv/0/mlfithWWhisto_limits_zll1hinveenj_$i.root > lll_ee
echo "results: "$i
grep -v ch1 lll_ll|grep ZH|grep -v ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep ZH|grep -v ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_ee|grep ZH|grep -v ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
done

echo 'results: ggZH'
grep -v ch1 lll_ll|grep ZH|grep -e ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep ZH|grep -e ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_ee|grep ZH|grep -e ggZH|awk '{print$3,$5}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
echo 'results: EM'
grep -v ch1 lll_ll|grep EM|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep EM|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,35.3,35.3*$2/$1)}'
grep -v ch1 lll_ee|grep EM|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,19.8,19.8*$2/$1)}'
echo 'results: Zjets'
grep -v ch1 lll_ll|grep Zjets|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep Zjets|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,7.6,7.6*$2/$1)}'
grep -v ch1 lll_ee|grep Zjets|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,5.1,5.1*$2/$1)}'
echo 'results: WZ'
grep -v ch1 lll_ll|grep WZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep WZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,34.0,34.0*$2/$1)}'
grep -v ch1 lll_ee|grep WZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,21.8,21.8*$2/$1)}'
echo 'results: ZZ'
grep -v ch1 lll_ll|grep ZZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep ZZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,80.9,80.9*$2/$1)}'
grep -v ch1 lll_ee|grep ZZ|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,51.9,51.9*$2/$1)}'
echo 'results: VVV'
grep -v ch1 lll_ll|grep VVV|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f\n",$1,$2)}'
grep -v ch1 lll_mm|grep VVV|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,0.23,0.23*$2/$1)}'
grep -v ch1 lll_ee|grep VVV|awk '{print$9,$11}'|awk -f ~/bin/others/sum2.awk|awk '{printf("%f %f %f %f\n",$1,$2,0.45,0.45*$2/$1)}'
