/* See xstream bindings
   https://gitlab.com/j3a-solutions/bs-xstream/blob/master/src/xstream_stream.re
   */
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
[@bs.module "flyd"]
external combine: ('a => 'c, array('v)) => Stream.t('a) = "";
[@bs.module "flyd"] external isStream: 'a => bool = "";
[@bs.module "flyd"] external immediate: Stream.t('a) => Stream.t('b) = "";
[@bs.module "flyd"]
external endsOn: (Stream.t('a), Stream.t('b)) => Stream.t('c) = "";
[@bs.module "flyd"]
external map: ('a => 'c, Stream.t('a)) => Stream.t('c) = "";
[@bs.module "flyd"]
external chain: ('a => 'c, Stream.t('a)) => Stream.t('c) = "";
[@bs.module "flyd"] external ap: (Stream.t('a), 'a => 'c) => 'c = "ap";
[@bs.module "flyd"] external on: ('a => 'c, Stream.t('a)) => 'c = "";
[@bs.module "flyd"] external scan: ('a => 'c, 'd, Stream.t('a)) => 'c = "";
[@bs.module "flyd"]
external merge: array(Stream.t('a)) => Stream.t('a) = "";
[@bs.module "flyd"] external transduce: ('a => 'c, Stream.t('a)) => 'a = "";
[@bs.module "flyd"] external curryN: (int, 'a => 'c) => 'c = "";
[@bs.module "flyd"] external fromPromise: 'a => 'a = "";