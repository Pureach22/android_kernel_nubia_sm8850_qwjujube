__int64 __fastcall zte_charger_policy_get_prop_by_name(__int64 a1, unsigned int a2, _DWORD *a3, __int64 a4)
{
  __int64 v7; // x0
  __int64 v8; // x3
  __int64 v9; // x22
  unsigned int property; // w0
  __int64 result; // x0
  unsigned int v12; // w21
  _QWORD v13[2]; // [xsp+0h] [xbp-10h] BYREF

  v13[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13[0] = 0;
  if ( a1 )
  {
    v7 = zte_power_supply_get_by_name();
    if ( v7 )
    {
      v9 = v7;
      property = zte_power_supply_get_property(v7, a2, v13);
      if ( (property & 0x80000000) != 0 )
      {
        v12 = property;
        printk(&unk_A4CB, "zte_charger_policy_get_prop_by_name", a1, a2);
        result = v12;
      }
      else
      {
        *a3 = v13[0];
        zte_power_supply_put(v9);
        result = 0;
      }
    }
    else
    {
      printk(&unk_A3BC, "zte_charger_policy_get_prop_by_name", a1, v8);
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_906B, "zte_charger_policy_get_prop_by_name", a3, a4);
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
