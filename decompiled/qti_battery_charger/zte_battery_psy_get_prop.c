__int64 __fastcall zte_battery_psy_get_prop(__int64 a1, int a2, _DWORD *a3)
{
  __int64 drvdata; // x0
  __int64 v6; // x8

  drvdata = zte_power_supply_get_drvdata();
  if ( a2 == 3 )
  {
    v6 = 1046;
    goto LABEL_5;
  }
  if ( a2 == 4 )
  {
    v6 = 1047;
LABEL_5:
    *a3 = *(unsigned __int8 *)(drvdata + v6);
  }
  return 0;
}
