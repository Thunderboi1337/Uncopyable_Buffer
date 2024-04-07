/**
 * @file test.cpp
 * @author your name (Marcus.Asberg.98@gmail.com)
 * @brief
 * @version 0.1
 * @date 2022-12-01
 *
 * @copyright Copyright (c) 2024
 * g++ test.cpp -o main && ./main
 */

#ifndef BUFFER_H
#define BUFFER_H

template <typename T, size_t N>
class buffer_t
{
private:
    int tail{0};
    int head{0};
    size_t counter{0};
    T buffer[N]{0};

    buffer_t(const buffer_t &) = delete;
    buffer_t &operator=(const buffer_t &) = delete;

public:
    buffer_t() {}

    void clear(void)
    {
        tail = 0;
        head = 0;
        counter = 0;
    }

    T read(void)
    {
        T value{0};

        if (counter != 0)
        {
            value = buffer[head];

            head = (head + 1) % N;

            counter--;
        }

        return value;
    }

    void write(const T &value)
    {
        buffer[tail] = value;
        tail = (tail + 1) % N;

        if (counter == N)
        {
            head = (head + 1) % N;
        }
        else
        {
            counter++;
        }
    }

    int elements(void)
    {

        return counter;
    }

    bool full(void)
    {
        bool full = false;
        if (counter == N)
        {
            full = true;
        }

        return full;
    }

    friend std::ostream &operator<<(std::ostream &os, const buffer_t &buff)
    {

        for (size_t i = 0; i < buff.counter; i++)
        {
            os << buff.buffer[(buff.head + i) % N] << " ";
        }
        return os;
    }

    template <typename T1 = T, typename = typename std::enable_if<std::is_arithmetic<T1>::value>::type>
    double average()
    {
        double sum{0};
        double avg{0};

        if (counter != 0)
        {
            for (size_t i = 0; i < counter; i++)
            {

                sum = sum + buffer[(head + i) % N];
            }
            avg = sum / counter;
        }

        return avg;
    }
};

#endif