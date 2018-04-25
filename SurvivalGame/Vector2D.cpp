#include "Vector2D.h"

Vector2D::Vector2D(int x, int y) {
	this->x = x;
	this->y = y;
}

Vector2D::Vector2D(const Vector2D& vector) {
	this->x = vector.x;
	this->y = vector.y;
}

Vector2D::~Vector2D() {
	this->x = 0;
	this->y = 0;
}

const Vector2D& Vector2D::operator=(const Vector2D& vector) {
	this->x = vector.x;
	this->y = vector.y;
	return *this;
}

bool Vector2D::operator==(const Vector2D& vector) {
	return this->x == vector.x && this->y == vector.y;
}

bool Vector2D::operator!=(const Vector2D& vector) {
	return !(*this==vector);
}

const Vector2D Vector2D::operator+(const Vector2D& vector) const {
	return Vector2D(this->x + vector.x, this->y + vector.y);
}

const Vector2D Vector2D::operator+(const int value) const {
	return Vector2D(this->x + value, this->y + value);
}

const Vector2D operator+(const int value, const Vector2D& vector) {
	return Vector2D(vector.x + value, vector.y + value);
}

const Vector2D& Vector2D::operator+=(const Vector2D& vector) {
	this->x += vector.x;
	this->y += vector.y;
	return *this;
}

const Vector2D& Vector2D::operator+=(const int value) {
	this->x += value;
	this->y += value;
	return *this;
}

const Vector2D& Vector2D::operator++() {
	++this->x;
	++this->y;
	return *this;
}

const Vector2D Vector2D::operator++(int) {
	const Vector2D tmp(*this);
	++*this;
	return tmp;
}

const Vector2D Vector2D::operator-(const Vector2D& vector) const {
	return Vector2D(this->x - vector.x, this->y - vector.y);
}

const Vector2D Vector2D::operator-(const int value) const {
	return Vector2D(this->x - value, this->y - value);
}

const Vector2D operator-(const int value, const Vector2D& vector) {
	return Vector2D(vector.x - value, vector.y - value);
}

const Vector2D operator-(const Vector2D& vector) {
	return Vector2D(-vector.x, -vector.y);
}

const Vector2D& Vector2D::operator-=(const Vector2D& vector) {
	this->x -= vector.x;
	this->y -= vector.y;
	return *this;
}

const Vector2D& Vector2D::operator-=(const int value) {
	this->x -= value;
	this->y -= value;
	return *this;
}

const Vector2D& Vector2D::operator--() {
	--this->x;
	--this->y;
	return *this;
}

const Vector2D Vector2D::operator--(int) {
	const Vector2D tmp(*this);
	--*this;
	return tmp;
}

const Vector2D Vector2D::operator*(const Vector2D& vector) const {
	return Vector2D(this->x * vector.x, this->y * vector.y);
}

const Vector2D Vector2D::operator*(const float value) const {
	return Vector2D(this->x * value, this->y * value);
}

const Vector2D operator*(const float value, const Vector2D& vector) {
	return Vector2D(vector.x * value, vector.y * value);
}

const Vector2D& Vector2D::operator*=(const Vector2D& vector) {
	this->x *= vector.x;
	this->y *= vector.y;
	return *this;
}

const Vector2D& Vector2D::operator*=(const float value) {
	this->x *= value;
	this->y *= value;
	return *this;
}

const Vector2D Vector2D::operator/(const Vector2D& vector) const {
	if (!vector.x && !vector.y) return Vector2D(this->x, this->y);
	if (!vector.x) return Vector2D(this->x / 1, this->y / vector.y);
	if (!vector.y) return Vector2D(this->x / vector.x, this-> y/ 1);
	return Vector2D(this->x / vector.x, this->y / vector.y);
}

const Vector2D Vector2D::operator/(const int value) const {
	if (!value) return Vector2D();
	return Vector2D(this->x / value, this->y / value);
}

const Vector2D& Vector2D::operator/=(const Vector2D& vector) {
	if(vector.x) this->x /= vector.x;
	if(vector.y) this->y /= vector.y;
	return *this;
}

const Vector2D& Vector2D::operator/=(const int value) {
	if (value) {
		this->x /= value;
		this->y /= value;
	}
	return *this;
}