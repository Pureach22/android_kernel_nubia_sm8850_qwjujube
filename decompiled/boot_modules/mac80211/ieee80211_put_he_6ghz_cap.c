__int64 __fastcall ieee80211_put_he_6ghz_cap(_DWORD *a1, __int64 a2, int a3)
{
  int v5; // w8
  unsigned int v7; // w22
  __int64 v8; // x9
  __int64 v9; // x8
  char v10; // w10
  _WORD *v11; // x9
  __int64 v12; // x10
  __int16 v13; // w8
  __int16 v14; // w21

  v5 = *(_DWORD *)(a2 + 4720);
  if ( *(_BYTE *)(a2 + 5848) != 1 )
  {
LABEL_5:
    v7 = (unsigned __int8)*(_DWORD *)(a2 + 4720);
    goto LABEL_6;
  }
  if ( v5 != 2 )
  {
    if ( v5 == 3 )
    {
      v7 = 9;
      goto LABEL_6;
    }
    goto LABEL_5;
  }
  v7 = 8;
LABEL_6:
  if ( (cfg80211_any_usable_channels(*(_QWORD *)(*(_QWORD *)(a2 + 1616) + 72LL), 8, 0x2000) & 1) == 0 )
    return 0;
  if ( v7 < 0xC )
  {
    v8 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 1616) + 72LL) + 352LL);
    v9 = *(unsigned __int16 *)(v8 + 92);
    if ( *(_WORD *)(v8 + 92) )
    {
      v10 = v7 == 4 ? 3 : v7;
      v11 = *(_WORD **)(v8 + 96);
      v12 = 1LL << v10;
      while ( ((unsigned __int16)v12 & *v11) == 0 )
      {
        --v9;
        v11 += 64;
        if ( !v9 )
          return 0;
      }
      if ( v11 )
      {
        v13 = *(_WORD *)((char *)v11 + 57);
        if ( v13 )
        {
          v14 = v13 & 0xF9FF;
          if ( a3 > 2 )
          {
            if ( a3 == 3 )
            {
              v14 |= 0x200u;
              if ( !a1[29] )
              {
LABEL_29:
                if ( (unsigned int)(a1[53] - a1[52]) >= 5 )
                {
                  *(_BYTE *)skb_put(a1, 1) = -1;
                  *(_BYTE *)skb_put(a1, 1) = 3;
                  *(_BYTE *)skb_put(a1, 1) = 59;
                  *(_WORD *)skb_put(a1, 2) = v14;
                  return 0;
                }
              }
              return 4294967191LL;
            }
            if ( a3 != 4 )
            {
LABEL_28:
              if ( !a1[29] )
                goto LABEL_29;
              return 4294967191LL;
            }
          }
          else if ( a3 )
          {
            if ( a3 != 1 )
              goto LABEL_28;
LABEL_27:
            v14 = v13 | 0x600;
            goto LABEL_28;
          }
          __break(0x800u);
          goto LABEL_27;
        }
      }
    }
    return 0;
  }
  __break(0x800u);
  return 0;
}
