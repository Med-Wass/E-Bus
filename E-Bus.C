#include<stdio.h>
#include <stdlib.h>
#define cmax1 50
#define max_capacite 100
#define cmax3 8

struct Personne
{
    char nom[cmax1];
    char adresse[cmax1];
    char cin[cmax3];
    int age;
    char num_Tel[cmax3];
};
struct Date
{
    int jour;
    int mois;
    int annee;
};

struct Bus
{
    int id_bus;
    char modele[cmax1];
    int capacite;
};
struct Chauffeur
{
    int num_chauffeur;
    struct Personne Personne;

};
struct Itineraire
{
    int id_itineraire;
    char depart[cmax1];
    char arrivee[cmax1];
};
struct Voyage 
{
    int id_voyage;
    int id_bus;
    int id_itineraire;
    int num_chauffeur;
    struct Date date_voyage;
    int nbr_reservations;
   
    
};
struct Reservation
{
    int id_reservation;
    struct Personne voyageur;
    struct Date date_reservation;
    int id_voyage;
    int paye;

};





void ajouterChauffeur(struct Chauffeur *chauffeurs) {
    struct Chauffeur nouveauChauffeur;

    printf("Nom du chauffeur : ");
    scanf("%s", nouveauChauffeur.Personne.nom);

    printf("Adresse du chauffeur : ");
    scanf("%s", nouveauChauffeur.Personne.adresse);
    printf("CIN du chauffeur : ");
    scanf("%s", nouveauChauffeur.Personne.cin);

    printf("Age du chauffeur : ");
    scanf("%d", &nouveauChauffeur.Personne.age);

    printf("Numéro de téléphone du chauffeur : ");
    scanf("%s", nouveauChauffeur.Personne.num_Tel);

    printf("Numéro du chauffeur : ");
    scanf("%d", &nouveauChauffeur.num_chauffeur);
    FILE *file = fopen("Chauffeurs.txt", "a"); // Ouvre le fichier en mode ajout (append)
        if (file != NULL) {
            fprintf(file, "%s %s %s %d %s %d\n",  nouveauChauffeur.Personne.nom,
                    nouveauChauffeur.Personne.adresse, nouveauChauffeur.Personne.cin,
                    nouveauChauffeur.Personne.age, nouveauChauffeur.Personne.num_Tel,
                    nouveauChauffeur.num_chauffeur);
            fclose(file);

           
        } else {
            printf("Erreur lors de l'ouverture du fichier 'chauffeurs.txt'.\n");
        }

    printf("Chauffeur ajouté avec succès!\n");
}

void afficherChauffeur(struct Chauffeur chauffeur) {
    printf("Nom : %s\n", chauffeur.Personne.nom);
    printf("Adresse : %s\n", chauffeur.Personne.adresse);
    printf("Age : %d\n", chauffeur.Personne.age);
    printf("Numéro de téléphone : %s\n", chauffeur.Personne.num_Tel);
    printf("Cin: %s\n",chauffeur.Personne.cin);
    printf("Numéro du chauffeur : %d\n", chauffeur.num_chauffeur);
    printf("\n");
}



void ajouterBus(){
    struct Bus nouveauBus;
    printf("donner id_bus  :");
    scanf("%d",&nouveauBus.id_bus);
    printf("donner le modele de bus   :");
    scanf("%s",nouveauBus.modele);
    printf("donner la capacité de bus  :");
    scanf("%d",&nouveauBus.capacite);
    FILE *file=fopen("bus.txt","a");
    if (file!=NULL){
    fprintf(file,"%d %s %d",nouveauBus.id_bus,nouveauBus.modele,nouveauBus.capacite);
    fclose(file);
     printf("Bus ajouté avec succès!\n");
    }
    else{
        printf("Erreur lors de l'ouverture du fichier 'Bus.txt'.\n");
    }
}
void ajouterItineraire(){
    struct Itineraire nouveauItinaraire;
    
    printf("donner id_itineraire :");
    scanf("%d",&nouveauItinaraire.id_itineraire);
    printf("donner le lieu de départ:");
    scanf("%s",nouveauItinaraire.depart);
    printf("donner le lieu de arrivee :");
    scanf("%s",nouveauItinaraire.arrivee);
    FILE *file=fopen("itineraire.txt","a");
    fprintf(file,"%d %s %s",nouveauItinaraire.id_itineraire,nouveauItinaraire.depart,nouveauItinaraire.arrivee);
    fclose(file);
    printf("itineraire ajouté avec succès!\n");
}
struct Bus verifierDisponibiliteBus(int idBus) {
    FILE *fichier = fopen("bus.txt", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'bus.txt'");
        exit(EXIT_FAILURE);
    }

    struct Bus bus;

    while (fscanf(fichier, "%d %s %d", &bus.id_bus, bus.modele, &bus.capacite) != EOF) {
        if (bus.id_bus == idBus) {
            fclose(fichier);
            return bus; // Retourne le bus correspondant à l'ID
        }
    }

    fclose(fichier);

    // Si l'ID n'est pas trouvé, initialise un bus avec un ID invalide (-1)
    bus.id_bus = -1;
    return bus; // L'id_bus est disponible
}
struct Voyage verifierDisponibiliteVoyage(int id_voyage){
    FILE *fichier = fopen("voyage.txt", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'voyage.txt'");
        exit(EXIT_FAILURE);
    }

    struct Voyage nouveauVoyage;

    while (fscanf(fichier, "%d %d %d %d %d %d %d %d", &nouveauVoyage.id_voyage,&nouveauVoyage.id_bus,&nouveauVoyage.id_itineraire,&nouveauVoyage.num_chauffeur
        ,&nouveauVoyage.date_voyage.jour,&nouveauVoyage.date_voyage.mois,&nouveauVoyage.date_voyage.annee,&nouveauVoyage.nbr_reservations) != EOF) {
        if (nouveauVoyage.id_voyage == id_voyage) {
            fclose(fichier);
            return nouveauVoyage; // Retourne le bus correspondant à l'ID
        }
    }

    fclose(fichier);

    // Si l'ID n'est pas trouvé, initialise un bus avec un ID invalide (-1)
    nouveauVoyage.id_voyage = -1;
    return nouveauVoyage;
}
struct Chauffeur verifierDisponibiliteChauffeur(int num_chauffeur){
    FILE *fichier = fopen("Chauffeurs.txt", "r");
   

    if (fichier== NULL) {
        perror("Erreur lors de l'ouverture du fichier 'Chauffeurs.txt'");
        exit(EXIT_FAILURE);
    }

    struct Chauffeur nouveauChauffeur;

    while (fscanf(fichier, "%s %s %s %d %s %d", nouveauChauffeur.Personne.nom,
                    nouveauChauffeur.Personne.adresse, nouveauChauffeur.Personne.cin,
                    &nouveauChauffeur.Personne.age, nouveauChauffeur.Personne.num_Tel,
                    &nouveauChauffeur.num_chauffeur) != EOF) {
        if (nouveauChauffeur.num_chauffeur == num_chauffeur) {
            fclose(fichier);
            return nouveauChauffeur; // Retourne le bus correspondant à l'ID
        }
    }

    fclose(fichier);

    // Si l'ID n'est pas trouvé, initialise un bus avec un ID invalide (-1)
    nouveauChauffeur.num_chauffeur = -1;
    return nouveauChauffeur; 
}
struct Itineraire verifierDisponibiliteItineraires(int id_itineraire) {
    FILE *fichier = fopen("itineraire.txt", "r");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'itineraire.txt'");
        exit(EXIT_FAILURE);
    }

    struct Itineraire itineraire;

    while (fscanf(fichier, "%d %s %s", &itineraire.id_itineraire, itineraire.depart, itineraire.arrivee) != EOF) {
        if (itineraire.id_itineraire == id_itineraire) {
            fclose(fichier);
            return itineraire; // Retourne le bus correspondant à l'ID
        }
    }

    fclose(fichier);

    // Si l'ID n'est pas trouvé, initialise un bus avec un ID invalide (-1)
    itineraire.id_itineraire = -1;
    return itineraire; 
}
void ajouterVoyage()
{  


    struct Voyage nouveauVoyage;
    struct Bus bus;
    struct Itineraire itineraire;
    struct Chauffeur chauffeur;
    printf("donner Id Voyage");
    scanf("%d",&nouveauVoyage.id_voyage);
   
    
       do {
        printf("Donner Id Chauffeur : ");
        scanf("%d", &nouveauVoyage.num_chauffeur);

        // Récupère les informations du bus depuis le fichier "bus.txt"
        chauffeur = verifierDisponibiliteChauffeur(nouveauVoyage.num_chauffeur);

        // Vérifie si le bus existe
        if (chauffeur.num_chauffeur == -1) {
            printf("Cet ID de bus n'existe pas. Veuillez choisir un autre.\n");
        }

    } while (chauffeur.num_chauffeur == -1);

    do {
        printf("Donner Id Bus : ");
        scanf("%d", &nouveauVoyage.id_bus);

        // Récupère les informations du bus depuis le fichier "bus.txt"
        bus = verifierDisponibiliteBus(nouveauVoyage.id_bus);

        // Vérifie si le bus existe
        if (bus.id_bus == -1) {
            printf("Cet ID de bus n'existe pas. Veuillez choisir un autre.\n");
        }

    } while (bus.id_bus == -1);
    
    do {
        printf("donner Id Iteneraire  :");
    scanf("%d",&nouveauVoyage.id_itineraire);

        // Récupère les informations du bus depuis le fichier "itineraire.txt"
        itineraire = verifierDisponibiliteItineraires(nouveauVoyage.id_itineraire);

        // Vérifie si le bus existe
        if (itineraire.id_itineraire == -1) {
            printf("Cet ID d'itineraire n'existe pas. Veuillez choisir un autre.\n");
        }

    } while (itineraire.id_itineraire == -1);
    nouveauVoyage.nbr_reservations=0;
    
    
    printf("donner le jour du voyage   :");
    scanf("%d",&nouveauVoyage.date_voyage.jour);
    printf("donner le mois du voyage  :");
    scanf("%d",&nouveauVoyage.date_voyage.mois);
    printf("donner l'annee du voyage   :");
    scanf("%d",&nouveauVoyage.date_voyage.annee);
    FILE *file=fopen("voyage.txt","a");
    if (file != NULL){
        fprintf(file,"%d %d %d %d %d %d %d %d",nouveauVoyage.id_voyage,nouveauVoyage.id_bus,nouveauVoyage.id_itineraire,nouveauVoyage.num_chauffeur
        ,nouveauVoyage.date_voyage.jour,nouveauVoyage.date_voyage.mois,nouveauVoyage.date_voyage.annee,nouveauVoyage.nbr_reservations);
        fclose(file);
        printf("voyage ajoutée avec succée");
    }else
    printf("Erreur lors de l'ouverture du fichier 'voyage.txt'.\n");
}


void afficherVoyage(int id_voyage) {
    FILE *file = fopen("voyage.txt", "r");
    if(file == NULL)
    {perror("Erreur lors de l'ouverture du fichier 'voyage.txt'");
        return;
    }
    struct Voyage voyage;
    int found=0;
    while (fscanf(file, "%d %d %d %d %d %d %d %d", &voyage.id_voyage, &voyage.id_bus, &voyage.id_itineraire,&voyage.num_chauffeur,
                    
                   &voyage.date_voyage.jour, &voyage.date_voyage.mois, &voyage.date_voyage.annee,&voyage.nbr_reservations) != EOF) {
        if (voyage.id_voyage == id_voyage) {
            found = 1;
            break;
        }
    }

    fclose(file);
    if(found){
        printf("\nInformations sur le Voyage :\n");
        printf("ID Voyage : %d\n", voyage.id_voyage);
        printf("ID Bus : %d\n", voyage.id_bus);
        printf("ID Itinéraire : %d\n", voyage.id_itineraire);
        printf("ID Chauffeur : %d\n", voyage.num_chauffeur);
        printf("Date du Voyage : %d/%d/%d\n", voyage.date_voyage.jour, voyage.date_voyage.mois, voyage.date_voyage.annee);
        struct Chauffeur chauffeur = verifierDisponibiliteChauffeur(voyage.num_chauffeur);

        if (chauffeur.num_chauffeur != -1) {
            printf("\nInformations sur le Chauffeur :\n");
            printf("num Chauffeur : %d\n", chauffeur.num_chauffeur);
            printf("Nom : %s\n", chauffeur.Personne.nom);
            printf("CIN : %s\n", chauffeur.Personne.cin);
        } else {
            printf("\nInformations sur le Chauffeur : Le chauffeur associé n'existe pas dans le fichier 'chauffeurs.txt'.\n");
        }
        // Afficher les informations sur le bus
        struct Bus bus = verifierDisponibiliteBus(voyage.id_bus);

        if (bus.id_bus != -1) {
            printf("\nInformations sur le Bus :\n");
            printf("ID Bus : %d\n", bus.id_bus);
            printf("Modèle : %s\n", bus.modele);
            printf("Capacité : %d\n", bus.capacite);
        } else {
            printf("\nInformations sur le Bus : Le bus associé n'existe pas dans le fichier 'bus.txt'.\n");
        }

        // Afficher les informations sur l'itinéraire
        struct Itineraire itineraire = verifierDisponibiliteItineraires(voyage.id_itineraire);

        if (itineraire.id_itineraire != -1) {
            printf("\nInformations sur l'Itinéraire :\n");
            printf("ID Itinéraire : %d\n", itineraire.id_itineraire);
            printf("Départ : %s\n", itineraire.depart);
            printf("Arrivée : %s\n", itineraire.arrivee);
        } else {
            printf("\nInformations sur l'Itinéraire : L'itinéraire associé n'existe pas dans le fichier 'itineraire.txt'.\n");
        }
    }
    else{
        printf("le voyage n'existe pas !!");
    }
}
void augmenterNombreReservations(int id_voyage, int increment) {
    FILE *fichier = fopen("voyage.txt", "r+");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'voyages.txt'");
        exit(EXIT_FAILURE);
    }

    struct Voyage voyage;

    // Trouver la ligne correspondant à l'ID du voyage
    while (fscanf(fichier, "%d", &voyage.id_voyage) == 1) {
        if (voyage.id_voyage == id_voyage) {
            // Lire et ignorer les valeurs précédentes
            for (int i = 1; i <= 6; ++i) {
                fscanf(fichier, "%*d");
            }

            // Lire la dernière valeur (nombre de réservations)
            fscanf(fichier, "%d", &voyage.nbr_reservations);

            // Modifier la valeur
            voyage.nbr_reservations += increment;

            // Revenir au début de la ligne
            fseek(fichier, -1, SEEK_CUR);

            // Écrire la nouvelle valeur
            fprintf(fichier, " %d", voyage.nbr_reservations);
            fseek(fichier, 1, SEEK_CUR);
            //fputc('\0', fichier);
            fclose(fichier);
            printf("Nombre de réservations pour le voyage %d mis à jour avec succès.\n", id_voyage);
            return;
        }
        // Ignorer le reste de la ligne
        for (int i = 1; i <= 7; ++i) {
            fscanf(fichier, "%*d");
        }
    }

    fclose(fichier);
    printf("Le voyage avec l'ID %d n'a pas été trouvé.\n", id_voyage);
}
void ajouterReservation()
{ 
    struct Reservation newReservation;
    struct Voyage voyage;
    printf("donner Id Reservation  :");
    scanf("%d",&newReservation.id_reservation);
   
    
       do {
        printf("Donner Id voyage : ");
        scanf("%d", &newReservation.id_voyage);

        // Récupère les informations du bus depuis le fichier "bus.txt"
        voyage = verifierDisponibiliteVoyage(newReservation.id_voyage);

        // Vérifie si le bus existe
        if (voyage.id_voyage == -1) {
            printf("Cet ID du voyage n'existe pas. Veuillez choisir un autre.\n");
        }

    } while (voyage.id_voyage == -1);
    
    
    printf("donner le nom du voyageur   :");
    scanf("%s",newReservation.voyageur.nom);
    printf("donner l'adresse du voyageur  :");
    scanf("%s",newReservation.voyageur.adresse);
    printf("donner le cin du voyageur   :");
    scanf("%s",newReservation.voyageur.cin);
    printf("donner l'age du voyageur  :");
    scanf("%d",&newReservation.voyageur.age);
    printf("donner le num_tel du voyageur  :");
    scanf("%s",newReservation.voyageur.num_Tel);
    printf("donner le jour du voyage   :");
    scanf("%d",&newReservation.date_reservation.jour);
    printf("donner le mois du voyage   :");
    scanf("%d",&newReservation.date_reservation.mois);
    printf("donner l'annee du voyage   :");
    scanf("%d",&newReservation.date_reservation.annee);
    newReservation.paye=1;
    FILE *file=fopen("reservations.txt","a");
    if (file != NULL){
        fprintf(file," %d %d %s %s %s %d %s %d %d %d %d",newReservation.id_reservation,newReservation.id_voyage,
        newReservation.voyageur.nom,newReservation.voyageur.adresse,newReservation.voyageur.cin,newReservation.voyageur.age
        ,newReservation.voyageur.num_Tel,newReservation.date_reservation.jour,newReservation.date_reservation.mois,
        newReservation.date_reservation.annee,newReservation.paye);
        fclose(file);
        printf("reservation ajoutée avec succée");
    }else
    printf("Erreur lors de l'ouverture du fichier 'reservations.txt'.\n");
}
void afficherReservationsById(int id_reservation){
    FILE *file = fopen("reservations.txt", "r");
    if(file == NULL)
    {perror("Erreur lors de l'ouverture du fichier 'reservations.txt'");
        return;
    }
    struct Reservation reservation;
    int found=0;
    while (fscanf(file, "%d %s %s %s %d %s %d %d %d %d %d", &reservation.id_reservation, reservation.voyageur.nom, reservation.voyageur.adresse,
                   reservation.voyageur.cin, &reservation.voyageur.age, reservation.voyageur.num_Tel,
                   &reservation.date_reservation.jour,&reservation.date_reservation.mois,&reservation.date_reservation.annee,
                   &reservation.id_voyage,&reservation.paye) != EOF) {
        if (reservation.id_reservation == id_reservation) {
            found = 1;
            break;
        }
    }

    fclose(file);
    if(found){
        printf("\nInformations sur la reservation :\n");
        printf("ID Reservation : %d\n", reservation.id_reservation);
        printf("Nom Voyageur : %s\n", reservation.voyageur.nom);
        printf("Adresse du Voyageur : %s\n", reservation.voyageur.adresse);
        printf("Cin Voyageur : %s\n", reservation.voyageur.cin);
        printf("Date du Réservation : %d/%d/%d\n", reservation.date_reservation.jour, reservation.date_reservation.mois, reservation.date_reservation.annee);
        struct Voyage voyage = verifierDisponibiliteVoyage(reservation.id_voyage);
        if (voyage.id_voyage != -1) {
            printf("\nInformations sur le Voyage :\n");
            printf("Date du Réservation : %d/%d/%d\n", voyage.date_voyage.jour, voyage.date_voyage.mois, voyage.date_voyage.annee);
            printf("Nom  : %d\n", voyage.nbr_reservations);
        } else {
            printf("\nInformations sur le Voyage : Le voyage associé n'existe pas dans le fichier 'voyages.txt'.\n");
        }
    }
    else{
        printf("la reservation n'existe pas !!");
    }
    
}
void afficherReservationsByIdVoyage(int id_voyage) {
    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'reservations.txt'");
        return;
    }

    struct Reservation reservation;
    int found = 0;
   

    printf("\nRéservations pour le Voyage avec ID %d :\n", id_voyage);
    printf("| %-12s | %-12s | %-12s | %-12s | %-5s |\n",
           "ID Réservation", "Nom Voyageur", "Date Réservation", "ID Voyage", "Payé");
    while (fscanf(file, "%d %s %s %s %d %s %d %d %d %d %d",
                  &reservation.id_reservation, reservation.voyageur.nom,reservation.voyageur.adresse,reservation.voyageur.cin,
                  &reservation.voyageur.age,reservation.voyageur.num_Tel,
                  &reservation.date_reservation.jour, &reservation.date_reservation.mois, &reservation.date_reservation.annee,
                   &reservation.id_voyage, &reservation.paye) != EOF) {
        if (reservation.id_voyage == id_voyage) {
            found = 1;
            printf("| %-12d | %-12s | %-2d/%-2d/%-4d | %-20d | %-20s |\n",
                   reservation.id_reservation, reservation.voyageur.nom,
                   reservation.date_reservation.jour, reservation.date_reservation.mois, reservation.date_reservation.annee,
                   reservation.id_voyage, (reservation.paye == 1) ? "Oui" : "Non");
        }
    }

    fclose(file);

    if (!found) {
        printf("Aucune réservation trouvée pour le voyage avec l'ID %d.\n", id_voyage);
    }
}
void modifierReservation()
{
    struct Reservation reservation;
    int id_reservation, tr = 0;
    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'reservations.txt'");
        return;
    }

    FILE *temp = fopen("temp.txt", "w");
    if (temp == NULL) {
        perror("Erreur lors de l'ouverture du fichier temporaire");
        fclose(file);
        return;
    }

    printf("Donner l'ID de la réservation à modifier : ");
    scanf("%d", &id_reservation);

    while (fscanf(file, "%d %s %s %s %d %s %d %d %d %d %d\n",
                  &reservation.id_reservation, reservation.voyageur.nom,reservation.voyageur.adresse,reservation.voyageur.cin,
                    &reservation.voyageur.age,reservation.voyageur.num_Tel,
                    &reservation.date_reservation.jour, &reservation.date_reservation.mois,
                    &reservation.date_reservation.annee, &reservation.id_voyage,
                    &reservation.paye) != EOF) {
        if (reservation.id_reservation == id_reservation) {
            tr = 1;

            printf("Veuillez saisir le nouveau nom du voyageur : ");
            scanf("%s", reservation.voyageur.nom);
            printf("Veuillez saisir le jour de modification de la réservation : ");
            scanf("%d", &reservation.date_reservation.jour);
            printf("Veuillez saisir le mois de modification de la réservation : ");
            scanf("%d", &reservation.date_reservation.mois);
            printf("Veuillez saisir l'année de modification de la réservation : ");
            scanf("%d", &reservation.date_reservation.annee);
            printf("Veuillez saisir le nouvel ID voyage de cette réservation : ");
            scanf("%d", &reservation.id_voyage);

            fprintf(temp, "%d %s %s %s %d %s %d %d %d %d %d\n",
            reservation.id_reservation, reservation.voyageur.nom,reservation.voyageur.adresse,reservation.voyageur.cin,
                    reservation.voyageur.age,reservation.voyageur.num_Tel,
                    reservation.date_reservation.jour, reservation.date_reservation.mois,
                    reservation.date_reservation.annee, reservation.id_voyage,
                    reservation.paye
                    );
        } else {
            fprintf(temp, "%d %s %s %s %d %s %d %d %d %d %d\n",
                    reservation.id_reservation, reservation.voyageur.nom,reservation.voyageur.adresse,reservation.voyageur.cin,
                    reservation.voyageur.age,reservation.voyageur.num_Tel,
                    reservation.date_reservation.jour, reservation.date_reservation.mois,
                    reservation.date_reservation.annee, reservation.id_voyage,
                    reservation.paye);
        }
    }

    fclose(file);
    fclose(temp);
    remove("reservations.txt");
    rename("temp.txt", "reservations.txt");

    if (tr == 0)
        printf("La réservation n'existe pas !");
    else
        printf("La réservation a été modifiée avec succès !");
}



void afficherToutesReservations() {
    FILE *file = fopen("reservations.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'reservations.txt'");
        return;
    }

    struct Reservation reservation;



    printf("\nToutes les Réservations :\n");
    printf("| %-12s | %-12s | %-12s | %-12s | %-12s | %-5s |\n",
           "ID Réservation", "Nom Voyageur", "Date Réservation", "ID Voyageur", "ID Voyage", "Payé");
    while (fscanf(file, "%d %s %s %s %d %s %d %d %d %d %d",
                  &reservation.id_reservation, reservation.voyageur.nom,reservation.voyageur.adresse,reservation.voyageur.cin,
                  &reservation.voyageur.age,reservation.voyageur.num_Tel,
                  &reservation.date_reservation.jour, &reservation.date_reservation.mois, &reservation.date_reservation.annee,
                   &reservation.id_voyage, &reservation.paye) != EOF) {
        printf("| %-12d | %-12s | %-2d/%-2d/%-4d | %-12d | %-5s |\n",
               reservation.id_reservation, reservation.voyageur.nom,
               reservation.date_reservation.jour, reservation.date_reservation.mois, reservation.date_reservation.annee,
                reservation.id_voyage, (reservation.paye == 1) ? "Oui" : "Non");
    }

    fclose(file);
}
void afficherTousVoyages() {
    FILE *file = fopen("voyage.txt", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier 'voyage.txt'");
        return;
    }

    struct Voyage voyage;

    printf("\nTous les Voyages :\n");
    printf("| %-12s | %-12s | %-12s | %-12s | %-12s | %-12s |\n",
           "ID Voyage", "ID Bus", "ID Itinéraire", "Date Voyage", "Nombre Réservations", "Prix");

    while (fscanf(file, "%d %d %d %d %d %d %d %d",
                  &voyage.id_voyage, &voyage.id_bus, &voyage.id_itineraire,&voyage.num_chauffeur,
                  &voyage.date_voyage.jour, &voyage.date_voyage.mois, &voyage.date_voyage.annee,
                   &voyage.nbr_reservations) != EOF) {
        printf("| %-12d | %-12d | %-12d | %-2d/%-2d/%-4d | %-18d |\n",
               voyage.id_voyage, voyage.id_bus, voyage.id_itineraire,
               voyage.date_voyage.jour, voyage.date_voyage.mois, voyage.date_voyage.annee,
               voyage.nbr_reservations);
    }

    fclose(file);
}



int main() {
   
    struct Chauffeur *chauffeur;
    struct Voyage *voyage;
    int nombreVoyageurs = 0;

    int choix;
    
    

    do {
        printf("\nMenu :\n");
        printf("1.Gestion Bus \n");
        printf("2.Gestion Chauffeur \n");
        printf("3.Gestion Itineraire \n");
        printf("4.Gestion Voyage \n");
        printf("5.Gestion Réservation\n");
        
        printf("0. Quitter\n");

        printf("Choix : ");
        scanf("%d", &choix);
        int choix1;
        int choix2;
        int choix3;
        switch (choix) {
            case 1:
                do {
                    printf("1.Ajouter  Bus\n");
                    printf("2.Afficher Les Bus\n");
                    printf("Choix :");
                    scanf("%d",&choix1);
                    switch(choix1){
                        case 1:
                            ajouterBus();
                            break;
                        case 2:
                            break;
                        case 0:
                            break;
                        
                    }
                }
                while(choix1 !=0);
                break;
            case 2:
                ajouterChauffeur(chauffeur);
                break;
            case 3:
                ajouterItineraire();
                break;
            case 4:
                do {
                    printf("1.Ajouter  Voyage\n");
                    printf("2.Afficher Les Voyage\n");
                    printf("Choix :");
                    scanf("%d",&choix2);
                    switch(choix2){
                        case 1:
                            ajouterVoyage();
                            break;
                        case 2:
                            printf("Entrez l'ID du voyage à afficher : ");
                            int t;
                            scanf("%d",&t);
                            afficherVoyage(t);
                break;
                            break;
                        case 0:
                            break;
                        
                    }
                }
                while(choix1 !=0);
                break;
                ajouterBus();
                break;
            case 5:
                do {
                    printf("1.Ajouter une réservation\n");
                    printf("2.Afficher reservation par id reservation\n");
                    printf("3.Afficher reservation par id voyage\n");
                    printf("4.modifier reservation par id reservation\n");
                    printf("Choix :");
                    scanf("%d",&choix3);
                    switch(choix3){
                        case 1:
                            ajouterReservation();
                            break;
                        case 2:
                            printf("Entrez l'ID du réservation à afficher : ");
                            int tt;
                            scanf("%d",&tt);
                            afficherReservationsById(tt);
                            break;
                        case 3:
                            printf("Entrez l'id du voyage du réservation à afficher");
                            int ttt;
                            scanf("%d",&ttt);
                            afficherReservationsByIdVoyage(ttt);
                        case 4:
                            modifierReservation();
                        case 0:
                            break;
                        
                    }
                }
                while(choix1 !=0);
                break;
                ajouterBus();
                break;
                ajouterVoyage();
                break;
            case 6:
                
            case 7:
                printf("Entrez l'ID du réservation à afficher : ");
                int y;
                scanf("%d",&y);
                afficherReservationsById(y);
                break;
            case 8:
                printf("Entrez l'ID du voyage du réservation à afficher : ");
                int z;
                scanf("%d",&z);
                afficherReservationsByIdVoyage(z);
                break;
            case 9:

                //modifierReservation();
               // afficherTousVoyages();
               afficherToutesReservations();
                break;
                
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}
