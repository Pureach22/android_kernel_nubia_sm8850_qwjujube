__int64 __fastcall cam_icp_mgr_prepare_frame_process_cmd(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  __int64 result; // x0
  int v9; // w8
  unsigned int v10; // w8
  int v11; // w9
  int v12; // w8

  if ( mem_trace_en == 1 )
  {
    result = cam_mem_trace_alloc(24, 0x820u, 0, "cam_icp_mgr_prepare_frame_process_cmd", 0x18A3u);
    if ( !result )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_prepare_frame_process_cmd",
               6309,
               "Failed in allocating memory for ICP ctx info");
  }
  else
  {
    result = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
    if ( !result )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               1,
               "cam_icp_mgr_prepare_frame_process_cmd",
               6309,
               "Failed in allocating memory for ICP ctx info");
  }
  v9 = *(_DWORD *)(a1 + 29224);
  *(_QWORD *)(result + 16) = a1;
  *(_DWORD *)(result + 4) = v9;
  v10 = *(_DWORD *)(*(_QWORD *)(a1 + 16) + 8LL) - 2;
  if ( v10 >= 3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
             3,
             256,
             1,
             "cam_icp_mgr_prepare_frame_process_cmd",
             6331,
             "%s: Invalid hw dev type not supported: %u",
             a1 + 29824);
  v11 = dword_45205C[v10];
  *(_DWORD *)(a2 + 4) = dword_452068[v10];
  *(_DWORD *)(a2 + 8) = v11;
  *(_DWORD *)a2 = 40;
  *(_DWORD *)(a2 + 28) = 1;
  v12 = *(_DWORD *)(a1 + 72);
  *(_QWORD *)(a2 + 12) = result;
  *(_QWORD *)(a2 + 20) = a3;
  *(_DWORD *)(a2 + 32) = v12;
  *(_DWORD *)(a2 + 36) = a4;
  if ( (debug_mdl & 0x100) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 0x100,
             4,
             "cam_icp_mgr_prepare_frame_process_cmd",
             6344,
             "%s: ctx_data : %pK, request_id :%lld cmd_buf %x",
             (const char *)(a1 + 29824),
             *(const void **)a1,
             a3,
             a4);
  return result;
}
