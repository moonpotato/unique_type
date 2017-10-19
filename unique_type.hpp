#ifndef MPT_UNIQUE_TYPE_HPP
#define MPT_UNIQUE_TYPE_HPP

#include <istream>
#include <ostream>

#include <type_traits>

namespace mpt
{
    template <typename Tag, typename T>
    class unique_type
    {
        static_assert(std::is_arithmetic<T>::value, "unique_type not given arithmetic type");

    private:
        template <typename UTag, typename U>
        friend class unique_type;

        template <typename U>
        using Unique = unique_type<Tag, U>;

    public:
        unique_type() = default;

        explicit unique_type(const T& val) : value{val} {}
        explicit unique_type(T&& val) : value{val} {}

        explicit operator T() const { return value; }
        explicit operator T&() { return value; }

        explicit operator bool() const { return bool(value); }
        bool operator !() const { return !value; }

        template <typename U>
        auto operator +(const Unique<U>& o) const {
            return Unique<decltype(value + o.value)>(value + o.value);
        }

        template <typename U>
        auto& operator +=(const Unique<U>& o) {
            value += o.value;
            return *this;
        }

        template <typename U>
        auto operator -(const Unique<U>& o) const {
            return Unique<decltype(value - o.value)>(value - o.value);
        }

        template <typename U>
        auto& operator -=(const Unique<U>& o) {
            value -= o.value;
            return *this;
        }

        template <typename U>
        auto operator *(const Unique<U>& o) const {
            return Unique<decltype(value * o.value)>(value * o.value);
        }

        template <typename U>
        auto& operator *=(const Unique<U>& o) {
            value *= o.value;
            return *this;
        }

        template <typename U>
        auto operator /(const Unique<U>& o) const {
            return Unique<decltype(value / o.value)>(value / o.value);
        }

        template <typename U>
        auto& operator /=(const Unique<U>& o) {
            value /= o.value;
            return *this;
        }

        template <typename U>
        auto operator %(const Unique<U>& o) const {
            return Unique<decltype(value % o.value)>(value % o.value);
        }

        template <typename U>
        auto& operator %=(const Unique<U>& o) {
            value %= o.value;
            return *this;
        }

        template <typename U>
        auto operator ^(const Unique<U>& o) const {
            return Unique<decltype(value ^ o.value)>(value ^ o.value);
        }

        template <typename U>
        auto& operator ^=(const Unique<U>& o) {
            value ^= o.value;
            return *this;
        }

        template <typename U>
        auto operator &(const Unique<U>& o) const {
            return Unique<decltype(value & o.value)>(value & o.value);
        }

        template <typename U>
        auto& operator &=(const Unique<U>& o) {
            value &= o.value;
            return *this;
        }

        template <typename U>
        auto operator |(const Unique<U>& o) const {
            return Unique<decltype(value | o.value)>(value | o.value);
        }

        template <typename U>
        auto& operator |=(const Unique<U>& o) {
            value |= o.value;
            return *this;
        }

        template <typename U>
        auto operator ~() const {
            return Unique<decltype(~value)>(~value);
        }

        template <typename U>
        auto operator <<(const Unique<U>& o) const {
            return Unique<decltype(value << o.value)>(value << o.value);
        }

        template <typename U>
        auto& operator <<=(const Unique<U>& o) {
            value <<= o.value;
            return *this;
        }

        template <typename U>
        auto operator >>(const Unique<U>& o) const {
            return Unique<decltype(value >> o.value)>(value >> o.value);
        }

        template <typename U>
        auto& operator >>=(const Unique<U>& o) {
            value >>= o.value;
            return *this;
        }

        auto& operator ++() { return ++value, *this; }
        auto operator ++(int) { return Unique<T>(value++); }

        auto& operator --() { return --value, *this; }
        auto operator --(int) { return Unique<T>(value--); }

        template<typename U>
        bool operator ==(const Unique<U>& o) const { return value == o.value; }

        template<typename U>
        bool operator !=(const Unique<U>& o) const { return value != o.value; }

        template<typename U>
        bool operator <(const Unique<U>& o) const { return value < o.value; }

        template<typename U>
        bool operator >(const Unique<U>& o) const { return value > o.value; }

        template<typename U>
        bool operator <=(const Unique<U>& o) const { return value <= o.value; }

        template<typename U>
        bool operator >=(const Unique<U>& o) const { return value >= o.value; }

    private:
        T value;
    };

    template <typename T>
    struct universal_type
    {
        operator T() const { return val; }
        operator T&() { return val; }

        template <typename Tag>
        operator unique_type<Tag, T>() {
            return unique_type<Tag, T>{val};
        }

        T val;
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

    template <typename T>
    universal_type<T> W(const T& wrap) {
        return universal_type<T>{wrap};
    }

    template <typename T>
    universal_type<T> W(T&& wrap) {
        return universal_type<T>{wrap};
    }

    template <typename Tag, typename T>
    T E(const unique_type<Tag, T>& extract_from) {
        return static_cast<T>(extract_from);
    }

    template <typename Tag, typename T>
    T& E(unique_type<Tag, T>& extract_from) {
        return static_cast<T&>(extract_from);
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
