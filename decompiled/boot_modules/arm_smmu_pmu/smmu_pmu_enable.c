__int64 __fastcall smmu_pmu_enable(__int64 a1)
{
  return writel_relaxed(1, *(_QWORD *)(a1 + 328) + 3588LL);
}
