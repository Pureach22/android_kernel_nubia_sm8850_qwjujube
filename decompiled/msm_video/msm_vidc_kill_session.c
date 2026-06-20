__int64 __fastcall msm_vidc_kill_session(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v7; // x19

  if ( *(_DWORD *)(a1 + 332) )
  {
    if ( a1 && (msm_vidc_debug & 1) != 0 )
    {
      v7 = a1;
      printk(&unk_83660, "err ", a1 + 340, "msm_vidc_kill_session", a5);
      a1 = v7;
    }
    v5 = a1;
    msm_vidc_session_close(a1);
    msm_vidc_change_state(v5, 5, "msm_vidc_kill_session");
  }
  else if ( a1 && (msm_vidc_debug & 1) != 0 )
  {
    printk(&unk_93064, "err ", a1 + 340, "msm_vidc_kill_session", a5);
  }
  return 0;
}
