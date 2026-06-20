__int64 __fastcall cam_cdm_pf_stream_off_all_clients(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w0
  __int64 i; // x21
  __int64 v5; // x23
  __int64 result; // x0
  unsigned int v7; // w20

  if ( !a1 )
    return 4294967274LL;
  v1 = *(_QWORD *)(a1 + 3680);
  if ( *(_DWORD *)(a1 + 88) )
  {
    if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_pf_stream_off_all_clients",
        505,
        "streaming off %s%u internally",
        (const char *)(v1 + 4),
        *(_DWORD *)(v1 + 132));
    v3 = cam_hw_cdm_pf_deinit(a1, 0, 0);
    if ( v3 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_pf_stream_off_all_clients",
        509,
        "Deinit failed in stream off rc: %d",
        v3);
    for ( i = 0; i != 2048; i += 8 )
    {
      v5 = *(_QWORD *)(v1 + 248 + i);
      if ( v5 )
      {
        mutex_lock(v5 + 280);
        *(_DWORD *)(v5 + 272) = 0;
        mutex_unlock(v5 + 280);
      }
    }
    result = cam_cpas_stop(*(_DWORD *)(v1 + 4868));
    if ( (_DWORD)result )
    {
      v7 = result;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        1,
        "cam_cdm_pf_stream_off_all_clients",
        523,
        "CPAS stop failed in stream off rc %d",
        result);
      result = v7;
    }
    *(_DWORD *)(a1 + 88) = 0;
  }
  else
  {
    if ( ((unsigned __int8)debug_mdl & (debug_priority == 0)) != 0 )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        1,
        4,
        "cam_cdm_pf_stream_off_all_clients",
        500,
        "%s%u already streamed off. Open count %d",
        (const char *)(v1 + 4),
        *(_DWORD *)(v1 + 132),
        0);
    return 0xFFFFFFFFLL;
  }
  return result;
}
