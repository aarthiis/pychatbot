#ifndef _TOKENSYSTEMH_
#define _TOKENSYSTEMH_
#include "common.h"

#ifdef INFORMATION
Copyright (C) 2011-2013 by Bruce Wilcox

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#endif

extern char* joinBuffer;
extern uint64 tokenFlags;  
extern char* wordStarts[MAX_SENTENCE_LENGTH];
extern bool capState[MAX_SENTENCE_LENGTH];	
extern unsigned int wordCount;	

int BurstWord(char* word, int contractionStyle = 0);
char* GetBurstWord(unsigned int n);
char* JoinWords(unsigned int n,bool output = false);

char* Tokenize(char* input,unsigned int& count,char** words,bool all = false, bool nomodify = false);
int ValidPeriodToken(char* start, char* end, char next,char next2);

void ProcessSubstitutes();
void ProcessCompositeNumber();
void ProcessCompositeName();

unsigned int TransformCount(char* dictword, unsigned int inputLen, char* inputSet, uint64 min);
void ResetTokenSystem();
void DumpTokenControls(uint64 val);
void DumpTokenFlags();
#endif
