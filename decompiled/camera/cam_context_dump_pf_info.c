__int64 __fastcall cam_context_dump_pf_info(__int64 a1, __int64 a2)
{
  unsigned int v4; // w7
  __int64 v5; // x8
  __int64 (__fastcall *v6)(__int64, __int64); // x9
  unsigned int v7; // w20
  const char *v8; // x5
  __int64 v9; // x4
  int v11; // w0

  if ( !a2 )
  {
    v8 = "PF args is NULL";
    v9 = 320;
LABEL_14:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_dump_pf_info",
      v9,
      v8);
    return 4294967274LL;
  }
  if ( !a1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_dump_pf_info",
      325,
      "Context is NULL");
    if ( *(_BYTE *)(a2 + 49) == 1 )
    {
      v11 = cam_context_send_pf_evt(0, a2);
      if ( v11 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          2,
          1,
          "cam_context_dump_pf_info",
          330,
          "Failed to notify PF event to userspace rc: %d",
          v11);
        return 4294967274LL;
      }
    }
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(a1 + 248) )
  {
    v8 = "Context is not ready";
    v9 = 336;
    goto LABEL_14;
  }
  mutex_lock(a1 + 72);
  v4 = *(_DWORD *)(a1 + 240);
  v5 = a1;
  if ( v4 - 2 <= 3 )
  {
    v6 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * v4 + 144);
    if ( v6 )
    {
      if ( *((_DWORD *)v6 - 1) != 1863972096 )
        __break(0x8229u);
      v7 = v6(a1, a2);
      v5 = a1;
      goto LABEL_18;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      2,
      2,
      "cam_context_dump_pf_info",
      348,
      "No dump ctx in dev %d, state %d",
      *(unsigned int *)(a1 + 60));
    v5 = a1;
  }
  v7 = 0;
LABEL_18:
  mutex_unlock(v5 + 72);
  return v7;
}
