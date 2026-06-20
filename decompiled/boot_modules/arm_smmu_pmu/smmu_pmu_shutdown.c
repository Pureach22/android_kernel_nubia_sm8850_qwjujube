__int64 __fastcall smmu_pmu_shutdown(__int64 a1)
{
  return writel_relaxed(0, *(_QWORD *)(*(_QWORD *)(a1 + 168) + 2480LL) + 3588LL);
}
