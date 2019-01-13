/* See xstream bindings
   https://gitlab.com/j3a-solutions/bs-xstream/blob/master/src/xstream_stream.re
   */
type stream('a, 'b);
module Stream = {
  type t('a) = {
    end_: (~force: bool) => unit,
    pipe: 'a => t('a),
    map: 'a => t('a),
    ap: t('a) => t('a),
    of_: 'a => t('a),
  };
};
[@bs.send] external stream: (~value: 'b, unit) => Stream.t('a) = "";
[@bs.send]
external combine: ('a => 'c, ~values: 'v, unit) => Stream.t('a) = "";
[@bs.send] external isStream: 'a => bool = "";
[@bs.send] external immediate: Stream.t('a) => Stream.t('a) = "";
[@bs.send]
external endsOn: (Stream.t('a), Stream.t('b)) => Stream.t('c) = "";
[@bs.send] external map: ('a => 'c, stream('a, 'b)) => stream('c, 'b) = "";
[@bs.send] external chain: ('a => 'c, stream('a, 'b)) => 'c = "";
[@bs.send] external apply: (stream('a, 'b), 'a => 'c) => 'c = "ap";
[@bs.send] external on: ('a => 'c, stream('a, 'b)) => 'c = "";
[@bs.send] external scan: ('a => 'c, 'd, stream('a, 'b)) => 'c = "";
[@bs.send] external merge: array(stream('a, 'b)) => stream('a, 'b) = "";
[@bs.send] external transduce: ('a => 'c, stream('a, 'b)) => 'a = "";
[@bs.send] external curryN: (int, 'a => 'c) => 'c = "";
[@bs.send] external fromPromise: 'a => 'a = "";