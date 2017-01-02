#include "project1.h"
/***************************************************************************************************************************
  Main Function(ATPG for Single Stuckat Faults)
****************************************************************************************************************************/
void main(int argc,char **argv)
{
FILE *fisc,*ford,*fres;                    //file pointers for reading Isc file, ord file and output file
int Max,Opt,Stnode,Sfault,Npi,Npo,*Ord, Cur, rank;    //(maxnode id,option,stuckatnode,faultvalue,tot nof PIs,tot nof Pos,orderArray)
NODE *graph;                               //structure used to stored the ckt information 
int a,b,c,d,i,j;  
int countBdd;                             //random variables

Max=Opt=Stnode=Sfault=Npi=Npo=a=b=c=d=-1;   //intiazializion of integer values

//demo functions used to show how to given functions work
 // DemoList("demo.txt"); //for LIST


//Read the .isc file and store the information in graph structure
fisc=fopen(argv[1],"r");                                       //file pointer to open isc file 
graph=(NODE *) malloc(Mnod * sizeof(NODE));                    //dynamic memory allocation for graph structure
Max=0; Max=ReadIsc(fisc,graph);                                //read isc file and return index of last node formed
fclose(fisc);                                                  //close file pointer for isc file
PrintCircuit(graph,Max);                                       //print all members of graph
manager=Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0);  //intializing CUDD package manger	

//Read the .ord file and store the information in Ord array
ford=fopen(argv[2],"r"); 
fres=fopen(argv[3],"w");                         		//file pointer to open .out file for printing results

Ord=(int *) malloc(Mpi * sizeof(int));                 	//dynamic memory allocation for Ord array
rank = rankcount(ford, Ord);    
printf ("rank is %d\n",rank);        
for (i=0;i<rank;i++)
 {
   for (j=0;j<rank;j++)
   {
       if (Ord[j]==i){
             printf ("Ord[%d]= %d\n", j, i); 
                     }
   }
 }
//free(Ord);		//clear memeory for Ord array

countBdd = CreateBdd ( graph, Max, manager, rank, Ord);

printf("counbdd %d\n",countBdd  );
//printf(" %d\n",Max );

Stnode= atoi(argv[4]);
Sfault= atoi(argv[5]);
CheckFaultWithBdd (graph, manager, Max, rank,fres,Stnode,Sfault);
//demo functions used to show how to given functions work
//DemoBdd(manager);     //bdd example
printf("\nNo of Unreferenced Bdds %d\n", Cudd_CheckZeroRef(manager)); //checking any unreferenced bdds in manager
Cudd_Quit(manager);                                           //closing the cudd package manager

ClearCircuit(graph,Mnod);                                     //clear memeory for all members of graph
return;
}//end of main
/****************************************************************************************************************************/


