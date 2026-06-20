__int64 __fastcall charger_policy_status_forcedischging(__int64 a1)
{
  __int64 v3; // x0
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x20
  __int64 v7; // x3

  if ( (charger_policy_ctrl_charging_enable(a1, 0, 0) & 1) == 0 )
    alarm_try_to_cancel(a1 + 40);
  if ( (charger_policy_check_soc_reach_min(a1) & 1) != 0 )
  {
    v3 = ktime_get_with_offset(1);
    v4 = ns_to_timespec64(v3);
    v5 = *(_DWORD *)(a1 + 492);
    v6 = v4;
    *(_DWORD *)(a1 + 492) = 1;
    *(_DWORD *)(a1 + 496) = v5;
    charger_policy_ctrl_charging_enable(a1, 1, 1);
    *(_QWORD *)(a1 + 520) = v6;
    printk(&unk_9819, "charger_policy_status_forcedischging", v6, v7);
  }
  return 0;
}
