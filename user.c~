#include "project1.h"



int rankcount (FILE *ford, int *Ord)
{
	char *a, b[5], Index;
	int rank=0, i, j,k=1000;

	a = (char *) malloc(k * sizeof(char));
	while (!feof(ford))
	{
		bzero(a, k);
		fgets (a, k, ford);
		for (i=0; a[i] != NULL; i++)	
		{
			if (a[i] == '(')		
			{
				j = 0;
				i++;
				do
				{
					b[j] = a[i];
					i++; j++;
				} while (a[i] != ')');
				b[j] = NULL;
				Index = atoi(b);
				Ord[Index] = rank;		
				rank++; 
			}
		}
	}
	
return rank;
}


int CreateBdd (NODE *graph, int Max, DdManager *manager, int rank, int *Ord)
{
	DdNode *Temp01, *Temp02;		
	int id, i,inputSeq=0, *inputIndx,countBdd = 0;				
        LIST *temp;	
	

	inputIndx = (int *) malloc(Mpi * sizeof(int));
        
     

	
	for (i =0; i <= Max; i++)		
		if (graph[i].typ == 1)
		{
			inputIndx [inputSeq] = i;printf("inputIndx [%d] = %d\n",inputSeq,i);
			inputSeq++;
                 
		}

for (inputSeq = 0; inputSeq < rank; inputSeq++)		
	{
		for (i = 0; i < rank  ; i++)
                   
		{ 
                         //printf("BDD inputIndx[%d].bdd \n",i);
			if (Ord[i] == inputSeq)
			{
				
				graph[inputIndx[i]].bdd = Cudd_bddIthVar(manager, inputSeq);		Cudd_Ref(graph[inputIndx[i]].bdd);
                                printf("BDD inputIndx[%d].bdd \n",i); Cudd_PrintMinterm(manager,graph[inputIndx[i]].bdd);
				countBdd++;
			}
		}
	}

for (id=1; id<=Max; id++)
	{	
		switch (graph[id].typ)
		{

			case 0	   : 	printf ("%d\n",graph[id].typ );break;

			case INPT     : 	printf ("%d\n",id);break;
					

			case AND   :	printf ("%d\n",id);temp = graph[id].fin;			
					Temp01 = Cudd_ReadOne(manager);	Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);						

						temp = temp->nxt;
						
											
					}
                                        Cudd_PrintMinterm(manager,Temp01);
					graph[id].bdd = Temp01;		Cudd_Ref(graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					break;

			case NAND   :	printf ("%d\n",id);
					temp = graph[id].fin;					
					Temp01 = Cudd_ReadOne(manager);	Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);
						
						temp = temp->nxt;	
						
									
					}
                                        
					graph[id].bdd = Cudd_Not(Temp01);		Cudd_Ref(graph[id].bdd);
					Cudd_PrintMinterm(manager,graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					
					break;

			case OR    :	printf ("%d\n",id);
					temp = graph[id].fin;
					Temp01 = Cudd_ReadLogicZero(manager);	Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);						

						temp = temp->nxt;
						
											
					}
                                        
					graph[id].bdd = Temp01;		Cudd_Ref(graph[id].bdd);
					Cudd_PrintMinterm(manager,graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					break;

			case NOR   :	printf ("%d\n",id);
					temp = graph[id].fin;
					Temp01 = Cudd_ReadLogicZero(manager);	Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);						

						temp = temp->nxt;
						
						
					}
                                       
					graph[id].bdd = Cudd_Not(Temp01);		Cudd_Ref(graph[id].bdd);
                                        Cudd_PrintMinterm(manager,graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					break;

			case XOR   :	printf ("%d\n",id );
					temp = graph[id].fin;
					
					
					Temp01 = Cudd_ReadLogicZero (manager);		Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);						

						temp = temp->nxt;					
					}
                                       
					graph[id].bdd = Temp01;		Cudd_Ref(graph[id].bdd);
                                        Cudd_PrintMinterm(manager,graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					break;

			case XNOR :	printf ("%d\n",id);
					temp = graph[id].fin;
					
					Temp01 = Cudd_ReadLogicZero (manager);		Cudd_Ref(Temp01);
					while (temp!=NULL)			
					{						
						Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);
						
						Cudd_RecursiveDeref (manager, Temp01);
						Temp01 = Temp02;		Cudd_Ref(Temp01);
						Cudd_RecursiveDeref (manager, Temp02);						

						temp = temp->nxt;					
					}
                                       
					graph[id].bdd = Cudd_Not(Temp01);		Cudd_Ref(graph[id].bdd);
                                        Cudd_PrintMinterm(manager,graph[id].bdd);
					
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp01);
					break;

			case BUFF  :	printf ("%d\n",id);
					graph[id].bdd = graph[graph[id].fin->id].bdd; 	Cudd_Ref(graph[id].bdd);
                                        Cudd_PrintMinterm(manager,graph[id].bdd);	
					
					countBdd++;
					break;

			case NOT   : 	printf ("%d\n",id);Temp02 = graph[graph[id].fin->id].bdd;	Cudd_Ref(Temp02);
					graph[id].bdd = Cudd_Not (Temp02);		Cudd_Ref(graph[id].bdd);	
					
					Cudd_PrintMinterm(manager,graph[id].bdd);
					countBdd++;
					Cudd_RecursiveDeref (manager, Temp02);
					break;
					
			case FROM  :	printf ("%d\n",id);
                                        graph[id].bdd = graph[graph[id].fin->id].bdd; 	Cudd_Ref(graph[id].bdd);	
					
                                        Cudd_PrintMinterm(manager,graph[id].bdd);
					countBdd++;
					break;
		}		
	}


return countBdd;
}

void CheckFaultWithBdd (NODE *graph, DdManager *manager, int Max, int Npi, FILE *fres,int Stnode, int Stfault)
{
	int id;

	if (Stnode == 0)				// Check all Faults for All NODES
		for (id = 1; id <= Max; id++)
		{ FaultyBdd (graph, manager, Max, Npi,fres, id, Stfault);}
				
			
		
	else						// Check fault at a particular node
	{
		
          FaultyBdd (graph, manager, Max, Npi,fres, Stnode, Stfault);
	}

return;
}

void FaultyBdd (NODE *graph, DdManager *manager, int Max, int Npi, FILE *fres,int id, int Stfault)
{
	DdNode *Temp01, *Temp02;			
	DdNode *orBddTmp, *orBdd;			
	int i,flag=0;			
	LIST *temp;
	
	
	for (i = 0; i<=Max; i++)		// clear mark
		graph[i].mar = 0;

	if (Stfault == 0)			// inject fault	0
	{ 
		graph[id].fbdd = Cudd_ReadLogicZero(manager);		Cudd_Ref(graph[id].fbdd);
		
					
	}
	else if (Stfault == 1)			// inject fault	1
	{ 
		graph[id].fbdd = Cudd_ReadOne(manager);		Cudd_Ref(graph[id].fbdd);
					
	}
		
	graph[id].mar = 1;			// update mark
	
	if (id < Max)
	{
		for (i = id+1; i<=Max; i++)
		{
			switch (graph[i].typ)
			{
				case 0	   : break;	
						
	
				case INPT  : break;	
						
	
				case AND   :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadOne(manager);	Cudd_Ref(Temp01);
						while (temp!=NULL)			
						{						
							if (graph[temp->id].mar == 0)	
								{ flag=1; Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else 
								{ Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}
							
							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);						
	
							temp = temp->nxt;					
						}
						if (flag==1)
                                                graph[i].fbdd = Temp01;		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
                                                if (flag==1)
						{graph[i].mar = 1; flag=0;}			// update mark
						Cudd_RecursiveDeref (manager, Temp01);
						break;

				case NAND  :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadOne(manager);	Cudd_Ref(Temp01);
						while (temp!=NULL)			
						{					
                                                       
							if (graph[temp->id].mar == 0)
								{  Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else
								{ flag=1;Temp02 = Cudd_bddAnd(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}

							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);	

												
	
							temp = temp->nxt;					
						}
						graph[i].fbdd = Cudd_Not(Temp01);		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp01);
						
						break;
	
				case OR    :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadLogicZero(manager);	Cudd_Ref(Temp01);
						while (temp!=NULL)			
						{						
							if (graph[temp->id].mar == 0)
								{ Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else
								{ flag=1;Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}
							
							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);						
	
							temp = temp->nxt;					
						}
						graph[i].fbdd = Temp01;		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp01);
						break;
	
				case NOR   :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadLogicZero(manager);	Cudd_Ref(Temp01);
						while (temp!=NULL)			
						{					
							if (graph[temp->id].mar == 0)	
								{ Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else
								{ flag=1;Temp02 = Cudd_bddOr(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}
							
							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);						
	
							temp = temp->nxt;					
						}
						graph[i].fbdd = Cudd_Not(Temp01);		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp01);
						break;
	
				case XOR   :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadLogicZero (manager);		Cudd_Ref(Temp01);
					
						

						while (temp!=NULL)			
						{						
							if (graph[temp->id].mar == 0)
								{ Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else
								{ flag=1;Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}
							
							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);						
	
							temp = temp->nxt;					
						}
						graph[i].fbdd = Temp01;		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp01);
						break;
	
				case XNOR  :	printf ("%d\n",i );temp = graph[i].fin;
						Temp01 = Cudd_ReadLogicZero (manager);		Cudd_Ref(Temp01);


						while (temp!=NULL)			
						{					
							if (graph[temp->id].mar == 0)
								{ Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].bdd);	Cudd_Ref(Temp02);}
							else
								{ flag=1;Temp02 = Cudd_bddXor(manager, Temp01, graph[temp->id].fbdd);	Cudd_Ref(Temp02);}
							
							Cudd_RecursiveDeref (manager, Temp01);
							Temp01 = Temp02;		Cudd_Ref(Temp01);
							Cudd_RecursiveDeref (manager, Temp02);						
	
							temp = temp->nxt;					
						}
						graph[i].fbdd = Cudd_Not(Temp01);		Cudd_Ref(graph[i].fbdd);
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp01);
						break;

				case BUFF  :	printf ("%d\n",i );if (graph[graph[i].fin->id].mar == 0)
							{ graph[i].fbdd = graph[graph[i].fin->id].bdd; 	Cudd_Ref(graph[i].fbdd);	}
						else
						{ 
							flag=1;graph[i].fbdd = graph[graph[i].fin->id].fbdd; 	Cudd_Ref(graph[i].fbdd); 
						}
							Cudd_PrintMinterm(manager,graph[i].fbdd);
							if (flag==1)
						{graph[i].mar = 1; flag=0;}						
						break;
	
				case NOT   : 	printf ("%d\n",i );if (graph[graph[i].fin->id].mar == 0)
							{ Temp02 = graph[graph[i].fin->id].bdd;	Cudd_Ref(Temp02);}
						else 
							{ flag=1;Temp02 = graph[graph[i].fin->id].fbdd;	Cudd_Ref(Temp02);}
						graph[i].fbdd = Cudd_Not (Temp02);		Cudd_Ref(graph[i].fbdd);		
						Cudd_PrintMinterm(manager,graph[i].fbdd);
						 if (flag==1)
						{graph[i].mar = 1; flag=0;}
						Cudd_RecursiveDeref (manager, Temp02);
						break;
						
				case FROM  :	printf ("%d\n",i );if (graph[graph[i].fin->id].mar == 0)
							{ graph[i].fbdd = graph[graph[i].fin->id].bdd; 	Cudd_Ref(graph[i].fbdd);	}
						else
						{	
							flag=1; graph[i].fbdd = graph[graph[i].fin->id].fbdd; 	Cudd_Ref(graph[i].fbdd);
						}
							Cudd_PrintMinterm(manager,graph[i].fbdd);
							 if (flag==1)
						{graph[i].mar = 1; flag=0;}						
						break;
			}		
		}
	}
              
                   CheckFaultyBdd (graph, Max, manager); 	
		
		// Calculate Total Meanterm by ORing all the xrbdd's of the CKT o/p
		orBdd = Cudd_ReadLogicZero(manager);	Cudd_Ref(orBdd);
		for (i = 1; i <= Max; i++)
			if (graph[i].po == 1 && graph[i].mar == 1)
			{
				orBddTmp = Cudd_bddOr(manager, orBdd, graph[i].xrbdd);	Cudd_Ref(orBddTmp);
				Cudd_RecursiveDeref (manager, orBdd);
				orBdd = orBddTmp;		Cudd_Ref(orBdd);
				Cudd_RecursiveDeref (manager, orBddTmp);				
			}

		// Print Faults for each primary o/p
		for (i = 1; i <= Max; i++)
			if (graph[i].po == 1 && graph[i].mar == 1 && Cudd_CountMinterm(manager, graph[i].xrbdd, (Npi)) != 0)
			{
				fprintf(fres, "\nStnode:%d Stuckat:%d Detected at PO: %d has %.0f Ms", id, Stfault, i, Cudd_CountMinterm(manager, graph[i].xrbdd, (Npi)));
				printf("\nStnode:%d Stuckat:%d Detected at PO: %d has %.0f Ms\n", id, Stfault, i, Cudd_CountMinterm(manager, graph[i].xrbdd, (Npi)));
                                  Cudd_PrintMinterm(manager,graph[i].xrbdd);
				FormFirstCuBe (manager, graph, i, id, Stfault, fres); 
			}
		// Print faults Combined
		if (Cudd_CountMinterm(manager, orBdd, (Npi)) != 0)
		{
			fprintf(fres, "\nStnode:%d Stuckat:%d Detected by %.0f Ms", id, Stfault, Cudd_CountMinterm(manager, orBdd, (Npi)));
			printf("\nStnode:%d Stuckat:%d Detected by %.0f Ms\n", id, Stfault, Cudd_CountMinterm(manager, orBdd, (Npi)));
                                   
		}
			

		Cudd_RecursiveDeref (manager, orBdd);		

		
return ;
}
void CheckFaultyBdd (NODE *graph, int Max, DdManager *manager)
{
	int id;

	for (id = 1; id <= Max; id++)
	{	
		if (graph[id].po == 1 && graph[id].mar == 1)		
		{
			graph[id].xrbdd = Cudd_bddXor(manager, graph[id].bdd, graph[id].fbdd);	Cudd_Ref(graph[id].xrbdd);
			
		}
	}

return;
}


