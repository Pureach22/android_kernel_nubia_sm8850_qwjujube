__int64 __fastcall sdhci_msm_v5_variant_writel_relaxed(unsigned int a1, __int64 a2, unsigned int a3)
{
  return writel_relaxed(a1, (unsigned int *)(*(_QWORD *)(a2 + 24) + a3));
}
