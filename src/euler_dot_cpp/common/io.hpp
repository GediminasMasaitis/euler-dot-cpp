#pragma once
inline void open_input(const std::string name, std::ifstream& ifs)
{
    constexpr auto inputs_path = "./inputs/";
    const auto path = inputs_path + name;
    ifs.open(path);
    if (!ifs.good())
    {
        // TODO: later
    }
}

inline std::istream& getline_s(std::istream& is, std::string& str, const char delim)
{
    auto& strm = std::getline(is, str, delim);
    while(str.back() == '\n' || str.back() == '\r')
    {
        str.erase(str.size() - 1);
    }
    return is;
}

template<typename T>
std::vector<std::vector<T>> read_matrix(const std::string name)
{
    std::vector<std::vector<T>> data;

    std::ifstream ifs;
    open_input(name, ifs);

    while (!ifs.eof())
    {
        data.emplace_back();
        auto& arr = data.back();

        std::string line;
        getline_s(ifs, line, '\n');
        std::stringstream line_ss(line);

        while (!line_ss.eof())
        {
            T num;
            line_ss >> num;
            arr.emplace_back(num);
        }
    }
    return data;
}

inline std::vector<std::string> read_all_lines(const std::string name)
{
    std::vector<std::string> lines;
    std::ifstream ifs;
    open_input(name, ifs);

    while (!ifs.eof())
    {
        lines.emplace_back();
        auto& line = lines.back();
        getline_s(ifs, line, '\n');
    }
    return lines;
}

inline std::vector<std::string> read_string_list(const std::string name)
{
    std::vector<std::string> strings;

    std::string all_text;

    {
        std::ifstream ifs;
        open_input(name, ifs);
        getline_s(ifs, all_text, '\n');
    }

    std::stringstream ss;
    ss << all_text;

    while (!ss.eof())
    {
        std::string _;
        getline(ss, _, '"');
        std::string name;
        getline(ss, name, '"');
        strings.push_back(name);
    }

    return strings;
}