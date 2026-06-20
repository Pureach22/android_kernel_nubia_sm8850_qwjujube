__int64 __fastcall battery_supply_callback(__int64 a1, __int64 a2, const char ***a3)
{
  if ( !strcmp(**a3, "battery") )
    queue_work_on(32, system_wq, bcl_perph + 32);
  return 1;
}
