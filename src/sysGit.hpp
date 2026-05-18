#include <iostream> 
#include <cstdlib>
#include <fstream>
#include <filesystem>



class repository {
private: 
    std::string repository_lnk; 
    int exitCode;

    void setRepo(const std::string& repo) {
        repository_lnk = repo; 
    }

    int checkIfGitInstalled() { 
        return std::system("git --version > nul 2>&1"); // > nul hides the console output spam
    }

    bool isRepoInit() {
        // Crucial fix: changed "/.git" to ".git" so it looks in the current working directory
        return std::filesystem::exists(".git");
    }

public: 
    repository() = default;

    repository(std::string repo) {
        setRepo(repo); 
    }

    template <typename T = int> 
    T clone(std::string destPath) {
        std::string _cmd = "git clone " + repository_lnk + " " + destPath;
        return static_cast<T>(std::system(_cmd.c_str())); 
    }

    template <typename T = int>
    T init() { 
        return static_cast<T>(std::system("git init")); 
    }

    template <typename T = int>
    T commit(std::string msg) {
        auto cigi = checkIfGitInstalled();

        if (cigi != 0) { // Fixed: checking the variable, not the function pointer
            std::cerr << "GIT ISN'T INSTALLED!" << std::endl;
            return static_cast<T>(1);
        } 
        
        if (!isRepoInit()) { // Fixed: added () to call the function
            std::cerr << "Repo doesnt exist! Call init() first." << std::endl;
            return static_cast<T>(1);
        } 
        
        // Fixed: changed 'std::system' type to 'std::string'
        std::string _cmd = "git commit -m \"" + msg + "\"";
        return static_cast<T>(std::system(_cmd.c_str())); // Added missing .c_str() here too
    }
};