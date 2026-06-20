__int64 __fastcall pmo_tgt_conf_hw_filter(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  const char *v20; // x4
  __int64 (__fastcall *v21)(__int64, unsigned __int8 *); // x8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w19
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "pmo_tgt_conf_hw_filter");
  if ( a2[1] )
    v20 = "Enable";
  else
    v20 = "Disable";
  qdf_trace_msg(
    0x4Du,
    8u,
    "%s: Send %s hw filter mode 0x%X for vdev_id %u",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "pmo_tgt_conf_hw_filter",
    v20,
    *((unsigned int *)a2 + 1),
    *a2);
  v21 = *(__int64 (__fastcall **)(__int64, unsigned __int8 *))(wlan_objmgr_psoc_get_comp_private_obj(a1, 4u) + 136);
  if ( v21 )
  {
    if ( *((_DWORD *)v21 - 1) != -1119811526 )
      __break(0x8228u);
    v30 = v21(a1, a2);
  }
  else
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_conf_hw_filter_req is null",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "pmo_tgt_conf_hw_filter");
    v30 = 29;
  }
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v31, v32, v33, v34, v35, v36, v37, v38, "pmo_tgt_conf_hw_filter");
  return v30;
}
