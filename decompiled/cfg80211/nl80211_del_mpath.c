__int64 __fastcall nl80211_del_mpath(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 (__fastcall *v3)(_QWORD); // x8

  v2 = *(_QWORD *)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 184LL) || *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 56) + 992LL) + 8LL) != 7 )
    return 4294967201LL;
  v3 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v2 + 184LL);
  if ( *((_DWORD *)v3 - 1) != 1857162459 )
    __break(0x8228u);
  return v3(v2 + 992);
}
