#include <pybind11/pybind11.h>

#include <msgpack.hpp>

struct your_class {
    int a;
    std::string b;
    MSGPACK_DEFINE(a, b);
};
std::string msg() {
    std::stringstream ss;
    msgpack::pack(ss, your_class{42,"hello"});
    return ss.str();
}

extern void pq();


int add(int i, int j) {
    return i + j;
}

PYBIND11_MODULE(freedomdb, m) {
    m.doc() = "Python version of FreedomDB library"; // optional module docstring

    m.def("add", &add, "A function which adds two numbers");
    m.def("msg", &msg, "MessagePack!");
    m.def("pq", &pq, "PostgreSQL!");
}
