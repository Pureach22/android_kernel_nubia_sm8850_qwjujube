__int64 __fastcall lmh_stats_driver_remove(__int64 a1)
{
  __int64 v1; // x19
  void (*v2)(void); // x8

  v1 = *(_QWORD *)(a1 + 168);
  v2 = *(void (**)(void))(*(_QWORD *)(*(_QWORD *)(cpufreq_get_driver_data() + 928) + 48LL) + 24LL);
  if ( *((_DWORD *)v2 - 1) != -1725305667 )
    __break(0x8228u);
  v2();
  return kobject_put(v1);
}
