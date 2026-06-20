__int64 __fastcall ieee80211_tx_h_select_key(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x10
  __int16 *v3; // x9
  unsigned __int64 v4; // x11
  __int64 v5; // x11
  unsigned __int64 v6; // x11
  __int64 v7; // x12
  __int64 v8; // x11
  unsigned int v9; // w15
  int v10; // w13
  __int16 v11; // w14
  int v12; // w16
  int v13; // w16
  __int64 v14; // x15
  unsigned int v15; // w14
  unsigned int v16; // w13
  bool v17; // w12
  __int16 v19; // w12
  __int64 v20; // x10
  __int64 v21; // x10
  int v22; // w14
  unsigned int v23; // w10

  v1 = *a1;
  if ( (*(_BYTE *)(*a1 + 42LL) & 1) != 0 )
    goto LABEL_61;
  v2 = a1[6];
  v3 = *(__int16 **)(v1 + 224);
  if ( !v2 )
    goto LABEL_5;
  v4 = *(unsigned __int8 *)(v2 + 120);
  if ( v4 < 5 )
  {
    v5 = *(_QWORD *)(v2 + 8 * v4 + 88);
    if ( v5 )
      goto LABEL_32;
LABEL_5:
    v6 = (unsigned __int64)*(unsigned int *)(v1 + 80) >> 28;
    if ( (_DWORD)v6 == 15 )
    {
      v7 = a1[5];
      v8 = v7 + 3616;
    }
    else
    {
      v7 = a1[5];
      v8 = *(_QWORD *)(v7 + 8 * v6 + 4568);
      if ( !v8 )
      {
        if ( (*((_DWORD *)v3 + 1) & 1) != 0 )
          goto LABEL_37;
        goto LABEL_31;
      }
    }
    v9 = *(_DWORD *)(v1 + 112);
    v10 = *((_DWORD *)v3 + 1);
    v11 = *v3;
    v12 = v10 & 1;
    if ( v9 >= 0x19 && (v11 & 0xFC) == 0xD0 )
    {
      if ( (v10 & 1) == 0 )
        goto LABEL_28;
      if ( (unsigned int)*((unsigned __int8 *)v3 + 24) - 13 < 2 )
        goto LABEL_26;
      v12 = 1;
    }
    if ( (v11 & 0xC) == 0 && v9 >= 0x19 && v12 )
    {
      v13 = v11 & 0xF0;
      v14 = 120;
      if ( v13 == 160 || v13 == 192 )
      {
LABEL_27:
        v5 = *(_QWORD *)(v8 + v14);
        if ( v5 )
          goto LABEL_32;
        goto LABEL_28;
      }
      if ( v13 == 208 )
      {
        if ( (*v3 & 0x4000) != 0
          || ((v15 = *((unsigned __int8 *)v3 + 24), v15 > 0x16) || ((1 << v15) & 0x708890) == 0) && v15 != 127 )
        {
          v5 = *(_QWORD *)(v8 + 120);
          if ( v5 )
            goto LABEL_32;
          goto LABEL_28;
        }
      }
LABEL_26:
      v14 = 112;
      goto LABEL_27;
    }
    if ( v12 )
      goto LABEL_26;
LABEL_28:
    if ( (v10 & 1) != 0 )
      goto LABEL_37;
LABEL_31:
    v5 = *(_QWORD *)(v7 + 1928);
    if ( v5 )
    {
LABEL_32:
      a1[7] = v5;
      v16 = *(_DWORD *)(v5 + 544) - 1027073;
      v17 = 0;
      if ( v16 <= 0xC )
      {
        if ( ((1 << v16) & 0x388) != 0 )
        {
          v19 = *v3;
          if ( (*v3 & 0x4C) == 8
            || v2
            && (v19 & 0xC) == 0
            && (*(_QWORD *)(v2 + 216) & 0x80) != 0
            && *(_DWORD *)(v1 + 112) >= 0x19u
            && ((v21 = *(_QWORD *)(v1 + 224), v22 = *(_WORD *)v21 & 0xFC, v22 == 160)
             || v22 == 192
             || v22 == 208
             && ((*(_WORD *)v21 & 0x4000) != 0
              || ((v23 = *(unsigned __int8 *)(v21 + 24), v23 > 0x16) || ((1 << v23) & 0x708890) == 0) && v23 != 127))
            || *(_DWORD *)(v1 + 112) >= 0x19u
            && (v20 = *(_QWORD *)(v1 + 224), (*(_WORD *)v20 & 0xFC) == 0xD0)
            && (*(_BYTE *)(v20 + 4) & 1) != 0
            && (unsigned int)*(unsigned __int8 *)(v20 + 24) - 13 < 2 )
          {
            if ( (*(_WORD *)(v5 + 552) & 0x10) != 0 )
            {
              v17 = (v19 & 0xC) == 0;
              if ( (*(_BYTE *)(v5 + 40) & 2) == 0 )
                goto LABEL_50;
LABEL_49:
              if ( (*v3 & 0xFC) != 0xC0 && *(unsigned __int16 *)(v1 + 180) != *(unsigned __int16 *)(a1[5] + 1940LL) )
                return 1;
LABEL_50:
              if ( !v17 && (*(_BYTE *)(v5 + 40) & 1) != 0 )
              {
                *(_QWORD *)(v1 + 72) = v5 + 536;
                return 0;
              }
              return 0;
            }
LABEL_43:
            v17 = 0;
            if ( (*(_BYTE *)(v5 + 40) & 2) == 0 )
              goto LABEL_50;
            goto LABEL_49;
          }
LABEL_61:
          a1[7] = 0;
          return 0;
        }
        if ( ((1 << v16) & 0x1C20) != 0 )
        {
          if ( (*v3 & 0xC) == 0 )
            goto LABEL_43;
          goto LABEL_61;
        }
        if ( ((1 << v16) & 0x13) != 0 )
        {
          if ( (*v3 & 0x4C) != 8 )
            goto LABEL_61;
          v17 = 0;
        }
      }
      if ( (*(_BYTE *)(v5 + 40) & 2) == 0 )
        goto LABEL_50;
      goto LABEL_49;
    }
LABEL_37:
    a1[7] = 0;
    return v2 && (*v3 & 0x4C) == 8 && (*(_QWORD *)(v2 + 216) & 0x4000000) != 0;
  }
  __break(0x5512u);
  return ieee80211_tx_h_rate_ctrl(a1);
}
