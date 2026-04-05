# re-color-contrast

[![NPM version](https://img.shields.io/npm/v/re-color-contrast.svg)](https://www.npmjs.com/package/re-color-contrast)
[![CI](https://github.com/mikaello/re-color-contrast/actions/workflows/ci.yml/badge.svg)](https://github.com/mikaello/re-color-contrast/actions/workflows/ci.yml)

[ReScript](https://rescript-lang.org) library to calculate color contrast of two colors.
The result is a number between 1.0 and 21.0, and can be used to determine if contrast fulfills the [WCAG success criterion for color contrast](https://www.w3.org/TR/WCAG21/#contrast-minimum).

## Getting started

```sh
npm install re-color-contrast
```

Then add `re-color-contrast` as a dependency to `rescript.json`:

```diff
"bs-dependencies": [
+  "re-color-contrast"
]
```

## Example

```rescript
open ReColorContrast

let blue = "#00f"
let green = "#00ff00"

ColorContrast.getContrast(blue, green) // 6.2618 ...

ColorContrast.getRelativeLuminance(blue) // 0.0722
```

## API

- `getContrast(string, string) => float` — takes two hex color strings and returns a float in the range `[1..21]`.
  1 is no contrast, 21 is maximum contrast.
  See [WCAG contrast ratio definition](https://www.w3.org/TR/WCAG21/#dfn-contrast-ratio) for details.
- `getRelativeLuminance(string) => float` — takes a hex color string and returns a float in the range `[0..1]`.
  0 is no luminance, 1 is maximum luminance.
  See [WCAG relative luminance definition](https://www.w3.org/TR/WCAG21/#dfn-relative-luminance) for details.

Both 3-character (`#rgb`) and 6-character (`#rrggbb`) hex strings are supported.

## Alternatives

- [rescript-tinycolor](https://github.com/mikaello/bs-tinycolor) has accessibility functions that do contrast checking and more
- [color-contrast](https://github.com/jescalan/color-contrast) is a JS library with the same functionality, but also accepts other input formats (not only hex)

## Contribute

If you find bugs or want to improve this library, feel free to open an issue or PR.
Try to adhere to [Conventional Commits](https://www.conventionalcommits.org/).
