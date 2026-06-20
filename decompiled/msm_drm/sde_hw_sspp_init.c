__int64 __fastcall sde_hw_sspp_init(unsigned int a1, __int64 a2, int *a3, char a4, __int64 a5, int a6)
{
  __int64 result; // x0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x20
  __int64 v16; // x8
  int *v17; // x8
  int v18; // w9
  int v19; // w10
  int v20; // w11
  unsigned __int64 v21; // x22
  unsigned __int64 v22; // x1
  __int64 v23; // x2
  __int64 v24; // x8
  unsigned int v25; // w1
  int v26; // w9
  void *v27; // x8
  int v28; // w8
  unsigned __int64 v29; // x8
  __int64 (__fastcall *v30)(); // x8
  __int64 (__fastcall *v31)(); // x9
  __int64 v32; // x8
  __int64 v33; // x10
  int v34; // w9
  __int64 v35; // x10
  __int64 (__fastcall *v36)(); // x9
  bool (__fastcall *v37)(__int64, int, char); // x10
  __int64 (__fastcall *v38)(__int64, int, int); // x9
  unsigned int v39; // w2
  unsigned int v40; // w2
  __int64 v41; // x8
  unsigned __int64 StatusReg; // x20
  __int64 v43; // x26
  __int64 v44; // [xsp+8h] [xbp-8h]
  unsigned __int64 v45; // [xsp+28h] [xbp+18h]

  result = -22;
  if ( !a2 || !a3 )
    return result;
  v13 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1416);
  if ( !v13 )
    return -12;
  while ( 1 )
  {
    if ( a1 > 0xE )
      goto LABEL_19;
    v14 = a3[1520];
    if ( !v14 )
      goto LABEL_19;
    v15 = v13;
    if ( a3[1526] == a1 )
    {
      v16 = 1522;
LABEL_8:
      v17 = &a3[v16];
      goto LABEL_9;
    }
    if ( v14 == 1 )
      goto LABEL_19;
    if ( a3[1544] == a1 )
    {
      v16 = 1540;
      goto LABEL_8;
    }
    if ( v14 == 2 )
      goto LABEL_19;
    if ( a3[1562] == a1 )
    {
      v16 = 1558;
      goto LABEL_8;
    }
    if ( v14 == 3 )
      goto LABEL_19;
    if ( a3[1580] == a1 )
    {
      v16 = 1576;
      goto LABEL_8;
    }
    if ( v14 == 4 )
      goto LABEL_19;
    if ( a3[1598] == a1 )
    {
      v16 = 1594;
      goto LABEL_8;
    }
    if ( v14 == 5 )
      goto LABEL_19;
    if ( a3[1616] == a1 )
    {
      v16 = 1612;
      goto LABEL_8;
    }
    if ( v14 == 6 )
      goto LABEL_19;
    if ( a3[1634] == a1 )
      break;
    if ( v14 == 7 )
      goto LABEL_19;
    if ( a3[1652] == a1 )
    {
      v41 = 1648;
      goto LABEL_116;
    }
    if ( v14 == 8 )
      goto LABEL_19;
    if ( a3[1670] == a1 )
    {
      v41 = 1666;
      goto LABEL_116;
    }
    if ( v14 == 9 )
      goto LABEL_19;
    if ( a3[1688] == a1 )
    {
      v41 = 1684;
      goto LABEL_116;
    }
    if ( v14 == 10 )
      goto LABEL_19;
    if ( a3[1706] == a1 )
    {
      v41 = 1702;
      goto LABEL_116;
    }
    if ( v14 == 11 )
      goto LABEL_19;
    if ( a3[1724] == a1 )
    {
      v41 = 1720;
      goto LABEL_116;
    }
    if ( v14 == 12 )
      goto LABEL_19;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v43 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_hw_sspp_init__alloc_tag;
    v13 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1416);
    *(_QWORD *)(StatusReg + 80) = v43;
    if ( !v13 )
      return -12;
  }
  v41 = 1630;
LABEL_116:
  v17 = &a3[v41];
LABEL_9:
  v18 = v17[5];
  v19 = v17[6];
  v20 = *a3;
  *(_QWORD *)v13 = a2;
  *(_DWORD *)(v13 + 8) = v18;
  *(_DWORD *)(v13 + 12) = v19;
  *(_DWORD *)(v13 + 20) = v20;
  *(_DWORD *)(v13 + 24) = 128;
  v21 = kmemdup_noprof(v17, 72, 3264);
  v13 = v15;
  if ( !v21 || v21 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_19:
    kfree(v13);
    return -22;
  }
  *(_DWORD *)(v15 + 48) = a1;
  *(_QWORD *)(v15 + 32) = a3;
  *(_QWORD *)(v15 + 40) = a3 + 162;
  *(_QWORD *)(v15 + 56) = v21;
  *(_DWORD *)(v15 + 1392) = a6;
  v22 = *(_QWORD *)(v21 + 32);
  v23 = *(_QWORD *)(v21 + 40);
  if ( (v22 & 0x40000000000LL) != 0 )
  {
    setup_layer_ops_v1((_QWORD *)v15, v22, v23);
    result = v15;
    v24 = a5;
    v25 = a3[5];
    if ( v25 )
      goto LABEL_76;
    goto LABEL_77;
  }
  v45 = *(_QWORD *)(v21 + 32);
  v44 = *(_QWORD *)(v21 + 40);
  if ( (v22 & 2) != 0 )
  {
    *(_QWORD *)(v15 + 64) = sde_hw_sspp_setup_format;
    *(_QWORD *)(v15 + 88) = sde_hw_sspp_setup_rects;
    *(_QWORD *)(v15 + 184) = sde_hw_sspp_setup_sourceaddress;
    *(_QWORD *)(v15 + 208) = sde_hw_sspp_get_source_addr;
    *(_QWORD *)(v15 + 256) = sde_hw_sspp_setup_solidfill;
    *(_QWORD *)(v15 + 136) = sde_hw_sspp_setup_pe_config_0;
    *(_QWORD *)(v15 + 832) = sde_hw_sspp_setup_secure;
    *(_QWORD *)(v15 + 856) = sde_hw_sspp_set_src_split_order;
    if ( (v22 & 0x200) != 0 )
      goto LABEL_28;
LABEL_14:
    if ( (v22 & 2) == 0 )
      goto LABEL_15;
LABEL_29:
    *(_QWORD *)(v15 + 544) = sde_hw_sspp_setup_qos_lut;
    *(_QWORD *)(v15 + 568) = sde_hw_sspp_setup_qos_ctrl;
    if ( (v23 & 8) != 0 )
      goto LABEL_30;
LABEL_16:
    if ( (v22 & 0x10) != 0 )
      goto LABEL_36;
LABEL_31:
    if ( (v22 & 0x20) != 0 )
      goto LABEL_36;
    if ( (v45 & 0x80000) == 0 )
      goto LABEL_33;
LABEL_37:
    *(_QWORD *)(v15 + 904) = sde_hw_sspp_setup_dgm_csc;
    if ( (v22 & 4) != 0 )
      goto LABEL_38;
LABEL_34:
    if ( (*(_QWORD *)(v21 + 32) & 0x400) != 0 )
      goto LABEL_41;
LABEL_39:
    if ( (*(_QWORD *)(v21 + 32) & 0x800) != 0 || (*(_QWORD *)(v21 + 32) & 0x1000) != 0 )
      goto LABEL_41;
  }
  else
  {
    if ( (v22 & 0x200) == 0 )
      goto LABEL_14;
LABEL_28:
    *(_QWORD *)(v15 + 160) = sde_hw_sspp_setup_excl_rect;
    if ( (v22 & 2) != 0 )
      goto LABEL_29;
LABEL_15:
    if ( (v23 & 8) == 0 )
      goto LABEL_16;
LABEL_30:
    *(_QWORD *)(v15 + 784) = sde_hw_sspp_setup_ts_prefill;
    if ( (v22 & 0x10) == 0 )
      goto LABEL_31;
LABEL_36:
    *(_QWORD *)(v15 + 232) = sde_hw_sspp_setup_csc;
    if ( (v45 & 0x80000) != 0 )
      goto LABEL_37;
LABEL_33:
    if ( (v22 & 4) == 0 )
      goto LABEL_34;
LABEL_38:
    *(_QWORD *)(v15 + 304) = sde_hw_sspp_setup_sharpening;
    *(_QWORD *)(v15 + 616) = sde_hw_sspp_setup_scaler;
    if ( (*(_QWORD *)(v21 + 32) & 0x400) == 0 )
      goto LABEL_39;
LABEL_41:
    *(_QWORD *)(v15 + 280) = sde_hw_sspp_update_multirect;
  }
  if ( (v45 & 0x10000000000LL) != 0 || (v45 & 0x20000000000LL) != 0 )
  {
    *(_QWORD *)(v15 + 1360) = sde_hw_sspp_setup_img_size;
    *(_QWORD *)(v15 + 1312) = sde_hw_sspp_setup_cac;
  }
  if ( (v22 & 8) != 0 || (v22 & 0x400000) != 0 )
  {
    v26 = a3[4];
    *(_QWORD *)(v15 + 616) = sde_hw_sspp_setup_scaler3;
    if ( v26 == 22 )
      v27 = reg_dmav1_setup_scaler3lite_lut;
    else
      v27 = reg_dmav1_setup_scaler3_lut;
    *(_QWORD *)(v15 + 640) = v27;
    if ( v26 == 22 )
      v28 = 22;
    else
      v28 = 3;
    if ( (unsigned int)reg_dmav1_init_sspp_op_v4(v28, v15) )
    {
      v22 = v45;
      v29 = (unsigned __int64)sde_hw_sspp_setup_scaler_cac;
      if ( (v45 & 0x10000000000LL) == 0 )
      {
        v22 = v45;
        v29 = (unsigned __int64)sde_hw_sspp_setup_scaler_cac & ((__int64)(v45 << 22) >> 63);
      }
      v13 = v15;
      *(_QWORD *)(v15 + 1336) = v29;
    }
    else
    {
      v22 = v45;
      v13 = v15;
      *(_QWORD *)(v15 + 616) = reg_dmav1_setup_vig_qseed3;
    }
  }
  if ( (v45 & 0x1000000) != 0 )
  {
    *(_QWORD *)(v13 + 952) = sde_hw_sspp_get_meta_error;
    v30 = sde_hw_sspp_clear_ubwc_error_v1;
    *(_QWORD *)(v13 + 928) = sde_hw_sspp_clear_meta_error;
    v31 = sde_hw_sspp_get_ubwc_error_v1;
  }
  else
  {
    v30 = sde_hw_sspp_clear_ubwc_error;
    v31 = sde_hw_sspp_get_ubwc_error;
  }
  *(_QWORD *)(v13 + 1000) = v31;
  *(_QWORD *)(v13 + 976) = v30;
  if ( (v45 & 0x2000000) == 0 )
  {
    if ( (v44 & 0x40) == 0 )
      goto LABEL_63;
LABEL_67:
    *(_QWORD *)(v13 + 712) = sde_hw_sspp_setup_sys_cache;
    if ( (v44 & 0x20) != 0 )
      goto LABEL_68;
LABEL_64:
    if ( (v44 & 0x80) == 0 )
      goto LABEL_71;
LABEL_69:
    *(_QWORD *)(v13 + 736) = sde_hw_sspp_setup_uidle;
    if ( (v44 & 0x100) != 0 )
      *(_QWORD *)(v13 + 760) = sde_hw_sspp_setup_uidle_fill_scale;
    goto LABEL_71;
  }
  *(_QWORD *)(v13 + 688) = sde_hw_sspp_setup_pre_downscale;
  if ( (v44 & 0x40) != 0 )
    goto LABEL_67;
LABEL_63:
  if ( (v44 & 0x20) == 0 )
    goto LABEL_64;
LABEL_68:
  *(_QWORD *)(v13 + 808) = sde_hw_sspp_setup_cdp;
  if ( (v44 & 0x80) != 0 )
    goto LABEL_69;
LABEL_71:
  setup_layer_ops_colorproc((_QWORD *)v13, v22, a4 & 1);
  if ( (v45 & 0x40000) != 0 )
  {
    v38 = sde_hw_sspp_setup_dgm_inverse_pma;
    result = v15;
    v24 = a5;
  }
  else
  {
    result = v15;
    v24 = a5;
    if ( (v45 & 0x20000) == 0 )
    {
      if ( (v45 & 0x100000000LL) == 0 )
        goto LABEL_74;
LABEL_100:
      *(_QWORD *)(result + 1048) = sde_hw_sspp_ubwc_stats_set_roi;
      *(_QWORD *)(result + 1024) = sde_hw_sspp_ubwc_stats_get_data;
      if ( (v45 & 0x400000000LL) != 0 )
        goto LABEL_101;
LABEL_75:
      v25 = a3[5];
      if ( v25 )
        goto LABEL_76;
      goto LABEL_77;
    }
    v38 = sde_hw_sspp_setup_inverse_pma;
  }
  *(_QWORD *)(result + 880) = v38;
  if ( (v45 & 0x100000000LL) != 0 )
    goto LABEL_100;
LABEL_74:
  if ( (v45 & 0x400000000LL) == 0 )
    goto LABEL_75;
LABEL_101:
  *(_QWORD *)(result + 1168) = sde_hw_sspp_setup_line_insertion;
  v25 = a3[5];
  if ( v25 )
  {
LABEL_76:
    sde_init_scaler_blk(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 80LL, v25);
    v24 = a5;
    result = v15;
  }
LABEL_77:
  if ( (a4 & 1) == 0 )
  {
    sde_dbg_reg_register_dump_range(
      (__int64)"sde",
      (const char *)v21,
      *(_DWORD *)(result + 8),
      *(_DWORD *)(result + 12) + *(_DWORD *)(result + 8),
      *(_DWORD *)(result + 16));
    v32 = *(_QWORD *)(v15 + 56);
    result = v15;
    if ( (*(_QWORD *)(v32 + 32) & 0x80000) == 0 )
    {
      if ( (*(_QWORD *)(v32 + 32) & 0x8000) == 0 )
        goto LABEL_80;
LABEL_92:
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        "DGM_0",
        *(_DWORD *)(result + 8) + 2544,
        *(_DWORD *)(result + 8) + 3600,
        *(_DWORD *)(result + 16));
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        "DGM_1",
        *(_DWORD *)(v15 + 8) + 6640,
        *(_DWORD *)(v15 + 8) + 7696,
        *(_DWORD *)(v15 + 16));
      v32 = *(_QWORD *)(v15 + 56);
      result = v15;
      if ( (*(_QWORD *)(v32 + 32) & 0x4000) != 0 )
        goto LABEL_93;
LABEL_81:
      if ( (*(_QWORD *)(v32 + 32) & 0x2000000000LL) == 0 )
        goto LABEL_82;
LABEL_94:
      v39 = *(_DWORD *)(*(_QWORD *)(v21 + 48) + 1012LL) + *(_DWORD *)(result + 8);
      sde_dbg_reg_register_dump_range((__int64)"sde", "UCSC_0", v39, v39 + 128, *(_DWORD *)(result + 16));
      v40 = *(_DWORD *)(*(_QWORD *)(v21 + 48) + 1048LL) + *(_DWORD *)(v15 + 8);
      sde_dbg_reg_register_dump_range((__int64)"sde", "UCSC_1", v40, v40 + 128, *(_DWORD *)(v15 + 16));
      result = v15;
      if ( (*(_QWORD *)(*(_QWORD *)(v15 + 56) + 32LL) & 0x40000000000LL) == 0 )
        goto LABEL_84;
LABEL_83:
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        "SSPP_REC_0",
        *(_DWORD *)(result + 8) + 4096,
        *(_DWORD *)(result + 8) + 4476,
        *(_DWORD *)(result + 16));
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        "SSPP_REC_1",
        *(_DWORD *)(v15 + 8) + 12288,
        *(_DWORD *)(v15 + 8) + 12668,
        *(_DWORD *)(v15 + 16));
      result = v15;
      goto LABEL_84;
    }
    sde_dbg_reg_register_dump_range(
      (__int64)"sde",
      "CSC_0",
      *(_DWORD *)(v15 + 8) + 2048,
      *(_DWORD *)(v15 + 8) + 2300,
      *(_DWORD *)(v15 + 16));
    sde_dbg_reg_register_dump_range(
      (__int64)"sde",
      "CSC_1",
      *(_DWORD *)(v15 + 8) + 6144,
      *(_DWORD *)(v15 + 8) + 6396,
      *(_DWORD *)(v15 + 16));
    v32 = *(_QWORD *)(v15 + 56);
    result = v15;
    if ( (*(_QWORD *)(v32 + 32) & 0x8000) != 0 )
      goto LABEL_92;
LABEL_80:
    if ( (*(_QWORD *)(v32 + 32) & 0x4000) == 0 )
      goto LABEL_81;
LABEL_93:
    sde_dbg_reg_register_dump_range(
      (__int64)"sde",
      (const char *)(*(_QWORD *)(v21 + 48) + 268LL),
      *(_DWORD *)(*(_QWORD *)(v21 + 48) + 288LL) + *(_DWORD *)(result + 8),
      *(_DWORD *)(*(_QWORD *)(v21 + 48) + 288LL) + *(_DWORD *)(result + 8) + 460,
      *(_DWORD *)(result + 16));
    v32 = *(_QWORD *)(v15 + 56);
    result = v15;
    if ( (*(_QWORD *)(v32 + 32) & 0x2000000000LL) != 0 )
      goto LABEL_94;
LABEL_82:
    if ( (*(_QWORD *)(v32 + 32) & 0x40000000000LL) != 0 )
      goto LABEL_83;
LABEL_84:
    v33 = *(_QWORD *)(v21 + 48);
    v24 = a5;
    v34 = *(_DWORD *)(v33 + 104);
    if ( v34 )
    {
      sde_dbg_reg_register_dump_range(
        (__int64)"sde",
        (const char *)(v33 + 80),
        *(_DWORD *)(v33 + 100) + *(_DWORD *)(result + 8),
        *(_DWORD *)(v33 + 100) + *(_DWORD *)(result + 8) + v34,
        *(_DWORD *)(result + 16));
      v24 = a5;
      result = v15;
    }
  }
  if ( (*((_QWORD *)a3 + 2751) & 0x8000000000LL) != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(v21 + 60) - 1) > 0xD )
    {
      printk(&unk_213481, "sde_hw_sspp_init");
      return v15;
    }
    else
    {
      *(_QWORD *)v24 = result;
      v35 = *(_QWORD *)(result + 56);
      *(_DWORD *)(v24 + 8) = *(_DWORD *)(v21 + 60);
      if ( (*(_QWORD *)(v35 + 32) & 0x40000000000LL) != 0 )
      {
        v36 = (__int64 (__fastcall *)())sde_hw_sspp_get_clk_ctrl_status_v1;
        v37 = sde_hw_sspp_setup_clk_force_ctrl_v1;
      }
      else
      {
        v36 = sde_hw_sspp_get_clk_ctrl_status;
        v37 = (bool (__fastcall *)(__int64, int, char))sde_hw_sspp_setup_clk_force_ctrl;
      }
      *(_QWORD *)(v24 + 16) = v37;
      *(_QWORD *)(v24 + 24) = v36;
    }
  }
  return result;
}
