__int64 __fastcall nl80211_set_noack_map(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x19
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 (__fastcall *v6)(__int64, __int64, __int64); // x8

  v2 = *(_QWORD *)(a2[4] + 1192LL);
  if ( !v2 )
    return 4294967274LL;
  v3 = a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v3 + 640LL) )
    return 4294967201LL;
  v4 = a2[7];
  v5 = *(unsigned __int16 *)(v2 + 4);
  v6 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)v3 + 640LL);
  if ( *((_DWORD *)v6 - 1) != 953464600 )
    __break(0x8228u);
  return v6(v3 + 992, v4, v5);
}
