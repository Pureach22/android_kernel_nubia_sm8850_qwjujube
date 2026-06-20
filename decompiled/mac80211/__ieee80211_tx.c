__int64 __fastcall _ieee80211_tx(__int64 a1, _QWORD *a2, __int64 a3, char a4)
{
  _QWORD *v4; // x8
  _DWORD *v6; // x1
  __int64 v7; // x9
  __int64 v8; // x8
  char v9; // w0
  unsigned __int64 v11; // x10

  v4 = (_QWORD *)*a2;
  if ( (_QWORD *)*a2 == a2 )
  {
    __break(0x800u);
    v9 = 1;
    return v9 & 1;
  }
  v6 = (_DWORD *)v4[8];
  if ( a3 && !*(_BYTE *)(a3 + 204) )
    a3 = 0;
  if ( *v6 == 4 )
  {
    v8 = *((_QWORD *)v6 - 336) - 2264LL;
LABEL_14:
    v6 = (_DWORD *)(v8 + 4720);
    goto LABEL_15;
  }
  if ( *v6 != 6 )
  {
    v8 = (__int64)(v6 - 1180);
    goto LABEL_14;
  }
  if ( (*(_BYTE *)(v6 - 614) & 0x40) != 0 )
    goto LABEL_15;
  v7 = *(_QWORD *)(a1 + 5384);
  if ( !v7 || (*(_QWORD *)(a1 + 96) & 0x1000) == 0 )
  {
    if ( (*(_QWORD *)(a1 + 96) & 0x40000) == 0 )
    {
      v6 = nullptr;
      goto LABEL_15;
    }
    ieee80211_purge_tx_queue(a1, (__int64)a2);
    v9 = 1;
    return v9 & 1;
  }
  v11 = *((unsigned __int16 *)v4 + 62);
  if ( v11 < 4 )
  {
    v6 = (_DWORD *)(v7 + 4720);
    *((_DWORD *)v4 + 11) = *((_DWORD *)v4 + 11) & 0xFFE1FFFF | ((*(_BYTE *)(v7 + v11 + 5850) & 0xF) << 17);
LABEL_15:
    v9 = ieee80211_tx_frags(a1, (__int64)v6, a3, (__int64)a2, a4 & 1);
    if ( (_QWORD *)*a2 != a2 )
      __break(0x800u);
    return v9 & 1;
  }
  __break(0x5512u);
  return ieee80211_amsdu_prepare_head(a1, v6, a3);
}
