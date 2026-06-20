__int64 __fastcall cam_context_handle_message(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v2; // w7
  __int64 (*v3)(void); // x8

  v1 = *(_QWORD *)(a1 + 248);
  if ( !v1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      2,
      1,
      "cam_context_handle_message",
      362,
      "Context is not ready");
    return 4294967274LL;
  }
  v2 = *(_DWORD *)(a1 + 240);
  if ( v2 - 2 > 3 )
    return 0;
  v3 = *(__int64 (**)(void))(v1 + 192LL * v2 + 184);
  if ( !v3 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      2,
      2,
      "cam_context_handle_message",
      374,
      "No message handler for ctx %d, state %d msg_type :%d",
      *(unsigned int *)(a1 + 60));
    return 0;
  }
  if ( *((_DWORD *)v3 - 1) != 414296116 )
    __break(0x8228u);
  return v3();
}
