type any;
module Stream = {
  type t = {
    end_: any,
    /* pipe: any => Stream.t, */
    /* map: any => Stream.t, */
    /* ap: Stream.t => Stream.t, */
    /* of_: any => Stream.t, */
    pipe: any => any,
    map: any => any,
    apply: any => any,
    of_: any => any,
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