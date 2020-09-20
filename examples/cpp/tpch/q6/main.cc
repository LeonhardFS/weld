//
// Created by Leonhard Spiegelberg on 9/19/20.
//

#include <iostream>
#include "../../../../weld-capi/weld.h"
using namespace std;

// @TODO: need to load FULL data, so it's fair to the other frameworks...
template <typename T>
struct weld_vector {
    T *data;
    int64_t length;
};

struct args {
    struct weld_vector<int32_t> shipdates;
    struct weld_vector<double> discounts;
    struct weld_vector<double> quantities;
    struct weld_vector<double> extended_prices;
};

template <typename T>
weld_vector<T> make_weld_vector(T *data, int64_t length) {
    struct weld_vector<T> vector;
    vector.data = data;
    vector.length = length;
    return vector;
}


const char* program = "|l_shipdate: vec[i32], l_discount: vec[f64], l_quantity: vec[f64], l_ep: vec[f64]|\n"
                      "    result(for(\n"
                      "        map(\n"
                      "            filter(\n"
                      "                zip(l_shipdate, l_discount, l_quantity, l_ep), \n"
                      "                |x| x.$0 >= 19940101 && x.$0 < 19950101 && x.$1 >= 0.05 && x.$1 <= 0.07 && x.$2 < 24.0\n"
                      "            ), |x| x.$1 * x.$3\n"
                      "        ), \n"
                      "        merger[f64,+], \n"
                      "        |b,i,x| merge(b,x)\n"
                      "    ))\n"
                      "";

int main(int argc, char* argv[]) {
    cout<<"Hello world"<<endl;


    weld_error_t  e = weld_error_new();
    weld_conf_t conf = weld_conf_new();

    weld_module_t m = weld_module_compile(program, conf, e);
    weld_conf_free(conf);
    if (weld_error_code(e)) {
        const char *err = weld_error_message(e);
        cerr<<"Error message: "<<err<<endl;
        exit(1);
    }


    return 0;
}