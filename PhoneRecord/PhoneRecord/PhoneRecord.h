#ifndef PHONERECORD_H
#define PHONERECORD_H

// function prototypes
int menu();
int displayFile(char *);
int findRecord(char *);
int displayRecord(char *, int);
int updateRecord(char *, int);
int deleteRecord(char *, int);
int addRecord(char *, int);
static char fileName[] = "phony.411.txt";
static int  recordSize = 43;

#endif
