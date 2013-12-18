#include "proto\ql2.pb.h"
#include <boost/asio.hpp>
#include <string>
#include <boost/format.hpp>
#include "exception.hpp"

#ifndef RETHINK_DB_DRIVER_CONNECTION
#define RETHINK_DB_DRIVER_CONNECTION

using namespace std;
using namespace boost::asio;
using namespace com::rethinkdb;
using namespace com::rethinkdb::driver;

namespace com {
	namespace rethinkdb {
		namespace driver {

			class connection {

			public:

				connection(const string& host, const string& port, const string& database, const string& auth_key);

				bool connect();

				shared_ptr<Response> read_response();

				void write_query(const Query& query);

			private:

				string host;
				string port;
				string database;
				string auth_key;
				int timeout;
				int64_t token;
				bool is_connected;

				io_service io_service;
				ip::tcp::resolver resolver_;
				ip::tcp::socket socket_;
				boost::asio::streambuf request_;
				boost::asio::streambuf response_;
			};

		}
	}
}
#endif