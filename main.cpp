#include <iostream>
#include "WinSock2.h"
#include "curlcpp/curl_easy.h"
using curl::curl_easy;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

int main()
{
    std::cout << "Hello World" << std::endl;

    // Easy object to handle the connection.
    curl_easy easy;

    // Add some options.
    easy.add<CURLOPT_URL>("www.google.com");
    easy.add<CURLOPT_FOLLOWLOCATION>(1L);

    try {
        easy.perform();
    } catch (curl_easy_exception &error) {
        // If you want to print the last error.
        std::cerr<<error.what()<<std::endl;
    }
    return 0;
}
