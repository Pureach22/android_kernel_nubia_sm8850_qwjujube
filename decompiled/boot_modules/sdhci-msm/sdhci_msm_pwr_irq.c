__int64 __fastcall sdhci_msm_pwr_irq(int a1, __int64 a2)
{
  sdhci_msm_handle_pwr_irq(a2, a1);
  *(_BYTE *)(a2 + 1600) = 1;
  _wake_up(a2 + 1576, 3, 1, 0);
  return 1;
}
