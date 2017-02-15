#ifndef HELLTRIANGLE_HPP
#define HELLTRIANGLE_HPP

#include <vector>

namespace B2W
{
    class HellTriangle
    {
    public:
        typedef std::vector<int> container_type;
        typedef typename container_type::size_type size_type;
        
        HellTriangle(const container_type& data) : _data(data) {}
        
        class Node
        {
        public:
            Node(size_type i, size_type j, size_type index, int& value, bool valid = true);
            
            operator bool() const { return valid(); }
            
            // Getters
            size_type index() const { return _index; }
            size_type i() const;
            size_type j() const;
            int& value();
            bool valid() const { return _valid; }
            
        private:
            size_type _i, _j, _index;
            int& _value;
            bool _valid;
            
            inline void check_valid() const;
        };
        
        Node root();
        Node child_left(const Node& node);
        Node child_right(const Node& node);
        
    private:
        container_type _data;

        Node create_child_node(size_type i, size_type j, const Node& parent);
    };
}

#endif //HELLTRIANGLE_HPP
