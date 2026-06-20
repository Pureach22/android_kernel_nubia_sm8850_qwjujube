__int64 __fastcall cam_cpas_get_slice_id(__int64 a1, unsigned int a2)
{
  __int64 v2; // x8
  int v3; // w6
  __int64 v4; // x8
  int v5; // w10
  __int64 v6; // x9
  __int64 result; // x0
  unsigned int v8; // [xsp+Ch] [xbp-4h]

  v2 = *(_QWORD *)(a1 + 3392);
  v3 = *(_DWORD *)(v2 + 1592);
  if ( a2 <= 0xD && v3 )
  {
    v4 = *(_QWORD *)(v2 + 1600);
    v5 = 0;
    while ( 1 )
    {
      v6 = v4 + ((__int64)v5 << 6);
      if ( *(_DWORD *)(v6 + 4) == a2 )
        break;
      if ( v3 == ++v5 )
        return 0xFFFFFFFFLL;
    }
    result = *(unsigned int *)(v6 + 24);
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      v8 = *(_DWORD *)(v6 + 24);
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_get_slice_id",
        4384,
        "Cache:%s type:%d scid:%d",
        *(_QWORD *)(v6 + 32));
      return v8;
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_get_slice_id",
      4376,
      "Invalid num_cache: %d or Invalid Cache Type: %d rc: %d",
      v3,
      a2,
      -22);
    return 0xFFFFFFFFLL;
  }
  return result;
}
