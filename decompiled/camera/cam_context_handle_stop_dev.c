__int64 __fastcall cam_context_handle_stop_dev(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x9
  unsigned int v5; // w20
  const char *v6; // x5
  __int64 v7; // x4

  if ( !a1 || !*(_QWORD *)(a1 + 248) )
  {
    v6 = "Context is not ready";
    v7 = 602;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_stop_dev",
      v7,
      v6);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v6 = "Invalid stop device command payload";
    v7 = 607;
    goto LABEL_9;
  }
  mutex_lock(a1 + 72);
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 32);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -767372301 )
      __break(0x8229u);
    v5 = v4(a1, a2);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      2,
      "cam_context_handle_stop_dev",
      618,
      "No stop device in dev %d, name %s state %d",
      *(_DWORD *)(a1 + 60),
      (const char *)a1,
      *(_DWORD *)(a1 + 240));
    v5 = 0;
  }
  *(_DWORD *)(a1 + 464) = 0;
  mutex_unlock(a1 + 72);
  return v5;
}
