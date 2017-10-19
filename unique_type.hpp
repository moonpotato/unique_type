#ifndef MPT_UNIQUE_TYPE_HPP
#define MPT_UNIQUE_TYPE_HPP

namespace mpt
{
    template <typename Tag, typename T>
    class unique_type
    {
        using Unique = unique_type<Tag, T>;

    public:
        unique_type() = default;
        explicit unique_type(const T& val) : value(val) {}
        explicit unique_type(T&& val) : value(val) {}

        explicit operator T() const { return value; }
        explicit operator T&() { return value; }
    
    private:
        T value;
    };
}

#define MPT_UNIQUE_TYPE(name, type) \
    struct name##_tag {}; \
    using name = mpt::unique_type<name##_tag, type>

#define MPT_UNIQUE_TYPE_FAMILY(name) \
    struct name##_tag {}; \
    template <typename T> \
    using name = mpt::unique_type<name##_tag, T>

#endif // MPT_UNIQUE_TYPE_HPP
