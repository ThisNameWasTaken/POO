#pragma once
class Vector2D{
public:
	Vector2D(int x = 0, int y = 0);
	Vector2D(const Vector2D& vector);
	~Vector2D();

	const Vector2D& operator=(const Vector2D& vector);
	bool operator==(const Vector2D& vector);
	bool operator!=(const Vector2D& vector);
	const Vector2D operator+(const Vector2D& vector) const;
	const Vector2D operator+(const int value) const;
	friend const Vector2D operator+(const int value, const Vector2D& vector);
	const Vector2D& operator+=(const Vector2D& vector);
	const Vector2D& operator+=(const int value);
	const Vector2D& operator++(); // Prefix increment operator.
	const Vector2D operator++(int); // Postfix increment operator.
	const Vector2D operator-(const Vector2D& vector) const;
	const Vector2D operator-(const int value) const;
	friend const Vector2D operator-(const int value, const Vector2D& vector);
	friend const Vector2D operator-(const Vector2D& vector);
	const Vector2D& operator-=(const Vector2D& vector);
	const Vector2D& operator-=(const int value);
	const Vector2D& operator--(); // Prefix decrement operator.
	const Vector2D operator--(int); // Postfix decrement operator.
	const Vector2D operator*(const Vector2D& vector) const;
	const Vector2D operator*(const float value) const;
	friend const Vector2D operator*(const float value, const Vector2D& vector);
	const Vector2D& operator*=(const Vector2D& vector);
	const Vector2D& operator*=(const float value);
	const Vector2D operator/(const Vector2D& vector) const;
	const Vector2D operator/(const int value) const;
	const Vector2D& operator/=(const Vector2D& vector);
	const Vector2D& operator/=(const int value);

	int x, y;
};

