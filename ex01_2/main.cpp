#include	<iostream>
#include	<string>
#include	"PhoneBook.hpp"
#include	"Contact.hpp"

int main()
{
	PhoneBook phoneBook;
	

	while (1)
	{
		std::string cmd;

		std::cout << "Entrer command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, cmd);

		if (!std::cin)
			break;
		if (cmd == "EXIT")
			break;
		
		else if (cmd == "ADD")
		{
			int flag = 0;
			Contact contact;
			//Contact Contact(nom, prenom, pseudo, numero, secretIntrouvable);
			std::string	nom;
			std::string prenom;
			std::string pseudo;
			std::string numero;
			std::string secretIntrouvable;
			std::cout << "Entrer Nom du contact: ";
			std::getline(std::cin, nom);
			if (!std::cin)
			break;
			std::cout << "Entrer Prenom duu contact : ";
			std::getline(std::cin, prenom);
			if (!std::cin)
			break;
			std::cout << "Entrer Pseudo du contact: ";
			std::getline(std::cin, pseudo);
			if (!std::cin)
			break;
			std::cout << "Entrer Numéro ddu contact : ";
			std::getline(std::cin, numero);
			if (!std::cin)
			break;
			std::cout << "Entrer Secret introuvable du contact : ";
			std::getline(std::cin, secretIntrouvable);
			if (!std::cin)
			break;
			flag = contact.addContact(nom, prenom, pseudo, numero, secretIntrouvable);
			if (flag)
			{
				std::cout << "Erreur : tous les champs doivent être remplis." << std::endl;
				continue;
			}
			phoneBook.addContactPhoneBook(contact);
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.searchContact();
		}
		else
		{
			std::cout << "Veuillez saisir une commande valide : " << std::endl;
			continue;
		}
	}
	return 0;
}