#pragma once

class Appdata {
	explicit Appdata() = default;
public:
	~Appdata() = default;
	Appdata(Appdata&&) = delete;
	Appdata(const Appdata&) = delete;
	Appdata& operator=(Appdata&&) = delete;
	Appdata& operator=(const Appdata&) = delete;

	static Appdata& get_instance();
private:

};
