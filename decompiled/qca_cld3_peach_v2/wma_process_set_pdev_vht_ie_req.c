__int64 __fastcall wma_process_set_pdev_vht_ie_req(__int64 *a1, __int64 a2)
{
  int v4; // w22
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x23
  __int64 v15; // x19
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  v4 = (*(unsigned __int8 *)(a2 + 3) + 3) & 0x1FC;
  result = wmi_buf_alloc_fl(*a1, v4 + 24, "wma_process_set_pdev_vht_ie_req", 0x1D3u);
  if ( result )
  {
    v14 = *(_QWORD *)(result + 224);
    v15 = result;
    *(_QWORD *)v14 = 11010064;
    *(_DWORD *)(v14 + 8) = *(unsigned __int8 *)(a2 + 3);
    *(_DWORD *)(v14 + 12) = *(unsigned __int8 *)(a2 + 2);
    *(_DWORD *)(v14 + 16) = *(unsigned __int8 *)(a2 + 2);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Setting pdev VHT ie with Nss = %u",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "wma_process_set_pdev_vht_ie_req",
      *(unsigned __int8 *)(a2 + 2));
    *(_DWORD *)(v14 + 20) = v4 | 0x110000;
    if ( *(_BYTE *)(a2 + 3) )
      qdf_mem_copy((void *)(v14 + 24), *(const void **)(a2 + 8), *(unsigned __int8 *)(a2 + 3));
    result = wmi_unified_cmd_send_fl(
               *a1,
               v15,
               v4 + 24,
               0x4008u,
               "wma_process_set_pdev_vht_ie_req",
               0x1E9u,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               v22,
               v23);
    if ( (_DWORD)result )
      return wmi_buf_free();
  }
  return result;
}
