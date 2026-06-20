__int64 __fastcall cam_cpas_notif_stalling_inc_cache_slice(__int64 a1, unsigned int a2)
{
  __int64 v2; // x28
  int v5; // w20
  int v6; // w25
  unsigned int v7; // w22
  __int64 v8; // x26
  __int64 v9; // x4
  const char *v10; // x5

  v2 = *(_QWORD *)(a1 + 3392);
  v5 = *(_DWORD *)(v2 + 1592);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_notif_stalling_inc_cache_slice",
      4526,
      "notification cache type: %d",
      a2);
    if ( a2 > 0xD )
      goto LABEL_17;
  }
  else if ( a2 > 0xD )
  {
LABEL_17:
    v7 = -22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_notif_stalling_inc_cache_slice",
      4531,
      "Invalid num_cache: %d or Invalid Cache Type: %d rc: %d",
      v5,
      a2,
      -22);
    return v7;
  }
  if ( !v5 )
    goto LABEL_17;
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = *(_QWORD *)(v2 + 1600) + ((__int64)v6 << 6);
    if ( *(_DWORD *)(v8 + 4) == a2 )
    {
      mutex_lock(a1);
      v7 = llcc_notif_staling_inc_counter(*(_QWORD *)(v8 + 40));
      if ( v7 )
      {
        if ( v7 == -95 )
        {
          v9 = 4317;
          v10 = "llcc notif stalling inc not supported: %s";
        }
        else
        {
          v9 = 4320;
          v10 = "Failed to llcc staling frame trigger:%s";
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_notif_stalling_inc_cache",
          v9,
          v10,
          *(_QWORD *)(v8 + 32));
      }
      mutex_unlock(a1);
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_notif_stalling_inc_cache",
          4324,
          "llcc staling frame triggered cache:%s",
          *(const char **)(v8 + 32));
    }
    ++v6;
  }
  while ( v5 != v6 );
  return v7;
}
