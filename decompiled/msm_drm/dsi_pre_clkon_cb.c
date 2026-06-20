__int64 __fastcall dsi_pre_clkon_cb(__int64 a1, char a2, __int64 a3, int a4)
{
  __int64 result; // x0
  unsigned int v6; // w8
  __int64 v7; // x0
  int v8; // w0
  unsigned int v9; // w20
  __int64 v10; // x0
  int v11; // w0
  __int64 v12; // x0
  __int64 v13; // x9
  __int64 v14; // x0
  int v15; // w0
  __int64 v16; // x8
  __int64 v17; // x0
  int v18; // w0
  __int64 v19; // x0

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: invalid input\n", "dsi_pre_clkon_cb");
    return 4294967274LL;
  }
  result = 0;
  if ( (a2 & 1) != 0 && a4 == 1 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: updating power states for ctrl and phy\n");
    v6 = *(_DWORD *)(a1 + 160);
    if ( !v6 )
      goto LABEL_30;
    v7 = *(_QWORD *)(a1 + 168);
    if ( v7 )
    {
      v8 = dsi_ctrl_set_power_state(v7, 1u);
      if ( v8 )
      {
        v9 = v8;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] Failed to set power state, rc=%d\n",
          *(const char **)(*(_QWORD *)(a1 + 168) + 16LL),
          v8);
LABEL_8:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to power on dsi controllers, rc=%d\n",
          *(_QWORD *)(a1 + 32),
          v9);
        return v9;
      }
      v6 = *(_DWORD *)(a1 + 160);
    }
    if ( v6 >= 2 )
    {
      v10 = *(_QWORD *)(a1 + 216);
      if ( !v10 )
      {
LABEL_19:
        v13 = *(_QWORD *)(a1 + 168);
        if ( !v13 || (v14 = *(_QWORD *)(a1 + 192)) == 0 )
        {
LABEL_26:
          if ( v6 >= 2 )
          {
            v16 = *(_QWORD *)(a1 + 216);
            if ( v16 )
            {
              v17 = *(_QWORD *)(a1 + 240);
              if ( v17 )
              {
                if ( !*(_QWORD *)(v16 + 2432) )
                {
                  v18 = dsi_phy_set_power_state(v17, 1);
                  if ( v18 )
                  {
                    v9 = v18;
                    drm_dev_printk(
                      0,
                      &unk_248D72,
                      "*ERROR* [msm-dsi-error]: [%s] Failed to set power state, rc=%d\n",
                      *(const char **)(*(_QWORD *)(a1 + 240) + 16LL),
                      v18);
                    v19 = *(_QWORD *)(a1 + 192);
                    if ( v19 )
                      dsi_phy_set_power_state(v19, 0);
                    goto LABEL_24;
                  }
                }
              }
            }
          }
          goto LABEL_30;
        }
        if ( !*(_QWORD *)(v13 + 2432) )
        {
          v15 = dsi_phy_set_power_state(v14, 1);
          if ( v15 )
          {
            v9 = v15;
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] Failed to set power state, rc=%d\n",
              *(const char **)(*(_QWORD *)(a1 + 192) + 16LL),
              v15);
LABEL_24:
            drm_dev_printk(
              0,
              &unk_248D72,
              "*ERROR* [msm-dsi-error]: [%s] failed to power on dsi phy, rc = %d\n",
              *(_QWORD *)(a1 + 32),
              v9);
            return v9;
          }
          v6 = *(_DWORD *)(a1 + 160);
          goto LABEL_26;
        }
LABEL_30:
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Enable DSI core power\n", "dsi_pre_clkon_cb");
        return 0;
      }
      v11 = dsi_ctrl_set_power_state(v10, 1u);
      if ( v11 )
      {
        v9 = v11;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] Failed to set power state, rc=%d\n",
          *(const char **)(*(_QWORD *)(a1 + 216) + 16LL),
          v11);
        v12 = *(_QWORD *)(a1 + 168);
        if ( v12 )
          dsi_ctrl_set_power_state(v12, 0);
        goto LABEL_8;
      }
      v6 = *(_DWORD *)(a1 + 160);
    }
    if ( !v6 )
      goto LABEL_30;
    goto LABEL_19;
  }
  return result;
}
