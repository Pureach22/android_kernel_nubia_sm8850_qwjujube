__int64 __fastcall mlo_dev_mlpeer_list_deinit(
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
  __int64 v9; // x8
  __int64 i; // x22

  v9 = *(_QWORD *)(a1 + 2232);
  if ( v9 )
  {
    if ( *(_BYTE *)(v9 + 120) == 1 )
    {
      *(_BYTE *)(v9 + 121) = 1;
      wlan_mlo_ap_delete_assoc_list_entries(*(_QWORD *)(a1 + 2232) + 96LL, a2, a3, a4, a5, a6, a7, a8, a9);
      v9 = *(_QWORD *)(a1 + 2232);
    }
    timer_delete_sync(v9 + 128);
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 2232) + 112LL) )
      qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", a2, a3, a4, a5, a6, a7, a8, a9, "qdf_list_destroy");
  }
  for ( i = 64; i != 1600; i += 24 )
  {
    if ( *(_DWORD *)(a1 + i) )
      qdf_trace_msg(0x33u, 2u, "%s: list length not equal to zero", a2, a3, a4, a5, a6, a7, a8, a9, "qdf_list_destroy");
  }
  qdf_mutex_destroy(a1 + 1584);
  return 0;
}
