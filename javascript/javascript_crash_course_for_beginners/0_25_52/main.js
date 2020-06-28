const numbers = new Array(1, 2, 3, 4, 5); // Using the consctructor to declare an array.
const fruits = ['apples', 'oranges', 'pears', // Using brackets to declare an array.
    10, true];  // Various data types.

console.log(numbers);

console.log(fruits);

fruits.push('mangos'); // Add to the end.
console.log(fruits);

fruits.unshift('strawberries'); // Add to the beginning.
console.log(fruits);

fruits.pop(); // Take the last item off.
console.log(fruits);

console.log(Array.isArray(fruits));
console.log(Array.isArray('hello'));

console.log(fruits.indexOf('oranges'));