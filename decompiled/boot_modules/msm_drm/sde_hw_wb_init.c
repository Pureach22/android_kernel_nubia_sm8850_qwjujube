__int64 __fastcall sde_hw_wb_init(int a1, __int64 a2, int *a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v11; // x0
  int v12; // w1
  int v13; // w8
  __int64 v14; // x8
  unsigned __int64 v15; // x24
  int v16; // w9
  unsigned int v17; // w2
  int v18; // w8
  __int64 v19; // x9
  int v20; // w9
  __int64 (__fastcall *v21)(); // x9
  int v22; // w8
  int v23; // w8
  int v24; // w8
  unsigned int v25; // w22
  unsigned int v26; // w2
  unsigned int v27; // w8
  int v28; // w8
  int v29; // w9
  unsigned int v30; // w2
  int v31; // w8
  int v32; // w9
  unsigned int v33; // w2
  __int64 v34; // x9
  __int64 v35; // x9
  unsigned __int64 v36; // x8
  __int64 v37; // x14
  int v38; // w17
  int v39; // w16
  int v40; // w15
  int v41; // w17
  char s[8]; // [xsp+8h] [xbp-48h] BYREF
  __int64 v44; // [xsp+10h] [xbp-40h]
  __int64 v45; // [xsp+18h] [xbp-38h]
  __int64 v46; // [xsp+20h] [xbp-30h]
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v5 = -22;
  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 || !a3 || !a4 )
    goto LABEL_91;
  v11 = _kmalloc_cache_noprof(kthread_park, 3520, 2584);
  v5 = v11;
  if ( !v11 )
  {
    v5 = -12;
    goto LABEL_91;
  }
  v13 = a3[3568];
  if ( !v13 )
    goto LABEL_18;
  if ( a3[3574] == a1 )
  {
    v14 = 3570;
    goto LABEL_8;
  }
  if ( v13 == 1 )
    goto LABEL_18;
  if ( a3[3596] == a1 )
  {
    v14 = 3592;
    goto LABEL_8;
  }
  if ( v13 == 2 )
    goto LABEL_18;
  if ( a3[3618] == a1 )
  {
    v14 = 3614;
    goto LABEL_8;
  }
  if ( v13 == 3 )
    goto LABEL_18;
  if ( a3[3640] == a1 )
  {
    v14 = 3636;
    goto LABEL_8;
  }
  if ( v13 == 4 )
    goto LABEL_18;
  if ( a3[3662] == a1 )
  {
    v14 = 3658;
    goto LABEL_8;
  }
  if ( v13 == 5 )
    goto LABEL_18;
  if ( a3[3684] == a1 )
  {
    v14 = 3680;
    goto LABEL_8;
  }
  if ( v13 == 6 )
    goto LABEL_18;
  if ( a3[3706] == a1 )
  {
    v14 = 3702;
    goto LABEL_8;
  }
  if ( v13 == 7 )
    goto LABEL_18;
  if ( a3[3728] == a1 )
  {
    v14 = 3724;
    goto LABEL_8;
  }
  if ( v13 == 8 )
    goto LABEL_18;
  if ( a3[3750] == a1 )
  {
    v14 = 3746;
    goto LABEL_8;
  }
  if ( v13 == 9 )
    goto LABEL_18;
  if ( a3[3772] == a1 )
  {
    v14 = 3768;
    goto LABEL_8;
  }
  if ( v13 == 10 )
    goto LABEL_18;
  if ( a3[3794] == a1 )
  {
    v14 = 3790;
    goto LABEL_8;
  }
  if ( v13 == 11 )
    goto LABEL_18;
  if ( a3[3816] != a1 )
  {
    if ( v13 != 12 )
      goto LABEL_58;
LABEL_18:
    _warn_printk("Unable to find wb idx=%d\n", a1);
    __break(0x800u);
    kfree(v5);
    v5 = -22;
    goto LABEL_91;
  }
  v14 = 3812;
LABEL_8:
  v15 = (unsigned __int64)&a3[v14];
  v16 = *a3;
  v17 = a3[v14 + 5];
  v18 = a3[v14 + 6];
  *(_QWORD *)v11 = a2;
  *(_DWORD *)(v11 + 20) = v16;
  *(_DWORD *)(v11 + 24) = 256;
  *(_DWORD *)(v11 + 8) = v17;
  *(_DWORD *)(v11 + 12) = v18;
  if ( v15 >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_18;
  *(_DWORD *)(v11 + 48) = a1;
  *(_QWORD *)(v11 + 32) = a3;
  *(_QWORD *)(v11 + 40) = a3 + 162;
  v19 = *(_QWORD *)(v15 + 32);
  *(_QWORD *)(v11 + 56) = v15;
  *(_QWORD *)s = v19;
  *(_QWORD *)(v11 + 88) = sde_hw_wb_setup_outaddress;
  *(_QWORD *)(v11 + 112) = sde_hw_wb_setup_format;
  *(_QWORD *)(v11 + 280) = sde_hw_wb_setup_qos_lut;
  *(_QWORD *)(v11 + 232) = sde_hw_wb_roi;
  *(_QWORD *)(v11 + 520) = sde_hw_wb_get_ubwc_error;
  *(_QWORD *)(v11 + 544) = sde_hw_wb_clear_ubwc_error;
  if ( (*(_WORD *)s & 0x8000) != 0 )
  {
    *(_QWORD *)(v11 + 256) = sde_hw_wb_crop;
    if ( (*(_WORD *)s & 0x400) == 0 )
    {
LABEL_11:
      if ( (*(_WORD *)s & 0x800) == 0 )
        goto LABEL_12;
      goto LABEL_23;
    }
  }
  else if ( (*(_WORD *)s & 0x400) == 0 )
  {
    goto LABEL_11;
  }
  *(_QWORD *)(v11 + 304) = sde_hw_wb_setup_cdp;
  if ( (*(_WORD *)s & 0x800) == 0 )
  {
LABEL_12:
    if ( (*(_DWORD *)s & 0x20000) == 0 )
      goto LABEL_13;
    goto LABEL_24;
  }
LABEL_23:
  *(_QWORD *)(v11 + 328) = sde_hw_wb_bind_pingpong_blk;
  if ( (*(_DWORD *)s & 0x20000) == 0 )
  {
LABEL_13:
    if ( (*(_DWORD *)s & 0x40000) == 0 )
      goto LABEL_14;
    goto LABEL_25;
  }
LABEL_24:
  *(_QWORD *)(v11 + 376) = sde_hw_wb_program_cwb_ctrl;
  if ( (*(_DWORD *)s & 0x40000) == 0 )
  {
LABEL_14:
    if ( (*(_DWORD *)s & 0x10000) == 0 )
      goto LABEL_15;
LABEL_26:
    *(_QWORD *)(v11 + 424) = sde_hw_wb_setup_sys_cache;
    if ( (*(_DWORD *)s & 0x80000) == 0 )
      goto LABEL_35;
    goto LABEL_27;
  }
LABEL_25:
  *(_QWORD *)(v11 + 400) = sde_hw_wb_program_dcwb_ctrl;
  *(_QWORD *)(v11 + 352) = sde_hw_wb_bind_dcwb_pp_blk;
  if ( (*(_DWORD *)s & 0x10000) != 0 )
    goto LABEL_26;
LABEL_15:
  if ( (*(_DWORD *)s & 0x80000) == 0 )
    goto LABEL_35;
LABEL_27:
  v20 = *(_DWORD *)(*((_QWORD *)a3 + 1209) + 140LL);
  if ( v20 == 196608 )
  {
    v21 = sde_hw_wb_program_cwb_dither_ctrl_v3;
    goto LABEL_34;
  }
  if ( v20 == 0x20000 )
  {
    v21 = sde_hw_wb_program_cwb_dither_ctrl;
LABEL_34:
    *(_QWORD *)(v11 + 448) = v21;
  }
LABEL_35:
  if ( (*(_DWORD *)s & 0x100000) != 0 )
  {
    *(_QWORD *)(v11 + 472) = sde_hw_wb_get_line_count;
    *(_QWORD *)(v11 + 496) = sde_hw_wb_set_prog_line_count;
  }
  if ( (*(_DWORD *)s & 0x400000) != 0 )
    *(_QWORD *)(v11 + 568) = sde_hw_wb_get_frame_count;
  *(_QWORD *)(v11 + 592) = a4;
  if ( (*((_QWORD *)a3 + 2751) & 0x8000000000LL) != 0 )
  {
    if ( (unsigned int)(*(_DWORD *)(v15 + 80) - 15) > 2 )
    {
      printk(&unk_270FC4, "sde_hw_wb_init");
      v17 = *(_DWORD *)(v5 + 8);
      v18 = *(_DWORD *)(v5 + 12);
    }
    else
    {
      *(_QWORD *)a5 = v11;
      *(_DWORD *)(a5 + 8) = *(_DWORD *)(v15 + 80);
      *(_QWORD *)(a5 + 16) = sde_hw_wb_setup_clk_force_ctrl;
      *(_QWORD *)(a5 + 24) = sde_hw_wb_get_clk_ctrl_status;
    }
  }
  sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v15, v17, v18 + v17, *(_DWORD *)(v5 + 16));
  if ( (*(_QWORD *)(v15 + 32) & 0x20000) != 0 )
  {
    v22 = a3[4968];
    v49 = 0;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    *(_DWORD *)(v5 + 608) = v22;
    *(_DWORD *)(v5 + 612) = 32;
    v23 = *a3;
    v45 = 0;
    v46 = 0;
    *(_DWORD *)(v5 + 620) = v23;
    *(_DWORD *)(v5 + 624) = 256;
    v24 = a3[2404];
    *(_QWORD *)s = 0;
    v44 = 0;
    *(_QWORD *)(v5 + 600) = a2;
    if ( v24 )
    {
      v25 = 0;
      do
      {
        snprintf(s, 0x40u, "cwb%d", v25);
        v26 = *(_DWORD *)(v5 + 608) + a3[4972] * v25;
        sde_dbg_reg_register_dump_range((__int64)"sde", s, v26, v26 + *(_DWORD *)(v5 + 612), 255);
        ++v25;
      }
      while ( v25 < a3[2404] );
    }
  }
  if ( (*(_QWORD *)(v15 + 32) & 0x40000) == 0 )
    goto LABEL_91;
  v27 = a3[4973];
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  *(_QWORD *)s = 0;
  v44 = 0;
  if ( v27 < 2 )
    goto LABEL_50;
  v28 = a3[4968];
  v29 = *a3;
  *(_QWORD *)(v5 + 632) = a2;
  *(_DWORD *)(v5 + 644) = 32;
  *(_DWORD *)(v5 + 640) = v28;
  *(_DWORD *)(v5 + 652) = v29;
  *(_DWORD *)(v5 + 656) = 256;
  snprintf(s, 0x40u, "dcwb%d", 0);
  sde_dbg_reg_register_dump_range(
    (__int64)"sde",
    s,
    *(_DWORD *)(v5 + 640),
    *(_DWORD *)(v5 + 644) + *(_DWORD *)(v5 + 640),
    255);
  snprintf(s, 0x40u, "dcwb%d", 1);
  v30 = a3[4972] + *(_DWORD *)(v5 + 640);
  sde_dbg_reg_register_dump_range((__int64)"sde", s, v30, v30 + *(_DWORD *)(v5 + 644), 255);
  if ( (unsigned int)a3[4973] <= 3 )
    goto LABEL_50;
  v31 = a3[4969];
  v32 = *a3;
  *(_QWORD *)(v5 + 664) = a2;
  *(_DWORD *)(v5 + 676) = 32;
  *(_DWORD *)(v5 + 672) = v31;
  *(_DWORD *)(v5 + 684) = v32;
  *(_DWORD *)(v5 + 688) = 256;
  snprintf(s, 0x40u, "dcwb%d", 0);
  sde_dbg_reg_register_dump_range(
    (__int64)"sde",
    s,
    *(_DWORD *)(v5 + 672),
    *(_DWORD *)(v5 + 676) + *(_DWORD *)(v5 + 672),
    255);
  snprintf(s, 0x40u, "dcwb%d", 1);
  v33 = a3[4972] + *(_DWORD *)(v5 + 672);
  sde_dbg_reg_register_dump_range((__int64)"sde", s, v33, v33 + *(_DWORD *)(v5 + 676), 255);
  if ( (unsigned int)a3[4973] <= 5 )
  {
LABEL_50:
    v34 = (unsigned int)a3[2404];
    if ( !(_DWORD)v34 )
      goto LABEL_91;
    v35 = v34 << 6;
    v36 = 0;
    v12 = 0;
    while ( v36 != 832 )
    {
      if ( (*(_QWORD *)&a3[v36 / 4 + 2414] & 0x400) != 0 )
      {
        if ( v12 > 3 )
          goto LABEL_59;
        if ( (unsigned int)v12 > 3 )
          break;
        v37 = v5 + 696 + 472LL * (unsigned int)v12;
        v38 = a3[v36 / 4 + 2410];
        ++v12;
        *(_QWORD *)(v37 + 40) = &a3[v36 / 4 + 2406];
        v39 = a3[v36 / 4 + 2411];
        v40 = a3[v36 / 4 + 2412];
        *(_DWORD *)(v37 + 32) = v38;
        v41 = *a3;
        *(_QWORD *)v37 = a2;
        *(_DWORD *)(v37 + 8) = v39;
        *(_DWORD *)(v37 + 12) = v40;
        *(_DWORD *)(v37 + 20) = v41;
        *(_DWORD *)(v37 + 24) = 256;
      }
      v36 += 64LL;
      if ( v35 == v36 )
        goto LABEL_91;
    }
  }
LABEL_58:
  __break(0x5512u);
LABEL_59:
  _drm_err("Invalid dcwb pp count %d more than %d", v12, 4);
LABEL_91:
  _ReadStatusReg(SP_EL0);
  return v5;
}
