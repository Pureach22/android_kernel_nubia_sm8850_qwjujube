__int64 __fastcall setup_layer_ops_v1(_QWORD *a1, __int64 a2, __int16 a3)
{
  __int64 v4; // x8
  __int64 v5; // x8
  void *v7; // x9
  int v8; // w0
  unsigned __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 (__fastcall *v12)(); // x8
  __int64 (__fastcall *v13)(); // x9
  __int64 result; // x0
  __int64 (__fastcall *v15)(); // x8

  if ( (a2 & 2) != 0 )
  {
    a1[8] = sde_hw_sspp_setup_format_v1;
    a1[11] = sde_hw_sspp_setup_rects_v1;
    a1[23] = sde_hw_sspp_setup_sourceaddress_v1;
    a1[26] = sde_hw_sspp_get_source_addr_v1;
    a1[32] = sde_hw_sspp_setup_solidfill_v1;
    a1[17] = sde_hw_sspp_setup_pe_config;
    a1[104] = sde_hw_sspp_setup_secure_v1;
    a1[107] = sde_hw_sspp_set_src_split_order_v1;
    if ( (a2 & 0x200) == 0 )
    {
LABEL_3:
      if ( (a2 & 2) == 0 )
        goto LABEL_4;
      goto LABEL_9;
    }
  }
  else if ( (a2 & 0x200) == 0 )
  {
    goto LABEL_3;
  }
  a1[20] = sde_hw_sspp_setup_excl_rect_v1;
  if ( (a2 & 2) == 0 )
  {
LABEL_4:
    if ( (a3 & 8) == 0 )
      goto LABEL_5;
    goto LABEL_10;
  }
LABEL_9:
  a1[68] = sde_hw_sspp_setup_qos_lut_v1;
  a1[71] = sde_hw_sspp_setup_qos_ctrl_v1;
  if ( (a3 & 8) == 0 )
  {
LABEL_5:
    if ( (a2 & 0x10) != 0 )
      goto LABEL_31;
    goto LABEL_11;
  }
LABEL_10:
  a1[98] = sde_hw_sspp_setup_ts_prefill_v1;
  if ( (a2 & 0x10) != 0 )
    goto LABEL_31;
LABEL_11:
  if ( (a2 & 0x20) == 0 )
  {
    if ( (a2 & 0x80000) != 0 )
      goto LABEL_32;
    goto LABEL_13;
  }
LABEL_31:
  a1[29] = sde_hw_sspp_setup_csc;
  if ( (a2 & 0x80000) != 0 )
  {
LABEL_32:
    a1[113] = sde_hw_sspp_setup_dgm_csc;
    if ( (a2 & 4) == 0 )
      goto LABEL_15;
    goto LABEL_14;
  }
LABEL_13:
  if ( (a2 & 4) != 0 )
  {
LABEL_14:
    a1[38] = sde_hw_sspp_setup_sharpening;
    a1[77] = sde_hw_sspp_setup_scaler;
  }
LABEL_15:
  v4 = a1[7];
  if ( (*(_QWORD *)(v4 + 32) & 0x400) != 0
    || (*(_QWORD *)(v4 + 32) & 0x800) != 0
    || (*(_QWORD *)(v4 + 32) & 0x1000) != 0 )
  {
    a1[35] = sde_hw_sspp_update_multirect_v1;
    if ( (a2 & 0x10000000000LL) == 0 )
    {
LABEL_19:
      if ( (a2 & 8) != 0 )
        goto LABEL_24;
      goto LABEL_23;
    }
  }
  else if ( (a2 & 0x10000000000LL) == 0 )
  {
    goto LABEL_19;
  }
  a1[164] = sde_hw_sspp_setup_cac_v1;
  a1[170] = sde_hw_sspp_setup_img_size_v1;
  if ( (a2 & 8) != 0 )
    goto LABEL_24;
LABEL_23:
  if ( (a2 & 0x400000) == 0 )
    goto LABEL_39;
LABEL_24:
  v5 = a1[4];
  a1[77] = sde_hw_sspp_setup_scaler3;
  v7 = reg_dmav1_setup_scaler3lite_lut;
  if ( *(_DWORD *)(v5 + 16) != 22 )
    v7 = reg_dmav1_setup_scaler3_lut;
  a1[80] = v7;
  if ( *(_DWORD *)(v5 + 16) == 22 )
    v8 = 22;
  else
    v8 = 3;
  if ( (unsigned int)reg_dmav1_init_sspp_op_v4(v8, (__int64)a1) )
  {
    v9 = (unsigned __int64)sde_hw_sspp_setup_scaler_cac & (a2 << 23 >> 63);
    v10 = 167;
LABEL_38:
    a1[v10] = v9;
    goto LABEL_39;
  }
  v11 = a1[80];
  a1[77] = reg_dmav1_setup_vig_qseed3;
  a1[78] = reg_dmav1_setup_vig_qseed3;
  a1[81] = v11;
  if ( (a2 & 2) != 0 )
  {
    a1[14] = reg_dmav1_setup_pe_config;
    a1[15] = reg_dmav1_setup_pe_config;
  }
  if ( (a2 & 0x2000000) != 0 )
  {
    v9 = (unsigned __int64)reg_dmav1_setup_pre_downscale;
    v10 = 84;
    a1[83] = reg_dmav1_setup_pre_downscale;
    goto LABEL_38;
  }
LABEL_39:
  if ( (a2 & 0x1000000) != 0 )
  {
    a1[119] = sde_hw_sspp_get_meta_error_v1;
    v12 = sde_hw_sspp_clear_ubwc_error_v3;
    a1[116] = sde_hw_sspp_clear_meta_error_v1;
    v13 = sde_hw_sspp_get_ubwc_error_v3;
  }
  else
  {
    v12 = sde_hw_sspp_clear_ubwc_error_v2;
    v13 = sde_hw_sspp_get_ubwc_error_v2;
  }
  a1[125] = v13;
  a1[122] = v12;
  if ( (a2 & 0x2000000) != 0 )
  {
    a1[86] = sde_hw_sspp_setup_pre_downscale_v1;
    if ( (a3 & 0x40) == 0 )
    {
LABEL_44:
      if ( (a3 & 0x20) == 0 )
        goto LABEL_45;
      goto LABEL_49;
    }
  }
  else if ( (a3 & 0x40) == 0 )
  {
    goto LABEL_44;
  }
  a1[89] = sde_hw_sspp_setup_sys_cache_v1;
  if ( (a3 & 0x20) == 0 )
  {
LABEL_45:
    if ( (a3 & 0x80) == 0 )
      goto LABEL_52;
    goto LABEL_50;
  }
LABEL_49:
  a1[101] = sde_hw_sspp_setup_cdp_v1;
  if ( (a3 & 0x80) == 0 )
    goto LABEL_52;
LABEL_50:
  a1[92] = sde_hw_sspp_setup_uidle_v1;
  if ( (a3 & 0x100) != 0 )
    a1[95] = sde_hw_sspp_setup_uidle_fill_scale_v1;
LABEL_52:
  result = setup_layer_ops_colorproc(a1);
  if ( (a2 & 0x40000) != 0 )
  {
    v15 = sde_hw_sspp_setup_dgm_inverse_pma;
  }
  else
  {
    if ( (a2 & 0x20000) == 0 )
    {
      if ( (a2 & 0x100000000LL) == 0 )
        goto LABEL_55;
      goto LABEL_61;
    }
    v15 = sde_hw_sspp_setup_inverse_pma;
  }
  a1[110] = v15;
  if ( (a2 & 0x100000000LL) == 0 )
  {
LABEL_55:
    if ( (a2 & 0x400000000LL) == 0 )
      return result;
    goto LABEL_56;
  }
LABEL_61:
  a1[131] = sde_hw_sspp_ubwc_stats_set_roi_v1;
  a1[128] = sde_hw_sspp_ubwc_stats_get_data_v1;
  if ( (a2 & 0x400000000LL) == 0 )
    return result;
LABEL_56:
  a1[146] = sde_hw_sspp_setup_line_insertion_v1;
  return result;
}
