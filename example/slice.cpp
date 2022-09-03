#include <boost/mp.hpp>
#include <ranges>

template <auto Begin, auto End>
auto slice = []<class... Ts> {
  return boost::mp::list<Ts...>() |
         std::ranges::views::drop(boost::mp::ct<Begin>) |
         std::ranges::views::take(boost::mp::ct<End>);
};

static_assert((boost::mp::list<int, double, float>() | slice<0, 2>) ==
              boost::mp::list<int, double>());
static_assert((boost::mp::list<int, double, float>() | slice<1, 1>) ==
              boost::mp::list<double>());
static_assert((boost::mp::list<int, double, float>() | slice<1, 2>) ==
              boost::mp::list<double, float>());

int main() {}