#ifndef MPT_UNIQUE_TYPE_HPP
#define MPT_UNIQUE_TYPE_HPP

#include <istream>
#include <ostream>

#include <type_traits>

namespace mpt
{
    template <typename T>
    struct universal_type;

    template <typename Tag, typename T>
    class unique_type
    {
        static_assert(std::is_arithmetic<T>::value, "unique_type not given arithmetic type");

    private:
        template <typename AnyTag, typename AnyType>
        friend class unique_type;

        template <typename AnyType>
        friend struct universal_type;

        template <typename U>
        using Unique = unique_type<Tag, U>;

    public:
        using TagType = Tag;
        using ValueType = T;

        unique_type() = default;

        explicit unique_type(const T& val) : value{val} {}

        template <typename U>
        unique_type(const Unique<U>& o) : value{o.value} {}

        explicit operator T() const { return value; }
        explicit operator T&() { return value; }

        explicit operator bool() const { return bool(value); }
        bool operator !() const { return !value; }

        auto operator +(const Unique<T>& o) const {
            return Unique<decltype(value + o.value)>(value + o.value);
        }

        auto& operator +=(const Unique<T>& o) {
            value += o.value;
            return *this;
        }

        auto operator -(const Unique<T>& o) const {
            return Unique<decltype(value - o.value)>(value - o.value);
        }

        auto& operator -=(const Unique<T>& o) {
            value -= o.value;
            return *this;
        }

        auto operator *(const Unique<T>& o) const {
            return Unique<decltype(value * o.value)>(value * o.value);
        }

        auto& operator *=(const Unique<T>& o) {
            value *= o.value;
            return *this;
        }

        auto operator /(const Unique<T>& o) const {
            return Unique<decltype(value / o.value)>(value / o.value);
        }

        auto& operator /=(const Unique<T>& o) {
            value /= o.value;
            return *this;
        }

        auto operator %(const Unique<T>& o) const {
            return Unique<decltype(value % o.value)>(value % o.value);
        }

        auto& operator %=(const Unique<T>& o) {
            value %= o.value;
            return *this;
        }

        auto operator ^(const Unique<T>& o) const {
            return Unique<decltype(value ^ o.value)>(value ^ o.value);
        }

        auto& operator ^=(const Unique<T>& o) {
            value ^= o.value;
            return *this;
        }

        auto operator &(const Unique<T>& o) const {
            return Unique<decltype(value & o.value)>(value & o.value);
        }

        auto& operator &=(const Unique<T>& o) {
            value &= o.value;
            return *this;
        }

        auto operator |(const Unique<T>& o) const {
            return Unique<decltype(value | o.value)>(value | o.value);
        }

        auto& operator |=(const Unique<T>& o) {
            value |= o.value;
            return *this;
        }

        auto operator ~() const {
            return Unique<decltype(~value)>(~value);
        }

        auto operator <<(const Unique<T>& o) const {
            return Unique<decltype(value << o.value)>(value << o.value);
        }

        auto& operator <<=(const Unique<T>& o) {
            value <<= o.value;
            return *this;
        }

        auto operator >>(const Unique<T>& o) const {
            return Unique<decltype(value >> o.value)>(value >> o.value);
        }

        auto& operator >>=(const Unique<T>& o) {
            value >>= o.value;
            return *this;
        }

        auto& operator ++() { return ++value, *this; }
        auto operator ++(int) { return Unique<T>(value++); }

        auto& operator --() { return --value, *this; }
        auto operator --(int) { return Unique<T>(value--); }

        bool operator ==(const Unique<T>& o) const {
            return value == o.value;
        }

        bool operator !=(const Unique<T>& o) const {
            return value != o.value;
        }

        bool operator <(const Unique<T>& o) const {
            return value < o.value;
        }

        bool operator >(const Unique<T>& o) const {
            return value > o.value;
        }

        bool operator <=(const Unique<T>& o) const {
            return value <= o.value;
        }

        bool operator >=(const Unique<T>& o) const {
            return value >= o.value;
        }

        auto operator +(const universal_type<T>& o) const {
            return Unique<decltype(value + o.val)>(value + o.val);
        }

        auto& operator +=(const universal_type<T>& o) {
            value += o.val;
            return *this;
        }

        auto operator -(const universal_type<T>& o) const {
            return Unique<decltype(value - o.val)>(value - o.val);
        }

        auto& operator -=(const universal_type<T>& o) {
            value -= o.val;
            return *this;
        }

        auto operator *(const universal_type<T>& o) const {
            return Unique<decltype(value * o.val)>(value * o.val);
        }

        auto& operator *=(const universal_type<T>& o) {
            value *= o.val;
            return *this;
        }

        auto operator /(const universal_type<T>& o) const {
            return Unique<decltype(value / o.val)>(value / o.val);
        }

        auto& operator /=(const universal_type<T>& o) {
            value /= o.val;
            return *this;
        }

        auto operator %(const universal_type<T>& o) const {
            return Unique<decltype(value % o.val)>(value % o.val);
        }

        auto& operator %=(const universal_type<T>& o) {
            value %= o.val;
            return *this;
        }

        auto operator ^(const universal_type<T>& o) const {
            return Unique<decltype(value ^ o.val)>(value ^ o.val);
        }

        auto& operator ^=(const universal_type<T>& o) {
            value ^= o.val;
            return *this;
        }

        auto operator &(const universal_type<T>& o) const {
            return Unique<decltype(value & o.val)>(value & o.val);
        }

        auto& operator &=(const universal_type<T>& o) {
            value &= o.val;
            return *this;
        }

        auto operator |(const universal_type<T>& o) const {
            return Unique<decltype(value | o.val)>(value | o.val);
        }

        auto& operator |=(const universal_type<T>& o) {
            value |= o.val;
            return *this;
        }

        auto operator <<(const universal_type<T>& o) const {
            return Unique<decltype(value << o.val)>(value << o.val);
        }

        auto& operator <<=(const universal_type<T>& o) {
            value <<= o.val;
            return *this;
        }

        auto operator >>(const universal_type<T>& o) const {
            return Unique<decltype(value >> o.val)>(value >> o.val);
        }

        auto& operator >>=(const universal_type<T>& o) {
            value >>= o.val;
            return *this;
        }

        bool operator ==(const universal_type<T>& o) const {
            return value == o.val;
        }

        bool operator !=(const universal_type<T>& o) const {
            return value != o.val;
        }

        bool operator <(const universal_type<T>& o) const {
            return value < o.val;
        }

        bool operator >(const universal_type<T>& o) const {
            return value > o.val;
        }

        bool operator <=(const universal_type<T>& o) const {
            return value <= o.val;
        }

        bool operator >=(const universal_type<T>& o) const {
            return value >= o.val;
        }

    private:
        T value;
    };

    template <typename T>
    struct universal_type
    {
        universal_type() = default;

        universal_type(const T& v) : val{v} {}

        template <typename U>
        universal_type(const universal_type<U>& o) : val{o.val} {}
        
        operator T() const { return val; }
        operator T&() { return val; }

        template <typename Tag>
        operator unique_type<Tag, T>() {
            return unique_type<Tag, T>{val};
        }

        template <typename Tag>
        auto operator +(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val + o.value)>(val + o.value);
        }

        template <typename Tag>
        auto operator -(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val - o.value)>(val - o.value);
        }

        template <typename Tag>
        auto operator *(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val * o.value)>(val * o.value);
        }

        template <typename Tag>
        auto operator /(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val / o.value)>(val / o.value);
        }

        template <typename Tag>
        auto operator %(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val % o.value)>(val % o.value);
        }

        template <typename Tag>
        auto operator ^(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val ^ o.value)>(val ^ o.value);
        }

        template <typename Tag>
        auto operator &(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val & o.value)>(val & o.value);
        }

        template <typename Tag>
        auto operator |(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val | o.value)>(val | o.value);
        }

        template <typename Tag>
        auto operator <<(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val << o.value)>(val << o.value);
        }

        template <typename Tag>
        auto operator >>(const unique_type<Tag, T>& o) const {
            return unique_type<Tag, decltype(val >> o.value)>(val >> o.value);
        }

        template <typename Tag>
        bool operator ==(const unique_type<Tag, T>& o) const {
            return val == o.value;
        }

        template <typename Tag>
        bool operator !=(const unique_type<Tag, T>& o) const {
            return val != o.value;
        }

        template <typename Tag>
        bool operator <(const unique_type<Tag, T>& o) const {
            return val < o.value;
        }

        template <typename Tag>
        bool operator >(const unique_type<Tag, T>& o) const {
            return val > o.value;
        }

        template <typename Tag>
        bool operator <=(const unique_type<Tag, T>& o) const {
            return val <= o.value;
        }

        template <typename Tag>
        bool operator >=(const unique_type<Tag, T>& o) const {
            return val >= o.value;
        }

        T val;
    };

    template <typename Tag, typename T>
    std::ostream& operator<<(std::ostream& os, const unique_type<Tag, T>& obj) {
        os << static_cast<T>(obj);
        return os;
    }

    template <typename Tag, typename T>
    std::istream& operator>>(std::istream& is, unique_type<Tag, T>& obj) {
        is >> static_cast<T&>(obj);
        return is;
    }

    template <typename T>
    universal_type<T> W(const T& wrap) {
        return universal_type<T>(wrap);
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

#define MPT_UNIQUE_TYPE_MODIFIER(name) \
    template <typename Tag> \
    struct name##_tag {}; \
    template <class Type> \
    using name = mpt::unique_type<name##_tag<typename Type::TagType>, typename Type::ValueType>;

#define MPT_UNIQUE_TYPE_FAMILY(name) \
    struct name##_tag {}; \
    template <typename T> \
    using name = mpt::unique_type<name##_tag, T>

#define MPT_UNIQUE_TYPE_FAMILY_MODIFIER(name) \
    template <typename Tag> \
    struct name##_tag {}; \
    template <template <typename> class Type, typename T> \
    using name = mpt::unique_type<name##_tag<typename Type<T>::TagType>, T>;

#endif // MPT_UNIQUE_TYPE_HPP
