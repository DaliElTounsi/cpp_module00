#include	<iostream>
#include	<string>
#include	"Contact.hpp"
#include	"PhoneBook.hpp"
#include	<sstream>


PhoneBook::PhoneBook()
	: m_i(0), m_nbContact(0)
{

}

void	PhoneBook::addContactPhoneBook(Contact const &contact)
{
	m_contact[m_i % 8] = contact;
	m_i++;
	if (m_nbContact < 8)
		m_nbContact++;
}

void	PhoneBook::afficheContact(size_t indexContact) const
{
	if (m_nbContact == 0)
	{
		std::cout << "il n'y a pas de contact \n";
		return;
	}
	if (indexContact >= m_nbContact)
	{
		std::cout << "invalide index, entrer un nombre entre 0 et " << (m_nbContact - 1) << "\n"; 
		return;
	}
	std::cout << m_contact[indexContact] << std::endl;
}
void	PhoneBook::afficheliste() const
{

	if (m_nbContact == 0)
	{	
		std::cout << "il n'y a pas de contact\n";
		return;
	}
	for (size_t i = 0; i < m_nbContact; i++)
	{
		std::stringstream ss;
		ss << i;
		std::string indexStr = ss.str();
		for (size_t e = indexStr.size(); e < 10; e++)
			std::cout << " ";
		std::cout << indexStr << " | ";

		if (m_contact[i].getNom().size() >= 10)
			std::cout << m_contact[i].getNom().substr(0, 9) << "." << " | ";
		else
		{
			std::cout << m_contact[i].getNom();
			for (size_t  e = m_contact[i].getNom().size(); e < 10; e++)
				std::cout << " ";
			std::cout << " | ";
		}
		if (m_contact[i].getPrenom().size() >= 10)
			std::cout << m_contact[i].getPrenom().substr(0, 9) << "." << " | ";
		else
		{
			std::cout << m_contact[i].getPrenom();
			for (size_t e = m_contact[i].getPrenom().size(); e < 10; e++)
				std::cout << " ";
			std::cout << " | ";
		}
		if (m_contact[i].getPseudo().size() >= 10)
			std::cout << m_contact[i].getPseudo().substr(0, 9) << "." << " | " << std::endl;
		else
		{
			std::cout << m_contact[i].getPseudo();
			for (size_t e = m_contact[i].getPseudo().size(); e < 10; e++)
				std::cout << " ";
			std::cout << " | " << std::endl;
		}
	}
}

void	PhoneBook::searchContact() const
{
	afficheliste();
	size_t index;
	std::cin >> index;
	if (!std::cin)
	{
		std::cout << "l'index doit être un nombre !" << std::endl;
		std::cin.clear();
		std::cin.ignore(100000, '\n');
		return;
	}
	afficheContact(index);
	std::cin.ignore(100000, '\n');
}


