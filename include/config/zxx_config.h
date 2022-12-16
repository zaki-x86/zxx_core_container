#if __cplusplus >= 201103L
#define GLIBZXX_CONSTEXPR constexpr  
#endif
#if __cplusplus >= 201703L
#define GLIBZXX_CONSTEXPR constexpr
#endif
#if __cplusplus >= 202003L
#define GLIBZXX_CONSTEXPR constexpr
#endif


#if __cplusplus >= 201703L

#define BEGIN_NS_ZXX_CORE_CONTAINER namespace zxx::core::container {
#define END_NS_ZXX_CORE_CONTAINER }

#else

#define BEGIN_NS_ZXX_CORE_CONTAINER             \
    namespace zxx {                             \
            namespace core {                    \
                namespace container {           \

#define END_NS_ZXX_CORE_CONTAINER  }}}
#endif

#if __cplusplus >= 201703L

#define BEGIN_NS_ZXX_CORE_CONTAINER_TEST namespace zxx::core::container::test {
#define END_NS_ZXX_CORE_CONTAINER_TEST }

#else

#define BEGIN_NS_ZXX_CORE_CONTAINER_TEST        \
    namespace zxx {                             \
            namespace core {                    \
                namespace container {           \
                    namespace test {            \

#define END_NS_ZXX_CORE_CONTAINER_TEST  }}}}


#endif