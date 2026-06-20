bool __fastcall ieee80211_set_sdata_offload_flags(__int64 a1)
{
  __int64 v1; // x8
  int v2; // w19
  unsigned int v3; // w9
  unsigned int v4; // w20
  unsigned int v5; // w9

  v1 = *(_QWORD *)(a1 + 1616);
  v2 = *(_DWORD *)(a1 + 5876);
  if ( (*(_QWORD *)(v1 + 96) & 0x1000000000000LL) != 0 && (*(_DWORD *)(a1 + 4720) & 0xFFFFFFFE) == 2 )
  {
    v3 = v2 | 1;
    if ( (*(_QWORD *)(v1 + 96) & 0x4000000000LL) == 0 && *(_DWORD *)(*(_QWORD *)(v1 + 72) + 200LL) != -1 )
      v3 = v2 & 0xFFFFFFFE;
    if ( *(_DWORD *)(v1 + 1320) )
      v3 &= ~1u;
    if ( (*(_QWORD *)(v1 + 96) & 0x2000000000000LL) == 0 )
    {
LABEL_18:
      v4 = v3 & 0xFFFFFFFB;
      if ( v2 == (v3 & 0xFFFFFFFB) )
        return v2 != v4;
      goto LABEL_16;
    }
  }
  else
  {
    v3 = v2 & 0xFFFFFFFE;
    if ( (*(_QWORD *)(v1 + 96) & 0x2000000000000LL) == 0 )
      goto LABEL_18;
  }
  if ( (*(_DWORD *)(a1 + 4720) & 0xFFFFFFFE) != 2 )
    goto LABEL_18;
  v4 = v3 | 4;
  if ( *(_DWORD *)(v1 + 1320) )
  {
    v5 = v3 & 0xFFFFFFFB;
    if ( (*(_QWORD *)(v1 + 96) & 0x4000000000000LL) == 0 )
      v4 = v5;
  }
  if ( v2 != v4 )
  {
LABEL_16:
    *(_DWORD *)(a1 + 5876) = v4;
    ieee80211_check_fast_rx_iface(a1);
  }
  return v2 != v4;
}
