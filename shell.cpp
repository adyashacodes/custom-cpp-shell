#include <iostream>
#include <string>
#include <vector>
#include <sstream>      // Used for splitting the input string
#include <unistd.h>     // For gethostname()
#include <sys/types.h>  // For getpwuid()
#include <pwd.h>        // For getpwuid()

// Using C++ OOP principles from the 'Overview of OOPs.pdf'
class Shell {
private:
    std::string username;
    std::string hostname;
    bool running;

public:
    // Constructor: Initializes the shell [cite: 2622-2624]
    Shell() {
        running = true;

        // Get username
        struct passwd *pw;
        uid_t uid = geteuid();
        pw = getpwuid(uid);
        if (pw) {
            username = pw->pw_name;
        } else {
            username = "user";
        }

        // Get hostname
        char host[256];
        if (gethostname(host, sizeof(host)) == 0) {
            hostname = host;
        } else {
            hostname = "localhost";
        }
    }

    // Main loop for the shell
    void run() {
        std::string input_line;

        while (running) {
            printPrompt();
            
            if (!std::getline(std::cin, input_line)) {
                std::cout << "exit" << std::endl;
                break; // Exit on Ctrl+D (EOF)
            }

            if (input_line.empty()) {
                continue; // Show prompt again
            }

            // Parse the input
            std::vector<std::string> args = parseInput(input_line);

            // Handle built-in commands
            if (handleBuiltin(args)) {
                continue; // Command was a builtin, loop again
            }
            
            // --- Day 2 will add execution here ---
            // For Day 1, we just print the parsed arguments
            std::cout << "Parsed arguments: " << std::endl;
            for (const std::string& arg : args) {
                std::cout << "  - '" << arg << "'" << std::endl;
            }
        }
    }

private:
    // Displays the shell prompt (e.g., uvaers@hostname:~$ )
    void printPrompt() {
        std::cout << username << "@" << hostname << ":~$ ";
        std::flush(std::cout);
    }

    // Parses a line of input into a vector of arguments
    std::vector<std::string> parseInput(const std::string& input) {
        std::vector<std::string> args;
        std::stringstream ss(input);
        std::string word;

        while (ss >> word) {
            args.push_back(word);
        }
        return args;
    }

    // Handles built-in shell commands
    bool handleBuiltin(const std::vector<std::string>& args) {
        if (args.empty()) {
            return false;
        }

        if (args[0] == "exit") {
            running = false;
            return true;
        }
        
        // (We will add 'cd' here in a later step)

        return false;
    }
};

int main() {
    Shell myShell;
    myShell.run(); // Start the shell
    return 0;
}
