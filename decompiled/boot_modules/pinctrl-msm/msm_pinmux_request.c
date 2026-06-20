__int64 __fastcall msm_pinmux_request(__int64 a1, unsigned int a2)
{
  __int64 drvdata; // x0

  drvdata = pinctrl_dev_get_drvdata();
  if ( (gpiochip_line_is_valid(drvdata + 16, a2) & 1) != 0 )
    return 0;
  else
    return 4294967274LL;
}
