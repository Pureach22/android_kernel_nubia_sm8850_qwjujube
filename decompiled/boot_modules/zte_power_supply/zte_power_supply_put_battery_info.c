__int64 __fastcall zte_power_supply_put_battery_info(__int64 result, __int64 a2)
{
  __int64 v3; // x19
  __int64 v4; // x21
  __int64 v5; // x22

  v3 = result;
  v4 = 0;
  v5 = a2 + 200;
  do
  {
    if ( *(_QWORD *)(v5 + v4) )
      result = devm_kfree(v3 + 56);
    v4 += 8;
  }
  while ( v4 != 160 );
  if ( *(_QWORD *)(a2 + 440) )
    return devm_kfree(v3 + 56);
  return result;
}
