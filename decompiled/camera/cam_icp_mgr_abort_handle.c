_QWORD *__fastcall cam_icp_mgr_abort_handle(_QWORD *result)
{
  __int64 v1; // x26
  _QWORD *v2; // x19
  __int64 v3; // x0
  _QWORD *v4; // x21
  int v5; // w8
  _QWORD *v6; // x0
  _QWORD *v7; // x20
  __int64 v8; // x0
  __int64 v9; // x21
  __int64 v10; // x1
  __int64 v11; // x22
  __int64 v12; // x0
  __int64 v13; // x23
  __int64 v14; // x1
  __int64 v15; // x24
  int v16; // w0
  _QWORD v17[2]; // [xsp+20h] [xbp-10h] BYREF

  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = result[1];
  if ( !*(_DWORD *)(v1 + 44148) )
  {
    v2 = result;
    v17[0] = 0;
    if ( mem_trace_en == 1 )
      v3 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_abort_handle", 0x1349u);
    else
      v3 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    v4 = (_QWORD *)v3;
    if ( !v3 )
    {
      result = (_QWORD *)((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                           3,
                           256,
                           1,
                           "cam_icp_mgr_abort_handle",
                           4939,
                           "Failed in allocating memory for ICP ctx info");
      goto LABEL_2;
    }
    v5 = *((_DWORD *)v2 + 7306);
    *(_QWORD *)(v3 + 16) = v2;
    *(_DWORD *)(v3 + 4) = v5;
    if ( (unsigned int)cam_icp_mgr_populate_abort_cmd(v3, v17) )
    {
      v6 = v4;
      if ( mem_trace_en == 1 )
      {
LABEL_9:
        result = cam_mem_trace_free(v6, 0);
        goto LABEL_2;
      }
    }
    else
    {
      *((_DWORD *)v2 + 7298) = 0;
      v7 = (_QWORD *)v17[0];
      if ( (unsigned int)hfi_write_cmd(*(unsigned int *)(v1 + 156), v17[0]) )
      {
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v4, 0);
        else
          kvfree(v4);
      }
      else
      {
        if ( (debug_mdl & 0x100) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x100,
            4,
            "cam_icp_mgr_abort_handle",
            4961,
            "%s: fw_handle = 0x%x ctx_data = %pK",
            (const char *)v2 + 29824,
            *((_DWORD *)v2 + 18),
            v2);
        v8 = ktime_get_with_offset(1);
        v9 = ns_to_timespec64(v8);
        v11 = v10;
        if ( !cam_common_wait_for_completion_timeout((__int64)(v2 + 3649)) )
        {
          v12 = ktime_get_with_offset(1);
          v13 = ns_to_timespec64(v12);
          v15 = v14;
          v16 = jiffies_to_msecs(500, v14);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_abort_handle",
            4966,
            "%s: FW response timeout for Abort handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timestam"
            "p:[%lld:%06lld])",
            (const char *)v2 + 29824,
            v16,
            v9,
            v11 / 1000,
            v13,
            v15 / 1000);
          cam_icp_dump_debug_info(v2[1], 0);
          *((_BYTE *)v2 + 30000) = 1;
          if ( *(_BYTE *)(v1 + 44260) == 1 )
            panic("CAMERA - [%s] Abort Timeout......\n", (const char *)(v1 + 112));
        }
      }
      v6 = v7;
      if ( mem_trace_en == 1 )
        goto LABEL_9;
    }
    result = (_QWORD *)kvfree(v6);
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
