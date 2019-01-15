# bs-flyd

Bucklescript bindings for [flyd](https://github.com/paldepind/flyd) stream library.
The modular, KISS, functional reactive programming library for JavaScript.

- Supports the transducer protocol. You can for instance transduce streams with
  [Ramda](http://ramdajs.com/) and [transducers.js](https://github.com/jlongster/transducers.js).
- Conforms to the fantasy land [monad](https://github.com/fantasyland/fantasy-land#monad) specification
- [Atomic updates](#atomic-updates).

## Writing bindings

To help write bucklescript bindings for this lib (and hence make it usable from ReasonML) see the [FFI cheatsheet](https://github.com/glennsl/bucklescript-ffi-cheatsheet) and go for it!

### Records

Read up on [Bucklescript objects and records](https://bucklescript.github.io/docs/en/object#record-mode)

## Use

Flyd can be used with modern state management solutions like [Meiosis](https://meiosis.js.org/) to great effect. No need for Virtual DOMs or other "complex machinery" at this point in time ;)

### Install

`npm i bs-flyd`

Add `bs-flyd` to `dependencies` in `bsconfig.json`

## Api

See [Flyd API](https://github.com/paldepind/flyd/blob/master/README.md#api)

### Api changes

- To force the stream to end, use `Stream.end(~force: true)`

### Usage

```javascript
let number = Flyd.stream(5);
let fn = strm => strm;
let combined = Flyd.combine(fn, [32]);
```

## Build

```
npm run build
```

## Watch

```
npm run watch
```

## Editor

If you use `vscode`, Press `Windows + Shift + B` it will build automatically
