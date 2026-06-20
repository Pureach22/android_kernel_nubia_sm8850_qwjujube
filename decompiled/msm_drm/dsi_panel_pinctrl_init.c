__int64 __fastcall dsi_panel_pinctrl_init(__int64 a1)
{
  unsigned int v1; // w20
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0

  if ( (*(_BYTE *)(a1 + 1274) & 1) != 0 || *(_BYTE *)(a1 + 2212) == 1 && !strcmp(*(const char **)(a1 + 8), "secondary") )
  {
    return 0;
  }
  else
  {
    v3 = devm_pinctrl_get(*(_QWORD *)(a1 + 1216));
    v1 = v3;
    *(_QWORD *)(a1 + 1616) = v3;
    if ( v3 && v3 < 0xFFFFFFFFFFFFF001LL )
    {
      v4 = pinctrl_lookup_state(v3, "panel_active");
      v1 = v4;
      *(_QWORD *)(a1 + 1632) = v4;
      if ( v4 && v4 < 0xFFFFFFFFFFFFF001LL )
      {
        v5 = pinctrl_lookup_state(*(_QWORD *)(a1 + 1616), "panel_active_with_esync");
        *(_QWORD *)(a1 + 1640) = v5;
        if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(a1 + 1640) = 0;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to get pinctrl active with esync state\n");
        }
        v6 = pinctrl_lookup_state(*(_QWORD *)(a1 + 1616), "panel_active_with_esync_without_te");
        *(_QWORD *)(a1 + 1648) = v6;
        if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
        {
          *(_QWORD *)(a1 + 1648) = 0;
          _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to get pinctrl active with esync without te state\n");
        }
        v7 = pinctrl_lookup_state(*(_QWORD *)(a1 + 1616), "panel_suspend");
        v1 = v7;
        *(_QWORD *)(a1 + 1656) = v7;
        if ( v7 && v7 < 0xFFFFFFFFFFFFF001LL )
        {
          v8 = pinctrl_lookup_state(*(_QWORD *)(a1 + 1616), "pwm_pin");
          *(_QWORD *)(a1 + 1664) = v8;
          if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
          {
            *(_QWORD *)(a1 + 1664) = 0;
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to get pinctrl pwm_pin");
          }
          v1 = 0;
          *(_QWORD *)(a1 + 1624) = 0;
        }
        else
        {
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: failed to get pinctrl suspend state, rc=%d\n",
            (unsigned int)v7);
        }
      }
      else
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: failed to get pinctrl active state, rc=%d\n",
          (unsigned int)v4);
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to get pinctrl, rc=%d\n", v3);
    }
  }
  return v1;
}
