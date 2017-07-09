//
// Created by oxydros on 7/9/17.
//

#ifndef STRANGEGAME_RESOURCEHOLDER_INL
#define STRANGEGAME_RESOURCEHOLDER_INL

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, std::string const &fileName) {
    std::unique_ptr<Resource> resource(new Resource());

    if (!resource->loadFromFile(fileName)) {
        throw std::runtime_error("ResourceHolder - Failed to load from file " + fileName);
    }
    insertResource(id, resource);
};

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, std::string const &fileName, Parameter param) {
    std::unique_ptr<Resource> resource(new Resource());

    if (!resource->loadFromFile(fileName, param)) {
        throw std::runtime_error("ResourceHolder - Failed to load from file " + fileName);
    }
    insertResource(id, resource);
};

template<typename Resource, typename Identifier>
Resource &ResourceHolder<Resource, Identifier>::get(Identifier id) {
    auto find = resourceMap.find(id);
    assert(find != resourceMap.end());
    return *find->second;
};

template<typename Resource, typename Identifier>
Resource const  &ResourceHolder<Resource, Identifier>::get(Identifier id) const {
    auto find = resourceMap.find(id);
    assert(find != resourceMap.end());
    return *find->second;
};

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::insertResource(Identifier id, std::unique_ptr<Resource> resource) {
    auto inserted = resourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
};
#endif //STRANGEGAME_RESOURCEHOLDER_INL
