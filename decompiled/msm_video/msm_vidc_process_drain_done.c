__int64 __fastcall msm_vidc_process_drain_done(__int64 a1)
{
  __int64 v2; // x4
  __int64 result; // x0

  if ( (is_sub_state(a1, 1) & 1) != 0 )
  {
    result = msm_vidc_change_sub_state(a1, 0, 16, "msm_vidc_process_drain_done");
    if ( (_DWORD)result )
      return result;
  }
  else if ( a1 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_867FA, "err ", a1 + 340, "msm_vidc_process_drain_done", v2);
  }
  return 0;
}
