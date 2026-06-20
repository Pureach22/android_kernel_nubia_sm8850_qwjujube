__int64 __fastcall msm_vidc_process_drain_last_flag(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x4
  _QWORD v4[18]; // [xsp+0h] [xbp-90h] BYREF

  v4[17] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v4, 0, 136);
  result = msm_vidc_change_sub_state(a1, 0, 36, "msm_vidc_state_change_drain_last_flag");
  if ( !(_DWORD)result )
  {
    if ( *(_QWORD *)(a1 + 35768) )
    {
      LODWORD(v4[0]) = 2;
      v4l2_event_queue_fh(a1 + 1648, v4);
      result = 0;
    }
    else if ( a1 && (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_92F5D, "high", a1 + 340, "msm_vidc_process_drain_last_flag", v3);
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
