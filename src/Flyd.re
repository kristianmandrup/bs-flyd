type any;
module Stream = {
  type t = {
    end_: any,
    pipe: any => t,
    map: any => t,
    ap: t => t,
    of_: any => t,
  };
};
type toStream = array(any) => Stream.t;
type acc;
type transformStream = Stream.t => Stream.t;
[@bs.send] external stream: (~value: any, unit) => Stream.t = "";
[@bs.send] external combine: (toStream, ~values: array('x), unit) => 'y = "";
[@bs.send] external isStream: 'a => bool = "";
[@bs.send] external immediate: Stream.t => Stream.t = "";
[@bs.send] external endsOn: (Stream.t, Stream.t) => Stream.t = "";
[@bs.send] external map: (transformStream, Stream.t) => any = "";
[@bs.send] external chain: (transformStream, Stream.t) => any = "";
[@bs.send] external apply: (any, transformStream) => any = "ap";
[@bs.send] external on: (transformStream, Stream.t) => any = "";
[@bs.send] external scan: (transformStream, acc, Stream.t) => any = "";
[@bs.send] external merge: (Stream.t, Stream.t) => any = "";
[@bs.send] external transduce: (transformStream, Stream.t) => any = "";
[@bs.send] external curryN: (int, toStream) => any = "";
[@bs.send] external fromPromise: any => any = "";