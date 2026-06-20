__int64 __fastcall send_dfs_phyerr_filter_offload_en_cmd_tlv(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x0
  __int64 v12; // x20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x4
  const char *v31; // x2
  __int64 result; // x0
  __int64 v33; // x20
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w0
  const char *v43; // x2

  if ( (a2 & 1) != 0 )
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Phyerror Filtering offload is Enabled in ini",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_dfs_phyerr_filter_offload_en_cmd_tlv");
    v11 = wmi_buf_alloc_fl(a1, 8u, "send_dfs_phyerr_filter_offload_en_cmd_tlv", 0x20B8u);
    if ( !v11 )
      return 16;
    v12 = v11;
    **(_DWORD **)(v11 + 224) = 15269892;
    qdf_mtrace(49, 100, 0x503u, 0xFFu, 0);
    v21 = wmi_unified_cmd_send_fl(
            a1,
            v12,
            8u,
            0xA003u,
            "send_dfs_phyerr_filter_offload_en_cmd_tlv",
            0x20CCu,
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19,
            v20);
    if ( v21 )
    {
      v30 = v21;
      v31 = "%s: Failed to send DFS PHYERR CMD ret=%d";
LABEL_8:
      qdf_trace_msg(
        0x31u,
        2u,
        v31,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "send_dfs_phyerr_filter_offload_en_cmd_tlv",
        v30);
      wmi_buf_free();
      return 16;
    }
    v43 = "%s: WMI_DFS_PHYERR_FILTER_ENA_CMDID Send Success";
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Phyerror Filtering offload is Disabled in ini",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "send_dfs_phyerr_filter_offload_en_cmd_tlv");
    result = wmi_buf_alloc_fl(a1, 8u, "send_dfs_phyerr_filter_offload_en_cmd_tlv", 0x2098u);
    if ( !result )
      return result;
    v33 = result;
    **(_DWORD **)(result + 224) = 15335428;
    qdf_mtrace(49, 100, 0x504u, 0xFFu, 0);
    v42 = wmi_unified_cmd_send_fl(
            a1,
            v33,
            8u,
            0xA004u,
            "send_dfs_phyerr_filter_offload_en_cmd_tlv",
            0x20ACu,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41);
    if ( v42 )
    {
      v30 = v42;
      v31 = "%s: Failed to send WMI_DFS_PHYERR_FILTER_DIS_CMDID ret=%d";
      goto LABEL_8;
    }
    v43 = "%s: WMI_DFS_PHYERR_FILTER_DIS_CMDID Send Success";
  }
  qdf_trace_msg(0x31u, 8u, v43, v22, v23, v24, v25, v26, v27, v28, v29, "send_dfs_phyerr_filter_offload_en_cmd_tlv");
  return 0;
}
