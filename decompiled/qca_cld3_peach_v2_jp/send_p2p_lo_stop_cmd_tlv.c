__int64 __fastcall send_p2p_lo_stop_cmd_tlv(
        __int64 a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v10; // w21
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x22
  __int64 v22; // x19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w20
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7

  v10 = a2;
  qdf_trace_msg(0x31u, 8u, "%s: vdev_id: %d", a3, a4, a5, a6, a7, a8, a9, a10, "send_p2p_lo_stop_cmd_tlv", a2);
  v12 = wmi_buf_alloc_fl(a1, 8u, "send_p2p_lo_stop_cmd_tlv", 0x1BAu);
  if ( v12 )
  {
    v21 = *(_DWORD **)(v12 + 224);
    v22 = v12;
    *v21 = 35848196;
    v21[1] = v10;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sending WMI_P2P_LO_STOP command",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "send_p2p_lo_stop_cmd_tlv");
    v23 = wmi_mtrace(53259, (unsigned int)v21[1], 0);
    v31 = wmi_unified_cmd_send_fl(
            a1,
            v22,
            8u,
            0xD00Bu,
            "send_p2p_lo_stop_cmd_tlv",
            0x1CBu,
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30);
    if ( v31 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send p2p lo stop: %d",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "send_p2p_lo_stop_cmd_tlv",
        v31);
      wmi_buf_free();
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Successfully sent WMI_P2P_LO_STOP",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "send_p2p_lo_stop_cmd_tlv");
    }
  }
  else
  {
    return 2;
  }
  return v31;
}
