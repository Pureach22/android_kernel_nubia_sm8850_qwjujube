__int64 __fastcall htc_dump_counter_info(__int64 result)
{
  if ( result )
  {
    if ( (dword_B0B4 & 1) != 0 )
      return qdf_trace_msg(
               56,
               2,
               "%s: \n%s: ce_send_cnt = %d, TX_comp_cnt = %d\n",
               "htc_dump_counter_info",
               "htc_dump_counter_info",
               *(_DWORD *)(result + 3488),
               *(_DWORD *)(result + 3492));
  }
  return result;
}
