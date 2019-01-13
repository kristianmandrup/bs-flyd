open Flyd;
open Jest;
open ExpectJs;

describe("Flyd", () => {
  test("#stream", () =>
    expect(() =>
      stream(~value=4)
    ) |> not |> toThrow
  );

  test("#combine", () =>
    expect(() =>
      combine(x => x + 4, [|1|])
    ) |> not |> toThrow
  );
});