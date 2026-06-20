__int64 __fastcall trace_raw_output_adreno_hw_preempt_template(__int64 a1)
{
  _DWORD *v1; // x20
  __int64 result; // x0

  v1 = *(_DWORD **)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    trace_event_printf(
      a1,
      "cur_rb_lvl=%d rptr=%x wptr=%x rbbase=%x new_rb_lvl=%d rptr=%x wptr=%x rbbase=%x\n",
      v1[2],
      v1[4],
      v1[6],
      v1[8],
      v1[3],
      v1[5],
      v1[7],
      v1[9]);
    return trace_handle_return(a1 + 8352);
  }
  return result;
}
