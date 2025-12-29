#include	<string>
#include	"Contact.hpp"
#include	<iostream>

Contact::Contact()
: m_nom("inconnu"), m_prenom("inconnu"), m_pseudo("inconnu"), m_numero("inconnu"), m_secretIntrouvable("inconnu")
{
}

Contact::Contact(std::string nom, std::string prenom, std::string pseudo, std::string numero, std::string secretIntrouvable)
: m_nom(nom), m_prenom(prenom), m_pseudo(pseudo), m_numero(numero), m_secretIntrouvable(secretIntrouvable)
{

}

int	Contact::addContact(std::string nom, std::string prenom, std::string pseudo, std::string numero, std::string secretIntrouvable)
{
	if (nom == "" || prenom == "" || pseudo == "" || numero == "" || secretIntrouvable == "")
		return (1);
	m_nom = nom;
	m_prenom = prenom;
	m_pseudo = pseudo;
	m_numero = numero;
	m_secretIntrouvable = secretIntrouvable;
	
	return 0;
}

std::ostream& operator<<(std::ostream& flux, Contact const& contact)
{
	flux << "Nom: " << contact.getNom() << "\n";
	flux << "Prenom: " << contact.getPrenom() << "\n";
	flux << "Pseudo: " << contact.getPseudo() << "\n";
	flux << "Numéro: " << contact.getNumero() << "\n";
	flux << "Secret: " << contact.getSecretIntrouvable() << "\n";
	return flux;
}