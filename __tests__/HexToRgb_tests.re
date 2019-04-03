open Jest;
open Expect;

open ColorContrast;

describe("long hex to rgb", () => {
  test("converts black", () =>
    expect(hexToRgb("#000000")) |> toEqual((0, 0, 0))
  );
  test("converts white", () =>
    expect(hexToRgb("#ffffff")) |> toEqual((255, 255, 255))
  );
  test("converts red", () =>
    expect(hexToRgb("#ff0000")) |> toEqual((255, 0, 0))
  );
  test("converts green", () =>
    expect(hexToRgb("#00ff00")) |> toEqual((0, 255, 0))
  );
  test("converts blue", () =>
    expect(hexToRgb("#0000ff")) |> toEqual((0, 0, 255))
  );
});

describe("short hex to rgb", () => {
  test("converts black", () =>
    expect(hexToRgb("#000")) |> toEqual((0, 0, 0))
  );
  test("converts white", () =>
    expect(hexToRgb("#fff")) |> toEqual((255, 255, 255))
  );
  test("converts red", () =>
    expect(hexToRgb("#f00")) |> toEqual((255, 0, 0))
  );
  test("converts green", () =>
    expect(hexToRgb("#0f0")) |> toEqual((0, 255, 0))
  );
  test("converts blue", () =>
    expect(hexToRgb("#00f")) |> toEqual((0, 0, 255))
  );
});