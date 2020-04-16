#!/bin/sh

if [ $# -lt 1 ]; then
   echo "TOO FEW PARAMETERS";
   exit;
fi

cd ~/releases/CMSSW_10_2_13/src/;
eval `scramv1 runtime -sh`;
cd -;

export TOYS=100;
export SEED=13579;

if [ $1 = "make" ]; then
combineCards.py -S \
SSWW_WW_2016=datacard_ssww_ww_2016.txt \
SSWW_WW_2017=datacard_ssww_ww_2017.txt \
SSWW_WW_2018=datacard_ssww_ww_2018.txt \
SSWW_WZ_2016=datacard_ssww_wz_2016.txt \
SSWW_WZ_2017=datacard_ssww_wz_2017.txt \
SSWW_WZ_2018=datacard_ssww_wz_2018.txt > ssww_comb.text;

grep -v autoMCStats ssww_comb.text > test.text;
mv test.text ssww_comb.text;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --channel-masks \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_ww.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --channel-masks \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose  --channel-masks \
--PO 'map=.*/EWKSSWW:r_s0[1,0,10]' \
--PO 'map=.*/EWKWZ:r_s1[1,0,10]' \
--PO 'map=.*/WZ:r_s1[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wwwz.root;

text2workspace.py -P HiggsAnalysis.CombinedLimit.PhysicsModel:multiSignalModel --PO verbose --channel-masks \
--PO 'map=.*/EWKWZ:r_s0[1,0,10]' \
--PO 'map=.*/WZ:r_s0[1,0,10]' \
ssww_comb.text -o workspace_ssww_comb_wzonly.root;

elif [ $1 = "run" ]; then

~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance obs
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1
combine -M MultiDimFit workspace_ssww_comb_wzonly.root -n ssww_comb_wzonly_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --setParameters r_s0=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wzonly.root -n ssww_comb_wzonly_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0

elif [ $1 = "toygen" ]; then

combine -M GenerateOnly workspace_ssww_comb_wzonly.root -n ssww_comb_wzonly_genonly --redefineSignalPOIs r_s0 --setParameters r_s0=1 -t ${TOYS} --toysFrequentist --saveToys --seed ${SEED}

elif [ $1 = "toy0" ]; then

combine -M MultiDimFit workspace_ssww_comb_wzonly.root -n ssww_comb_wzonly_${SEED}_toy0 --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP --setParameterRanges r_s0=0.6,1.4  --redefineSignalPOIs r_s0 -t ${TOYS} --setParameters mask_SSWW_WW_2016=0,mask_SSWW_WW_2017=0,mask_SSWW_WW_2018=0 --toysFile higgsCombinessww_comb_wzonly_genonly.GenerateOnly.mH120.${SEED}.root

elif [ $1 = "toy1" ]; then

combine -M MultiDimFit workspace_ssww_comb_wzonly.root -n ssww_comb_wzonly_${SEED}_toy1 --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP --setParameterRanges r_s0=0.6,1.4  --redefineSignalPOIs r_s0 -t ${TOYS} --setParameters mask_SSWW_WW_2016=1,mask_SSWW_WW_2017=1,mask_SSWW_WW_2018=1 --toysFile higgsCombinessww_comb_wzonly_genonly.GenerateOnly.mH120.${SEED}.root

fi
