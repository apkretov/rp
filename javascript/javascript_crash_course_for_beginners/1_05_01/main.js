function Person(firstName, lastName, dob) { // Constructor function.
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
}
Person.prototype.getBirhYear = function () {
    return this.dob.getFullYear();
}
Person.prototype.getFullName = function () {
    return `${this.firstName} ${this.lastName}`;
}

const person1 = new Person('John', 'Doe', '3/4/1980');

console.log(person1);