__int64 __fastcall hfi_cmd_ubwc_config(unsigned int a1, _DWORD *a2)
{
  __int64 v3; // x8
  __int64 v5; // x0
  unsigned int v6; // w20
  _QWORD *v7; // x20

  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v6 = -22;
LABEL_10:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_cmd_ubwc_config",
      587,
      "Failed to get hfi info rc: %d for hdl:%d",
      v6,
      a1);
    return v6;
  }
  v3 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v6 = -19;
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000,
      4,
      "hfi_cmd_ubwc_config",
      593,
      "[%s] hfi hdl: %d size of ubwc %u, ubwc_cfg [rd-0x%x,wr-0x%x]",
      (const char *)(v3 + 1004),
      a1,
      24,
      *a2,
      a2[1]);
  if ( mem_trace_en == 1 )
    v5 = cam_mem_trace_alloc(24, 0xCC0u, 0, "hfi_cmd_ubwc_config", 0x253u);
  else
    v5 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  v7 = (_QWORD *)v5;
  if ( v5 )
  {
    *(_QWORD *)v5 = 0x1000300000018LL;
    *(_QWORD *)(v5 + 8) = 0x200000001LL;
    *(_DWORD *)(v5 + 16) = *a2;
    *(_DWORD *)(v5 + 20) = a2[1];
    hfi_write_cmd(a1, (unsigned int *)v5);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v7, 0);
    else
      kvfree(v7);
    return 0;
  }
  else
  {
    return (unsigned int)-12;
  }
}
