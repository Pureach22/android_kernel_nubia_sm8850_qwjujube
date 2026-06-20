__int64 __fastcall trace_raw_output_sde_perf_uidle_status(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "crtc:%d danger[0x%x, 0x%x] safe[0x%x, 0x%x] idle[0x%x, 0x%x] fal[0x%x, 0x%x] status:0x%x en_fal10:0x%x\n",
      v1[2],
      v1[3],
      v1[4],
      v1[5],
      v1[6],
      v1[7],
      v1[8],
      v1[9],
      v1[10],
      v1[11],
      v1[12]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
