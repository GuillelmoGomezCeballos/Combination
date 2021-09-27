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
for sampleName in 125; do
  nohup ~/ana_area/Combination/comb/runFit.sh . darkg_comb_${sampleName} mlf obs >& log_mlf_darkg_comb_${sampleName}_obs &
  echo "sample: "${sampleName};
  ~/ana_area/Combination/comb/runFit.sh . darkg_comb_${sampleName} limit obs
done

elif [ $1 = "vbfg" ]; then
echo "*****vbfg*******"
#grep -e sample -e r_s0 log_runFits_vbfg|awk '{xs=0.05;if($1=="sample:")printf("%19s ",$2);else printf("%11.6f ",$5*xs);if(NR%7==0)printf("\n");}'
for sampleName in 115 120 125 150 200 300 500 800 1000; do
#for sampleName in 120; do

  if [ ${sampleName} == '115' ]; then
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} mlf obs >& log_mlf_vbfg_${sampleName}_obs &
  fi
  if [ ${sampleName} == '120' ]; then
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} mlf obs >& log_mlf_vbfg_${sampleName}_obs &
   fi
  if [ ${sampleName} == '125' ]; then
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} mlf obs >& log_mlf_vbfg_${sampleName}_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2016 mlf obs >& log_mlf_vbfg_${sampleName}_2016_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2017 mlf obs >& log_mlf_vbfg_${sampleName}_2017_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2018 mlf obs >& log_mlf_vbfg_${sampleName}_2018_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts obs >& log_impacts_vbfg_${sampleName}_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts exp >& log_impacts_vbfg_${sampleName}_exp &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts expnosig >& log_impacts_vbfg_${sampleName}_expnosig &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} gof obs      >& log_gof_vbfg_${sampleName}_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} gof expnosig >& log_gof_vbfg_${sampleName}_expnosig &
   fi
   if [ ${sampleName} == '500' ]; then
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts obs >& log_impacts_vbfg_${sampleName}_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts exp >& log_impacts_vbfg_${sampleName}_exp &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts expnosig >& log_impacts_vbfg_${sampleName}_expnosig &
   fi
   if [ ${sampleName} == '1000' ]; then
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts obs >& log_impacts_vbfg_${sampleName}_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts exp >& log_impacts_vbfg_${sampleName}_exp &
    nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} impacts expnosig >& log_impacts_vbfg_${sampleName}_expnosig &
   fi

   #nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} grid obs >& log_grid_vbfg_${sampleName}_obs &
   #nohup ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} grid expnosig >& log_grid_vbfg_${sampleName}_expnosig &

  echo "sample: "${sampleName};
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName} limit obs
  echo "sample: "${sampleName}-2016;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2016 limit obs
  echo "sample: "${sampleName}-2017;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2017 limit obs
  echo "sample: "${sampleName}-2017-trigger0;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2017_trigger0 limit obs
  echo "sample: "${sampleName}-2017-trigger1;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2017_trigger1 limit obs
  echo "sample: "${sampleName}-2018;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2018 limit obs
  echo "sample: "${sampleName}-2018-trigger0;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2018_trigger0 limit obs
  echo "sample: "${sampleName}-2018-trigger1;
  ~/ana_area/Combination/comb/runFit.sh . vbfg${sampleName}_2018_trigger1 limit obs

done

elif [ $1 = "monoz" ]; then
echo "*****monoz*******"
#grep -e sample -e r_s0 log_runFits_monoz|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%7==0)printf("\n");}'
for sampleName in `cat list_of_samples.txt`; do
   echo "sample: "${sampleName};
   #~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb limit exp
   ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb limit obs
done

#for sampleName in `cat list_of_samples.txt`; do
#   echo "sample: "${sampleName};
#   #~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_2016 limit exp
#   ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_2016 limit obs
#done

elif [ $1 = "aqgc" ]; then
echo "*****aqgc*******"
#grep -e sample -e r_s0 log_runFits_aqgc|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%7==0)printf("\n");}'|awk '{printf("%10s %11.6f 1 %11.6f %11.6f %11.6f %11.6f %11.6f\n",$1,$2,$5,$3,$4,$6,$7)}'
for sampleName in `cat list_of_aqgc_samples.txt`; do
   echo "sample: "${sampleName};
   #~/ana_area/Combination/comb/runFit.sh . aqgc_${sampleName}_comb limit exp
   ~/ana_area/Combination/comb/runFit.sh . aqgc_${sampleName}_comb limit obs
done

elif [ $1 = "zhstudy" ]; then
export sampleName="ADDMonoZ_MD_3_d_4"
#~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb limit exp
~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb limit obs

nohup ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb impacts obs >& log_impacts_zh${sampleName}_obs_comb &
nohup ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb impacts exp >& log_impacts_zh${sampleName}_exp_comb &
nohup ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb impacts expnosig >& log_impacts_zh${sampleName}_expnosig_comb &

nohup ~/ana_area/Combination/comb/runFit.sh . zh${sampleName}_comb mlf obs >& log_mlf_zh${sampleName}_comb_obs &

elif [ $1 = "zhinv" ]; then
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'|awk '{printf("%5.2f %5.2f %5.2f %5.2f\n",$1,$4-$3,$4,$5-$4)}'

echo "*****IMPACTS*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts obs >& log_impacts_zh &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts exp >& log_impacts_zh_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts expnosig >& log_impacts_zh_expnosig &

echo "*****MLF*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      mlf obs >& log_mlf_zh_comb_obs &

~/ana_area/Combination/comb/runFit.sh . zh_comb limit obs
~/ana_area/Combination/comb/runFit.sh . zh_comb significance exp
~/ana_area/Combination/comb/runFit.sh . zh_comb significance obs

elif [ $1 = "zh" ]; then
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'
#grep -e sample -e r_s0 log_runFits_zh|awk '{if($1=="sample:")printf("%10s ",$2);else printf("%11.6f ",$5);if(NR%6==0)printf("\n");}'|awk '{printf("%5.2f %5.2f %5.2f %5.2f\n",$1,$4-$3,$4,$5-$4)}'
echo "*****ZH*******"
#~/ana_area/Combination/comb/runFit.sh . zh_2016 limit exp
~/ana_area/Combination/comb/runFit.sh . zh_2016 limit obs
#~/ana_area/Combination/comb/runFit.sh . zh_2017 limit exp
~/ana_area/Combination/comb/runFit.sh . zh_2017 limit obs
#~/ana_area/Combination/comb/runFit.sh . zh_2018 limit exp
~/ana_area/Combination/comb/runFit.sh . zh_2018 limit obs
#~/ana_area/Combination/comb/runFit.sh . zh_comb limit exp
~/ana_area/Combination/comb/runFit.sh . zh_comb limit obs

echo "*****IMPACTS*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2016      impacts obs >& log_impacts_zh_2016 &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2017      impacts obs >& log_impacts_zh_2017 &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2018      impacts obs >& log_impacts_zh_2018 &

nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts obs >& log_impacts_zh &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts exp >& log_impacts_zh_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      impacts expnosig >& log_impacts_zh_expnosig &

echo "*****MLF*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2016      mlf obs >& log_mlf_zh_2016_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2017      mlf obs >& log_mlf_zh_2017_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_2018      mlf obs >& log_mlf_zh_2018_obs &

nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb      mlf obs >& log_mlf_zh_comb_obs &

echo "*****GOF*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb       gof obs      >& log_gof_zh_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . zh_comb       gof expnosig >& log_gof_zh_expnosig &

echo "*****GRID*******"
nohup combine -M MultiDimFit workspace_zh_comb.root -n zh_comb_grid_rs0_expnosig \
--algo grid --points 240 --setParameterRanges r_s0=0.0,1.2 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
--setParameters r_s0=0 -t -1 >& log_zh_comb_grid_rs0_expnosig &

nohup combine -M MultiDimFit workspace_zh_comb.root -n zh_comb_grid_rs0_fastScan_expnosig \
--algo grid --points 240 --setParameterRanges r_s0=0.0,1.2 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances \
--setParameters r_s0=0 -t -1 >& log_zh_comb_grid_rs0_fastScan_expnosig &

nohup combine -M MultiDimFit workspace_zh_comb.root -n zh_comb_grid_rs0_exp \
--algo grid --points 240 --setParameterRanges r_s0=0.0,1.2 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
--setParameters r_s0=1 -t -1 >& log_zh_comb_grid_rs0_exp &

nohup combine -M MultiDimFit workspace_zh_comb.root -n zh_comb_grid_rs0_obs \
--algo grid --points 240 --setParameterRanges r_s0=0.0,1.2 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 >& log_zh_comb_grid_rs0_obs &
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinezh_comb_grid_rs0_expnosig.MultiDimFit.mH120.root --POI "r_s0" --main-label "";mv scan.root scan0.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinezh_comb_grid_rs0_fastScan_expnosig.MultiDimFit.mH120.root --POI "r_s0" --main-label "";mv scan.root scan1.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinezh_comb_grid_rs0_obs.MultiDimFit.mH120.root --POI "r_s0" --main-label "";mv scan.root scan2.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinezh_comb_grid_rs0_exp.MultiDimFit.mH120.root --POI "r_s0" --main-label "";mv scan.root scan3.root;

elif [ $1 = "zhg" ]; then
echo "*****ZHG125*******"
~/ana_area/Combination/comb/runFit.sh . zhg_2016_125 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2016_125 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2017_125 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2017_125 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2018_125 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2018_125 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 limit obs

nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 limitToys obs >& limitToys_zhg_comb_125 &

echo "*****ZHG200*******"
~/ana_area/Combination/comb/runFit.sh . zhg_2016_200 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2016_200 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2017_200 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2017_200 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2018_200 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2018_200 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_comb_200 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_comb_200 limit obs

echo "*****ZHG300*******"
~/ana_area/Combination/comb/runFit.sh . zhg_2016_300 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2016_300 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2017_300 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2017_300 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_2018_300 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_2018_300 limit obs
~/ana_area/Combination/comb/runFit.sh . zhg_comb_300 limit exp
~/ana_area/Combination/comb/runFit.sh . zhg_comb_300 limit obs

echo "*****IMPACTS*******"
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 impacts obs >& log_impacts_zhg_125 &
nohup ~/ana_area/Combination/comb/runFit.sh . zhg_comb_125 impacts exp >& log_impacts_zhg_125_exp &

echo "*****MLF*******"
~/ana_area/Combination/comb/runFit.sh . zhg_comb_125  mlf obs

elif [ $1 = "ssww_hllhc" ]; then

  fake="";
  lumi=3000;
  #for lumi in 3000; do
  for lumi in 137 300 500 1000 2000 3000 4500 6000; do
  #for fake in _fake0p50 _fake0p75 _fake1p00 _fake1p25 _fake1p50 _fake2p00; do
  #for fake in _jetpt40 _jetpt50 _jetpt60 _jetpt80 _jetpt100; do
 
    echo "sample: "${lumi}${fake};

    if [ ${lumi} == '3000' ]; then
      nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial0_l${lumi}_wwframe${fake} mlf exp >& log_mlf_ssww_comb_fiducial0_l${lumi}_wwframe${fake}_exp &
    fi

    nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial0_l${lumi}_wwframe${fake} impacts exp >& log_impacts_ssww_comb_fiducial0_l${lumi}_wwframe${fake}_exp &
    nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_l${lumi}_wwframe${fake} impacts exp >& log_impacts_ssww_comb_fiducial5_l${lumi}_wwframe${fake}_exp &
    nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_l${lumi}_ppframe${fake} impacts exp >& log_impacts_ssww_comb_fiducial5_l${lumi}_ppframe${fake}_exp &

    combine -M MultiDimFit workspace_ssww_comb_fiducial0_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial0_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameterRanges r_s0=0.7,1.3:r_s1=0.5,1.5:r_s2=0.7,1.3 \
    --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1

    ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_l${lumi}_wwframe${fake}_rs0only significance exp
    ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_l${lumi}_ppframe${fake}_rs0only significance exp

    combine -M MultiDimFit workspace_ssww_comb_fiducial5_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial5_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4:r_s1=0.5,1.5 \
    --setParameters r_s0=1,r_s1=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial5_l${lumi}_ppframe${fake}.root -n ssww_comb_fiducial5_l${lumi}_ppframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4:r_s1=0.5,1.5 \
    --setParameters r_s0=1,r_s1=1 -t -1

    combine -M MultiDimFit workspace_ssww_comb_fiducial51_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.6,1.4:REWK=-0.8,2.8 --setParameters r_s0=1,REWK=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial52_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial52_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.6,1.4:REWK=-0.8,2.8 --setParameters r_s0=1,REWK=1 -t -1

    combine -M MultiDimFit workspace_ssww_comb_fiducial51_l${lumi}_ppframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_ppframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.6,1.4:REWK=-0.8,2.8 --setParameters r_s0=1,REWK=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial52_l${lumi}_ppframe${fake}.root -n ssww_comb_fiducial52_l${lumi}_ppframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.6,1.4:REWK=-0.8,2.8 --setParameters r_s0=1,REWK=1 -t -1

  done


elif [ $1 = "ssww_hllhc_3d" ]; then

  fake="";
  lumi=3000;
  #for lumi in 3000; do
  for lumi in 137 300 500 1000 2000 3000 4500 6000; do
  #for fake in _fake0p50 _fake0p75 _fake1p00 _fake1p25 _fake1p50 _fake2p00; do
  #for fake in _jetpt40 _jetpt50 _jetpt60 _jetpt80 _jetpt100; do
 
    echo "sample: "${lumi}${fake};

    combine -M MultiDimFit workspace_ssww_comb_fiducial51_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK2,REWK3 --setParameterRanges r_s0=0.6,1.4:REWK2=-2,4:REWK3=-2,4 --setParameters r_s0=1,REWK2=1,REWK3=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial52_l${lumi}_wwframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_wwframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK1,REWK3 --setParameterRanges r_s0=0.6,1.4:REWK1=-2,4:REWK3=-2,4 --setParameters r_s0=1,REWK1=1,REWK3=1 -t -1

    combine -M MultiDimFit workspace_ssww_comb_fiducial51_l${lumi}_ppframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_ppframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK2,REWK3 --setParameterRanges r_s0=0.6,1.4:REWK2=-2,4:REWK3=-2,4 --setParameters r_s0=1,REWK2=1,REWK3=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial52_l${lumi}_ppframe${fake}.root -n ssww_comb_fiducial51_l${lumi}_ppframe${fake}_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK1,REWK3 --setParameterRanges r_s0=0.6,1.4:REWK1=-2,4:REWK3=-2,4 --setParameters r_s0=1,REWK1=1,REWK3=1 -t -1


  done

elif [ $1 = "ssww_altcr" ]; then
~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance obs

nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_wwwz mlf obs >& log_mlf_comb_wwwz_obs &

combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2

elif [ $1 = "ssww" ]; then
echo "*****SSWW*******"
~/ana_area/Combination/comb/runFit.sh . ssww_2016_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2016_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_2017_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2017_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_2018_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2018_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_2016_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2016_wz significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_2017_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2017_wz significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_2018_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2018_wz significance obs
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_wz significance obs

nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial3all impacts exp >& log_impacts_ssww_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial3all impacts obs >& log_impacts_ssww_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial3all_2poi impacts exp >& log_impacts_ssww_2poi_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial3all_2poi impacts obs >& log_impacts_ssww_2poi_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial8all impacts exp >& log_impacts_ssww_fiducial8_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial8all impacts obs >& log_impacts_ssww_fiducial8_obs &

echo "*****MLF*******"
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2016_wwwz mlf obs >& log_mlf_2016_wwwz_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2017_wwwz mlf obs >& log_mlf_2017_wwwz_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2018_wwwz mlf obs >& log_mlf_2018_wwwz_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_wwwz mlf obs >& log_mlf_comb_wwwz_obs &

echo "*****GOF*******"
#nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww_wwwz gof exp >& log_gof_ssww_exp &
#nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_ww_wwwz gof obs >& log_gof_ssww_obs &

echo "****DIFFERENTIAL*****"
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_intf.root -n ssww_comb_intf_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_intf.root -n ssww_comb_intf_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2
combine -M MultiDimFit workspace_ssww_comb_wwwz_2poi.root -n ssww_comb_wwwz_2poi_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5 --setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_comb_wwwz_2poi.root -n ssww_comb_wwwz_2poi_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5

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
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_fiducial3all_r_s0_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_r_s1_fast_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_fiducial3all_r_s1_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all.root -n ssww_comb_fiducial3all_r_s2_fast_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s2 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_fiducial3all_r_s2_fast_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_fast_r_s0_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s0 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_fiducial3all_2poi_fast_r_s0_obs &

nohup combine -M MultiDimFit workspace_ssww_comb_fiducial3all_2poi.root -n ssww_comb_fiducial3all_2poi_fast_r_s1_obs \
--algo grid --points 2000 --setParameterRanges r_s0=0.5,2.5:r_s1=0.5,2.5:r_s2=0.5,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_fiducial3all_2poi_fast_r_s1_obs &


nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_fast_exp \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances \
--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1 >& log_ssww_comb_wwwz_grid_fast_exp &
nohup combine -M MultiDimFit workspace_ssww_comb_wwwz.root -n ssww_comb_wwwz_grid_fast_obs \
--algo grid --points 5000 --setParameterRanges r_s0=0.0,2.5:r_s1=0.0,2.5:r_s2=0.0,2.5  \
--redefineSignalPOIs r_s0,r_s1,r_s2 -P r_s1 -P r_s2 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances >& log_ssww_comb_wwwz_grid_fast_obs &

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
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5 impacts exp >& log_impacts_ssww_fiducial5_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5 impacts obs >& log_impacts_ssww_fiducial5_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial9 impacts exp >& log_impacts_ssww_fiducial9_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial9 impacts obs >& log_impacts_ssww_fiducial9_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2016_fiducial5 mlf obs >& log_mlf_2016_fiducial5_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2017_fiducial5 mlf obs >& log_mlf_2017_fiducial5_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2018_fiducial5 mlf obs >& log_mlf_2018_fiducial5_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5 mlf obs >& log_mlf_2019_fiducial5_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial9 mlf obs >& log_mlf_2019_fiducial9_obs &

~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5_rs0only limit obs
~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5_rs0only significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial5_rs0only significance obs

~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial9_rs0only significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial9_rs0only significance obs

combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_rs0only_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --setParameterRanges r_s0=-2,4 \
--setParameters r_s0=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_rs0only_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --setParameterRanges r_s0=-2,4

combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4 \
--setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4

combine -M MultiDimFit workspace_ssww_2019_fiducial9.root -n ssww_2019_fiducial9_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0,3:r_s1=0,3 \
--setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial9.root -n ssww_2019_fiducial9_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0,3:r_s1=0,3

if [ $# == 2 ] && [ $2 == 'intf' ]; then

combine -M MultiDimFit workspace_ssww_2019_fiducial5_intf.root -n ssww_2019_fiducial5_intf_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4 \
--setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial5_intf.root -n ssww_2019_fiducial5_intf_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-2,4

combine -M MultiDimFit workspace_ssww_2019_fiducial9_intf.root -n ssww_2019_fiducial9_intf_exp \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0,3:r_s1=0,3 \
--setParameters r_s0=1,r_s1=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial9_intf.root -n ssww_2019_fiducial9_intf_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=0,3:r_s1=0,3

fi

#combine -M MultiDimFit workspace_ssww_2019_fiducial9_split.root -n ssww_2019_fiducial9_split_exp \
#--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameterRanges r_s0=0,3:r_s1=0,3:r_s2=0,3 \
#--setParameters r_s0=1,r_s1=1,r_s2=1 -t -1
#combine -M MultiDimFit workspace_ssww_2019_fiducial9_split.root -n ssww_2019_fiducial9_split_obs \
#--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1,r_s2 --setParameterRanges r_s0=0,3:r_s1=0,3:r_s2=0,3

combine -M MultiDimFit workspace_ssww_2019_fiducial51.root -n ssww_2019_fiducial51_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameters r_s0=1,REWK=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial51.root -n ssww_2019_fiducial51_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.3,1.5:REWK=-1,3
combine -M MultiDimFit workspace_ssww_2019_fiducial52.root -n ssww_2019_fiducial52_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameters r_s0=1,REWK=1 -t -1 --setParameterRanges r_s0=0.3,1.5:REWK=-1,3
combine -M MultiDimFit workspace_ssww_2019_fiducial52.root -n ssww_2019_fiducial52_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.3,1.5:REWK=-1,3

combine -M MultiDimFit workspace_ssww_2019_fiducial91.root -n ssww_2019_fiducial91_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameters r_s0=1,REWK=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial91.root -n ssww_2019_fiducial91_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.5,1.5:REWK=0,3
combine -M MultiDimFit workspace_ssww_2019_fiducial92.root -n ssww_2019_fiducial92_exp --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameters r_s0=1,REWK=1 -t -1
combine -M MultiDimFit workspace_ssww_2019_fiducial92.root -n ssww_2019_fiducial92_obs --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,REWK --setParameterRanges r_s0=0.4,1.5:REWK=0,3

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_exp \
#--algo grid --points 5000 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5  \
#--redefineSignalPOIs r_s0,r_s1 -P r_s0 -P r_s1 --floatOtherPOIs=1 \
#--setParameters r_s0=1,r_s1=1 -t -1 >& log_ssww_2019_fiducial5_grid_exp &
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5.root -n ssww_2019_fiducial5_grid_obs \
#--algo grid --points 5000 --setParameterRanges r_s0=-1.0,1.5:r_s1=0.0,2.5  \
#--redefineSignalPOIs r_s0,r_s1 -P r_s0 -P r_s1 --floatOtherPOIs=1 >& log_ssww_2019_fiducial5_grid_obs &

nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_grid_rs0_expnosig \
--algo grid --points 500 --setParameterRanges r_s0=0.0,5.0 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
--setParameters r_s0=0 -t -1 >& log_ssww_2019_fiducial5_grid_rs0_expnosig &

nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_grid_rs0_fastScan_expnosig \
--algo grid --points 500 --setParameterRanges r_s0=0.0,5.0 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 --freezeParameters allConstrainedNuisances \
--setParameters r_s0=0 -t -1 >& log_ssww_2019_fiducial5_grid_rs0_fastScan_expnosig &

nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_grid_rs0_exp \
--algo grid --points 500 --setParameterRanges r_s0=0.0,5.0 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
--setParameters r_s0=1 -t -1 >& log_ssww_2019_fiducial5_grid_rs0_exp &

nohup combine -M MultiDimFit workspace_ssww_2019_fiducial5_rs0only.root -n ssww_2019_fiducial5_grid_rs0_obs \
--algo grid --points 500 --setParameterRanges r_s0=0.0,5.0 \
--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 >& log_ssww_2019_fiducial5_grid_rs0_obs &

#python ~/releases/CMSSW_10_2_13/src/CombineHarvester/CombineTools/scripts/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_exp.MultiDimFit.mH120.root --POI "r_s0*999" --translate translate.json --main-label "ObserveD"
#python ~/releases/CMSSW_10_2_13/src/CombineHarvester/CombineTools/scripts/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_obs.MultiDimFit.mH120.root --POI "r_s0*999" --translate translate.json --main-label "ObserveD"
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_expnosig.MultiDimFit.mH120.root          --POI "r_s0*0.441" --main-label "";mv scan.root scan0.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_fastScan_expnosig.MultiDimFit.mH120.root --POI "r_s0*0.441" --main-label "";mv scan.root scan1.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_obs.MultiDimFit.mH120.root               --POI "r_s0*0.441" --main-label "";mv scan.root scan2.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_exp.MultiDimFit.mH120.root               --POI "r_s0*0.441" --main-label "";mv scan.root scan3.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_expnosig.MultiDimFit.mH120.root          --POI "r_s0*0.279" --main-label "";mv scan.root scan0.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_fastScan_expnosig.MultiDimFit.mH120.root --POI "r_s0*0.279" --main-label "";mv scan.root scan1.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_obs.MultiDimFit.mH120.root               --POI "r_s0*0.279" --main-label "";mv scan.root scan2.root;
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial5_grid_rs0_exp.MultiDimFit.mH120.root               --POI "r_s0*0.279" --main-label "";mv scan.root scan3.root;

  if [ $# == 2 ] && [ $2 == 'comb' ]; then

    ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_rs0only limit obs
    ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_rs0only significance exp
    ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5_rs0only significance obs
    nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial5 mlf obs >& log_mlf_ssww_comb_fiducial5_obs &
    nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial9 mlf obs >& log_mlf_ssww_comb_fiducial9_obs &

    combine -M MultiDimFit workspace_ssww_comb_fiducial5.root -n ssww_comb_fiducial5_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-3,4 \
    --setParameters r_s0=1,r_s1=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial5.root -n ssww_comb_fiducial5_obs \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-3,4
    
    combine -M MultiDimFit workspace_ssww_comb_fiducial9.root -n ssww_comb_fiducial9_exp \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 \
    --setParameters r_s0=1,r_s1=1 -t -1
    combine -M MultiDimFit workspace_ssww_comb_fiducial9.root -n ssww_comb_fiducial9_obs \
    --algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1
    
  fi

elif [ $1 == "higgs" ]; then
echo "*****HIGGS*******"

for sampleName in 200 300 400 500 600 700 800 900 1000 1500 2000 3000; do
#for sampleName in 500; do
echo "sample: "${sampleName};

#grep -e "r_s0 <" -e "r_s1 <" log_runFits_*|awk '{xs=1;if($1=="sample:")printf("%19s ",$2);else printf("%11.6f ",$5*xs);if(NR%6==0)printf("\n");if(NR%36==0)printf("--------------\n");}'

rMin0=0;rMin1=0;
rMax0=1;rMax1=1;
if [ ${sampleName} == 2000 ]; then
  rMin0=0;rMin1=0;
  rMax0=2;rMax1=9;
elif [ ${sampleName} == 3000 ]; then
  rMin0=0;rMin1=0;
  rMax0=10;rMax1=50;
fi

if [ ${sampleName} == 500 ]; then

nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  mlf obs >& log_mlf_ssww_2019_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial6_mH${sampleName}  mlf obs >& log_mlf_ssww_comb_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts obs      >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts expnosig >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_expnosig &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts exp      >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_exp &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial6_mH${sampleName}  impacts obs      >& log_impacts_ssww_comb_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial6_mH${sampleName}  impacts expnosig >& log_impacts_ssww_comb_fiducial6_mH${sampleName}_expnosig &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  gof obs      >& log_gof_ssww_2019_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  gof expnosig >& log_gof_ssww_2019_fiducial6_mH${sampleName}_expnosig &

fi

if [ ${sampleName} == 1000 ]; then

nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts obs      >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_obs &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts expnosig >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_expnosig &
nohup ~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName}  impacts exp      >& log_impacts_ssww_2019_fiducial6_mH${sampleName}_exp &

fi

combine -M AsymptoticLimits workspace_ssww_2019_fiducial6_mH${sampleName}.root       --newExpected=1 -n ssww_2019_fiducial6_mH${sampleName}_obs --rMin ${rMin0} --rMax ${rMax0}
combine -M AsymptoticLimits workspace_ssww_2019_fiducial6_mH${sampleName}_split.root --newExpected=1 --redefineSignalPOIs r_s0 --setParameters r_s1=0 --freezeParameters r_s1,QCDscale_Hpp,QCDscale_Hp -n ssww_2019_fiducial6_mH${sampleName}_split_rs0_obs --rMin ${rMin0} --rMax ${rMax0}
combine -M AsymptoticLimits workspace_ssww_2019_fiducial6_mH${sampleName}_split.root --newExpected=1 --redefineSignalPOIs r_s1 --setParameters r_s0=0 --freezeParameters r_s0,QCDscale_Hpp,QCDscale_Hp -n ssww_2019_fiducial6_mH${sampleName}_split_rs1_obs --rMin ${rMin1} --rMax ${rMax1}
~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName} significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_2019_fiducial6_mH${sampleName} significance obs

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}_split.root -n ssww_2019_fiducial6_mH${sampleName}_split_grid_rs0_expnosig \
#--algo grid --points 500 --setParameterRanges r_s0=-1,1 \
#--redefineSignalPOIs r_s0,r_s1 -P r_s0 --floatOtherPOIs=1 \
#--setParameters r_s0=0 -t -1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_split_grid_rs0_expnosig &
#
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}_split.root -n ssww_2019_fiducial6_mH${sampleName}_split_grid_rs0_obs \
#--algo grid --points 500 --setParameterRanges r_s0=-1,1 \
#--redefineSignalPOIs r_s0,r_s1 -P r_s0 --floatOtherPOIs=1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_split_grid_rs0_obs &
#
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}_split.root -n ssww_2019_fiducial6_mH${sampleName}_split_grid_rs1_expnosig \
#--algo grid --points 500 --setParameterRanges r_s1=-1,1 \
#--redefineSignalPOIs r_s0,r_s1 -P r_s1 --floatOtherPOIs=1 \
#--setParameters r_s1=0 -t -1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_split_grid_rs1_expnosig &

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}_split.root -n ssww_2019_fiducial6_mH${sampleName}_split_grid_rs1_obs \
#--algo grid --points 500 --setParameterRanges r_s1=-1,1 \
#--redefineSignalPOIs r_s0,r_s1 -P r_s1 --floatOtherPOIs=1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_split_grid_rs1_obs &

#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}.root -n ssww_2019_fiducial6_mH${sampleName}_grid_rs0_expnosig \
#--algo grid --points 500 --setParameterRanges r_s0=-1,1 \
#--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
#--setParameters r_s0=0 -t -1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_grid_rs0_expnosig &
#
#nohup combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}.root -n ssww_2019_fiducial6_mH${sampleName}_grid_rs0_obs \
#--algo grid --points 500 --setParameterRanges r_s0=-1,1 \
#--redefineSignalPOIs r_s0 -P r_s0 --floatOtherPOIs=1 \
#>& log_ssww_2019_fiducial6_mH${sampleName}_grid_rs0_obs &
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_split_grid_rs2_expnosig.MultiDimFit.mH120.root --POI "r_s0";
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_split_grid_rs2_obs.MultiDimFit.mH120.root      --POI "r_s0";
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_split_grid_rs3_expnosig.MultiDimFit.mH120.root --POI "r_s1";
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_split_grid_rs3_obs.MultiDimFit.mH120.root      --POI "r_s1";
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_grid_rs2_expnosig.MultiDimFit.mH120.root --POI "r_s0";
#python ~/ana_area/Combination/comb/plot1DScan.py higgsCombinessww_2019_fiducial6_mH${sampleName}_grid_rs2_obs.MultiDimFit.mH120.root	   --POI "r_s0";

combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}_split.root -n ssww_fiducial6_mH${sampleName}_split_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-1,4:r_s1=-1,4

combine -M MultiDimFit workspace_ssww_2019_fiducial6_mH${sampleName}.root -n ssww_fiducial6_mH${sampleName}_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --setParameterRanges r_s0=-1,4

if [ $# == 2 ] && [ $2 == 'comb' ]; then

combine -M AsymptoticLimits workspace_ssww_comb_fiducial6_mH${sampleName}.root       --newExpected=1 -n ssww_comb_fiducial6_mH${sampleName}_obs --rMax 1.0
combine -M AsymptoticLimits workspace_ssww_comb_fiducial6_mH${sampleName}_split.root --newExpected=1 --redefineSignalPOIs r_s0 --setParameters r_s1=0 --freezeParameters r_s1 -n ssww_comb_fiducial6_mH${sampleName}_split_rs0_obs --rMax 1.0
combine -M AsymptoticLimits workspace_ssww_comb_fiducial6_mH${sampleName}_split.root --newExpected=1 --redefineSignalPOIs r_s1 --setParameters r_s0=0 --freezeParameters r_s0 -n ssww_comb_fiducial6_mH${sampleName}_split_rs1_obs --rMax 1.0
~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial6_mH${sampleName} significance exp
~/ana_area/Combination/comb/runFit.sh . ssww_comb_fiducial6_mH${sampleName} significance obs

combine -M MultiDimFit workspace_ssww_comb_fiducial6_mH${sampleName}_split.root -n ssww_fiducial6_mH${sampleName}_split_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0,r_s1 --setParameterRanges r_s0=-1,4:r_s1=-1,4

combine -M MultiDimFit workspace_ssww_comb_fiducial6_mH${sampleName}.root -n ssww_fiducial6_mH${sampleName}_obs \
--algo=singles --robustFit=1 --X-rtd FITTER_DYN_STEP  --redefineSignalPOIs r_s0 --setParameterRanges r_s0=-1,4

fi

done

elif [ $1 = "ww" ]; then
echo "*****WW*******"
echo "*****IMPACTS*******"
nohup ~/ana_area/Combination/comb/runFit.sh . ww_2016   impacts obs >& log_impacts_ww_2016 &
nohup ~/ana_area/Combination/comb/runFit.sh . ww_2017   impacts obs >& log_impacts_ww_2017 &
nohup ~/ana_area/Combination/comb/runFit.sh . ww_2018   impacts obs >& log_impacts_ww_2018 &
nohup ~/ana_area/Combination/comb/runFit.sh . ww_2019   impacts obs >& log_impacts_ww_2019 &

echo "*****MLF*******"
~/ana_area/Combination/comb/runFit.sh . ww_2016   mlf obs
~/ana_area/Combination/comb/runFit.sh . ww_2017   mlf obs
~/ana_area/Combination/comb/runFit.sh . ww_2018   mlf obs
~/ana_area/Combination/comb/runFit.sh . ww_2019   mlf obs

fi
