__int64 __fastcall lim_ll_sap_send_ecsa_action_frame(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x20
  __int64 session_by_vdev_id; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w21
  unsigned int v24; // w22
  unsigned int v25; // w23
  __int64 v26; // x24
  double v27; // d0
  unsigned int v28; // w0
  unsigned int v29; // w25
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w0

  context = _cds_get_context(53, (__int64)"lim_ll_sap_send_ecsa_action_frame", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( context )
  {
    v13 = context;
    session_by_vdev_id = pe_find_session_by_vdev_id(context, *(unsigned __int8 *)(a1 + 168));
    if ( session_by_vdev_id )
    {
      v23 = *(_DWORD *)(session_by_vdev_id + 7204);
      v24 = *(unsigned __int8 *)(session_by_vdev_id + 7224);
      v25 = *(unsigned __int8 *)(session_by_vdev_id + 7218);
      v26 = session_by_vdev_id;
      v27 = lim_op_class_from_bandwidth(
              v13,
              v23,
              *(unsigned __int8 *)(session_by_vdev_id + 7212),
              *(unsigned __int8 *)(session_by_vdev_id + 7211));
      v29 = v28;
      v37 = wlan_reg_freq_to_chan(v13[2704], v23, v27, v30, v31, v32, v33, v34, v35, v36);
      lim_send_extended_chan_switch_action_frame(v13, a2, v24, v29, v37, v25, v26);
      return 0;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Session not found for vdev_id: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "lim_ll_sap_send_ecsa_action_frame",
      *(unsigned __int8 *)(a1 + 168));
  }
  return 16;
}
