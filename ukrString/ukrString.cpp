#include"pch.h"
#include"ukrString.h"
#include"ukrString.h"

using su = strings::ukrString;

#pragma region Interface functions definitions

size_t su::getLength() const
{
	return m_chars.getSize();
}

void su::from_Word(const Word& word)
{
	if (word.size() == 0) return;

	if (m_chars.isAllocated())
		m_chars.deAllocate();

	m_chars.allocate_memory_block(word);
}

void su::from_char_ptr(char* src, size_t length)
{
	if (length == 0) return;

	if (m_chars.isAllocated())
		m_chars.deAllocate();

	m_chars.allocate_memory_block(src, length);
}

char* su::get_chars()
{
	return m_chars.getPtr();
}

std::string su::to_string() const
{
	std::string str;

	size_t length = this->getLength();

	if (length == 0) return str;

	for (size_t i = 0; i < length; i++)
	{
		str.push_back(m_chars[i]);
	}

	return str;
}

void su::use_for_input()
{
	m_use_for_input = true;
}

bool su::is_used_for_input() const
{
	return m_use_for_input;
}

void su::not_for_input()
{
	m_use_for_input = false;
}

void su::from_string(const std::string& str)
{
	if (m_chars.isAllocated())
		m_chars.deAllocate();

	m_chars.allocate_memory_block(str._Unchecked_begin(), str.length());
}

#pragma endregion


#pragma region Ctor Definition

su::ukrString() : m_use_for_input(false) {}

su::ukrString(char* str, size_t length) : ukrString()
{
	m_chars.allocate_memory_block(str, length);
}

su::ukrString(const char* str) : ukrString()
{
	m_chars.allocate_memory_block(str, strlen(str));
}

su::ukrString(const std::string& str) : ukrString()
{
	m_chars.allocate_memory_block(str._Unchecked_begin(), str.length());
}

su::ukrString(const ukrString& other)
{
	m_use_for_input = other.m_use_for_input;
	m_chars = other.m_chars;
}

su::ukrString(std::vector<char>& v) : ukrString()
{
	m_chars.allocate_memory_block(v);
}

su::ukrString(int number)
{		
	std::string t = std::to_string(number);

	m_chars.allocate_memory_block(t.c_str(), t.size());
}

su::ukrString(float number)
{
	std::string t = std::to_string(number);

	m_chars.allocate_memory_block(t.c_str(), t.size());
}

su::ukrString(double number)
{
	std::string t = std::to_string(number);

	m_chars.allocate_memory_block(t.c_str(), t.size());
}

#pragma endregion

#pragma region Operators

su& su::operator= (const char c_str[])
{
	if (this->m_chars.isAllocated())
		this->m_chars.deAllocate();

	m_chars.allocate_memory_block(c_str, strlen(c_str));

	return *this;
}

su& su::operator = (const ukrString& other)
{
	m_use_for_input = other.m_use_for_input;
	this->m_chars = other.m_chars;

	return *this;
}

su::operator std::string() const
{
	return to_string();
}

char& su::operator [] (int index)
{
	if (m_chars.isAllocated())
		return m_chars[index];
}

const char& su::operator [] (int index) const
{
	if (m_chars.isAllocated())
		return m_chars[index];
}

su su::operator + (const ukrString& other) const
{
	su newStr;

	size_t this_size = this->getLength();
	size_t otherSize = other.getLength();

	size_t newSize = this_size + otherSize;

	newStr.m_chars.allocate_memory_block(newSize);

	for (size_t i = 0; i < this_size; i++)
	{
		newStr[i] = this->m_chars[i];
	}

	size_t j = 0;

	for (size_t i = this_size; i < newSize; i++, j++)
	{
		newStr[i] = other[j];
	}

	return newStr;
}

void su::operator += (const ukrString& other)
{
	size_t this_size = this->getLength();
	size_t otherSize = other.getLength();

	size_t newSize = this_size + otherSize;

	allocator::smart_allocator<char> temp(m_chars);

	this->m_chars.deAllocate();

	this->m_chars.allocate_memory_block(newSize);

	for (size_t i = 0; i < this_size; i++)
	{
		m_chars[i] = temp[i];
	}

	size_t j = 0;

	for (size_t i = this_size; i < newSize; i++, j++)
	{
		m_chars[i] = other[j];
	}
}

bool su::operator == (const su& other)
{
	return m_chars == other.m_chars;
}

bool su::operator != (const su& other)
{
	return !(*this == other);
}

#pragma endregion


#pragma region Destructor

su::~ukrString()
{
	m_chars.~smart_allocator();
}

#pragma endregion

#pragma region Private Static Functions

bool su::Compare(char current, const char delim[])
{
	size_t length = strlen(delim);

	for (size_t i = 0; i < length; i++)
	{
		if (current == delim[i])
			return true;
	}

	return false;
}

#pragma endregion


#pragma region public static functions

void su::ukrStrCopy(ukrString& src, ukrString dest, int start, int end)
{
	if (src.getLength() == 0) return;

	if (start < 0 || start > end - 1)
		throw std::runtime_error("Incorrect range! Start index is greater then end index!");

	for (int i = start; i < end; i++)
	{
		dest[i] = src[i];
	}
}

char su::Ukr(char str)
{
	switch (str)
	{
	case -78: return 73;  // ²
	case -77: return 105; // ³
	case -86: return 242; // ª
	case -70: return 243; // º
	case -81: return 244; // ¯
	case -65: return 245; // ¿
	case -88: return 240; // ¨
	case -72: return 241; // ¸

	default:
	{
		if (str <= -17 && str >= -64) return str -= 64;
		else
			if (str <= -1 && str >= -16) return str -= 16;
	}
	}
}

std::istream& su::getLine(std::istream& is, su& output)
{
	std::string str;

	std::getline(is, str);

	output.from_string(str);

	output.use_for_input();

	return is;
}

std::ifstream& su::getLine(std::ifstream& ifs, su& output)
{
	std::string temp;

	std::getline(ifs, temp);

	if (output.m_chars.isAllocated())
	{
		output.m_chars.deAllocate();
	}

	output.m_chars.allocate_memory_block(temp.c_str(), temp.size());

	return ifs;
}

void su::Split(strings::ukrString& str, wordSet& word_Set,
	const char delim[])
{
	bool delim_found = false;

	size_t length = str.getLength();

	Word word;

	for (size_t i = 0; i < length; i++)//O(n * sizeof(delim))
	{
		if (!Compare(str[i], delim) || i == 0)//Space not found or we are at the begining create Word
		{
			word.push_back(str[i]);

			delim_found = false;
		}
		else//delim_found found
		{
			if (!delim_found)
			{
				word_Set.push_back(word);

				word.clear();
			}

			delim_found = true;
		}

		if (i == length - 1)//End reached
		{
			word_Set.push_back(word);

			word.clear();
		}
	}
}

void su::Split(const strings::ukrString& input_sentence,
	std::vector<strings::ukrString>& word_set, const char delim[])
{
	bool delim_found = false;

	size_t length = input_sentence.getLength();

	Word word;

	for (size_t i = 0; i < length; i++)//O(n * sizeof(delim))
	{
		if (!Compare(input_sentence[i], delim) || i == 0)//Space not found or we are at the begining create Word
		{
			word.push_back(input_sentence[i]);

			delim_found = false;
		}
		else//delim_found found
		{
			if (!delim_found)
			{
				word_set.push_back(ukrString(word));

				word.clear();
			}

			delim_found = true;
		}

		if (i == length - 1)//End reached
		{
			word_set.push_back(ukrString(word));

			word.clear();
		}
	}
}

#pragma endregion



