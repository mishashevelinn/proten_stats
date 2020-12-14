#ifndef EX4_PROTSTATS_H
#define EX4_PROTSTATS_H
#define _POSIX_C_SOURCE 200809L
typedef struct ProtStats{
    char* name;
    int length;
    double aa_freq[3];
} ProtStats;

typedef enum  {
    H=0,
    C=1,
    P=2

}aa_type;

unsigned int num_prots(const char* path);

ProtStats* ProtStatsCreate(const char* prot,const char* amino);

void ProtStatsInit(const char* prot ,const char* amino,ProtStats* ps);

void ProtStatCopy(ProtStats* prot1,ProtStats* p2);

void ProtStatSwap(ProtStats* prot1,ProtStats* p2);

ProtStats** read_fasta_file(const char* file, unsigned int* prot );

aa_type find_type(unsigned char chr );




#endif //EX4_PROTSTATS_H
