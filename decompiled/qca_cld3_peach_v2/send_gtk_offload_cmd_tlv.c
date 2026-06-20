__int64 __fastcall send_gtk_offload_cmd_tlv(__int64 a1, unsigned __int8 a2, __int64 a3, char a4, int a5)
{
  unsigned int v5; // w8
  unsigned int v10; // w19
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x26
  __int64 v22; // x21
  int v23; // w9
  size_t v24; // x2
  int *v25; // x24
  __int64 result; // x0
  char *v27; // x24
  int *v28; // x0
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

  v5 = *(unsigned __int8 *)(a3 + 36);
  if ( *(_BYTE *)(a3 + 126) )
    v10 = 160;
  else
    v10 = 56;
  if ( v5 >= 0x11 )
    v10 += (((_WORD)v5 + 3) & 0x1FC) + ((*(_DWORD *)(a3 + 104) + 3) & 0xFFFFFFFC) + 8;
  v12 = wmi_buf_alloc_fl(a1, v10, "send_gtk_offload_cmd_tlv", 0x370u);
  if ( !v12 )
    return 2;
  v21 = *(_QWORD *)(v12 + 224);
  v22 = v12;
  *(_DWORD *)v21 = 5963824;
  *(_DWORD *)(v21 + 4) = a2;
  *(_DWORD *)(v21 + 8) = a5;
  if ( (a4 & 1) == 0 )
  {
    qdf_mem_copy((void *)(v21 + 28), (const void *)(a3 + 4), 0x10u);
    qdf_mem_copy((void *)(v21 + 12), (const void *)(a3 + 37), 0x10u);
    qdf_mem_copy((void *)(v21 + 44), (const void *)(a3 + 112), 8u);
  }
  if ( *(_BYTE *)(a3 + 126) == 1 )
  {
    v23 = *(_DWORD *)(v21 + 8);
    *(_DWORD *)(v21 + 60) = a2;
    *(_DWORD *)(v21 + 64) = v23;
    *(_QWORD *)(v21 + 52) = 0x2A1006400120068LL;
    v24 = *(unsigned int *)(a3 + 104);
    *(_DWORD *)(v21 + 68) = v24;
    qdf_mem_copy((void *)(v21 + 72), (const void *)(a3 + 37), v24);
    qdf_mem_copy((void *)(v21 + 136), (const void *)(a3 + 4), 0x10u);
    qdf_mem_copy((void *)(v21 + 152), (const void *)(a3 + 112), 8u);
    v25 = (int *)(v21 + 156);
  }
  else
  {
    v25 = (int *)(v21 + 56);
    *(_DWORD *)(v21 + 52) = 1179648;
  }
  if ( *(unsigned __int8 *)(a3 + 36) >= 0x11u )
  {
    *v25 = ((unsigned __int16)*(_DWORD *)(a3 + 104) + 3) & 0xFFFC | 0x110000;
    v27 = (char *)(v25 + 1);
    qdf_mem_copy(v27, (const void *)(a3 + 37), *(unsigned int *)(a3 + 104));
    v28 = (int *)&v27[(*(unsigned int *)(a3 + 104) + 3LL) & 0x1FFFFFFFCLL];
    *v28 = (*(unsigned __int8 *)(a3 + 36) + 3) & 0x1FC | 0x110000;
    qdf_mem_copy(v28 + 1, (const void *)(a3 + 4), *(unsigned __int8 *)(a3 + 36));
  }
  qdf_trace_msg(
    0x31u,
    8u,
    "%s: VDEVID: %d, GTK_FLAGS: x%x kek len %d",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "send_gtk_offload_cmd_tlv",
    a2,
    *(unsigned int *)(v21 + 8),
    *(unsigned int *)(a3 + 104));
  wmi_mtrace(0x19001u, *(_DWORD *)(v21 + 4), 0);
  result = wmi_unified_cmd_send_fl(
             a1,
             v22,
             v10,
             0x19001u,
             "send_gtk_offload_cmd_tlv",
             0x3ABu,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             v35,
             v36);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Failed to send WMI_GTK_OFFLOAD_CMDID %d",
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      "send_gtk_offload_cmd_tlv",
      (unsigned int)result);
    wmi_buf_free();
    return 16;
  }
  return result;
}
