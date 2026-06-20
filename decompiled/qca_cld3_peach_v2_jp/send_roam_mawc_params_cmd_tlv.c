__int64 __fastcall send_roam_mawc_params_cmd_tlv(__int64 a1, unsigned __int8 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  _DWORD *v13; // x8
  __int64 v14; // x19
  int v15; // w9
  int v16; // w10
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x1Cu, "send_roam_mawc_params_cmd_tlv", 0x1A7u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 28246040;
    v13[1] = *a2;
    v13[2] = a2[1];
    v13[3] = *((_DWORD *)a2 + 1);
    v13[4] = *((_DWORD *)a2 + 2);
    v15 = a2[12];
    v13[5] = v15;
    v16 = a2[13];
    v13[6] = v16;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: MAWC roam en=%d, vdev=%d, tr=%d, ap=%d, high=%d, low=%d",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_roam_mawc_params_cmd_tlv",
      v15,
      v16);
    wmi_mtrace(0xB00Du, 0xFFu, 0);
    v25 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0x1Cu,
            0xB00Du,
            "send_roam_mawc_params_cmd_tlv",
            0x1C8u,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
    if ( v25 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_ROAM_CONFIGURE_MAWC_CMDID failed, Error %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "send_roam_mawc_params_cmd_tlv",
        v25);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v25;
}
