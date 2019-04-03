open Jest;
open Expect;

open ColorContrast;

describe("relative luminance", () => {
  test("white", () =>
    expect(getRelativeLuminance("#FFF")) |> toBe(1.0)
  );
  test("black", () =>
    expect(getRelativeLuminance("#000000")) |> toBe(0.0)
  );
  test("grey", () =>
    expect(getRelativeLuminance("#777")) |> toBeSoCloseTo(0.1844, ~digits=3)
  );
  test("blue-ish", () =>
    expect(getRelativeLuminance("#2D78DC"))
    |> toBeSoCloseTo(0.1915, ~digits=3)
  );
});

describe("color contrast", () => {
  test("white on black", () =>
    expect(getContrast("#fff", "#000")) |> toBe(21.0)
  );

  test("black on white", () =>
    expect(getContrast("#000", "#fff")) |> toBe(21.0)
  );

  test("blue / green", () =>
    expect(getContrast("#0f0", "#00f")) |> toBeSoCloseTo(6.2618, ~digits=3)
  );
  test("green / blue", () =>
    expect(getContrast("#00f", "#0f0")) |> toBeSoCloseTo(6.2618, ~digits=3)
  );
  test("blue-ish / red-ish", () =>
    expect(getContrast("#2D78DC", "#CD0745"))
    |> toBeSoCloseTo(1.3015, ~digits=3)
  );
});