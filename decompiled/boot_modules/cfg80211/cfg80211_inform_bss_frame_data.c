__int64 __fastcall cfg80211_inform_bss_frame_data(
        __int64 a1,
        __int64 a2,
        unsigned __int16 *a3,
        unsigned __int64 a4,
        unsigned int a5)
{
  int v5; // w9
  unsigned __int64 v6; // x8
  size_t v7; // x10
  char *v8; // x7
  unsigned __int64 v9; // x12
  char *v10; // x9
  unsigned __int8 *v11; // x8
  __int64 v12; // x11
  __int64 v13; // x3
  int *v14; // x3
  __int16 *v15; // x12
  __int16 *v16; // x11
  int v17; // w8

  if ( !a3 || !a1 )
    goto LABEL_22;
  v5 = *a3;
  if ( (v5 & 0xFC) != 0x1C )
  {
    if ( a4 > 0x23 )
    {
      v7 = a4 - 36;
      v8 = (char *)(a3 + 18);
      v14 = (int *)(a3 + 8);
      v15 = (__int16 *)(a3 + 16);
      v16 = (__int16 *)(a3 + 17);
      if ( (v5 & 0xFC) == 0x50 )
        v17 = 2;
      else
        v17 = 1;
      return cfg80211_inform_bss_data(a1, a2, v17, v14, *((_QWORD *)a3 + 3), *v16, *v15, v8, v7, a5);
    }
LABEL_22:
    v13 = 0;
    __break(0x800u);
    return v13;
  }
  v6 = 15;
  if ( (~v5 & 0x11C) == 0 )
    v6 = 18;
  v7 = a4 - v6;
  if ( a4 < v6 )
    goto LABEL_22;
  if ( (v7 & 0xFFFFFFFE) != 0 )
  {
    v8 = (char *)a3 + v6;
    v9 = (unsigned int)(a4 - v6);
    v10 = (char *)a3 + v6 + v9;
    v11 = (unsigned __int8 *)a3 + v6;
    do
    {
      v12 = v11[1];
      if ( v9 < v12 + 2 )
        break;
      if ( *v11 == 213 )
      {
        v13 = 0;
        if ( v11 && (unsigned int)v12 >= 8 )
        {
          v16 = (__int16 *)(v11 + 2);
          v14 = (int *)(a3 + 2);
          v15 = (__int16 *)(v11 + 4);
          v17 = 3;
          return cfg80211_inform_bss_data(a1, a2, v17, v14, *((_QWORD *)a3 + 3), *v16, *v15, v8, v7, a5);
        }
        return v13;
      }
      v11 += v12 + 2;
      v9 = v10 - (char *)v11;
    }
    while ( v10 - (char *)v11 > 1 );
  }
  return 0;
}
