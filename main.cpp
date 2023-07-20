#include<iostream> // For inputs, outputs and other necessary functions needed
#include<fstream> // For file handling (opening, reading, and closing a file)
#include<stdexcept> // For error handling
#include<windows.h> // For cursor positioning and box
#include<random> // For setting random numbers (6 digits) in verification section
#include<ctime> // For random generator using time
/// @brief gotoxy() set a specific location in screen then print something on that area.
/// @param x describes the x coordinate.
/// @param y describes the y coordinate.
void gotoxy(short x, short y){
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void color(){
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
}
/// @brief Box() prints box on a screen based on parameter coordinates.
/// @param x1 is responsible for starting point both x and y coordinates.
/// @param x2 is responsible on last point connected to x1 horizontally.
/// @param y1 is responsible for starting point both x and y coordinates.
/// @param y2 is responsible on last point connected to y1 vertically.
void Box(int x1, int x2, int y1, int y2){
    int temp = 0;
    temp += x1;
    for(x1; x1 <= x2; x1++){
        gotoxy(static_cast<short>(x1), static_cast<short>(y1)); std::cout << '*';
        gotoxy(static_cast<short>(x1), static_cast<short>(y2)); std::cout << '*';
    }
    x1 = temp;
    for(y1; y1 <= y2; y1++){
        gotoxy(static_cast<short>(x1), static_cast<short>(y1)); std::cout << '*';
        gotoxy(static_cast<short>(x2), static_cast<short>(y1)); std::cout << '*';
    }
}
/// @brief choices[] is used mainly fot the main function to let the user choose
/// which topic he/she wants to explore.
std::string choices[] = {
    "1 - People",
    "2 - Timeline",
    "3 - Mactan Battle",
    "4 - 5 Ships",
    "5 - Treaty of Tordesillas",
    "6 - Philippine First Mass",
    "7 - Locations where they docked",
    "8 - Pacific Ocean",
    "9 - Goal of the expedition",
    "10 - Feedback",
    "11 - About the program",
    "12 - Exit"
};
/// @brief Person[] is used to let the use know who are involved in the expedition
/// and who did Magellan and his crew met while they in the Philippines.
std::string Person[] = {
    "1 - Magellan",
    "2 - Lapu-Lapu",
    "3 - Pigafetta",
    "4 - Malacca",
    "5 - Humabon",
    "6 - Siaui & Colambu",
    "7 - Exit"
};
/// @brief Timeline[] is used for identifying the dates of event of the expedition in
/// in the Philippines.
std::string Timeline[] = {
    "1 - March 16, 1521",
    "2 - March 17, 1521",
    "3 - March 18, 1521",
    "4 - March 27, 1521",
    "5 - March 29, 1521",
    "6 - March 31, 1521",
    "7 - April 4, 1521",
    "8 - April 7, 1521",
    "9 - April 27, 1521",
    "10 - May 2, 1521",
    "11 - Sept 30, 1521",
    "12 - Oct 7, 1521",
    "13 - Oct 27, 1521",
    "14 - Exit"
};
/// @brief This variable is used to get the username, show it to the main menu and to use it as part of our review section.
std::string User_name;
// initialized functions
bool Verification();
void set_of_choice(std::string user_choice[], int size);
int input_try_catch(long long choice);
void open_file(const std::string filename);
void Persons();
void Timelines();
void Random_Quiz(std::string filename);
void Loading();
//main function
int main(){

    int choice = 0, num;
    color();
    bool result = Verification();
    // This array is main function files that doesn't have subtopics to open so
    // this files will be access directly as long as the user choose the right cases.
    const std::string Basic_file[] = {
        "Files/Battle_of_Mactan.txt",
        "Files/Ships.txt", 
        "Files/Treaty.txt",
        "Files/First_Mass.txt",
        "Files/Location.txt",
        "Files/Pacific.txt",
        "Files/Expedition.txt",
        "Files/About.txt"
    };
    const std::string Quizz_files[] = {
        "Quiz1.txt",
        "Quiz2.txt",
        "Quiz3.txt"
    };
    // Do while loop is used for the user to repeat choosing the cases
    // to access files as long as user did not choose the exit case
    // the loop will continue.
    // The if statement is responsible for showing the main menu if the user satisfy the verification.
    if(result){
        // This do while loop is responsible for looping the main menu as user not choosing the exit case.
        do{
            system("cls"); // Every loop will clear the screen
            color();
            gotoxy(11, 4); std::cout << "Beyond the Horizon: Magellan's Journey" << std::endl;
            gotoxy(static_cast<short>(((58 - (8 + User_name.length())) / 2) + 2), 5); std::cout << "Welcome " << User_name << std::endl;
            set_of_choice(choices, sizeof(choices)/sizeof(choices[0]));
            choice = input_try_catch(static_cast<long long>(choice));
            switch (choice){
                case 0:
                gotoxy(15, 26); system("pause");
                break;
                case 1: Persons();
                break;
                case 2: Timelines();
                break;
                case 3: open_file(Basic_file[0]); // Here is the example of of direct accessing the file
                gotoxy(15, 26); system("pause");
                break;
                case 4: open_file(Basic_file[1]);
                gotoxy(15, 26); system("pause");
                break;
                case 5: open_file(Basic_file[2]);
                gotoxy(15, 26); system("pause");
                break;
                case 6: open_file(Basic_file[3]);
                gotoxy(15, 26); system("pause");
                break;
                case 7: open_file(Basic_file[4]);
                gotoxy(15, 26); system("pause");
                break;
                case 8: open_file(Basic_file[5]);
                gotoxy(15, 26); system("pause");
                break;
                case 9: open_file(Basic_file[6]);
                gotoxy(15, 26); system("pause");
                case 10:
                srand(static_cast<unsigned int>(time(0)));
                num = rand() % 3 + 1;
                Random_Quiz(Quizz_files[num]);
                break;
                case 11:
                gotoxy(7, 22); std::cout << "Go to the link for feedback (ctrl + click)" << std::endl;
                gotoxy(7, 23); std::cout << "https://bit.ly/Magellan_expedition" << std::endl;
                gotoxy(15, 26); system("pause");
                break;
                case 12: open_file(Basic_file[7]);
                gotoxy(15, 26); system("pause");
                break;
                case 13: // Exit case
                break;
                default: gotoxy(7, 20); std::cout << "That is a invalid choice" << std::endl; // Invalid message
                gotoxy(15, 26); system("pause");
                break;
            }
        }while(choice != 13);
        // If the loop ends it will clear the screen and print the Box() once again the print Thank message.
        system("cls");
        Box(4, 58, 2, 24);
        Box(2, 60, 1, 25);
        gotoxy((60 - 22) / 2, 12); std::cout << "Thank you for visiting" << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
        gotoxy(15, 26); system("pause");
    }
    return 0;
}
/// @brief This function is used to verify the user first by getting his/her name and
/// inputting the right verification code before entering the main menu
/// It uses rand() to generate a random number for verification.
/// @return it returns true if the user satisfy the verification else false if he/she tried 3 times.
bool Verification(){
    std::random_device rand;
    std::mt19937 generator(rand());
    int min = 100000, max = 999999;
    int entered_code = 1, code = 0, counter = 1;
    do{
        system("cls");
        Box(4, 58, 2, 24);
        Box(2, 60, 1, 25);
        std::uniform_int_distribution<int> distribution(min, max);
        code = distribution(generator);
        gotoxy(21, 3); std::cout << "Verification Section" << std::endl;
        gotoxy(6, 5); std::cout << "Enter your name: ";
        std::getline(std::cin >> std::ws, User_name);
        gotoxy(6, 6); std::cout << "Verification code: " << code << std::endl;
        gotoxy(6, 7); std::cout << "Enter the code: ";
        entered_code = input_try_catch(static_cast<long long>(entered_code));
        if(entered_code == code) return true;
        else if(entered_code == 0){
            gotoxy(15, 26); system("pause");
            continue;
        } else {
            gotoxy(6, 8); std::cout << "The verification did not match" << std::endl;
            counter++;
        }
        if(counter > 3){
            system("cls");
            Box(4, 58, 2, 24);
            Box(2, 60, 1, 25);
            gotoxy(14, 12); std::cout << "The verification done unsuccessfully" << std::endl;
            gotoxy(21, 13); std::cout << "Program is terminated" << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
            return false;
        }
        gotoxy(15, 26); system("pause");
    }while(entered_code != code);
    return false;
}
/// @brief This function prints all the values of the chosen array in the console
/// each std::cout has its own coordinates, it share coordinates with x but +1 in each y coordinates
/// as you can see the i + 6 and the y_point increments to identify the possible position of text
/// for inputting in the y axis as you see in its gotoxy so the number of std::cout will defined its position
/// we also built a box for proper layout of the text in the screen.
/// @param user_choice is the array used based on user choice that will print on the console.
/// @param size is the size of the array to identify the stopping condition of the for loop.
void set_of_choice(std::string user_choice[], int size){
    int y_point = 7;
    Box(4, 58, 2, 24);
    Box(2, 60, 1, 25);
    for(int i = 0; i < size; i++){
        gotoxy(7, static_cast<short>(i + 7)); std::cout << user_choice[i] << std::endl;
        y_point++;
    }
    gotoxy(7, static_cast<short>(y_point)); std::cout << "Enter your choice: ";
}
/// @brief This function is used to check inputs that causes errors.
/// it is used to let the user continue the use of the program without
/// terminating the program because of run time errors.
/// @param choice is a parameter, where the input is stored the it
/// checks by the function if the variable is valid.
/// @return it will return the number if the user satisfy the requirement
/// such as inputting a integer, else it will return 0 if the function
/// encounters an error.
int input_try_catch(long long choice){
    try{
        std::cin >> choice;
        Loading();
        std::cin.exceptions(std::ios_base::failbit);
        if(choice > std::numeric_limits<int>::max() || choice < std::numeric_limits<int>::min())
            throw std::overflow_error("The input is out of range");
        return static_cast<int>(choice);
    } catch(const std::ios_base::failure& e){
        system("cls");
        Box(4, 58, 2, 24);
        Box(2, 60, 1, 25);
        if(e.code() == std::make_error_code(std::io_errc::stream)){
            gotoxy(2 + ((60 - 41) / 2), 12); std::cerr << "Exception caught: Input must be integer" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return 0;
        }
    } catch(const std::exception& e){
        system("cls");
        Box(4, 58, 2, 24);
        Box(2, 60, 1, 25);
        gotoxy(2 + ((60 - 43) / 2), 12); std::cerr << "Exception caught: " << e.what() << "\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }
    return 0;
}
/// @brief This function is basically used to read the file and printing it into the console
/// but first we check the longest length in a line of text, it is necessary to print it
/// in the console correctly, then once finished the file closed and reopen to print the file
/// line by line in the console.
/// @param filename is the filename that will be use to open scan, and print into the console.
void open_file(const std::string filename){
    int x_length = 0, i = 4, y_length = 0;
    std::string line;
    std::ifstream File;
    // This part of the function is responsible to scan the length of each lines in the file
    // and the longest length will be stored in the length variable and also scan how many lines
    // are in the file by incrementing y_length varible for each loop.
    // once done close the file
    File.open(filename, std::ios::in);
    if(File.is_open()){
        while(std::getline(File, line)){
            if(line.length() > x_length) x_length = static_cast<int>(line.length());
            y_length++;
        }
    } else {
        gotoxy(21, 23); std::cout << "File did not open" << std::endl;
    }
    File.close();
    // This part of the function is doing the printing, the length and y_length is used
    // to specifically print the line in the center of the box.
    // ones done close the file
    File.open(filename, std::ios::in);
    if(File.is_open()){
        Box(64, x_length + 69, 2, y_length + 5);
        Box(62, x_length + 71, 1, y_length + 6);
        while(std::getline(File, line)){
            gotoxy(static_cast<short>(67 + ((x_length - line.length()) / 2)), static_cast<short>(i)); std::cout << line << std::endl;
            i++;
        }
    } else {
        gotoxy(21, 23); std::cout << "File did not open" << std::endl;
    }
    File.close();
}
/// @brief This function is a subtopic for the case 1 of the main function, it is used
/// to let the user choose which person he/she wants to know.
void Persons(){
    int choice = 0;
    // This is the constant array for the files
    const std::string files[] = {
        "Files/Magellan.txt",
        "Files/Lapulapu.txt",
        "Files/Pigafetta.txt",
        "Files/Malacca.txt",
        "Files/Humabon.txt",
        "Files/Siaui_Colambu.txt"
    };
    // Do while loop for printing the choices, inputting, cases, error handling
    // this part is completely the same as the main function just the number of
    // cases and the file wants to open are the difference.
    do{
        system("cls");
        gotoxy(8, 4); std::cout << "Persons related to the exploration of Magellan" << std::endl;
        set_of_choice(Person, sizeof(Person)/sizeof(Person[0]));
        choice = input_try_catch(static_cast<long long>(choice));
        switch(choice){
            case 0:
            break;
            case 1: open_file(files[0]);
            break;
            case 2: open_file(files[1]);
            break;
            case 3: open_file(files[2]);
            break;
            case 4: open_file(files[3]);
            break;
            case 5: open_file(files[4]);
            break;
            case 6: open_file(files[5]);
            break;
            case 7: // Exit Case
            break;
            default: gotoxy(7, 15); std::cout << "That is a invalid choice" << std::endl; 
        }
        gotoxy(15, 26); system("pause");
    }while(choice != 7);
}
/// @brief This function is a subtopic for the case 2 of the main function, it is used
/// to let the user choose which timeline he/she wants to know.
void Timelines(){
    int choice = 0;
    // This is the constant array for the files
    const std::string files[] = {
        "Files/16March1521.txt",
        "Files/17March1521.txt",
        "Files/18March1521.txt",
        "Files/27March1521.txt",
        "Files/29March1521.txt",
        "Files/31March1521.txt",
        "Files/4April1521.txt",
        "Files/7April1521.txt",
        "Files/27April1521.txt",
        "Files/2May1521.txt",
        "Files/30Sept1521.txt",
        "Files/7Oct1521.txt",
        "Files/27Oct1521.txt"
    };
    // Do while loop for printing the choices, inputting, cases, error handling
    // this part is completely the same as the main function just the number of
    // cases and the file wants to open are the difference.
    do{
        system("cls");
        gotoxy(10, 4); std::cout << "Timelines of expedition in the Philippines" << std::endl;
        set_of_choice(Timeline, sizeof(Timeline)/sizeof(Timeline[0]));
        choice = input_try_catch(static_cast<long long>(choice));
        switch(choice){
            case 0:
            break;
            case 1: open_file(files[0]);
            break;
            case 2: open_file(files[1]);
            break;
            case 3: open_file(files[2]);
            break;
            case 4: open_file(files[3]);
            break;
            case 5: open_file(files[4]);
            break;
            case 6: open_file(files[5]);
            break;
            case 7: open_file(files[6]);
            break;
            case 8: open_file(files[7]);
            break;
            case 9: open_file(files[8]);
            break;
            case 10: open_file(files[9]);
            break;
            case 11: open_file(files[10]);
            break;
            case 12: open_file(files[11]);
            break;
            case 13: open_file(files[12]);
            break;
            case 14: // Exit case
            break;
            default: gotoxy(7, 22); std::cout << "That is a invalid choice" << std::endl;
            break;
        }
        gotoxy(15, 26); system("pause");
    }while(choice != 14);
}
/// @brief This function is responsible for printing, aswering and counting of scores
/// The function will use the text files to gather all questions, answers and keys
/// that shall be stored in a structure named Quizz_content.
/// This function will open the file since it has different approach.
/// @param filename the filename is a parameter to open a specific file related to
/// quiz game, the file is randomly selected in the main function case 10.
void Random_Quiz(std::string filename){
    struct Quizz_content{
        std::string question;
        std::string choices[4];
        std::string key;
    };
    std::vector<std::string> contents;
    std::ifstream file;
    std::string line;
    char choice = 0;
    file.open(filename, std::ios::in);
    if(file.is_open()){
        while(std::getline(file, line)) contents.push_back(line);
    } else {
        gotoxy(21, 23); std::cout << "The file did not open" << std::endl;
    }
    Quizz_content quiz_set[5];
    int score = 0;
    for(int i = 0, j = 0; i < 5; i++, j += 6){
        quiz_set[i].question = contents[j];
        quiz_set[i].key = contents[j+1];
        quiz_set[i].choices[0] = contents[j+2];
        quiz_set[i].choices[1] = contents[j+3];
        quiz_set[i].choices[2] = contents[j+4];
        quiz_set[i].choices[3] = contents[j+5];
    }
    for(int i = 0; i < 5; i++){
        std::cout << quiz_set[i].question << std::endl;
        for(int j = 0; j < 4; j++){
            std::cout << quiz_set[i].choices[j] << std::endl;
        }
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if(choice == quiz_set[i].key[0]){
            std::cout << "You are correct!" << std::endl;
            score++;
        } else {
            std::cout << "Wrong! The correct answer is: " << quiz_set[i].key << std::endl;
        }
    }
    std::cout << "Your score is: " << score << '/' << 5 << std::endl;
    switch(score){
        case 5: std::cout << "You're smart huh! ;)" << std::endl;
        break;
        case 4: std::cout << "One more to be perfect, well done." << std::endl;
        break;
        case 3: std::cout << "3/5 well done" << std::endl;
        break;
        case 2: std::cout << "Need some progress" << std::endl;
        break;
        case 1: std::cout << "Sorry! The quizz did not fit to your knowledge" << std::endl;
        break;
        case 0: std::cout << "You must like eggs don't you?" << std::endl;
        break;
    }
    gotoxy(15, 26); system("pause");
}
/// @brief This function is used to create a loading text on the screen as part of
/// of the program's feature, this will used symbols like '-', '\\', '|', '/'
/// to create a rotating lines that will be helped by the Sleep function to have
/// time to rotate or refresh the character in the screen. And the last std::cout
/// is used to clear the Loading text if the loading loop is done.
void Loading(){
    char symbols[] = {'-', '\\', '|', '/'};
    srand(static_cast<unsigned int>(time(0)));
    int result = rand() % 4 + 1;
    for(int i = 0; i < result; i++){
        for(int j = 0; j < 4; j++){
            gotoxy(25, 23); std::cout << "Loading " << symbols[j] << '\r' << std::endl;
            Sleep(100);
        }
    }
    gotoxy(25, 23); std::cout << "           " << std::endl;
}