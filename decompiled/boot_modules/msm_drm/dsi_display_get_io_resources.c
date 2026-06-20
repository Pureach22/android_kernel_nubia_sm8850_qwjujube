__int64 __fastcall dsi_display_get_io_resources(__int64 a1, __int64 *a2)
{
  __int64 v2; // x21
  __int64 result; // x0
  unsigned int named_gpio; // w0
  unsigned int gpio_io_mem; // w0
  unsigned int v8; // w19
  unsigned int v9; // w0

  if ( !a2 )
    return 4294967274LL;
  v2 = *a2;
  if ( !*a2 )
    return 4294967274LL;
  result = dsi_ctrl_get_io_resources(a1);
  if ( !(_DWORD)result )
  {
    result = dsi_phy_get_io_resources(a1);
    if ( !(_DWORD)result )
    {
      result = dsi_panel_get_io_resources(a2[33], a1);
      if ( !(_DWORD)result )
      {
        named_gpio = of_get_named_gpio(*(_QWORD *)(v2 + 760), "qcom,platform-te-gpio", 0);
        if ( (named_gpio & 0x80000000) == 0 )
        {
          gpio_io_mem = msm_dss_get_gpio_io_mem(named_gpio, (_QWORD *)(a1 + 16));
          if ( gpio_io_mem )
          {
            v8 = gpio_io_mem;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to retrieve the te gpio address\n",
              *(_QWORD *)a2[33]);
            return v8;
          }
        }
        v9 = of_get_named_gpio(*(_QWORD *)(v2 + 760), "qcom,avdd-regulator-gpio", 0);
        if ( (v9 & 0x80000000) != 0 )
        {
          return 0;
        }
        else
        {
          result = msm_dss_get_gpio_io_mem(v9, (_QWORD *)(a1 + 16));
          if ( (_DWORD)result )
          {
            v8 = result;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to retrieve the avdd gpio address\n",
              *(_QWORD *)a2[33]);
            return v8;
          }
        }
      }
    }
  }
  return result;
}
