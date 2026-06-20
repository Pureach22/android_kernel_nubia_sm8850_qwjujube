__int64 __fastcall zte_misc_get_design_capacity(char *a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x2
  unsigned int v6; // w20
  __int64 v7; // x20
  unsigned int property; // w0
  __int64 v9; // x2
  __int64 result; // x0
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  v2 = power_supply_get_by_name("battery");
  if ( v2 )
  {
    v7 = v2;
    property = power_supply_get_property(v2, 22, v11);
    if ( property )
      printk(&unk_7C94, property, v9);
    power_supply_put(v7);
    if ( SLODWORD(v11[0]) <= 999999 )
      v6 = v11[0];
    else
      v6 = LODWORD(v11[0]) / 0x3E8;
  }
  else
  {
    printk(&unk_7BBC, v3, v4);
    v6 = 0;
  }
  printk(&unk_7BDF, v6, v5);
  result = snprintf(a1, 0x1000u, "%d", v6);
  _ReadStatusReg(SP_EL0);
  return result;
}
