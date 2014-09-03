#include <iostream>
#include <stdexcept>

class Stack
{
    int * m_ip_data, m_i_length, m_i_size; // data - zawartosc stosu, length - ilosc elementow, size - rozmiar zaalokowany

public:
    Stack():m_ip_data(NULL), m_i_length(0), m_i_size(0)
    {
    }

    void push(int value)
    {
        if (m_i_size > m_i_length)
        {
            m_ip_data[m_i_length++] = value;
        }
        else
        {
            int * ip_data = new int [m_i_size+=32];
            for (int i = 0; i < m_i_length; i++)
            {
                ip_data[i] = m_ip_data[i];
            }
            delete [] m_ip_data;
            m_ip_data = ip_data;
            m_ip_data[m_i_length++] = value;
        }
    }

    int pop()
    {
        if (m_i_length == 0)
        {
           throw std::runtime_error("Empty Stack");
        }
        int i_result = m_ip_data[--m_i_length];
        if (2 * m_i_length < m_i_size)
        {
            int * ip_temp = new int [m_i_length];
            for (int i = 0; i < m_i_length; i++)
            {
                ip_temp[i] = m_ip_data[i];
            }
            delete [] m_ip_data;
            m_ip_data = ip_temp;
        }
        return i_result;
    }

    int top()
    {
        if (m_i_length == 0)
        {
           throw std::runtime_error("Empty Stack");
        }
        return m_ip_data[m_i_length - 1];
    }

};

int main()
{

    Stack stos;

    try
    {
       std::cout << stos.top() << std::endl;
    }
    catch(std::runtime_error & execption)
    {
        std::cout << execption.what() << std::endl;
    }

    stos.push(1);
    stos.push(2);
    stos.push(3);

    std::cout << stos.pop() << std::endl;
    std::cout << stos.pop() << std::endl;

    stos.push(1);

    std::cout << stos.top() << std::endl;

    try
    {
        std::cout << stos.pop() << std::endl;
        std::cout << stos.pop() << std::endl;
        std::cout << stos.pop() << std::endl;
    }
    catch(std::runtime_error & execption)
    {
        std::cout << execption.what() << std::endl;
    }




    return 0;
}
