__int64 __fastcall cfg80211_get_6ghz_power_type(unsigned __int8 *a1, unsigned int a2)
{
  unsigned __int64 v2; // x10
  unsigned __int8 *v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  unsigned int *v6; // x10
  unsigned __int64 v7; // x11
  int v8; // w8
  unsigned int v9; // w8
  bool v10; // cc
  __int64 v11; // x8
  unsigned __int64 v12; // x8

  if ( (a2 & 0xFFFFFFFE) != 0 )
  {
    v2 = a2;
    v3 = &a1[a2];
    do
    {
      v4 = a1[1];
      if ( v2 < v4 + 2 )
        break;
      if ( a1[1] && *a1 == 255 && a1[2] == 36 )
      {
        LODWORD(v5) = 0;
        if ( !a1 || (unsigned int)v4 < 7 )
          return (unsigned int)v5;
        v6 = (unsigned int *)(a1 + 3);
        if ( a1 == (unsigned __int8 *)-3LL )
          break;
        v7 = *v6;
        if ( (v7 & 0x4000) != 0 )
          v8 = 9;
        else
          v8 = 6;
        v9 = v8 + (((unsigned int)v7 >> 15) & 1);
        if ( (v7 & 0x20000) != 0 )
          v9 += 5;
        v10 = (unsigned int)v4 > v9;
        LODWORD(v5) = 0;
        if ( !v10 || (v7 & 0x20000) == 0 )
          return (unsigned int)v5;
        v11 = 9;
        if ( (v7 & 0x4000) == 0 )
          v11 = 6;
        v5 = (__int64)v6 + v11 + ((v7 >> 15) & 1);
        if ( !v5 )
          return (unsigned int)v5;
        v12 = ((unsigned __int64)*(unsigned __int8 *)(v5 + 1) >> 3) & 7;
        if ( (unsigned int)v12 > 4 )
          break;
        return dword_BE3D4[v12];
      }
      a1 += v4 + 2;
      v2 = v3 - a1;
    }
    while ( v3 - a1 > 1 );
  }
  LODWORD(v5) = 0;
  return (unsigned int)v5;
}
