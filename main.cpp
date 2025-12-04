#include <iostream>
#include "curlcpp/curl_easy.h"
#include <toml++/toml.h>

using curl::curl_easy;
using curl::curl_easy_exception;
using curl::curlcpp_traceback;

int main()
{
    std::cout << "Starting" << std::endl;

    toml::table tbl = toml::parse_file("config.toml");

    std::string config_path = "config.toml";
    std::string svg_source = load_svg_path(config_path);

    std::string svg_data;

    if (is_url(svg_source)) {
        svg_data = download_svg(svg_source);
    } else {
        std::ifstream file(svg_source);
        svg_data.assign(std::istreambuf_iterator<char>(file),
                        std::istreambuf_iterator<char>());
    }

    render_svg(svg_data);

    // Easy object to handle the connection.
    curl::curl_easy easy;



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
