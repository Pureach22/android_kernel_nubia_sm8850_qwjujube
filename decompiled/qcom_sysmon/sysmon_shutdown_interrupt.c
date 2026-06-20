__int64 __fastcall sysmon_shutdown_interrupt(__int64 a1, __int64 a2)
{
  complete(a2 + 312);
  return 1;
}
