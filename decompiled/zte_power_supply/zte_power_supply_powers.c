__int64 __fastcall zte_power_supply_powers(__int64 a1, __int64 a2)
{
  return sysfs_create_link(a1 + 56, a2, "powers");
}
