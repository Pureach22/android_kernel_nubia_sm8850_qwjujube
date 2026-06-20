__int64 __fastcall hdd_close_adapter(
        __int64 *a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 i; // x26
  int v22; // w20
  char *v23; // x25

  ucfg_dp_bus_bw_compute_timer_stop(*a1, a4, a5, a6, a7, a8, a9, a10, a11);
  for ( i = 0; i != 68; ++i )
  {
    v22 = 50;
    while ( *(_DWORD *)(a2 + 52524 + 4 * i) )
    {
      v23 = net_dev_ref_debug_string_from_id_strings[i];
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: net_dev held for debug id %s",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "hdd_check_for_net_dev_ref_leak",
        v23);
      qdf_sleep();
      if ( !--v22 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: net_dev hold reference leak detected for debug id: %s",
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          "hdd_check_for_net_dev_ref_leak",
          v23);
        break;
      }
    }
  }
  if ( a1[1057] == a2 )
    a1[1057] = 0;
  hdd_remove_adapter(a1, a2);
  _hdd_close_adapter(a1, a2, a3 & 1);
  return ucfg_dp_bus_bw_compute_timer_try_start(*a1);
}
