cmake_minimum_required(VERSION 3.16.0) # 3.16 required for KF5

# Set c++17 standard (and not gnu++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)
project(satellite_constellation_viewer)

cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)
set(QT_MIN_VERSION "5.3.0")
set(KF5_MIN_VERSION "5.2.0")

find_package(ECM 1.0.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(FeatureSummary)

# Find Qt modules
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core #QCommandLineParser, QStringLiteral
    Widgets #QApplication
)

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    CoreAddons    # KAboutData
    I18n          # KLocalizedString
    WidgetsAddons # KMessageBox
)

find_package(Marble REQUIRED)

feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

# Set verbose build
set(CMAKE_VERBOSE_MAKEFILE ON)

# Set the what files go into the add_executable
set(satellite_constellation_viewer_SRCS main.cpp)
add_executable(satellite_constellation_viewer ${satellite_constellation_viewer_SRCS})

target_link_libraries(satellite_constellation_viewer
    Marble
    Qt5::Widgets
    KF5::CoreAddons
    KF5::I18n
    KF5::WidgetsAddons)

install(TARGETS satellite_constellation_viewer RUNTIME DESTINATION bin)
