exception InvalidInput(string)

@send external sliceStr: (string, int, int) => string = "slice"
@val external parseInt: (string, int) => int = "parseInt"

let map3Tuple = ((val1, val2, val3), f) => (f(val1), f(val2), f(val3))

let hexToRgb = hexString => {
  let toIntValue = colorStr => parseInt(colorStr, 16)

  switch String.length(hexString) {
  | 4 =>
    let r1 = hexString->sliceStr(1, 2)
    let g1 = hexString->sliceStr(2, 3)
    let b1 = hexString->sliceStr(3, 4)
    (r1 ++ r1, g1 ++ g1, b1 ++ b1)->map3Tuple(toIntValue)

  | 7 =>
    let r = hexString->sliceStr(1, 3)
    let g = hexString->sliceStr(3, 5)
    let b = hexString->sliceStr(5, 7)
    (r, g, b)->map3Tuple(toIntValue)

  | _ => throw(InvalidInput("Invalid hex string: " ++ hexString))
  }
}

/** Get luminance from a color, as defined in
  http://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
*/
let getRelativeLuminance = hexColor => {
  let rgbColor = hexToRgb(hexColor)

  let convertToFraction = value => Belt.Int.toFloat(value) /. 255.

  let convertToLinearRgb = gammaCompressedRgb =>
    if gammaCompressedRgb < 0.03928 {
      gammaCompressedRgb /. 12.92
    } else {
      ((gammaCompressedRgb +. 0.055) /. 1.055) ** 2.4
    }

  let luminosityFunction = ((r, g, b)) => 0.2126 *. r +. 0.7152 *. g +. 0.0722 *. b

  rgbColor->map3Tuple(convertToFraction)->map3Tuple(convertToLinearRgb)->luminosityFunction
}

/** Get contrast between two colors, as defined in
  http://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
*/
let getContrast = (color1, color2) => {
  let relativeLuminance1 = getRelativeLuminance(color1)
  let relativeLuminance2 = getRelativeLuminance(color2)

  let brightest = max(relativeLuminance1, relativeLuminance2)
  let darkest = min(relativeLuminance1, relativeLuminance2)

  (brightest +. 0.05) /. (darkest +. 0.05)
}
