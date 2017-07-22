//
// Created by oxydros on 7/9/17.
//

#ifndef STRANGEGAME_RESOURCEHOLDER_HPP
#define STRANGEGAME_RESOURCEHOLDER_HPP

# include <map>
# include <memory>
# include <string>
# include <stdexcept>
# include <cassert>

template<typename Resource, typename Identifier>
class ResourceHolder
{
private:
    std::map<Identifier, std::unique_ptr<Resource>> resourceMap;

public:
    void            load(Identifier id, std::string const &fileName);
    template<typename Parameter>
    void            load(Identifier id, std::string const &fileName, Parameter param);

public:
    Resource        &get(Identifier id);
    Resource const  &get(Identifier id) const;

private:
    void            insertResource(Identifier id, std::unique_ptr<Resource> resource);
};

# include "ResourceHolder.inl"
#endif //STRANGEGAME_RESOURCEHOLDER_HPP
