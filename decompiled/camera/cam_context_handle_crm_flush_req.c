__int64 __fastcall cam_context_handle_crm_flush_req(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  unsigned int v5; // w20

  if ( *(_QWORD *)(a1 + 248) )
  {
    mutex_lock(a1 + 72);
    v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 112);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != 1826364657 )
        __break(0x8228u);
      v5 = v4(a1, a2);
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        2,
        3,
        "cam_context_handle_crm_flush_req",
        232,
        "No crm flush req in dev %d, state %d, name %s",
        *(unsigned int *)(a1 + 60));
      v5 = -71;
    }
    mutex_unlock(a1 + 72);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_crm_flush_req",
      222,
      "Context is not ready");
    return (unsigned int)-22;
  }
  return v5;
}
