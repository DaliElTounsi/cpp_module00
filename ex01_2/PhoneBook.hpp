#ifndef		DEF_PHONEBOOK
#define		DEF_PHONEBOOK
#include	"Contact.hpp"


class PhoneBook
{
private :
	Contact		m_contact[8];
	size_t		m_i;
	size_t		m_nbContact;



public :
	PhoneBook();
	void	addContactPhoneBook(Contact const &contact);
	void	searchContact() const;
	void	afficheContact(size_t indexContact) const;
	void	afficheliste() const;
	size_t  getRealIndex(size_t logicalIndex) const;


};



#endif