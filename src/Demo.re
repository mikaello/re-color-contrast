exception InvalidInput(string);

let hexToRgb = hexString => {
  let toIntValue = ((rStr, gStr, bStr)) => {
    let f = colorStr => "0x" ++ colorStr |> int_of_string;
    (f(rStr), f(gStr), f(bStr));
  };

  switch (String.length(hexString)) {
  | 4 =>
    let r1 = String.sub(hexString, 1, 1);
    let g1 = String.sub(hexString, 2, 1);
    let b1 = String.sub(hexString, 3, 1);

    (r1 ++ r1, g1 ++ g1, b1 ++ b1) |> toIntValue;

  | 7 =>
    let r = String.sub(hexString, 1, 2);
    let g = String.sub(hexString, 3, 2);
    let b = String.sub(hexString, 5, 2);

    (r, g, b) |> toIntValue;
  | _ => raise(InvalidInput("Invalid hex string: " ++ hexString))
  };
};