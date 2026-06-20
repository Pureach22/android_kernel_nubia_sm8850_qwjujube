__int64 __fastcall charger_policy_check_usb_present(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x3
  __int64 v4; // x2
  __int64 v5; // x3
  __int64 v6; // x21
  __int64 v7; // x3
  unsigned int v8; // w19
  __int64 v9; // x3
  __int64 v10; // x2
  __int64 v11; // x3
  int v12; // w21
  __int64 v13; // x3
  __int64 v14; // x2
  __int64 v15; // x3
  int v16; // w20
  __int64 v17; // x0
  __int64 v18; // x3
  __int64 v19; // x22
  int v20; // w23
  _BOOL4 v21; // w8
  __int64 v23; // x2
  __int64 v24; // x3
  __int64 v25; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v26[2]; // [xsp+10h] [xbp-10h] BYREF

  v26[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v25 = 0;
  v26[0] = 0;
  v2 = power_supply_get_by_name("usb");
  if ( !v2 )
  {
    printk(&unk_A3BC, "charger_policy_get_prop_by_name", "usb", v3);
LABEL_5:
    printk(&unk_A308, "charger_policy_check_usb_present", v4, v5);
    v8 = 0;
    goto LABEL_7;
  }
  v6 = v2;
  if ( (power_supply_get_property(v2, 4, v26) & 0x80000000) != 0 )
  {
    printk(&unk_AD62, "charger_policy_get_prop_by_name", "usb", 4);
    goto LABEL_5;
  }
  v8 = v26[0];
  power_supply_put(v6);
LABEL_7:
  printk(&unk_A00C, "charger_policy_check_usb_present", v8, v7);
  if ( (zte_charger_policy_get_prop_by_name(*(_QWORD *)(a1 + 456), 0x11u, (_DWORD *)&v25 + 1, v9) & 0x80000000) != 0 )
    printk(&unk_AC76, "charger_policy_check_usb_present", v10, v11);
  v12 = HIDWORD(v25);
  printk(&unk_9C51, "charger_policy_check_usb_present", HIDWORD(v25), v11);
  if ( (zte_charger_policy_get_prop_by_name(*(_QWORD *)(a1 + 456), 0x12u, &v25, v13) & 0x80000000) != 0 )
    printk(&unk_95C4, "charger_policy_check_usb_present", v14, v15);
  v16 = v25;
  printk(&unk_993C, "charger_policy_check_usb_present", (unsigned int)v25, v15);
  v26[0] = 0;
  v17 = power_supply_get_by_name("wireless");
  if ( v17 )
  {
    v19 = v17;
    if ( (power_supply_get_property(v17, 4, v26) & 0x80000000) == 0 )
    {
      v20 = v26[0];
      power_supply_put(v19);
      v21 = v20 != 0;
      goto LABEL_14;
    }
    printk(&unk_AD62, "charger_policy_get_prop_by_name", "wireless", 4);
  }
  else
  {
    printk(&unk_A3BC, "charger_policy_get_prop_by_name", "wireless", v18);
  }
  printk(&unk_A308, "charger_policy_check_usb_present", v23, v24);
  v21 = 0;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v12 | v8 | v16 || v21;
}
