__int64 __fastcall sde_wb_connector_post_init(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x8
  __int64 v5; // x21
  __int64 v7; // x20
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  unsigned int v11; // w21
  void *v12; // x0
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !*(_QWORD *)(a2 + 16) || (v3 = *(_QWORD *)(*(_QWORD *)a2 + 56LL)) == 0 )
  {
    v12 = &unk_223EAA;
LABEL_28:
    printk(v12, "sde_wb_connector_post_init");
    result = 4294967274LL;
    goto LABEL_32;
  }
  v4 = *(_QWORD *)(v3 + 8);
  if ( !v4 || (v5 = *(_QWORD *)(v4 + 152)) == 0 )
  {
    v12 = &unk_25E374;
    goto LABEL_28;
  }
  *(_QWORD *)(a2 + 96) = a1;
  *(_DWORD *)(a2 + 112) = 1;
  if ( (*(_QWORD *)(v5 + 21696) & 1) != 0 || (*(_QWORD *)(v5 + 21696) & 4) != 0 )
    msm_property_install_enum(a1 + 3312, "cache_state", 0, 0, &sde_wb_connector_post_init_e_cache_state, 2, 0, 41);
  msm_property_install_range(a1 + 3312, "FB_ID", 0, 0, -1, 0, 11);
  msm_property_install_range(a1 + 3312, "DST_X", 0, 0, 0xFFFFFFFFLL, 0, 14);
  msm_property_install_range(a1 + 3312, "DST_Y", 0, 0, 0xFFFFFFFFLL, 0, 15);
  msm_property_install_range(a1 + 3312, "DST_W", 0, 0, 0xFFFFFFFFLL, 0, 16);
  msm_property_install_range(a1 + 3312, "DST_H", 0, 0, 0xFFFFFFFFLL, 0, 17);
  msm_property_install_enum(
    a1 + 3312,
    "fb_translation_mode",
    0,
    0,
    &sde_wb_connector_post_init_e_fb_translation_mode,
    2,
    0,
    32);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 34LL) & 0x10) != 0 )
    msm_property_install_range(a1 + 3312, "early_fence_line", 0, 0, 0xFFFFFFFFLL, 0, 25);
  if ( *(_DWORD *)(v5 + 12624) && *(_QWORD *)(v5 + 22088) )
    msm_property_install_range(a1 + 3312, "dnsc_blur", 0, 0, -1, 0, 9);
  if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 34LL) & 0x20) != 0 )
  {
    msm_property_install_enum(a1 + 3312, "wb_rotate_type", 0, 0, &sde_wb_connector_post_init_e_wb_rotate_type, 4, 0, 44);
    msm_property_install_range(a1 + 3312, "wb_rot_bytes_per_clk", 0, 0, 0xFFFFFFFFLL, 0, 45);
  }
  msm_property_install_enum(a1 + 3312, "wb_usage_type", 0, 0, &sde_wb_connector_post_init_e_wb_usage_type, 4, 0, 43);
  msm_property_install_blob(a1 + 3312, "wb_csc_config", 16, 10);
  v7 = *(_QWORD *)(a2 + 96);
  if ( v7 && *(_QWORD *)v7 && (v8 = *(_QWORD *)(*(_QWORD *)v7 + 56LL)) != 0 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      v10 = *(_QWORD *)(v9 + 152);
      v16 = 0;
      v17 = 0;
      *(_QWORD *)s = 0;
      v15 = 0;
      if ( v10 && (*(_QWORD *)(v10 + 22008) & 0x20) != 0 )
      {
        v11 = *(_DWORD *)(*(_QWORD *)(v10 + 9672) + 140LL);
        snprintf(s, 0x20u, "%s%d", "SDE_PP_CWB_DITHER_V", HIWORD(v11));
        if ( (v11 & 0xFFFE0000) == 0x20000 )
          msm_property_install_blob(v7 + 3312, s, 16, 5);
        else
          printk(&unk_27B2AF, "_sde_wb_connector_install_dither_property");
      }
    }
    else
    {
      printk(&unk_234896, "sde_connector_get_kms");
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_get_kms");
  }
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}
