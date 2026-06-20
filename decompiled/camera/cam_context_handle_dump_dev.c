__int64 __fastcall cam_context_handle_dump_dev(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x9
  unsigned int v5; // w20
  __int64 v7; // x7
  const char *v8; // x5
  __int64 v9; // x4

  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_dump_dev",
      657,
      "Invalid Context");
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 248) )
  {
    v7 = *(unsigned int *)(a1 + 32);
    v8 = "Context %s ctx_id %d is not ready";
    v9 = 663;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_dump_dev",
      v9,
      v8,
      a1,
      v7);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v7 = *(unsigned int *)(a1 + 32);
    v8 = "Context %s ctx_id %d Invalid dump command payload";
    v9 = 670;
    goto LABEL_14;
  }
  mutex_lock(a1 + 72);
  if ( (debug_mdl & 2) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 2,
      4,
      "cam_context_handle_dump_dev",
      676,
      "dump device in dev %d, name %s state %d",
      *(_DWORD *)(a1 + 60),
      (const char *)a1,
      *(_DWORD *)(a1 + 240));
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 64);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != -1498240764 )
      __break(0x8229u);
    v5 = v4(a1, a2);
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      2,
      2,
      "cam_context_handle_dump_dev",
      682,
      "No dump device in dev %d, name %s state %d",
      *(_DWORD *)(a1 + 60),
      (const char *)a1,
      *(_DWORD *)(a1 + 240));
    v5 = 0;
  }
  mutex_unlock(a1 + 72);
  return v5;
}
