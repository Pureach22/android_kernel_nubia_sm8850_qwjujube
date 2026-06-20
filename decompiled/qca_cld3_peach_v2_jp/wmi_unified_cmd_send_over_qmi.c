__int64 __fastcall wmi_unified_cmd_send_over_qmi(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x8
  unsigned int v42; // w21
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  __int64 v52; // x0
  unsigned int v60; // w4

  v4 = *(_QWORD *)(a2 + 40);
  if ( v4 )
    *(_QWORD *)(a2 + 40) = v4 - 4;
  if ( skb_push(a2, 4) )
  {
    qdf_mem_set(*(void **)(a2 + 224), 4u, 0);
    **(_DWORD **)(a2 + 224) = a4 & 0xFFFFFF | (*(unsigned __int8 *)(*(_QWORD *)(a2 + 224) + 3LL) << 24);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Sending WMI_CMD_ID: 0x%x over qmi",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wmi_unified_cmd_send_over_qmi",
      a4);
    v32 = qdf_wmi_send_recv_qmi(v24, v25, v26, v27, v28, v29, v30, v31);
    if ( v32 )
    {
      v41 = *(_QWORD *)(a2 + 40);
      v42 = v32;
      if ( v41 )
        *(_QWORD *)(a2 + 40) = v41 + 4;
      skb_pull(a2, 4);
      qdf_trace_msg(
        0x31u,
        3u,
        "%s: WMI send on QMI failed. Retrying WMI on HTC",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wmi_unified_cmd_send_over_qmi");
    }
    else
    {
      _X8 = (unsigned int *)(a1 + 888);
      __asm { PRFM            #0x11, [X8] }
      do
        v60 = __ldxr(_X8);
      while ( __stlxr(v60 + 1, _X8) );
      __dmb(0xBu);
      qdf_trace_msg(
        0x31u,
        8u,
        "%s: num stats over qmi: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wmi_unified_cmd_send_over_qmi");
      v52 = wbuff_buff_put(a2);
      if ( v52 )
        _qdf_nbuf_free(v52);
      return 0;
    }
  }
  else
  {
    v51 = a4;
    v42 = 2;
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send cmd %x, no memory",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wmi_unified_cmd_send_over_qmi",
      v51);
  }
  return v42;
}
