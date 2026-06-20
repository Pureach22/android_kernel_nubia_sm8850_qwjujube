__int64 __fastcall dbg_sensors_open(__int64 a1, __int64 a2)
{
  return single_open(a2, dbg_sensors_show, *(_QWORD *)(a1 + 696));
}
