# cmake_minimum_required(VERSION 3.5)

# project(Gui_Navi VERSION 0.1 LANGUAGES CXX)

# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test Widgets)
# find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test Widgets)

# set(PROJECT_SOURCES
#         main.cpp
#         mainwindow.cpp
#         mainwindow.h
#         mainwindow.ui
#         adresse.h
#         adresse.cpp
#          ort.h
#          ort.cpp
#          point_of_interest.h
#          point_of_interest.cpp
#             meinort.h
#          meinort.cpp
#          adressewindow.h
#          adressewindow.cpp
#          poiwindow.h
#          poiwindow.cpp
#          displaywindow.h
#          displaywindow.cpp
#          distancewindow.h
#          distancewindow.cpp
#          savedatawindow.h
#          savedatawindow.cpp
#          ressource.qrc
#          test.h test.cpp
# )

# if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
#     qt_add_executable(Gui_Navi
#         MANUAL_FINALIZATION
#         ${PROJECT_SOURCES}


#     )

#  else()
#   if(ANDROID)
#       add_library(Gui_Navi SHARED
#        ${PROJECT_SOURCES}
#    )

#     else()
#         add_executable(Gui_Navi
#             ${PROJECT_SOURCES}
#         )
#     endif()
# endif()

# if(${QT_VERSION} VERSION_LESS 6.1.0 AND NOT DEFINED BUNDLE_ID_OPTION)
#     set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Taschenrechner)
# endif()

# set_target_properties(Gui_Navi PROPERTIES
#     ${BUNDLE_ID_OPTION}
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS Gui_Navi
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# if(QT_VERSION_MAJOR EQUAL 6)
#     qt_finalize_executable(Gui_Navi)
# endif()

# target_link_libraries(Gui_Navi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets  Qt${QT_VERSION_MAJOR}::Test)

#  set_target_properties(Gui_Navi PROPERTIES
#      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
#  )

# # enable_testing()
# # add_executable(Gui_Navi_Tests
# #     test.cpp
# #     test.h
# # )
# # target_link_libraries(Gui_Navi_Tests PRIVATE Qt${QT_VERSION_MAJOR}::Test  Qt${QT_VERSION_MAJOR}::Widgets)
# # add_test(NAME GuiNaviTests COMMAND Gui_Navi_Tests)

cmake_minimum_required(VERSION 3.5)

project(Gui_Navi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Test Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Test Widgets)

#
# 1) Lister TOUTES vos sources (UI, code, tests, etc.)
#
set(PROJECT_SOURCES
    # ========== Votre code de base ==========
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    adresse.h
    adresse.cpp
    ort.h
    ort.cpp
    point_of_interest.h
    point_of_interest.cpp
    meinort.h
    meinort.cpp
    adressewindow.h
    adressewindow.cpp
    poiwindow.h
    poiwindow.cpp
    displaywindow.h
    displaywindow.cpp
    distancewindow.h
    distancewindow.cpp
    savedatawindow.h
    savedatawindow.cpp

    # ========== Vos ressources ==========
    ressource.qrc

    # ========== Code de test ==========
    test.h
    test.cpp
)

#
# 2) Créer l’exécutable unique
#
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Gui_Navi
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Gui_Navi SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Gui_Navi
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#
# 3) Paramètres divers (bundle Mac, exécutable Win, etc.)
#
if(${QT_VERSION} VERSION_LESS 6.1.0 AND NOT DEFINED BUNDLE_ID_OPTION)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.GuiNavi)
endif()

set_target_properties(Gui_Navi PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE

    # Où générer l'exécutable ?
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

#
# 4) Lier QtWidgets (pour l'UI) et QtTest (pour les tests) au même exécutable
#
target_link_libraries(Gui_Navi
    PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
    PRIVATE Qt${QT_VERSION_MAJOR}::Test
)

#
# 5) Si on est sous Qt6, on doit "finaliser" l’exécutable
#
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Gui_Navi)
endif()

#
# 6) Installation éventuelle (optionnel)
#
include(GNUInstallDirs)
install(TARGETS Gui_Navi
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Gui_Navi)
endif()

target_link_libraries(Gui_Navi PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Test)

set_target_properties(Gui_Navi PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
