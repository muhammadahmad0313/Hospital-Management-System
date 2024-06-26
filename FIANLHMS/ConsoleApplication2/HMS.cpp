#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>
#include <iomanip>




using namespace std;

// Function prototypes for main functionality
void login();
void homePage();
void doctorsPage();
void patientPage();
void appointmentPage();
void prescriptionPage();
void medicineInventoryPage();
void laboratoryPage();

// Function prototypes for patient
void addPatient();
void updatePatient();
void removePatient();
void viewPatients();
void searchPatient();

// Function prototypes for doctor
void addDoctor();
void updateDoctor();
void removeDoctor();
void viewDoctors();
void searchDoctor();

// Function prototypes for appointment
void addAppointment();
void viewAppointments();

// Function prototypes for prescription
void addPrescription();
void generatePrescription();

// Function prototypes for medicine inventory
void addMedicine();
void updateMedicine();
void removeMedicine();
void viewMedicines();
void searchMedicine();

// Function prototypes for laboratory
void addLaboratoryTest();
void updateLaboratoryTest();
void removeLaboratoryTest();
void viewLaboratoryTests();
void searchLaboratoryTest();

// Function prototypes for bills

void billingpage();
double calculateBill(double medicineCost, double testCost, bool isEmergency);
bool isItemExists(const char* fileName, const string& itemName);
double getItemCost(const char* fileName, const string& itemName);

//Function prototypes for admin

bool authenticateAdmin();
void addUsers();
void removeUsers();
void viewUsers();
void updateUsers();
void admin_main();




// Constants file names
const char userFileName[] = "user.txt";
const char adminFileName[] = "admin.txt";
const char patientFileName[] = "patients.txt";
const char doctorFileName[] = "doctors.txt";
const char medicineFileName[] = "medicine_inventory.txt";
const char billingFileName[] = "billing.txt";
const char testFileName[] = "laboratory_tests.txt";
const char appointmentFileName[] = "appointment.txt";
const char prescriptionFileName[] = "prescription.txt";


int main() {
    login();
    return 0;
}

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void login() {
    cout << "=== User Authentication ===" << endl;

    string enteredUsername, enteredPassword;
    bool isAuthenticated = false;

    do {
        cout << "Enter username: ";
        cin >> enteredUsername;
        cout << "Enter password: ";
        cin >> enteredPassword;

        ifstream userFile(userFileName);
        if (userFile.is_open()) {
            string username, password;
            while (userFile >> username >> password) {
                if (username == enteredUsername && password == enteredPassword) {
                    isAuthenticated = true;
                    break;
                }
            }
            userFile.close();
        }
        else {
            cout << "Error opening user file.\n";
           
        }

        if (!isAuthenticated) {
            cout << "Invalid credentials. Please try again.\n";
        }

    } while (!isAuthenticated);

    clearScreen();
    homePage();
}

void homePage() {
    int choice;
    cout << "\n=== Home Page ===" << endl;
    cout << "1. Patient\n";
    cout << "2. Doctor\n";
    cout << "3. Appointment\n";
    cout << "4. Prescription\n";
    cout << "5. Medicine Inventory\n";
    cout << "6. Laboratory\n";
    cout << "7. Billing\n";
    cout << "8. Admin\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
  
    if (choice > 0 && choice <= 9)
    {
     

        switch (choice) {
        case 1:
            clearScreen();
            patientPage();
            break;
        case 2:
            clearScreen();
            doctorsPage();
            break;
        case 3:
            clearScreen();
            appointmentPage();
            break;
        case 4:
            clearScreen();
            prescriptionPage();
            break;
        case 5:
            clearScreen();
            medicineInventoryPage();
            break;

        case 6:
            clearScreen();
            laboratoryPage();
            break;
        case 7:
            clearScreen();
            billingpage();
            break;
        case 8:
            clearScreen();
            admin_main();
            break;
        case 9:
            clearScreen();
            cout << "Exiting HMS. Goodbye!\n";
            break;
        default:
            clearScreen();
            cout << "Invalid choice. Please try again.\n";
        }

    }
    
    else {
        cout << "Invalid Input!" << endl;
    }
    

}

void doctorsPage() {
    int choice;

   
        cout << "\n=== Doctor Page ===" << endl;
        cout << "1. Add Doctor\n";
        cout << "2. Update Doctor\n";
        cout << "3. Remove Doctor\n";
        cout << "4. View Doctors\n";
        cout << "5. Search Doctor\n";
        cout << "6. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice > 0 && choice <= 6)
        {
            switch (choice) {
            case 1:
                clearScreen();
                addDoctor();
                break;

            case 2:
                clearScreen();
                updateDoctor();
                break;
            case 3:
                clearScreen();
                removeDoctor();
                break;
            case 4:
                clearScreen();
                viewDoctors();
                break;
            case 5:
                clearScreen();
                searchDoctor();
                break;

            case 6:
                clearScreen();
                cout << "Returning to Home Page.\n";
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

      }
        else { cout << "Invalid Input!" << endl; }
    
}


void patientPage() {
    int choice;

    
        cout << "\n=== Patient Page ===" << endl;
        cout << "1. Add Patient\n";
        cout << "2. Update Patient\n";
        cout << "3. Remove Patient\n";
        cout << "4. View Patients\n";
        cout << "5. Search Patient\n";
        cout << "6. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        if (choice > 0 && choice <= 6)
        {
            switch (choice) {
            case 1:
                clearScreen();
                addPatient();
                break;
            case 2:
                clearScreen();
                updatePatient();
                break;
            case 3:
                clearScreen();
                removePatient();
                break;
            case 4:
                clearScreen();
                viewPatients();
                break;
            case 5:
                clearScreen();
                searchPatient();
                break;
            case 6:
                clearScreen();
                cout << "Returning to Home Page.\n";
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

        }
        else { cout << "Invalid Input!" << endl; }
}




void appointmentPage() {
    int choice;

    
        cout << "\n=== Appointment Page ===" << endl;
        cout << "1. Add Appointment\n";
        cout << "2. View Appointments\n";
        cout << "3. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice > 0 && choice <= 3)
        {
            switch (choice) {
            case 1:
                clearScreen();
                addAppointment();
                break;
            case 2:
                clearScreen();
                viewAppointments();
                break;
            case 3:
                clearScreen();
                cout << "Returning to Home Page.\n";
                homePage();
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

      }
        else { cout << "Invalid Input!" << endl; }
}


void prescriptionPage() {
    int choice;

   
        cout << "\n=== Prescription Page ===" << endl;
        cout << "1. Add Patient's Prescription\n";
        cout << "2. Generate Prescription\n";
        cout << "3. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

      
        if (choice > 0 && choice <= 3)
        {
            switch (choice) {
            case 1:
                clearScreen();
                addPrescription();
                break;
            case 2:
                clearScreen();
                generatePrescription();
                break;

            case 3:
                clearScreen();
                cout << "Returning to Home Page.\n";
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

    }
        else { cout << "Invalid Input!" << endl; }
}


void medicineInventoryPage() {
    int choice;

   
        cout << "\n=== Medicine Inventory Page ===" << endl;
        cout << "1. Add Medicine\n";
        cout << "2. Update Medicine\n";
        cout << "3. Remove Medicine\n";
        cout << "4. View Medicines\n";
        cout << "5. Search Medicine\n";
        cout << "6. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice > 0 && choice <= 6)
        {

            switch (choice) {
            case 1:
                clearScreen();
                addMedicine();
                break;
            case 2:
                clearScreen();
                updateMedicine();
                break;
            case 3:
                clearScreen();
                removeMedicine();
                break;
            case 4:
                clearScreen();
                viewMedicines();
                break;
            case 5:
                clearScreen();
                searchMedicine();
                break;

            case 6:
                clearScreen();
                cout << "Returning to Home Page.\n";
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

   }
        else { cout << "Invalid Input!" << endl; }
}

void laboratoryPage() {
    int choice;

   
        cout << "\n=== Laboratory Page ===" << endl;
        cout << "1. Add Laboratory Test\n";
        cout << "2. Update Laboratory Test\n";
        cout << "3. Remove Laboratory Test\n";
        cout << "4. View Laboratory Tests\n";
        cout << "5. Search Laboratory Test\n";
        cout << "6. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

      
        if (choice > 0 && choice <= 6)
        {
            switch (choice) {
            case 1:
                clearScreen();
                addLaboratoryTest();
                break;
            case 2:
                clearScreen();
                updateLaboratoryTest();
                break;
            case 3:
                clearScreen();
                removeLaboratoryTest();
                break;
            case 4:
                clearScreen();
                viewLaboratoryTests();
                break;
            case 5:
                clearScreen();
                searchLaboratoryTest();
                break;

            case 6:
                clearScreen();
                cout << "Returning to Home Page.\n";
                break;
            default:
                clearScreen();
                cout << "Invalid choice. Please try again.\n";
            }

    }
        else { cout << "Invaid Input!" << endl; }
}



void addDoctor() {
    string id, firstName, lastName, contact, specialist, degree, startTime, endTime, availability, ampmtime, ampmtime1;
    int age,fee, htime, htime1, mtime, mtime1;
    cin.ignore();
    cout << "Enter Doctor's ID: ";
    getline(cin, id);

    // Checking if the doctor already exists
    ifstream doctorFile(doctorFileName);
    if (doctorFile.is_open()) {
        string existingId;
        while (doctorFile >> existingId) {
            if (existingId == id) {
                cout << "Doctor with the same ID already exists.\n";
                doctorFile.close();
                return;
            }
        }
        doctorFile.close();
    }
    else {
        cout << "Error opening doctor file.\n";
        return;
    }

    cout << "Enter Doctor's First Name: ";
    getline(cin, firstName);

    cout << "Enter Doctor's Last Name: ";
    getline(cin, lastName);

    cout << "Enter Doctor's Age (>0): ";
    cin >> age;
    if (age <= 0) {
        cout << "Invalid age: ";
      
    }
    cin.ignore();

    cout << "Enter Doctor's Contact: ";
    getline(cin, contact);

    cout << "Enter Doctor's Specialist: ";
    getline(cin, specialist);

    cout << "Enter Doctor's Degree: ";
    getline(cin, degree);



    cout << "Enter Starting Time:" << endl;
    cout << "Hour: ";
    cin >> htime;
    if (!(htime > 0 && htime < 13)) {
        cout << "Invalid HOUR." << endl;
        return;
    }

    cout << "Minutes: ";
    cin >> mtime;
    if (!(mtime >= 0 && mtime < 60)) {
        cout << "Invalid MINUTES." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter AM/PM: ";
    getline(cin, ampmtime);
    if (!(ampmtime == "am" || ampmtime == "AM" || ampmtime == "pm" || ampmtime == "PM")) {
        cout << "Invalid AM/PM." << endl;
        return;
    }

    startTime = to_string(htime) + ":" + (mtime < 10 ? "0" : "") + to_string(mtime) + ampmtime;

    
    cout << "Enter Ending Time:" << endl;
    cout << "Hour: ";
    cin >> htime1;
    if (!(htime1 > 0 && htime1 < 13)) {
        cout << "Invalid HOUR." << endl;
        return;
    }

    cout << "Minutes: ";
    cin >> mtime1;
    if (!(mtime1 >= 0 && mtime1 < 60)) {
        cout << "Invalid MINUTES." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter AM/PM: ";
    getline(cin, ampmtime1);
    if (!(ampmtime1 == "am" || ampmtime1 == "AM" || ampmtime1 == "pm" || ampmtime1 == "PM")) {
        cout << "Invalid AM/PM." << endl;
        return;
    }

    endTime = to_string(htime1) + ":" + (mtime1 < 10 ? "0" : "") + to_string(mtime1) + ampmtime1;

    
    cout << "Enter Doctor's Availability (e.g., Mon, Tue, Wed, Thu, Fri, Sat, Sun, or specific days): ";

    getline(cin, availability);

    if (!(availability == "mon" || availability == "tue" || availability == "wed" ||
        availability == "thu" || availability == "fri" || availability == "sat" || availability == "sun" ||
        availability == "monday" || availability == "tuesday" || availability == "wednesday" ||
        availability == "thursday" || availability == "friday" || availability == "saturday" || availability == "sunday")) {
        cout << "Invalid availability!" << endl;
        return;
    }




    cout << "Enter Doctor's FEE: ";
    cin >> fee;
    while (!(fee > 0))
    {
        cout << "Enter Doctor's FEE: ";
        cin >> fee;
    }
    cin.ignore();


    ofstream doctorFileOut(doctorFileName, ios::app);
    if (doctorFileOut.is_open()) {
        doctorFileOut << id << " " << firstName << " " << lastName << " " << age << " "
            << contact << " " << specialist << " " << degree << " "
            << startTime << " " << endTime << " " << availability<<" " << fee << "\n";
        doctorFileOut.close();
        cout << "Doctor added successfully.\n";
    }
    else {
        cout << "Error opening doctor file for writing.\n";
    }
    system("pause");
    clearScreen();
}

void updateDoctor() {
    string id, newPassword;
    cin.ignore();

    cout << "Enter Doctor's ID to update: ";
    getline(cin, id);

    // Checking if the doctor exists
    ifstream doctorFile(doctorFileName);
    if (doctorFile.is_open()) {
        string existingId, firstName, lastName ,contact, specialist, degree, startTime, endTime, availability;
        int age,fee;
        bool doctorFound = false;
        ofstream tempFile("temp_doctors.txt");

        while (doctorFile >> existingId >> firstName >> lastName >> age>>contact >> specialist
            >> degree >> startTime >> endTime >> availability>>fee) {
            if (existingId == id) {
                doctorFound = true;
                cout << "Enter new password: ";
                getline(cin, newPassword);
                tempFile << existingId << " " << firstName << " " << lastName << " "<<
                   age<<" " << contact << " " << specialist << " " << degree << " "
                    << startTime << " " << endTime << " " << availability<<" " << fee << "\n";
                cout << "Doctor details updated successfully.\n";
            }
            else {
                tempFile << existingId << " " << firstName << " " << lastName << " "<<age<<" "
                    << contact << " " << specialist << " " << degree << " "
                    << startTime << " " << endTime << " " << availability <<" " << fee << "\n";
            }
        }

        doctorFile.close();
        tempFile.close();


        remove(doctorFileName);
        rename("temp_doctors.txt", doctorFileName);

        if (!doctorFound) {
            cout << "Doctor not found.\n";
        }
    }
    else {
        cout << "Error opening doctor file.\n";
    }

    system("pause");
    clearScreen();
}

void removeDoctor() {
    string id;
    cin.ignore();

    cout << "Enter Doctor's ID to remove: ";
    getline(cin, id);

    // Checking if the doctor exists
    ifstream doctorFile(doctorFileName);
    if (doctorFile.is_open()) {
        string existingId, firstName, lastName, contact, specialist, degree, startTime, endTime, availability;
        int age,fee;
        bool doctorFound = false;
        ofstream tempFile("temp_doctors.txt");

        while (doctorFile >> existingId >> firstName >> lastName>>age >> contact >> specialist
            >> degree >> startTime >> endTime >> availability>>fee) {
            if (existingId == id) {
                doctorFound = true;
                cout << "Doctor removed successfully.\n";
            }
            else {
                tempFile << existingId << " " << firstName << " " << lastName << " "<<age<<" "
                    << contact << " " << specialist << " " << degree << " "
                    << startTime << " " << endTime << " " << availability<<" " << fee << "\n";
            }
        }

        doctorFile.close();
        tempFile.close();


        remove(doctorFileName);
        rename("temp_doctors.txt", doctorFileName);

        if (!doctorFound) {
            cout << "Doctor not found.\n";
        }
    }
    else {
        cout << "Error opening doctor file.\n";
    }

    
    system("pause");
    clearScreen();
}

void viewDoctors() {
    cin.ignore();

    ifstream doctorFile(doctorFileName);

    if (doctorFile.is_open()) {
        string id, firstName, lastName, contact, specialist, degree, startTime, endTime, availability;
        int age,fee;
        cout << "\n=== List of Doctors ===\n";
        while (doctorFile >> id >> firstName >> lastName >>age>> contact >> specialist
            >> degree >> startTime >> endTime >> availability>>fee) {
            cout << "ID: " << id << endl
                << "Name: " << firstName << " " << lastName << endl
                << "Age: " << age << endl
                << "Contact: " << contact << endl
                << "Specialist: " << specialist << endl
                << "Degree: " << degree << endl
                << "Start Time: " << startTime << endl
                << "End Time: " << endTime << endl
                << "Availability: " << availability << endl
                << "FEE: " << fee << endl << endl;
        }

        doctorFile.close();
    }
    else {
        cout << "Error opening doctor file.\n";
    }

    system("pause");
    clearScreen();
}

void searchDoctor() {
    string id;
    cin.ignore();

    cout << "Enter Doctor's ID to search: ";
    getline(cin, id);

    // Checking if the doctor exists
    ifstream doctorFile(doctorFileName);
    if (doctorFile.is_open()) {
        string existingId, firstName, lastName, contact, specialist, degree, startTime, endTime, availability;
        int age,fee;
        bool doctorFound = false;

        while (doctorFile >> existingId >> firstName >> lastName>>age >> contact >> specialist
            >> degree >> startTime >> endTime >> availability>>fee) {
            if (existingId == id) {
                doctorFound = true;
                cout << "ID: " << id << endl
                    << "Name: " << firstName << " " << lastName << endl
                    << "Age: " << age << endl
                    << "Contact: " << contact << endl
                    << "Specialist: " << specialist << endl
                    << "Degree: " << degree << endl
                    << "Start Time: " << startTime << endl
                    << "End Time: " << endTime << endl
                    << "Availability: " << availability << endl
                    << "FEE: " << fee << endl << endl;

                break;
            }
        }

        doctorFile.close();

        if (!doctorFound) {
            cout << "Doctor not found.\n";
        }
    }
    else {
        cout << "Error opening doctor file.\n";
    }

    system("pause");
    clearScreen();
}

void addPatient() {
    string patientId;
    string firstName, lastName, symptoms, bloodType, temperature, bloodPressure, heartRate;

    cout << "Enter Patient ID: ";
    getline(cin, patientId);

    // Checking if the patient ID already exists
    ifstream patientFile(patientFileName);
    if (patientFile.is_open()) {
        string existingId;
        while (patientFile >> existingId) {
            if (existingId == patientId) {
                cout << "Patient with the same ID already exists.\n";
                patientFile.close();
                return;
            }
        }
        patientFile.close();
    }
    else {
        cout << "Error opening patient file.\n";
        return;
    }

    cout << "Enter Patient First Name: ";
    getline(cin, firstName);

    cout << "Enter Patient Last Name: ";
    getline(cin, lastName);

    cout << "Enter Patient Symptoms: ";
    getline(cin, symptoms);

    cout << "Enter Patient Blood Type: ";
    getline(cin, bloodType);

    cout << "Enter Patient Temperature: ";
    getline(cin, temperature);

    cout << "Enter Patient Blood Pressure: ";
    getline(cin, bloodPressure);

    cout << "Enter Patient Heart Rate: ";
    getline(cin, heartRate);

    ofstream patientFileOut(patientFileName, ios::app);
    if (patientFileOut.is_open()) {
        patientFileOut << patientId << " " << firstName << " " << lastName << " " << symptoms << " " << bloodType << " "
            << temperature << " " << bloodPressure << " " << heartRate << "\n";
        patientFileOut.close();
        cout << "Patient added successfully.\n";
    }
    else {
        cout << "Error opening patient file for writing.\n";
    }
    system("pause");

    clearScreen();
}

void updatePatient() {
    string patientId;
    cout << "Enter Patient ID to update: ";
    getline(cin, patientId);

    // Checking if the patient exists
    ifstream patientFile(patientFileName);
    if (patientFile.is_open()) {
        string existingId;
        string existingFirstName, existingLastName, existingSymptoms, existingBloodType, existingTemperature, existingBloodPressure, existingHeartRate;

        bool patientFound = false;
        ofstream tempFile("temp_patients.txt");

        while (patientFile >> existingId >> existingFirstName >> existingLastName >> existingSymptoms >> existingBloodType
            >> existingTemperature >> existingBloodPressure >> existingHeartRate) {
            if (existingId == patientId) {
                patientFound = true;

                cout << "Enter new first name: ";
                cin.ignore();
                getline(cin, existingFirstName);

                cout << "Enter new last name: ";
                getline(cin, existingLastName);

                cout << "Enter new symptoms: ";
                getline(cin, existingSymptoms);

                cout << "Enter new blood type: ";
                getline(cin, existingBloodType);

                cout << "Enter new temperature: ";
                getline(cin, existingTemperature);

                cout << "Enter new blood pressure: ";
                getline(cin, existingBloodPressure);

                cout << "Enter new heart rate: ";
                getline(cin, existingHeartRate);

                tempFile << existingId << " " << existingFirstName << " " << existingLastName << " "
                    << existingSymptoms << " " << existingBloodType << " "
                    << existingTemperature << " " << existingBloodPressure << " " << existingHeartRate << "\n";
                cout << "Patient details updated successfully.\n";
            }
            else {
                tempFile << existingId << " " << existingFirstName << " " << existingLastName << " "
                    << existingSymptoms << " " << existingBloodType << " "
                    << existingTemperature << " " << existingBloodPressure << " " << existingHeartRate << "\n";
            }
            clearScreen();
        }

        patientFile.close();
        tempFile.close();

        remove(patientFileName);
        rename("temp_patients.txt", patientFileName);

        if (!patientFound) {
            cout << "Patient not found.\n";
        }
    }
    else {
        cout << "Error opening patient file.\n";
    }
    system("pause");

    clearScreen();
}
void removePatient() {
    string patientId;
    cout << "Enter Patient ID to remove: ";
    getline(cin, patientId);


    // Checking if the patient exists
    ifstream patientFile(patientFileName);
    if (patientFile.is_open()) {
        string existingId;
        string existingName, existingSymptoms, existingBloodType, existingTemperature, existingBloodPressure, existingHeartRate;

        bool patientFound = false;
        ofstream tempFile("temp_patients.txt");

        while (patientFile >> existingId >> existingName >> existingSymptoms >> existingBloodType
            >> existingTemperature >> existingBloodPressure >> existingHeartRate) {
            if (existingId == patientId) {
                patientFound = true;
                cout << "Patient removed successfully.\n";
            }
            else {
                tempFile << existingId << " " << existingName << " " << existingSymptoms << " "
                    << existingBloodType << " " << existingTemperature << " "
                    << existingBloodPressure << " " << existingHeartRate << "\n";
            }
        }

        patientFile.close();
        tempFile.close();

        remove(patientFileName);
        rename("temp_patients.txt", patientFileName);

        if (!patientFound) {
            cout << "Patient not found.\n";
        }
    }
    else {
        cout << "Error opening patient file.\n";
    }
    system("pause");

    clearScreen();
}

void viewPatients() {
    ifstream patientFile(patientFileName);

    if (patientFile.is_open()) {
        string patientId;
        string firstName, lastName, symptoms, bloodType, temperature, bloodPressure, heartRate;

        cout << "\n=== List of Patients ===\n";

        while (patientFile >> patientId >> firstName >> lastName >> symptoms >> bloodType
            >> temperature >> bloodPressure >> heartRate) {
            cout << "Patient ID: " << patientId << endl
                << "First Name: " << firstName << endl
                << "Last Name: " << lastName << endl
                << "Symptoms: " << symptoms << endl
                << "Blood Type: " << bloodType << endl
                << "Temperature: " << temperature << endl
                << "Blood Pressure: " << bloodPressure << endl
                << "Heart Rate: " << heartRate << "\n\n";
        }

        patientFile.close();
    }
    else {
        cout << "Error opening patient file.\n";
    }
    cout << "Press Enter to continue...";
    cin.ignore(); 
    clearScreen();
}

void searchPatient() {
    string patientId;
    cout << "Enter Patient ID to search: ";
    getline(cin, patientId);

    // Checking if the patient exists
    ifstream patientFile(patientFileName);
    if (patientFile.is_open()) {
        string existingId;
        string existingFirstName, existingLastName, existingSymptoms, existingBloodType, existingTemperature, existingBloodPressure, existingHeartRate;

        bool patientFound = false;

        while (patientFile >> existingId >> existingFirstName >> existingLastName >> existingSymptoms >> existingBloodType
            >> existingTemperature >> existingBloodPressure >> existingHeartRate) {
            if (existingId == patientId) {
                patientFound = true;
                cout << "\n=== Patient Found ===\n";
                cout << "Patient ID: " << existingId << "\n";
                cout << "First Name: " << existingFirstName << "\n";
                cout << "Last Name: " << existingLastName << "\n";
                cout << "Symptoms: " << existingSymptoms << "\n";
                cout << "Blood Type: " << existingBloodType << "\n";
                cout << "Temperature: " << existingTemperature << "\n";
                cout << "Blood Pressure: " << existingBloodPressure << "\n";
                cout << "Heart Rate: " << existingHeartRate << "\n\n";
                break;
            }
        }

        patientFile.close();

        if (!patientFound) {
            cout << "Patient not found.\n";
        }
    }
    else {
        cout << "Error opening patient file.\n";
    }

    cout << "Press Enter to continue...";
    cin.ignore(); 
    clearScreen();
}
void addAppointment() {
    string firstName, lastName, gender, timing, date, specialist;
    int age, htime, mtime, day, month, year;
    string ampmtime;

    cout << "Enter Patient First Name: ";
    cin.ignore();
    getline(cin, firstName);

    cout << "Enter Patient Last Name: ";
    getline(cin, lastName);

    cout << "Enter Patient Age: ";
    cin >> age;
    if (!(age > 0)) {
        cout << "Invalid AGE." << endl;
        return;
    }

    cout << "Enter Patient Gender ('m' or 'male', 'f' or 'female'): ";
    cin >> gender;
    if (!(gender == "m" || gender == "male" || gender == "f" || gender == "female")) {
        cout << "Invalid gender. Please enter 'm' or 'male' for male, 'f' or 'female' for female." << endl;
        return;
    }
    cin.ignore();

    cout << "Enter Appointment Time:" << endl;
    cout << "Hour: ";
    cin >> htime;
    if (!(htime > 0 && htime < 13)) {
        cout << "Invalid HOUR." << endl;
        return;
    }

    cout << "Minutes: ";
    cin >> mtime;
    if (!(mtime >= 0 && mtime < 60)) {
        cout << "Invalid MINUTES." << endl;
        return;
    }

    cin.ignore();
    cout << "Enter AM/PM: ";
    getline(cin, ampmtime);
    if (!(ampmtime == "am" || ampmtime == "AM" || ampmtime == "pm" || ampmtime == "PM")) {
        cout << "Invalid AM/PM." << endl;
        return;
    }

    timing = to_string(htime) + ":" + (mtime < 10 ? "0" : "") + to_string(mtime)  + ampmtime;

    cout << "Enter Appointment Date: (DD-MM-YYYY)" << endl;

    cout << "DAY: ";
    cin >> day;
    if (!(day > 0 && day <= 31)) {
        cout << "Invalid DAY." << endl;
        return;
    }

    cout << "MONTH: ";
    cin >> month;
    if (!(month > 0 && month <= 12)) {
        cout << "Invalid MONTH." << endl;
        return;
    }

    cout << "YEAR: ";
    cin >> year;
    if (!(year >= 2023)) {
        cout << "Invalid YEAR." << endl;
        return;
    }

    date = to_string(day) + "-" + (month < 10 ? "0" : "") + to_string(month) + "-" + to_string(year);

    cin.ignore();
    cout << "Enter Specialist: ";
    getline(cin, specialist);

    ofstream appointmentFile(appointmentFileName, ios::app);
    if (appointmentFile.is_open()) {
        appointmentFile << firstName << " " << lastName << " " << age << " " << gender << " " << timing << " "
            << date << " " << specialist << "\n";
        appointmentFile.close();
        clearScreen();
        cout << "Appointment added successfully." << endl;
        appointmentPage();
    }
    else {
        cout << "Error opening appointment file for writing." << endl;
    }

    cin.ignore();
    clearScreen();
}

void viewAppointments() {
    ifstream appointmentFile(appointmentFileName);

    if (appointmentFile.is_open()) {
        string firstName, lastName, gender, timing, date, specialist;
        int age;

        cout << "\n=== List of Appointments ===\n";
        if (appointmentFile.peek() == ifstream::traits_type::eof()) {
            cout << "No appointments found.\n";
        }
        else {
            while (appointmentFile >> firstName >> lastName >> age >> gender >> timing >> date >> specialist) {
                cout << "Name: " << firstName << " " << lastName << "\n";
                cout << "Age: " << age << "\n";
                cout << "Gender: " << gender << "\n";
                cout << "Timing: " << timing << "\n";
                cout << "Date: " << date << "\n";
                cout << "Specialist: " << specialist << "\n\n";
            }
        }

        appointmentFile.close();
    }
    else {
        cout << "Error opening appointment file.\n";
    }
    cout << "Press Enter to continue...";
    cin.ignore(); 
    system("pause");
    clearScreen();
}
void generatePrescription() {
    ifstream prescriptionFile("prescription.txt");

    if (prescriptionFile.is_open()) {
        string line;
        cout << "\n=== Patient's Prescription ===\n";

        while (getline(prescriptionFile, line)) {
            cout << line << "\n";
        }

        prescriptionFile.close();
    }
    else {
        cout << "No prescription available.\n";
    }
    system("pause");

    clearScreen();
}


void addPrescription() {
    cin.ignore();
    string patientId;
    cout << "Enter Patient ID: ";
    getline(cin, patientId);

    // Checking if the patient exists
    ifstream patientFile("patients.txt");
    if (patientFile.is_open()) {
        string existingId, firstname, lastname, symptoms, bloodType, temperature, bloodPressure, heartRate;

        bool patientFound = false;

        while (patientFile >> existingId >> firstname >> lastname >> symptoms >> bloodType
            >> temperature >> bloodPressure >> heartRate) {
            if (existingId == patientId) {
                patientFound = true;
               
                ofstream prescriptionFile("prescription.txt", ios::app);
                if (prescriptionFile.is_open()) {
                    prescriptionFile << "Patient ID: " << existingId << "\n";
                    prescriptionFile << "Name: " << firstname + " " + lastname << "\n";
                    prescriptionFile << "Symptoms: " << symptoms << "\n";
                    prescriptionFile << "Blood Type: " << bloodType << "\n";
                    prescriptionFile << "Temperature: " << temperature << "\n";
                    prescriptionFile << "Blood Pressure: " << bloodPressure << "\n";
                    prescriptionFile << "Heart Rate: " << heartRate << "\n";

                    // Add medicines
                    string medicineName;
                    do {
                        cout << "Enter Medicine Name (0 to stop): ";
                        getline(cin, medicineName);

                        if (medicineName != "0") {
                            prescriptionFile << "Medicine: " << medicineName << "\n";
                        }
                    } while (medicineName != "0");

                    prescriptionFile << "\n";

                    cout << "Prescription added successfully.\n";

                    prescriptionFile.close();
                }
                else {
                    cout << "Error opening prescription file for writing.\n";
                }
                break;
            }
        }

        patientFile.close();

        if (!patientFound) {
            cout << "Patient not found. Entered ID: " << patientId << "\n";
        }
    }
    else {
        cout << "Error opening patient file.\n";
    }

   
    cout << "Press enter to exit...";
    cin.ignore();
    clearScreen();
}
void searchMedicine() {
    string medicineName;
    cout << "Enter Medicine Name to search: ";
    cin.ignore();
    getline(cin, medicineName);

    // Checking if the medicine exists
    ifstream medicineFile(medicineFileName);
    if (medicineFile.is_open()) {
        string existingName;
        float existingPrice;

        bool medicineFound = false;

        while (medicineFile >> existingName >> existingPrice) {
            if (existingName == medicineName) {
                medicineFound = true;
                cout << "\n=== Medicine Found ===\n";
                cout << "Medicine Name: " << existingName << "\n";
                cout << "Price: " << existingPrice << "\n\n";
                break;
            }
        }

        medicineFile.close();

        if (!medicineFound) {
            cout << "Medicine not found.\n";
        }
    }
    else {
        cout << "Error opening medicine file.\n";
    }
    system("pause");

    clearScreen();
}

void viewMedicines() {
    ifstream medicineFile(medicineFileName);

    if (medicineFile.is_open()) {
        string name;
        float price;

        cout << "\n=== List of Medicines ===\n";
        while (medicineFile >> name >> price) {
            cout << "Medicine Name: " << name << "\n";
            cout << "Price: " << price << "\n\n";
        }

        medicineFile.close();
    }
    else {
        cout << "Error opening medicine file.\n";
    }
    system("pause");

    clearScreen();
}

void removeMedicine() {
    string medicineName;
    cout << "Enter Medicine Name to remove: ";
    cin.ignore(); 
    getline(cin, medicineName);

    // Checking if the medicine exists
    ifstream medicineFile(medicineFileName);
    if (medicineFile.is_open()) {
        string existingName;
        float existingPrice;

        bool medicineFound = false;
        ofstream tempFile("temp_medicines.txt");

        while (medicineFile >> existingName >> existingPrice) {
            if (existingName == medicineName) {
                medicineFound = true;
                cout << "Medicine removed successfully.\n";
            }
            else {
                tempFile << existingName << " " << existingPrice << "\n";
            }
        }

        medicineFile.close();
        tempFile.close();

        remove(medicineFileName);
        rename("temp_medicines.txt", medicineFileName);

        if (!medicineFound) {
            cout << "Medicine not found.\n";
        }
    }
    else {
        cout << "Error opening medicine file.\n";
    }
    system("pause");

    clearScreen();
}

void updateMedicine() {
    string medicineName;
    float newPrice;

    cout << "Enter Medicine Name to update: ";
    cin.ignore(); 
    getline(cin, medicineName);

    // Checking if the medicine exists
    ifstream medicineFile(medicineFileName);
    if (medicineFile.is_open()) {
        string existingName;
        float existingPrice;

        bool medicineFound = false;
        ofstream tempFile("temp_medicines.txt");

        while (medicineFile >> existingName >> existingPrice) {
            if (existingName == medicineName) {
                medicineFound = true;
                cout << "Enter new price: ";
                cin >> newPrice;
                tempFile << medicineName << " " << newPrice << "\n";
                cout << "Medicine details updated successfully.\n";
            }
            else {
                tempFile << existingName << " " << existingPrice << "\n";
            }
        }

        medicineFile.close();
        tempFile.close();

        remove(medicineFileName);
        rename("temp_medicines.txt", medicineFileName);

        if (!medicineFound) {
            cout << "Medicine not found.\n";
        }
    }
    else {
        cout << "Error opening medicine file.\n";
    }
    system("pause");

    clearScreen();
}

void addMedicine() {
    string medicineName;
    float medicinePrice;

    cout << "Enter Medicine Name: ";
    cin.ignore(); 
    getline(cin, medicineName);

    cout << "Enter Medicine Price: ";
    cin >> medicinePrice;

    ofstream medicineFile(medicineFileName, ios::app);
    if (medicineFile.is_open()) {
        medicineFile << medicineName << " " << medicinePrice << "\n";
        medicineFile.close();
        cout << "Medicine added successfully.\n";
    }
    else {
        cout << "Error opening medicine file for writing.\n";
    }
    system("pause");

    clearScreen();
}

void searchLaboratoryTest() {
    string testName;
    cout << "Enter Laboratory Test Name to search: ";
    cin.ignore(); 
    getline(cin, testName);

    // Checking if the laboratory test exists
    ifstream testFile(testFileName);
    if (testFile.is_open()) {
        string existingName;
        float existingPrice;

        bool testFound = false;

        while (testFile >> existingName >> existingPrice) {
            if (existingName == testName) {
                testFound = true;
                cout << "\n=== Laboratory Test Found ===\n";
                cout << "Test Name: " << existingName << "\n";
                cout << "Price: " << existingPrice << "\n\n";
                break;
            }
        }

        testFile.close();

        if (!testFound) {
            cout << "Laboratory test not found.\n";
        }
    }
    else {
        cout << "Error opening test file.\n";
    }

    system("pause");

    clearScreen();
}


void viewLaboratoryTests() {
    ifstream testFile(testFileName);

    if (testFile.is_open()) {
        string name;
        float price;

        cout << "\n=== List of Laboratory Tests ===\n";
        while (testFile >> name >> price) {
            cout << "Test Name: " << name << "\n";
            cout << "Price: " << price << "\n\n";
        }

        testFile.close();
    }
    else {
        cout << "Error opening test file.\n";
    }
    system("pause");

    clearScreen();
}

void removeLaboratoryTest() {
    string testName;
    cout << "Enter Laboratory Test Name to remove: ";
    cin.ignore(); 
    getline(cin, testName);

    // Checking if the laboratory test exists
    ifstream testFile(testFileName);
    if (testFile.is_open()) {
        string existingName;
        float existingPrice;

        bool testFound = false;
        ofstream tempFile("temp_tests.txt");

        while (testFile >> existingName >> existingPrice) {
            if (existingName == testName) {
                testFound = true;
                cout << "Laboratory test removed successfully.\n";
            }
            else {
                tempFile << existingName << " " << existingPrice << "\n";
            }
        }

        testFile.close();
        tempFile.close();

        remove(testFileName);
        rename("temp_tests.txt", testFileName);

        if (!testFound) {
            cout << "Laboratory test not found.\n";
        }
    }
    else {
        cout << "Error opening test file.\n";
    }
    system("pause");

    clearScreen();
}

void addLaboratoryTest() {
    string testName;
    float testPrice;

    cout << "Enter Laboratory Test Name: ";
    cin.ignore(); 
    getline(cin, testName);

    cout << "Enter Laboratory Test Price: ";
    cin >> testPrice;

    ofstream testFile(testFileName, ios::app);
    if (testFile.is_open()) {
        testFile << testName << " " << testPrice << "\n";
        testFile.close();
        cout << "Laboratory test added successfully.\n";
    } else {
        cout << "Error opening test file for writing.\n";
    }
    system("pause");

    clearScreen();
}

void updateLaboratoryTest() {
    string testName;
    float newPrice;

    cout << "Enter Laboratory Test Name to update: ";
    cin.ignore();
    getline(cin, testName);

    // Checking if the laboratory test exists
    ifstream testFile(testFileName);
    if (testFile.is_open()) {
        string existingName;
        float existingPrice;

        bool testFound = false;
        ofstream tempFile("temp_tests.txt");

        while (testFile >> existingName >> existingPrice) {
            if (existingName == testName) {
                testFound = true;
                cout << "Enter new price: ";
                cin >> newPrice;
                tempFile << testName << " " << newPrice << "\n";
                cout << "Laboratory test details updated successfully.\n";
            }
            else {
                tempFile << existingName << " " << existingPrice << "\n";
            }
        }

        testFile.close();
        tempFile.close();

        remove(testFileName);
        rename("temp_tests.txt", testFileName);

        if (!testFound) {
            cout << "Laboratory test not found.\n";
        }
    }
    else {
        cout << "Error opening test file.\n";
    }
    system("pause");

    clearScreen();
}



// Function to calculate the bill
double calculateBill(double medicineCost, double testCost, bool isEmergency) {
    const double hospitalFee = 1000;
    const double bedFee = 500;
    const double emergencyFee = 500;

    double totalBill = medicineCost + testCost + hospitalFee + bedFee;

    if (isEmergency) {
        totalBill += emergencyFee;
    }

    return totalBill;
}

// Function to check if a given test or medicine exists in a file
bool isItemExists(const char* fileName, const string& itemName) {
    ifstream file(fileName);

    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        if (line.find(itemName) != string::npos) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Function to get the cost of a test or medicine from a file
double getItemCost(const char* fileName, const string& itemName) {
    ifstream file(fileName);

    if (!file) {
        cerr << "Error opening file: " << fileName << endl;
        exit(1);
    }

    string line;
    while (getline(file, line)) {
        if (line.find(itemName) != string::npos) {
            file.close();
            size_t pos = line.find(' ');
            return stod(line.substr(pos + 1));
        }
    }

    file.close();
    return 0; 
}

// Billing function
void billingpage() {
    // Get patient ID
    cout << "Enter Patient ID: ";
    string patientID;
    cin >> patientID;

    // Check if patient exists
    ifstream patientFile(patientFileName);
    if (!patientFile) {
        cerr << "Error opening file: " << patientFileName << endl;
        return;
    }

    bool patientFound = false;
    string line;
    while (getline(patientFile, line)) {
        if (line.find(patientID) != string::npos) {
            patientFound = true;
            break;
        }
    }

    patientFile.close();

    if (!patientFound) {
        cerr << "Patient not found." << endl;
        return;
    }

    // Ask for laboratory tests
    double testCost = 0;
    cout << "Enter Laboratory Tests (Enter 0 to finish): " << endl;
    while (true) {
        string testName;
        cout << "Test Name: ";
        cin >> testName;

        if (testName == "0") {
            break;
        }

        if (isItemExists(testFileName, testName)) {
            testCost += getItemCost(testFileName, testName);
        }
        else {
            cout << "Test not found." << endl;
        }
    }

    // Ask for medicines
    double medicineCost = 0;
    cout << "Enter Medicines and Quantity (Enter 0 to finish): " << endl;
    while (true) {
        string medicineName;
        int quantity;

        cout << "Medicine Name: ";
        cin >> medicineName;

        if (medicineName == "0") {
            break;
        }

        cout << "Quantity: ";
        cin >> quantity;

        if (isItemExists(medicineFileName, medicineName)) {
            medicineCost += getItemCost(medicineFileName, medicineName) * quantity;
        }
        else {
            cout << "Medicine not found." << endl;
        }
    }

    // Check if emergency
    char emergency;
    cout << "Is it an emergency? (y/n): ";
    cin >> emergency;
    bool isEmergency = (emergency == 'y' || emergency == 'Y');

    // Calculate the total bill
    double totalBill = calculateBill(medicineCost, testCost, isEmergency);

    // Output the bill
    cout << fixed << setprecision(2);
    cout << "\n------ Billing Information ------" << endl;
    cout << "Laboratory Test Cost: $" << testCost << endl;
    cout << "Medicine Cost: $" << medicineCost << endl;
    cout << "Hospital Fee: $1000.00" << endl;
    cout << "Bed Fee: $500.00" << endl;
    if (isEmergency) {
        cout << "Emergency Fee: $500.00" << endl;
    }
    cout << "Total Bill: $" << totalBill << endl;

    // Save the billing information to a file
    ofstream billingFile(billingFileName, ios::app);
    if (!billingFile) {
        cerr << "Error opening file: " << billingFileName << endl;
        return;
    }

    billingFile << "Patient ID: " << patientID << "\n";
    billingFile << "Laboratory Test Cost: $" << testCost << "\n";
    billingFile << "Medicine Cost: $" << medicineCost << "\n";
    billingFile << "Hospital Fee: $1000.00\n";
    billingFile << "Bed Fee: $500.00\n";
    if (isEmergency) {
        billingFile << "Emergency Fee: $500.00\n";
    }
    billingFile << "Total Bill: $" << totalBill << "\n\n";

    billingFile.close();

    cout << "\nBilling information saved to " << billingFileName << endl;
    system("pause");
    clearScreen();
}

bool authenticateAdmin() {
    string username, password;

    cout << "Enter admin username: ";
    getline(cin >> ws, username);
    cout << "Enter admin password: ";
    getline(cin, password);

    ifstream adminFile(adminFileName);
    string adminUsername, adminPassword;

    while (adminFile >> adminUsername >> adminPassword) {
        if (adminUsername == username && adminPassword == password) {
            return true;
        }
    }

    return false;
    system("pause");

    clearScreen();

}

void addUsers() {
    string username, password;
    ofstream userFile(userFileName, ios::app);

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    userFile << username << " " << password << endl;
    cout << "User added successfully!\n";
    system("pause");

    clearScreen();

}

void removeUsers() {
    string username, password, inputUsername;
    ifstream userFile(userFileName);
    ofstream tempFile("temp.txt");

    cout << "Enter username to remove: ";
    cin >> inputUsername;

    bool userFound = false;

    while (userFile >> username >> password) {
        if (username == inputUsername) {
            userFound = true;
            cout << "User removed successfully!\n";
        }
        else {
            tempFile << username << " " << password << endl;
        }
    }

    userFile.close();
    tempFile.close();

    if (!userFound) {
        cout << "User not found.\n";
    }
    else {
        remove(userFileName);
        rename("temp.txt", userFileName);
    }

    system("pause");
    clearScreen();
}

void viewUsers() {
    string username, password;
    ifstream userFile(userFileName);

    cout << "Users:\n";
    while (userFile >> username >> password) {
        cout << "Username: " << username <<endl<< "Password: " << password <<endl<< endl;
    }
    system("pause");

    clearScreen();

}

void updateUsers() {
    string oldUsername, oldPassword, newUsername, newPassword;
    ifstream userFile(userFileName);
    ofstream tempFile("temp.txt");

    cout << "Enter old username: ";
    cin >> oldUsername;
    cout << "Enter old password: ";
    cin >> oldPassword;

    bool userFound = false;

    while (userFile >> newUsername >> newPassword) {
        if (oldUsername == newUsername && oldPassword == newPassword) {
            userFound = true;

            cout << "Enter new username: ";
            cin >> newUsername;
            cout << "Enter new password: ";
            cin >> newPassword;

            tempFile << newUsername << " " << newPassword << endl;
            cout << "User updated successfully!\n";
        }
        else {
            tempFile << newUsername << " " << newPassword << endl;
        }
    }

    userFile.close();
    tempFile.close();

    if (!userFound) {
        cout << "User not found or authentication failed.\n";
    }
    else {
        remove(userFileName);
        rename("temp.txt", userFileName);
    }
    system("pause");

    clearScreen();

}

void admin_main() {
    int choice;

    bool authenticated = false;

    do {
        authenticated = authenticateAdmin();

        if (!authenticated) {
            cout << "Authentication failed. Please try again.\n";
        }

    } while (!authenticated);

    do {
        cout << "\n=== Admin Page ===" << endl;
        cout << "1. Add Users\n";
        cout << "2. Update Users\n";
        cout << "3. Remove Users\n";
        cout << "4. View Users\n";
        cout << "5. Back to Home Page\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            clearScreen();
            addUsers();
            break;
        case 2:
            clearScreen();
            updateUsers();

            break;
        case 3:
            clearScreen();
            removeUsers();

            break;
        case 4:
            clearScreen();
            viewUsers();

            break;
        case 5:
            cout << "Exiting...\n";
            clearScreen();
            homePage();

            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5.\n";
        }

    } while (choice != 5);
    system("pause");

    clearScreen();

}