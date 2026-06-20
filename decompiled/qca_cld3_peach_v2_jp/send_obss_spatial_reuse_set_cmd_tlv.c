__int64 __fastcall send_obss_spatial_reuse_set_cmd_tlv(__int64 a1, _DWORD *a2)
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
  unsigned int v14; // w20
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7

  v4 = wmi_buf_alloc_fl(a1, 0x14u, "send_obss_spatial_reuse_set_cmd_tlv", 0x3314u);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    *v13 = 49217552;
    v13[1] = *a2;
    v13[2] = a2[1];
    v13[3] = a2[2];
    v13[4] = a2[3];
    v14 = wmi_unified_cmd_send_fl(
            a1,
            v4,
            0x14u,
            0x40001u,
            "send_obss_spatial_reuse_set_cmd_tlv",
            0x3324u,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10,
            v11,
            v12);
    if ( v14 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: WMI_PDEV_OBSS_PD_SPATIAL_REUSE_CMDID send returned Error %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "send_obss_spatial_reuse_set_cmd_tlv",
        v14);
      wmi_buf_free();
    }
  }
  else
  {
    return 16;
  }
  return v14;
}
