__int64 __fastcall dp_bus_bw_compute_timer_try_start(__int64 a1)
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
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  const char *v31; // x2
  unsigned int v32; // w1

  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  qdf_trace_msg(0x45u, 8u, "%s: enter", v3, v4, v5, v6, v7, v8, v9, v10, "dp_bus_bw_compute_timer_try_start");
  if ( comp_private_obj )
  {
    v19 = *(_QWORD *)(comp_private_obj + 376);
    v20 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 536);
    if ( *((_DWORD *)v20 - 1) != 859392181 )
      __break(0x8228u);
    if ( (v20(v19) & 1) != 0 )
    {
      v21 = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
      if ( v21 )
      {
        v30 = v21;
        if ( (unsigned int)cds_get_conparam() != 5 && (unsigned int)cds_get_conparam() != 8 )
        {
          qdf_periodic_work_start(v30 + 896, *(_DWORD *)(v30 + 88));
          __isb(0xFu);
          *(_QWORD *)(v30 + 888) = _ReadStatusReg(CNTVCT_EL0);
        }
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Unable to get DP context",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "__dp_bus_bw_compute_timer_start");
      }
    }
    v31 = "%s: exit";
    v32 = 8;
  }
  else
  {
    v31 = "%s: Unable to get DP context";
    v32 = 2;
  }
  return qdf_trace_msg(0x45u, v32, v31, v11, v12, v13, v14, v15, v16, v17, v18, "dp_bus_bw_compute_timer_try_start");
}
