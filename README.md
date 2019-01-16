# bs-flyd

Bucklescript bindings for [flyd](https://github.com/paldepind/flyd) stream library.
The modular, KISS, functional reactive programming library for JavaScript.

- Supports the transducer protocol. You can for instance transduce streams with
  [Ramda](http://ramdajs.com/) and [transducers.js](https://github.com/jlongster/transducers.js).
- Conforms to the fantasy land [monad](https://github.com/fantasyland/fantasy-land#monad) specification
- [Atomic updates](#atomic-updates).

## Use

Flyd can be used to great effect with modern patterns like [Meiosis](https://meiosis.js.org/).
See [reasonml-meiosis-examples](https://github.com/kristianmandrup/reasonml-meiosis-examples)

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
