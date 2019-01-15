open Flyd;
open Jest;
open ExpectJs;

let emptyStrm = stream();

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
      combine(x => x + 4, [|1|])
    ) |> not |> toThrow
  );

  test("#isStream - true", () =>
    expect(() =>
      isStream(emptyStrm)
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
  /* test("#endsOn", () =>
       expect(() =>
         endsOn(stream(), stream())
       ) |> not |> toThrow
     ); */
  /* test("#map", () =>
       expect(() =>
         map(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#chain", () =>
       expect(() =>
         chain(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#ap", () =>
        expect(() =>
          ap(stream(), x => x)
        ) |> not |> toThrow
      );
     */
  /* test("#on", () =>
       expect(() =>
         on(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#scan", () =>
       expect(() =>
         scan(x => x, stream())
       ) |> not |> toThrow
     ); */
  /* test("#merge", () =>
       expect(() =>
         merge([|stream()|])
       ) |> not |> toThrow
     ); */
  /* test("#transduce", () =>
       expect(() =>
         transduce(x => x, stream())
       ) |> not |> toThrow
     ); */
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