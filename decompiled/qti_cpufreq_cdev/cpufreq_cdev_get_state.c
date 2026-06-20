__int64 __fastcall cpufreq_cdev_get_state(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a1 + 944);
  *a2 = *(_QWORD *)(v2 + 32);
  return 0;
}
