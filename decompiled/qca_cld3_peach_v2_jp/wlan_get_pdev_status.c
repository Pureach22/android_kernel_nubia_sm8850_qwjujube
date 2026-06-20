__int64 __fastcall wlan_get_pdev_status(
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
  _QWORD *pdev_obj; // x20
  bool v10; // w19
  bool v11; // w0
  unsigned int is_cmd_in_active_pending; // w19
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7

  if ( a1 )
  {
    pdev_obj = (_QWORD *)wlan_serialization_get_pdev_obj(a1);
    wlan_serialization_acquire_lock(pdev_obj + 11);
    v10 = qdf_list_empty(pdev_obj);
    v11 = qdf_list_empty(pdev_obj + 3);
    is_cmd_in_active_pending = wlan_serialization_is_cmd_in_active_pending(!v10, !v11);
    wlan_serialization_release_lock(pdev_obj + 11);
    if ( is_cmd_in_active_pending < 5 && ((0x17u >> is_cmd_in_active_pending) & 1) != 0 )
      return dword_A30348[is_cmd_in_active_pending];
    qdf_trace_msg(
      0x15u,
      3u,
      "%s: invalid serialization status %d",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_get_scan_status_from_serialization_status",
      is_cmd_in_active_pending);
  }
  else
  {
    qdf_trace_msg(0x4Cu, 2u, "%s: null pdev", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_get_pdev_status");
  }
  return 0;
}
