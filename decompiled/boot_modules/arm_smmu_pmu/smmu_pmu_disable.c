__int64 __fastcall smmu_pmu_disable(__int64 a1)
{
  return writel_relaxed(0, *(_QWORD *)(a1 + 328) + 3588LL);
}
