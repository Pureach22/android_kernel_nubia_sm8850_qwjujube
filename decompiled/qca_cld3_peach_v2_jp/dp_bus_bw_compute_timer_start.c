__int64 __fastcall dp_bus_bw_compute_timer_start(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x19
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7

  qdf_trace_msg(0x45u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "dp_bus_bw_compute_timer_start");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
  {
    v19 = comp_private_obj;
    if ( (unsigned int)cds_get_conparam() != 5 && (unsigned int)cds_get_conparam() != 8 )
    {
      qdf_periodic_work_start(v19 + 896, *(_DWORD *)(v19 + 88));
      __isb(0xFu);
      *(_QWORD *)(v19 + 888) = _ReadStatusReg(CNTVCT_EL0);
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Unable to get DP context",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "__dp_bus_bw_compute_timer_start");
  }
  return qdf_trace_msg(0x45u, 8u, "%s: exit", v20, v21, v22, v23, v24, v25, v26, v27, "dp_bus_bw_compute_timer_start");
}
