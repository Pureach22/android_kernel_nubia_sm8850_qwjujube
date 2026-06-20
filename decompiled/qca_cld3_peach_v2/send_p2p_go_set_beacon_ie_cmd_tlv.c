__int64 __fastcall send_p2p_go_set_beacon_ie_cmd_tlv(
        __int64 a1,
        int a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  unsigned int v12; // w21
  unsigned int v13; // w20
  int v16; // w24
  __int64 v18; // x0
  _DWORD *v19; // x25
  __int64 v20; // x19
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7

  v11 = a3[1];
  v12 = v11 + 2;
  if ( v11 < 0xFA )
  {
    v16 = ((_WORD)v11 + 5) & 0x1FC;
    v18 = wmi_buf_alloc_fl(a1, v16 + 16, "send_p2p_go_set_beacon_ie_cmd_tlv", 0x19E2u);
    if ( v18 )
    {
      v19 = *(_DWORD **)(v18 + 224);
      v20 = v18;
      *v19 = 5898248;
      v19[1] = a2;
      v19[2] = v12;
      v19[3] = v16 | 0x110000;
      qdf_mem_copy(v19 + 4, a3, v12);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Sending WMI_P2P_GO_SET_BEACON_IE",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "send_p2p_go_set_beacon_ie_cmd_tlv");
      qdf_mtrace(49, 100, 0x683u, v19[1], 0);
      v13 = wmi_unified_cmd_send_fl(
              a1,
              v20,
              v16 + 16,
              0xD003u,
              "send_p2p_go_set_beacon_ie_cmd_tlv",
              0x19FAu,
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36);
      if ( v13 )
      {
        qdf_trace_msg(
          0x31u,
          2u,
          "%s: Failed to send bcn tmpl: %d",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "send_p2p_go_set_beacon_ie_cmd_tlv",
          v13);
        wmi_buf_free();
      }
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: Successfully sent WMI_P2P_GO_SET_BEACON_IE",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "send_p2p_go_set_beacon_ie_cmd_tlv");
    }
    else
    {
      return 2;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid p2p ie length %u",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "send_p2p_go_set_beacon_ie_cmd_tlv",
      v12);
    return 4;
  }
  return v13;
}
