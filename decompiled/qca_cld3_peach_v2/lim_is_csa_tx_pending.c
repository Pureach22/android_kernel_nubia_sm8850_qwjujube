bool __fastcall lim_is_csa_tx_pending(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x20
  __int64 session_by_vdev_id; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x21
  int v30; // w19
  __int64 sap_ch_sw_info; // x0
  const char *v33; // x2
  unsigned int v34; // w0

  context = _cds_get_context(53, (__int64)"lim_is_csa_tx_pending", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v33 = "%s: Invalid mac context";
    v34 = 104;
LABEL_11:
    qdf_trace_msg(v34, 2u, v33, v11, v12, v13, v14, v15, v16, v17, v18, "lim_is_csa_tx_pending");
    return 0;
  }
  v19 = context;
  session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, a1, v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !session_by_vdev_id )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session does not exist for given vdev_id %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "lim_is_csa_tx_pending",
      a1);
    return 0;
  }
  v29 = session_by_vdev_id;
  v30 = *(_DWORD *)(v19[2703] + 20LL);
  sap_ch_sw_info = wlan_get_sap_ch_sw_info(*(_QWORD *)(session_by_vdev_id + 16), v21, v22, v23, v24, v25, v26, v27, v28);
  if ( !sap_ch_sw_info )
  {
    v33 = "%s: Invalid channel info";
    v34 = 53;
    goto LABEL_11;
  }
  return *(_BYTE *)(v29 + 7282)
      && *(unsigned __int8 *)(v29 + 7218) == *(unsigned __int8 *)(sap_ch_sw_info + 46)
      && (v30 & 0x2000000) != 0;
}
