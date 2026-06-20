__int64 __fastcall cam_common_util_get_string_index(__int64 a1, int a2, const char *a3, int *a4)
{
  int v8; // w21
  size_t v9; // x0

  if ( !a2 )
    return 4294967274LL;
  v8 = 0;
  while ( 1 )
  {
    v9 = strlen(*(const char **)(a1 + 8LL * v8));
    if ( strnstr(*(_QWORD *)(a1 + 8LL * v8), a3, v9) )
      break;
    if ( a2 == ++v8 )
      return 4294967274LL;
  }
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x20000,
      4,
      "cam_common_util_get_string_index",
      43,
      "matched %s : %d\n",
      a3,
      v8);
  *a4 = v8;
  return 0;
}
