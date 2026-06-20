__int64 __fastcall lpi_pinctrl_ssr_disable(__int64 a1)
{
  lpi_dev_up = 0;
  return lpi_pinctrl_suspend(a1);
}
