__int64 __fastcall send_log_supported_evt_cmd_tlv(
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
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 v21; // x23
  __int64 v22; // x0
  const char *v23; // x2
  __int64 result; // x0
  __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x0
  _DWORD *v28; // x9
  __int64 v29; // x22
  unsigned __int64 v30; // x8
  _DWORD *v31; // x9
  int v32; // w11
  unsigned int v33; // w11
  unsigned int v34; // w11
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7

  qdf_trace_msg(
    0x31u,
    8u,
    "%s: Received WMI_DIAG_EVENT_LOG_SUPPORTED_EVENTID",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "send_log_supported_evt_cmd_tlv");
  if ( !a2 )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Invalid log supported event buffer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_log_supported_evt_cmd_tlv");
    return 4;
  }
  v20 = *(unsigned int *)(*(_QWORD *)a2 + 4LL);
  if ( (unsigned int)v20 > *(_DWORD *)(a2 + 24) )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: message number of events %d is more than tlv hdr content %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_log_supported_evt_cmd_tlv",
      (unsigned int)v20);
    return 4;
  }
  v21 = *(_QWORD *)(a2 + 16);
  if ( !v21 )
  {
    v23 = "%s: Event list is empty, num_of_diag_events_logs=%d";
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: num_of_diag_events_logs=%d",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "send_log_supported_evt_cmd_tlv",
    (unsigned int)v20);
  v22 = *(_QWORD *)(a1 + 328);
  if ( v22 )
  {
    _qdf_mem_free(v22);
    *(_QWORD *)(a1 + 328) = 0;
  }
  if ( (unsigned int)v20 >= 0x181 )
  {
    v23 = "%s: excess num of logs: %d";
LABEL_11:
    qdf_trace_msg(
      0x31u,
      2u,
      v23,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "send_log_supported_evt_cmd_tlv",
      (unsigned int)v20);
    return 4;
  }
  v25 = 4 * v20;
  v26 = _qdf_mem_malloc(4 * v20, "send_log_supported_evt_cmd_tlv", 11305);
  *(_QWORD *)(a1 + 328) = v26;
  if ( !v26 )
    return 2;
  *(_DWORD *)(a1 + 320) = v20;
  v27 = wmi_buf_alloc_fl(a1, (int)v25 + 12, "send_log_supported_evt_cmd_tlv", 0x2C33u);
  if ( !v27 )
  {
    _qdf_mem_free(*(_QWORD *)(a1 + 328));
    *(_QWORD *)(a1 + 328) = 0;
    return 2;
  }
  v28 = *(_DWORD **)(v27 + 224);
  v29 = v27;
  *v28 = 27328516;
  v28[1] = v20;
  v28[2] = v25 | 0x100000;
  if ( (_DWORD)v20 )
  {
    v30 = 0;
    v31 = v28 + 3;
    do
    {
      v32 = v31[v30 / 4];
      v31[v30 / 4] = v32 & 0xFFFDFFFF;
      v33 = (*(_DWORD *)(v21 + v30) & 0x20000 | v32 & 0xFFFD0000) ^ 0x20000;
      v31[v30 / 4] = v33;
      v34 = v33 & 0xFFFE0000 | *(unsigned __int16 *)(v21 + v30);
      v31[v30 / 4] = v34;
      v31[v30 / 4] = v34 | *(_DWORD *)(v21 + v30) & 0x10000;
      *(_DWORD *)(*(_QWORD *)(a1 + 328) + v30) = *(_DWORD *)(v21 + v30);
      v30 += 4LL;
    }
    while ( v25 != v30 );
  }
  qdf_mtrace(49, 100, 0xB09u, 0xFFu, 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v29,
             (int)v25 + 12,
             0x16009u,
             "send_log_supported_evt_cmd_tlv",
             0x2C5Eu,
             v35,
             v36,
             v37,
             v38,
             v39,
             v40,
             v41,
             v42);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: WMI_DIAG_EVENT_LOG_CONFIG_CMDID failed",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "send_log_supported_evt_cmd_tlv");
    wmi_buf_free();
    return 4;
  }
  return result;
}
