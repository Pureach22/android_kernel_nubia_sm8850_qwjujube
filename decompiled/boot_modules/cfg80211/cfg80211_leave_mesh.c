__int64 __fastcall cfg80211_leave_mesh(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v5; // x8
  __int64 *v6; // x0
  __int64 (__fastcall *v7)(_QWORD); // x8
  __int64 result; // x0
  __int64 *v9; // x0
  _DWORD *v10; // x8

  v2 = *(_QWORD *)(a2 + 992);
  if ( *(_DWORD *)(v2 + 8) != 7 || !*(_QWORD *)(*a1 + 256) )
    return 4294967201LL;
  if ( !*(_BYTE *)(v2 + 384) )
    return 4294967189LL;
  v5 = *a1;
  v6 = a1 + 124;
  v7 = *(__int64 (__fastcall **)(_QWORD))(v5 + 256);
  if ( *((_DWORD *)v7 - 1) != 1283138139 )
    __break(0x8228u);
  result = v7(v6);
  if ( !(_DWORD)result )
  {
    *(_DWORD *)(v2 + 100) = 0;
    v9 = a1;
    *(_BYTE *)(v2 + 384) = 0;
    *(_DWORD *)(v2 + 280) = 0;
    *(_QWORD *)(v2 + 320) = 0;
    *(_QWORD *)(v2 + 328) = 0;
    *(_QWORD *)(v2 + 336) = 0;
    *(_QWORD *)(v2 + 344) = 0;
    if ( *(_QWORD *)(*a1 + 736) )
    {
      v10 = *(_DWORD **)(*a1 + 736);
      if ( *(v10 - 1) != -824243271 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64 *, __int64, _QWORD))v10)(a1 + 124, a2, 0);
      v9 = a1;
    }
    cfg80211_sched_dfs_chan_update(v9);
    return 0;
  }
  return result;
}
