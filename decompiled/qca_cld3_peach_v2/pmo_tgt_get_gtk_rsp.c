__int64 __fastcall pmo_tgt_get_gtk_rsp(
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
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 (__fastcall *v20)(_QWORD); // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7

  qdf_trace_msg(0x4Du, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "pmo_tgt_get_gtk_rsp");
  v18 = *(_QWORD *)(a1 + 216);
  if ( !v18 || (v19 = *(_QWORD *)(v18 + 80)) == 0 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to find psoc from from vdev:%pK",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "pmo_tgt_get_gtk_rsp",
      a1);
LABEL_9:
    v29 = 29;
    goto LABEL_10;
  }
  v20 = *(__int64 (__fastcall **)(_QWORD))(wlan_objmgr_psoc_get_comp_private_obj(v19, 4u) + 264);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: send_get_gtk_rsp_cmd is null",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "pmo_tgt_get_gtk_rsp");
    goto LABEL_9;
  }
  if ( *((_DWORD *)v20 - 1) != 1263140689 )
    __break(0x8228u);
  v29 = v20(a1);
  if ( v29 )
    qdf_trace_msg(
      0x4Du,
      2u,
      "%s: Failed to send_get_gtk_rsp_cmd  event",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "pmo_tgt_get_gtk_rsp");
LABEL_10:
  qdf_trace_msg(0x4Du, 8u, "%s: exit", v30, v31, v32, v33, v34, v35, v36, v37, "pmo_tgt_get_gtk_rsp");
  return v29;
}
