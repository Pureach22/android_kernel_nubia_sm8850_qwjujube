__int64 __fastcall nl80211_del_tx_ts(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x8
  __int64 v5; // x1
  __int64 v6; // x19
  __int64 v7; // x2
  __int64 (__fastcall *v8)(__int64, __int64, __int64, __int64); // x9

  v2 = a2[4];
  v3 = *(_QWORD *)(v2 + 1680);
  if ( !v3 )
    return 4294967274LL;
  v4 = *(_QWORD *)(v2 + 48);
  if ( !v4 )
    return 4294967274LL;
  v6 = a2[6];
  v5 = a2[7];
  v7 = *(unsigned __int8 *)(v3 + 4);
  v8 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(*(_QWORD *)v6 + 760LL);
  if ( !v8 )
    return 4294967201LL;
  if ( *((_DWORD *)v8 - 1) != -180201227 )
    __break(0x8229u);
  return v8(v6 + 992, v5, v7, v4 + 4);
}
