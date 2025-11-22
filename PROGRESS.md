PROJET : GlobalBanksters United — Module 00 (ex02)

But : reconstituer Account.cpp, comprendre le projet et pouvoir reprendre le travail à cet endroit.

État actuel :
- Account.hpp : présent
- tests.cpp : présent
- Account.cpp : implémenté et testé localement
- Log : 19920104_091532.log (disponible)

Actions effectuées (par moi) :
1. Lecture du sujet `cpp0.pdf` et du log.
2. Ajout de `Account.cpp` implémentant la classe `Account`.
3. Compilation et exécution : les sorties correspondent au log (timestamps différents).

Prochaines étapes recommandées :
1. Créer un dépôt Git local (initialisé ici).
2. Créer un dépôt GitHub distant et le lier.
3. Pousser les commits sur `origin/main` (ou `master` selon ton choix).
4. Écrire un `README.md` / fichier de documentation (optionnel, mais recommandé).

Comment reprendre le travail depuis ici :
- Cloner le dépôt distant (ou copier le dossier) puis lancer :
  g++ -Wall -Wextra -Werror -std=c++98 tests.cpp Account.cpp -o test_exec
  ./test_exec

Notes pour l'audit / évaluation :
- Le commit initial contient l'implémentation d'`Account.cpp`. Vérifier les horaires/destructeurs si nécessaire.

Si tu veux que je crée le dépôt Git local et fasse le commit initial, je peux le faire maintenant (je vais l'initialiser et committer) puis t'indiquer comment créer le dépôt GitHub distant et pousser (ou je peux créer le dépôt distant automatiquement si `gh` est configuré).

-- FIN DU FICHIER --
