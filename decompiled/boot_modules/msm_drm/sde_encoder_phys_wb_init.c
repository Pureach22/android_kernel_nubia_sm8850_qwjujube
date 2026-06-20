__int64 __fastcall sde_encoder_phys_wb_init(__int64 *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x10
  __int64 v7; // x8
  unsigned __int64 mdp; // x0
  int v9; // w8
  __int64 v10; // x8
  __int64 v11; // x11
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x9
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x9
  _QWORD *v20; // x11
  __int64 v21; // x8
  __int64 v22; // x10
  __int64 v23; // x10
  int v24; // w9
  int v25; // w17
  int v26; // w10
  int v27; // w0
  const char *v28; // x11
  const char *v29; // x1
  __int64 v30; // x12
  __int64 v31; // x13
  __int64 v32; // x14
  __int64 v33; // x15
  __int64 v34; // x16
  __int64 v35; // x2
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  __int64 v40; // x17
  __int64 v41; // x8
  __int64 v42; // x9
  __int64 v43; // x20
  __int64 v44; // x21
  unsigned int framebuffer_size; // w0
  unsigned int v46; // w24
  __int64 format_info; // x0
  unsigned int v48; // w22
  unsigned __int8 *v49; // x23
  unsigned __int64 v50; // x0
  unsigned __int64 *v51; // x24
  unsigned __int64 v52; // x0
  unsigned __int64 v53; // x21
  int v54; // w4
  __int64 v55; // x8
  int v56; // w5
  __int64 v57; // x20
  int v58; // w4
  int v60; // w20
  __int64 v61; // x8
  int v62; // w5
  int v69; // w8
  __int128 v70; // [xsp+0h] [xbp-70h] BYREF
  __int64 v71; // [xsp+10h] [xbp-60h]
  __int64 v72; // [xsp+18h] [xbp-58h]
  __int64 v73; // [xsp+20h] [xbp-50h] BYREF
  __int64 v74; // [xsp+28h] [xbp-48h]
  __int64 v75; // [xsp+30h] [xbp-40h]
  __int64 v76; // [xsp+38h] [xbp-38h]
  __int64 v77; // [xsp+40h] [xbp-30h]
  __int64 v78; // [xsp+48h] [xbp-28h]
  __int64 v79; // [xsp+50h] [xbp-20h]
  __int64 v80; // [xsp+58h] [xbp-18h]
  __int64 v81; // [xsp+60h] [xbp-10h]
  __int64 v82; // [xsp+68h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "\n");
  if ( !a1 || !a1[1] )
  {
    printk(&unk_223EAA, "sde_encoder_phys_wb_init");
    v57 = -22;
LABEL_76:
    v3 = v57;
    goto LABEL_77;
  }
  v2 = _kmalloc_cache_noprof(kthread_park, 3520, 2952);
  v3 = v2;
  if ( !v2 )
  {
    printk(&unk_24D96D, "sde_encoder_phys_wb_init");
    v57 = -12;
    goto LABEL_76;
  }
  v4 = *a1;
  *(_DWORD *)(v2 + 992) = 84;
  v5 = 1712;
  if ( !*(_QWORD *)(v4 + 1768) )
    v5 = 1704;
  v6 = 1728;
  v7 = *(_QWORD *)(v4 + v5);
  if ( !*(_QWORD *)(v4 + 1768) )
    v6 = 1720;
  *(_QWORD *)(v2 + 2848) = v7;
  *(_QWORD *)(v2 + 2856) = *(_QWORD *)(v4 + v6);
  mdp = sde_rm_get_mdp(v4 + 2144);
  if ( !mdp || mdp >= 0xFFFFFFFFFFFFF001LL )
  {
    LODWORD(v57) = mdp;
    printk(&unk_2510D9, "sde_encoder_phys_wb_init");
    v57 = (int)v57;
LABEL_75:
    kfree(v3);
    goto LABEL_76;
  }
  v9 = *((_DWORD *)a1 + 16);
  *(_QWORD *)(v3 + 408) = mdp;
  if ( !v9 )
  {
    printk(&unk_25C090, "sde_encoder_phys_wb_init");
LABEL_56:
    v57 = -22;
    goto LABEL_75;
  }
  v71 = 0;
  v70 = 0u;
  sde_rm_init_hw_iter((__int64)&v70, 0, 9);
  do
  {
    if ( (sde_rm_get_hw(*a1 + 2144, (__int64)&v70) & 1) == 0 )
    {
      if ( !*(_QWORD *)(v3 + 2680) )
        goto LABEL_17;
      goto LABEL_19;
    }
    v10 = v70;
  }
  while ( *(_DWORD *)(v70 + 48) != *((_DWORD *)a1 + 16) );
  *(_QWORD *)(v3 + 2680) = v70;
  if ( !v10 )
  {
LABEL_17:
    printk(&unk_25FBAE, "sde_encoder_phys_wb_init");
    goto LABEL_56;
  }
LABEL_19:
  *(_QWORD *)(v3 + 16) = sde_encoder_phys_wb_late_register;
  v11 = a1[2];
  *(_QWORD *)(v3 + 32) = sde_encoder_phys_wb_is_master;
  *(_QWORD *)(v3 + 48) = sde_encoder_phys_wb_mode_set;
  *(_QWORD *)(v3 + 64) = sde_encoder_phys_wb_enable;
  *(_QWORD *)(v3 + 72) = sde_encoder_phys_wb_disable;
  *(_QWORD *)(v3 + 80) = sde_encoder_phys_wb_atomic_check;
  *(_QWORD *)(v3 + 88) = sde_encoder_phys_wb_destroy;
  *(_QWORD *)(v3 + 96) = &sde_encoder_phys_wb_get_hw_resources;
  *(_QWORD *)(v3 + 368) = v11;
  *(_QWORD *)(v3 + 128) = sde_encoder_phys_wb_wait_for_commit_done;
  *(_QWORD *)(v3 + 136) = sde_encoder_phys_wb_wait_for_tx_complete;
  *(_QWORD *)(v3 + 152) = sde_encoder_phys_wb_prepare_for_kickoff;
  *(_QWORD *)(v3 + 168) = sde_encoder_phys_wb_trigger_flush;
  *(_QWORD *)(v3 + 176) = &sde_encoder_helper_trigger_start;
  *(_QWORD *)(v3 + 216) = &sde_encoder_helper_hw_reset;
  *(_QWORD *)(v3 + 224) = sde_encoder_phys_wb_irq_ctrl;
  v13 = *a1;
  v12 = a1[1];
  *(_QWORD *)(v3 + 312) = sde_encoder_phys_wb_add_enc_to_minidump;
  *(_QWORD *)(v3 + 336) = sde_encoder_phys_wb_cesta_ctrl_cfg;
  *(_QWORD *)v3 = v12;
  v15 = a1[5];
  v14 = a1[6];
  *(_QWORD *)(v3 + 512) = v13;
  *(_QWORD *)(v3 + 392) = v15;
  *(_QWORD *)(v3 + 400) = v14;
  v16 = a1[4];
  *(_QWORD *)(v3 + 376) = a1[3];
  *(_QWORD *)(v3 + 384) = v16;
  LODWORD(v16) = *((_DWORD *)a1 + 15);
  *(_DWORD *)(v3 + 664) = *((_DWORD *)a1 + 14);
  *(_DWORD *)(v3 + 668) = 4;
  v17 = a1[9];
  *(_DWORD *)(v3 + 672) = v16;
  *(_QWORD *)(v3 + 824) = v17;
  *(_DWORD *)(v3 + 880) = 0;
  *(_DWORD *)(v3 + 876) = 0;
  *(_DWORD *)(v3 + 884) = 0;
  _init_waitqueue_head(v3 + 896, "&phys_enc->pending_kickoff_wq", &sde_encoder_phys_wb_init___key);
  v18 = 0;
  v19 = *(_QWORD *)(*(_QWORD *)(v3 + 2680) + 56LL);
  do
  {
    v20 = (_QWORD *)(v3 + v18);
    v18 += 56;
    v20[128] = v20 + 128;
    v20[129] = v20 + 128;
    v20[127] = 0xFFFFFFEAFFFFFFEALL;
    v20[131] = v3;
  }
  while ( v18 != 1288 );
  v21 = *(_QWORD *)(v3 + 2680);
  *(_QWORD *)(v3 + 1560) = "wb_done";
  *(_DWORD *)(v3 + 1576) = *(_DWORD *)(v21 + 48);
  v22 = *(_QWORD *)(*(_QWORD *)(v21 + 56) + 32LL);
  *(_DWORD *)(v3 + 1572) = 10;
  *(_QWORD *)(v3 + 1600) = sde_encoder_phys_wb_done_irq;
  *(_QWORD *)(v3 + 1336) = "ctl_start";
  *(_QWORD *)(v3 + 1344) = 0x60000001BLL;
  *(_QWORD *)(v3 + 2064) = "lineptr_irq";
  *(_QWORD *)(v3 + 1376) = sde_encoder_phys_wb_ctl_start_irq;
  *(_DWORD *)(v3 + 1568) = (v22 & 4) == 0;
  LODWORD(v21) = *(_DWORD *)(v21 + 48);
  *(_QWORD *)(v3 + 2072) = 0x1300000025LL;
  *(_DWORD *)(v3 + 2080) = v21;
  *(_QWORD *)(v3 + 2104) = sde_encoder_phys_wb_lineptr_irq;
  if ( v19 )
  {
    v23 = *(_QWORD *)(v19 + 32);
    if ( (v23 & 0x2000) != 0 )
    {
      v40 = *(_QWORD *)(v19 + 32);
      v24 = 16;
      v28 = "pp_cwb0_overflow";
      v26 = 9;
      v30 = 1936;
      v31 = 1908;
      v32 = 1904;
      v33 = 1912;
      v34 = 1896;
      if ( (v40 & 0x4000) == 0 )
      {
LABEL_28:
        *(_QWORD *)(v3 + v34) = v28;
        *(_DWORD *)(v3 + v33) = v26;
        *(_DWORD *)(v3 + v32) = 10;
        *(_DWORD *)(v3 + v31) = v24;
        *(_QWORD *)(v3 + v30) = sde_encoder_phys_cwb_ovflow;
        goto LABEL_29;
      }
      v25 = 17;
      v29 = "pp_cwb2_overflow";
      v27 = 11;
      v35 = 1992;
      v36 = 1964;
      v37 = 1960;
      v38 = 1968;
      v39 = 1952;
LABEL_27:
      *(_QWORD *)(v3 + v39) = v29;
      *(_DWORD *)(v3 + v38) = v27;
      *(_DWORD *)(v3 + v37) = 10;
      *(_DWORD *)(v3 + v36) = v25;
      *(_QWORD *)(v3 + v35) = sde_encoder_phys_cwb_ovflow;
      goto LABEL_28;
    }
    if ( (v23 & 0x1000) != 0 )
    {
      *(_QWORD *)(v3 + 1616) = "pp1_overflow";
      *(_DWORD *)(v3 + 1632) = 2;
      *(_QWORD *)(v3 + 1624) = 0xB0000000ALL;
      *(_QWORD *)(v3 + 1672) = "pp2_overflow";
      v24 = 15;
      v25 = 14;
      *(_DWORD *)(v3 + 1688) = 3;
      v26 = 6;
      v27 = 5;
      *(_QWORD *)(v3 + 1680) = 0xC0000000ALL;
      v28 = "pp5_overflow";
      *(_QWORD *)(v3 + 1728) = "pp3_overflow";
      v29 = "pp4_overflow";
      *(_DWORD *)(v3 + 1744) = 4;
      v30 = 1880;
      v31 = 1852;
      *(_QWORD *)(v3 + 1736) = 0xD0000000ALL;
      v32 = 1848;
      v33 = 1856;
      v34 = 1840;
      v35 = 1824;
      v36 = 1796;
      v37 = 1792;
      v38 = 1800;
      v39 = 1784;
      *(_QWORD *)(v3 + 1656) = sde_encoder_phys_cwb_ovflow;
      *(_QWORD *)(v3 + 1712) = sde_encoder_phys_cwb_ovflow;
      *(_QWORD *)(v3 + 1768) = sde_encoder_phys_cwb_ovflow;
      goto LABEL_27;
    }
  }
LABEL_29:
  v41 = *(_QWORD *)v3;
  v80 = 0;
  v81 = 0;
  v78 = 0;
  v79 = 0;
  v76 = 0;
  v77 = 0;
  v74 = 0;
  v75 = 0;
  v72 = 0;
  v73 = 0;
  v71 = 0;
  v70 = 0u;
  if ( !v41 || (v42 = *(_QWORD *)(v3 + 512)) == 0 )
  {
    printk(&unk_223EAA, "_sde_encoder_phys_wb_init_internal_fb");
    goto LABEL_74;
  }
  v43 = *(_QWORD *)(v42 + 1704);
  if ( !v43 )
  {
    printk(&unk_22F838, "_sde_encoder_phys_wb_init_internal_fb");
    goto LABEL_74;
  }
  v44 = *(_QWORD *)(v42 + 136);
  if ( !v44 )
  {
    printk(&unk_225686, "_sde_encoder_phys_wb_init_internal_fb");
    goto LABEL_74;
  }
  HIDWORD(v70) = 875710290;
  *(_QWORD *)((char *)&v70 + 4) = 0x100000002LL;
  HIDWORD(v73) = 6;
  framebuffer_size = sde_format_get_framebuffer_size(875710290, 2u, 1u, (_DWORD *)&v73 + 1, 0);
  if ( !framebuffer_size )
  {
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)v3 )
        v58 = *(_DWORD *)(*(_QWORD *)v3 + 24LL);
      else
        v58 = -1;
      v61 = *(_QWORD *)(v3 + 2864);
      if ( v61 )
        v62 = *(_DWORD *)(v61 + 12) - 1;
      else
        v62 = -1;
      _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] invalid fbsize\n", v58, v62);
    }
    goto LABEL_74;
  }
  v46 = framebuffer_size;
  format_info = drm_get_format_info(v44, &v70);
  v48 = *(unsigned __int8 *)(format_info + 5);
  if ( v48 >= 4 )
  {
    printk(&unk_2404B8, "_sde_encoder_phys_wb_init_internal_fb");
    goto LABEL_74;
  }
  v49 = (unsigned __int8 *)format_info;
  v50 = msm_gem_new(v44, v46, 131073);
  *(_QWORD *)(v3 + 2872) = v50;
  if ( v50 && v50 <= 0xFFFFFFFFFFFFF000LL )
  {
    v51 = (unsigned __int64 *)(v3 + 2872);
    if ( v48 )
    {
      *v51 = v50;
      HIDWORD(v73) = 2 * v49[6];
      if ( v48 != 1 )
      {
        *(_QWORD *)(v3 + 2880) = v50;
        LODWORD(v74) = 2 * v49[7];
        if ( v48 != 2 )
        {
          *(_QWORD *)(v3 + 2888) = v50;
          HIDWORD(v74) = 2 * v49[8];
        }
      }
    }
    v52 = msm_framebuffer_init(v44, &v70, v3 + 2872);
    v53 = v52;
    if ( v52 && v52 < 0xFFFFFFFFFFFFF001LL )
    {
      if ( !(unsigned int)msm_framebuffer_prepare(v52, v43) )
      {
        *(_QWORD *)(v3 + 2904) = v53;
        goto LABEL_45;
      }
      goto LABEL_74;
    }
    _X0 = (unsigned int *)*v51;
    if ( *v51 )
    {
      __asm { PRFM            #0x11, [X0] }
      do
        v69 = __ldxr(_X0);
      while ( __stlxr(v69 - 1, _X0) );
      if ( v69 == 1 )
      {
        __dmb(9u);
        drm_gem_object_free(_X0);
      }
      else if ( v69 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    *(_QWORD *)(v3 + 2872) = 0;
    printk(&unk_2472DD, "_sde_encoder_phys_wb_init_internal_fb");
    if ( (_DWORD)v53 )
    {
LABEL_74:
      printk(&unk_22F6E5, "sde_encoder_phys_wb_init");
      v57 = 0;
      goto LABEL_75;
    }
  }
  else
  {
    *(_QWORD *)(v3 + 2872) = 0;
    v60 = v50;
    printk(&unk_21ADE6, "_sde_encoder_phys_wb_init_internal_fb");
    if ( v60 )
      goto LABEL_74;
  }
LABEL_45:
  if ( (_drm_debug & 4) != 0 )
  {
    if ( *(_QWORD *)v3 )
    {
      v54 = *(_DWORD *)(*(_QWORD *)v3 + 24LL);
      v55 = *(_QWORD *)(v3 + 2864);
      if ( v55 )
      {
LABEL_48:
        v56 = *(_DWORD *)(v55 + 12) - 1;
LABEL_52:
        _drm_dev_dbg(0, 0, 0, "[enc:%d wb:%d] Created wb_phys\n", v54, v56);
        goto LABEL_77;
      }
    }
    else
    {
      v54 = -1;
      v55 = *(_QWORD *)(v3 + 2864);
      if ( v55 )
        goto LABEL_48;
    }
    v56 = -1;
    goto LABEL_52;
  }
LABEL_77:
  _ReadStatusReg(SP_EL0);
  return v3;
}
