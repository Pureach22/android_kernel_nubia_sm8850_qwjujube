__int64 __fastcall cm_start_wait_for_key_timer(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 cmpt_obj; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x8
  __int64 v22; // x4
  __int64 v23; // x8
  __int64 v24; // x21
  unsigned int v25; // w20
  const char *v27; // x2

  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( cmpt_obj )
  {
    v21 = *(_QWORD *)(a1 + 216);
    v22 = *(unsigned __int8 *)(a1 + 168);
    if ( v21 && (v23 = *(_QWORD *)(v21 + 80)) != 0 )
    {
      v24 = cmpt_obj;
      v25 = *(unsigned __int8 *)(a1 + 168);
      if ( mlme_get_psoc_ext_obj_fl(v23) )
        return qdf_mc_timer_start(*(_QWORD *)(v24 + 536) + 24280LL, a2 / 0x3E8);
      v27 = "%s: psoc mlme obj is NULL for vdev id %d";
      v22 = v25;
    }
    else
    {
      v27 = "%s: psoc obj is NULL for vdev id %d";
    }
    qdf_trace_msg(0x68u, 2u, v27, v13, v14, v15, v16, v17, v18, v19, v20, "cm_start_wait_for_key_timer", v22);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev priv mlme obj is NULL",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "cm_start_wait_for_key_timer");
  }
  return 4;
}
