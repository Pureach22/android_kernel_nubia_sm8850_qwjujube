__int64 __fastcall cam_context_handle_crm_link(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v4)(__int64, __int64); // x8
  unsigned int v5; // w20
  const char *v6; // x5
  __int64 v7; // x4

  if ( !*(_QWORD *)(a1 + 248) )
  {
    v6 = "Context is not ready";
    v7 = 107;
LABEL_9:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_crm_link",
      v7,
      v6);
    return 4294967274LL;
  }
  if ( !a2 )
  {
    v6 = "Invalid link payload";
    v7 = 112;
    goto LABEL_9;
  }
  mutex_lock(a1 + 72);
  v4 = *(__int64 (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 248) + 192LL * *(unsigned int *)(a1 + 240) + 80);
  if ( v4 )
  {
    if ( *((_DWORD *)v4 - 1) != 243265318 )
      __break(0x8228u);
    v5 = v4(a1, a2);
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_crm_link",
      121,
      "No crm link in dev %d, state %d",
      *(unsigned int *)(a1 + 60));
    v5 = -71;
  }
  mutex_unlock(a1 + 72);
  return v5;
}
