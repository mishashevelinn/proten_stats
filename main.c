#include <stdio.h>
#include <malloc.h>
#include "ProtStats.h"

int main() {
//    printf("%d\n",num_prots("example1.fasta"));
//    ProtStats* protptr1;
//    ProtStats* protptr2;
//
//    protptr1=ProtStatsCreate("prot1","MEIVCNQNEFNYAIQLVSKAVASRPTHPILANLLLTADQGT");
//    printf("%s ,%d\n",protptr1->name,protptr1->length);
//
//    protptr2=ProtStatsCreate("prot2","MCGIVGIVSCDDVNQQ");
//    printf("%s ,%d\n",protptr2->name,protptr2->length);
//
//    ProtStatsInit("prot1","MEIVCNQNEFNYAIQLVSKAVASRPTHPILANLLLTADQGT",protptr1);
//    printf("%f, %f, %f\n", protptr1->aa_freq[H],protptr1->aa_freq[P],protptr1->aa_freq[C] );
//
//    ProtStatsInit("prot2","MCGIVGIVSCDDVNQQ",protptr2);
//
//    ProtStatSwap(protptr1,protptr2);
//    printf("%s, %d, %f, %f, %f\n", protptr1->name,protptr1->length,
//           protptr1->aa_freq[H],protptr1->aa_freq[C],protptr1->aa_freq[P]);
//    printf("%s, %d, %f, %f, %f\n", protptr2->name,protptr2->length,
//           protptr2->aa_freq[H],protptr2->aa_freq[C],protptr2->aa_freq[P]);
//



    unsigned int len = 0;
    ProtStats** protArray;
    protArray=read_fasta_file("example1.fasta",&len);

    printf("N\tName\tLength\tHydro\tCharged\tPolar\n");
    int i;
    for(i=0; i <= num_prots("example1.fasta");i++) {
        printf( "%d\t %s\t %d\t %f\t %f\t %f\t ",i+1, protArray[i]->name, protArray[i]->length,
                protArray[i]->aa_freq[H],protArray[i]->aa_freq[C],protArray[i]->aa_freq[P]);



    return 0;
}
}