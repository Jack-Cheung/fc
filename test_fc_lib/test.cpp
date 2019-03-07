#include <fc/crypto/public_key.hpp>
#include <fc/crypto/private_key.hpp>
#include <fc/crypto/signature.hpp>
#include <fc/utility.hpp>
#include <iostream>

using namespace fc::crypto;
using namespace fc;

int main()
{
	auto private_key_string = std::string("5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3");
	auto expected_public_key = std::string("EOS6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV");
	auto test_private_key = private_key(private_key_string);
	auto test_public_key = test_private_key.get_public_key();

	std::cout << std::string(test_private_key) << std::endl;
	std::cout << std::string(test_public_key) << std::endl;;
}