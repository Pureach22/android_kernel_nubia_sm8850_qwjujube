__int64 __fastcall btpower_off(int a1)
{
  int v1; // w0

  if ( a1 == 1 )
    v1 = 1;
  else
    v1 = 2;
  return power_disable(v1);
}
