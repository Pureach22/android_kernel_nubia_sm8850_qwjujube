__int64 __fastcall ieee80211_rx_h_mgmt(__int64 a1)
{
  __int64 v1; // x19
  unsigned int v2; // w9
  bool v3; // zf
  __int64 v4; // x1
  __int64 v5; // x10
  unsigned int v6; // w11
  unsigned int v7; // w8
  bool v8; // zf
  unsigned int v9; // w11
  unsigned int v10; // w8
  int v11; // w8
  __int64 v12; // x20
  char v13; // w9
  char v14; // w8

  v1 = *(_QWORD *)(a1 + 24);
  v2 = *(_DWORD *)(v1 + 4720);
  v3 = v2 > 0xB || ((1 << v2) & 0x806) == 0;
  if ( v3 )
    return 0x20000;
  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(_QWORD *)(v4 + 224);
  v6 = ((*(_WORD *)v5 & 0xF0u) - 16) >> 4;
  v7 = 0x20000;
  if ( v6 > 6 )
  {
    if ( ((*(_WORD *)v5 & 0xF0u) - 16) >> 4 <= 9 )
    {
      if ( v6 != 7 )
      {
        if ( v6 != 9 )
          return v7;
LABEL_15:
        v9 = *(_DWORD *)(v5 + 4);
        if ( (v9 & 1) != 0 )
        {
          if ( v2 != 2 || (*(unsigned __int16 *)(v5 + 8) & v9 & HIWORD(v9)) != 0xFFFF )
            return v7;
        }
        else if ( v2 != 2 )
        {
          return v7;
        }
      }
LABEL_35:
      v11 = *(_DWORD *)(a1 + 76);
      v12 = *(_QWORD *)(a1 + 40);
      v13 = *(_BYTE *)(v4 + 86);
      *(_WORD *)(v4 + 180) = 0;
      if ( v11 < 0 )
        v14 = v13 & 0xFE;
      else
        v14 = v13 & 0xE0 | (2 * (v11 & 0xF)) | 1;
      *(_BYTE *)(v4 + 86) = v14;
      skb_queue_tail(v1 + 1984);
      wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v1 + 1616) + 72LL), v1 + 1960);
      v7 = 0;
      if ( v12 )
        ++*(_QWORD *)(v12 + 1752);
      return v7;
    }
    if ( v6 == 10 )
      goto LABEL_35;
    if ( v6 != 11 )
      return v7;
    v10 = *(_DWORD *)(v5 + 4);
    if ( (v10 & 1) != 0 )
    {
      v3 = (*(unsigned __int16 *)(v5 + 8) & v10 & HIWORD(v10)) == 0xFFFF;
      v7 = 0x20000;
      if ( !v3 || v2 - 1 >= 2 )
        return v7;
      goto LABEL_35;
    }
    if ( v2 - 1 < 2 )
      goto LABEL_35;
    return 0x20000;
  }
  if ( ((*(_WORD *)v5 & 0xF0u) - 16) >> 4 > 2 )
  {
    if ( v6 == 3 )
    {
      if ( v2 != 7 && v2 != 1 )
        return v7;
    }
    else if ( v6 != 4 )
    {
      return v7;
    }
    goto LABEL_35;
  }
  if ( v6 )
    v8 = v6 == 2;
  else
    v8 = 1;
  if ( v8 )
    goto LABEL_15;
  return v7;
}
