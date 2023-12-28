# Système de Réservation E-Bus

E-Bus est une application en ligne de commande simple écrite en C, qui facilite la réservation de bus pour des voyages. Elle permet la gestion des bus, des réservations, des chauffeurs et des itinéraires. Des structures de données avancées sont utilisées pour le stockage des données."fichiers.txt"

## Fonctionnalités
- Créer un nouvel itinéraire.
- Afficher les détails d'un itinéraire.
- Créer une nouvelle réservation.
- Afficher reservation a partir de son ID-reservation.
- Afficher reservation a partir de son ID-voyage.
- Afficher toutes les reservation enregistrées.
- Modifier les détails d'une réservation.
- Ajouter un nouvel chauffeur.
- Afficher les détails d'un chauffeur.
- Ajouter un Bus.
- Afficher les détails des bus.
- Créer un nouveau voyage avec un nombre de réservations incrémenté lors de l'ajout d'une réservation.


## Structure des Fichiers

- `main.c`: Fichier principal du programme.
- `bus.txt`: Stocke les informations sur les bus.
- `chauffeurs.txt`: Stocke les informations sur les chauffeurs.
- `itineraires.txt`: Stocke les informations sur les itinéraires.
- `voyages.txt`: Stocke les informations sur les voyages.
- `reservations.txt`: Stocke les informations sur les réservations.

## Classes

- `Personne`: Représente un individu.
- `Date`: Représente une date.
- `Bus`: Représente un bus.
- `Chauffeur`: Représente un chauffeur.
- `Itineraire`: Représente un itinéraire.
- `Voyage`: Représente un voyage.
- `Reservation`: Représente une réservation.

## Fonctions

- `ajouterChauffeur()`: Ajouter un nouveau chauffeur.
- `afficherChauffeur()`: Afficher les détails du chauffeur.
- `ajouterBus()`: Ajouter un nouveau bus.
- `ajouterItineraire()`: Ajouter un nouvel itinéraire.
- `verifierDisponibiliteBus()`: Vérifier la disponibilité du bus.
- `verifierDisponibiliteVoyage()`: Vérifier la disponibilité du voyage.
- `verifierDisponibiliteChauffeur()`: Vérifier la disponibilité du chauffeur.
- `verifierDisponibiliteItineraires()`: Vérifier la disponibilité de l'itinéraire.
- `ajouterVoyage()`: Ajouter un nouveau voyage.
- `afficherVoyage()`: Afficher les détails du voyage.
- `augmenterNombreReservations()`: Augmenter le nombre de réservations.
- `ajouterReservation()`: Ajouter une nouvelle réservation.
- `afficherReservationsById()`: Afficher les réservations par ID.
- `afficherReservationsByIdVoyage()`: Afficher les réservations par ID de voyage.
- `modifierReservation()`: Modifier les détails de la réservation.
- `afficherToutesReservations()`: Afficher toutes les réservations.
- `afficherTousVoyages()`: Afficher tous les voyages.

## Utilisation

Compilez le programme et exécutez l'exécutable. Suivez les invites à l'écran pour interagir avec le système de réservation.

## Remarque

Assurez-vous d'utiliser les structures de données appropriées pour le stockage avancé des données.

