open Vitest

describe("long hex to rgb", () => {
  test("converts black", t => {
    t->expect(ColorContrast.hexToRgb("#000000"))->Expect.toEqual((0, 0, 0))
  })
  test("converts white", t => {
    t->expect(ColorContrast.hexToRgb("#ffffff"))->Expect.toEqual((255, 255, 255))
  })
  test("converts red", t => {
    t->expect(ColorContrast.hexToRgb("#ff0000"))->Expect.toEqual((255, 0, 0))
  })
  test("converts green", t => {
    t->expect(ColorContrast.hexToRgb("#00ff00"))->Expect.toEqual((0, 255, 0))
  })
  test("converts blue", t => {
    t->expect(ColorContrast.hexToRgb("#0000ff"))->Expect.toEqual((0, 0, 255))
  })
})

describe("short hex to rgb", () => {
  test("converts black", t => {
    t->expect(ColorContrast.hexToRgb("#000"))->Expect.toEqual((0, 0, 0))
  })
  test("converts white", t => {
    t->expect(ColorContrast.hexToRgb("#fff"))->Expect.toEqual((255, 255, 255))
  })
  test("converts red", t => {
    t->expect(ColorContrast.hexToRgb("#f00"))->Expect.toEqual((255, 0, 0))
  })
  test("converts green", t => {
    t->expect(ColorContrast.hexToRgb("#0f0"))->Expect.toEqual((0, 255, 0))
  })
  test("converts blue", t => {
    t->expect(ColorContrast.hexToRgb("#00f"))->Expect.toEqual((0, 0, 255))
  })
})

describe("invalid input to RGB", () => {
  test("throws when inserting invalid input", t => {
    Expect.toThrow(t->expect(() => ColorContrast.hexToRgb("tullball")))
  })
})
