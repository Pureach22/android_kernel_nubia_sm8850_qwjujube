__int64 __fastcall cam_cpas_deactivate_cache_slice(__int64 a1, unsigned int a2)
{
  __int64 v2; // x24
  int v5; // w20
  int v6; // w25
  unsigned int v7; // w27
  __int64 v8; // x26
  int v9; // w8

  v2 = *(_QWORD *)(a1 + 3392);
  v5 = *(_DWORD *)(v2 + 1592);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_deactivate_cache_slice",
      4427,
      "De-activate type: %d",
      a2);
    if ( a2 > 0xD )
      goto LABEL_20;
  }
  else if ( a2 > 0xD )
  {
LABEL_20:
    v7 = -22;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_deactivate_cache_slice",
      4432,
      "Invalid num_cache: %d or Invalid Cache Type: %d rc: %d",
      v5,
      a2,
      -22);
    return v7;
  }
  if ( !v5 )
    goto LABEL_20;
  v6 = 0;
  v7 = 0;
  do
  {
    v8 = *(_QWORD *)(v2 + 1600) + ((__int64)v6 << 6);
    if ( *(_DWORD *)(v8 + 4) == a2 )
    {
      mutex_lock(a1);
      if ( *(_DWORD *)v8 )
      {
        v9 = *(_DWORD *)v8 - 1;
        *(_DWORD *)v8 = v9;
        if ( v9 )
        {
          mutex_unlock(a1);
          v7 = 0;
          if ( (debug_mdl & 4) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 4,
              4,
              "cam_cpas_deactivate_cache",
              4228,
              "activate cnt for: %s non-zero: %d",
              *(const char **)(v8 + 32),
              *(_DWORD *)v8);
            v7 = 0;
          }
        }
        else
        {
          v7 = llcc_slice_deactivate(*(_QWORD *)(v8 + 40));
          if ( v7 )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              4,
              1,
              "cam_cpas_deactivate_cache",
              4235,
              "Failed to deactivate cache:%s",
              *(const char **)(v8 + 32));
          mutex_unlock(a1);
          if ( (debug_mdl & 4) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 4,
              4,
              "cam_cpas_deactivate_cache",
              4238,
              "De-activated cache:%s",
              *(const char **)(v8 + 32));
        }
      }
      else
      {
        mutex_unlock(a1);
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_deactivate_cache",
          4220,
          "Unbalanced deactivate");
        v7 = -14;
      }
    }
    ++v6;
  }
  while ( v5 != v6 );
  return v7;
}
