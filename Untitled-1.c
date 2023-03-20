#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>



typedef struct personne
{
    char nom[20], prenom[20], numero[8];
} personne;

personne Saisirpers()
{ 
    personne p;
    printf("               -- Veuillez saisir le nom du contact : \n ");
    scanf("%s", p.nom);
    printf("               -- Veuillez saisir le prenom du contact : \n ");
    scanf("%s", p.prenom);
    printf("	    -- Veuillez introduire le numero du telephone du contact : \n ");
    scanf("%s", p.numero);
    printf("			   -- Ce contact est crée \n\n ");
    return p;
}

void saisirrep(personne *repertoire, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        *(repertoire + i) = Saisirpers();
        getch();
       system("cls");
    }
}

void afficherep(personne *repertoire, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        
        printf(" \n -- contact num (%d) :\n -- nom : %s \n -- prenom : %s \n -- numero tel : %s \n ", i + 1, ((repertoire + i)->nom), ((repertoire + i)->prenom), ((repertoire + i)->numero));
    }
}
void recherchercontact(personne *repertoire, int taille)
{
    char n[20];
    // personne_est_trouve est un booleen
    int personne_est_trouve = 0; // c a d initilisé a "False"
    printf("              --   Donner le nom a chercher : \n ");
    scanf("%s", n);
    int i = 0;
    while (i < taille && personne_est_trouve == 0)
    {
        if (strcmp(n, ((repertoire + i)->nom)) == 0) // c'est a dire le personne est trouvé
        {
            personne_est_trouve = 1;
            printf(" \n	   --	personne trouve      !                         								!\n");
            printf(" \n contact num (%d) :\n nom : %s \n prenom : %s \n numero tel : %s \n ", i + 1, ((repertoire + i)->nom), ((repertoire + i)->prenom), ((repertoire + i)->numero));
            break;
        }
        else
        {
            i++;
        }
    }

    if (personne_est_trouve == 0)
    {
        printf("        -- contact non trouve !  \n ");
    }
}

void supprimer_contact(personne repertoire[],int *taille )
{
    char nom[5];
       printf("nom de contact a suprimer : \n");
scanf("%s", nom);

for(int i=0;i<*taille;i++)
{
    if(strcmp(repertoire[i].nom,nom)==0)
    {
    for(int j=i;j<*taille;j++)
    {
        repertoire[i]=repertoire[i+1];
    }
    *taille=*taille-1;
    }
    
}
}


    
int main()
{
     int taille,choice,nb;
    personne *repertoire = NULL;
    
    repertoire = (personne *)malloc(sizeof(personne) * taille);
	
    printf("                    -- donner la taille de votre repertoire : \n");
    scanf("%d", &taille);
    saisirrep(repertoire,taille);

 
  do
  {

  	
	  
  
 
    printf("\n\n\n\t  1 :   Add contacts \n");
    printf("\t  2 :   Delete contact \n");
    printf("\t  3 :   Show contacts \n");
    printf("\t  4 :   Search contacts \n");
    printf("\t  5 :   Exit \n\n\n\n");

    printf("Votre choix : ");
    scanf("%d", &choice);

    switch (choice)
    {	
     case 1: taille++;
   
    printf("		-- Saisir le nom de contact : ");
    
    scanf("%s",repertoire[taille-1].nom);
    printf("\n 	   -- Saisir le prenom de contact : ");
     scanf("%s",repertoire[taille-1].prenom);
    printf("\n 	   -- Saisir le numero de contact : ");
     scanf("%s",repertoire[taille-1].numero);
    break;
      
    case 2:
       supprimer_contact(repertoire,&taille);
      break;
    case 3:
      afficherep(repertoire, taille);
      break;
    case 4:
      
     recherchercontact(repertoire, taille);
    case 5:
       afficherep(repertoire,taille);
      break;
    }
       
}
while(choice !=5);
}
  
