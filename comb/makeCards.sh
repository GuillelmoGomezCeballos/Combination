#!/bin/sh

cd ~/releases/CMSSW_10_2_13/src/;
eval `scramv1 runtime -sh`;
cd -;

if [ $1 = "darkg" ]; then

for sampleName in 125 200 300; do

combineCards.py -S \
../ana_zhg/zhg_comb_${sampleName}.text \
../done_vbfg/vbfg${sampleName}.text \
> darkg_comb_${sampleName}.text
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' darkg_comb_${sampleName}.text -o workspace_darkg_comb_${sampleName}.root;

done

elif [ $1 = "vbfg" ]; then

for sampleName in 115 125 150 200 300 500 800 1000; do
#for sampleName in 115; do
   echo "sample: "${sampleName};
  combineCards.py -S \
  VBFG_2016_trigger0=datacard_vbfg_2016_trigger0_mH${sampleName}.txt \
  VBFG_2017_trigger0=datacard_vbfg_2017_trigger0_mH${sampleName}.txt \
  VBFG_2017_trigger1=datacard_vbfg_2017_trigger1_mH${sampleName}.txt \
  VBFG_2018_trigger0=datacard_vbfg_2018_trigger0_mH${sampleName}.txt \
  VBFG_2018_trigger1=datacard_vbfg_2018_trigger1_mH${sampleName}.txt \
  > vbfg${sampleName}.text

  combineCards.py -S \
  VBFG_2016_trigger0=datacard_vbfg_2016_trigger0_mH${sampleName}.txt \
  > vbfg${sampleName}_2016.text

  combineCards.py -S \
  VBFG_2017_trigger0=datacard_vbfg_2017_trigger0_mH${sampleName}.txt \
  VBFG_2017_trigger1=datacard_vbfg_2017_trigger1_mH${sampleName}.txt \
  > vbfg${sampleName}_2017.text

  combineCards.py -S \
  VBFG_2017_trigger0=datacard_vbfg_2017_trigger0_mH${sampleName}.txt \
  > vbfg${sampleName}_2017_trigger0.text

  combineCards.py -S \
  VBFG_2017_trigger1=datacard_vbfg_2017_trigger1_mH${sampleName}.txt \
  > vbfg${sampleName}_2017_trigger1.text

  combineCards.py -S \
  VBFG_2018_trigger0=datacard_vbfg_2018_trigger0_mH${sampleName}.txt \
  VBFG_2018_trigger1=datacard_vbfg_2018_trigger1_mH${sampleName}.txt \
  > vbfg${sampleName}_2018.text

  combineCards.py -S \
  VBFG_2018_trigger0=datacard_vbfg_2018_trigger0_mH${sampleName}.txt \
  > vbfg${sampleName}_2018_trigger0.text

  combineCards.py -S \
  VBFG_2018_trigger1=datacard_vbfg_2018_trigger1_mH${sampleName}.txt \
  > vbfg${sampleName}_2018_trigger1.text

  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}.text -o workspace_vbfg${sampleName}.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2016.text -o workspace_vbfg${sampleName}_2016.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2017.text -o workspace_vbfg${sampleName}_2017.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2017_trigger0.text -o workspace_vbfg${sampleName}_2017_trigger0.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2017_trigger1.text -o workspace_vbfg${sampleName}_2017_trigger1.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2018.text -o workspace_vbfg${sampleName}_2018.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2018_trigger0.text -o workspace_vbfg${sampleName}_2018_trigger0.root;
  text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
                    --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' vbfg${sampleName}_2018_trigger1.text -o workspace_vbfg${sampleName}_2018_trigger1.root;
done

elif [ $1 = "aqgc" ]; then

for sampleName in `cat list_of_aqgc_samples.txt`; do
   echo "sample: "${sampleName};
   ls datacard_ssww_aqgc_${sampleName}_201?_fiducial4_input.txt
   combineCards.py -S datacard_ssww_aqgc_${sampleName}_201?_fiducial4_input.txt > aqgc_${sampleName}_comb.text;
   text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
  --PO 'map=.*/EWKSSWW_dim8:r_s0[1,0,10]' --PO 'map=.*/EWKWZ_dim8:r_s0[1,0,10]' aqgc_${sampleName}_comb.text -o workspace_aqgc_${sampleName}_comb.root;
done

elif [ $1 = "monoz" ]; then

for sampleName in `cat list_of_samples.txt`; do
   echo "sample: "${sampleName};

   ls datacard_zh${sampleName}_201?_[0,1]j.txt datacard_wz_201?.txt datacard_zz_201?.txt;
   combineCards.py -S datacard_zh${sampleName}_201?_?j.txt datacard_wz_201?.txt datacard_zz_201?.txt > zh${sampleName}_comb.text;
   text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
   --PO 'map=.*/BSM:r_s0[1,0,10]' zh${sampleName}_comb.text -o workspace_zh${sampleName}_comb.root;

done

elif [ $1 = "zh" ]; then

export sampleName=""
combineCards.py -S \
ZH0_2016=datacard_zh${sampleName}_2016_0j.txt \
ZH1_2016=datacard_zh${sampleName}_2016_1j.txt \
WZ_2016=datacard_wz_2016.txt \
ZZ_2016=datacard_zz_2016.txt > zh${sampleName}_2016.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zh${sampleName}_2016.text -o workspace_zh${sampleName}_2016.root;

combineCards.py -S \
ZH0_2017=datacard_zh${sampleName}_2017_0j.txt \
ZH1_2017=datacard_zh${sampleName}_2017_1j.txt \
WZ_2017=datacard_wz_2017.txt \
ZZ_2017=datacard_zz_2017.txt > zh${sampleName}_2017.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zh${sampleName}_2017.text -o workspace_zh${sampleName}_2017.root;

combineCards.py -S \
ZH0_2018=datacard_zh${sampleName}_2018_0j.txt \
ZH1_2018=datacard_zh${sampleName}_2018_1j.txt \
WZ_2018=datacard_wz_2018.txt \
ZZ_2018=datacard_zz_2018.txt > zh${sampleName}_2018.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zh${sampleName}_2018.text -o workspace_zh${sampleName}_2018.root;

combineCards.py -S \
ZH0_2016=datacard_zh${sampleName}_2016_0j.txt \
ZH1_2016=datacard_zh${sampleName}_2016_1j.txt \
WZ_2016=datacard_wz_2016.txt \
ZZ_2016=datacard_zz_2016.txt \
ZH0_2017=datacard_zh${sampleName}_2017_0j.txt \
ZH1_2017=datacard_zh${sampleName}_2017_1j.txt \
WZ_2017=datacard_wz_2017.txt \
ZZ_2017=datacard_zz_2017.txt \
ZH0_2018=datacard_zh${sampleName}_2018_0j.txt \
ZH1_2018=datacard_zh${sampleName}_2018_1j.txt \
WZ_2018=datacard_wz_2018.txt \
ZZ_2018=datacard_zz_2018.txt > zh${sampleName}_comb.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zh${sampleName}_comb.text -o workspace_zh${sampleName}_comb.root;

elif [ $1 = "zhg" ]; then

# 125
combineCards.py -S datacard_zhg_mH125_2016.txt > zhg_2016_125.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2016_125.text -o workspace_zhg_2016_125.root;

combineCards.py -S datacard_zhg_mH125_2017.txt > zhg_2017_125.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2017_125.text -o workspace_zhg_2017_125.root;

combineCards.py -S datacard_zhg_mH125_2018.txt > zhg_2018_125.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2018_125.text -o workspace_zhg_2018_125.root;

combineCards.py -S \
ZHG_2016_125=zhg_2016_125.text \
ZHG_2017_125=zhg_2017_125.text \
ZHG_2018_125=zhg_2018_125.text > zhg_comb_125.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_comb_125.text -o workspace_zhg_comb_125.root;

# 200
combineCards.py -S datacard_zhg_mH200_2016.txt > zhg_2016_200.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2016_200.text -o workspace_zhg_2016_200.root;

combineCards.py -S datacard_zhg_mH200_2017.txt > zhg_2017_200.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2017_200.text -o workspace_zhg_2017_200.root;

combineCards.py -S datacard_zhg_mH200_2018.txt > zhg_2018_200.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2018_200.text -o workspace_zhg_2018_200.root;

combineCards.py -S \
ZHG_2016_200=zhg_2016_200.text \
ZHG_2017_200=zhg_2017_200.text \
ZHG_2018_200=zhg_2018_200.text > zhg_comb_200.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_comb_200.text -o workspace_zhg_comb_200.root;

# 300
combineCards.py -S datacard_zhg_mH300_2016.txt > zhg_2016_300.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2016_300.text -o workspace_zhg_2016_300.root;

combineCards.py -S datacard_zhg_mH300_2017.txt > zhg_2017_300.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2017_300.text -o workspace_zhg_2017_300.root;

combineCards.py -S datacard_zhg_mH300_2018.txt > zhg_2018_300.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_2018_300.text -o workspace_zhg_2018_300.root;

combineCards.py -S \
ZHG_2016_300=zhg_2016_300.text \
ZHG_2017_300=zhg_2017_300.text \
ZHG_2018_300=zhg_2018_300.text > zhg_comb_300.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' zhg_comb_300.text -o workspace_zhg_comb_300.root;

elif [ $1 = "ssww" ]; then

combineCards.py -S ch1=datacard_ssww_2016.txt > ssww_2016.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2016.text -o workspace_ssww_2016_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2016.text -o workspace_ssww_2016_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_2016.text -o workspace_ssww_2016_wwwz.root;

combineCards.py -S ch1=datacard_ssww_2017.txt > ssww_2017.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2017.text -o workspace_ssww_2017_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2017.text -o workspace_ssww_2017_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_2017.text -o workspace_ssww_2017_wwwz.root;

combineCards.py -S ch1=datacard_ssww_2018.txt > ssww_2018.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2018.text -o workspace_ssww_2018_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2018.text -o workspace_ssww_2018_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_2018.text -o workspace_ssww_2018_wwwz.root;

combineCards.py -S \
SSWW_2016=ssww_2016.text \
SSWW_2017=ssww_2017.text \
SSWW_2018=ssww_2018.text > ssww_comb.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wwwz.root;

cp ssww_comb.text ssww_comb_intf.txt;
echo "IntfWW rateParam * qqWW sqrt(@0) r_s0" >> ssww_comb_intf.txt;
echo "IntfWZ rateParam * ggWW sqrt(@0*@1) r_s1,r_s2" >> ssww_comb_intf.txt;
combineCards.py -S ssww_comb_intf.txt > ssww_comb_intf.text;
rm -f ssww_comb_intf.txt;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_intf.text -o workspace_ssww_comb_intf.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s1[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wwwz_2poi.root;

# fiducial1
combineCards.py -S datacard_ssww_201?_fiducial1.txt > ssww_comb_fiducial1.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s1[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s1[1,0,10]' \
--PO 'map=.*/Signal3:r_s1[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
ssww_comb_fiducial1.text -o workspace_ssww_comb_fiducial1all.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s1[1,0,10]' \
--PO 'map=.*/Signal1:r_s2[1,0,10]' \
--PO 'map=.*/Signal2:r_s3[1,0,10]' \
--PO 'map=.*/Signal3:r_s4[1,0,10]' \
ssww_comb_fiducial1.text -o workspace_ssww_comb_fiducial1split.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(0,1,"WZ")';
cat ssww_comb_fiducial1.text datacard_add.txt > ssww_comb_fiducial10.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s1[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s1[1,0,10]' \
--PO 'map=.*/Signal3:r_s1[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
ssww_comb_fiducial10.text -o workspace_ssww_comb_fiducial10.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(3,1,"WZ")';
cat ssww_comb_fiducial1.text datacard_add.txt > ssww_comb_fiducial11.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s1[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s1[1,0,10]' \
--PO 'map=.*/Signal3:r_s1[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
ssww_comb_fiducial11.text -o workspace_ssww_comb_fiducial11.root;

# fiducial2
combineCards.py -S datacard_ssww_201?_fiducial2.txt > ssww_comb_fiducial2.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial2.text -o workspace_ssww_comb_fiducial2all.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s2[1,0,10]' \
--PO 'map=.*/Signal3:r_s3[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s4[1,0,10]' \
--PO 'map=.*/WZ:r_s4[1,0,10]' \
ssww_comb_fiducial2.text -o workspace_ssww_comb_fiducial2split.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s1[1,0,10]' \
ssww_comb_fiducial2.text -o workspace_ssww_comb_fiducial2all_2poi.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(0,2)';
cat ssww_comb_fiducial2.text datacard_add.txt > ssww_comb_fiducial20.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial20.text -o workspace_ssww_comb_fiducial20.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(3,2)';
cat ssww_comb_fiducial2.text datacard_add.txt > ssww_comb_fiducial21.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial21.text -o workspace_ssww_comb_fiducial21.root;

# fiducial3
combineCards.py -S datacard_ssww_201?_fiducial3.txt > ssww_comb_fiducial3.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial3.text -o workspace_ssww_comb_fiducial3all.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s2[1,0,10]' \
--PO 'map=.*/Signal3:r_s3[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s4[1,0,10]' \
--PO 'map=.*/WZ:r_s4[1,0,10]' \
ssww_comb_fiducial3.text -o workspace_ssww_comb_fiducial3split.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s1[1,0,10]' \
ssww_comb_fiducial3.text -o workspace_ssww_comb_fiducial3all_2poi.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(0,3)';
cat ssww_comb_fiducial3.text datacard_add.txt > ssww_comb_fiducial30.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial30.text -o workspace_ssww_comb_fiducial30.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(3,3)';
cat ssww_comb_fiducial3.text datacard_add.txt > ssww_comb_fiducial31.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial31.text -o workspace_ssww_comb_fiducial31.root;

# fiducial6
combineCards.py -S datacard_ssww_201?_fiducial6.txt > ssww_comb_fiducial6.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_comb_fiducial6.text -o workspace_ssww_comb_fiducial6_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_comb_fiducial6.text -o workspace_ssww_comb_fiducial6_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial6.text -o workspace_ssww_comb_fiducial6_wwwz.root;

combineCards.py -S datacard_ssww_2016_fiducial6.txt > ssww_2016_fiducial6.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2016_fiducial6.text -o workspace_ssww_2016_fiducial6_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2016_fiducial6.text -o workspace_ssww_2016_fiducial6_wz.root;

combineCards.py -S datacard_ssww_2017_fiducial6.txt > ssww_2017_fiducial6.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2017_fiducial6.text -o workspace_ssww_2017_fiducial6_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2017_fiducial6.text -o workspace_ssww_2017_fiducial6_wz.root;

combineCards.py -S datacard_ssww_2018_fiducial6.txt > ssww_2018_fiducial6.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_2018_fiducial6.text -o workspace_ssww_2018_fiducial6_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ssww_2018_fiducial6.text -o workspace_ssww_2018_fiducial6_wz.root;

# fiducial7
combineCards.py -S datacard_ssww_201?_fiducial7.txt > ssww_comb_fiducial7.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial7.text -o workspace_ssww_comb_fiducial7all.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
--PO 'map=.*/Signal2:r_s2[1,0,10]' \
--PO 'map=.*/Signal3:r_s3[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s4[1,0,10]' \
--PO 'map=.*/WZ:r_s4[1,0,10]' \
ssww_comb_fiducial7.text -o workspace_ssww_comb_fiducial7split.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s1[1,0,10]' \
ssww_comb_fiducial7.text -o workspace_ssww_comb_fiducial7all_2poi.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(0,7)';
cat ssww_comb_fiducial7.text datacard_add.txt > ssww_comb_fiducial70.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial70.text -o workspace_ssww_comb_fiducial70.root;

root -l -q -b ../Combination/comb/makeSSWWParam.C'(3,7)';
cat ssww_comb_fiducial7.text datacard_add.txt > ssww_comb_fiducial71.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/Signal0:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial71.text -o workspace_ssww_comb_fiducial71.root;

# fiducial8
combineCards.py -S datacard_ssww_201?_fiducial8.txt > ssww_comb_fiducial8.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb_fiducial8.text -o workspace_ssww_comb_fiducial8all.root;

rm -f datacard_add.txt;

elif [ $1 = "long" ]; then
combineCards.py -S  datacard_ssww_2016_fiducial5.txt > ssww_2016_fiducial5.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
ssww_2016_fiducial5.text -o workspace_ssww_2016_fiducial5.root;

combineCards.py -S  datacard_ssww_2017_fiducial5.txt > ssww_2017_fiducial5.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
ssww_2017_fiducial5.text -o workspace_ssww_2017_fiducial5.root;

combineCards.py -S  datacard_ssww_2018_fiducial5.txt > ssww_2018_fiducial5.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
ssww_2018_fiducial5.text -o workspace_ssww_2018_fiducial5.root;

combineCards.py -S \
SSWW_2016=datacard_ssww_2016_fiducial5.txt \
SSWW_2017=datacard_ssww_2017_fiducial5.txt \
SSWW_2018=datacard_ssww_2018_fiducial5.txt \
> ssww_2019_fiducial5.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s1[1,0,10]' \
ssww_2019_fiducial5.text -o workspace_ssww_2019_fiducial5.root;

root -l -q -b ../Combination/comb/makeSSWWLLParam.C'(0,5)'
cat ssww_2019_fiducial5.text datacard_add.txt > ssww_2019_fiducial50.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
ssww_2019_fiducial50.text -o workspace_ssww_2019_fiducial50.root;

root -l -q -b ../Combination/comb/makeSSWWLLParam.C'(1,5)'
cat ssww_2019_fiducial5.text datacard_add.txt > ssww_2019_fiducial51.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
--PO 'map=.*/Signal1:r_s0[1,0,10]' \
ssww_2019_fiducial51.text -o workspace_ssww_2019_fiducial51.root;

echo "CMS_ssww_wwtxnorm  rateParam SSWW_2016 Signal1 1 [0.1,3]" >> ssww_2019_fiducial5.text
echo "CMS_ssww_wwtxnorm  rateParam SSWW_2017 Signal1 1 [0.1,3]" >> ssww_2019_fiducial5.text
echo "CMS_ssww_wwtxnorm  rateParam SSWW_2018 Signal1 1 [0.1,3]" >> ssww_2019_fiducial5.text

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/BSM:r_s0[1,0,10]' \
ssww_2019_fiducial5.text -o workspace_ssww_2019_fiducial5_rs0only.root;

combineCards.py -S \
SSWW_2016=datacard_ssww_2016_fiducial9.txt \
SSWW_2017=datacard_ssww_2017_fiducial9.txt \
SSWW_2018=datacard_ssww_2018_fiducial9.txt \
> ssww_2019_fiducial9.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s1[1,0,10]' \
ssww_2019_fiducial9.text -o workspace_ssww_2019_fiducial9.root;

root -l -q -b ../Combination/comb/makeSSWWLLParam.C'(0,9)'
cat ssww_2019_fiducial9.text datacard_add.txt > ssww_2019_fiducial90.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
ssww_2019_fiducial90.text -o workspace_ssww_2019_fiducial90.root;

root -l -q -b ../Combination/comb/makeSSWWLLParam.C'(1,9)'
cat ssww_2019_fiducial9.text datacard_add.txt > ssww_2019_fiducial91.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal2:r_s0[1,0,10]' \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
ssww_2019_fiducial91.text -o workspace_ssww_2019_fiducial91.root;

echo "CMS_ssww_wwttnorm  rateParam SSWW_2016 Signal2 1 [0.1,3]" >> ssww_2019_fiducial9.text
echo "CMS_ssww_wwttnorm  rateParam SSWW_2017 Signal2 1 [0.1,3]" >> ssww_2019_fiducial9.text
echo "CMS_ssww_wwttnorm  rateParam SSWW_2018 Signal2 1 [0.1,3]" >> ssww_2019_fiducial9.text

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/Signal3:r_s0[1,0,10]' \
ssww_2019_fiducial9.text -o workspace_ssww_2019_fiducial9_rs0only.root;

  if [ $# == 2 ] && [ $2 == 'comb' ]; then
    cd ..;
    cd $CMSSW_BASE/src;
    eval `scramv1 runtime -sh`;
    cd -;

    hadd -f ssww_comb_fiducial5_input.root ana_long/ssww_201?_fiducial5_input.root;
    root -l -q -b MitAnalysisRunII/panda/macros/9x/makeSSWWDataCards.C+'("ssww_comb_fiducial5_input.root",5)';

    mv ssww_comb_fiducial5_input.root ana_long/;
    mv datacard_ssww_comb_fiducial5.txt ana_long/;

    hadd -f ssww_comb_fiducial9_input.root ana_long/ssww_201?_fiducial9_input.root;
    root -l -q -b MitAnalysisRunII/panda/macros/9x/makeSSWWDataCards.C+'("ssww_comb_fiducial9_input.root",9)';

    mv ssww_comb_fiducial9_input.root ana_long/;
    mv datacard_ssww_comb_fiducial9.txt ana_long/;

    cd ana_long/;
    cd ~/releases/CMSSW_10_2_13/src/;
    eval `scramv1 runtime -sh`;
    cd -;
  
    combineCards.py -S SSWW_2019=datacard_ssww_comb_fiducial5.txt > ssww_comb_fiducial5.text;
    echo "CMS_ssww_wznorm  rateParam SSWW_2019 WZ 1 [0.1,3]" >> ssww_comb_fiducial5.text

    text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=.*/BSM:r_s0[1,0,10]' \
    --PO 'map=.*/Signal1:r_s1[1,0,10]' \
    ssww_comb_fiducial5.text -o workspace_ssww_comb_fiducial5.root;

    echo "CMS_ssww_wwttnorm  rateParam SSWW_2019 Signal1 1 [0.1,3]" >> ssww_comb_fiducial5.text

    text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=.*/BSM:r_s0[1,0,10]' \
    ssww_comb_fiducial5.text -o workspace_ssww_comb_fiducial5_rs0only.root;

    combineCards.py -S SSWW_2019=datacard_ssww_comb_fiducial9.txt > ssww_comb_fiducial9.text;
    echo "CMS_ssww_wznorm  rateParam SSWW_2019 WZ 1 [0.1,3]" >> ssww_comb_fiducial9.text

    text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
    --PO 'map=.*/Signal2:r_s0[1,0,10]' \
    --PO 'map=.*/Signal3:r_s1[1,0,10]' \
    ssww_comb_fiducial9.text -o workspace_ssww_comb_fiducial9.root;

  fi


elif [ $1 = "ww" ]; then

combineCards.py -S datacard_ww_2016.txt > ww_2016.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ww_2016.text -o workspace_ww_2016.root;

combineCards.py -S datacard_ww_2017.txt > ww_2017.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ww_2017.text -o workspace_ww_2017.root;

combineCards.py -S datacard_ww_2018.txt > ww_2018.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/ggWW:r_s0[1,0,10]' \
ww_2018.text -o workspace_ww_2018.root;

fi

echo "run fits using ~/ana_area/Combination/comb/runFit.sh"
