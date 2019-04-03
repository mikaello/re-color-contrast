exception InvalidInput(string);

let map3Tuple = (f, (val1, val2, val3)) => (f(val1), f(val2), f(val3));

let hexToRgb = hexString => {
  let toIntValue = colorStr => "0x" ++ colorStr |> int_of_string;

  switch (String.length(hexString)) {
  | 4 =>
    let r1 = String.sub(hexString, 1, 1);
    let g1 = String.sub(hexString, 2, 1);
    let b1 = String.sub(hexString, 3, 1);

    (r1 ++ r1, g1 ++ g1, b1 ++ b1) |> map3Tuple(toIntValue);

  | 7 =>
    let r = String.sub(hexString, 1, 2);
    let g = String.sub(hexString, 3, 2);
    let b = String.sub(hexString, 5, 2);

    (r, g, b) |> map3Tuple(toIntValue);
  | _ => raise(InvalidInput("Invalid hex string: " ++ hexString))
  };
};

/** Get luminance from color, as defined in http://www.w3.org/TR/2008/REC-WCAG20-20081211/#relativeluminancedef
 */
let getRelativeLuminance = hexColor => {
  let rgbColor = hexColor |> hexToRgb;

  let convertToFraction = value => float_of_int(value) /. 255.;

  let convertToLinearRgb = gammaCompressedRgb =>
    if (gammaCompressedRgb < 0.03928) {
      gammaCompressedRgb /. 12.92;
    } else {
      ((gammaCompressedRgb +. 0.055) /. 1.055) ** 2.4;
    };

  let luminosityFunction = ((r, g, b)) =>
    0.2126 *. r +. 0.7152 *. g +. 0.0722 *. b;

  rgbColor
  |> map3Tuple(convertToFraction)
  |> map3Tuple(convertToLinearRgb)
  |> luminosityFunction;
};

/** Get contrast between two colors, as defined in http://www.w3.org/TR/2008/REC-WCAG20-20081211/#contrast-ratiodef
*/
let getContrast = (color1, color2) => {
  let relativeLuminance1 = getRelativeLuminance(color1);
  let relativeLuminance2 = getRelativeLuminance(color2);

  let brightest = max(relativeLuminance1, relativeLuminance2);
  let darkest = min(relativeLuminance1, relativeLuminance2);

  (brightest +. 0.05) /. (darkest +. 0.05);
};