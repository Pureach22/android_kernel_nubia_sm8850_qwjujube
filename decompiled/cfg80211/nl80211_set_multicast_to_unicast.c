__int64 __fastcall nl80211_set_multicast_to_unicast(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  int v3; // w9
  __int64 (__fastcall *v5)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 824LL) )
    return 4294967201LL;
  v3 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 992LL) + 8LL);
  if ( v3 != 9 && v3 != 3 )
    return 4294967201LL;
  v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 824LL);
  if ( *((_DWORD *)v5 - 1) != 666380368 )
    __break(0x8228u);
  return v5(v2 + 992);
}
