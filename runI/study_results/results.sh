#!/bin/sh

rm -f lll;
touch lll;
for mass in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
  do
export MASS=${mass};
awk '{printf("%9.5f ",$ENVIRON["MASS"]);if(NR==15)printf("\n");}' results0.txt >> lll;
done

awk '($1!=0){if(NR==1)printf("double study01[21]={");printf("%4.2f",$1/$4); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study02[21]={");printf("%4.2f",$1/$7); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study03[21]={");printf("%4.2f",$1/$10);if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study04[21]={");printf("%4.2f",$1/$13);if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study05[21]={");printf("%4.2f",$2/$5); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study06[21]={");printf("%4.2f",$2/$8); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study07[21]={");printf("%4.2f",$2/$11);if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study08[21]={");printf("%4.2f",$2/$14);if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study09[21]={");printf("%4.2f",$3/$6); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study10[21]={");printf("%4.2f",$3/$9); if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study11[21]={");printf("%4.2f",$3/$12);if(NR!=21)printf(",");else printf("};\n");}' lll
awk '($1!=0){if(NR==1)printf("double study12[21]={");printf("%4.2f",$3/$15);if(NR!=21)printf(",");else printf("};\n");}' lll

awk '($1!=0){printf("%4.2f %4.2f %4.2f %4.2f - %4.2f %4.2f %4.2f %4.2f - %4.2f %4.2f %4.2f %4.2f\n",$1/$4,$1/$7,$1/$10,$1/$13,$2/$5,$2/$8,$2/$11,$2/$14,$3/$6,$3/$9,$3/$12,$3/$15)}' lll

rm -f lll;
