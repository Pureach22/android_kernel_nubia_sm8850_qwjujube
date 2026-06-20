__int64 __fastcall cam_sync_put_obj_ref(unsigned int a1)
{
  __int64 result; // x0
  unsigned int v9; // w10

  if ( a1 - 2048 < 0xFFFFF801 )
    return 4294967274LL;
  _X8 = (unsigned int *)(*(_QWORD *)(sync_dev + 128) + 216LL * a1 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 - 1, _X8) );
  result = 0;
  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int8)debug_mdl & 0x80,
      4,
      "cam_sync_put_obj_ref",
      584,
      "put ref for obj %d",
      a1);
    return 0;
  }
  return result;
}
