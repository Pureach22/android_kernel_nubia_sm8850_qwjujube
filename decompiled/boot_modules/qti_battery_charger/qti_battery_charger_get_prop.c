__int64 __fastcall qti_battery_charger_get_prop(const char *a1, int a2, _DWORD *a3)
{
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x20
  __int64 drvdata; // x0
  __int64 v9; // x19
  int v10; // w10
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  int v12; // [xsp+8h] [xbp-18h]
  __int64 v13; // [xsp+Ch] [xbp-14h]
  int v14; // [xsp+14h] [xbp-Ch]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 && (!strcmp(a1, "battery") || !strcmp(a1, "usb") || !strcmp(a1, "wireless")) )
  {
    v6 = power_supply_get_by_name(a1);
    if ( v6 && (v7 = v6, (drvdata = power_supply_get_drvdata()) != 0) )
    {
      v9 = drvdata;
      power_supply_put(v7);
      v10 = *(_DWORD *)(v9 + 388);
      v14 = 0;
      v13 = 0x1500000000LL;
      v11 = 0x10000800ALL;
      v12 = v10;
      result = battery_chg_write(v9, &v11, 24, 1000);
      if ( !(_DWORD)result )
        *a3 = *(_DWORD *)(*(_QWORD *)(v9 + 376) + 84LL);
    }
    else
    {
      result = 4294967277LL;
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
