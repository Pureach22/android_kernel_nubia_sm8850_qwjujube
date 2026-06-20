__int64 __fastcall cam_sync_get_obj_ref(unsigned int a1)
{
  __int64 v2; // x22
  __int64 v3; // x20
  __int64 result; // x0
  unsigned int v11; // w9

  if ( a1 - 2048 < 0xFFFFF801 )
    return 4294967274LL;
  v2 = a1;
  raw_spin_lock(sync_dev + 4LL * a1 + 136);
  v3 = *(_QWORD *)(sync_dev + 128) + 216LL * a1;
  if ( *(_DWORD *)(v3 + 104) != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_get_obj_ref",
      558,
      "Error: accessing an uninitialized sync obj = %s[%d]",
      (const char *)(*(_QWORD *)(sync_dev + 128) + 216LL * a1),
      a1);
    cam_sync_dump_monitor_array(v3);
    raw_spin_unlock(sync_dev + 4 * v2 + 136);
    return 4294967274LL;
  }
  _X8 = (unsigned int *)(v3 + 176);
  __asm { PRFM            #0x11, [X8] }
  do
    v11 = __ldxr(_X8);
  while ( __stxr(v11 + 1, _X8) );
  raw_spin_unlock(sync_dev + 4 * v2 + 136);
  result = 0;
  if ( (debug_mdl & 0x80) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      (unsigned __int8)debug_mdl & 0x80,
      4,
      "cam_sync_get_obj_ref",
      565,
      "get ref for obj %d",
      a1);
    return 0;
  }
  return result;
}
