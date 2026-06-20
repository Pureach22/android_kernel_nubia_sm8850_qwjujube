__int64 __fastcall ieee80211_put_srates_elem(
        _DWORD *a1,
        __int64 a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        unsigned __int8 a6)
{
  int v6; // w8
  unsigned __int8 v7; // w13
  int v8; // w9
  __int64 v9; // x14
  unsigned __int64 v10; // x15
  int v11; // w14
  int v12; // w15
  int v13; // w19
  unsigned __int8 v14; // w22
  char v15; // w23
  unsigned int v16; // w8
  int v22; // w9
  __int64 v23; // x8
  unsigned __int8 v24; // w11
  int v25; // w10
  unsigned __int8 v26; // w26
  __int64 v27; // x11
  char v29; // w20
  __int64 v31; // [xsp+0h] [xbp-10h]

  v6 = *(_DWORD *)(a2 + 24);
  if ( v6 >= 1 )
  {
    v7 = 0;
    v8 = 0;
    do
    {
      v9 = 12LL * v7;
      v10 = (unsigned __int64)a5 >> v7++;
      v11 = *(_DWORD *)(*(_QWORD *)(a2 + 8) + v9);
      if ( (v10 & 1) != 0 )
        v12 = v8;
      else
        v12 = v8 + 1;
      if ( (a4 & ~v11) == 0 )
        v8 = v12;
    }
    while ( v6 > (unsigned int)v7 );
    v13 = a6;
    if ( a6 != 1 )
    {
      if ( (unsigned __int8)v8 < 9u )
        return 0;
      v14 = v8 - 8;
      v15 = 8;
      if ( a1[29] )
        return (unsigned int)-105;
LABEL_18:
      if ( a1[53] - a1[52] < v14 + 2 )
        return (unsigned int)-105;
      *(_BYTE *)skb_put(a1, 1) = a6;
      *(_BYTE *)skb_put(a1, 1) = v14;
      v22 = *(_DWORD *)(a2 + 24);
      if ( v22 >= 1 && v14 )
      {
        v23 = a2;
        v24 = 0;
        v31 = a3;
        v25 = a4;
        do
        {
          v26 = v24;
          v27 = *(_QWORD *)(v23 + 8) + 12LL * v24;
          if ( (v25 & ~*(_DWORD *)v27) == 0 && ((1LL << v26) & a5) == 0 )
          {
            if ( v15 )
            {
              --v15;
            }
            else
            {
              v29 = ((858993460 * (unsigned __int64)((unsigned int)*(unsigned __int16 *)(v27 + 4) + 4)) >> 32)
                  | ((((1LL << v26) & v31) != 0) << 7);
              *(_BYTE *)skb_put(a1, 1) = v29;
              v23 = a2;
              v25 = a4;
              v22 = *(_DWORD *)(a2 + 24);
              v15 = 0;
              --v14;
            }
          }
          v24 = v26 + 1;
        }
        while ( v22 > (unsigned __int8)(v26 + 1) && v14 );
      }
      if ( v14 )
      {
        _warn_printk("rates confused: rates:%d, element:%d\n", v14, v13);
        v16 = 0;
        __break(0x800u);
        return v16;
      }
      return 0;
    }
LABEL_14:
    v15 = 0;
    if ( (v8 & 0xF8) != 0 )
      v14 = 8;
    else
      v14 = v8;
    v13 = 1;
    if ( a1[29] )
      return (unsigned int)-105;
    goto LABEL_18;
  }
  LOBYTE(v8) = 0;
  v16 = 0;
  if ( a6 == 1 )
    goto LABEL_14;
  return v16;
}
