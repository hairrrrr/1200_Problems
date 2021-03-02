PROGRAM Ananagrams; (*Originally North Central 91-07*)

CONST probname = 'PROBLEM';
      prob_id = 'A';
      file_id = 'PROBLEM';

VAR   debugcounter: integer;

CONST
      MaxWords = 2500;
      BigPrime = 32749;

TYPE  word = string;
      entry = record
                ThisWord: word;
                sign: integer;
                alike: Boolean
                end;
      list = array[0..MaxWords] of entry;

VAR   words: list;
      NumWords: integer;

FUNCTION  ReadWords: Boolean;     forward;
PROCEDURE SolveProblem;           forward;

PROCEDURE Error(s:string);
begin
  writeln; writeln(s); HALT;
end;

PROCEDURE MainProg;
begin  {Main}
NumWords := 0;
while ReadWords do;
SolveProblem;

end; {of main procedure}

function lower(ch: char): char;
begin
case ch of
  'a'..'z': lower := ch;
  'A'..'Z': lower := chr(ord(ch) - ord('A') + ord('a'));
      otherwise  Error(ch + ' is not a valid character');
   end;
end;  {lower}

FUNCTION Signature(ThisWord: word): word;
var i, j, m: integer;
    ch: char;

begin
for i := 1 to length(ThisWord) do ThisWord[i] := lower(ThisWord[i]);
for i := 1 to length(ThisWord)-1 do begin
  m := i;
  for j := i+1 to length(ThisWord) do
    if ThisWord[j] < ThisWord[m] then m := j;
  ch := ThisWord[i]; ThisWord[i] := ThisWord[m]; ThisWord[m] := ch end;
Signature := ThisWord;
end;

function ReadWords: Boolean;
var line: string;
    NextWord: word;
    i,l: integer;
    sgn: longint;

FUNCTION Val(ch: char): integer;
begin Val := ord(ch) - ord('a') + 1 end;

begin  {ReadWords}
readln(line);
if line = '#'
  then ReadWords := false
  else begin
    line := line + ' '; ReadWords := true;
    while length(line) > 0 do begin
      l := Pos(' ', line); NextWord := Copy(line, 1, l-1); Delete(line, 1, l);
      inc(NumWords);
      with words[NumWords] do begin
        ThisWord := NextWord; NextWord := Signature(NextWord);
        sgn := 1;
        for i := 1 to length(NextWord) do
          sgn := (sgn*2 + Val(NextWord[i])) mod BigPrime;
        sign := sgn; alike := false end;
      end;  {while length(line) > 1}
    end;
end;

PROCEDURE SortWordsBySignature;
{For now do an Insertion Sort -- later put in qsort}
var i,j,x: integer;
    tw: entry;

begin
words[0].sign := 0;
for i := 2 to NumWords do begin
  tw := words[i]; x := tw.sign; j := i-1;
  while x < words[j].sign do begin
    words[j+1] := words[j]; dec(j) end;
  words[j+1] := tw end;
end;

PROCEDURE CheckforAnagrams;
var i: integer;

begin
for i := 2 to NumWords do
  if words[i].sign = words[i-1].sign
    then begin words[i].alike := true; words[i-1].alike := true end;
end;

PROCEDURE DiscardAnagrams;
var i,j: integer;
begin
j := 1;
for i := 1 to NumWords do
  if not words[i].alike and (i >= j)
    then begin words[j] := words[i]; inc(j) end;
NumWords := j-1;
end;

PROCEDURE SortWordsByWord;
{For now do an Insertion Sort -- later put in qsort}
var i,j: integer;
    x: word;
    tw: entry;

begin
words[0].ThisWord:= '';
for i := 2 to NumWords do begin
  tw := words[i]; x := tw.ThisWord; j := i-1;
  while x < words[j].ThisWord do begin
    words[j+1] := words[j]; dec(j) end;
  words[j+1] := tw end;
end;

PROCEDURE ListWords;
var i: integer;

begin
for i := 1 to NumWords do with words[i] do begin
  writeln(ThisWord)
  end;
end;

PROCEDURE SolveProblem;
var i: integer;

begin
SortWordsBySignature;
CheckforAnagrams;
DiscardAnagrams;
if NumWords > 0
  then begin SortWordsByWord; ListWords end
  else writeln(' No Ananagrams found');

end;

begin mainprog end.

