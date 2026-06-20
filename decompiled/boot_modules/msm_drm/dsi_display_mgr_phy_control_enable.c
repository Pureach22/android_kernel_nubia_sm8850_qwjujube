__int64 __fastcall dsi_display_mgr_phy_control_enable(__int64 a1, int a2)
{
  int v4; // w7
  __int64 v5; // x23
  __int64 *v6; // x25
  __int64 v7; // x24
  unsigned int v8; // w21
  unsigned int v9; // w0
  unsigned int v10; // w0
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  unsigned int v15; // w0
  unsigned int v16; // w0
  unsigned int v17; // w0
  unsigned int v18; // w0
  unsigned int v19; // w8
  __int64 v20; // x21
  char v21; // w0
  __int64 v22; // x21
  char v23; // w0
  __int64 v24; // x9
  __int64 v25; // x12
  __int64 v26; // x13
  __int64 v27; // x9
  __int64 v28; // x12
  __int64 v29; // x13
  __int64 v30; // x8
  __int64 v31; // x10
  unsigned int v32; // w8
  unsigned int v33; // w0
  char vars0; // [xsp+0h] [xbp+0h]

  mutex_lock(&unk_29BAC8);
  v5 = *(_QWORD *)(a1 + 192);
  v6 = &disp_mgr;
  do
  {
    v6 = (__int64 *)*v6;
    if ( v6 == &disp_mgr )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: master display not found\n");
      goto LABEL_10;
    }
  }
  while ( (v6[100] & 1) == 0 );
  if ( v6 == &_ksymtab_dss_reg_dump )
  {
LABEL_10:
    v8 = -22;
    goto LABEL_26;
  }
  v7 = v6[18];
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_control_enable", 127, -1, 4369, a2, -1059143953, v4, vars0);
  if ( *(_DWORD *)(v5 + 28) )
    goto LABEL_6;
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_mgr_phy_control_enable",
    138,
    -1,
    *(unsigned __int8 *)(a1 + 848),
    0,
    *(_DWORD *)(v7 + 28),
    -1059143953,
    vars0);
  if ( *(_BYTE *)(a1 + 848) != 1 )
  {
    v10 = dsi_display_clk_ctrl_nolock(v6[159], 1, 1);
    if ( v10 )
    {
      v8 = v10;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable core clk on master, rc %d\n", v10);
      goto LABEL_25;
    }
    if ( !*(_DWORD *)(v7 + 28) )
    {
      if ( *(_DWORD *)(v7 + 1176) )
      {
        v15 = ((__int64 (__fastcall *)(__int64 *, _QWORD, __int64))dsi_display_phy_idle_on)(
                v6 - 6,
                *(unsigned __int8 *)(a1 + 1219),
                1);
        if ( v15 )
        {
          v8 = v15;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to idle on master, rc %d\n", v15);
          goto LABEL_44;
        }
      }
      else
      {
        v17 = dsi_display_phy_sw_reset((__int64)(v6 - 6));
        if ( v17 )
        {
          v8 = v17;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to reset master, rc %d\n", v17);
          goto LABEL_44;
        }
        v24 = *(_QWORD *)(a1 + 916);
        v25 = *(_QWORD *)(a1 + 892);
        v26 = *(_QWORD *)(a1 + 900);
        *(__int64 *)((char *)v6 + 860) = *(_QWORD *)(a1 + 908);
        *(__int64 *)((char *)v6 + 868) = v24;
        *(__int64 *)((char *)v6 + 844) = v25;
        *(__int64 *)((char *)v6 + 852) = v26;
        v27 = *(_QWORD *)(a1 + 948);
        v28 = *(_QWORD *)(a1 + 924);
        v29 = *(_QWORD *)(a1 + 932);
        *(__int64 *)((char *)v6 + 892) = *(_QWORD *)(a1 + 940);
        *(__int64 *)((char *)v6 + 900) = v27;
        *(__int64 *)((char *)v6 + 876) = v28;
        *(__int64 *)((char *)v6 + 884) = v29;
        v30 = *(_QWORD *)(a1 + 964);
        v31 = *(_QWORD *)(a1 + 972);
        LODWORD(v27) = *(_DWORD *)(a1 + 980);
        *(__int64 *)((char *)v6 + 908) = *(_QWORD *)(a1 + 956);
        *((_DWORD *)v6 + 233) = v27;
        *(__int64 *)((char *)v6 + 916) = v30;
        *(__int64 *)((char *)v6 + 924) = v31;
        v32 = *((_DWORD *)v6 + 28);
        v6[143] = *(_QWORD *)(a1 + 1192);
        if ( v32 )
        {
          if ( v6 != (__int64 *)-120LL )
          {
            ((void (__fastcall *)(__int64, __int64, _QWORD))dsi_phy_update_phy_timings)(v6[18], a1 + 888, 0);
            v32 = *((_DWORD *)v6 + 28);
          }
          if ( v32 >= 2 && v6 != (__int64 *)-168LL )
            ((void (__fastcall *)(__int64, __int64, _QWORD))dsi_phy_update_phy_timings)(v6[24], a1 + 888, 0);
        }
        v33 = dsi_display_phy_enable((__int64)(v6 - 6), 1u);
        if ( v33 )
        {
          v8 = v33;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable master, rc %d\n", v33);
          dsi_display_clk_ctrl_nolock(v6[159], 1, 0);
          goto LABEL_44;
        }
      }
    }
    if ( a2 )
    {
      v12 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))dsi_display_phy_idle_on)(
              a1,
              *(unsigned __int8 *)(a1 + 1219),
              2);
      if ( v12 )
      {
        v8 = v12;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: error phy_idle_on slave phy, rc %d\n", v12);
LABEL_44:
        dsi_display_clk_ctrl_nolock(v6[159], 1, 0);
        goto LABEL_25;
      }
    }
    else
    {
      v16 = dsi_display_phy_sw_reset(a1);
      if ( v16 )
      {
        v8 = v16;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to reset slave, rc %d\n", v16);
        goto LABEL_44;
      }
      v18 = dsi_display_phy_enable(a1, 2u);
      if ( v18 )
      {
        v8 = v18;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable slave, rc %d\n", v18);
        goto LABEL_44;
      }
    }
    v19 = *(_DWORD *)(a1 + 160);
    if ( !v19 )
      goto LABEL_6;
    if ( a1 != -168 )
    {
      v20 = *(_QWORD *)(*(_QWORD *)(a1 + 192) + 1344LL);
      v21 = is_skip_op_required(a1);
      v8 = dsi_pll_program_slave(v20, v21 & 1);
      if ( v8 )
      {
LABEL_43:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to program slave %d\n", v8);
        goto LABEL_44;
      }
      v19 = *(_DWORD *)(a1 + 160);
    }
    if ( v19 < 2 )
      goto LABEL_6;
    if ( a1 == -216 )
      goto LABEL_6;
    v22 = *(_QWORD *)(*(_QWORD *)(a1 + 240) + 1344LL);
    v23 = is_skip_op_required(a1);
    v8 = dsi_pll_program_slave(v22, v23 & 1);
    if ( !v8 )
      goto LABEL_6;
    goto LABEL_43;
  }
  if ( !a2 )
  {
    v11 = dsi_display_phy_sw_reset(a1);
    if ( v11 )
    {
      v8 = v11;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to reset master, rc %d\n", v11);
      goto LABEL_25;
    }
    v13 = dsi_display_phy_enable(a1, 1u);
    if ( v13 )
    {
      v8 = v13;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to enable master, rc %d\n", v13);
      goto LABEL_25;
    }
LABEL_6:
    if ( (*(_BYTE *)(a1 + 848) & 1) == 0 )
      ++*(_DWORD *)(v7 + 28);
    v8 = 0;
    ++*(_DWORD *)(v5 + 28);
    goto LABEL_25;
  }
  v9 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))dsi_display_phy_idle_on)(
         a1,
         *(unsigned __int8 *)(a1 + 1219),
         1);
  if ( !v9 )
    goto LABEL_6;
  v8 = v9;
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to phy_idle_on master, rc %d\n", v9);
LABEL_25:
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: master: %d phy ref_cnt = %d m_phy ref_cnt = %d\n",
    *(unsigned __int8 *)(a1 + 848),
    *(_DWORD *)(v5 + 28),
    *(_DWORD *)(v7 + 28));
LABEL_26:
  sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_mgr_phy_control_enable", 291, -1, 8738, a2, -1059143953, v4, vars0);
  mutex_unlock(&unk_29BAC8);
  return v8;
}
