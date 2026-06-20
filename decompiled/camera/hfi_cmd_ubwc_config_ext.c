__int64 __fastcall hfi_cmd_ubwc_config_ext(unsigned int a1, _DWORD *a2, _DWORD *a3, _DWORD *a4)
{
  __int64 v5; // x8
  __int64 v9; // x0
  unsigned int v10; // w20
  _QWORD *v11; // x20

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
    v10 = -22;
LABEL_10:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_cmd_ubwc_config_ext",
      627,
      "Failed to get hfi info rc: %d for hdl:%d",
      v10,
      a1);
    return v10;
  }
  v5 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v5 )
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
    v10 = -19;
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000,
      4,
      "hfi_cmd_ubwc_config_ext",
      638,
      "[%s] hfi hdl: %d size of ubwc %u, ubwc_ipe_cfg[rd-0x%x,wr-0x%x] ubwc_bps_cfg[rd-0x%x,wr-0x%x] ubwc_ofe_cfg[rd-0x%x,wr-0x%x]",
      (const char *)(v5 + 1004),
      a1,
      40,
      *a2,
      a2[1],
      *a3,
      a3[1],
      *a4,
      a4[1]);
  if ( mem_trace_en == 1 )
    v9 = cam_mem_trace_alloc(40, 0xCC0u, 0, "hfi_cmd_ubwc_config_ext", 0x280u);
  else
    v9 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
  v11 = (_QWORD *)v9;
  if ( v9 )
  {
    *(_QWORD *)v9 = 0x1000300000028LL;
    *(_QWORD *)(v9 + 8) = 0x900000001LL;
    *(_DWORD *)(v9 + 16) = *a3;
    *(_DWORD *)(v9 + 20) = a3[1];
    *(_DWORD *)(v9 + 24) = *a2;
    *(_DWORD *)(v9 + 28) = a2[1];
    *(_DWORD *)(v9 + 32) = *a4;
    *(_DWORD *)(v9 + 36) = a4[1];
    hfi_write_cmd(a1, (unsigned int *)v9);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v11, 0);
    else
      kvfree(v11);
    return 0;
  }
  else
  {
    return (unsigned int)-12;
  }
}
