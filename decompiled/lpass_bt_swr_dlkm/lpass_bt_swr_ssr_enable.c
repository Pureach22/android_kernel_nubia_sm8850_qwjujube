__int64 __fastcall lpass_bt_swr_ssr_enable(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  __int64 v4; // x20

  if ( *((_BYTE *)a2 + 153) == 1 )
  {
    *((_BYTE *)a2 + 153) = 0;
  }
  else
  {
    mutex_lock(a2 + 13);
    *((_BYTE *)a2 + 152) = 1;
    mutex_unlock(a2 + 13);
    mutex_lock(a2 + 7);
    if ( *((int *)a2 + 46) >= 1 )
    {
      v3 = a2[24];
      clk_disable(v3);
      clk_unprepare(v3);
      v4 = a2[25];
      if ( v4 )
      {
        clk_disable(a2[25]);
        clk_unprepare(v4);
      }
      if ( (msm_cdc_pinctrl_select_sleep_state(a2[40]) & 0x80000000) != 0
        && (unsigned int)__ratelimit(&lpass_bt_swr_ssr_enable__rs, "lpass_bt_swr_ssr_enable") )
      {
        dev_err(*a2, "%s: bt swr pinctrl disable failed\n", "lpass_bt_swr_ssr_enable");
      }
      lpass_bt_swr_mclk_enable(a2, 1);
      if ( (msm_cdc_pinctrl_select_active_state(a2[40]) & 0x80000000) != 0
        && (unsigned int)__ratelimit(&lpass_bt_swr_ssr_enable__rs_45, "lpass_bt_swr_ssr_enable") )
      {
        dev_err(*a2, "%s: bt swr pinctrl enable failed\n", "lpass_bt_swr_ssr_enable");
      }
    }
    mutex_unlock(a2 + 7);
    swrm_wcd_notify(*(_QWORD *)a2[26], 7, 0);
  }
  return 0;
}
