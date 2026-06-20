__int64 __fastcall cam_context_handle_info_dump(__int64 a1, unsigned int a2)
{
  _DWORD *v4; // x8
  unsigned int v5; // w21

  if ( a1 && *(_QWORD *)(a1 + 248) )
  {
    mutex_lock(a1 + 72);
    v4 = *(_DWORD **)(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 152);
    if ( v4 )
    {
      if ( *(v4 - 1) != -1997778068 )
        __break(0x8228u);
      v5 = ((__int64 (__fastcall *)(__int64, _QWORD))v4)(a1, a2);
      mutex_unlock(a1 + 72);
      if ( v5 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          2,
          "cam_context_handle_info_dump",
          646,
          "Dump for id %u failed on ctx_id %u name %s state %d",
          a2,
          *(_DWORD *)(a1 + 32),
          (const char *)a1,
          *(_DWORD *)(a1 + 240));
        return v5;
      }
    }
    else
    {
      mutex_unlock(a1 + 72);
    }
    return 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_info_dump",
      633,
      "Context is not ready");
    return 4294967274LL;
  }
}
