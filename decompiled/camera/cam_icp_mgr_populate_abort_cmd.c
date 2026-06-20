__int64 __fastcall cam_icp_mgr_populate_abort_cmd(__int64 a1, __int64 *a2)
{
  __int64 v2; // x21
  unsigned int v3; // w8
  int v4; // w22
  int v5; // w23
  __int64 v8; // x0
  int v10; // w9
  __int64 v11; // [xsp+18h] [xbp+18h]

  v2 = *(_QWORD *)(a1 + 16);
  v3 = *(_DWORD *)(*(_QWORD *)(v2 + 16) + 8LL) - 2;
  if ( v3 >= 3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_populate_abort_cmd",
      4841,
      "%s: Invalid device type not supported: %u",
      v2 + 29824);
    return 4294967274LL;
  }
  v4 = dword_452038[v3];
  v5 = dword_452044[v3];
  if ( mem_trace_en == 1 )
  {
    v8 = cam_mem_trace_alloc(52, 0xCC0u, 0, "cam_icp_mgr_populate_abort_cmd", 0x12EDu);
    if ( !v8 )
      return 4294967284LL;
  }
  else
  {
    v8 = _kvmalloc_node_noprof(52, 0, 3520, 0xFFFFFFFFLL);
    if ( !v8 )
      return 4294967284LL;
  }
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
  {
    v11 = v8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x100,
      4,
      "cam_icp_mgr_populate_abort_cmd",
      4850,
      "%s: abort pkt size = %d",
      (const char *)(v2 + 29824),
      52);
    v8 = v11;
  }
  *(_DWORD *)(v8 + 8) = v4;
  *(_DWORD *)v8 = 52;
  *(_DWORD *)(v8 + 4) = v5;
  *(_DWORD *)(v8 + 28) = 1;
  v10 = *(_DWORD *)(v2 + 72);
  *(_QWORD *)(v8 + 12) = a1;
  *(_QWORD *)(v8 + 20) = 0;
  *(_DWORD *)(v8 + 32) = v10;
  *a2 = v8;
  return 0;
}
