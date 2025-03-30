cd /G4/geant4-install/share/Geant4/data
# download 15 data sets from Geant4 website onto this folder
for f in *.tar.gz; do tar -xvf "$f"; done
echo "Now you can start using Geant4!!"
