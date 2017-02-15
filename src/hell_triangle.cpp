#include "hell_triangle.hpp"
#include "invalid_node_exception.hpp"

using namespace B2W;

HellTriangle::Node HellTriangle::root()
{
    auto& value = _data[0];
    return Node(0, 0, 0, value, _data.size() > 0);
}
  
HellTriangle::Node HellTriangle::child_left(const Node& parent)
{
    auto i = parent.i() +1;
    auto j = parent.j();
    
    return create_child_node(i, j, parent);
}

HellTriangle::Node HellTriangle::child_right(const Node& parent)
{
    auto i = parent.i() +1;
    auto j = parent.j() +1;
    
    return create_child_node(i, j, parent);
}

HellTriangle::Node HellTriangle::create_child_node(size_type i, size_type j, const Node& parent)
{
    auto index = parent.index() + i + (j -parent.j());
    auto& value = _data[index];
    
    if (index >= _data.size())
        return Node(0, 0, 0, _data[0], false); // invalid node
        
    return Node(i, j, index, value);
}

HellTriangle::Node::Node(size_type i, size_type j, size_type index, int& value, bool valid)
    : _i(i), _j(j), _index(index), _value(value), _valid(valid) {}
    
HellTriangle::size_type HellTriangle::Node::i() const
{
    check_valid();
    return _i;
}

HellTriangle::size_type HellTriangle::Node::j() const
{
    check_valid();
    return _j;
}

int& HellTriangle::Node::value()
{
    check_valid();
    return _value;
}

void HellTriangle::Node::check_valid() const
{
    if (!valid())
        throw InvalidNodeException("Trying to access an invalid instance of HellTriangle::Node");
}
