__int64 __fastcall nl80211_abort_scan(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x1
  _DWORD *v4; // x8

  v2 = *(_QWORD **)(a2 + 48);
  if ( !*(_QWORD *)(*v2 + 328LL) )
    return 4294967201LL;
  if ( v2[30] )
    return 0;
  if ( v2[28] )
  {
    v3 = *(_QWORD *)(a2 + 56);
    v4 = *(_DWORD **)(*v2 + 328LL);
    if ( *(v4 - 1) != 1366774891 )
      __break(0x8228u);
    ((void (__fastcall *)(_QWORD *, __int64))v4)(v2 + 124, v3);
    return 0;
  }
  return 4294967294LL;
}
