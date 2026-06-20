__int64 __fastcall cam_context_handle_crm_process_evt(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  unsigned int v5; // w20

  if ( *(_QWORD *)(a1 + 248) )
  {
    mutex_lock(a1 + 72);
    v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 120);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != -1084726947 )
        __break(0x8228u);
      v5 = v4(a1, a2);
    }
    else
    {
      v5 = 0;
      if ( (debug_mdl & 2) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          debug_mdl & 2,
          4,
          "cam_context_handle_crm_process_evt",
          257,
          "No crm process evt in dev %d, state %d",
          *(unsigned int *)(a1 + 60));
        v5 = 0;
      }
    }
    mutex_unlock(a1 + 72);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_crm_process_evt",
      246,
      "Context is not ready");
    return (unsigned int)-22;
  }
  return v5;
}
