#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include	"Contact.hpp"
#include	<cstddef>

class PhoneBook
{
private :
	Contact		m_contact[8];
	size_t		m_i;
	size_t		m_nbContact;

	void	printFormatted(const std::string& str) const;

public :
	PhoneBook();
	void	addContactPhoneBook(Contact const &contact);
	void	searchContact() const;
	void	afficheContact(size_t indexContact) const;
	void	afficheliste() const;

};

#endif