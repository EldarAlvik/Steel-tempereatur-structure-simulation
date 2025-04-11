#include "std_lib_facilities.h"
#include "buttonLogic.h"
#include "simulationControl.h"
#include "atomAndStructure/atom.h"
#include "atomAndStructure/coordinates.h"

void testButton()
{
    cout << "dette er en test" << endl;
}


std::function<void ()> startSimulationCallback(Simulation* sim){
    return [sim]() { sim->setRun(true); };
}
std::function<void ()> pauseSimulationCallback(Simulation* sim){
    return [sim]() { 
        bool currentRunState = sim->getRun();
        sim->setRun(!currentRunState);
    };
}
std::function<void ()> resetSimulationCallback(Simulation* sim){
    return [sim]() { sim->resetSimulation(); };
}

// denne er skrevet selv
std::function<void ()> saveSimulationButtonCallback(Simulation* sim){
    return[sim](){
        sim->setRun(false);
        string filename = "data/simulation_data.dat";
        fstream outfile;

        try{
            outfile.open(filename, ios::out| ios::binary);
            if(outfile.is_open()){

                int temperatur = sim->getTemperature();
                outfile.write(reinterpret_cast<char*>(&temperatur), sizeof(int));
                float carPercent = sim->getCarbonPercent();
                outfile.write(reinterpret_cast<char*>(&carPercent), sizeof(float));

                int sizeOfAllAtoms = sim->getAllAtoms().size();
                outfile.write(reinterpret_cast<char*>(&sizeOfAllAtoms), sizeof(int));
                

                for (auto& atom: sim->getAllAtoms()){
                    string id = atom->getId();
                    size_t lenid = id.length();
                    unsigned int x = atom->getCoordinates().x;
                    unsigned int y = atom->getCoordinates().y;
                    string grainId = atom->boundBy();
                    size_t lengrainid = grainId.length();
                    
                    //write 
                    outfile.write(reinterpret_cast<char*>(&lenid), sizeof(size_t));
                    outfile.write(id.c_str(), lenid);

                    outfile.write(reinterpret_cast<char*>(&x), sizeof(unsigned int));
                    outfile.write(reinterpret_cast<char*>(&y), sizeof(unsigned int));
                    
                    outfile.write(reinterpret_cast<char*>(&lengrainid), sizeof(size_t));
                    outfile.write(grainId.c_str(), lengrainid);
                    
                }
                outfile.close();
                cout << "simulation saved to " << filename << endl;

                
            }
            else{
                throw string("");
        }
        }
        catch(exception& e){
            cout << "file not at location"<< endl;
        }
    };
}
std::function<void ()> saveSimulationInputCallback(Simulation* sim){
    return [sim](){
        string userFilename;
        cout << "Enter filename to save (without extension): ";
        cin >> userFilename;
        
        // Create data directory if it doesn't exist
        if (!filesystem::exists("data")) {
            filesystem::create_directory("data");
        }
        
        string filename = "data/" + userFilename + ".dat";
        ofstream outfile(filename, ios::binary);
        
        try {
            if (!outfile) {
                throw runtime_error("Could not open file for writing: " + filename);
            }
            
            // Copy the same saving logic from saveSimulationButtonCallback
            int temperatur = sim->getTemperature();
            outfile.write(reinterpret_cast<char*>(&temperatur), sizeof(int));
            float carPercent = sim->getCarbonPercent();
            outfile.write(reinterpret_cast<char*>(&carPercent), sizeof(float));

            int sizeOfAllAtoms = sim->getAllAtoms().size();
            outfile.write(reinterpret_cast<char*>(&sizeOfAllAtoms), sizeof(int));
            

            for (auto& atom: sim->getAllAtoms()){
                string id = atom->getId();
                size_t lenid = id.length();
                unsigned int x = atom->getCoordinates().x;
                unsigned int y = atom->getCoordinates().y;
                string grainId = atom->boundBy();
                size_t lengrainid = grainId.length();
                
                //write 
                outfile.write(reinterpret_cast<char*>(&lenid), sizeof(size_t));
                outfile.write(id.c_str(), lenid);

                outfile.write(reinterpret_cast<char*>(&x), sizeof(unsigned int));
                outfile.write(reinterpret_cast<char*>(&y), sizeof(unsigned int));
                
                outfile.write(reinterpret_cast<char*>(&lengrainid), sizeof(size_t));
                outfile.write(grainId.c_str(), lengrainid);
                
            }
            outfile.close();
            cout << "Simulation saved to " << filename << endl;
        }
        catch (const exception& e) {
            cout << "Error saving simulation: " << e.what() << endl;
        }
    };
}


// rettet mnedCopilot for vectorene
std::function<void ()>loadSimulationButtonCallback(Simulation* sim){
    return[sim](){
        sim->setRun(false);
        sim->clearAtoms();
        
        // Create data directory if it doesn't exist
        if (!filesystem::exists("data")) {
            filesystem::create_directory("data");
        }
        
        string filename = "data/simulation_data.dat";
        ifstream infile(filename, ios::binary);

        try{
            if(!infile) {
                throw runtime_error("Could not open file: " + filename);
            }

            // Read simulation parameters
            int temperatur;
            infile.read(reinterpret_cast<char*>(&temperatur), sizeof(int));
            sim->setTemperature(temperatur);
            
            float carPercent;
            infile.read(reinterpret_cast<char*>(&carPercent), sizeof(float));
            
    
            sim->resetSimulation();  
            sim->clearAtoms();       
            
            // Read atom count
            int sizeOfAllAtoms;
            infile.read(reinterpret_cast<char*>(&sizeOfAllAtoms), sizeof(int));
            
            cout << "Loading " << sizeOfAllAtoms << " atoms..." << endl;

            // Initialize with proper grid size (use sim's current gridLen)
            unsigned int gridSize = 100; // Default if not available
            
            for (int i = 0; i < sizeOfAllAtoms; i++){
                // Read ID
                size_t lenid;
                infile.read(reinterpret_cast<char*>(&lenid), sizeof(size_t));
                vector<char> idBuffer(lenid);
                infile.read(idBuffer.data(), lenid);
                string id(idBuffer.begin(), idBuffer.end());
                
                // Read coordinates
                unsigned int x, y;
                infile.read(reinterpret_cast<char*>(&x), sizeof(unsigned int));
                infile.read(reinterpret_cast<char*>(&y), sizeof(unsigned int));
                
                // Validate coordinates (prevent out-of-bounds errors)
                if (x >= gridSize || y >= gridSize) {
                    cout << "Warning: Atom at position (" << x << "," << y 
                         << ") exceeds grid size " << gridSize << endl;
                    
                    // Skip remaining data for this atom
                    size_t lengrainid;
                    infile.read(reinterpret_cast<char*>(&lengrainid), sizeof(size_t));
                    infile.ignore(lengrainid);
                    continue;
                }
                
                // Read grain ID
                size_t lengrainid;
                infile.read(reinterpret_cast<char*>(&lengrainid), sizeof(size_t));
                vector<char> grainIdBuffer(lengrainid);
                infile.read(grainIdBuffer.data(), lengrainid);
                string grainId(grainIdBuffer.begin(), grainIdBuffer.end());
                
                // Create appropriate atom type
                char atomType = id[0];
                string idNumber = id.substr(1);
                int idtem = std::stoi(idNumber);
                
                Atom* newAtom = nullptr;
                if (atomType == 'C'){
                    newAtom = new Carbon(idtem);
                } else {
                    newAtom = new Iron(idtem);
                }
                
                if (newAtom) {
                    newAtom->bindGrain(grainId);
                    newAtom->setCoordinates(x, y);
                    if (!sim->addAtom(newAtom)) {
                        cout << "Warning: Failed to add atom at position (" << x << "," << y << ")" << endl;
                        delete newAtom; 
                    }
                }
            }
            
            infile.close();
            cout << "Simulation loaded from " << filename << endl;
        }
        catch(const exception& e){
            cout << "Error loading simulation: " << e.what() << endl;
        }
    };
}