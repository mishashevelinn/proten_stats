/*
 * getline.h
 *
 *  Created on: May 6, 2020
 *      Author: Abziz
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef GETLINE_H_
#define GETLINE_H_

ssize_t getdelim(char** buf, size_t* bufsiz, int delimiter, FILE* fp);
ssize_t getline(char** buf, size_t* bufsiz, FILE* fp);
#endif /* GETLINE_H_ */