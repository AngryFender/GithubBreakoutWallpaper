cmake_minimum_required (VERSION 3.10)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("GithubBreakoutWallpaper")

find_package(curl REQUIRED)
find_package(curlcpp CONFIG REQUIRED)
find_package(tomlplusplus CONFIG REQUIRED)
INCLUDE_DIRECTORIES(${CURLCPP_SOURCE_DIR}/include)

get_property(imported_targets DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}" PROPERTY IMPORTED_TARGETS)
MESSAGE(STATUS "Imported targets ➜ ${imported_targets}")

# Add source to this project's executable.
add_executable (GithubBreakoutWallpaper 
"main.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET GithubBreakoutWallpaper PROPERTY CXX_STANDARD 20)
endif()

if(WIN32)
  target_link_libraries(${PROJECT_NAME}
          PRIVATE
          wsock32
          ws2_32
          CURL::libcurl
          curlcpp::curlcpp
          tomlplusplus::tomlplusplus
  )

endif()
