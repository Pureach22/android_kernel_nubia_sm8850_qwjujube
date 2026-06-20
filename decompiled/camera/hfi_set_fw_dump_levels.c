__int64 __fastcall hfi_set_fw_dump_levels(unsigned int a1, int a2, unsigned int a3)
{
  __int64 v4; // x22
  __int64 v7; // x0
  unsigned int v8; // w20
  unsigned int *v9; // x21

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
    v8 = -22;
LABEL_10:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_set_fw_dump_levels",
      728,
      "Failed to get hfi info rc: %d for hdl: %d",
      v8,
      a1);
    return v8;
  }
  v4 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v4 )
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
    v8 = -19;
    goto LABEL_10;
  }
  if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000,
      4,
      "hfi_set_fw_dump_levels",
      733,
      "[%s] hfi hdl: %d fw dump ENTER",
      (const char *)(v4 + 1004),
      a1);
  if ( mem_trace_en == 1 )
    v7 = cam_mem_trace_alloc(20, 0xCC0u, 0, "hfi_set_fw_dump_levels", 0x2E0u);
  else
    v7 = _kvmalloc_node_noprof(20, 0, 3520, 0xFFFFFFFFLL);
  v9 = (unsigned int *)v7;
  if ( v7 )
  {
    *(_DWORD *)(v7 + 16) = a2;
    *(_QWORD *)v7 = 0x1000300000014LL;
    *(_QWORD *)(v7 + 8) = 0x800000001LL;
    hfi_write_cmd(a1, (unsigned int *)v7);
    v9[3] = 11;
    v9[4] = a3;
    hfi_write_cmd(a1, v9);
    if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000,
        4,
        "hfi_set_fw_dump_levels",
        761,
        "[%s] hfi hdl: %d prop->size = %d prop->pkt_type = %d prop->num_prop = %d hang_dump_lvl = %u ram_dump_lvl = %u",
        (const char *)(v4 + 1004),
        a1,
        *v9,
        v9[1],
        v9[2],
        a2,
        a3);
    if ( mem_trace_en == 1 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    return 0;
  }
  else
  {
    return (unsigned int)-12;
  }
}
