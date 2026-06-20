__int64 __fastcall nl80211_flush_pmksa(__int64 a1, __int64 a2)
{
  int v2; // w9
  __int64 v4; // x19
  __int64 (__fastcall *v5)(_QWORD); // x8

  v2 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 992LL) + 8LL);
  if ( v2 != 8 && v2 != 2 )
    return 4294967201LL;
  v4 = *(_QWORD *)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v4 + 496LL) )
    return 4294967201LL;
  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 496LL);
  if ( *((_DWORD *)v5 - 1) != 1283138139 )
    __break(0x8228u);
  return v5(v4 + 992);
}
