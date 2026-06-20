__int64 __fastcall wlan_delayed_peer_obj_free_deinit(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  if ( a1 )
  {
    cancel_work_sync(a1 + 1304);
    qdf_trace_msg(
      0x57u,
      8u,
      "%s: Deinit successfully, active_work_cnt=%u",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "wlan_delayed_peer_obj_free_deinit",
      *(unsigned int *)(a1 + 1352));
    return 0;
  }
  else
  {
    qdf_trace_msg(0x57u, 2u, "%s: pdev is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_delayed_peer_obj_free_deinit");
    return 16;
  }
}
