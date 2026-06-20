__int64 __fastcall gpr_notifier_service_cb(__int64 a1, __int64 a2, __int64 a3)
{
  char v4; // w21
  __int64 v5; // x0

  if ( a3 )
  {
    if ( a2 == 1 )
    {
      if ( *(_DWORD *)(a3 + 4) != 1 )
      {
        if ( (unsigned int)__ratelimit(&gpr_adsp_up__rs, "gpr_adsp_up") )
          dev_info(*(_QWORD *)(gpr_priv + 8), "%s: Q6 is Up\n", "gpr_adsp_up");
        q6 = 2;
        snd_event_notify(*(_QWORD *)(gpr_priv + 8), 1);
      }
      raw_spin_lock(gpr_priv + 16);
      v5 = gpr_priv + 16;
      *(_BYTE *)(gpr_priv + 20) = 0;
      raw_spin_unlock(v5);
    }
    else if ( !a2 )
    {
      raw_spin_lock(gpr_priv + 16);
      v4 = *(_BYTE *)(gpr_priv + 20);
      raw_spin_unlock(gpr_priv + 16);
      if ( (v4 & 1) == 0 )
      {
        if ( *(_DWORD *)(a3 + 4) == 1 )
        {
          dword_7174 = 0;
        }
        else
        {
          if ( (unsigned int)__ratelimit(&gpr_adsp_down__rs, "gpr_adsp_down") )
            dev_info(*(_QWORD *)(gpr_priv + 8), "%s: Q6 is Down\n", "gpr_adsp_down");
          q6 = 0;
          snd_event_notify(*(_QWORD *)(gpr_priv + 8), 0);
        }
      }
    }
  }
  else if ( (unsigned int)__ratelimit(&gpr_notifier_service_cb__rs, "gpr_notifier_service_cb") )
  {
    dev_err(*(_QWORD *)(gpr_priv + 8), "%s: Callback data is NULL!\n", "gpr_notifier_service_cb");
  }
  return 1;
}
