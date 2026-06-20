__int64 __fastcall ieee80211_rx_h_action_return(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v5; // x0
  __int64 v6; // x10
  char v7; // w9
  __int16 v8; // w11
  __int64 v9; // x9
  int v10; // w11

  v1 = a1[1];
  v2 = *(_QWORD *)(v1 + 224);
  if ( (*(_WORD *)v2 & 0xFC) != 0xD0 )
    return 1;
  v3 = a1[2];
  if ( (*(_BYTE *)(v1 + 75) & 0x10) == 0 && (unsigned int)(*(_DWORD *)(a1[3] + 4720LL) - 3) < 2
    || (*(_BYTE *)(v2 + 4) & 1) != 0 )
  {
    return 0x20000;
  }
  if ( *(char *)(v2 + 24) < 0 )
    return 65561;
  v5 = skb_copy_expand(a1[1], *(unsigned int *)(v3 + 104), 0, 2080);
  if ( v5 )
  {
    v6 = *(_QWORD *)(v5 + 224);
    v7 = *(_BYTE *)(v6 + 24);
    v8 = *(_WORD *)(v6 + 14);
    *(_DWORD *)(v6 + 4) = *(_DWORD *)(v6 + 10);
    *(_WORD *)(v6 + 8) = v8;
    *(_BYTE *)(v6 + 24) = v7 | 0x80;
    v9 = a1[3];
    v10 = *(_DWORD *)(v9 + 5842);
    *(_WORD *)(v6 + 14) = *(_WORD *)(v9 + 5846);
    *(_DWORD *)(v6 + 10) = v10;
    *(_QWORD *)(v5 + 40) = 0;
    *(_QWORD *)(v5 + 72) = 0;
    *(_QWORD *)(v5 + 80) = 0;
    *(_QWORD *)(v5 + 56) = 0;
    *(_QWORD *)(v5 + 64) = 0;
    *(_QWORD *)(v5 + 48) = 0;
    if ( *(_DWORD *)(a1[3] + 4720LL) == 10 )
    {
      *(_DWORD *)(v5 + 40) = 167780352;
      if ( (*(_QWORD *)(v3 + 96) & 0x40000) != 0 )
        *(_DWORD *)(v5 + 44) = (*(_BYTE *)(v3 + 141) & 0xF) << 17;
    }
    _ieee80211_tx_skb_tid_band(a1[3], v5, 7, 0xFFFFFFFFLL, *(unsigned __int8 *)(v1 + 76));
  }
  return 65582;
}
