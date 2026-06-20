__int64 __fastcall hfi_set_debug_level(unsigned int a1, int a2, unsigned int a3)
{
  __int64 v4; // x8
  unsigned int v5; // w20
  int v8; // w9
  __int64 v10; // x0
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
    v5 = -22;
LABEL_7:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_set_debug_level",
      674,
      "Failed to get hfi info rc: %d for hdl: %d",
      v5,
      a1);
    return v5;
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
    v5 = -19;
    goto LABEL_7;
  }
  if ( a3 <= 0x1100003F )
  {
    v8 = (unsigned __int8)mem_trace_en;
    *(_QWORD *)(v4 + 992) = a3;
    if ( v8 == 1 )
      v10 = cam_mem_trace_alloc(24, 0xCC0u, 0, "hfi_set_debug_level", 0x2B8u);
    else
      v10 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
    v11 = (_QWORD *)v10;
    if ( v10 )
    {
      *(_DWORD *)(v10 + 16) = a3;
      *(_DWORD *)(v10 + 20) = a2;
      *(_QWORD *)v10 = 0x1000300000018LL;
      *(_QWORD *)(v10 + 8) = 0x100000001LL;
      hfi_write_cmd(a1, (unsigned int *)v10);
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
  else
  {
    return (unsigned int)-22;
  }
}
