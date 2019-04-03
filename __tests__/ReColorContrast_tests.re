open Jest;
open Expect;

open ColorContrast;

let extractFourDecimals = number => number *. 10000. |> truncate;

describe("relative luminance", () => {
  test("white", () =>
    expect(getRelativeLuminance((255, 255, 255))) |> toBe(1.0)
  );
  test("black", () =>
    expect(getRelativeLuminance((0, 0, 0))) |> toBe(0.0)
  );
  test("grey", () =>
    expect(getRelativeLuminance((119, 119, 119)) |> extractFourDecimals)
    |> toBe(1844)
  );
  test("blue-ish", () =>
    expect(getRelativeLuminance((45, 120, 220)) |> extractFourDecimals)
    |> toBe(1915)
  );
});

describe("color contrast", () => {
  test("white on black", () =>
    expect(getContrast((255, 255, 255), (0, 0, 0))) |> toBe(21.0)
  );

  test("black on white", () =>
    expect(getContrast((0, 0, 0), (255, 255, 255))) |> toBe(21.0)
  );

  test("blue / green", () =>
    expect(getContrast((0, 255, 0), (0, 0, 255)) |> extractFourDecimals)
    |> toBe(62618)
  );
  test("green / blue", () =>
    expect(getContrast((0, 0, 255), (0, 255, 0)) |> extractFourDecimals)
    |> toBe(62618)
  );
  test("blue-ish / red-ish", () =>
    expect(
      getContrast((45, 120, 220), (205, 7, 69)) |> extractFourDecimals,
    )
    |> toBe(13015)
  );
});