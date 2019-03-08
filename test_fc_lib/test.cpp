#include <fc/crypto/public_key.hpp>
#include <fc/crypto/private_key.hpp>
#include <fc/crypto/signature.hpp>
#include <fc/utility.hpp>
#include <iostream>

using namespace fc::crypto;
using namespace fc;

#define CHECK_EQUAL( A, B ) \
 std::cout<<(A)<<std::endl;\
 std::cout<<(B)<<std::endl;\
 if((A) != (B))\
 {\
	 std::cout << A << " != " << B << std::endl;\
 }

int main()
{

	do{
		auto private_key_string = std::string("PVT_R1_iyQmnyPEGvFd8uffnk152WC2WryBjgTrg22fXQryuGL9mU6qW");
		auto expected_public_key = std::string("PUB_R1_6EPHFSKVYHBjQgxVGQPrwCxTg7BbZ69H9i4gztN9deKTEXYne4");
		auto test_private_key = private_key(private_key_string);
		auto test_public_key = test_private_key.get_public_key();
		CHECK_EQUAL(private_key_string, std::string(test_private_key));
		CHECK_EQUAL(expected_public_key, std::string(test_public_key));
	} while(false);

	do{
		auto payload = "Test Cases";
		auto digest = sha256::hash(payload, const_strlen(payload));
		auto key = private_key::generate<r1::private_key_shim>();
		auto pub = key.get_public_key();
		auto sig = key.sign(digest);
		auto recovered_pub = public_key(sig, digest);
		std::cout << recovered_pub << std::endl;
		CHECK_EQUAL(std::string(recovered_pub), std::string(pub));
	} while(false);

	do{
		auto key = private_key::generate<r1::private_key_shim>();
		auto pub = key.get_public_key();
		auto pub_str = std::string(pub);
		auto recycled_pub = public_key(pub_str);
		std::cout << pub << " -> " << recycled_pub << std::endl;
		CHECK_EQUAL(std::string(pub), std::string(recycled_pub));
	} while(false);

}