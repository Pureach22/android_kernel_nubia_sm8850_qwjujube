__int64 __fastcall icnss_battery_supply_callback(__int64 a1, __int64 a2, const char ***a3)
{
  if ( !strcmp(**a3, "battery") && (*(_QWORD *)(a1 - 4016) & 1) != 0 && (*(_QWORD *)(a1 - 4016) & 0x2000) == 0 )
    queue_work_on(32, *(_QWORD *)(a1 + 72), a1 + 40);
  return 1;
}
