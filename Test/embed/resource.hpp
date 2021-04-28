#pragma once

#include <algorithm>
#include <array>
#include <cstdint>
#include <functional>
#include "span.hpp"
#include <tuple>
#include <vector>

class Resource {
public:
	template <typename T>
	using span = tcb::span<T>;
	using EmbeddedData = span<const std::uint8_t>;

private:
	const EmbeddedData arr_view;
	const std::string path;

public:
	Resource() = default;
	template <typename Container>
	Resource(const Container& arr_, std::string path_) : arr_view(arr_), path(std::move(path_)) {}

	auto GetArray() const {
		return arr_view;
	}

	auto& GetPath() const {
		return path;
	}
};
