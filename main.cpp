#include <iostream>
#include "curlcpp/curl_easy.h"
#include <toml++/toml.h>
#include<string>

using curl::curl_easy;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

int main() {
    std::cout << "Starting" << std::endl;

    toml::table tbl;
    try {
        tbl = toml::parse_file("config.toml");
    } catch (std::exception &e) {
        std::cout << e.what();
        return -1;
    }
    std::optional<std::string> path = tbl["general"]["path"].value_or("");

    curl::curl_easy easy;

    // Add some options.
    easy.add<CURLOPT_URL>(path.value().c_str());
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);

    try {
        easy.perform();
    } catch (curl_easy_exception &error) {
        // If you want to print the last error.
        std::cerr << error.what() << std::endl;
    }
    return 0;
}
