bool __fastcall zte_power_supply_match_device_node(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 96);
  return v2 && *(_QWORD *)(v2 + 744) == a2;
}
