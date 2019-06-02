//#define BOOST_TEST_MODULE cypher_suites
#include <boost/test/unit_test.hpp>

//#define BOOST_TEST_SOURCE
//#include <boost/test/impl/unit_test_main.ipp>

#include <fc/utility.hpp>
#include <fc/crypto/pke.hpp>
#include <fc/log/logger.hpp>
using namespace fc;

BOOST_AUTO_TEST_SUITE(pke_suites)

BOOST_AUTO_TEST_CASE(test_pke) try {

	/*auto key = private_key::generate<r1::private_key_shim>();
	auto pub = key.get_public_key();
	auto pub_str = std::string(pub);
	auto recycled_pub = public_key(pub_str);

	std::cout << pub << " -> " << recycled_pub << std::endl;

	BOOST_CHECK_EQUAL(std::string(pub), std::string(recycled_pub));*/
	public_key pub_key;
	private_key priv_key;
	generate_key_pair(pub_key, priv_key);
	//std::cout << pub_key.serialize() << std::endl;
	ilog("pub key = ${pubk}", ("pubk", pub_key));
} FC_LOG_AND_RETHROW();

BOOST_AUTO_TEST_SUITE_END()