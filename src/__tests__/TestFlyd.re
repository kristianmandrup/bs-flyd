open Flyd;
open Jest;
open ExpectJs;

let emptyStrm = make();
let strm = make(~value=2, ());

describe("Flyd", () => {
  test("#stream empty - no value ", () =>
    expect(() =>
      stream()
    ) |> not |> toThrow
  );

  test("#stream with value", () =>
    expect(() =>
      stream(~value=4, ())
    ) |> not |> toThrow
  );

  test("#combine", () =>
    expect(() =>
      combine(x => strm, emptyStrm)
    ) |> not |> toThrow
  );

  test("#isStream - true", () =>
    expect(() =>
      isStream(make())
    ) |> toBeTruthy
  );

  test("#isStream - false", () =>
    expect(() =>
      isStream(5)
    ) |> toBeFalsy
  );

  test("#immediate", () =>
    expect(() =>
      immediate(emptyStrm)
    ) |> not |> toThrow
  );
  test("#endsOn", () =>
    expect(() =>
      endsOn(strm, emptyStrm)
    ) |> not |> toThrow
  );
  test("#map", () =>
    expect(() =>
      map(x => x, strm)
    ) |> not |> toThrow
  );
  test("#chain", () =>
    expect(() =>
      chain(x => x, strm)
    ) |> not |> toThrow
  );
  test("#ap", () =>
    expect(() =>
      ap(strm, x => x)
    ) |> not |> toThrow
  );
  test("#on", () =>
    expect(() =>
      on(x => x, strm)
    ) |> not |> toThrow
  );
  test("#scan", () =>
    expect(() =>
      scan(x => x, stream())
    ) |> not |> toThrow
  );
  test("#merge", () =>
    expect(() =>
      merge(strm, emptyStrm)
    ) |> not |> toThrow
  );
  test("#transduce", () =>
    expect(() =>
      transduce(x => x, strm)
    ) |> not |> toThrow
  );
  /* test("#curryN", () =>
       expect(() =>
         curryN(5, x => x)
       ) |> not |> toThrow
     ); */
  /* test("#fromPromise", () =>
       expect(() => {
         let p = Js.Promise((x) => x)
         fromPromise(p)
       }) |> not |> toThrow
     ); */
});