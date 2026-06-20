__int64 __fastcall qmp_combo_dp_power_off(__int64 a1)
{
  __int64 v1; // x19

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 208);
  writel(2u, (unsigned int *)(*(_QWORD *)(v1 + 120) + 24LL));
  mutex_unlock(v1 + 208);
  return 0;
}
