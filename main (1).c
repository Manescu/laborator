#include <stdio.h>
#include <stdlib.h>

int nrNoduri, nrNoduriVizitate;
int *matriceAdiacenta;

void citireDate(FILE *file, int nrMuchii){
    int source, target, offset;

    if (file == NULL) {
        printf("Error: Fisierul este gol.");
        exit(1);
    }

    matriceAdiacenta =(int *) calloc((size_t) (nrNoduri * nrNoduri), sizeof(int));

    while (nrMuchii > 0){
        fscanf(file,"%d %d",&source,&target);
        offset = source * nrNoduri + target;
        *(matriceAdiacenta + offset)=1;
        nrMuchii--;
    }
}


void dfs(int *vizitat, int nodDat){
    int i,offset;

    *(vizitat+nodDat)=1;
    nrNoduriVizitate = nrNoduriVizitate+1;
    for (i=0;i<nrNoduri;i++){
        offset=nodDat*nrNoduri+i;
        if (*(vizitat+i) == 0 && *(matriceAdiacenta+offset) == 1){
            dfs(vizitat,i);
        }
    }
}

int main() {
    FILE *fileIn;
//    FILE *fileOut;
    int nrTeste,nrMuchii,nodStart, nrSolutiiGasite;
    int *vizitat;

    fileIn=fopen("/Users/becheru/Google Drive/Wrk/Probleme Procon Becheru/Becheru 2 Conducte/date.in","r");
//    fileOut=fopen("/Users/becheru/Google Drive/Wrk/Probleme Procon Becheru/Becheru 2 Conducte/date.out","w");
    fscanf(fileIn,"%d",&nrTeste);
    while (nrTeste > 0){
        fscanf(fileIn,"%d %d",&nrNoduri,&nrMuchii);
        citireDate(fileIn,nrMuchii);
        nrSolutiiGasite = 0;

        for (nodStart=0;nodStart<nrNoduri;nodStart++){
            vizitat=calloc((size_t) nrNoduri, sizeof(int));
            nrNoduriVizitate = 0;
            dfs(vizitat,nodStart);

            if (nrNoduriVizitate == nrNoduri){
                nrSolutiiGasite++;
            }
            free(vizitat);
        }
        if (nrSolutiiGasite == 0){
            printf("Nu");
//            fprintf(fileOut,"Nu");
        }else{
            printf("%d",nrSolutiiGasite);
//            fprintf(fileOut,"%d",nrSolutiiGasite);
        }
        free(matriceAdiacenta);
        nrTeste--;
        if (nrTeste > 0) {
            printf("\n");
//            fprintf(fileOut,"\n");
        }
    }
//    fclose(fileOut)
    fclose(fileIn);
    return 0;
}

