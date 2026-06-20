__int64 __fastcall dp_mon_peer_detach(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x8
  __int64 v12; // x0
  __int64 v13; // x8

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    v10 = *(_QWORD *)(a1 + 24);
    v12 = *(_QWORD *)(a1 + 8);
    v13 = *(_QWORD *)(v10 + 24);
    *(_QWORD *)(v9 + 8) = 0;
    wlan_minidump_remove(a2, a3, a4, a5, a6, a7, a8, a9, v12, 16, *(_QWORD *)(*(_QWORD *)(v13 + 8) + 16LL));
    _qdf_mem_free(v9);
    *(_QWORD *)(a1 + 8) = 0;
  }
  return 0;
}
