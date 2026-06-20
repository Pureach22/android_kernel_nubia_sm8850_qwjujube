__int64 __fastcall dsi_ctrl_set_clock_source(__int64 a1, _QWORD *a2)
{
  int updated; // w0
  unsigned int v5; // w20
  const char *v6; // x3
  const char *v7; // x4

  if ( a1 && a2 )
  {
    mutex_lock(a1 + 32);
    if ( *(_DWORD *)(a1 + 1608) == 1 || (updated = dsi_clk_update_parent(a2, a1 + 2264)) == 0 )
    {
      v7 = *(const char **)(a1 + 16);
      *(_QWORD *)(a1 + 2344) = *a2;
      *(_QWORD *)(a1 + 2352) = a2[1];
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Source clocks are updated\n", v7);
      v5 = 0;
    }
    else
    {
      v5 = updated;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Failed to update link clk parent, rc=%d\n",
        *(const char **)(a1 + 16),
        updated);
      dsi_clk_update_parent(a1 + 2344, a1 + 2264);
    }
    mutex_unlock(a1 + 32);
  }
  else
  {
    if ( a1 )
      v6 = *(const char **)(a1 + 16);
    else
      v6 = "inv";
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", v6);
    return (unsigned int)-22;
  }
  return v5;
}
