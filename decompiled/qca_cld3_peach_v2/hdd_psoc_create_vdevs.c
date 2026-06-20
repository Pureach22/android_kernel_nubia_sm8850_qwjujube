__int64 __fastcall hdd_psoc_create_vdevs(
        __int64 *a1,
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
  __int64 (__fastcall *v11)(); // x8
  __int64 v12; // x0
  unsigned int v13; // w21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7

  v9 = (unsigned int)curr_con_mode;
  if ( (unsigned int)curr_con_mode > 0xA || ((0x6CEuLL >> curr_con_mode) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Driver mode %d not supported",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "hdd_open_adapters_for_mode",
      (unsigned int)curr_con_mode);
    v13 = -524;
LABEL_12:
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to create vdevs; status:%d",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "hdd_psoc_create_vdevs",
      v13);
    return v13;
  }
  rtnl_lock();
  v11 = hdd_open_mode_handlers[v9];
  if ( *((_DWORD *)v11 - 1) != 237692882 )
    __break(0x8228u);
  v12 = ((__int64 (__fastcall *)(__int64 *))v11)(a1);
  v13 = v12;
  rtnl_unlock(v12);
  if ( v13 )
    goto LABEL_12;
  ucfg_dp_try_set_rps_cpu_mask(*a1);
  if ( (_DWORD)v9 != 5 && (_DWORD)v9 != 8 )
  {
    if ( (*(_BYTE *)(a1[13] + 28) & 1) == 0 )
      hdd_psoc_idle_timer_start((__int64)a1, v22, v23, v24, v25, v26, v27, v28, v29);
    return 0;
  }
  return v13;
}
