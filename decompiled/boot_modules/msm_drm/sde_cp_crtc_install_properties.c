__int64 __fastcall sde_cp_crtc_install_properties(_QWORD *a1)
{
  _QWORD *v2; // x2
  __int64 v3; // x8
  _QWORD *v4; // x20
  __int64 v6; // x23
  __int64 v7; // x24
  __int64 v8; // x20
  __int64 v9; // x20
  void (__fastcall *v10)(_QWORD); // x8
  __int64 v11; // x20
  void (__fastcall *v12)(_QWORD); // x8
  unsigned __int64 v13; // [xsp+18h] [xbp+18h]
  unsigned __int64 v14; // [xsp+18h] [xbp+18h]

  if ( !a1 )
  {
    v2 = nullptr;
    return _drm_err("invalid crtc %pK dev %pK\n", a1, v2);
  }
  v2 = (_QWORD *)*a1;
  if ( !*a1 )
    return _drm_err("invalid crtc %pK dev %pK\n", a1, v2);
  v3 = v2[7];
  if ( !v3 )
    return _drm_err("invalid crtc %pK dev %pK\n", a1, v2);
  v4 = *(_QWORD **)(v3 + 8);
  if ( v4 && v4[19] )
  {
    mutex_lock(a1 + 583);
    if ( (_QWORD *)a1[565] != a1 + 565 )
      return mutex_unlock(a1 + 583);
    v6 = v4[19];
    v7 = *(_QWORD *)(*a1 + 56LL);
    if ( *(_QWORD *)(v7 + 5224) )
    {
LABEL_23:
      if ( *(_DWORD *)(v6 + 8160) )
      {
        v9 = 0;
        v13 = *(_QWORD *)(v6 + 8200);
        do
        {
          if ( ((v13 >> v9) & 1) != 0 )
          {
            v10 = (void (__fastcall *)(_QWORD))dspp_prop_install_func[v9];
            if ( v10 )
            {
              if ( *((_DWORD *)v10 - 1) != -1434212794 )
                __break(0x8228u);
              v10(a1);
            }
          }
          ++v9;
        }
        while ( v9 != 25 );
      }
      if ( *(_DWORD *)(v6 + 6952) )
      {
        v11 = 0;
        v14 = *(_QWORD *)(v6 + 6992);
        do
        {
          if ( ((v14 >> v11) & 1) != 0 )
          {
            v12 = (void (__fastcall *)(_QWORD))lm_prop_install_func[v11];
            if ( v12 )
            {
              if ( *((_DWORD *)v12 - 1) != -1434212794 )
                __break(0x8228u);
              v12(a1);
            }
          }
          ++v11;
        }
        while ( v11 != 16 );
      }
      return mutex_unlock(a1 + 583);
    }
    v8 = _kmalloc_cache_noprof(msleep, 3520, 416);
    qword_293FA8 = (__int64)dspp_memcolor_install_property;
    qword_293FB0 = (__int64)dspp_sixzone_install_property;
    qword_293FD8 = (__int64)dspp_ad_install_property;
    qword_293FE0 = (__int64)dspp_ltm_install_property;
    qword_293FE8 = (__int64)dspp_spr_install_property;
    qword_293F98 = (__int64)dspp_gc_install_property;
    qword_293FA0 = (__int64)dspp_hsic_install_property;
    qword_293F88 = (__int64)dspp_igc_install_property;
    qword_293F90 = (__int64)dspp_pcc_install_property;
    qword_293FC8 = (__int64)dspp_hist_install_property;
    qword_293FD0 = (__int64)dspp_vlut_install_property;
    qword_293FB8 = (__int64)dspp_gamut_install_property;
    qword_293FC0 = (__int64)dspp_dither_install_property;
    *(_QWORD *)(v7 + 5224) = v8;
    qword_294000 = (__int64)dspp_demura_install_property;
    qword_294008 = (__int64)dspp_rc_install_property;
    qword_294028 = (__int64)dspp_aiqe_install_property;
    qword_294040 = (__int64)dspp_ai_scaler_install_property;
    qword_294060 = (__int64)lm_gc_install_property;
    memset(&unk_293E30, 0, 0x130u);
    set_crtc_feature_wrappers[0] = (__int64)set_dspp_igc_feature;
    qword_293DD0 = (__int64)set_dspp_pcc_feature;
    qword_293DD8 = (__int64)set_dspp_gc_feature;
    qword_293DE0 = (__int64)set_dspp_hsic_feature;
    qword_293DE8 = (__int64)set_dspp_memcol_skin_feature;
    qword_293DF0 = (__int64)set_dspp_memcol_sky_feature;
    qword_293DF8 = (__int64)set_dspp_memcol_foliage_feature;
    qword_293E00 = (__int64)set_dspp_memcol_prot_feature;
    qword_293E08 = (__int64)set_dspp_sixzone_feature;
    qword_293E10 = (__int64)set_dspp_gamut_feature;
    qword_293E18 = (__int64)set_dspp_dither_feature;
    qword_293E20 = (__int64)set_dspp_hist_ctrl_feature;
    qword_293E28 = (__int64)set_dspp_hist_irq_feature;
    qword_293E38 = (__int64)set_dspp_vlut_feature;
    qword_293E40 = (__int64)set_dspp_ad_mode_feature;
    qword_293E48 = (__int64)set_dspp_ad_init_feature;
    qword_293E50 = (__int64)set_dspp_ad_cfg_feature;
    qword_293E58 = (__int64)set_dspp_ad_input_feature;
    qword_293E60 = (__int64)set_dspp_ad_assertive_feature;
    qword_293E68 = (__int64)set_dspp_ad_backlight_feature;
    qword_293E70 = (__int64)set_dspp_ad_strength_feature;
    qword_293E78 = (__int64)set_dspp_ad_roi_feature;
    qword_293F60 = (__int64)set_lm_gc_feature;
    qword_293E88 = (__int64)set_ltm_init_feature;
    qword_293E90 = (__int64)set_ltm_roi_feature;
    qword_293EA8 = (__int64)set_ltm_buffers_feature;
    qword_293EB0 = (__int64)set_ltm_queue_buf_feature;
    qword_293EB8 = (__int64)set_ltm_queue_buf_feature;
    qword_293EC0 = (__int64)set_ltm_queue_buf_feature;
    qword_293EC8 = (__int64)set_ltm_vlut_feature;
    qword_293E98 = (__int64)set_ltm_hist_crtl_feature;
    qword_293EA0 = (__int64)set_ltm_thresh_feature;
    qword_293ED8 = (__int64)set_rc_mask_feature;
    qword_293EE0 = (__int64)set_spr_init_feature;
    qword_293EE8 = (__int64)set_spr_udc_feature;
    qword_293EF0 = (__int64)set_dspp_spr_dither_feature;
    qword_293EF8 = (__int64)set_demura_feature;
    qword_293F00 = (__int64)set_demura_backlight;
    qword_293F10 = (__int64)set_demura_cfg0_param2;
    qword_293F18 = (__int64)set_mdnie_feature;
    qword_293F20 = (__int64)set_mdnie_art_feature;
    qword_293F30 = (__int64)set_aiqe_ssrc_config;
    qword_293F38 = (__int64)set_aiqe_ssrc_data;
    qword_293F40 = (__int64)set_copr_feature;
    qword_293F48 = (__int64)&set_ai_scaler_feature;
    qword_293F50 = (__int64)&set_aiqe_abc_feature;
    memset(check_crtc_feature_wrappers, 0, 0x1A0u);
    qword_293D20 = (__int64)check_rc_mask_feature;
    qword_293D28 = (__int64)check_spr_init_feature;
    qword_293D30 = (__int64)check_spr_udc_feature;
    qword_293CD8 = (__int64)check_ltm_roi_feature;
    qword_293D80 = (__int64)check_aiqe_ssrc_data;
    qword_293D90 = (__int64)check_ai_scaler_feature;
    memset(crtc_feature_disable_wrappers, 0, 0x1A0u);
    qword_2941D8 = (__int64)disable_rc_mask_feature;
    set_crtc_pu_feature_wrappers[0] = (__int64)set_rc_pu_feature;
    qword_293F70 = (__int64)set_spr_pu_feature;
    qword_293F78 = (__int64)set_demura_pu_feature;
    check_crtc_pu_feature_wrappers = check_rc_pu_feature;
    off_293DB8 = check_spr_pu_feature;
    off_293DC0 = check_spr_pu_feature;
    dspp_cap_update_func_0 = dspp_idx_caps_update;
    dspp_cap_update_func_1 = rc_caps_update;
    dspp_cap_update_func_2 = demura_caps_update;
    dspp_cap_update_func_3 = spr_caps_update;
    dspp_cap_update_func_4 = ltm_caps_update;
    dspp_cap_update_func_5 = aiqe_caps_update;
    if ( !v6 )
    {
      _drm_err("invalid catalog\n");
      if ( !*(_QWORD *)(v7 + 5224) )
        return mutex_unlock(a1 + 583);
      goto LABEL_23;
    }
    if ( *(_DWORD *)(v6 + 19972) )
    {
      if ( *(_DWORD *)(v6 + 19980) )
        goto LABEL_15;
    }
    else
    {
      qword_293D20 = (__int64)feature_unsupported;
      qword_293ED8 = (__int64)feature_unsupported;
      check_crtc_pu_feature_wrappers = feature_unsupported;
      set_crtc_pu_feature_wrappers[0] = (__int64)feature_unsupported;
      if ( *(_DWORD *)(v6 + 19980) )
      {
LABEL_15:
        if ( *(_DWORD *)(v6 + 19976) )
          goto LABEL_16;
LABEL_22:
        off_293DB8 = feature_unsupported;
        qword_293EE0 = (__int64)feature_unsupported;
        qword_293EF0 = (__int64)feature_unsupported;
        qword_293F70 = (__int64)feature_unsupported;
        if ( !v8 )
          return mutex_unlock(a1 + 583);
        goto LABEL_23;
      }
    }
    off_293DC0 = feature_unsupported;
    qword_293EF8 = (__int64)feature_unsupported;
    qword_293F78 = (__int64)feature_unsupported;
    if ( *(_DWORD *)(v6 + 19976) )
    {
LABEL_16:
      if ( !v8 )
        return mutex_unlock(a1 + 583);
      goto LABEL_23;
    }
    goto LABEL_22;
  }
  return _drm_err("invalid sde kms %pK catalog %pK sde_crtc %pK\n", v4, nullptr, a1);
}
