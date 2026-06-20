__int64 __fastcall cam_cpas_activate_cache_slice(__int64 a1, unsigned int a2)
{
  __int64 v2; // x28
  int v5; // w20
  int v6; // w24
  unsigned int v7; // w26
  __int64 v8; // x22
  unsigned int v9; // w8

  v2 = *(_QWORD *)(a1 + 3392);
  v5 = *(_DWORD *)(v2 + 1592);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_activate_cache_slice",
      4400,
      "Activate type: %d",
      a2);
    if ( a2 > 0xD )
      goto LABEL_19;
  }
  else if ( a2 > 0xD )
  {
    goto LABEL_19;
  }
  if ( v5 )
  {
    v6 = 0;
    v7 = 0;
    while ( 1 )
    {
      v8 = *(_QWORD *)(v2 + 1600) + ((__int64)v6 << 6);
      if ( *(_DWORD *)(v8 + 4) == a2 )
      {
        mutex_lock(a1);
        v9 = *(_DWORD *)v8 + 1;
        *(_DWORD *)v8 = v9;
        if ( v9 >= 2 )
        {
          mutex_unlock(a1);
          v7 = 0;
          if ( (debug_mdl & 4) == 0 || debug_priority )
            goto LABEL_8;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_activate_cache",
            4190,
            "Cache: %s has already been activated cnt: %d",
            *(const char **)(v8 + 32),
            *(_DWORD *)v8);
          goto LABEL_17;
        }
        v7 = llcc_slice_activate(*(_QWORD *)(v8 + 40));
        if ( !v7 )
        {
          mutex_unlock(a1);
          if ( (debug_mdl & 4) == 0 || debug_priority )
            goto LABEL_8;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_activate_cache",
            4202,
            "Activated cache:%s",
            *(const char **)(v8 + 32));
LABEL_17:
          v7 = 0;
          goto LABEL_8;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_activate_cache",
          4197,
          "Failed to activate cache:%s",
          *(const char **)(v8 + 32));
        --*(_DWORD *)v8;
        mutex_unlock(a1);
      }
LABEL_8:
      if ( v5 == ++v6 )
        return v7;
    }
  }
LABEL_19:
  v7 = -22;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_activate_cache_slice",
    4405,
    "Invalid num_cache: %d or Invalid Cache Type: %d rc: %d",
    v5,
    a2,
    -22);
  return v7;
}
