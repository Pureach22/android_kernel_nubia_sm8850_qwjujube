__int64 __fastcall dsi_display_link_clk_force_update_ctrl(__int64 a1)
{
  __int64 v2; // x19
  unsigned int updated; // w20

  if ( a1 )
  {
    mutex_lock(&dsi_mngr_clk_mutex);
    v2 = *(_QWORD *)(a1 + 80);
    if ( *(_DWORD *)(v2 + 384) == 1 )
    {
      updated = 0;
    }
    else
    {
      mutex_lock(v2 + 32);
      if ( *(_DWORD *)(v2 + 372) )
      {
        updated = dsi_clk_update_link_clk_state(v2, v2 + 216, 3, 0, 0);
        if ( !updated )
          updated = dsi_clk_update_link_clk_state(v2, v2 + 216, 3, 1, 1);
      }
      else
      {
        updated = -11;
      }
      mutex_unlock(v2 + 32);
    }
    mutex_unlock(&dsi_mngr_clk_mutex);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid arg\n");
    return (unsigned int)-22;
  }
  return updated;
}
