/* See xstream bindings
   https://gitlab.com/j3a-solutions/bs-xstream/blob/master/src/xstream_stream.re
   */
module Stream = {
  type t;
};

/* a -> Stream a */
[@bs.module "flyd"] external stream: (~value: 'a, unit) => Stream.t = "stream";
/* * -> Boolean */
[@bs.send] external isStream: 'a => bool = "isStream";
/* (...Stream * -> Stream b -> b) -> [Stream *] -> Stream b */
[@bs.send]
external combine: ('a => Stream.t, Stream.t) => Stream.t = "combine";
[@bs.send]
external combine2: ('a => 'b, Stream.t, Stream.t) => Stream.t = "combine";
[@bs.send]
external combine3: ('a => 'b, Stream.t, Stream.t, Stream.t) => Stream.t =
  "combine";
/* Stream a -> Stream b -> Stream b */
[@bs.send] external endsOn: (Stream.t, Stream.t) => Stream.t = "endsOn";
/* Stream a -> Stream a */
[@bs.send] external immediate: Stream.t => Stream.t = "immediate";
/* (a -> result) -> Stream a -> Stream result */
[@bs.send] external map: ('a => 'c, Stream.t) => Stream.t = "map";
/* (a -> Stream b) -> Stream a -> Stream b */
[@bs.send] external chain: ('a => Stream.t, Stream.t) => Stream.t = "chain";
/* Stream (a -> b) -> Stream a -> Stream b */
[@bs.send] external ap: (Stream.t, 'a => Stream.t) => Stream.t = "ap";
/* (a -> result) -> Stream a -> Stream undefined */
[@bs.send] external on: ('a => 'c, Stream.t) => Stream.t = "on";
[@bs.send] external scan: ('a => 'c, 'd, Stream.t) => Stream.t = "scan";
/* Stream a -> Stream a -> Stream a */
[@bs.send] external merge: (Stream.t, Stream.t) => Stream.t = "merge";
/* Transducer -> Stream a -> Stream b */
[@bs.send]
external transduce: ('a => Stream.t, Stream.t) => Stream.t = "transduce";
/* arity:int, function2curry => curriedFunction */
[@bs.send] external curryN: (int, 'a => 'c) => 'c = "curryN";
[@bs.send] external fromPromise: 'a => Stream.t = "fromPromise";
let make = (~value=?, ()) => stream(~value, ());