const person = {
    firstName: 'John',
    lastName: 'Doe',
    age: 30,
    hobbies: ['music', 'movies', 'sports'],
    address: {
        street: '50 main st',
        city: 'Boston',
        state: 'MA'
    }
}
console.log(person);
console.log(person.firstName);
console.log(person.firstName, person.lastName); // Log more than one item.
console.log(person.hobbies[1]);
console.log(person.address.city);

const { firstName, lastName, address:{city} } = person; // Desctructoring or pulling values out.
console.log(firstName);
console.log(city);

person.email = 'john@gmail.com'; // Adding a property.
console.log(person.email);