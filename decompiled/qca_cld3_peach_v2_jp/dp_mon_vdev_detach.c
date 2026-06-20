__int64 __fastcall dp_mon_vdev_detach(
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
  __int64 v11; // x9
  __int64 v12; // x21
  __int64 v13; // x20
  __int64 v17; // x8
  void (__fastcall *v18)(__int64, __int64); // x8

  v9 = *(_QWORD *)(a1 + 24);
  v10 = *(_QWORD *)(v9 + 8);
  if ( !v10 )
    return 16;
  v11 = *(_QWORD *)(v10 + 20056);
  if ( !v11 )
    return 16;
  v12 = *(_QWORD *)(v11 + 416);
  v13 = *(_QWORD *)(a1 + 42696);
  if ( !v12 || v13 == 0 )
    return 16;
  wlan_minidump_remove(a2, a3, a4, a5, a6, a7, a8, a9, *(_QWORD *)(a1 + 42696), 24, *(_QWORD *)(v10 + 16));
  _qdf_mem_free(v13);
  *(_QWORD *)(a1 + 42696) = 0;
  *(_BYTE *)(*(_QWORD *)(v9 + 95560) + 39318LL) = 0;
  v17 = *(_QWORD *)(v9 + 95560);
  if ( *(_QWORD *)(v17 + 16) == a1 )
  {
    *(_QWORD *)(v17 + 16) = 0;
    *(_BYTE *)(v17 + 9) = -1;
    v17 = *(_QWORD *)(v9 + 95560);
  }
  if ( *(_QWORD *)(v17 + 18544) == a1 )
  {
    *(_QWORD *)(v17 + 18544) = 0;
    *(_BYTE *)(v17 + 18537) = -1;
  }
  v18 = *(void (__fastcall **)(__int64, __int64))(v12 + 976);
  if ( v18 )
  {
    if ( *((_DWORD *)v18 - 1) != 1765709534 )
      __break(0x8228u);
    v18(v9, a1);
  }
  return 0;
}
