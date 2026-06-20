__int64 __fastcall pmo_tgt_set_apf_mode_req(
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
  const char *v24; // x2

  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: vdev_id: %d: APF mode:  %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "pmo_tgt_set_apf_mode_req",
    a3,
    a2);
  v14 = *(_DWORD **)(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 480);
  if ( !v14 )
  {
    v23 = 29;
    v24 = "%s: send_apf_mode_req is null";
    goto LABEL_7;
  }
  if ( *(v14 - 1) != -93775912 )
    __break(0x8228u);
  v23 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))v14)(a1, a2, a3);
  if ( v23 )
  {
    v24 = "%s: Failed to send APF mode";
LABEL_7:
    qdf_trace_msg(0x4Du, 2u, v24, v15, v16, v17, v18, v19, v20, v21, v22, "pmo_tgt_set_apf_mode_req");
  }
  return v23;
}
