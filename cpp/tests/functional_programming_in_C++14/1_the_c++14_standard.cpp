/*
struct xplusone {
template <typename T>
auto operator ()(const T& x) const->decltype (x+1) {
return x + 1;
};
}xplusone;

//The equivalent in function in C++14 standard is
auto xplusone14 = [] (auto x) {
return x + 1;
};

int main() {

}
*/
