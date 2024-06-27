#include <iostream>
#include <string>
using namespace std;

// Define a Hotel class
class Hotel {
private:
    // Define the node structure for linked list
    struct Node {
        int roomId;
        string customerName;
        string dateOfJoining;
        string dateOfExiting;
        string roomType; // Added room type
        Node* next; // Pointer to the next node
    };

    Node* head; // Head of the linked list

public:
    // Constructor
    Hotel() {
        head = nullptr; // Initialize head to nullptr
    }

    // Function to allocate room
    void allocateRoom() {
        int roomId;
        string customerName, dateOfJoining, dateOfExiting, roomType;

        cout << "Enter Room ID: ";
        cin >> roomId;
        cin.ignore(); // Ignore newline character in buffer

        // Check if room ID already exists
        if (findRoom(roomId)) {
            cout << "Room ID " << roomId << " already allocated." << endl;
            return;
        }

        cout << "Enter Customer Name: ";
        getline(cin, customerName);

        cout << "Enter Date of Joining (dd/mm/yyyy): ";
        getline(cin, dateOfJoining);

        cout << "Enter Date of Exiting (dd/mm/yyyy): ";
        getline(cin, dateOfExiting);

        cout << "Enter Room Type (single/double/deluxe): ";
        getline(cin, roomType);

        // Create a new node
        Node* newNode = new Node;
        newNode->roomId = roomId;
        newNode->customerName = customerName;
        newNode->dateOfJoining = dateOfJoining;
        newNode->dateOfExiting = dateOfExiting;
        newNode->roomType = roomType; // Assign room type
        newNode->next = nullptr;

        // Insert at the end of the linked list
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }

        cout << "Room allocated successfully." << endl;
    }

    // Function to delete customer data by room ID
    void deleteCustomerData(int roomId) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->roomId == roomId) {
                // Found the node, delete it
                if (previous == nullptr) {
                    // If it's the first node
                    head = current->next;
                } else {
                    previous->next = current->next;
                }
                delete current;
                cout << "Customer data for Room ID " << roomId << " deleted successfully." << endl;
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Room ID " << roomId << " not found. No data deleted." << endl;
    }

    // Function to update customer details by room ID
    void updateRoomDetails(int roomId) {
        Node* current = head;

        while (current != nullptr) {
            if (current->roomId == roomId) {
                // Found the room, update details
                cout << "Update details for Room ID " << roomId << ":" << endl;

                cout << "Enter Customer Name: ";
                getline(cin, current->customerName);

                cout << "Enter Date of Joining (dd/mm/yyyy): ";
                getline(cin, current->dateOfJoining);

                cout << "Enter Date of Exiting (dd/mm/yyyy): ";
                getline(cin, current->dateOfExiting);

                cout << "Enter Room Type (single/double/deluxe): ";
                getline(cin, current->roomType);

                cout << "Room details updated successfully." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Room ID " << roomId << " not found. No data updated." << endl;
    }

    // Function to sort customer details by room ID and print
    void sortAndPrintByRoomId() {
        // Implement sorting logic here (if needed)
        // For demonstration, let's just print the current list
        Node* current = head;
        int serialNo = 1;

        cout << "\n*********** Customer Details by Room ID ***********\n";
        cout << "Serial No. | Room ID | Customer Name | Date of Joining | Date of Exiting | Room Type\n";
        while (current != nullptr) {
            cout << serialNo << ". ";
            cout << current->roomId << " | ";
            cout << current->customerName << " | ";
            cout << current->dateOfJoining << " | ";
            cout << current->dateOfExiting << " | ";
            cout << current->roomType << endl;

            current = current->next;
            serialNo++;
        }
    }

    // Function to show room records
    void showRoomRecords() {
        // Implement logic to print all room records
        Node* current = head;
        int serialNo = 1;

        cout << "\n*********** Room Records ***********\n";
        cout << "Serial No. | Room ID | Customer Name | Date of Joining | Date of Exiting | Room Type\n";
        while (current != nullptr) {
            cout << serialNo << ". ";
            cout << current->roomId << " | ";
            cout << current->customerName << " | ";
            cout << current->dateOfJoining << " | ";
            cout << current->dateOfExiting << " | ";
            cout << current->roomType << endl;

            current = current->next;
            serialNo++;
        }
    }

private:
    // Private helper function to find a room by its ID
    bool findRoom(int roomId) {
        Node* current = head;

        while (current != nullptr) {
            if (current->roomId == roomId) {
                return true; // Room ID found
            }
            current = current->next;
        }

        return false; // Room ID not found
    }
};

int main() {
    Hotel hotel;
    int choice;
    int roomIdToUpdate;
    int roomIdToDelete;

    do {
        cout << "\n*********** Hotel Management System ***********\n";
        cout << "1. Allocate Room\n";
        cout << "2. Delete Customer Data\n";
        cout << "3. Update Room Details\n";
        cout << "4. Sort and Print by Room ID\n";
        cout << "5. Show Room Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character in buffer

        switch (choice) {
            case 1:
                hotel.allocateRoom();
                break;
            case 2:
                cout << "Enter Room ID to delete customer data: ";
                cin >> roomIdToDelete;
                hotel.deleteCustomerData(roomIdToDelete);
                break;
            case 3:
                cout << "Enter Room ID to update details: ";
                cin >> roomIdToUpdate;
                cin.ignore(); // Ignore newline character in buffer
                hotel.updateRoomDetails(roomIdToUpdate);
                break;
            case 4:
                hotel.sortAndPrintByRoomId();
                break;
            case 5:
                hotel.showRoomRecords();
                break;
            case 6:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please enter again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
