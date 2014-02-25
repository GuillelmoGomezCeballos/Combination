#/bin/sh

for chan in hww_01j_shape  hww_01j_cut  hww_vbf_shape    hww_vbf_cut    hww_vh2j_shape  hww_vh2j_cut \
            hww_vh3l_shape hww_vh3l_cut hww_zh3l2j_shape hww_zh3l2j_cut hww_7p8TeV
do
./submit.sh $1 $chan sig exp;
./submit.sh $1 $chan sig obs;
./submit.sh $1 $chan lim exp;
./submit.sh $1 $chan lim obs;
./submit.sh $1 $chan mlf exp;
./submit.sh $1 $chan mlf obs;
done
