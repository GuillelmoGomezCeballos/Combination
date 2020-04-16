#!/bin/sh

cd ~/releases/CMSSW_10_2_13/src/;
eval `scramv1 runtime -sh`;
cd -;

echo "*****ZHG*******"
~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_comb_200 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_comb_300 limit obs

echo "*****SSWW*******"
~/ana_area/Combination/comb/runFit.sh . ssww_comb significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb significance obs

echo "*****ZH*******"
~/ana_area/Combination/comb/runFit.sh . zh_comb limit obs

echo "*****IMPACTS*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125  impacts obs >& log_impacts_zhg_125_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125  impacts exp >& log_impacts_zhg_125_exp &

nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_wwwz impacts obs >& log_impacts_ssww_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_wwwz impacts exp >& log_impacts_ssww_exp &

nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb impacts obs >& log_impacts_zh_125_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb impacts exp >& log_impacts_zh_125_exp &

echo "*****MLF*******"
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_wwwz      mlf obs >& log_mlf_ssww_comb_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125        mlf obs >& log_mlf_zhg_comb_125_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_200        mlf obs >& log_mlf_zhg_comb_200_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_300        mlf obs >& log_mlf_zhg_comb_300_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb             mlf obs >& log_mlf_zh_comb_obs &

echo "****DIFFERENTIAL*****"
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_exp --algo=singles --robustFit=1  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_obs --algo=singles --robustFit=1  --redefineSignalPOIs r_s0,r_s1,r_s2
