__int64 __fastcall charger_policy_remove(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _QWORD *v4; // x19
  __int64 v5; // x2
  __int64 v6; // x3

  v4 = *(_QWORD **)(a1 + 168);
  printk(&unk_A494, "charger_policy_remove", a3, a4);
  if ( v4 )
  {
    power_supply_unreg_notifier(v4 + 2);
    wakeup_source_unregister(v4[60]);
    devm_kfree(*v4, v4);
  }
  return printk(&unk_A701, "charger_policy_remove", v5, v6);
}
