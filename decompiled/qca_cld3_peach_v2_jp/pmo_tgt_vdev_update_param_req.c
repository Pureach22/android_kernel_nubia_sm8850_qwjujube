__int64 __fastcall pmo_tgt_vdev_update_param_req(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _DWORD *v14; // x8
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "pmo_tgt_vdev_update_param_req");
  v14 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 80LL), 4u) + 320);
  if ( v14 )
  {
    if ( *(v14 - 1) != -1990808338 )
      __break(0x8228u);
    v23 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v14)(a1, a2, a3);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_vdev_param_update_req is null",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "pmo_tgt_vdev_update_param_req");
    v23 = 29;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v24, v25, v26, v27, v28, v29, v30, v31, "pmo_tgt_vdev_update_param_req");
  return v23;
}
