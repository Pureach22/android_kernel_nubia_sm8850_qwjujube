_QWORD *__fastcall cam_icp_mgr_destroy_handle(_QWORD *result)
{
  __int64 v1; // x19
  unsigned int v2; // w8
  int v3; // w21
  int v4; // w22
  _QWORD *v5; // x27
  _QWORD *v6; // x20
  __int64 v7; // x0
  int v8; // w9
  _QWORD *v9; // x21
  int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x21
  __int64 v13; // x1
  __int64 v14; // x22
  __int64 v15; // x0
  __int64 v16; // x23
  __int64 v17; // x1
  __int64 v18; // x24
  int v19; // w0

  v1 = result[1];
  if ( !*(_DWORD *)(v1 + 44148) )
  {
    v2 = *(_DWORD *)(result[2] + 8LL) - 2;
    if ( v2 >= 3 )
      return (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD *))cam_print_log)(
                         3,
                         256,
                         1,
                         "cam_icp_mgr_destroy_handle",
                         5016,
                         "%s: Invalid hw dev type not supported: %u",
                         result + 3728);
    v3 = dword_452044[v2];
    v4 = dword_45202C[v2];
    v5 = result;
    result = (_QWORD *)(mem_trace_en == 1
                      ? cam_mem_trace_alloc(44, 0xCC0u, 0, "cam_icp_mgr_destroy_handle", 0x139Cu)
                      : _kvmalloc_node_noprof(44, 0, 3520, 0xFFFFFFFFLL));
    v6 = result;
    if ( result )
    {
      if ( mem_trace_en == 1 )
      {
        v7 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_destroy_handle", 0x13A2u);
        if ( !v7 )
          goto LABEL_22;
      }
      else
      {
        v7 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
        if ( !v7 )
        {
LABEL_22:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_destroy_handle",
            5028,
            "Failed in allocating memory for ICP ctx info");
LABEL_23:
          if ( mem_trace_en == 1 )
            return cam_mem_trace_free(v6, 0);
          else
            return (_QWORD *)kvfree(v6);
        }
      }
      v8 = *((_DWORD *)v5 + 7306);
      *(_QWORD *)(v7 + 16) = v5;
      *(_DWORD *)(v7 + 4) = v8;
      *(_DWORD *)v6 = 44;
      *((_DWORD *)v6 + 1) = v3;
      v9 = (_QWORD *)v7;
      *((_DWORD *)v6 + 2) = v4;
      *((_DWORD *)v6 + 7) = 1;
      v10 = *((_DWORD *)v5 + 18);
      *(_QWORD *)((char *)v6 + 12) = v7;
      *(_QWORD *)((char *)v6 + 20) = 0;
      *((_DWORD *)v6 + 8) = v10;
      *((_DWORD *)v5 + 7298) = 0;
      if ( (unsigned int)hfi_write_cmd(*(unsigned int *)(v1 + 156), v6) )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v9, 0);
        else
          kvfree(v9);
      }
      else
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_destroy_handle",
            5053,
            "%s: fw_handle = 0x%x ctx_data = %pK",
            (const char *)v5 + 29824,
            *((_DWORD *)v5 + 18),
            v5);
        v11 = ktime_get_with_offset(1);
        v12 = ns_to_timespec64(v11);
        v14 = v13;
        if ( !cam_common_wait_for_completion_timeout((__int64)(v5 + 3649)) )
        {
          v15 = ktime_get_with_offset(1);
          v16 = ns_to_timespec64(v15);
          v18 = v17;
          v19 = jiffies_to_msecs(250, v17);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_destroy_handle",
            5058,
            "%s: FW response timeout for Destroy handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timest"
            "amp:[%lld:%06lld])",
            (const char *)v5 + 29824,
            v19,
            v12,
            v14 / 1000,
            v16,
            v18 / 1000);
          cam_icp_dump_debug_info(v1, *((unsigned __int8 *)v5 + 30000));
          if ( *(_BYTE *)(v1 + 44260) == 1 )
            panic("CAMERA - [%s] Destroy Timeout......\n", (const char *)(v1 + 112));
        }
      }
      goto LABEL_23;
    }
  }
  return result;
}
