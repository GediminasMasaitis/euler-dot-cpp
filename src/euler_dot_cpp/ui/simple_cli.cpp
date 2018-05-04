#include "stdafx.hpp"
#include "simple_cli.hpp"

using namespace std;

simple_cli::simple_cli(benchmarker& bm, problems_map& problems): ui_base(bm, problems)
{
}

static void print_help()
{
    stringstream ss;
    ss << "Project Euler dot cpp, by Gediminas Masaitis" << endl << endl;
    ss << "{problem_id}            Solves and benchmarks the problem, then prints the results" << endl;
    ss << "list                    Shows available problems and their status" << endl;
    ss << "help                    Prints this help dialogue" << endl;
    ss << "exit                    Finishes work and quits" << endl;
    ss << endl;
    const auto str = ss.str();
    puts(str.c_str());
}

static void print_problems(problems_map& problems)
{
    stringstream ss;
    auto border = "+--------+--------------------------------------------+--------------+--------------+";
    ss << border << endl;
    ss << "|  ID    |   Name                                     |  Difficulty  |  Status      |" << endl;
    ss << border << endl;
    auto last10 = 0;
    for (const auto& pair : problems)
    {
        const auto this10 = pair.first / 10;
        if (this10 != last10)
        {
            last10 = this10;
            ss << border << endl;
        }
        auto& problem = *pair.second;
        //const auto answer = problem.solved ? to_string(problem.answer) : "UNSOLVED";
        const auto status = problem.solved ? "Solved" : "UNSOLVED";
        ss << "|  " << setw(4) << right << problem.id << "  |  " << setw(40) << left << problem.name << "  |  " << setw(10) << problem.difficulty << "  |  " << setw(10) << status << "  |" << endl;
    }
    ss << border << endl;
    ss << endl;
    const auto str = ss.str();
    //cout << str;
    puts(str.c_str());
}

void simple_cli::run()
{
    print_help();
    
    while(true)
    {
        string str;
        cin >> str;

        if(str == "list")
        {
            print_problems(problems);
        }
        else if (str == "help")
        {
            print_help();
        }
        else if (str == "exit" || str == "quit")
        {
            return;
        }
        else
        {
            const auto problem_id = stoi(str);
            const auto problem_it = problems.find(problem_id);
            if (problem_it == problems.end())
            {
                cout << "Problem " << problem_id << " not found!" << endl;
                return;
            }

            auto& problem = *problem_it->second;
            benchmark::ConsoleReporter reporter;
            bm.run_benchmarks(problem, reporter);
        }
    }
}