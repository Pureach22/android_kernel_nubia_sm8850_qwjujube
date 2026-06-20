__int64 __fastcall charger_policy_demo_sts_set(const char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _BOOL8 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x2
  __int64 v9; // x3
  int v10; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( a2 )
  {
    sscanf(a1, "%d", &v11);
    v6 = v11 != 0;
    v11 = v11 != 0;
    printk(&unk_9EF3, "charger_policy_demo_sts_set", v6, v7);
    if ( v11 != *(unsigned __int8 *)(a2 + 537) )
    {
      printk(&unk_A163, "charger_policy_demo_sts_set", v8, v9);
      v10 = v11;
      *(_BYTE *)(a2 + 537) = v11 != 0;
      if ( !v10 )
      {
        _pm_stay_awake(*(_QWORD *)(a2 + 480));
        charger_policy_status_disable(a2);
        _pm_relax(*(_QWORD *)(a2 + 480));
      }
      queue_delayed_work_on(32, *(_QWORD *)(a2 + 160), a2 + 168, 25);
    }
    result = 0;
  }
  else
  {
    printk(&unk_9AE6, "charger_policy_demo_sts_set", a3, a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
