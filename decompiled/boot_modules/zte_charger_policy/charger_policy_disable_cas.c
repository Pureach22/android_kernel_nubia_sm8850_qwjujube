__int64 __fastcall charger_policy_disable_cas(__int64 a1, char a2, __int64 a3, __int64 a4)
{
  int v4; // w20
  __int64 v6; // x2
  __int64 v7; // x3
  __int64 v8; // x19
  __int64 v9; // x0
  __int64 v10; // x3
  __int64 v11; // x21
  unsigned int v12; // w0
  __int64 result; // x0
  __int64 v14; // x3
  unsigned int v15; // w19
  __int64 v16; // x2
  _QWORD v17[2]; // [xsp+0h] [xbp-10h] BYREF

  v4 = a2 & 1;
  v17[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  printk(&unk_A9CE, "charger_policy_disable_cas", a2 & 1, a4);
  v8 = *(_QWORD *)(a1 + 464);
  v17[0] = 0;
  if ( !v8 )
  {
    printk(&unk_906B, "charger_policy_set_prop_by_name", v6, v7);
    v15 = -22;
LABEL_9:
    result = printk(&unk_97EC, "charger_policy_disable_cas", v15, v14);
    goto LABEL_5;
  }
  v9 = power_supply_get_by_name(v8);
  if ( !v9 )
  {
    printk(&unk_A3BC, "charger_policy_set_prop_by_name", v8, v10);
    v15 = -22;
    goto LABEL_9;
  }
  v11 = v9;
  LODWORD(v17[0]) = v4;
  v12 = power_supply_set_property(v9, 5, v17);
  if ( (v12 & 0x80000000) != 0 )
  {
    v16 = v8;
    v15 = v12;
    printk(&unk_A4CB, "charger_policy_set_prop_by_name", v16, 5);
    goto LABEL_9;
  }
  result = power_supply_put(v11);
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
