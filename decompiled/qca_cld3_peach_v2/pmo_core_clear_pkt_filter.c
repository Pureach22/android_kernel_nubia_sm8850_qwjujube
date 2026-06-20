__int64 __fastcall pmo_core_clear_pkt_filter(
        __int64 a1,
        __int64 a2,
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
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  __int64 v23; // x21
  double v24; // d0
  unsigned int v25; // w0
  unsigned int v26; // w19
  unsigned int *v27; // x8
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "pmo_core_clear_pkt_filter");
  if ( !a1 )
  {
    v43 = "%s: psoc is null";
LABEL_6:
    qdf_trace_msg(0x4Du, 2u, v43, v14, v15, v16, v17, v18, v19, v20, v21, "pmo_core_clear_pkt_filter");
    v26 = 29;
    goto LABEL_7;
  }
  v22 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a3, 10);
  if ( !v22 )
  {
    v43 = "%s: vdev is NULL";
    goto LABEL_6;
  }
  v23 = v22;
  v24 = pmo_tgt_clear_pkt_filter(v22, a2, a3);
  v26 = v25;
  wlan_objmgr_vdev_release_ref(v23, 0xAu, v27, v24, v28, v29, v30, v31, v32, v33, v34);
LABEL_7:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v35, v36, v37, v38, v39, v40, v41, v42, "pmo_core_clear_pkt_filter");
  return v26;
}
