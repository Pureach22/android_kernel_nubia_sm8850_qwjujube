__int64 __fastcall lim_update_pbc_session_entry(const void *a1, const void *a2, __int64 a3)
{
  unsigned __int64 v6; // x19
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x8
  _QWORD *v16; // x24
  __int64 v17; // x21
  __int64 result; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  _QWORD *v28; // x8
  __int64 v29; // x23

  v6 = qdf_mc_timer_get_system_ticks() / 0x3E8;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Receive WPS probe request curTime: %d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "lim_update_pbc_session_entry",
    (unsigned int)v6);
  ((void (__fastcall *)(__int64, __int64, const void *, __int64))qdf_trace_hex_dump)(53, 8, a1, 6);
  ((void (__fastcall *)(__int64, __int64, const void *, __int64))qdf_trace_hex_dump)(53, 8, a2, 16);
  v15 = *(_QWORD *)(a3 + 1944);
  if ( v15 )
  {
    v16 = nullptr;
    while ( 1 )
    {
      v17 = v15;
      if ( !(unsigned int)qdf_mem_cmp((const void *)(v15 + 8), a1, 6u) )
      {
        result = qdf_mem_cmp((const void *)(v17 + 14), a2, 0x10u);
        if ( !(_DWORD)result )
          break;
      }
      v15 = *(_QWORD *)v17;
      v16 = (_QWORD *)v17;
      if ( !*(_QWORD *)v17 )
        goto LABEL_8;
    }
    v27 = *(_QWORD *)v17;
    if ( v16 )
      *v16 = v27;
    else
      *(_QWORD *)(a3 + 1944) = v27;
  }
  else
  {
LABEL_8:
    result = _qdf_mem_malloc(0x28u, "lim_update_pbc_session_entry", 140);
    if ( !result )
      return result;
    v17 = result;
    result = (__int64)qdf_mem_copy((void *)(result + 8), a1, 6u);
    if ( a2 )
      result = (__int64)qdf_mem_copy((void *)(v17 + 14), a2, 0x10u);
  }
  *(_QWORD *)v17 = *(_QWORD *)(a3 + 1944);
  *(_QWORD *)(a3 + 1944) = v17;
  *(_DWORD *)(v17 + 32) = v6;
  while ( 1 )
  {
    v28 = (_QWORD *)v17;
    v17 = *(_QWORD *)v17;
    if ( !v17 )
      break;
    if ( *(_DWORD *)(v17 + 32) + 120 < (unsigned int)v6 )
    {
      *v28 = 0;
      do
      {
        v29 = *(_QWORD *)v17;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: WPS PBC sessions remove",
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          "lim_remove_timeout_pbc_sessions");
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v17 + 8, 6);
        ((void (__fastcall *)(__int64, __int64, __int64, __int64))qdf_trace_hex_dump)(53, 8, v17 + 14, 16);
        result = _qdf_mem_free(v17);
        v17 = v29;
      }
      while ( v29 );
      return result;
    }
  }
  return result;
}
