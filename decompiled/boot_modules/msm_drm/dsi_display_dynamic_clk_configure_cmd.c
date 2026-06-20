__int64 __fastcall dsi_display_dynamic_clk_configure_cmd(__int64 a1, __int64 a2)
{
  int v4; // w19
  int updated; // w0
  unsigned int v6; // w20

  if ( (int)a2 <= 0 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: bitrate should be greater than 0\n",
      "dsi_display_dynamic_clk_configure_cmd");
    return 4294967274LL;
  }
  else if ( *(_DWORD *)(a1 + 860) == (_DWORD)a2 )
  {
    drm_dev_printk(
      0,
      &unk_2597DF,
      "[msm-dsi-info]: %s: ignore duplicated DSI clk setting\n",
      "dsi_display_dynamic_clk_configure_cmd");
    return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 860) = a2;
    v4 = a2;
    updated = dsi_display_update_dsi_bitrate(a1, a2);
    if ( updated )
    {
      v6 = updated;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Failed to prepare to configure '%d'. rc = %d\n",
        "dsi_display_dynamic_clk_configure_cmd",
        v4,
        updated);
      *(_DWORD *)(a1 + 864) = 0;
      *(_DWORD *)(a1 + 860) = 0;
      return v6;
    }
    else
    {
      _drm_dev_dbg(
        0,
        0,
        0,
        "[msm-dsi-debug]: %s: bit clk is ready to be configured to '%d'\n",
        "dsi_display_dynamic_clk_configure_cmd",
        v4);
      *(_DWORD *)(a1 + 864) = 1;
      return 0;
    }
  }
}
