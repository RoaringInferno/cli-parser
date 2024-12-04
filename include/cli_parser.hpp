#pragma once

#include <vector>
#include <string>

namespace largs
{
    class cli_parser
    {
    public:
        struct argument_t
        {
            enum class type : unsigned char
            {
                hard_argument, // A hard argument is an argument that cannot be passed to an option
                soft_argument, // A soft argument is an argument that can be passed to an option
                short_option_string, // A short option string is a string of short options that is passed with a single dash
                long_option, // A long option is an option that is passed with a double dash
                passed_long_option_value // A passed long option value is an option value that was passed to a long option
            };
            typedef type type_t;

            type_t argument_type;
            std::string_view argument_value;
        };
    private:
        std::vector<argument_t> arguments;
    public:
        cli_parser() = default;
        cli_parser(const std::vector<std::string>& raw_argument_list);
        cli_parser(const cli_parser &) = default;
        cli_parser(cli_parser &&) = default;
        cli_parser &operator=(const cli_parser &) = default;
        cli_parser &operator=(cli_parser &&) = default;
        ~cli_parser() = default;

        const std::vector<argument_t> &argument_list() const { return arguments; }
        std::vector<argument_t> &argument_list() { return arguments; }

        void parse(const std::vector<std::string>& raw_argument_list);
    };
} // namespace largs