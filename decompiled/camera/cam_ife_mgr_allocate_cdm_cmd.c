__int64 __fastcall cam_ife_mgr_allocate_cdm_cmd(char a1, __int64 *a2)
{
  int v3; // w8
  __int64 v4; // x0
  __int64 v5; // x0

  if ( (a1 & 1) != 0 )
    v3 = 40;
  else
    v3 = 30;
  if ( mem_trace_en == 1 )
  {
    v4 = cam_mem_trace_alloc((unsigned int)(24 * v3 + 48), 0xCC0u, 0, "cam_ife_mgr_allocate_cdm_cmd", 0x4C1u);
    *a2 = v4;
    if ( !v4 )
      goto LABEL_9;
    return 0;
  }
  v5 = _kvmalloc_node_noprof((unsigned int)(24 * v3 + 48), 0, 3520, 0xFFFFFFFFLL);
  *a2 = v5;
  if ( v5 )
    return 0;
LABEL_9:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_allocate_cdm_cmd",
    1220,
    "Failed to allocate cdm bl memory");
  return 4294967284LL;
}
