
template <typename U, typename V, typename W>
struct Dim {
  using M = U;  // kg
  using L = V;  // m
  using T = W;  // s

  using type = Dim<M, L, T>;
};