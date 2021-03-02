{
@BEGIN_OF_SOURCE_CODE
}

(* @JUDGE_ID: 8286AE 127 Pascal "" *)
type
   cardptr=^card;
   card=record
      rank,suit:char;
      next:cardptr;
      end;
var
  pile:array[0..51] of cardptr;
  deck:cardptr;
  npiles:integer;
  i:integer;

procedure pc(p:cardptr);
begin
  if p=nil then write('nil') else write(p^.rank,p^.suit);
end;

function matches(i,j:integer):boolean;
var
  p1,p2:cardptr;
begin
if i>=0 then begin
  p1:=pile[i];
  p2:=pile[j];
  matches:=(p1^.rank=p2^.rank)or(p1^.suit=p2^.suit);
  end
else
  matches:=false;
end;

procedure move(var p1,p2:cardptr);
var
  p:cardptr;
begin
  p:=p1;
  p1:=p1^.next;
  p^.next:=p2;
  p2:=p;
end;

procedure movep(i1,i2:integer);
var
   j:integer;
begin
  move(pile[i2],pile[i1]);
  if pile[i2]=nil then
  begin
    for j:=i2 to npiles-2 do
      pile[j]:=pile[j+1];
    npiles:=npiles-1;
  end;
  i:=0;
end;

procedure play;
begin
  npiles:=0;
  while deck<>nil do
  begin
    pile[npiles]:=nil;
    npiles:=npiles+1;
    move(deck,pile[npiles-1]);
    i:=1;
    while i<npiles do
    begin
      if matches(i-3,i) then
        movep(i-3,i)
      else if matches(i-1,i) then
        movep(i-1,i)
      else
        i:=i+1;
    end;
  end;
end;

function inputdata : boolean;
var
   line:string;
   k,j,i:integer;
   p,t:cardptr;
   ok : boolean;
begin
ok := true;
{writeln('begin input');}
deck:=nil;
t:=nil;
for j:=1 to 2 do begin
   if ok then
      begin
      readln(line);
   {   writeln('read ',line);}
      if line[1] = '#' then
	 ok := false;
      end;
   if ok then
      begin
      for i:=0 to 25 do begin
         k:=3*i+1;
         new(p);
         p^.rank:=line[k];
         p^.suit:=line[k+1];
         p^.next:=nil;
         if t=nil then deck:=p else t^.next:=p;
         t:=p;
         end;
      end;
   end;
{writeln('end input');}
inputdata := ok;
end;

function count(p:cardptr):integer;
var
   n:integer;
begin
n:=0;
while p<>nil do begin
   n:=n+1;
   p:=p^.next;
   end;
count:=n;
end;

procedure print;
begin
write(npiles:1,' piles remaining:');
for i:=0 to npiles-1 do write(' ',count(pile[i]):1);
writeln;
end;

procedure pp(s:string; p:cardptr);
begin
write(s,' ');
while p<>nil do begin
   write(p^.rank,p^.suit,' ');
   p:=p^.next;
   end;
writeln;
end;

begin
while inputdata do
   begin
   {pp('deck:',deck);}
   play;
   print;
   end;
end.

{
@END_OF_SOURCE_CODE
}