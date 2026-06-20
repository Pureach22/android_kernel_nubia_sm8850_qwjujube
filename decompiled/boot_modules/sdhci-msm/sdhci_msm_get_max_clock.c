__int64 __fastcall sdhci_msm_get_max_clock(__int64 a1)
{
  return clk_round_rate(*(_QWORD *)(a1 + 1456), -1);
}
