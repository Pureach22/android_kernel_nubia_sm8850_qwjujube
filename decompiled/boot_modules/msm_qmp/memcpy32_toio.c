__int64 __fastcall memcpy32_toio(__int64 result, unsigned int *a2, unsigned __int64 a3)
{
  __int64 v4; // x1
  unsigned __int64 v5; // x20
  unsigned int v6; // t1
  __int64 v7; // x21

  v4 = result;
  if ( (a3 & 3) != 0 )
  {
    __break(0x800u);
    if ( a3 < 4 )
      return result;
  }
  else if ( a3 < 4 )
  {
    return result;
  }
  v5 = a3 >> 2;
  do
  {
    v6 = *a2++;
    --v5;
    v7 = v4 + 4;
    result = writel(v6, v4);
    v4 = v7;
  }
  while ( v5 );
  return result;
}
