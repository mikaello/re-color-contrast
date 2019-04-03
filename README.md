# re-color-contrast

[![Build Status](https://travis-ci.org/mikaello/re-color-contrast.svg?branch=master)](https://travis-ci.org/mikaello/re-color-contrast)

Calculate color contrast of two colors. The result is a number between 1.0 and 21.0, and can be used to determine if contrast fullfills [WCAG success criterion for color contrast](https://www.w3.org/TR/UNDERSTANDING-WCAG20/visual-audio-contrast-contrast.html).

## Getting started

```
yarn add mikaello/re-color-contrast
```

Then add `re-color-contrast` as a dependency to `bsconfig.json`:

```diff
"bs-dependencies": [
+  "re-color-contrast"
]
```

## Example

```reason
open ReColorContrast;

let blue = "#00f";
let green = "#00ff00";

ColorContrast.getContrast(blue, green); // 6.2618 ...

ColorContrast.getRelativeLuminance(blue); // 0.0722
```

## API

- `getContrast(string, string) => float` - takes in two hex color strings and returns a float in range `[1..21]`. 1 is no contrast, and 21 is best contrast (colors of opposing side of spectrum). See [WCAG](http://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef) for details on calculation.
- `getRelativeLuminance(string) => float` - takes in a hex color string and returns a float in range `[0..1]`. 0 is no luminance and 1 is max. See [WCAG](http://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef) for details on calculation.

## Alternatives

- [bs-tinycolor](https://github.com/mikaello/bs-tinycolor) has accessibility functions that does contrast checking and more
- [color-contrast](https://github.com/jescalan/color-contrast) is a JS library with same functionality as this library, but does also accepts all kinds of input formats (not only hex)

## Contribute

- If you find bugs or want to improve this library, feel free to open an issue or PR.
- If you are upgrading any dependencies, please use yarn so `yarn.lock` is updated.
- Try to adhere to [Angular commit guidelines](https://github.com/angular/angular.js/blob/master/DEVELOPERS.md#-git-commit-guideline).
