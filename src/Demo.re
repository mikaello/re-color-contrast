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