__int64 __fastcall lpi_pinctrl_ssr_enable(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x20

  if ( lpi_dev )
  {
    if ( (initial_boot & 1) != 0 )
    {
      return 0;
    }
    else
    {
      if ( (lpi_dev_up & 1) == 0 )
      {
        v2 = *(_QWORD *)(lpi_dev + 152);
        msleep(100);
        if ( *(_QWORD *)(v2 + 648) )
          digital_cdc_rsc_mgr_hw_vote_reset();
        if ( *(_QWORD *)(v2 + 656) )
          digital_cdc_rsc_mgr_hw_vote_reset();
      }
      result = 0;
      lpi_dev_up = 1;
    }
  }
  else
  {
    dev_err(a1, "%s: lpi_dev is NULL, return\n", "lpi_pinctrl_ssr_enable");
    return 4294967274LL;
  }
  return result;
}
