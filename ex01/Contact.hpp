#ifndef CONTACT_HPP
#define CONTACT_HPP

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
	static bool			getInput(const std::string& prompt, std::string& result);
	static bool			getNameInput(const std::string& prompt, std::string& result);
	static bool			getPseudoInput(const std::string& prompt, std::string& result);
	static bool			getPhoneInput(const std::string& prompt, std::string& result);
	static bool			getSecretInput(const std::string& prompt, std::string& result);
	const std::string&	getNom() const { return m_nom; }
	const std::string&	getPrenom() const { return m_prenom; }
	const std::string&	getPseudo() const { return m_pseudo; }
	const std::string&	getNumero() const { return m_numero; }
	const std::string&	getSecretIntrouvable() const { return m_secretIntrouvable; }
	void				addContact(const std::string& nom, const std::string& prenom, const std::string& pseudo, const std::string& numero, const std::string& secretIntrouvable);
};

std::ostream& operator<<(std::ostream& flux, Contact const& contact);

#endif