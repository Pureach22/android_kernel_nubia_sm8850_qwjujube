__int64 __fastcall stm_mmap_close(__int64 a1)
{
  __int64 v1; // x19

  v1 = **(_QWORD **)(*(_QWORD *)(a1 + 88) + 32LL);
  *(_QWORD *)(v1 + 520) = ktime_get_mono_fast_ns(a1);
  return _pm_runtime_suspend(v1, 13);
}
