__int64 __fastcall dp_bus_bw_compute_timer_try_stop(__int64 a1)
{
  __int64 comp_private_obj; // x20
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  const char *v21; // x2
  unsigned int v22; // w1

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  qdf_trace_msg(0x45u, 8u, "%s: enter", v3, v4, v5, v6, v7, v8, v9, v10, "dp_bus_bw_compute_timer_try_stop");
  if ( comp_private_obj )
  {
    v19 = *(_QWORD *)(comp_private_obj + 376);
    v20 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 536);
    if ( *((_DWORD *)v20 - 1) != 859392181 )
      __break(0x8228u);
    if ( (v20(v19) & 1) == 0 )
      _dp_bus_bw_compute_timer_stop(a1);
    v21 = "%s: exit";
    v22 = 8;
  }
  else
  {
    v21 = "%s: Unable to get DP context";
    v22 = 2;
  }
  return qdf_trace_msg(0x45u, v22, v21, v11, v12, v13, v14, v15, v16, v17, v18, "dp_bus_bw_compute_timer_try_stop");
}
