program test;
var
  f1:text;
  f2:text;
  s1,s2:string;
  err:boolean;


  begin
    assign(f1,'orders.out');
    assign(f2,'orders.std');
    reset(f1);
    reset(f2);
    err:=false;
    while(not eof(f2)) do
      begin
        readln(f1,s1);
        readln(f2,s2);
        if s1<>s2 then
          begin
            err:=true;
            break;
          end;
      end;
    if err then writeln('Wrong') else writeln('OK');
    close(f1);
    close(f2);
  end.

