__int64 __fastcall cam_icp_mgr_create_handle(__int64 a1, int a2, __int64 a3)
{
  __int64 v5; // x8
  int v6; // w24
  const char *v7; // x5
  __int64 v8; // x4
  int *task; // x0
  int *v10; // x21
  __int64 v11; // x22
  int v12; // w8
  __int64 v13; // x9
  unsigned int v14; // w0
  unsigned int v15; // w19
  __int64 result; // x0
  __int64 v17; // x0
  __int64 v18; // x21
  __int64 v19; // x1
  __int64 v20; // x22
  __int64 v21; // x0
  __int64 v22; // x23
  __int64 v23; // x1
  __int64 v24; // x24
  int v25; // w0
  __int64 v26; // x21
  unsigned int (__fastcall *v27)(__int64, __int64, int *, __int64); // x8
  __int64 v28; // x0
  const char *v29; // x5
  __int64 v30; // x6
  __int64 v31; // x4
  __int64 v32; // [xsp+28h] [xbp-28h] BYREF
  __int128 v33; // [xsp+30h] [xbp-20h]
  int v34; // [xsp+40h] [xbp-10h]
  int v35; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+48h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a3 + 16);
  v34 = 0;
  v33 = 0u;
  LODWORD(v5) = *(_DWORD *)(v5 + 8);
  v32 = 0;
  if ( (_DWORD)v5 == 4 )
  {
    v6 = a2 - 7;
    HIDWORD(v32) = 67174408;
    if ( (unsigned int)(a2 - 7) >= 3 )
    {
      v7 = "Invalid OFE stream type: %u";
      v8 = 8224;
LABEL_13:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_create_handle",
        v8,
        v7);
LABEL_14:
      result = 4294967274LL;
      goto LABEL_18;
    }
  }
  else
  {
    v6 = a2 - 1;
    HIDWORD(v32) = 16842760;
    if ( (unsigned int)(a2 - 1) >= 6 )
    {
      v7 = "Invalid IPE/BPS stream type: %u";
      v8 = 8249;
      goto LABEL_13;
    }
  }
  task = cam_req_mgr_workq_get_task(*(_QWORD *)(a1 + 992));
  if ( !task )
  {
LABEL_17:
    result = 4294967284LL;
    goto LABEL_18;
  }
  v10 = task;
  if ( mem_trace_en == 1 )
  {
    v11 = cam_mem_trace_alloc(24, 0xCC0u, 0, "cam_icp_mgr_create_handle", 0x2041u);
    if ( v11 )
      goto LABEL_8;
    goto LABEL_16;
  }
  v11 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  if ( !v11 )
  {
LABEL_16:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_create_handle",
      8259,
      "Failed in allocating memory for ICP ctx info");
    goto LABEL_17;
  }
LABEL_8:
  v12 = *(_DWORD *)(a3 + 29224);
  *(_QWORD *)(v11 + 16) = a3;
  *(_DWORD *)(v11 + 4) = v12;
  LODWORD(v33) = v6 + 1;
  *(_QWORD *)((char *)&v33 + 4) = v11;
  *(_DWORD *)(a3 + 29192) = 0;
  v13 = *((_QWORD *)v10 + 1);
  LODWORD(v32) = 28;
  *(_QWORD *)(v13 + 8) = &v32;
  *(_DWORD *)v13 = 1;
  *(_DWORD *)(v13 + 16) = 0;
  *((_QWORD *)v10 + 2) = cam_icp_mgr_process_cmd;
  v14 = cam_req_mgr_workq_enqueue_task((unsigned int *)v10, a1, 0);
  if ( !v14 )
  {
    v17 = ktime_get_with_offset(1);
    v18 = ns_to_timespec64(v17);
    v20 = v19;
    if ( cam_common_wait_for_completion_timeout(a3 + 29192) )
    {
      result = 0;
      if ( *(_DWORD *)(a3 + 72) )
        goto LABEL_18;
      goto LABEL_31;
    }
    v21 = ktime_get_with_offset(1);
    v22 = ns_to_timespec64(v21);
    v24 = v23;
    v25 = jiffies_to_msecs(1250, v23);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_create_handle",
      8287,
      "%s: FW response timeout for create handle command (timeout: %ums start: timestamp:[%lld:%06lld] end: timestamp:[%lld:%06lld])",
      (const char *)(a3 + 29824),
      v25,
      v18,
      v20 / 1000,
      v22,
      v24 / 1000);
    v26 = *(_QWORD *)(a1 + 80);
    if ( v26 )
    {
      v35 = 1;
      cam_icp_mgr_process_dbg_buf(a1);
      cam_hfi_queue_dump(*(unsigned int *)(a1 + 156), 0);
      v27 = *(unsigned int (__fastcall **)(__int64, __int64, int *, __int64))(v26 + 88);
      v28 = *(_QWORD *)(v26 + 112);
      if ( *((_DWORD *)v27 - 1) != -1055839300 )
        __break(0x8228u);
      if ( !v27(v28, 15, &v35, 4) )
      {
LABEL_30:
        result = 4294967186LL;
        if ( *(_DWORD *)(a3 + 72) )
          goto LABEL_18;
LABEL_31:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_create_handle",
          8294,
          "%s: Invalid handle created",
          (const char *)(a3 + 29824));
        goto LABEL_14;
      }
      v29 = "[%s] Fail to dump debug info";
      v30 = a1 + 112;
      v31 = 219;
    }
    else
    {
      v29 = "[%s] ICP device interface is NULL";
      v30 = a1 + 112;
      v31 = 208;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_dump_debug_info",
      v31,
      v29,
      v30);
    goto LABEL_30;
  }
  v15 = v14;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_create_handle",
    8278,
    "Failed at enqueuing task to workq, ctx_id: %d",
    *(_DWORD *)(v11 + 4));
  if ( mem_trace_en == 1 )
    cam_mem_trace_free((_QWORD *)v11, 0);
  else
    kvfree(v11);
  result = v15;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
