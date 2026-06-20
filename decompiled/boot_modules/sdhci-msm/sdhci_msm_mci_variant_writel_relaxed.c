__int64 __fastcall sdhci_msm_mci_variant_writel_relaxed(__int64 a1, __int64 a2, unsigned int a3)
{
  return writel_relaxed(a1, *(_QWORD *)(a2 + 1416) + a3);
}
