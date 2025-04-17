cmake_minimum_required(VERSION 3.16)
project(Tutorial)

# Find Geant4 package, including optional UI and visualization components
find_package(Geant4 REQUIRED ui_all vis_all)

# Include Geant4 macros
include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)

# Create the executable
add_executable(sim sim.cc ${sources})

# Set include directories for the sim target
target_include_directories(sim PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Link against Geant4 libraries
target_link_libraries(sim PUBLIC ${Geant4_LIBRARIES})
