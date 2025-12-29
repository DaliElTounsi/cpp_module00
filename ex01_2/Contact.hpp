#ifndef		DEF_CONTACT
#define		DEF_CONTACT

#include	<string>
#include	<iostream>


class Contact
{
private :
	std::string		m_nom;
	std::string		m_prenom;
	std::string		m_pseudo;
	std::string		m_numero;
	std::string		m_secretIntrouvable;

public :

	Contact();
	Contact(std::string nom, std::string prenom, std::string pseudo, std::string numero, std::string secretIntrouvable);
	std::string		getNom() const {return m_nom; }
	std::string		getPrenom() const {return m_prenom; }
	std::string		getPseudo() const {return m_pseudo; }
	std::string		getNumero() const {return m_numero; }
	std::string		getSecretIntrouvable() const {return m_secretIntrouvable; }
	int				addContact(std::string nom, std::string prenom, std::string pseudo, std::string numero, std::string secretIntrouvable);
};

std::ostream& operator<<(std::ostream& flux, Contact const& contact);

#endif