#!/bin/bash

# Check if the Geant4 tar file is provided as an argument
if [ $# -ne 1 ]; then
    echo "Usage: $0 <geant4_tar_file>"
    exit 1
fi

GEANT4_TAR=$1

# Check if the tar file exists
if [ ! -f "$GEANT4_TAR" ]; then
    echo "Error: The file $GEANT4_TAR does not exist."
    exit 1
fi

# Step 1: Update the system and install dependencies
echo "Updating system and installing dependencies..."
sudo apt update && sudo apt upgrade -y
sudo apt install -y build-essential cmake g++ git
sudo apt install -y libxerces-c-dev libexpat1-dev libgl1-mesa-dev libglu1-mesa-dev freeglut3-dev
sudo apt install -y qtbase5-dev qt5-qmake
sudo apt install -y libx11-dev libxmu-dev

# Step 2: Extract the Geant4 tar file
echo "Extracting $GEANT4_TAR..."
tar -xzf "$GEANT4_TAR"

# Get the extracted directory name (assuming the tar file extracts to a folder like geant4-v11.3.0)
GEANT4_DIR=$(tar -tzf "$GEANT4_TAR" | head -1 | cut -f1 -d"/")

if [ -z "$GEANT4_DIR" ]; then
    echo "Error: Could not determine the Geant4 directory from the tar file."
    exit 1
fi

# Step 3: Create geant4-build and geant4-install directories inside the extracted folder
echo "Creating build and install directories..."
cd "$GEANT4_DIR" || { echo "Error: Could not change to directory $GEANT4_DIR"; exit 1; }
mkdir -p geant4-build geant4-install

# Step 4: Run cmake with the specified options
echo "Configuring with cmake..."
cd geant4-build || { echo "Error: Could not change to geant4-build directory"; exit 1; }
cmake .. \
    -DCMAKE_INSTALL_PREFIX="../geant4-install" \
    -DGEANT4_USE_OPENGL_X11=ON \
    -DGEANT4_USE_QT=ON \
    -DGEANT4_BUILD_MULTITHREADED=ON

# Step 5: Build the project
echo "Building Geant4..."
make -j$(nproc)

# Step 6: Install the project
echo "Installing Geant4..."
make install

echo "1. Geant4 installation completed"
echo "2. Add this to bashrc file source /media/roshan/Roshan/radha/G4/geant4-install/bin/geant4.sh"
echo "3. Check using which geant4-config"
echo "4. Proceed with running datasetG4.sh"
