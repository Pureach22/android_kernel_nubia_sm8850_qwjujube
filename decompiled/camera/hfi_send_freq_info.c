__int64 __fastcall hfi_send_freq_info(unsigned int a1, int a2)
{
  __int64 v3; // x22
  unsigned int v4; // w20
  __int64 v7; // x0
  unsigned int *v8; // x20

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
    v4 = -22;
LABEL_7:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_send_freq_info",
      779,
      "Failed to get hfi info rc: %d for hdl: %d",
      v4,
      a1);
    return v4;
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
    v4 = -19;
    goto LABEL_7;
  }
  if ( (*(_BYTE *)(v3 + 992) & 0x20) != 0 )
  {
    if ( mem_trace_en == 1 )
      v7 = cam_mem_trace_alloc(20, 0xCC0u, 0, "hfi_send_freq_info", 0x313u);
    else
      v7 = _kvmalloc_node_noprof(20, 0, 3520, 0xFFFFFFFFLL);
    v8 = (unsigned int *)v7;
    if ( v7 )
    {
      *(_DWORD *)(v7 + 16) = a2;
      *(_QWORD *)v7 = 0x1000300000014LL;
      *(_QWORD *)(v7 + 8) = 0xA00000001LL;
      if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40000,
          4,
          "hfi_send_freq_info",
          814,
          "[%s] hfi hdl: %d\n"
          "prop->size = %d\n"
          "prop->pkt_type = %d\n"
          "prop->num_prop = %d\n"
          "prop->prop_data[0] = %d\n"
          "prop->prop_data[1] = %d\n"
          "dbg_lvl = 0x%x\n",
          (const char *)(v3 + 1004),
          a1,
          20,
          65539,
          1,
          10,
          a2,
          *(_QWORD *)(v3 + 992));
      hfi_write_cmd(a1, v8);
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v8, 0);
      else
        kvfree(v8);
      return 0;
    }
    else
    {
      return (unsigned int)-12;
    }
  }
  else
  {
    return (unsigned int)-22;
  }
}
