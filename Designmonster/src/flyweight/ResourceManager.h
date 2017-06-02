#pragma once

#include "../Common.h"

#include <unordered_map>
#include <utility>
#include <string>
#include <iostream>

template<typename Derived, typename T>
class ResourceManager {
public:
	ResourceManager();

	virtual ~ResourceManager();

	T* RequireResource(const std::string& id);

	// Decrements the amount a resource is used.
	// If counter hits 0 it uses Unload to remove the
	// resource from memory.
	bool ReleaseResource(const std::string& id);

	// Removes all resources from the heap.
	void PurgeResources();

protected:
	T* Load(const std::string& path);

private:
	typedef std::unordered_map<std::string, std::pair<T*, uint32>> ResourceContainer;

	ResourceContainer m_Resources;

	// Attempts to find an existing resource. Returns nullptr
	// if none is found.
	std::pair<T*, uint32>* Find(const std::string& id);

	// Removes a resource from memory.
	bool Unload(const std::string& id);
};

template<typename Derived, typename T>
inline ResourceManager<Derived, T>::ResourceManager() {
}

template<typename Derived, typename T>
inline ResourceManager<Derived, T>::~ResourceManager() {
	PurgeResources();
}

template<typename Derived, typename T>
inline T* ResourceManager<Derived, T>::RequireResource(const std::string& path) {
	auto res = Find(path);
	if (res != nullptr) {
		// Increment the resource counter if the resource already exists.
		++res->second;
		std::cout << "Resource " << path << " found in the resourcemanager. Returning existing resource.\n";
		std::cout << "There is currently " << res->second << " number of instances of " << path << "\n";
		return res->first;
	}

	// Attempt to load the resource from the given path
	// if the resource isn't found.
	T* resource = Load(path);
	if (resource == nullptr) {
		return nullptr;
	}
	m_Resources.emplace(path, std::make_pair(resource, 1));
	std::cout << "Added new resource (" << path << ") to the resourcemanager.\n";
	return resource;
}

template<typename Derived, typename T>
inline bool ResourceManager<Derived, T>::ReleaseResource(const std::string& path) {
	auto res = Find(path);
	if (res == nullptr) {
		std::cout << "Could not find the resource " << path << " in the resourcemanager.\n";
		return false;
	}
	std::cout << "Releasing one instance of the resource " << path << " from the resourcemanager.\n";
	--res->second;
	std::cout << "There is currently " << res->second << " instances left of the resource.\n";

	// Remove the resource from memory if nothing is using it anymore.
	if (res->second == 0) {
		std::cout << "Resourcemanager says: Since there's no more instances of the resource, I will remove it from memory.\n";
		Unload(path);
	}
	return true;
}

// Release all resources from memory.
template<typename Derived, typename T>
inline void ResourceManager<Derived, T>::PurgeResources() {
	std::cout << "Purging all resources.\n";
	while (m_Resources.begin() != m_Resources.end()) {
		std::cout << "Puring resource " << m_Resources.begin()->first << "\n";
		delete m_Resources.begin()->second.first;
		m_Resources.erase(m_Resources.begin());
	}
	std::cout << "Finished purging all resources.\n";
}

template<typename Derived, typename T>
inline T* ResourceManager<Derived, T>::Load(const std::string& path) {
	// Use the derived class version of Load, without having it rely on 
	// virtual pointers to functions during run-time
	return static_cast<Derived*>(this)->Load(path);
}

template<typename Derived, typename T>
inline std::pair<T*, uint32>* ResourceManager<Derived, T>::Find(const std::string& path) {
	auto itr = m_Resources.find(path);
	return (itr != m_Resources.end() ? &itr->second : nullptr);
}

template<typename Derived, typename T>
inline bool ResourceManager<Derived, T>::Unload(const std::string& path) {
	auto itr(m_Resources.find(path));
	
	if (itr == m_Resources.end()) {
		return false;
	}

	delete itr->second.first;
	itr->second.first = nullptr;
	m_Resources.erase(itr);
	return true;
}
