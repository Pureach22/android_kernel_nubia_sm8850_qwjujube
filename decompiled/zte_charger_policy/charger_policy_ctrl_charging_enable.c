__int64 __fastcall charger_policy_ctrl_charging_enable(__int64 a1, char a2, char a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x3
  _BOOL4 v11; // w22
  __int64 v13; // x2
  __int64 v14; // x3
  void *v15; // x0
  unsigned int v16; // w22
  __int64 result; // x0
  unsigned int v18; // w23
  unsigned int v19; // w21
  unsigned int v20; // w20
  unsigned int v21; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v22; // [xsp+10h] [xbp-10h] BYREF
  int v23; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 440);
  v21 = 0;
  v22 = 0;
  v23 = 0;
  if ( (charger_policy_get_prop_by_name(v7, 0, &v23, a4) & 0x80000000) != 0 )
  {
    printk(&unk_A299, "charger_policy_battery_is_charging", v8, v9);
    v11 = 0;
  }
  else
  {
    v11 = v23 == 1 || v23 == 4;
    printk(&unk_A4FF, "charger_policy_battery_is_charging", v11, v9);
  }
  printk(&unk_ABB7, "charger_policy_ctrl_charging_enable", v11, v10);
  if ( (zte_charger_policy_get_prop_by_name(*(_QWORD *)(a1 + 448), 3, &v21) & 0x80000000) != 0 )
  {
    v15 = &unk_90FC;
  }
  else
  {
    v16 = v21;
    printk(&unk_ABD9, "charger_policy_ctrl_charging_enable", v21, v14);
    if ( (zte_charger_policy_get_prop_by_name(*(_QWORD *)(a1 + 448), 4, &v22) & 0x80000000) != 0 )
    {
      v15 = &unk_913F;
    }
    else
    {
      v18 = v22;
      printk(&unk_A9EE, "charger_policy_ctrl_charging_enable", v22, v14);
      v19 = a3 & 1;
      v20 = a2 & 1;
      if ( v16 == v19 )
      {
        if ( v18 != v20 )
          printk(&unk_AA1D, "charger_policy_ctrl_charging_enable", v16, v16);
      }
      else
      {
        printk(&unk_AA1D, "charger_policy_ctrl_charging_enable", v16, v19);
        if ( (zte_charger_policy_set_prop_by_name(*(_QWORD *)(a1 + 448), 3, v19) & 0x80000000) != 0 )
        {
          v15 = &unk_922E;
          goto LABEL_14;
        }
      }
      if ( v18 == v20 || (zte_charger_policy_set_prop_by_name(*(_QWORD *)(a1 + 448), 4, v20) & 0x80000000) == 0 )
      {
        result = 1;
        goto LABEL_21;
      }
      v15 = &unk_9F18;
    }
  }
LABEL_14:
  printk(v15, "charger_policy_ctrl_charging_enable", v13, v14);
  result = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}
