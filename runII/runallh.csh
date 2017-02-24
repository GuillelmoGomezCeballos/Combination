#!/bin/tcsh -f

foreach file (sm mh110 mh125 mh150 mh200 mh300 mh400 mh500 mh600 mh800 mh1000 DarkMatter_MonoZToLL_V_Mx-150_Mv-500_gDMgQ-1 DarkMatter_MonoZToLL_V_Mx-150_Mv-295_gDMgQ-1 DarkMatter_MonoZToLL_V_Mx-1_Mv-2000_gDMgQ-1 DarkMatter_MonoZToLL_A_Mx-150_Mv-500_gDMgQ-1 DarkMatter_MonoZToLL_A_Mx-150_Mv-295_gDMgQ-1 DarkMatter_MonoZToLL_A_Mx-1_Mv-2000_gDMgQ-1)
#foreach file (sm)

#./computeLimit#.sh zh${file}    1 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 1 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    2 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 2 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    3 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 3 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    4 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 4 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    5 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 5 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    6 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 6 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    7 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 7 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

#./computeLimit#.sh zh${file}    8 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
#./computeLimit#.sh zh${file}_10 8 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

./computeLimit.sh zh${file}    9 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv
./computeLimit.sh zh${file}_10 9 exp $HOME/releases/CMSSW_7_4_7/src/cards/cards_inv

end
