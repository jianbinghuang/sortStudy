// learn.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <unordered_set>
#       define M_PI 3.14159265358979323846

extern void ComputeCosSin()
{
    FILE* fp = fopen("d:\cosSin.txt", "w");
    double cosVal[72], sinVal[72];
    for(int i=0; i<72; ++i){
        cosVal[i] = cos(double(i)*2.0*M_PI /72.0);
        sinVal[i] = sin(double(i)*2.0*M_PI /72.0);
    }
    float cosValF[72], sinValF[72];
    for(int i=0; i<72; ++i){
        cosValF[i] = float(cosVal[i]);
        sinValF[i] = float(sinVal[i]);
    }

    for(int i=0; i<72; i=i+6){
        fprintf(fp, "%.14f,", cosVal[i]);
        fprintf(fp, "%.14f,", cosVal[i+1]);
        fprintf(fp, "%.14f,", cosVal[i+2]);
        fprintf(fp, "%.14f,", cosVal[i+3]);
        fprintf(fp, "%.14f,", cosVal[i+4]);
        fprintf(fp, "%.14f,", cosVal[i+5]);
        fprintf(fp,"\n");
    }

    for(int i=0; i<72; i=i+6){
        fprintf(fp, "%.14f,", sinVal[i]);
        fprintf(fp, "%.14f,", sinVal[i+1]);
        fprintf(fp, "%.14f,", sinVal[i+2]);
        fprintf(fp, "%.14f,", sinVal[i+3]);
        fprintf(fp, "%.14f,", sinVal[i+4]);
        fprintf(fp, "%.14f,", sinVal[i+5]);
        fprintf(fp,"\n");
    }

    for(int i=0; i<72; i=i+6){
        fprintf(fp, "%.7ff,", cosValF[i]);
        fprintf(fp, "%.7ff,", cosValF[i+1]);
        fprintf(fp, "%.7ff,", cosValF[i+2]);
        fprintf(fp, "%.7ff,", cosValF[i+3]);
        fprintf(fp, "%.7ff,", cosValF[i+4]);
        fprintf(fp, "%.7ff,", cosValF[i+5]);
        fprintf(fp,"\n");
    }

    for(int i=0; i<72; i=i+6){
        fprintf(fp, "%.7ff,", sinValF[i]);
        fprintf(fp, "%.7ff,", sinValF[i+1]);
        fprintf(fp, "%.7ff,", sinValF[i+2]);
        fprintf(fp, "%.7ff,", sinValF[i+3]);
        fprintf(fp, "%.7ff,", sinValF[i+4]);
        fprintf(fp, "%.7ff,", sinValF[i+5]);
        fprintf(fp,"\n");
    }
    fclose(fp);
}
