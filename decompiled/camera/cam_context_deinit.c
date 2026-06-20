__int64 __fastcall cam_context_deinit(_DWORD *a1)
{
  _DWORD *v1; // x19

  if ( !a1 )
    return 4294967274LL;
  if ( a1[60] != 1 )
  {
    v1 = a1;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_deinit",
      781,
      "Device did not shutdown cleanly");
    a1 = v1;
  }
  memset(a1, 0, 0x228u);
  return 0;
}
