type any;
module Stream = {
  type t = {
    end_: any => unit,
    pipe: any => t,
    map: any => t,
    ap: t => t,
    of_: any => t,
  };
};
type toStream = array(any) => Stream.t;
type acc;
type transformStream = Stream.t => Stream.t;
[@bs.send] external stream: (~value: 'a, unit) => Stream.t = "";
[@bs.send] external combine: (toStream, ~values: array('x), unit) => 'y = "";
[@bs.send] external isStream: 'a => bool = "";
[@bs.send] external immediate: Stream.t => Stream.t = "";
[@bs.send] external endsOn: (Stream.t, Stream.t) => Stream.t = "";
[@bs.send] external map: (transformStream, Stream.t) => 'a = "";
[@bs.send] external chain: (transformStream, Stream.t) => 'a = "";
[@bs.send] external apply: ('a, transformStream) => 'a = "ap";
[@bs.send] external on: (transformStream, Stream.t) => 'a = "";
[@bs.send] external scan: (transformStream, acc, Stream.t) => 'a = "";
[@bs.send] external merge: (Stream.t, Stream.t) => 'a = "";
[@bs.send] external transduce: (transformStream, Stream.t) => 'a = "";
[@bs.send] external curryN: (int, toStream) => 'a = "";
[@bs.send] external fromPromise: 'a => 'a = "";