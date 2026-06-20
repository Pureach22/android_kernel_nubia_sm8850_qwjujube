__int64 __fastcall cnss_mhi_pm_runtime_put_autosuspend(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned int *v8; // x19
  __int64 v9; // x20

  v8 = *(unsigned int **)(*(_QWORD *)(a1 + 8) + 152LL);
  if ( v8 )
  {
    v9 = *(_QWORD *)v8;
    *(_QWORD *)(v9 + 720) = ktime_get_mono_fast_ns(a1);
  }
  return cnss_pci_pm_runtime_put_autosuspend(v8, 1u, a3, a4, a5, a6, a7, a8);
}
