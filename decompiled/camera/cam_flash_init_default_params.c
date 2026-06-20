__int64 __fastcall cam_flash_init_default_params(__int64 a1)
{
  int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x0
  __int64 v5; // x0
  __int64 v6; // x19

  if ( (debug_mdl & 0x1000) != 0 && !debug_priority )
  {
    v6 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x1000,
      4,
      "cam_flash_init_default_params",
      325,
      "master_type: %d",
      *(_DWORD *)(a1 + 6280));
    a1 = v6;
  }
  v1 = *(_DWORD *)(a1 + 6280);
  if ( v1 == 2 )
  {
    if ( !*(_QWORD *)(a1 + 6288) )
      return 4294967274LL;
    return 0;
  }
  if ( v1 != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4096,
      1,
      "cam_flash_init_default_params",
      337,
      "Invalid master / Master type Not supported");
    return 4294967274LL;
  }
  v2 = a1;
  if ( mem_trace_en == 1 )
  {
    v3 = cam_mem_trace_alloc(40, 0xCC0u, 0, "cam_flash_init_default_params", 0x149u);
    *(_QWORD *)(v2 + 6296) = v3;
    if ( !v3 )
      return 4294967284LL;
    return 0;
  }
  v5 = _kvmalloc_node_noprof(40, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(v2 + 6296) = v5;
  if ( v5 )
    return 0;
  return 4294967284LL;
}
