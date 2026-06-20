__int64 __fastcall sdhci_msm_mci_variant_readl_relaxed(__int64 a1, unsigned int a2)
{
  return readl_relaxed(*(_QWORD *)(a1 + 1416) + a2);
}
