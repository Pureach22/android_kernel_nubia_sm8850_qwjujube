__int64 __fastcall rproc_restart_level_notifier(__int64 a1, __int64 a2)
{
  const char *v2; // x20
  size_t v4; // x0
  size_t v5; // x0
  size_t v6; // x0
  __int64 result; // x0
  _BYTE *v8; // x3
  __int64 v9; // x0

  v2 = *(const char **)(a2 + 24);
  v4 = strlen(v2);
  printk("%sicnss2: rproc name: %s(%zu) recovery disable: %d", byte_13289B, v2, v4, *(unsigned __int8 *)(a2 + 1204));
  v5 = strlen(*(const char **)(a2 + 24));
  ipc_log_string(
    icnss_ipc_log_context,
    "%sicnss2: rproc name: %s(%zu) recovery disable: %d",
    (const char *)&unk_12DBF3,
    *(const char **)(a2 + 24),
    v5,
    *(unsigned __int8 *)(a2 + 1204));
  v6 = strlen(*(const char **)(a2 + 24));
  result = strnstr(*(_QWORD *)(a2 + 24), "wpss", v6);
  if ( result )
  {
    result = _kmalloc_cache_noprof(pm_stay_awake, 2336, 1);
    v8 = (_BYTE *)result;
    if ( result )
    {
      v9 = penv;
      *v8 = *(_BYTE *)(a2 + 1204) ^ 1;
      return icnss_driver_event_post(v9, 0x11u, 0, (__int64)v8);
    }
  }
  return result;
}
