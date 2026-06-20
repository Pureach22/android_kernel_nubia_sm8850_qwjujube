__int64 __fastcall wcd939x_reset(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // [xsp+0h] [xbp-20h] BYREF
  __int64 v5; // [xsp+8h] [xbp-18h] BYREF
  __int64 v6; // [xsp+10h] [xbp-10h]
  __int64 v7; // [xsp+18h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = 4294967277LL;
    goto LABEL_10;
  }
  v1 = *(_QWORD *)(a1 + 152);
  if ( !v1 )
  {
LABEL_9:
    result = 4294967274LL;
    goto LABEL_10;
  }
  if ( !*(_QWORD *)(v1 + 24) )
  {
    if ( (unsigned int)__ratelimit(&wcd939x_reset__rs, "wcd939x_reset") )
      dev_err(a1, "%s: reset gpio device node not specified\n", "wcd939x_reset");
    goto LABEL_9;
  }
  if ( (int)msm_cdc_pinctrl_get_state() <= 0 )
  {
    v5 = 30;
    v6 = 33;
    v4 = 0x7700000063LL;
    wcd_usbss_register_update(&v4, 1, 1);
    wcd_usbss_register_update(&v5, 0, 2);
    HIDWORD(v5) = HIDWORD(v5) & 0xFFFFFFF1 | 8;
    HIDWORD(v6) = HIDWORD(v6) & 0xFFFFFFF1 | 8;
    wcd_usbss_register_update(&v5, 1, 2);
    if ( (unsigned int)msm_cdc_pinctrl_select_sleep_state(*(_QWORD *)(v1 + 24)) )
    {
      if ( (unsigned int)__ratelimit(&wcd939x_reset__rs_114, "wcd939x_reset") )
        dev_err(a1, "%s: wcd sleep state request fail!\n", "wcd939x_reset");
    }
    else
    {
      usleep_range_state(80, 85, 2);
      if ( !(unsigned int)msm_cdc_pinctrl_select_active_state(*(_QWORD *)(v1 + 24)) )
      {
        usleep_range_state(80, 85, 2);
        wcd_usbss_set_ovp_threshold(6);
        goto LABEL_5;
      }
      if ( (unsigned int)__ratelimit(&wcd939x_reset__rs_116, "wcd939x_reset") )
        dev_err(a1, "%s: wcd active state request fail!\n", "wcd939x_reset");
    }
    result = 4294966779LL;
    goto LABEL_10;
  }
LABEL_5:
  result = 0;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
