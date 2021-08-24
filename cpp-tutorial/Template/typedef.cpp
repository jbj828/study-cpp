#if defined USING_COMPILER_A
typedef __int32 Int32;
typedef __int64 Int64;
#elif defined USING_COMPILER_B
typedef int Int32;
typedef long long Int64;
#endif

class MyTypeClass {
 public:
  typedef int Type1;
};

int main() {
  MyTypeClass a;
  MyTypeClass::Type1 b;
  return 0;
}