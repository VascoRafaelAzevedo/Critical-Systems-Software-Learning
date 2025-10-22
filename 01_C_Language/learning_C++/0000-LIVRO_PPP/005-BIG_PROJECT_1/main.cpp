#include <iostream>
#include <vector>

const int MULTIPLY_CODE = 42;
const int DIVIDE_CODE = 47;
const int SUM_CODE = 43;
const int MINUS_CODE = 45;

const int ZERO_CODE = 48;
const int NINE_CODE = 57;
const int DOT_CODE = 46;

const int OPEN_BRACKET_CODE = 40;
const int CLOSE_BRACKET_CODE = 41;

bool is_number(int c)
{
    if (c < ZERO_CODE || c > NINE_CODE)
    {
        return false;
    }
    return true;
}

std::string remove_white_spaces(std::string input)
{
    std::string output;
    bool dont_put_number;

    for (char &c : input)
    {
        if (c != ' ')
        {
            if (dont_put_number && is_number((int)c))
            {
                std::cerr << "ERROR: 2 numbers in a row without operator" << std::endl;
                std::cerr << "ERROR: the expression provided does not have valid syntax" << std::endl;
                exit(1);
            }

            output += c;
        }
        else
        {
            if (is_number((int)output[output.length() - 1]))
            {
                dont_put_number = true;
            }
        }
    }
    std::cout << output << std::endl;
    return output;
}

bool is_operator(int c)
{

    if (c == MULTIPLY_CODE || c == SUM_CODE || c == MINUS_CODE || c == DIVIDE_CODE)
    {
        return true;
    }
    return false;
}

bool is_bracket(int c)
{
    if (c == OPEN_BRACKET_CODE || c == CLOSE_BRACKET_CODE)
    {
        return true;
    }
    return false;
}

bool is_floating_point(int c)
{
    if (c == DOT_CODE)
    {
        return true;
    }
    return false;
}

bool validate_start_end(int start, int end)
{

    if (!is_number(start) && !is_bracket(start))
    {

        std::cerr << "ERROR: start not correct" << std::endl;
        return false;
    }

    if (!is_number(end) && !is_bracket(end))
    {
        std::cerr << "ERROR: end not correct" << std::endl;
        return false;
    }

    return true;
}

bool valid_expression(std::string input)
{
    int open_bracket_counter{0};

    if (!validate_start_end((int)input[0], (int)input[input.length() - 1]))
    {
        return false;
    }

    for (int i{0}; i < input.length(); i++)
    {
        char c = (int)input[i];

        if (is_operator(c))
        {
            if (c != MINUS_CODE && is_operator((int)input[i - 1])) // 2 operators in a row not counting negative nunumbers
            {
                std::cerr << "ERROR: 2 operators in a row" << std::endl;
                return false;
            }
            if (c == DIVIDE_CODE && (int)input[i + 1] == ZERO_CODE) // division by 0
            {
                std::cerr << "ERROR: divide by 0" << std::endl;
                return false;
            }
            if (!is_number((int)input[i - 1]) && (int)input[i - 1] != CLOSE_BRACKET_CODE) // division by 0
            {
                std::cerr << "ERROR: operator not after number or close bracket" << std::endl;
                return false;
            }
        }
        else if (is_bracket(c))
        {
            if (c == OPEN_BRACKET_CODE)
            {

                ++open_bracket_counter;
            }
            else
            {
                if (!is_number((int)input[i - 1]) && input[i - 1] != CLOSE_BRACKET_CODE && input[i - 1] != OPEN_BRACKET_CODE)
                {
                    std::cerr << "ERROR: close bracket not after number or valid bracket" << std::endl;
                }

                --open_bracket_counter;
            }
            if (open_bracket_counter < 0)
            {
                std::cerr << "ERROR: bracket negative" << std::endl;
                return false;
            }
        }
        else if (is_floating_point(c))
        {
            if (!is_number(input[i + 1]) || !is_number(input[i - 1])) // floatin gpoint is between numbers
            {
                std::cerr << "ERROR: floating point not between numbers" << std::endl;
                return false;
            }
        }
        else if (!is_number(c))
        {
            std::cerr << "ERROR: Else index - " << i << std::endl;
            std::cerr << "ERROR: Else char - " << c << std::endl;
            return false;
        }
    }

    if (open_bracket_counter > 0)
    {
        std::cerr << "ERROR: final bracket count not 0" << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> tokenize(std::string input)
{
    std::vector<std::string> tokens;
    std::string temp;

    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];

        if (is_number(c) || is_floating_point(c))
        {
            temp += c; // acumula dígitos e pontos
        }
        else if (is_operator(c) || is_bracket(c))
        {
            // se há número acumulado, guarda-o primeiro
            if (!temp.empty())
            {
                tokens.push_back(temp);
                temp.clear();
            }
            // guarda o operador/bracket
            tokens.push_back(std::string(1, c));
        }
    }

    // não esquecer o último número!
    if (!temp.empty())
    {
        tokens.push_back(temp);
    }

    return tokens;
}

int precedence(char op)
{
    if (op == MULTIPLY_CODE || op == DIVIDE_CODE)
        return 2;
    if (op == SUM_CODE || op == MINUS_CODE)
        return 1;
    return 0;
}

std::vector<std::string> shunting_yard(std::vector<std::string> tokens)
{
    std::vector<std::string> post_fixed_tokens;
    std::vector<std::string> temp_op_stack;

    for (std::string token : tokens)
    {
        if (is_number((int)token[0]))
        {
            post_fixed_tokens.push_back(token);
        }
        else if ((int)token[0] == OPEN_BRACKET_CODE)
        {
            temp_op_stack.push_back(token);
        }
        else if ((int)token[0] == CLOSE_BRACKET_CODE)
        {
            std::string out_of_stack = temp_op_stack.back();
            temp_op_stack.pop_back();
            while ((int)out_of_stack[0] != OPEN_BRACKET_CODE)
            {
                post_fixed_tokens.push_back(out_of_stack);
                out_of_stack = temp_op_stack.back();
                temp_op_stack.pop_back();
            }
        }
        else if (is_operator((int)token[0]))
        {
            while (!temp_op_stack.empty() &&
                   is_operator(temp_op_stack.back()[0]) &&
                   precedence(temp_op_stack.back()[0]) >= precedence(token[0]))
            {
                post_fixed_tokens.push_back(temp_op_stack.back());
                temp_op_stack.pop_back();
            }

            temp_op_stack.push_back(token);
        }
    }
    while (!temp_op_stack.empty())
    {
        post_fixed_tokens.push_back(temp_op_stack.back());
        temp_op_stack.pop_back();
    }
    return post_fixed_tokens;
}

double evaluate(std::vector<std::string> operations)
{
    std::vector<double> values_stack;

    for (std::string token : operations)
    {
        if (is_number((int)token[0]))
        {
            values_stack.push_back(std::stod(token));
        }
        else
        {
            double op1 = values_stack.back();
            values_stack.pop_back();

            double op2 = values_stack.back();
            values_stack.pop_back();

            double temp_value{};

            if ((int)token[0] == SUM_CODE)
            {
                temp_value = op2 + op1;
            }
            else if ((int)token[0] == MINUS_CODE)
            {
                temp_value = op2 - op1;
            }
            else if ((int)token[0] == MULTIPLY_CODE)
            {
                temp_value = op2 * op1;
            }
            else if ((int)token[0] == DIVIDE_CODE)
            {
                temp_value = op2 / op1;
            }

            values_stack.push_back(temp_value);
        }
    }

    return values_stack.back();
}

bool verify_floats(std::vector<std::string> tokens)
{
    for (std::string token : tokens)
    {
        if (is_number(token[0]))
        {
            int dot_count = 0;
            for (char c : token)
            {
                if (c == '.')
                    dot_count++;
            }
            if (dot_count > 1)
            {
                std::cerr << "ERROR: invalid number format" << std::endl;
                std::cerr << "ERROR: number " << token << " is not a valid number" << std::endl;
                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::string input;
    std::cout << "Please insert the algebric expression:" << std::endl;
    getline(std::cin, input);

    // clean the string
    std::string input_clean{remove_white_spaces(input)};
    if (!valid_expression(input_clean))
    {
        std::cerr << "ERROR: the expression provided does not have valid syntax" << std::endl;
        return 1;
    }
    std::vector<std::string> tokens{tokenize(input_clean)};

    if (!verify_floats(tokens))
    {
        std::cerr << "ERROR: the expression provided does not have valid syntax" << std::endl;
        return 1;
    }

    for (std::string token : tokens)
    {
        std::cout << token << "   |   ";
    }
    std::cout << std::endl;

    std::vector<std::string> post_fixed_tokens{shunting_yard(tokens)};

    std::cout << "POST FIXED" << std::endl;
    std::cout << std::endl;

    if (!post_fixed_tokens.empty())
    {
        for (std::string token : post_fixed_tokens)
        {
            std::cout << token << "   |   ";
        }
        std::cout << std::endl;
        double evaluation{evaluate(post_fixed_tokens)};
        std::cout << "EVALUATION OF EXPRESSION\n";
        std::cout << evaluation << std::endl;
        return 0;
    }
    std::cout << "EVALUATION OF EXPRESSION\n";
    std::cout << "EMPTY EXPRESSION\n";
    return 1;
}