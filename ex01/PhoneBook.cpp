#include	<iostream>
#include	<string>
#include	<iomanip>
#include	"Contact.hpp"
#include	"PhoneBook.hpp"


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

void	PhoneBook::printFormatted(const std::string& str) const
{
	if (str.size() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
	std::cout << " | ";
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
		std::cout << std::setw(10) << i << " | ";
		printFormatted(m_contact[i].getNom());
		printFormatted(m_contact[i].getPrenom());
		printFormatted(m_contact[i].getPseudo());
		std::cout << std::endl;
	}
}

void	PhoneBook::searchContact() const
{
	afficheliste();
	if (m_nbContact == 0)
		return;
	
	while (true)
	{
		std::cout << "Entrer l'index du contact: ";
		size_t index;
		std::cin >> index;
		if (!std::cin)
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				return;
			}
			std::cout << "L'index doit être un nombre." << std::endl;
			std::cin.clear();
			std::cin.ignore(100000, '\n');
			continue;
		}
		std::cin.ignore(100000, '\n');
		if (index >= m_nbContact)
		{
			std::cout 
				<< "Index invalide, entrer un nombre entre 0 et " 
				<< (m_nbContact - 1) 
				<< "." 
				<< std::endl;
			continue;
		}
		afficheContact(index);
		return;
	}
}


