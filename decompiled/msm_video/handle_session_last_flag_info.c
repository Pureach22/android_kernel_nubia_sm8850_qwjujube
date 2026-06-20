__int64 __fastcall handle_session_last_flag_info(__int64 a1, __int64 a2)
{
  __int64 v2; // x4
  unsigned int flag; // w20

  v2 = *(unsigned int *)(a2 + 4);
  if ( (_DWORD)v2 == 100663302 )
  {
    if ( (msm_vidc_allow_drain_last_flag(a1) & 1) != 0 )
    {
      flag = msm_vidc_process_drain_last_flag(a1);
      if ( !flag )
        return flag;
      goto LABEL_10;
    }
LABEL_9:
    flag = -22;
LABEL_10:
    msm_vidc_change_state(a1, 5u, (__int64)"handle_session_last_flag_info");
    return flag;
  }
  if ( (_DWORD)v2 == 100663303 )
  {
    if ( (msm_vidc_allow_psc_last_flag(a1) & 1) != 0 )
    {
      flag = msm_vidc_process_psc_last_flag(a1);
      if ( !flag )
        return flag;
      goto LABEL_10;
    }
    goto LABEL_9;
  }
  if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_91C6F, "err ", a1 + 340, "handle_session_last_flag_info", v2);
    return 0;
  }
  else
  {
    return 0;
  }
}
