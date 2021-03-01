add_executable(
    BeverageService
    BeverageService.cpp
    ${THRIFT_GEN_CPP_DIR}/BeverageService.cpp
    ${THRIFT_GEN_CPP_DIR}/vending_machine_types.cpp
)

target_include_directories(
    BeverageService PRIVATE
)

target_link_libraries(
    BeverageService
    nlohmann_json::nlohmann_json
    ${THRIFT_LIB}
    ${CMAKE_THREAD_LIBS_INIT}
    ${Boost_LIBRARIES}
    Boost::log
    Boost::log_setup
)

install(TARGETS BeverageService DESTINATION ./)
