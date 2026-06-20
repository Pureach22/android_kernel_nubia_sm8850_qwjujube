__int64 __fastcall wlan_iecap_get(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  char v3; // w9
  __int64 v4; // x15
  unsigned int v5; // w8
  unsigned int v6; // w13
  int v7; // w10
  char v8; // w12
  unsigned __int8 v9; // w16
  unsigned int v10; // w17
  unsigned int v11; // w13
  int v12; // w13
  char v13; // w11

  v3 = a2 & 7;
  v4 = a2 >> 3;
  v5 = 8 - (a2 & 7);
  v6 = *(unsigned __int8 *)(a1 + v4);
  if ( v5 >= a3 )
    LOBYTE(v5) = a3;
  if ( (a2 & 7) + a3 < 9 )
  {
    v13 = 0;
    v7 = 0;
  }
  else
  {
    v7 = 0;
    v8 = 0;
    v9 = a2 & 7;
    do
    {
      v9 += v5;
      if ( v9 == 8 )
      {
        LODWORD(v4) = v4 + 1;
        v10 = *(unsigned __int8 *)(a1 + (unsigned __int8)v4);
        v9 = 0;
      }
      else
      {
        v10 = v6;
      }
      v11 = v6 >> v3;
      a3 -= (unsigned __int8)v5;
      v3 = v9;
      v12 = (v11 & ~(-1 << v5)) << v8;
      v8 += v5;
      if ( a3 <= (unsigned __int8)(8 - v9) )
        LOBYTE(v5) = a3;
      else
        LOBYTE(v5) = 8 - v9;
      v7 |= v12;
      v6 = v10;
    }
    while ( a3 + v9 > 8 );
    v13 = v8;
    v6 = v10;
  }
  return (((v6 >> v3) & ~(-1 << v5)) << v13) | v7;
}
