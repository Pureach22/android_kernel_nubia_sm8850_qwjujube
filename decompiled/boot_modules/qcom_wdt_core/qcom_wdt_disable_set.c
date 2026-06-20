__int64 __fastcall qcom_wdt_disable_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x20
  int v6; // w0
  __int64 v7; // x1
  __int64 v8; // x0
  int v9; // w0
  int v11; // w21
  _BYTE v12[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v13; // [xsp+8h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 152);
  v12[0] = 0;
  v6 = kstrtou8(a3, 10, v12);
  if ( v6 )
  {
    v11 = v6;
    dev_err(*(_QWORD *)(v5 + 8), "invalid user input\n");
    a4 = v11;
  }
  else if ( v12[0] == 1 )
  {
    v8 = mutex_lock(v5 + 56);
    if ( (*(_BYTE *)(v5 + 208) & 1) != 0 )
    {
      v9 = qcom_scm_sec_wdog_deactivate(v8);
      if ( v9 )
        dev_err(*(_QWORD *)(v5 + 8), "Failed to deactivate secure wdog, ret = %d\n", v9);
      qcom_wdt_disable(v5);
    }
    else
    {
      dev_err(*(_QWORD *)(v5 + 8), "MSM Apps Watchdog already disabled\n");
    }
    mutex_unlock(v5 + 56);
  }
  else
  {
    printk(&unk_7BBA, v7);
    a4 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}
