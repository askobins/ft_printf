# ft\_printf
42 project ft\_printf (2019 version)

## Goals:

1. All bonuses
2. All on the stack (no malloc challenge)
3. No buffering (no large arrays with potential empty items)
4. Variables kept to a minimum, use bit setting for booleans), no weird unweildy structures
5. Minimize errors on undefined behavior as much as possible
6. Extra conversion for binary (b and B)

## Afterthoughts

1. Failed float bonus, float handling is a lot more difficult and time consuming than it seems
2. No malloc forces you to write efficient code, embedded guides are a great resource
3. buffering is, in fact, very useful when working with potentially large amounts of data
4. I was right about this but I do use unweildy structures, they're just unweildy in a different way lol
5. Undefined behavior means "I don't know why this crashes sometimes but I dont have to handle it" and thats,, valid
6. binary conversions are good as hell actually
