__int64 __fastcall ieee80211_ifa6_changed(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 *v3; // x2
  __int64 v4; // x8
  _QWORD *v5; // x9
  void (__fastcall *v6)(__int64, __int64); // x9
  __int64 v7; // x0

  v3 = *(__int64 **)(a3 + 184);
  v4 = *v3;
  v5 = *(_QWORD **)(*v3 + 992);
  if ( !v5 || *v5 != *(_QWORD *)(a1 - 5056) || *(_DWORD *)(v4 + 7408) != 2 )
    return 0;
  v6 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 - 4664) + 648LL);
  if ( v6 )
  {
    v7 = a1 - 5128;
    if ( *((_DWORD *)v6 - 1) != 128662365 )
      __break(0x8229u);
    v6(v7, v4 + 7408);
  }
  return 1;
}
