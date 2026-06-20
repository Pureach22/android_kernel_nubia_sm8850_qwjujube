__int64 __fastcall wlan_iecap_set(__int64 result, unsigned __int8 a2, unsigned __int8 a3, unsigned int a4)
{
  char v4; // w8
  unsigned int v5; // w10
  unsigned __int8 v6; // w9
  char v7; // w12
  unsigned __int8 v8; // w14
  __int64 v9; // x1
  int v10; // w17
  bool v11; // zf
  int v12; // w16
  int v13; // w15
  char v14; // w16
  char v15; // w15
  char v16; // w11

  v4 = a2 & 7;
  v5 = 8 - (a2 & 7);
  v6 = a2 >> 3;
  if ( v5 >= a3 )
    LOBYTE(v5) = a3;
  if ( (a2 & 7) + (unsigned int)a3 < 9 )
  {
    v16 = 0;
  }
  else
  {
    v7 = 0;
    v8 = a2 & 7;
    do
    {
      v8 += v5;
      v9 = v6;
      a3 -= v5;
      v7 += v5;
      v10 = ~(-1 << v5);
      v11 = v8 == 8;
      v12 = v10 << v4;
      if ( v8 == 8 )
        v8 = 0;
      v13 = (a4 & v10) << v4;
      v4 = v8;
      v14 = *(_BYTE *)(result + v6) & ~(_BYTE)v12;
      if ( v11 )
        ++v6;
      v15 = v14 | v13;
      if ( a3 <= (unsigned int)(unsigned __int8)(8 - v8) )
        LOBYTE(v5) = a3;
      else
        LOBYTE(v5) = 8 - v8;
      *(_BYTE *)(result + v9) = v15;
    }
    while ( v8 + (unsigned int)a3 > 8 );
    v16 = v7;
  }
  *(_BYTE *)(result + v6) = *(_BYTE *)(result + v6) & ~(~(-1 << v5) << v4) | (((a4 >> v16) & ~(-1 << v5)) << v4);
  return result;
}
