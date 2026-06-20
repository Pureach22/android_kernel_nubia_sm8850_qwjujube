__int64 __fastcall wma_roam_scan_send_hlp(_QWORD *a1, __int64 a2)
{
  __int64 result; // x0
  unsigned __int8 *v5; // x21
  size_t v6; // x2
  unsigned int v7; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7

  result = _qdf_mem_malloc(0x808u, "wma_roam_scan_send_hlp", 8938);
  if ( result )
  {
    v5 = (unsigned __int8 *)result;
    *(_BYTE *)result = *(_BYTE *)a2;
    v6 = *(unsigned int *)(a2 + 4);
    *(_DWORD *)(result + 4) = v6;
    qdf_mem_copy((void *)(result + 8), (const void *)(a2 + 8), v6);
    v7 = wmi_unified_roam_send_hlp_cmd(*a1, v5);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Send HLP status %d vdev id %d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "wma_roam_scan_send_hlp",
      v7,
      *v5);
    ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, __int64))qdf_trace_hex_dump)(49, 8, v5 + 8, 10);
    return _qdf_mem_free((__int64)v5);
  }
  return result;
}
