for i in {1..100};
do
    #echo 'echo "HOSTNAME:";hostname;source /cvmfs/cms.cern.ch/cmsset_default.sh;cd /home/ceballos/releases/CMSSW_10_2_13/src/;eval `scram runtime -sh`;cd -;cp /home/ceballos/ana_area/done_vbfg_default/workspace_vbfg125.root .;combine -M FitDiagnostics --saveWithUncertainties --saveNormalizations --savePredictionsPerToy -t 10 --toysFrequentist workspace_vbfg125.root -s '$i' -n '$i';pwd;ls;mv fitDiagnostic*.root /data/t3home000/ceballos/toys/;'
    echo 'echo "HOSTNAME:";hostname;source /cvmfs/cms.cern.ch/cmsset_default.sh;cd /home/ceballos/releases/CMSSW_10_2_13/src/;eval `scram runtime -sh`;cd -;cp /home/ceballos/ana_area/ana_long/workspace_ssww_2019_fiducial5.root .;combine -M FitDiagnostics --saveWithUncertainties --saveNormalizations --savePredictionsPerToy -t 10 --toysFrequentist workspace_ssww_2019_fiducial5.root --setParameters r_s0=1,r_s1=1 -s '$i' -n '$i';pwd;ls;mv fitDiagnostic*.root /data/t3home000/ceballos/toys/;'
done
