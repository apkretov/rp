function Person(firstName, lastName, dob) { // Consturctor function.
    this.firstName = firstName;
    this.lastName = lastName;
    this.dob = new Date(dob);
    this.getBirhYear = function () {
        return this.dob.getFullYear();
    }
    this.getFullName = function () {
        return `${this.firstName} ${this.lastName}`;
    }
}

const person1 = new Person('John', 'Doe', '3/4/1980');

console.log(person1);
console.log(person1.dob.getFullYear());
console.log(person1.getBirhYear());
console.log(person1.getFullName());