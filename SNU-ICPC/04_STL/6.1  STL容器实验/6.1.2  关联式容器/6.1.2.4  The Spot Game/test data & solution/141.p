Program ProblemB (input, output);

Const
   max = 50;
   max2 = 100;
   max4 = 200;

Type
   boardtype = array[1..max, 1..max] of boolean;
Var
   move, x, y, i, j, n : integer;
   board : boardtype;
   prev : array[0..max2] of string;
   finished : boolean;
   rest : string;


Procedure Scream (message : string);

   Begin
   writeln ('****** Problem wuth input data *****');
   writeln (message);
   writeln ('************************************');
   halt;
   End;

function encode : string;

  var
    i, j : integer;
    code : string;

  begin
  code := '';
  for i := 1 to n do
    for j := 1 to n do
      if board[i, j] then
        code := code + chr(i) + chr(j);
  encode := code;
  end;

procedure test;

  var
    p, spin, i, j : integer;
    cboard : boardtype;
    code : string;

  begin
  for spin := 1 to 4 do
    begin
    for i := 1 to n do
      for j := 1 to n do
        cboard[i, j] := board[n - j + 1, i];
    board := cboard;
    code := encode;
    for p := 0 to (move - 1) do
      begin
      if code = prev[p] then
        begin
        if not finished then
          writeln('Player ', ord(odd(move)) + 1:1, ' wins on move ', move:1);
        finished := true;
        end;
      end;
    end;
  prev[move] := code;
  end;


BEGIN
repeat
  read(n);
  if not eoln then
    scream('Redundant data following board size');
  if (n > 0) then
    begin
    finished := false;
    prev[0] := '';
    for i := 1 to n do
      for j := 1 to n do
        board[i, j] := false;
    for move := 1 to 2 * n do
      begin
      readln(x, y, rest);
      while (rest <> '') and (pos(' ', rest) <> 0) do
        delete(rest, pos(' ', rest), 1);
      if (rest = '+') then
        if board[x, y] then
          scream('Board set twice  ++')
        else
          board[x, y] := true
      else if (rest = '-') then
        if not board[x, y] then
          scream('Board unset twice  --')
        else
          board[x, y] := false
      else
        scream('Invalid move  ' + rest);
      if not finished then
        test;
      end;
    if not finished then
      writeln('Draw');
    end;
until n = 0;

END.
