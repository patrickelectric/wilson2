set(CMAKE_AUTOMOC ON)

set(SRCS
    abilitiesmanager.cpp
    abilityinterface.cpp
    main.cpp
    qbot.cpp
)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(abilities)

add_executable(wilson2 ${SRCS} ${Abilities_SRCS})

target_link_libraries(wilson2
    TgBot ${CMAKE_THREAD_LIBS_INIT} ${OPENSSL_LIBRARIES} ${Boost_LIBRARIES} ${CURL_LIBRARIES}
    Qt5::Core Qt5::Widgets Qt5::Qml
)
