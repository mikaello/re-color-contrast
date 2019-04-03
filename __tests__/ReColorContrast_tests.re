open Jest;
open Expect;

open ColorContrast;

describe("relative luminance", () => {
  test("white", () =>
    expect(getRelativeLuminance((255, 255, 255))) |> toBe(1.0)
  );
  test("black", () =>
    expect(getRelativeLuminance((0, 0, 0))) |> toBe(0.0)
  );
  test("grey", () =>
    expect(getRelativeLuminance((119, 119, 119)))
    |> toBeSoCloseTo(0.1844, ~digits=3)
  );
  test("blue-ish", () =>
    expect(getRelativeLuminance((45, 120, 220)))
    |> toBeSoCloseTo(0.1915, ~digits=3)
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
    expect(getContrast((0, 255, 0), (0, 0, 255)))
    |> toBeSoCloseTo(6.2618, ~digits=3)
  );
  test("green / blue", () =>
    expect(getContrast((0, 0, 255), (0, 255, 0)))
    |> toBeSoCloseTo(6.2618, ~digits=3)
  );
  test("blue-ish / red-ish", () =>
    expect(getContrast((45, 120, 220), (205, 7, 69)))
    |> toBeSoCloseTo(1.3015, ~digits=3)
  );
});