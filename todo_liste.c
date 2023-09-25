#include<stdio.h>
#include<time.h>
#include<string.h>

  typedef struct{//utulisation des memes nom pour mieux comprandre
         int identifiant;
         char titre[100];
         char description [100];
         int jeur,mois,annee;
         char statu[100];

  }liste;
     liste tach[100];
     int N,nb,i,j,a,b,c,choix;
     int total=0;


          void saisier(int nb){
          	
                  int i,type_statu;
                   for(i = total ; i < nb + total ; i++){
                            tach[i].identifiant=i+1;
	             printf("\n");
                 printf("donner un titre de  tache : ");
                 scanf(" %[^\n]",tach[i].titre);
                 printf("donner le description de tache : ");
                 scanf(" %[^\n]",tach[i].description);
                 printf("donner la date limite(jj/mm/aaaa):");
                 scanf (" %d%d%d", &tach[i].jeur, &tach[i].mois, &tach[i].annee);
                 printf("donner le statu de la tache:\n ");
                   printf("#--******--#\n");
                   printf("|1: todo   |\n");
                   printf("|2: doing  |\n");
                   printf("|3: done   |\n");
                   printf("#--******--#\n");
                scanf("%d",&type_statu);
                switch(type_statu){
				case 1 :
					strcpy(tach[i].statu,"to Do");
					break;
				case 2 :
				    strcpy(tach[i].statu,"Doing");
					break;	
				case 3 :
					strcpy(tach[i].statu,"done");
					break;
			    	default :
						printf("statu non valide");
					break;
				}
				
                 }
                  total += nb;
          }
          
void	supprimer(){
	int	id, cher;
	
	printf("Enter the id\n");
	scanf("%d", &id);
	
	for(cher = 0;cher < total; cher++)
	{
		if(id == tach[cher].identifiant)
		{
			tach[cher].identifiant = -1;
			
			return;
		}
	}
}
int	recherch_ID(int id){
	int i;
    for (i = 0; i < total; i++) {
        if (tach[i].identifiant == id)
            return (i);
    }
    return (-1);    
}
int  recherch_titre(char titre[] ){
	int i;
    for (i = 0; i < total; i++) {
        if (tach[i].titre == titre)
            return (i);
    }
    return (-1);
}
 void modifier(){
           	    int id  , indice;
           		char desc[100],le_statu[100];
           		printf("entre id:");
           		scanf("%d",&id);
           	    int	choix,a,m,j;	
                      printf("Choiser le type de définition de tache!\n");
		              printf("#--------**************************------#\n");
                      printf("|1:Modifier la description d'une tache:  |\n");
                      printf("|2:Modifier le status d'une tache:       |\n");
                      printf("|3:Modifier le deadline d'une tache:     |\n");
		              printf("#--------**************************------#\n");
		              printf("donner un nombre :");
		              scanf("%d",&choix);
					  switch(choix){
					  	case 1 :
					  		indice = recherch_ID(id);
					  		if (indice != -1) {
					  			printf("donner la discription qui tu veux modifier:");
					  			scanf(" %s",desc);
					  			strcpy(tach[indice].description, desc);
					  		}
					  		break;
					  	case 2 :
						    indice =recherch_ID(id);
						    if (indice != -1) {
					  			printf("donner le statu qui tu veux modifier:");
					  			scanf(" %s",le_statu);
					  			strcpy(tach[indice].statu, le_statu);
							}
								break;
					  }
      }
 void rechercher(){
		     char nauv_titre[20];
		     int id;
                      printf("Choiser le type de recherche des tacge!\n");
		              printf("#-----******************************---------#\n");
                      printf("|1:rechercher une tache par son identifiant  |\n");
                      printf("|2:Rechercher une tache par son titre:       |\n");
		              printf("#------*****************************---------#\n");
		              printf("enter your choice : "); 
		              scanf("%d",&choix);
	     switch(choix){
		      case 1 :printf("donner l'identifiant de tache:");
			      scanf("%d",&id);
			      recherch_ID(id);
			      break;
		      case 2 :printf("Entrez le titre de la tâche à rechercher: ");
			      scanf(" %[^\n]",nauv_titre);
			      recherch_titre(nauv_titre);
		    }
	     }
          
void alpha(){
 	int i,j;
 	liste temp;
    for (i = 0; i < total-1 ; i++) {
        for (j = 0; j < total - i - 1; j++) {
            if (strcasecmp(tach[j].titre, tach[j + 1].titre) > 0 && (tach[j].identifiant != -1 || tach[j + 1].identifiant != -1)) {
                temp = tach[j + 1];
                tach[j + 1] = tach[j];
                tach[j] = temp;
            }
        }
    }
}

void affichage(){
	    int i;
		  printf("#----#----------------------#-------------------#------------------#------------#\n");
	      printf("| ID |    Nom de la t�che   |    Description    |  Date d'�ch�ance |     Statut |\n");
	      printf("#----#----------------------#-------------------#------------------#------------#\n");
	        for ( i = 0 ; i < total  ; i++){
	        	if (tach[i].identifiant != -1)
					printf("| %-2d | %-19s | %-22s | %02d/%02d/%04d | %-15s |\n",tach[i].identifiant, tach[i].titre, tach[i].description, 
					tach[i].jeur, tach[i].mois,tach[i].annee,tach[i].statu);
	  }
	  printf("\n");
}


void afficher(){
          	int choix;
                 
		          printf("#----**************************MENU**************************-----#\n");
                  printf("|1:les tache en tries par ordre alphabitique!                     |\n");
                  printf("|2:les tache en tries par deadline!                               |\n");
                  printf("|3:Afficher les tâches dont le deadline est dans 3 jours ou moins|\n");
		          printf("#----*********************************************************----#\n");
		          printf("Choisissez l’ordre de l’affichage!\n");
                  scanf("%d",&choix);
          switch(choix){
                 case 1 :

						 affichage();
                 		break;
                  case 2 :printf("deadlin\n");
                  		break;
                  case 3 :printf("dedlin modifier par 3 jeur\n");
                        break;
          }
}
 void statistiques(){
 	     int choix_statu;
 	     	int i;
		 	int n_iga ,n_origa;
         printf("Choiser le type de statistique quintu veux:\n");
		 printf("#--------**************************************************------------#\n");
         printf("|1:Afficher le nombre total des taches                                 |\n");
         printf("|2:Afficher le nombre de tache complite et incomplte :                 |\n");
         printf("|3:Afficher le nombre de jours restants jusquau délai de chaque tache:|\n");
		 printf("#-------***************************************************------------#\n");
		 printf("choisier votre choix: ");
		 scanf("%d",&choix_statu);
		 switch(choix_statu){
		 	case 1 :
		 		printf("le nombre totatest: %d\n",total);
		 		break;
		 	case 2 :
		 	
		 	/*	for(i=0 ; i < total ; i++){
		 		   if(strcmp(tach[i].statu,"done")==0 || strcmp(tach[i].statu,"done")==0 || (tach[i].statu,"done")==0 && tach[i].identifiant>0){
		 		   	   n_iga=n_iga+1;
					}
						for(i=0 ; i < total ; i++){
		 		   if(strcmp(tach[i].statu,"done")==0 || strcmp(tach[i].statu,"done")==0 || (tach[i].statu,"done")==0 && tach[i].identifiant>0){
		 		   	   n_origa = n_origa+1;
						   }
						   }
						   printf("nombre des tache complaite est : %d",n_iga);
						   printf("nombre des tache incomplite est: %d",n_origa);:
		 		break;*/
		 	case 3 :
		 		break;
		 		default :
		 			break;	
		 }
	     }
	 
          
          
          int main(){
          	int choix;
          	while(1){
        printf("#------------       Liste ToDo       ------------# \n");
        printf("|   1:Ajouter une nouvelle tache:                |\n");
        printf("|   2:Ajouter plusier nouvelles tache:           |\n");
        printf("|   3:Aficher la liste de toutes les tache:      |\n");
        printf("|   4:Modifier une tache:                        |\n");
        printf("|   5:Supprimer une tache par identifiant:       |\n");
        printf("|   6:Rechercher les taches:                     |\n");
        printf("|   7:Statistiques:                              |\n");
        printf("|   0:puor queté le programe:                   |\n");
	    printf("#------------------------------------------------#\n");
        printf("\n");
			printf("donner un nombre ");
          	scanf("%d",&choix);
          	switch(choix){
          	case 0 :return 0;	
          	case 1 : saisier(1);
          	        break;
          	case 2 :printf("donner le nombre de r�pition: "); 
			        scanf("%d",&nb);
			         saisier(nb);
					 break; 
					  
			case 3 : 
					alpha();
					afficher(); 
					break;
			case 4 : 
			         modifier();
                     break;
			case 5:
				if (total != 0)
				{
					supprimer();
			     	afficher();
          		}
          		     break;
			case 6 :
			        rechercher();
			         break;
			case 7 :
				    statistiques();
				     break;
				
		  }
	  }
	return 0;
}
	
          
          
          
          
          
          
          
          
          
          
          
          
          
          
