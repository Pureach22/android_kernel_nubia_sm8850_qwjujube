__int64 __fastcall cnss_mhi_pm_runtime_get_sync(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return cnss_pci_pm_runtime_get_sync(*(unsigned int **)(*(_QWORD *)(a1 + 8) + 152LL), 1u, a3, a4, a5, a6, a7, a8);
}
