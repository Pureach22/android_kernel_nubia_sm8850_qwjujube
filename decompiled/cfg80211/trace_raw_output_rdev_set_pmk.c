__int64 __fastcall trace_raw_output_rdev_set_pmk(__int64 a1)
{
  __int64 v1; // x23
  __int64 result; // x0
  int v4; // w20
  int v5; // w21
  const char *v6; // x22
  const char *v7; // x8

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(_DWORD *)(v1 + 56);
    v5 = *(unsigned __int8 *)(v1 + 66);
    v6 = (const char *)trace_print_array_seq(
                         a1 + 136,
                         v1 + (unsigned __int16)*(_DWORD *)(v1 + 68),
                         (unsigned __int16)HIWORD(*(_DWORD *)(v1 + 68)),
                         1);
    if ( *(_BYTE *)(v1 + 67) )
      v7 = (const char *)trace_print_array_seq(
                           a1 + 136,
                           v1 + (unsigned __int16)*(_DWORD *)(v1 + 72),
                           (unsigned __int16)HIWORD(*(_DWORD *)(v1 + 72)),
                           1);
    else
      v7 = (const char *)&unk_B6F9E;
    trace_event_printf(
      a1,
      "%s, netdev:%s(%d), %pMpmk_len=%u, pmk: %s pmk_r0_name: %s\n",
      (const char *)(v1 + 8),
      (const char *)(v1 + 40),
      v4,
      (const void *)(v1 + 60),
      v5,
      v6,
      v7);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
