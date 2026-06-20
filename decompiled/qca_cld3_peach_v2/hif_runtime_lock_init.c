__int64 __fastcall hif_runtime_lock_init(__int64 *a1, const char *a2)
{
  __int64 v4; // x0
  const char *v5; // x9
  __int64 v6; // x8
  __int64 result; // x0

  if ( gp_hif_rtpm_ctx )
  {
    qdf_trace_msg(61, 8, "%s: Initializing Runtime PM wakelock %s", "hif_runtime_lock_init", a2);
    v4 = _qdf_mem_malloc(32, "hif_runtime_lock_init", 600);
    if ( v4 )
    {
      v5 = "Default";
      v6 = v4;
      result = 0;
      if ( a2 )
        v5 = a2;
      *(_QWORD *)(v6 + 24) = v5;
      *a1 = v6;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    qdf_trace_msg(61, 2, "%s: Runtime PM context NULL", "hif_runtime_lock_init");
    return 16;
  }
  return result;
}
