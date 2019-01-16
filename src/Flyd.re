/* See xstream bindings
    https://gitlab.com/j3a-solutions/bs-xstream/blob/master/src/xstream_stream.re
   */

type _value;
type _mapArg;
[@bs.deriving abstract]
type strm = {
  [@bs.as "end"]
  end_: (~force: bool) => unit,
  pipe: (strm => strm, unit) => strm,
  map: _mapArg => strm,
  ap: strm => strm,
  [@bs.as "of"]
  of_: _value => strm,
};
module Stream = {
  type t = strm;
};

/* a -> Stream a */
[@bs.module "flyd"] external stream: (~value: 'a, unit) => Stream.t = "";
/* * -> Boolean */
[@bs.send] external isStream: 'a => bool = "";
/* (...Stream * -> Stream b -> b) -> [Stream *] -> Stream b */
[@bs.send] external combine: ('a => 'b, array(Stream.t)) => Stream.t = "";
[@bs.send] external combine1: ('a => 'b, Stream.t) => Stream.t = "combine";
[@bs.send]
external combine2: ('a => 'b, Stream.t, Stream.t) => Stream.t = "combine";
[@bs.send]
external combine3: ('a => 'b, Stream.t, Stream.t, Stream.t) => Stream.t =
  "combine";
/* Stream a -> Stream b -> Stream b */
[@bs.send] external endsOn: (Stream.t, Stream.t) => Stream.t = "";
/* Stream a -> Stream a */
[@bs.send] external immediate: Stream.t => Stream.t = "";
/* (a -> result) -> Stream a -> Stream result */
[@bs.send] external map: ('a => 'c, Stream.t) => Stream.t = "";
/* (a -> Stream b) -> Stream a -> Stream b */
[@bs.send] external chain: ('a => Stream.t, Stream.t) => Stream.t = "";
/* Stream (a -> b) -> Stream a -> Stream b */
[@bs.send] external ap: (Stream.t, 'a => Stream.t) => Stream.t = "";
/* (a -> result) -> Stream a -> Stream undefined */
[@bs.send] external on: ('a => 'c, Stream.t) => Stream.t = "";
[@bs.send] external scan: ('a => 'c, 'd, Stream.t) => Stream.t = "";
/* Stream a -> Stream a -> Stream a */
[@bs.send] external merge: (Stream.t, Stream.t) => Stream.t = "";
/* Transducer -> Stream a -> Stream b */
[@bs.send] external transduce: ('a => Stream.t, Stream.t) => Stream.t = "";
/* arity:int, function2curry => curriedFunction */
[@bs.send] external curryN: (int, 'a => 'c) => 'c = "";
[@bs.send] external fromPromise: 'a => Stream.t = "";
let make = (~value=?, ()) => stream(~value, ());