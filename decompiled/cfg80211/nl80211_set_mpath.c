__int64 __fastcall nl80211_set_mpath(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x19
  __int64 v6; // x1
  __int64 (__fastcall *v7)(__int64, __int64, __int64, __int64); // x10

  v2 = a2[4];
  v3 = *(_QWORD *)(v2 + 48);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v2 + 208);
  if ( !v4 )
    return 4294967274LL;
  v5 = a2[6];
  if ( !*(_QWORD *)(*(_QWORD *)v5 + 192LL) )
    return 4294967201LL;
  v6 = a2[7];
  if ( *(_DWORD *)(*(_QWORD *)(v6 + 992) + 8LL) != 7 )
    return 4294967201LL;
  v7 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v5 + 192LL);
  if ( *((_DWORD *)v7 - 1) != -2076196415 )
    __break(0x822Au);
  return v7(v5 + 992, v6, v3 + 4, v4 + 4);
}
