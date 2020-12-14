#include "ProtStats.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "getline.h"


unsigned int num_prots(const char *path) {
    FILE *fileptr;
    fileptr = fopen(path, "r");//open file
    if (fileptr == NULL) {
        printf("FILE NOT FOUND!\n");
        exit(-1);
    }
    unsigned int counter = 0;
    char c;

    while ((c = getc(fileptr)) != EOF) {
        if (c == '>') {
            counter++;
        }
    }
    fclose(fileptr);
    return counter;

}

ProtStats *ProtStatsCreate(const char *prot, const char *amino) {
    ProtStats *ps;
    ps = (ProtStats *) malloc(sizeof(struct ProtStats));
    ps->name = strdup(prot);
    ps->length = strlen(amino);
    return ps;
}

void ProtStatsInit(const char *prot, const char *amino, ProtStats *ps) {
    double hidro = 0, polar = 0, charge = 0;

    for (int i = 0; amino[i]; i++) {
        switch (find_type(amino[i])) {
            case H :
                hidro++;
                break;
            case P :
                polar++;
                break;
            case C :
                charge++;
                break;
            default:
                continue;
        }
    }
    ps->aa_freq[H] = (hidro / (double) strlen(amino)) * 100;
    ps->aa_freq[P] = (polar / strlen(amino)) * 100;
    ps->aa_freq[C] = (charge / strlen(amino)) * 100;

}

void ProtStatCopy(ProtStats *target, ProtStats *source) {
    if (target == NULL || source == NULL)
        printf(stderr, "SEGMENTATION FAULT\n");
    target->name = strdup(source->name);

    target->length = source->length;
    target->aa_freq[H] = source->aa_freq[H];
    target->aa_freq[P] = source->aa_freq[P];
    target->aa_freq[C] = source->aa_freq[C];

}

void ProtStatSwap(ProtStats *prot1, ProtStats *prot2) {

    ProtStats *temp = ProtStatsCreate("", "");
    temp->aa_freq[H] = 0;
    temp->aa_freq[C] = 0;
    temp->aa_freq[P] = 0;


    temp->name = strdup(prot1->name);
    temp->length = prot1->length;
    temp->aa_freq[H] = prot1->aa_freq[H];
    temp->aa_freq[P] = prot1->aa_freq[P];
    temp->aa_freq[C] = prot1->aa_freq[C];

    prot1->name = strdup(prot1->name);
    prot1->length = prot2->length;
    prot1->aa_freq[H] = prot2->aa_freq[H];
    prot1->aa_freq[P] = prot2->aa_freq[P];
    prot1->aa_freq[C] = prot2->aa_freq[C];

    prot2->name = strdup(temp->name);
    prot2->length = temp->length;
    prot2->aa_freq[H] = temp->aa_freq[H];
    prot2->aa_freq[P] = temp->aa_freq[P];
    prot2->aa_freq[C] = temp->aa_freq[C];
    free(temp);
}

ProtStats **read_fasta_file(const char *filename, unsigned int *arrLen) {
    int size = num_prots(filename);

    ProtStats **array = (ProtStats **) malloc((size) * sizeof(struct ProtStats));
    FILE *fileptr;
    fileptr = fopen(filename, "r");//open file
    if (fileptr == NULL) {
        printf("FILE NOT FOUND!\n");
        exit(-1);
    }

    char *buf = NULL;
    size_t buf_size = 0;
    char *buf2 = NULL;
    size_t buf_size2 = 0;
    *arrLen = 0;

    while (getline(&buf, &buf_size, fileptr) != EOF) {

        char *protName = strdup((buf + 1));

        getline(&buf2, &buf_size2, fileptr);
        ProtStats *protstat = ProtStatsCreate(protName, buf2);
        ProtStatsInit(protName, buf2, protstat);
        array[*arrLen] = protstat;
        (*arrLen)++;

    }
    return array;


}

aa_type find_type(unsigned char chr) {

    if (chr == 'A' || chr == 'I' || chr == 'L' || chr == 'F'
        || chr == 'V' || chr == 'P' || chr == 'G')
        return H;
    if (chr == 'R' || chr == 'K' || chr == 'D' || chr == 'E')
        return C;
    if (chr == 'Q' || chr == 'N' || chr == 'H' || chr == 'S'
        || chr == 'T' || chr == 'Y' || chr == 'C' || chr == 'M' || chr == 'W')
        return P;
    return -1;

}

