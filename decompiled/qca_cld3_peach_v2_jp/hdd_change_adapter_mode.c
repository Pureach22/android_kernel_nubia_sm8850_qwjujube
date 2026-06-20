__int64 __fastcall hdd_change_adapter_mode(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x20
  __int64 *v11; // x22
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v11 = *(__int64 **)(a1 + 24);
  v10 = *(_QWORD *)(a1 + 32);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_change_adapter_mode");
  if ( *(_DWORD *)(a1 + 40) != 7 || (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(*v11) & 1) == 0 )
  {
    hdd_stop_adapter(v11, a1);
    hdd_deinit_adapter(v11, a1, 1);
  }
  memset((void *)(*(_QWORD *)(a1 + 52824) + 80LL), 0, 0x8F8u);
  *(_DWORD *)(a1 + 40) = a2;
  hdd_set_station_ops(v10);
  qdf_trace_msg(0x33u, 8u, "%s: exit", v14, v15, v16, v17, v18, v19, v20, v21, "hdd_change_adapter_mode");
  return qdf_status_to_os_return(0);
}
