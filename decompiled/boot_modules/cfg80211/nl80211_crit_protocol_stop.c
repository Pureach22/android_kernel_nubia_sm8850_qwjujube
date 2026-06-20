__int64 __fastcall nl80211_crit_protocol_stop(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x19
  __int64 v3; // x1
  _DWORD *v4; // x8

  v2 = *(_DWORD **)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 712LL) )
    return 4294967201LL;
  if ( v2[162] )
  {
    v3 = *(_QWORD *)(a2 + 56);
    v2[162] = 0;
    v4 = *(_DWORD **)(*(_QWORD *)v2 + 712LL);
    if ( *(v4 - 1) != 1366774891 )
      __break(0x8228u);
    ((void (__fastcall *)(_DWORD *, __int64))v4)(v2 + 248, v3);
  }
  return 0;
}
