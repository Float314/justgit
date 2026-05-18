#include <iostream>
#include "justgit.hpp"

int main() {

    // Online repository
    repository repo(
        "https://github.com/user/project.git"
    );

    std::cout << "Cloning repository...\n";

    int clone_result = repo.clone("./project");

    if (clone_result == 0) {
        std::cout << "Clone successful!\n";
    } else {
        std::cout << "Clone failed.\n";
        return 1;
    }

    // Change working directory manually if needed
    std::filesystem::current_path("./project");

    std::cout << "Initializing repository...\n";

    int init_result = repo.init();

    if (init_result == 0) {
        std::cout << "Repository initialized.\n";
    }

    std::cout << "Creating commit...\n";

    bool commit_result =
        repo.commit<bool>("Initial commit");

    if (commit_result == 0) {
        std::cout << "Commit successful!\n";
    } else {
        std::cout << "Commit failed.\n";
    }

    return 0;
}