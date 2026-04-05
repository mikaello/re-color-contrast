open Vitest

describe("relative luminance", () => {
  test("white", t => {
    t->expect(ColorContrast.getRelativeLuminance("#FFF"))->Expect.toBe(1.0)
  })
  test("black", t => {
    t->expect(ColorContrast.getRelativeLuminance("#000000"))->Expect.toBe(0.0)
  })
  test("grey", t => {
    t->expect(ColorContrast.getRelativeLuminance("#777"))->Expect.Float.toBeCloseTo(0.1844, 3)
  })
  test("blue", t => {
    t->expect(ColorContrast.getRelativeLuminance("#00f"))->Expect.Float.toBeCloseTo(0.0722, 3)
  })
  test("blue-ish", t => {
    t->expect(ColorContrast.getRelativeLuminance("#2D78DC"))->Expect.Float.toBeCloseTo(0.1915, 3)
  })
})

describe("color contrast", () => {
  test("white on black", t => {
    t->expect(ColorContrast.getContrast("#fff", "#000"))->Expect.toBe(21.0)
  })
  test("black on white", t => {
    t->expect(ColorContrast.getContrast("#000", "#fff"))->Expect.toBe(21.0)
  })
  test("blue / green", t => {
    t->expect(ColorContrast.getContrast("#0f0", "#00f"))->Expect.Float.toBeCloseTo(6.2618, 3)
  })
  test("green / blue", t => {
    t->expect(ColorContrast.getContrast("#00f", "#0f0"))->Expect.Float.toBeCloseTo(6.2618, 3)
  })
  test("blue-ish / red-ish", t => {
    t->expect(ColorContrast.getContrast("#2D78DC", "#CD0745"))->Expect.Float.toBeCloseTo(1.3015, 3)
  })
})
