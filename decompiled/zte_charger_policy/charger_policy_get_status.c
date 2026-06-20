bool charger_policy_get_status()
{
  __int64 v0; // x0
  __int64 v1; // x3
  __int64 v2; // x19
  int v3; // w20
  _BOOL8 result; // x0
  _QWORD v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  v0 = power_supply_get_by_name("policy");
  if ( !v0 )
  {
    printk(&unk_A3BC, "charger_policy_get_prop_by_name", "policy", v1);
LABEL_7:
    result = 0;
    goto LABEL_4;
  }
  v2 = v0;
  if ( (power_supply_get_property(v0, 5, v5) & 0x80000000) != 0 )
  {
    printk(&unk_AD62, "charger_policy_get_prop_by_name", "policy", 5);
    goto LABEL_7;
  }
  v3 = v5[0];
  power_supply_put(v2);
  result = v3 != 0;
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
