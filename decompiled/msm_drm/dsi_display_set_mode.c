__int64 __fastcall dsi_display_set_mode(__int64 a1, const void *a2)
{
  int v4; // w7
  __int64 v5; // x8
  unsigned int v6; // w20
  unsigned int v7; // w9
  int v8; // w21
  int v9; // w22
  __int64 v10; // x10
  __int64 v11; // x0
  int v12; // w9
  unsigned int v13; // w23
  __int64 result; // x0
  __int64 v15; // x26
  int v16; // w8
  unsigned int host_cfg_for_mode; // w0
  __int64 v18; // x3
  const char *v19; // x2
  unsigned int v20; // w28
  char v21; // w3
  __int64 v22; // x23
  __int64 *v23; // x27
  __int64 v24; // x8
  __int64 v25; // x9
  void (__fastcall *v26)(__int64, __int64); // x9
  unsigned int v27; // w8
  __int64 v28; // x8
  __int64 v29; // x9
  void (__fastcall *v30)(__int64, __int64); // x9
  unsigned int v31; // w8
  unsigned int v32; // w0
  int v33; // w8
  unsigned int v34; // w0
  int v35; // w6
  int v36; // w7
  unsigned int v37; // w23
  unsigned int v38; // w0
  int v39; // w6
  int v40; // w7
  unsigned int v41; // w8
  unsigned int v42; // w0
  __int64 v43; // x4
  __int64 v44; // x8
  unsigned int v45; // w27
  __int64 v46; // x0
  __int64 v47; // x9
  char v48; // w23
  unsigned int v49; // w2
  unsigned int v50; // w27
  unsigned int v51; // w0
  __int64 v52; // x0
  unsigned int v53; // w0
  _DWORD *v54; // x23
  size_t v55; // x0
  int v56; // w6
  int v57; // w7
  unsigned int updated; // w0
  unsigned int v59; // w8
  unsigned int v60; // w2
  unsigned int v61; // w23
  unsigned int v62; // w23
  unsigned __int64 StatusReg; // x23
  __int64 v64; // x24
  __int64 (__fastcall *v65)(_QWORD, _QWORD, _QWORD); // x0
  char v66; // [xsp+0h] [xbp-100h]
  _QWORD dest[24]; // [xsp+10h] [xbp-F0h] BYREF
  _QWORD v68[3]; // [xsp+D0h] [xbp-30h] BYREF
  __int64 v69; // [xsp+E8h] [xbp-18h]
  __int64 v70; // [xsp+F0h] [xbp-10h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(dest, 0, sizeof(dest));
  if ( !a1 || !a2 || !*(_QWORD *)(a1 + 264) )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    result = 4294967274LL;
    goto LABEL_79;
  }
  mutex_lock(a1 + 72);
  memcpy(dest, a2, sizeof(dest));
  v5 = *(_QWORD *)(a1 + 264);
  v6 = dest[0];
  if ( *(_BYTE *)(v5 + 1280) != 1 || (v7 = *(_DWORD *)(v5 + 1284), v7 <= 1) )
  {
    if ( *(_BYTE *)(dest[23] + 3400LL) == 1 )
    {
      *(_WORD *)(dest[23] + 2506LL) = dest[0];
      v5 = *(_QWORD *)(a1 + 264);
    }
    v7 = *(_DWORD *)(a1 + 160);
  }
  v8 = dest[3];
  v9 = HIDWORD(dest[5]);
  LODWORD(dest[0]) = v6 / v7;
  HIDWORD(dest[0]) /= v7;
  v10 = *(_QWORD *)(v5 + 1424);
  LODWORD(dest[1]) /= v7;
  HIDWORD(dest[1]) /= v7;
  LODWORD(dest[2]) /= v7;
  LODWORD(dest[19]) /= v7;
  if ( v10 )
    goto LABEL_12;
  v11 = _kmalloc_cache_noprof(_init_waitqueue_head, 3520, 192);
  while ( 1 )
  {
    *(_QWORD *)(*(_QWORD *)(a1 + 264) + 1424LL) = v11;
    v5 = *(_QWORD *)(a1 + 264);
    if ( !*(_QWORD *)(v5 + 1424) )
    {
      v13 = -12;
      goto LABEL_78;
    }
LABEL_12:
    v12 = *(_DWORD *)(a1 + 160);
    if ( v12
      && (*(_DWORD *)(a1 + 188) > 1u
       || *(_BYTE *)(a1 + 208) == 1
       || v12 != 1 && (*(_DWORD *)(a1 + 236) > 1u || (*(_BYTE *)(a1 + 256) & 1) != 0)) )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] mode cannot be set\n", *(const char **)(a1 + 32));
      v13 = -22;
      goto LABEL_78;
    }
    v15 = dest[23];
    if ( !dest[23] )
    {
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to get private info of the display mode\n",
        *(const char **)(a1 + 32));
      v13 = -22;
      goto LABEL_77;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_display_set_mode_sub",
      5583,
      -1,
      SHIDWORD(dest[19]),
      *(_DWORD *)(v5 + 1352),
      -1059143953,
      v4,
      v66);
    if ( (dest[19] & 0x8000000000LL) != 0 )
    {
      v16 = 1;
      goto LABEL_25;
    }
    if ( (dest[19] & 0x10000000000LL) != 0 )
    {
      v16 = 2;
LABEL_25:
      *(_DWORD *)(*(_QWORD *)(a1 + 264) + 1352LL) = v16;
    }
    host_cfg_for_mode = dsi_panel_get_host_cfg_for_mode(*(_QWORD *)(a1 + 264), dest, a1 + 888);
    if ( host_cfg_for_mode )
    {
      v18 = *(_QWORD *)(a1 + 32);
      v19 = "*ERROR* [msm-dsi-error]: [%s] failed to get host config for mode, rc=%d\n";
LABEL_28:
      v13 = host_cfg_for_mode;
      goto LABEL_76;
    }
    v20 = *(_DWORD *)(a1 + 836);
    *(_QWORD *)(a1 + 1192) = *(_QWORD *)(a1 + 1200);
    if ( v20 < 3 )
    {
      v21 = BYTE4(dest[19]);
      v22 = *(_QWORD *)(a1 + 264);
      if ( (dest[19] & 0x1200000000LL) == 0 )
      {
        v32 = 0;
        if ( (dest[19] & 0x2000000000LL) != 0 )
          goto LABEL_65;
        goto LABEL_88;
      }
      v23 = (__int64 *)(a1 + 168);
      if ( *(_DWORD *)(a1 + 160) )
      {
        if ( !v20 )
        {
          v24 = *v23;
          if ( *v23 )
          {
            v25 = *(unsigned int *)(v24 + 1608);
            if ( (unsigned int)v25 > 2 )
              goto LABEL_134;
            v26 = *(void (__fastcall **)(__int64, __int64))(v24 + 8 * v25 + 1152);
            if ( v26 )
            {
              if ( *((_DWORD *)v26 - 1) != 1642962683 )
                __break(0x8229u);
              v26(v24 + 96, 1);
            }
            ((void (__fastcall *)(_QWORD))dsi_phy_dynamic_refresh_clear)(*(_QWORD *)(a1 + 192));
            v27 = *(_DWORD *)(*(_QWORD *)(a1 + 168) + 88LL);
            if ( v27 >= 4 && v27 != 9 && *(_BYTE *)(v22 + 1400) == 1 )
              dsi_phy_dynamic_refresh_trigger_sel(*(_QWORD *)(a1 + 192), 1);
          }
        }
        if ( *(_DWORD *)(a1 + 160) >= 2u && v20 == 1 )
        {
          v28 = *(_QWORD *)(a1 + 216);
          if ( v28 )
          {
            v29 = *(unsigned int *)(v28 + 1608);
            if ( (unsigned int)v29 > 2 )
              goto LABEL_134;
            v30 = *(void (__fastcall **)(__int64, __int64))(v28 + 8 * v29 + 1152);
            if ( v30 )
            {
              if ( *((_DWORD *)v30 - 1) != 1642962683 )
                __break(0x8229u);
              v30(v28 + 96, 1);
            }
            ((void (__fastcall *)(_QWORD))dsi_phy_dynamic_refresh_clear)(*(_QWORD *)(a1 + 240));
            v31 = *(_DWORD *)(*(_QWORD *)(a1 + 216) + 88LL);
            if ( v31 >= 4 && v31 != 9 && *(_BYTE *)(v22 + 1400) == 1 )
              dsi_phy_dynamic_refresh_trigger_sel(*(_QWORD *)(a1 + 240), 1);
          }
        }
        v22 = *(_QWORD *)(a1 + 264);
      }
      v69 = 0;
      memset(v68, 0, sizeof(v68));
      if ( !v22 )
      {
        v13 = -22;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
        goto LABEL_75;
      }
      dsi_panel_get_dfps_caps(v22, v68);
      if ( (v69 & 0x100000000LL) == 0 && *(_BYTE *)(*(_QWORD *)(a1 + 264) + 1400LL) != 1 )
      {
        v13 = -524;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dfps or constant fps not supported\n");
        goto LABEL_75;
      }
      if ( LODWORD(v68[0]) == 2 )
      {
        v13 = -524;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dfps clock method not supported\n");
        goto LABEL_75;
      }
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: configuring seamless dynamic fps\n\n");
      sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_dfps_update", 5335, -1, 4369, -1059143953, v35, v36, v66);
      v37 = *(_DWORD *)(a1 + 836);
      if ( v37 < 3 )
        break;
    }
LABEL_134:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v64 = *(_QWORD *)(StatusReg + 80);
    v65 = _init_waitqueue_head;
    *(_QWORD *)(StatusReg + 80) = &dsi_display_set_mode__alloc_tag;
    v11 = _kmalloc_cache_noprof(v65, 3520, 192);
    *(_QWORD *)(StatusReg + 80) = v64;
  }
  v38 = dsi_ctrl_async_timing_update(v23[6 * v37], dest);
  if ( v38 )
  {
    v13 = v38;
    drm_dev_printk(
      0,
      &unk_248D72,
      "*ERROR* [msm-dsi-error]: [%s] failed to dfps update host_%d, rc=%d\n",
      *(_QWORD *)(a1 + 32),
      0);
    goto LABEL_73;
  }
  v41 = *(_DWORD *)(a1 + 160);
  if ( v41 )
  {
    if ( v37 && *v23 )
    {
      v42 = dsi_ctrl_async_timing_update(*v23, dest);
      if ( v42 )
      {
        v13 = v42;
        v43 = 0;
LABEL_117:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to dfps update host_%d, rc=%d\n",
          *(_QWORD *)(a1 + 32),
          v43);
LABEL_73:
        sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_dfps_update", 5370, -1, 8738, -1059143953, v39, v40, v66);
LABEL_75:
        v18 = *(_QWORD *)(a1 + 32);
        v19 = "*ERROR* [msm-dsi-error]: [%s]DSI dfps update failed, rc=%d\n";
LABEL_76:
        drm_dev_printk(0, &unk_248D72, v19, v18);
LABEL_77:
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to set mode\n", *(const char **)(a1 + 32));
        goto LABEL_78;
      }
      v41 = *(_DWORD *)(a1 + 160);
    }
    if ( v41 > 1 && v37 != 1 )
    {
      v52 = *(_QWORD *)(a1 + 216);
      if ( v52 )
      {
        v53 = dsi_ctrl_async_timing_update(v52, dest);
        if ( v53 )
        {
          v13 = v53;
          v43 = 1;
          goto LABEL_117;
        }
      }
    }
  }
  v54 = *(_DWORD **)(*(_QWORD *)(a1 + 264) + 1424LL);
  memcpy(v54, dest, 0xC0u);
  v55 = sde_dbg_base_evtlog;
  v54[39] = 0;
  sde_evtlog_log(v55, "dsi_display_dfps_update", 5370, -1, 8738, -1059143953, v56, v57, v66);
  if ( *(_DWORD *)(a1 + 160) )
  {
    updated = dsi_ctrl_update_host_config(
                *(_QWORD *)(a1 + 168),
                (int *)(a1 + 888),
                (__int64)dest,
                SBYTE4(dest[19]),
                *(_QWORD *)(a1 + 1320));
    if ( updated )
    {
LABEL_120:
      v13 = updated;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to update ctrl config\n");
      goto LABEL_77;
    }
    v59 = *(_DWORD *)(a1 + 160);
    if ( v59 > 1 )
    {
      updated = dsi_ctrl_update_host_config(
                  *(_QWORD *)(a1 + 216),
                  (int *)(a1 + 888),
                  (__int64)dest,
                  SBYTE4(dest[19]),
                  *(_QWORD *)(a1 + 1320));
      if ( updated )
        goto LABEL_120;
      v59 = *(_DWORD *)(a1 + 160);
    }
    v32 = 0;
    if ( v59 )
    {
      v60 = *(_DWORD *)(v15 + 2368);
      if ( v60 )
      {
        v61 = dsi_phy_set_timing_params(*(_QWORD *)(a1 + 192), *(_QWORD *)(v15 + 2360), v60, 0);
        if ( v61 )
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Fail to add timing params\n");
        v32 = v61;
        if ( *(_DWORD *)(a1 + 160) >= 2u )
        {
          v32 = dsi_phy_set_timing_params(*(_QWORD *)(a1 + 240), *(_QWORD *)(v15 + 2360), *(_DWORD *)(v15 + 2368), 0);
          if ( v32 )
          {
            v62 = v32;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Fail to add timing params\n");
            v32 = v62;
          }
        }
      }
    }
  }
  else
  {
    v32 = 0;
  }
  v21 = BYTE4(dest[19]);
  if ( (dest[19] & 0x2000000000LL) == 0 )
    goto LABEL_103;
  v22 = *(_QWORD *)(a1 + 264);
LABEL_65:
  v33 = *(_DWORD *)(v22 + 1352);
  if ( v33 == 2 )
  {
    v32 = dsi_display_dynamic_clk_configure_cmd(a1, LODWORD(dest[6]));
    if ( v32 )
    {
      v13 = v32;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to configure dynamic clk\n");
      goto LABEL_77;
    }
    v21 = BYTE4(dest[19]);
    goto LABEL_88;
  }
  if ( v33 != 1 )
  {
LABEL_88:
    if ( *(_DWORD *)(a1 + 160) )
    {
      host_cfg_for_mode = dsi_ctrl_update_host_config(
                            *(_QWORD *)(a1 + 168),
                            (int *)(a1 + 888),
                            (__int64)dest,
                            v21,
                            *(_QWORD *)(a1 + 1320));
      if ( host_cfg_for_mode
        || *(_DWORD *)(a1 + 160) >= 2u
        && (host_cfg_for_mode = dsi_ctrl_update_host_config(
                                  *(_QWORD *)(a1 + 216),
                                  (int *)(a1 + 888),
                                  (__int64)dest,
                                  SBYTE4(dest[19]),
                                  *(_QWORD *)(a1 + 1320))) != 0 )
      {
        v18 = *(_QWORD *)(a1 + 32);
        v19 = "*ERROR* [msm-dsi-error]: [%s] failed to update ctrl config, rc=%d\n";
        goto LABEL_28;
      }
      v21 = BYTE4(dest[19]);
      v32 = 0;
    }
    if ( (v21 & 8) != 0 && (v44 = *(_QWORD *)(a1 + 264), *(_DWORD *)(v44 + 1352) == 2) )
    {
      v45 = v32;
      v46 = *(_QWORD *)(v44 + 1424);
      v47 = *(_QWORD *)(v46 + 48);
      if ( !(v47 | dest[6]) || v47 != dest[6] )
      {
        *(_DWORD *)(a1 + 864) = 1;
        v46 = *(_QWORD *)(v44 + 1424);
      }
      dsi_display_validate_dms_fps(v46, dest);
      v48 = 1;
      v32 = v45;
    }
    else
    {
      v48 = 0;
    }
    v49 = *(_DWORD *)(v15 + 2368);
    if ( v49 && !*(_DWORD *)(a1 + 864) && *(_DWORD *)(a1 + 160) )
    {
      v32 = dsi_phy_set_timing_params(*(_QWORD *)(a1 + 192), *(_QWORD *)(v15 + 2360), v49, v48);
      if ( v32 )
      {
        v50 = v32;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to add DSI PHY timing params\n");
        v32 = v50;
      }
      if ( *(_DWORD *)(a1 + 160) >= 2u )
      {
        v51 = dsi_phy_set_timing_params(*(_QWORD *)(a1 + 240), *(_QWORD *)(v15 + 2360), *(_DWORD *)(v15 + 2368), v48);
        if ( v51 )
        {
          v13 = v51;
          drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to add DSI PHY timing params\n");
          goto LABEL_77;
        }
        goto LABEL_104;
      }
    }
LABEL_103:
    v13 = v32;
    if ( v32 )
      goto LABEL_77;
    goto LABEL_104;
  }
  v34 = dsi_display_dynamic_clk_switch_vid(a1, dest);
  if ( v34 )
  {
    v13 = v34;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: dynamic clk change failed %d\n", v34);
    goto LABEL_77;
  }
LABEL_104:
  *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 264) + 2312LL) + 40LL) = v9;
  drm_dev_printk(
    0,
    &unk_2597DF,
    "[msm-dsi-info]: mdp_transfer_time=%d, hactive=%d, vactive=%d, fps=%d, clk_rate=%llu\n",
    *(_DWORD *)(dest[23] + 2384LL),
    v6,
    v8,
    v9,
    *(_QWORD *)(dest[23] + 2408LL));
  sde_evtlog_log(
    sde_dbg_base_evtlog,
    "dsi_display_set_mode",
    8585,
    -1,
    *(_DWORD *)(dest[23] + 2384LL),
    v6,
    v8,
    v9,
    *(_QWORD *)(dest[23] + 2408LL));
  memcpy(*(void **)(*(_QWORD *)(a1 + 264) + 1424LL), dest, 0xC0u);
  v13 = 0;
LABEL_78:
  mutex_unlock(a1 + 72);
  result = v13;
LABEL_79:
  _ReadStatusReg(SP_EL0);
  return result;
}
