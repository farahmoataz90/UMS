#include "courselistitem.h"
void UMS::courselistitem::setName(String^ name) {
	this->name = name;
}
void UMS::courselistitem::setCode(String^ code) {
	this->Code = code;
}
void UMS::courselistitem::setInstructor(String^ instructor) {
	this->instructor = instructor;
}
void UMS::courselistitem::setIsRequirement(bool isRequirement) {
	this->isRequirement = isRequirement;
}
void UMS::courselistitem::setMaxNumberOfStudents(int maxNumberOfStudents) {
	this->maxNumberOfStudents = maxNumberOfStudents;
}
void UMS::courselistitem::setHours(int hours) {
	this->hours = hours;
}

String^ UMS::courselistitem::getName() {
	return name;
}
String^ UMS::courselistitem::getCode()
{
	return Code;
}
String^ UMS::courselistitem::getInstructor() {
	return instructor;
}
bool UMS::courselistitem::getIsRequirement() {
	return isRequirement;
}
int UMS::courselistitem::getMaxNumberOfStudents() {
	return maxNumberOfStudents;
}
int UMS::courselistitem::getHours() {
	return hours;
}