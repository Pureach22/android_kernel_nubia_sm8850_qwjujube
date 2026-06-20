__int64 __fastcall cam_context_handle_crm_dump_req(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x9
  unsigned int v5; // w20

  if ( a1 )
  {
    if ( *(_QWORD *)(a1 + 248) )
    {
      mutex_lock(a1 + 72);
      v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 128);
      if ( v4 )
      {
        if ( *((_DWORD *)v4 - 1) != 1801897041 )
          __break(0x8229u);
        v5 = v4(a1, a2);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "cam_context_handle_crm_dump_req",
          285,
          "No crm dump req for %s dev %d, state %d",
          (const char *)a1,
          *(_DWORD *)(a1 + 60),
          *(_DWORD *)(a1 + 240));
        v5 = 0;
      }
      mutex_unlock(a1 + 72);
      return v5;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        2,
        1,
        "cam_context_handle_crm_dump_req",
        275,
        "Context %s ctx_id %d is not ready",
        (const char *)a1,
        *(_DWORD *)(a1 + 32));
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_crm_dump_req",
      270,
      "Invalid Context");
    return 4294967274LL;
  }
}
