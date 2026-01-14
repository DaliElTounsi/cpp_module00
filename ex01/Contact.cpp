#include	<string>
#include	"Contact.hpp"
#include	<iostream>

Contact::Contact()
: m_nom("inconnu"), m_prenom("inconnu"), m_pseudo("inconnu"), m_numero("inconnu"), m_secretIntrouvable("inconnu")
{
}

bool Contact::getInput(const std::string& prompt, std::string& result)
{
	do {
		std::cout << prompt;
		std::getline(std::cin, result);
		if (!std::cin)
			return false;
		if (result.empty())
			std::cout << "Le champ ne peut pas être vide." << std::endl;
	} while (result.empty());
	return true;
}

static bool isLetter(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

static bool isAlphaNum(char c)
{
	return isLetter(c) || (c >= '0' && c <= '9');
}

static bool isPrintable(char c)
{
	return c >= 32 && c <= 126;
}

bool Contact::getNameInput(const std::string& prompt, std::string& result)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (!std::cin)
			return false;
		if (result.empty())
		{
			std::cout << "Le champ ne peut pas être vide." << std::endl;
			continue;
		}
		bool isValid = true;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (!isLetter(result[i]) && result[i] != ' ' && result[i] != '-')
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
		{
			std::cout << "Le nom ne doit contenir que des lettres, espaces ou tirets." << std::endl;
			continue;
		}
		return true;
	}
}

bool Contact::getPseudoInput(const std::string& prompt, std::string& result)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (!std::cin)
			return false;
		if (result.empty())
		{
			std::cout << "Le champ ne peut pas être vide." << std::endl;
			continue;
		}
		bool isValid = true;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (!isAlphaNum(result[i]))
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
		{
			std::cout << "Le pseudo ne doit contenir que des lettres et chiffres." << std::endl;
			continue;
		}
		return true;
	}
}

bool Contact::getPhoneInput(const std::string& prompt, std::string& result)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (!std::cin)
			return false;
		if (result.empty())
		{
			std::cout << "Le champ ne peut pas être vide." << std::endl;
			continue;
		}
		bool isValid = true;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (result[i] < '0' || result[i] > '9')
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
		{
			std::cout << "Le numéro ne doit contenir que des chiffres." << std::endl;
			continue;
		}
		if (result.size() != 10)
		{
			std::cout << "Le numéro doit contenir exactement 10 chiffres." << std::endl;
			continue;
		}
		return true;
	}
}

bool Contact::getSecretInput(const std::string& prompt, std::string& result)
{
	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, result);
		if (!std::cin)
			return false;
		if (result.empty())
		{
			std::cout << "Le champ ne peut pas être vide." << std::endl;
			continue;
		}
		bool isValid = true;
		for (size_t i = 0; i < result.size(); i++)
		{
			if (!isPrintable(result[i]))
			{
				isValid = false;
				break;
			}
		}
		if (!isValid)
		{
			std::cout << "Le champ contient des caractères invalides." << std::endl;
			continue;
		}
		return true;
	}
}

void	Contact::addContact(const std::string& nom, const std::string& prenom, const std::string& pseudo, const std::string& numero, const std::string& secretIntrouvable)
{
	m_nom = nom;
	m_prenom = prenom;
	m_pseudo = pseudo;
	m_numero = numero;
	m_secretIntrouvable = secretIntrouvable;

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