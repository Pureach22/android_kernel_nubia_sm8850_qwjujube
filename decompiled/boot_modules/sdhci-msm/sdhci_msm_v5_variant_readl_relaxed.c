__int64 __fastcall sdhci_msm_v5_variant_readl_relaxed(__int64 a1, unsigned int a2)
{
  return readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 24) + a2));
}
