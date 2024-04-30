# PHILOSOPHER

## Introduction
Créer un programme qui va simuler des philosophe qui vont manger, penser et dormir.

Le but c'est que nos philosophes ne meurt pas.

il se lance de la manière suivante :

```
./philosopher [combien de philosophe] [temps de survie] [temps pour manger] [temps pour dormir] [nombre de repas]
```
On as par contre plusieurs contraite, combien il y a de philosophe et il y a autant de philosophe que de fourchette(il faut que il y a une fourchette a droite et a gauche du philosophe, si il est seul donc 1 fourchette), combien de temps il doit dormir, combien de temps il lui faut pour manger, et un temps pour penser.

Le philosophe pour pouvoir manger il lui faut 2 fourchette pour que la vie continue il faut au minimun 2 philosophe, si il est seul il mourras. Apres avoir manger il vas dormir et dés qu'il est réveiller il vas commencer a pensé. Chaque philosophe a un compte a rebour de leur mort si il atteint le nombre indiqué il meurt ce compte a rebour vas pouvoir etre réinitialiser, pour ca il faut que le philosophe mange pendant qu'il mange son compteur est figé puis apres avoir finis de manger ce même compteur repars a 0. Pour pas qu'il meurt il faut que le philosophe mange avant la fin du compteur.

Chaque philosophe est representer par un thread.

Une video explicatif de comment réaliser ce projet par **Jamshidbek2000**

## Les fonctions autoriser
* ``pthread_create()``: Creates a new thread.
* ``pthread_join()``: Waits until a specific thread finishes to avoid having zombie threads.
* ``pthread_mutex_init()``: Creates a mutex.
* ``pthread_mutex_destroy()``: Destroys a mutex.
* ``pthread_mutex_lock()``: Locks a mutex.
* ``pthread_mutex_unlock()``: Unlocks a mutex.
* ``usleep()``: Makes a thread sleep for a specified number of microseconds.
* ``gettimeofday()``: Returns the number of microseconds passed since January 1, 1970.
* ``malloc()``: Allocates memory on the heap.
* ``free()``: Frees memory from the heap.
* ``printf()``: Prints messages.

## Usage
autant de mutex que de fourchette

un mutex = cadenas, le thread qui a lock c'est a lui qui doit unlock les autres threads, les autres threads vont essaye de lock et pendant ce temps ils sont freeze