__int64 __fastcall free_bytes(unsigned int a1, unsigned int a2, int a3)
{
  int v3; // w9

  if ( a2 <= a1 )
    v3 = a3;
  else
    v3 = 0;
  return a2 - a1 + v3;
}
