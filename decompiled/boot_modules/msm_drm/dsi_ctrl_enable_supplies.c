__int64 __fastcall dsi_ctrl_enable_supplies(__int64 a1, char a2)
{
  __int64 v4; // x21
  unsigned int v5; // w0
  unsigned int v6; // w19
  __int64 v7; // x21
  unsigned int v8; // w0
  unsigned int v9; // w0
  int v10; // w21
  int v11; // w22
  unsigned int v12; // w0
  unsigned int v13; // w8
  unsigned int v20; // w10
  int v21; // w7
  char *v22; // x1
  size_t v23; // x0
  int v24; // w2
  unsigned int v25; // w8
  unsigned int v28; // w10
  unsigned int v29; // w0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( *(_QWORD *)(a1 + 2432) )
  {
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: %s: skip phy regulator voting; AOSS voted w/CESTA, en:%d\n",
      *(const char **)(a1 + 16),
      a2 & 1);
    if ( (a2 & 1) == 0 )
    {
      v10 = *(unsigned __int8 *)(a1 + 2584);
      v11 = *(unsigned __int8 *)(a1 + 1648);
      sde_evtlog_log(sde_dbg_base_evtlog, "dsi_ctrl_aoss_update", 1200, -1, v10, v11, v11 | v10, -1059143953, vars0);
      v6 = sde_cesta_aoss_update(*(int **)(a1 + 2432), v11 | (unsigned int)v10);
      if ( !v6 )
        goto LABEL_27;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to update AOSS VCD, cp:%d, idle_pc:%d, rc:%d\n",
        *(const char **)(a1 + 16),
        v11 | v10,
        *(unsigned __int8 *)(a1 + 1648),
        v6);
      return v6;
    }
    v4 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL);
    v5 = _pm_runtime_resume(v4, 4);
    if ( (v5 & 0x80000000) == 0 )
    {
      v6 = sde_cesta_aoss_update(*(int **)(a1 + 2432), 4);
      if ( v6 )
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: failed to disable AOSS VCD, rc:%d\n",
          *(const char **)(a1 + 16),
          v6);
LABEL_27:
        _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL), 4);
        return v6;
      }
      return v6;
    }
    v13 = *(_DWORD *)(v4 + 480);
    v6 = v5;
    do
    {
      if ( !v13 )
        break;
      _X12 = (unsigned int *)(v4 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v20 = __ldxr(_X12);
        if ( v20 != v13 )
          break;
        if ( !__stlxr(v13 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v20 == v13;
      v13 = v20;
    }
    while ( !_ZF );
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to enable power resource %d\n",
      *(const char **)(a1 + 16),
      v5);
    v22 = "dsi_ctrl_aoss_update";
    v23 = sde_dbg_base_evtlog;
    v24 = 1187;
LABEL_41:
    sde_evtlog_log(v23, v22, v24, -1, v6, 60333, -1059143953, v21, vars0);
    return v6;
  }
  if ( (a2 & 1) == 0 )
  {
    v12 = dsi_pwr_enable_regulator((_DWORD *)(a1 + 2400), 0);
    if ( v12 )
    {
      v6 = v12;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to disable gdsc, rc=%d\n",
        *(const char **)(a1 + 16),
        v12);
    }
    else if ( (*(_BYTE *)(a1 + 1628) & 1) != 0 || (v29 = dsi_pwr_enable_regulator((_DWORD *)(a1 + 2416), 0)) == 0 )
    {
      _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL), 4);
      return 0;
    }
    else
    {
      v6 = v29;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to disable host power regs\n",
        *(const char **)(a1 + 16));
    }
    return v6;
  }
  v7 = *(_QWORD *)(*(_QWORD *)(a1 + 80) + 8LL);
  v8 = _pm_runtime_resume(v7, 4);
  if ( (v8 & 0x80000000) != 0 )
  {
    v25 = *(_DWORD *)(v7 + 480);
    v6 = v8;
    do
    {
      if ( !v25 )
        break;
      _X12 = (unsigned int *)(v7 + 480);
      __asm { PRFM            #0x11, [X12] }
      while ( 1 )
      {
        v28 = __ldxr(_X12);
        if ( v28 != v25 )
          break;
        if ( !__stlxr(v25 - 1, _X12) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v28 == v25;
      v25 = v28;
    }
    while ( !_ZF );
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to enable power resource %d\n",
      *(const char **)(a1 + 16),
      v8);
    v22 = "dsi_ctrl_enable_supplies";
    v23 = sde_dbg_base_evtlog;
    v24 = 1239;
    goto LABEL_41;
  }
  if ( (*(_BYTE *)(a1 + 1628) & 1) == 0 )
  {
    v9 = dsi_pwr_enable_regulator((_DWORD *)(a1 + 2416), 1);
    if ( v9 )
    {
      v6 = v9;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: failed to enable host power regs\n",
        *(const char **)(a1 + 16));
      goto LABEL_27;
    }
  }
  v6 = dsi_pwr_enable_regulator((_DWORD *)(a1 + 2400), 1);
  if ( v6 )
  {
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: %s: failed to enable gdsc, rc=%d\n",
      *(const char **)(a1 + 16),
      v6);
    dsi_pwr_enable_regulator((_DWORD *)(a1 + 2416), 0);
    goto LABEL_27;
  }
  return v6;
}
