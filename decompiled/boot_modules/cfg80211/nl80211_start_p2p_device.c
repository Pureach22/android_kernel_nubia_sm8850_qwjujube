__int64 __fastcall nl80211_start_p2p_device(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 result; // x0
  __int64 (__fastcall *v6)(__int64, __int64); // x8

  v2 = *(_DWORD **)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 656LL) )
    return 4294967201LL;
  v3 = *(_QWORD *)(a2 + 56);
  if ( *(_DWORD *)(v3 + 8) != 10 )
    return 4294967201LL;
  v4 = *(_QWORD *)(v3 + 32);
  if ( v4 )
  {
    if ( (*(_QWORD *)(v4 + 168) & 1) == 0 )
      goto LABEL_5;
    return 0;
  }
  if ( (*(_BYTE *)(v3 + 66) & 1) != 0 )
    return 0;
LABEL_5:
  if ( (rfkill_blocked(*((_QWORD *)v2 + 309)) & 1) != 0 )
    return 4294967164LL;
  v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)v2 + 656LL);
  if ( *((_DWORD *)v6 - 1) != -520763295 )
    __break(0x8228u);
  result = v6((__int64)(v2 + 248), v3);
  if ( !(_DWORD)result )
  {
    *(_BYTE *)(v3 + 66) = 1;
    ++v2[28];
  }
  return result;
}
