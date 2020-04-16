#!/bin/sh

rm -f higgsCombine* workspace_* impacts* fitDiagnostics* *png;

cd ..;
cd $CMSSW_BASE/src;
eval `scramv1 runtime -sh`;
cd -;

hadd -f ssww_comb_input.root ana_ssww/ssww_201?_input.root;
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeSSWWDataCards.C+'("ssww_comb_input.root")';

hadd -f zhg_comb_125_input.root ana_zhg/zhg_201?_mH125_input.root
hadd -f zhg_comb_200_input.root ana_zhg/zhg_201?_mH200_input.root
hadd -f zhg_comb_300_input.root ana_zhg/zhg_201?_mH300_input.root
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHGDataCards.C+'("zhg_comb_125_input.root")';
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHGDataCards.C+'("zhg_comb_200_input.root")';
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHGDataCards.C+'("zhg_comb_300_input.root")';

hadd -f zh_comb_0j_input.root ana_zh/zh_201?_0j_input.root
hadd -f zh_comb_1j_input.root ana_zh/zh_201?_1j_input.root
hadd -f wz_comb_input.root ana_zh/wz_201?_input.root
hadd -f zz_comb_input.root ana_zh/zz_201?_input.root
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHDataCards.C+'("zh_comb_0j_input.root",0)';
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHDataCards.C+'("zh_comb_1j_input.root",1)';
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHDataCards.C+'("wz_comb_input.root",-1)';
root -l -q -b MitAnalysisRunII/panda/macros/9x/makeZHDataCards.C+'("zz_comb_input.root",-1)';

mv ssww_comb_*input.root zhg_comb_*_input.root ??_comb_*input.root comb/;
mv datacard_*_comb*.txt comb/;
cd comb/;

cd ~/releases/CMSSW_10_2_13/src/;
eval `scramv1 runtime -sh`;
cd -;

combineCards.py -S SSWW_2019=datacard_ssww_comb.txt > ssww_comb.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/qqWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/ggWW:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s2[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wwwz.root;

combineCards.py -S ZHG_2019_125=datacard_zhg_comb_125.txt > zhg_comb_125.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
--PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' \
zhg_comb_125.text -o workspace_zhg_comb_125.root;

combineCards.py -S ZHG_2019_200=datacard_zhg_comb_200.txt > zhg_comb_200.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
--PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' \
zhg_comb_200.text -o workspace_zhg_comb_200.root;

combineCards.py -S ZHG_2019_300=datacard_zhg_comb_300.txt > zhg_comb_300.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
--PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' \
zhg_comb_300.text -o workspace_zhg_comb_300.root;

combineCards.py -S ZH0_2019=datacard_zh_comb_0j.txt ZH1_2019=datacard_zh_comb_1j.txt WZ_2019=datacard_wz_comb.txt ZZ_2019=datacard_zz_comb.txt > zh_comb.text;
text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel \
--PO verbose --PO 'map=.*/BSM:r_s0[1,0,10]' \
zh_comb.text -o workspace_zh_comb.root;

echo "run fits using ~/ana_area/Combination/comb/runFit.sh"
