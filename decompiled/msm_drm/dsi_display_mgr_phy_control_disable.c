__int64 __fastcall dsi_display_mgr_phy_control_disable(__int64 a1, int a2)
{
  int v4; // w7
  __int64 *v5; // x8
  __int64 *v6; // x21
  __int64 *v7; // x8
  unsigned int v8; // w22
  __int64 v9; // x23
  __int64 v10; // x24
  __int64 v11; // x22
  int v12; // w5
  int v13; // w4
  int v14; // w6
  unsigned int v16; // w0
  int v17; // w0
  unsigned int v18; // w0
  int v19; // w0
  unsigned int v20; // w0
  char v21; // [xsp+0h] [xbp+0h]
  char v22; // [xsp+0h] [xbp+0h]

  mutex_lock(&unk_29BAC8);
  v5 = &disp_mgr;
  while ( 1 )
  {
    v5 = (__int64 *)*v5;
    if ( v5 == &disp_mgr )
      break;
    if ( *((_BYTE *)v5 + 800) == 1 )
    {
      v6 = v5 - 6;
      goto LABEL_6;
    }
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: master display not found\n");
  v6 = nullptr;
LABEL_6:
  v7 = &disp_mgr;
  do
  {
    v7 = (__int64 *)*v7;
    if ( v7 == &disp_mgr )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: slave display not found\n");
      v8 = -22;
      goto LABEL_17;
    }
  }
  while ( (v7[100] & 1) != 0 );
  v8 = -22;
  if ( v6 && v7 != &_ksymtab_dss_reg_dump )
  {
    v9 = *(_QWORD *)(a1 + 192);
    v10 = v6[24];
    v11 = v7[18];
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_control_disable", 322, -1, 4369, a2, -1059143953, v4, v21);
    v12 = *(_DWORD *)(v9 + 28) - 1;
    *(_DWORD *)(v9 + 28) = v12;
    v13 = *(unsigned __int8 *)(a1 + 848);
    v14 = *(_DWORD *)(v10 + 28);
    if ( (v13 & 1) == 0 )
    {
      *(_DWORD *)(v10 + 28) = --v14;
      v13 = *(unsigned __int8 *)(a1 + 848);
      v12 = *(_DWORD *)(v9 + 28);
    }
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_control_disable", 330, -1, v13, v12, v14, -1059143953, v22);
    if ( *(_DWORD *)(v9 + 28) )
    {
LABEL_14:
      v8 = 0;
    }
    else if ( (*(_BYTE *)(a1 + 848) & 1) != 0 )
    {
      if ( *(_DWORD *)(v11 + 28) )
        goto LABEL_14;
      if ( a2 )
        v16 = ((__int64 (__fastcall *)(__int64))dsi_display_phy_idle_off)(a1);
      else
        v16 = dsi_display_phy_disable(a1);
      v8 = v16;
      if ( v16 )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable master, rc %d\n", v16);
    }
    else
    {
      if ( a2 )
      {
        v17 = ((__int64 (__fastcall *)(__int64))dsi_display_phy_idle_off)(a1);
        if ( v17 )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable slave%d\n", v17);
        if ( !*(_DWORD *)(v10 + 28) )
        {
          v18 = ((__int64 (__fastcall *)(__int64 *))dsi_display_phy_idle_off)(v6);
          if ( v18 )
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to phy_idle_off master, rc %d\n", v18);
        }
      }
      else
      {
        v19 = dsi_display_phy_disable(a1);
        if ( v19 )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable slave, rc %d\n", v19);
        if ( (*(_BYTE *)(v6[33] + 1973) & 1) == 0 )
        {
          v20 = dsi_display_phy_disable((__int64)v6);
          if ( v20 )
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable master, rc %d\n", v20);
        }
      }
      v8 = dsi_display_clk_ctrl_nolock(v6[165], 1, 0);
      if ( v8 )
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to disable core clk on master, rc %d\n", v8);
    }
    _drm_dev_dbg(
      0,
      0,
      0,
      "[msm-dsi-debug]: master: %d phy ref_cnt = %d m_phy ref_cnt = %d\n",
      *(unsigned __int8 *)(a1 + 848),
      *(_DWORD *)(v9 + 28),
      *(_DWORD *)(v10 + 28));
  }
LABEL_17:
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_control_disable", 394, -1, 8738, a2, -1059143953, v4, v21);
  mutex_unlock(&unk_29BAC8);
  return v8;
}
