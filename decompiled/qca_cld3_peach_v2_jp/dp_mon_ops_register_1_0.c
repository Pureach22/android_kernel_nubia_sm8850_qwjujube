__int64 __fastcall dp_mon_ops_register_1_0(__int64 a1)
{
  *(_QWORD *)(a1 + 416) = &monitor_ops_1_0;
  return dp_mon_register_lpc_ops_1_0(&monitor_ops_1_0);
}
