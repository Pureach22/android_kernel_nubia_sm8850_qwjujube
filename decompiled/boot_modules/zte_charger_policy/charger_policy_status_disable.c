__int64 __fastcall charger_policy_status_disable(__int64 a1)
{
  charger_policy_ctrl_charging_enable(a1, 1, 1);
  *(_BYTE *)(a1 + 539) = 0;
  *(_QWORD *)(a1 + 520) = 0;
  *(_QWORD *)(a1 + 492) = 0;
  return charger_policy_disable_cas(a1, 0);
}
