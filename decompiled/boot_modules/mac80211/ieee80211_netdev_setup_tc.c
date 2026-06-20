__int64 __fastcall ieee80211_netdev_setup_tc(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x2
  _DWORD *v6; // x9
  __int64 v7; // x0

  if ( *(_DWORD *)(a1 + 7408) == 4 )
    v5 = *(_QWORD *)(a1 + 4720) - 2264LL;
  else
    v5 = a1 + 2688;
  v6 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 4304) + 464LL) + 952LL);
  if ( !v6 )
    return 4294967201LL;
  v7 = *(_QWORD *)(a1 + 4304);
  if ( *(v6 - 1) != 1497897745 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, __int64))v6)(v7, v5 + 4720, a1, a2, a3);
}
