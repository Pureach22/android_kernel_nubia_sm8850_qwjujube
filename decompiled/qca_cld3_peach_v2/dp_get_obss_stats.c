__int64 __fastcall dp_get_obss_stats(__int64 a1, char a2, void *a3, unsigned int *a4)
{
  __int64 v4; // x19
  __int64 result; // x0
  int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( a2 )
    return 4;
  v4 = *(_QWORD *)(a1 + 72);
  if ( !v4 )
    return 4;
  if ( (*(_BYTE *)(v4 + 96264) & 1) != 0 )
    return 3;
  *(_BYTE *)(v4 + 96264) = 1;
  *a4 = 23;
  a4[5] = 64;
  qdf_event_reset(v4 + 96224);
  result = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _BYTE))dp_h2t_ext_stats_msg_send)(
             v4,
             *a4,
             a4[1],
             a4[2],
             a4[3],
             a4[4],
             0,
             a4[5],
             *((_BYTE *)a4 + 24));
  if ( !(_DWORD)result )
  {
    v8 = qdf_wait_single_event(v4 + 96224, 0x64u);
    if ( v8 )
    {
      if ( v8 == 15 )
        qdf_trace_msg(0x38u, 8u, "%s: TIMEOUT_OCCURS", v9, v10, v11, v12, v13, v14, v15, v16, "dp_get_obss_stats");
      result = 15;
    }
    else
    {
      qdf_mem_copy(a3, (const void *)(v4 + 7944), 0x80u);
      result = 0;
    }
  }
  *(_BYTE *)(v4 + 96264) = 0;
  return result;
}
