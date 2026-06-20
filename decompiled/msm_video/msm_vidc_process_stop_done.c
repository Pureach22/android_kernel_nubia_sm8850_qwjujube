__int64 __fastcall msm_vidc_process_stop_done(__int64 a1, unsigned int a2)
{
  __int64 v4; // x4
  __int64 v5; // x4
  __int64 v6; // x2
  __int64 result; // x0

  if ( a2 == 1 )
  {
    v6 = 32;
  }
  else if ( a2 )
  {
    v6 = 0;
  }
  else
  {
    if ( (is_sub_state(a1, 2) & 1) != 0 && (is_sub_state(a1, 8) & 1) == 0 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_85954, "err ", a1 + 340, "msm_vidc_process_stop_done", v4);
      msm_vidc_change_state(a1, 5, "msm_vidc_process_stop_done");
    }
    if ( *(_DWORD *)(a1 + 308) == 2 && (is_sub_state(a1, 1) & 1) != 0 && (is_sub_state(a1, 4) & 1) == 0 )
    {
      if ( a1 && (msm_vidc_debug & 1) != 0 )
        printk(&unk_7F95A, "err ", a1 + 340, "msm_vidc_process_stop_done", v5);
      msm_vidc_change_state(a1, 5, "msm_vidc_process_stop_done");
    }
    v6 = 16;
  }
  result = msm_vidc_change_sub_state(a1, 0, v6, "msm_vidc_process_stop_done");
  if ( a2 <= 2 && !(_DWORD)result )
  {
    complete(a1 + 32LL * a2 + 37584);
    return 0;
  }
  return result;
}
