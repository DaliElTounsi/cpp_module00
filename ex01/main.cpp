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
			Contact contact;
			std::string	nom;
			std::string prenom;
			std::string pseudo;
			std::string numero;
			std::string secretIntrouvable;

			if (!Contact::getNameInput("Entrer Nom du contact: ", nom))
				break;
			if (!Contact::getNameInput("Entrer Prenom du contact: ", prenom))
				break;
			if (!Contact::getPseudoInput("Entrer Pseudo du contact: ", pseudo))
				break;
			if (!Contact::getPhoneInput("Entrer Numero du contact: ", numero))
				break;
			if (!Contact::getSecretInput("Entrer Secret introuvable du contact: ", secretIntrouvable))
				break;

			contact.addContact(nom, prenom, pseudo, numero, secretIntrouvable);
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