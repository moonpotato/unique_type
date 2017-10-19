#ifndef MPT_UNIQUE_TYPE_HPP
#define MPT_UNIQUE_TYPE_HPP

#include <istream>
#include <ostream>

namespace mpt
{
    template <typename Tag, typename T>
    class unique_type
    {
    private:
        template <typename UTag, typename U>
        friend class unique_type;

        template <typename U>
        using Unique = unique_type<Tag, U>;

    public:
        unique_type() = default;

        explicit unique_type(const T& val) : value(val) {}
        explicit unique_type(T&& val) : value(val) {}

        explicit operator T() const { return value; }
        explicit operator T&() { return value; }

        operator bool() const { return bool(value); }

        template <typename U>
        auto operator +(const Unique<U>& o) const {
            return Unique<decltype(value + o.value)>(value + o.value);
        }
        template <typename U>
        auto operator -(const Unique<U>& o) const {
            return Unique<decltype(value - o.value)>(value - o.value);
        }
        template <typename U>
        auto operator *(const Unique<U>& o) const {
            return Unique<decltype(value * o.value)>(value * o.value);
        }
        template <typename U>
        auto operator /(const Unique<U>& o) const {
            return Unique<decltype(value / o.value)>(value / o.value);
        }
        template <typename U>
        auto operator %(const Unique<U>& o) const {
            return Unique<decltype(value % o.value)>(value % o.value);
        }

    private:
        T value;
    };

    template <typename Tag, typename T>
    std::ostream& operator<<(std::ostream& os, const unique_type<Tag, T>& obj) {
        os << T(obj);
        return os;
    }

    template <typename Tag, typename T>
    std::istream& operator>>(std::istream& is, unique_type<Tag, T>& obj) {
        is >> T(obj);
        return is;
    }
}

#define MPT_UNIQUE_TYPE(name, type) \
    struct name##_tag {}; \
    using name = mpt::unique_type<name##_tag, type>

#define MPT_UNIQUE_TYPE_FAMILY(name) \
    struct name##_tag {}; \
    template <typename T> \
    using name = mpt::unique_type<name##_tag, T>

#endif // MPT_UNIQUE_TYPE_HPP
