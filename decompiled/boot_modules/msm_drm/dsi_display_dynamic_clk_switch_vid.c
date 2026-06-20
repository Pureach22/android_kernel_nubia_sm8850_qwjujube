__int64 __fastcall dsi_display_dynamic_clk_switch_vid(__int64 a1, __int64 a2)
{
  unsigned int v4; // w27
  _QWORD *v5; // x26
  _QWORD *v6; // x25
  unsigned int v7; // w8
  __int64 v8; // x8
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x28
  int updated; // w0
  unsigned int v13; // w24
  unsigned int v14; // w8
  _QWORD *v15; // x21
  unsigned int v16; // w9
  __int64 v17; // x23
  unsigned int v18; // w22
  __int64 v19; // x27
  _QWORD *v20; // x28
  int v21; // w21
  unsigned int v22; // w8
  unsigned int v23; // w0
  int v24; // w3
  __int64 v25; // x22
  __int64 v26; // x21
  unsigned int v27; // w8
  unsigned int v28; // w0
  int v29; // w3
  __int64 v30; // x23
  __int64 v31; // x9
  unsigned int v32; // w0
  unsigned int v33; // w0
  unsigned int v34; // w0
  int v35; // w3
  unsigned int v37; // w8
  unsigned int v38; // w0
  __int64 v39; // [xsp+0h] [xbp-30h]
  __int64 v40; // [xsp+8h] [xbp-28h]

  _ReadStatusReg(SP_EL0);
  mutex_lock(*(_QWORD *)(a1 + 264) + 1040LL);
  v4 = *(_DWORD *)(a1 + 836);
  if ( v4 >= 3 )
LABEL_92:
    __break(0x5512u);
  v5 = (_QWORD *)(a1 + 168);
  v6 = (_QWORD *)(a1 + 168 + 48LL * v4);
  dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 1);
  v7 = *(_DWORD *)(a1 + 160);
  if ( v7 )
  {
    if ( a1 != -168 && *v5 )
    {
      mutex_lock(*v5 + 32LL);
      ((void (__fastcall *)(_QWORD, __int64, __int64))dsi_ctrl_mask_error_status_interrupts)(
        *(_QWORD *)(a1 + 168),
        22,
        1);
      mutex_unlock(*(_QWORD *)(a1 + 168) + 32LL);
      v7 = *(_DWORD *)(a1 + 160);
    }
    if ( v7 >= 2 )
    {
      if ( a1 == -216 || (v8 = *(_QWORD *)(a1 + 216)) == 0 )
      {
LABEL_11:
        ((void (__fastcall *)(_QWORD, __int64, __int64))dsi_phy_update_phy_timings)(*(_QWORD *)(a1 + 192), a1 + 888, 1);
        if ( *(_DWORD *)(a1 + 160) >= 2u )
          ((void (__fastcall *)(_QWORD, __int64, __int64))dsi_phy_update_phy_timings)(
            *(_QWORD *)(a1 + 240),
            a1 + 888,
            1);
        goto LABEL_13;
      }
      mutex_lock(v8 + 32);
      ((void (__fastcall *)(_QWORD, __int64, __int64))dsi_ctrl_mask_error_status_interrupts)(
        *(_QWORD *)(a1 + 216),
        22,
        1);
      mutex_unlock(*(_QWORD *)(a1 + 216) + 32LL);
      v7 = *(_DWORD *)(a1 + 160);
    }
    if ( !v7 )
      goto LABEL_13;
    goto LABEL_11;
  }
LABEL_13:
  v9 = *(unsigned int *)(*v6 + 2376LL);
  v10 = *(unsigned int *)(*v6 + 2380LL);
  v11 = *(unsigned int *)(*v6 + 2384LL);
  updated = dsi_display_update_dsi_bitrate(a1, *(unsigned int *)(a2 + 48));
  if ( updated )
  {
    v13 = updated;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed set link frequencies %d\n", updated);
    goto LABEL_15;
  }
  v16 = *(_DWORD *)(a1 + 836);
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) == 1 )
  {
    if ( v16 >= 2 )
      goto LABEL_92;
    if ( !*(_DWORD *)(a1 + 160) )
      goto LABEL_36;
LABEL_31:
    if ( *(_QWORD *)(a1 + 192) )
      ((void (*)(void))dsi_phy_config_dynamic_refresh)();
    if ( *(_DWORD *)(a1 + 160) >= 2u && *(_QWORD *)(a1 + 240) )
      ((void (*)(void))dsi_phy_config_dynamic_refresh)();
    goto LABEL_36;
  }
  if ( v16 >= 3 )
    goto LABEL_92;
  dsi_phy_get_version(v5[6 * v16 + 3]);
  if ( *(_DWORD *)(a1 + 160) )
    goto LABEL_31;
LABEL_36:
  v39 = v11;
  v40 = v10;
  v17 = v9;
  v18 = *(_DWORD *)(a1 + 836);
  if ( v18 >= 3 )
    goto LABEL_92;
  v19 = *(_QWORD *)(a1 + 264);
  v20 = &v5[6 * v18];
  v21 = *(_DWORD *)(*v20 + 88LL);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 168) + 1608LL) != 1 )
    dsi_clk_prepare_enable(a1 + 872);
  dsi_display_phy_configure(a1, 0);
  v22 = *(_DWORD *)(a1 + 160);
  if ( !v22 )
    goto LABEL_61;
  if ( *v5 )
  {
    v23 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD))dsi_clk_set_byte_clk_rate)(
            *(_QWORD *)(a1 + 1320),
            *(unsigned int *)(*v5 + 2376LL),
            *(unsigned int *)(*v5 + 2380LL),
            0);
    if ( v23 )
    {
      v13 = v23;
      v24 = 0;
LABEL_43:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set byte rate for index:%d\n", v24);
      v25 = v40;
      v26 = v17;
LABEL_44:
      v27 = *(_DWORD *)(a1 + 160);
      goto LABEL_74;
    }
    v28 = dsi_clk_set_pixel_clk_rate(*(_QWORD *)(a1 + 1320), *(unsigned int *)(*(_QWORD *)(a1 + 168) + 2384LL), 0);
    if ( v28 )
    {
      v13 = v28;
      v29 = 0;
LABEL_47:
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to set pix rate for index:%d\n", v29);
      v26 = v17;
      v30 = v39;
      v25 = v40;
      goto LABEL_67;
    }
    v22 = *(_DWORD *)(a1 + 160);
  }
  if ( v22 <= 1 )
    goto LABEL_56;
  v31 = *(_QWORD *)(a1 + 216);
  if ( v31 )
  {
    v32 = ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, __int64))dsi_clk_set_byte_clk_rate)(
            *(_QWORD *)(a1 + 1320),
            *(unsigned int *)(v31 + 2376),
            *(unsigned int *)(v31 + 2380),
            1);
    if ( v32 )
    {
      v13 = v32;
      v24 = 1;
      goto LABEL_43;
    }
    v33 = dsi_clk_set_pixel_clk_rate(*(_QWORD *)(a1 + 1320), *(unsigned int *)(*(_QWORD *)(a1 + 216) + 2384LL), 1);
    if ( v33 )
    {
      v13 = v33;
      v29 = 1;
      goto LABEL_47;
    }
    v22 = *(_DWORD *)(a1 + 160);
LABEL_56:
    if ( !v22 )
      goto LABEL_61;
  }
  if ( !v18 )
  {
    if ( v22 <= 1 )
      goto LABEL_61;
    goto LABEL_60;
  }
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_phy_dynamic_refresh_trigger)(
    *(_QWORD *)(a1 + 192),
    0,
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 264) + 2024LL));
  if ( *(_DWORD *)(a1 + 160) >= 2u && v18 != 1 )
LABEL_60:
    ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_phy_dynamic_refresh_trigger)(
      *(_QWORD *)(a1 + 240),
      0,
      *(unsigned __int8 *)(*(_QWORD *)(a1 + 264) + 2024LL));
LABEL_61:
  ((void (__fastcall *)(_QWORD, __int64, _QWORD))dsi_phy_dynamic_refresh_trigger)(
    v20[3],
    1,
    *(unsigned __int8 *)(*(_QWORD *)(a1 + 264) + 2024LL));
  if ( (v21 & 0xFC) != 0 && (*(_BYTE *)(v19 + 1400) & 1) != 0 )
    goto LABEL_90;
  if ( !*(_DWORD *)(a1 + 160) )
  {
LABEL_89:
    if ( *(_DWORD *)(*v5 + 1608LL) != 1 )
    {
      dsi_clk_disable_unprepare(a1 + 872);
      v13 = 0;
      goto LABEL_15;
    }
LABEL_90:
    v13 = 0;
    goto LABEL_15;
  }
  v34 = ((__int64 (__fastcall *)(_QWORD))dsi_ctrl_wait4dynamic_refresh_done)(*v5);
  if ( !v34 )
  {
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: dynamic refresh done on dsi: %s\n", "master");
    v37 = *(_DWORD *)(a1 + 160);
    v26 = v17;
    v30 = v39;
    if ( v37 > 1 )
    {
      v38 = ((__int64 (__fastcall *)(_QWORD))dsi_ctrl_wait4dynamic_refresh_done)(*(_QWORD *)(a1 + 216));
      if ( v38 )
      {
        v13 = v38;
        v35 = 1;
        goto LABEL_66;
      }
      drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: dynamic refresh done on dsi: %s\n", "slave");
      v37 = *(_DWORD *)(a1 + 160);
    }
    if ( v37 )
    {
      ((void (__fastcall *)(_QWORD))dsi_phy_dynamic_refresh_clear)(*(_QWORD *)(a1 + 192));
      if ( *(_DWORD *)(a1 + 160) > 1u )
        ((void (__fastcall *)(_QWORD))dsi_phy_dynamic_refresh_clear)(*(_QWORD *)(a1 + 240));
    }
    goto LABEL_89;
  }
  v26 = v17;
  v30 = v39;
  v13 = v34;
  v35 = 0;
LABEL_66:
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: wait4dynamic refresh failed for dsi:%d\n", v35);
  v25 = v40;
LABEL_67:
  v27 = *(_DWORD *)(a1 + 160);
  if ( !v27 )
    goto LABEL_73;
  if ( *v5 )
  {
    dsi_clk_set_pixel_clk_rate(*(_QWORD *)(a1 + 1320), v30, 0);
    v27 = *(_DWORD *)(a1 + 160);
  }
  if ( v27 >= 2 )
  {
    if ( !*(_QWORD *)(a1 + 216) )
    {
LABEL_75:
      if ( *v5 )
      {
        ((void (__fastcall *)(_QWORD, __int64, __int64, _QWORD))dsi_clk_set_byte_clk_rate)(
          *(_QWORD *)(a1 + 1320),
          v26,
          v25,
          0);
        v27 = *(_DWORD *)(a1 + 160);
      }
      if ( v27 >= 2 && *(_QWORD *)(a1 + 216) )
        ((void (__fastcall *)(_QWORD, __int64, __int64, __int64))dsi_clk_set_byte_clk_rate)(
          *(_QWORD *)(a1 + 1320),
          v26,
          v25,
          1);
      goto LABEL_15;
    }
    dsi_clk_set_pixel_clk_rate(*(_QWORD *)(a1 + 1320), v30, 1);
    goto LABEL_44;
  }
LABEL_74:
  if ( v27 )
    goto LABEL_75;
LABEL_15:
  v14 = *(_DWORD *)(a1 + 160);
  if ( v14 )
  {
    if ( a1 != -168 && *v5 )
    {
      mutex_lock(*v5 + 32LL);
      ((void (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_mask_error_status_interrupts)(
        *(_QWORD *)(a1 + 168),
        22,
        0);
      mutex_unlock(*(_QWORD *)(a1 + 168) + 32LL);
      v14 = *(_DWORD *)(a1 + 160);
    }
    if ( v14 >= 2 )
    {
      v15 = (_QWORD *)(a1 + 216);
      if ( a1 != -216 )
      {
        if ( *v15 )
        {
          mutex_lock(*v15 + 32LL);
          ((void (__fastcall *)(_QWORD, __int64, _QWORD))dsi_ctrl_mask_error_status_interrupts)(*v15, 22, 0);
          mutex_unlock(*v15 + 32LL);
        }
      }
    }
  }
LABEL_73:
  dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 0);
  ((void (__fastcall *)(_QWORD, _QWORD, _QWORD))dsi_phy_dyn_refresh_cache_phy_timings)(
    v6[3],
    *(_QWORD *)(*(_QWORD *)(a2 + 184) + 2360LL),
    *(unsigned int *)(*(_QWORD *)(a2 + 184) + 2368LL));
  mutex_unlock(*(_QWORD *)(a1 + 264) + 1040LL);
  _ReadStatusReg(SP_EL0);
  return v13;
}
