unsigned __int64 __fastcall smp2p_sleepstate_probe(__int64 a1)
{
  __int64 v2; // x20
  unsigned __int64 result; // x0
  unsigned int v4; // w0
  unsigned __int64 v5; // x0
  unsigned __int64 StatusReg; // x9
  unsigned int v7; // w0
  int byname; // w0
  int v9; // w20
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 760);
  v10 = 0;
  result = qcom_smem_state_get(a1 + 16, 0, &v10);
  state_1 = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    qcom_smem_state_update_bits();
    v4 = qcom_smem_alloc(0xFFFFFFFFLL, 512, 32);
    v10 = v4;
    if ( (v4 & 0x80000000) == 0 || v4 == -17 )
    {
      v5 = qcom_smem_get(0xFFFFFFFFLL, 512, 0);
      state_0 = v5;
      if ( v5 < 0xFFFFFFFFFFFFF001LL )
      {
        *(_QWORD *)v5 = 1;
        *(_DWORD *)(v5 + 8) = 1;
        __isb(0xFu);
        StatusReg = _ReadStatusReg(CNTVCT_EL0);
        *(_QWORD *)(state_0 + 16) = StatusReg;
        __dsb(0xFu);
      }
      else
      {
        state_0 = 0;
        printk(&unk_6585);
      }
      printk(&unk_6539);
    }
    else
    {
      printk(&unk_64A8);
    }
    v7 = register_pm_notifier(&sleepstate_pm_nb);
    v10 = v7;
    if ( v7 )
    {
      dev_err(a1 + 16, "%s: power state notif error %d\n", "smp2p_sleepstate_probe", v7);
    }
    else
    {
      notify_ws = wakeup_source_register(a1 + 16, "smp2p-sleepstate");
      if ( notify_ws )
      {
        byname = of_irq_get_byname(v2, "smp2p-sleepstate-in");
        if ( byname <= 0 )
        {
          dev_err(a1 + 16, "failed to get irq for smp2p_sleep_state\n");
          v10 = -517;
        }
        else
        {
          v9 = byname;
          result = devm_request_threaded_irq(
                     a1 + 16,
                     (unsigned int)byname,
                     0,
                     smp2p_sleepstate_handler,
                     24579,
                     "smp2p_sleepstate",
                     a1 + 16);
          v10 = result;
          if ( !(_DWORD)result )
            goto LABEL_2;
          dev_err(a1 + 16, "fail to register smp2p threaded_irq=%d\n", v9);
        }
        wakeup_source_unregister(notify_ws);
      }
      else
      {
        v10 = -12;
      }
      unregister_pm_notifier(&sleepstate_pm_nb);
    }
    result = v10;
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
