#!/bin/sh

if [ $# -lt 1 ]; then
   echo "TOO FEW PARAMETERS";
   exit;
fi

cd ~/releases/CMSSW_10_2_13/src/;
eval `scramv1 runtime -sh`;
cd -;

if [ $1 = "darkg" ]; then
echo "*****darkg*******"
#grep -e sample -e r_s0 log_runFits_darkg|awk '{xs=0.1;if($1=="sample:")printf("%19s ",$2);else printf("%11.6f ",$5*xs);if(NR%7==0)printf("\n");}'
for sampleName in 125 200 300; do
  nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . darkg_comb_${sampleName} mlf obs >& log_mlf_darkg_comb_${sampleName}_obs &
  echo "sample: "${sampleName};
  ~/releases/CMSSW_10_2_13/src/runFit.sh . darkg_comb_${sampleName} limit obs
done

elif [ $1 = "vbfg" ]; then
echo "*****vbfg*******"
#grep -e sample -e r_s0 log_runFits_vbfg|awk '{xs=0.1;if($1=="sample:")printf("%19s ",$2);else printf("%11.6f ",$5*xs);if(NR%7==0)printf("\n");}'
for sampleName in 115 125 150 200 300 500 800 1000; do
#for sampleName in 115; do

  if [ ${sampleName} == '115' ]; then
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} mlf obs >& log_mlf_vbfg_${sampleName}_obs &
  fi
  if [ ${sampleName} == '125' ]; then
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} mlf obs >& log_mlf_vbfg_${sampleName}_obs &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2016 mlf obs >& log_mlf_vbfg_${sampleName}_2016_obs &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2017 mlf obs >& log_mlf_vbfg_${sampleName}_2017_obs &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2018 mlf obs >& log_mlf_vbfg_${sampleName}_2018_obs &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} impacts obs >& log_impacts_vbfg_${sampleName}_obs &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} impacts exp >& log_impacts_vbfg_${sampleName}_exp &
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} impacts expnosig >& log_impacts_vbfg_${sampleName}_expnosig &
   fi

  echo "sample: "${sampleName};
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName} limit obs
  echo "sample: "${sampleName}-2016;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2016 limit obs
  echo "sample: "${sampleName}-2017;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2017 limit obs
  echo "sample: "${sampleName}-2017-trigger0;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2017_trigger0 limit obs
  echo "sample: "${sampleName}-2017-trigger1;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2017_trigger1 limit obs
  echo "sample: "${sampleName}-2018;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2018 limit obs
  echo "sample: "${sampleName}-2018-trigger0;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2018_trigger0 limit obs
  echo "sample: "${sampleName}-2018-trigger1;
  ~/releases/CMSSW_10_2_13/src/runFit.sh . vbfg${sampleName}_2018_trigger1 limit obs

done

elif [ $1 = "monoz" ]; then
echo "*****monoz*******"
#grep -e sample -e r_s0 log_runFits_monoz|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%7==0)printf("\n");}'
for sampleName in `cat list_of_samples.txt`; do
   echo "sample: "${sampleName};
   #~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb limit exp
   ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb limit obs
done

#for sampleName in `cat list_of_samples.txt`; do
#   echo "sample: "${sampleName};
#   #~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_2016 limit exp
#   ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_2016 limit obs
#done

elif [ $1 = "aqgc" ]; then
echo "*****aqgc*******"
#grep -e sample -e r_s0 log_runFits_aqgc|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%7==0)printf("\n");}'|awk '{printf("%10s %11.6f 1 %11.6f %11.6f %11.6f %11.6f %11.6f\n",$1,$2,$5,$3,$4,$6,$7)}'
for sampleName in `cat list_of_aqgc_samples.txt`; do
   echo "sample: "${sampleName};
   #~/releases/CMSSW_10_2_13/src/runFit.sh . aqgc_${sampleName}_comb limit exp
   ~/releases/CMSSW_10_2_13/src/runFit.sh . aqgc_${sampleName}_comb limit obs
done

elif [ $1 = "zhstudy" ]; then
export sampleName="ADDMonoZ_MD_3_d_4"
#~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb limit obs

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb impacts obs >& log_impacts_zh${sampleName}_obs_comb &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb impacts exp >& log_impacts_zh${sampleName}_exp_comb &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb impacts expnosig >& log_impacts_zh${sampleName}_expnosig_comb &

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh${sampleName}_comb mlf obs >& log_mlf_zh${sampleName}_comb_obs &

elif [ $1 = "zh" ]; then
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'|awk '{printf("%5.2f %5.2f %5.2f %5.2f\n",$1,$4-$3,$4,$5-$4)}'
echo "*****ZH*******"
#~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2016 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2016 limit obs
#~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2017 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2017 limit obs
#~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2018 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2018 limit obs
#~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb limit obs

echo "*****IMPACTS*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2016      impacts obs >& log_impacts_zh_2016 &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2017      impacts obs >& log_impacts_zh_2017 &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2018      impacts obs >& log_impacts_zh_2018 &

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb      impacts obs >& log_impacts_zh &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb      impacts exp >& log_impacts_zh_exp &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb      impacts expnosig >& log_impacts_zh_expnosig &

echo "*****MLF*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2016      mlf obs >& log_mlf_zh_2016_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2017      mlf obs >& log_mlf_zh_2017_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_2018      mlf obs >& log_mlf_zh_2018_obs &

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb      mlf obs >& log_mlf_zh_comb_obs &

echo "*****GOF*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb       gof obs >& log_gof_zh_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zh_comb       gof exp >& log_gof_zh_exp &

elif [ $1 = "zhg" ]; then
echo "*****ZHG125*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_125 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_125 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_125 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_125 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_125 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_125 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125 limit obs

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125 limitToys obs >& limitToys_zhg_comb_125 &

echo "*****ZHG200*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_200 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_200 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_200 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_200 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_200 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_200 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_200 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_200 limit obs

echo "*****ZHG300*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_300 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2016_300 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_300 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2017_300 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_300 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_2018_300 limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_300 limit exp
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_300 limit obs

echo "*****IMPACTS*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125 impacts obs >& log_impacts_zhg_125 &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125 impacts exp >& log_impacts_zhg_125_exp &

echo "*****MLF*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . zhg_comb_125  mlf obs

elif [ $1 = "ssww" ]; then
echo "*****SSWW*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_fiducial6_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_fiducial6_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_fiducial6_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_fiducial6_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_fiducial6_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_fiducial6_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial6_ww significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial6_ww significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_fiducial6_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_fiducial6_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_fiducial6_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_fiducial6_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_fiducial6_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_fiducial6_wz significance obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial6_wz significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial6_wz significance obs

nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial3all impacts exp >& log_impacts_ssww_exp &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial3all impacts obs >& log_impacts_ssww_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial3all_2poi impacts exp >& log_impacts_ssww_2poi_exp &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial3all_2poi impacts obs >& log_impacts_ssww_2poi_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial8all impacts exp >& log_impacts_ssww_fiducial8_exp &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial8all impacts obs >& log_impacts_ssww_fiducial8_obs &

echo "*****MLF*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_wwwz mlf obs >& log_mlf_2016_wwwz_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_wwwz mlf obs >& log_mlf_2017_wwwz_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_wwwz mlf obs >& log_mlf_2018_wwwz_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_wwwz mlf obs >& log_mlf_comb_wwwz_obs &

echo "*****GOF*******"
#nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_ww_wwwz gof exp >& log_gof_ssww_exp &
#nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_ww_wwwz gof obs >& log_gof_ssww_obs &

echo "****DIFFERENTIAL*****"
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_intf.root -n ssww_comb_intf_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_intf.root -n ssww_comb_intf_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_wwwz_2poi.root -n ssww_comb_wwwz_2poi_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz_2poi.root -n ssww_comb_wwwz_2poi_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5
combine -M MultiDimFit workspace_ssww_comb_fiducial6_wwwz.root -n ssww_comb_fiducial6_wwwz_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial6_wwwz.root -n ssww_comb_fiducial6_wwwz_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,1.5

echo "****fiducial1*****"
combine -M MultiDimFit workspace_ssww_comb_fiducial1all.root -n ssww_comb_fiducial1all_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial1all.root -n ssww_comb_fiducial1all_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1

combine -M MultiDimFit workspace_ssww_comb_fiducial1split.root -n ssww_comb_fiducial1split_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4 --setParameters r_s0=1,r_s1=1,r_s2=1,r_s3=1,r_s4=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial1split.root -n ssww_comb_fiducial1split_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4

combine -M MultiDimFit workspace_ssww_comb_fiducial10.root -n ssww_comb_fiducial10_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1 --setParameters r_s0=1,REWK_1=1,REWK_2=1,REWK_3=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial10.root -n ssww_comb_fiducial10_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1

combine -M MultiDimFit workspace_ssww_comb_fiducial11.root -n ssww_comb_fiducial11_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1 --setParameters r_s0=1,REWK_0=1,REWK_1=1,REWK_2=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial11.root -n ssww_comb_fiducial11_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1

echo "****fiducial2*****"
combine -M MultiDimFit workspace_ssww_comb_fiducial2all.root -n ssww_comb_fiducial2all_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial2all.root -n ssww_comb_fiducial2all_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_fiducial2all_2poi.root -n ssww_comb_fiducial2all_2poi_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial2all_2poi.root -n ssww_comb_fiducial2all_2poi_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1

combine -M MultiDimFit workspace_ssww_comb_fiducial2split.root -n ssww_comb_fiducial2split_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4 --setParameters r_s0=1,r_s1=1,r_s2=1,r_s3=1,r_s4=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial2split.root -n ssww_comb_fiducial2split_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4

combine -M MultiDimFit workspace_ssww_comb_fiducial20.root -n ssww_comb_fiducial20_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2 --setParameters r_s0=1,REWK_1=1,REWK_2=1,REWK_3=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial20.root -n ssww_comb_fiducial20_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2

combine -M MultiDimFit workspace_ssww_comb_fiducial21.root -n ssww_comb_fiducial21_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2 --setParameters r_s0=1,REWK_0=1,REWK_1=1,REWK_2=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial21.root -n ssww_comb_fiducial21_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2

echo "****fiducial3*****"
combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1

combine -M MultiDimFit workspace_ssww_comb_fiducial3split.root -n ssww_comb_fiducial3split_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4 --setParameters r_s0=1,r_s1=1,r_s2=1,r_s3=1,r_s4=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial3split.root -n ssww_comb_fiducial3split_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4

combine -M MultiDimFit workspace_ssww_comb_fiducial30.root -n ssww_comb_fiducial30_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2 --setParameters r_s0=1,REWK_1=1,REWK_2=1,REWK_3=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial30.root -n ssww_comb_fiducial30_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2

combine -M MultiDimFit workspace_ssww_comb_fiducial31.root -n ssww_comb_fiducial31_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2 --setParameters r_s0=1,REWK_0=1,REWK_1=1,REWK_2=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial31.root -n ssww_comb_fiducial31_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2

#limit->Scan("r_s2:abs(r_s2-1.0062296)","deltaNLL==0||abs(2*deltaNLL-1)<0.008")
nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_r_s0_fast_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_fiducial3all_r_s0_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_r_s1_fast_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_fiducial3all_r_s1_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_r_s2_fast_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s2 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_fiducial3all_r_s2_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_fast_r_s0_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_fiducial3all_2poi_fast_r_s0_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_fast_r_s1_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_fiducial3all_2poi_fast_r_s1_obs &


nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_fast_exp \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 --fastScan \
--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_comb_wwwz_grid_fast_exp &
nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_fast_obs \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 --fastScan >& log_ssww_comb_wwwz_grid_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_exp \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 \
--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_comb_wwwz_grid_exp &
nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_obs \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 >& log_ssww_comb_wwwz_grid_obs &

#limit->Draw("2*deltaNLL:r_s1:r_s2>>h(50,0.0,2.5,50,0.0,2.5)","2*deltaNLL<25","prof colz")
#limit->Draw("r_s1:r_s2","quantileExpected == -1","P same")
#TGraph *best_fit = (TGraph*)gROOT->FindObject("Graph")
#best_fit->SetMarkerSize(3); best_fit->SetMarkerStyle(34); best_fit->Draw("p same")

nohup combine -M MultiDimFit workspace_ssww_comb_wz.root -n ssww_comb_wz_grid_rs0_exp \
--algo grid --points 500 --setParameterRanges r_s0=0.0,2.5  \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
--setParameters r_s0=1 -t -1 >& log_ssww_comb_wz_grid_rs0_exp &
nohup combine -M MultiDimFit workspace_ssww_comb_wz.root -n ssww_comb_wz_grid_rs0_obs \
--algo grid --points 500 --setParameterRanges r_s0=0.0,2.5  \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 >& log_ssww_comb_wz_grid_rs0_obs &
##limit->Draw("2*deltaNLL:r_s0>>h(500,0.0,2.5)","2*deltaNLL<25","prof colz")
##python ~/releases/CMSSW_10_2_13/src/CombineHarvester/CombineTools/scripts/plot1DScan.py higgsCombinessww_comb_wz_grid_rs0_exp.MultiDimFit.mH120.root --POI r_s0

nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_rs1_exp \
--algo grid --points 500 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 \
--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_comb_wwwz_grid_rs1_exp &
nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_rs1_obs \
--algo grid --points 500 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 >& log_ssww_comb_wwwz_grid_rs1_obs &
##limit->Draw("2*deltaNLL:r_s1>>h(500,0.0,2.5)","2*deltaNLL<25","prof colz")
##python ~/releases/CMSSW_10_2_13/src/CombineHarvester/CombineTools/scripts/plot1DScan.py higgsCombinessww_comb_wwwz_grid_rs1_exp.MultiDimFit.mH120.root --POI r_s1

echo "****fiducial7*****"
combine -M MultiDimFit workspace_ssww_comb_fiducial7all.root -n ssww_comb_fiducial7all_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial7all.root -n ssww_comb_fiducial7all_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_fiducial7all_2poi.root -n ssww_comb_fiducial7all_2poi_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial7all_2poi.root -n ssww_comb_fiducial7all_2poi_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1

combine -M MultiDimFit workspace_ssww_comb_fiducial7split.root -n ssww_comb_fiducial7split_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4 --setParameters r_s0=1,r_s1=1,r_s2=1,r_s3=1,r_s4=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial7split.root -n ssww_comb_fiducial7split_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2,r_s3,r_s4

combine -M MultiDimFit workspace_ssww_comb_fiducial70.root -n ssww_comb_fiducial70_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2 --setParameters r_s0=1,REWK_1=1,REWK_2=1,REWK_3=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial70.root -n ssww_comb_fiducial70_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_1,REWK_2,REWK_3,r_s1,r_s2

combine -M MultiDimFit workspace_ssww_comb_fiducial71.root -n ssww_comb_fiducial71_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2 --setParameters r_s0=1,REWK_0=1,REWK_1=1,REWK_2=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial71.root -n ssww_comb_fiducial71_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK_0,REWK_1,REWK_2,r_s1,r_s2

echo "****fiducial8*****"
combine -M MultiDimFit workspace_ssww_comb_fiducial8all.root -n ssww_comb_fiducial8all_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_fiducial8all.root -n ssww_comb_fiducial8all_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2

elif [ $1 = "long" ]; then
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5 impacts exp >& log_impacts_ssww_fiducial5_exp &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5 impacts obs >& log_impacts_ssww_fiducial5_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2016_fiducial5 mlf obs >& log_mlf_2016_fiducial5_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2017_fiducial5 mlf obs >& log_mlf_2017_fiducial5_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2018_fiducial5 mlf obs >& log_mlf_2018_fiducial5_obs &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5 mlf obs >& log_mlf_2019_fiducial5_obs &

~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5_rs0only limit obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5_rs0only significance exp
~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_2019_fiducial5_rs0only significance obs

combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_rs0only_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --rMin -3 \
--setParameters r_s0=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_rs0only_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --rMin -3

combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --rMin -3 \
--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --rMin -3

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_exp \
#--algo grid --points 5000 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5:r_s2=0.5,2.0  \
#--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 -P r_s1 --floatOtherPOIs=1 \
#--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_2019_fiducial5_grid_exp &
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_obs \
#--algo grid --points 5000 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5:r_s2=0.5,2.0  \
#--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 -P r_s1 --floatOtherPOIs=1 >& log_ssww_2019_fiducial5_grid_obs &

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_rs0_exp \
#--algo grid --points 500 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
#--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 \
#--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_2019_fiducial5_grid_rs0_exp &
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_rs0_obs \
#--algo grid --points 500 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5:r_s2=0.0,2.5 \
#--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 >& log_ssww_2019_fiducial5_grid_rs0_obs &

  if [ $# == 2 ] && [ $2 == 'comb' ]; then

    ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial5_rs0only limit obs
    ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial5_rs0only significance exp
    ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial5_rs0only significance obs
    nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ssww_comb_fiducial5 mlf obs >& log_mlf_ssww_comb_fiducial5_obs &
    combine -M MultiDimFit workspace_ssww_comb_fiducial5.root -n ssww_comb_fiducial5_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --rMin -3 \
    --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial5.root -n ssww_comb_fiducial5_obs \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --rMin -3
    
  fi

elif [ $1 = "ww" ]; then
echo "*****WW*******"
echo "*****IMPACTS*******"
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2016   impacts obs >& log_impacts_ww_2016 &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2017   impacts obs >& log_impacts_ww_2017 &
nohup ~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2018   impacts obs >& log_impacts_ww_2018 &

echo "*****MLF*******"
~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2016   mlf obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2017   mlf obs
~/releases/CMSSW_10_2_13/src/runFit.sh . ww_2018   mlf obs

fi