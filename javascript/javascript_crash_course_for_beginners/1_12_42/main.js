// Single element
console.log(window);
console.log(document.querySelector('h1'));

// Multiple element
console.log(document.querySelectorAll('.item'));

const items = document.querySelectorAll('.item');
items.forEach((item) => console.log(item));