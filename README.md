# bs-flyd

Bucklescript bindings for [flyd](https://github.com/paldepind/flyd) stream library.
The modular, KISS, functional reactive programming library for JavaScript.

- Supports the transducer protocol. You can for instance transduce streams with
  [Ramda](http://ramdajs.com/) and [transducers.js](https://github.com/jlongster/transducers.js).
- Conforms to the fantasy land [monad](https://github.com/fantasyland/fantasy-land#monad) specification
- [Atomic updates](#atomic-updates).

## Use

Flyd can be used with modern state management solutions like [Meiosis](https://meiosis.js.org/) to great effect. No need for Virtual DOMs or other "complex machinery" at this point in time ;)

### Install

`npm i bs-flyd`

Add `bs-flyd` to `dependencies` in `bsconfig.json`

### Usage

```javascript
open Flyd;
let number = stream(5)
```

## Api

See [Flyd API](https://github.com/paldepind/flyd/blob/master/README.md#api)
Note: Use `apply` and NOT `ap` to apply functions on streams.

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
