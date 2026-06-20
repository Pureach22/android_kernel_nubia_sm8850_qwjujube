__int64 __fastcall zte_charger_policy_set_prop_by_name(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w22
  unsigned int v5; // w20
  __int64 v7; // x0
  __int64 v8; // x3
  __int64 v9; // x21
  unsigned int v10; // w0
  __int64 result; // x0
  unsigned int v12; // w21
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  if ( a1 )
  {
    v4 = a3;
    v5 = a2;
    v7 = zte_power_supply_get_by_name(a1, a2);
    if ( v7 )
    {
      v9 = v7;
      LODWORD(v13[0]) = v4;
      v10 = zte_power_supply_set_property(v7, v5, v13);
      if ( (v10 & 0x80000000) != 0 )
      {
        v12 = v10;
        printk(&unk_A4CB, "zte_charger_policy_set_prop_by_name", a1, v5);
        result = v12;
      }
      else
      {
        zte_power_supply_put(v9);
        result = 0;
      }
    }
    else
    {
      printk(&unk_A3BC, "zte_charger_policy_set_prop_by_name", a1, v8);
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_906B, "zte_charger_policy_set_prop_by_name", a3, a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
