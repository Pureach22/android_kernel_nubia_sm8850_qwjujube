__int64 __fastcall zte_devm_power_supply_release(__int64 a1, _QWORD *a2)
{
  return zte_power_supply_unregister(*a2);
}
