__int64 __fastcall dsi_phy_set_power_state(__int64 a1, char a2)
{
  int v4; // w21
  unsigned int v5; // w20
  unsigned int v6; // w0
  unsigned int v7; // w0
  unsigned int v8; // w0

  if ( a1 )
  {
    v4 = a2 & 1;
    mutex_lock(a1 + 32);
    if ( *(unsigned __int8 *)(a1 + 1180) == v4 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: No state change\n", *(_DWORD *)(a1 + 8));
      v5 = 0;
LABEL_19:
      mutex_unlock(a1 + 32);
      return v5;
    }
    if ( (a2 & 1) != 0 )
    {
      v6 = dsi_pwr_enable_regulator(a1 + 784, 1);
      if ( v6 )
      {
LABEL_7:
        v5 = v6;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: failed to enable digital regulator\n",
          *(unsigned int *)(a1 + 8));
        goto LABEL_19;
      }
      if ( !*(_DWORD *)(a1 + 1176) && *(_BYTE *)(a1 + 1360) == 1 )
      {
        v8 = dsi_pwr_enable_regulator(a1 + 800, 1);
        if ( v8 )
        {
          v5 = v8;
          drm_dev_printk(
            0,
            &unk_248D72,
            "*ERROR* [msm-dsi-error]: DSI_%d: failed to enable phy power\n",
            *(_DWORD *)(a1 + 8));
          dsi_pwr_enable_regulator(a1 + 784, 0);
          goto LABEL_19;
        }
      }
    }
    else
    {
      if ( !*(_DWORD *)(a1 + 1176) && *(_BYTE *)(a1 + 1360) == 1 )
      {
        v6 = dsi_pwr_enable_regulator(a1 + 800, 0);
        if ( v6 )
          goto LABEL_7;
      }
      v7 = dsi_pwr_enable_regulator(a1 + 784, 0);
      if ( v7 )
      {
        v5 = v7;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: DSI_%d: failed to enable phy power\n",
          *(unsigned int *)(a1 + 8));
        goto LABEL_19;
      }
    }
    v5 = 0;
    *(_BYTE *)(a1 + 1180) = v4;
    goto LABEL_19;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: DSI_%d: Invalid params\n", -1);
  return (unsigned int)-22;
}
