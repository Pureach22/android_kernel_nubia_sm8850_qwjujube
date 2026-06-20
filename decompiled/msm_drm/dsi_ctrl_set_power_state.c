__int64 __fastcall dsi_ctrl_set_power_state(__int64 a1, unsigned int a2)
{
  const char *v5; // x3
  unsigned int v6; // w0
  __int64 v7; // x3
  const char *v8; // x2
  unsigned int v9; // w21

  if ( a1 && a2 < 2 )
  {
    if ( *(_DWORD *)(a1 + 1608) == 1 )
      return 0;
    mutex_lock(a1 + 32);
    v6 = dsi_ctrl_check_state(a1, 0, a2);
    if ( v6 )
    {
      v7 = *(_QWORD *)(a1 + 16);
      v8 = "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n";
LABEL_9:
      v9 = v6;
      drm_dev_printk(0, &unk_248D72, v8, v7);
LABEL_10:
      mutex_unlock(a1 + 32);
      return v9;
    }
    if ( a2 == 1 )
    {
      v6 = dsi_ctrl_enable_supplies(a1, 1);
      if ( v6 )
      {
        v7 = *(_QWORD *)(a1 + 16);
        v8 = "*ERROR* [msm-dsi-error]: %s: failed to enable voltage supplies, rc=%d\n";
        goto LABEL_9;
      }
    }
    else
    {
      v6 = dsi_ctrl_enable_supplies(a1, 0);
      if ( v6 )
      {
        v7 = *(_QWORD *)(a1 + 16);
        v8 = "*ERROR* [msm-dsi-error]: %s: failed to disable vreg supplies, rc=%d\n";
        goto LABEL_9;
      }
    }
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Power state updated to %d\n", *(const char **)(a1 + 16), a2);
    v9 = 0;
    *(_DWORD *)(a1 + 1612) = a2;
    goto LABEL_10;
  }
  if ( a1 )
    v5 = *(const char **)(a1 + 16);
  else
    v5 = "inv";
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid Params\n", v5);
  return 4294967274LL;
}
