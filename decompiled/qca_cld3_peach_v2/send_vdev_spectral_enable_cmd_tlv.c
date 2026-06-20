__int64 __fastcall send_vdev_spectral_enable_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  _DWORD *v13; // x22
  __int64 v14; // x19
  int v15; // w5
  unsigned int v16; // w20
  int v17; // w6
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_vdev_spectral_enable_cmd_tlv", 0x24D4u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 9306128;
    v13[1] = *a2;
    if ( a2[1] )
    {
      if ( a2[2] )
        v15 = 1;
      else
        v15 = 2;
    }
    else
    {
      v15 = 0;
    }
    v13[2] = v15;
    if ( a2[3] )
    {
      if ( a2[4] )
        v17 = 1;
      else
        v17 = 2;
    }
    else
    {
      v17 = 0;
    }
    v13[3] = v17;
    v13[4] = a2[5];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev_id = %u trigger_cmd = %u enable_cmd = %u",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_vdev_spectral_enable_cmd_tlv");
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: spectral_scan_mode = %u",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_vdev_spectral_enable_cmd_tlv",
      (unsigned int)v13[4]);
    qdf_mtrace(49, 100, 0xA82u, v13[1], 0);
    v16 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0x14u,
            0x15002u,
            "send_vdev_spectral_enable_cmd_tlv",
            0x24F5u,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33);
    if ( v16 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Sending scan enable CMD failed",
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        "send_vdev_spectral_enable_cmd_tlv");
      wmi_buf_free();
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sent WMI_VDEV_SPECTRAL_SCAN_ENABLE_CMDID, Status: %d",
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      "send_vdev_spectral_enable_cmd_tlv",
      v16);
  }
  else
  {
    return 16;
  }
  return v16;
}
