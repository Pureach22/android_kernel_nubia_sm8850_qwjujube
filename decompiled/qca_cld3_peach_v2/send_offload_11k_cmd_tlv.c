__int64 __fastcall send_offload_11k_cmd_tlv(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x24
  __int64 v15; // x19
  int v16; // w5
  size_t v17; // x2
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
  unsigned int v34; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( (*(_DWORD *)(a2 + 4) & 1) != 0 )
    v4 = 80;
  else
    v4 = 12;
  v5 = wmi_buf_alloc_fl(a1, v4, "send_offload_11k_cmd_tlv", 0x1943u);
  if ( v5 )
  {
    v14 = *(_QWORD *)(v5 + 224);
    v15 = v5;
    *(_DWORD *)v14 = 46596104;
    *(_DWORD *)(v14 + 4) = *(_DWORD *)a2;
    v16 = *(_DWORD *)(a2 + 4);
    *(_DWORD *)(v14 + 8) = v16;
    if ( (v16 & 1) != 0 )
    {
      *(_QWORD *)(v14 + 12) = 0x2C9003C00120040LL;
      *(_DWORD *)(v14 + 20) = *(_DWORD *)(a2 + 8);
      *(_DWORD *)(v14 + 24) = *(_DWORD *)(a2 + 12);
      *(_DWORD *)(v14 + 28) = *(_DWORD *)(a2 + 16);
      *(_DWORD *)(v14 + 32) = *(_DWORD *)(a2 + 20);
      *(_DWORD *)(v14 + 36) = *(_DWORD *)(a2 + 24);
      *(_DWORD *)(v14 + 40) = *(_DWORD *)(a2 + 28);
      v17 = *(unsigned __int8 *)(a2 + 32);
      *(_DWORD *)(v14 + 44) = v17;
      qdf_mem_copy((void *)(v14 + 48), (const void *)(a2 + 33), v17);
    }
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: vdev %d 11k_bitmask:%u time_offset:%u low_rssi_offset:%u bmiss_count_trigger:%u per_threshold_offset%u",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "send_offload_11k_cmd_tlv",
      *(_DWORD *)(a2 + 16),
      *(_DWORD *)(a2 + 20));
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: RSO_CFG: neighbor_report_cache_timeout:%u max_neighbor_report_req_cap:%u SSID:%.*s",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "send_offload_11k_cmd_tlv",
      *(unsigned int *)(a2 + 24),
      *(unsigned int *)(a2 + 28),
      *(unsigned __int8 *)(a2 + 32),
      a2 + 33);
    wmi_mtrace(0x3D001u, *(_DWORD *)(v14 + 4), 0);
    v34 = wmi_unified_cmd_send_fl(
            a1,
            v15,
            v4,
            0x3D001u,
            "send_offload_11k_cmd_tlv",
            0x1987u,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33);
    if ( v34 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Failed to send 11k offload command %d",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        "send_offload_11k_cmd_tlv",
        v34);
      wmi_buf_free();
    }
  }
  else
  {
    return 2;
  }
  return v34;
}
