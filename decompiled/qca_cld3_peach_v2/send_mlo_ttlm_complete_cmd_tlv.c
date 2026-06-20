__int64 __fastcall send_mlo_ttlm_complete_cmd_tlv(__int64 a1, unsigned __int8 *a2)
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
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v33; // [xsp+0h] [xbp-20h]
  int v34; // [xsp+8h] [xbp-18h]
  int v35; // [xsp+10h] [xbp-10h]

  v4 = wmi_buf_alloc_fl(a1, 0x18u, "send_mlo_ttlm_complete_cmd_tlv", 0x81Du);
  if ( v4 )
  {
    v13 = *(_DWORD **)(v4 + 224);
    v14 = v4;
    *v13 = 84148244;
    v13[1] = *a2;
    v13[4] = *((_DWORD *)a2 + 2);
    v13[5] = *((_DWORD *)a2 + 3);
    v13[2] = *(_DWORD *)(a2 + 1);
    v13[3] = *(unsigned __int16 *)(a2 + 5);
    v33 = a2[2];
    v35 = a2[6];
    v34 = a2[3];
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: vdev %d status %d reassoc_if_failure %d ap mld %02x:%02x:%02x:**:**:%02x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_mlo_ttlm_complete_cmd_tlv",
      *a2,
      *((unsigned int *)a2 + 2),
      *((unsigned int *)a2 + 3),
      a2[1],
      v33,
      v34,
      v35);
    wmi_mtrace(0x4800Fu, v13[1], 0);
    v23 = wmi_unified_cmd_send_fl(
            a1,
            v14,
            0x18u,
            0x4800Fu,
            "send_mlo_ttlm_complete_cmd_tlv",
            0x839u,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22);
    if ( v23 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send WMI_MLO_LINK_TTLM_COMPLETE_CMDID to FW: %d vdev id %d",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "send_mlo_ttlm_complete_cmd_tlv",
        v23,
        (unsigned int)v13[1]);
      wmi_buf_free();
    }
  }
  else
  {
    v23 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi buf alloc failed for vdev id %d for TTLM complete cmd ",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "send_mlo_ttlm_complete_cmd_tlv",
      *a2);
  }
  return v23;
}
