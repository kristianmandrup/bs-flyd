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
[@bs.module "flyd"] external stream: (~value: 'b, unit) => Stream.t('a) = "";
[@bs.send]
external combine: ('a => 'c, ~values: 'v, unit) => Stream.t('a) = "";
[@bs.module "flyd"] external isStream: 'a => bool = "";
[@bs.module "flyd"] external immediate: Stream.t('a) => Stream.t('a) = "";
[@bs.send]
external endsOn: (Stream.t('a), Stream.t('b)) => Stream.t('c) = "";
[@bs.module "flyd"]
external map: ('a => 'c, stream('a, 'b)) => stream('c, 'b) = "";
[@bs.module "flyd"] external chain: ('a => 'c, stream('a, 'b)) => 'c = "";
[@bs.module "flyd"] external apply: (stream('a, 'b), 'a => 'c) => 'c = "ap";
[@bs.module "flyd"] external on: ('a => 'c, stream('a, 'b)) => 'c = "";
[@bs.module "flyd"] external scan: ('a => 'c, 'd, stream('a, 'b)) => 'c = "";
[@bs.module "flyd"]
external merge: array(stream('a, 'b)) => stream('a, 'b) = "";
[@bs.module "flyd"] external transduce: ('a => 'c, stream('a, 'b)) => 'a = "";
[@bs.module "flyd"] external curryN: (int, 'a => 'c) => 'c = "";
[@bs.module "flyd"] external fromPromise: 'a => 'a = "";