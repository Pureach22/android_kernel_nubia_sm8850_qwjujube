__int64 __fastcall trace_raw_output_core_ctl_update_nr_need(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cpu=%d nr_need=%d nr_misfit_need=%d nrrun=%d nr_misfit_threshold=%u max_nr=%d strict_nrrun=%d nr_assist_need=%d nr"
      "_misfit_assist_need=%d nr_assist=%d nr_busy=%d min_nr_assist_misfit_threshold=%u\n",
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
      v1[12],
      v1[13]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
