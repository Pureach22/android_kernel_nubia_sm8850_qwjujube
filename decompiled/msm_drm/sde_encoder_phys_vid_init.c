__int64 __fastcall sde_encoder_phys_vid_init(__int64 *a1, char a2)
{
  __int64 v4; // x19
  unsigned __int64 mdp; // x0
  int v6; // w8
  char v7; // w9
  int v8; // w4
  __int64 v9; // x8
  int v10; // w5
  int v11; // w9
  __int64 v12; // x10
  __int64 v13; // x13
  __int64 v14; // x8
  __int64 v15; // x11
  __int64 v16; // x12
  __int64 v17; // x10
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x10
  _QWORD *v21; // x10
  char v22; // w8
  int v23; // w4
  __int64 v24; // x8
  int v25; // w5
  __int64 v26; // x21
  int v27; // w4
  __int64 v28; // x8
  int v29; // w5

  if ( !a1 )
  {
    v26 = -22;
LABEL_37:
    printk(&unk_25ABD7, "sde_encoder_phys_vid_init");
    return v26;
  }
  v4 = _kmalloc_cache_noprof(kthread_park, 3520, 2776);
  if ( !v4 )
  {
    v26 = -12;
    goto LABEL_37;
  }
  mdp = sde_rm_get_mdp(*a1 + 2144);
  if ( !mdp || mdp > 0xFFFFFFFFFFFFF000LL )
  {
    LODWORD(v26) = mdp;
    printk(&unk_25AD8B, "sde_encoder_phys_vid_init");
    v26 = (int)v26;
    printk(&unk_25ABD7, "sde_encoder_phys_vid_init");
    if ( (_drm_debug & 4) != 0 )
    {
      if ( *(_QWORD *)v4 )
        v27 = *(_DWORD *)(*(_QWORD *)v4 + 24LL);
      else
        v27 = -1;
      v28 = *(_QWORD *)(v4 + 424);
      if ( v28 )
        v29 = *(_DWORD *)(v28 + 32) - 1;
      else
        v29 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v27, v29);
    }
    kfree(v4);
    return v26;
  }
  v6 = *((_DWORD *)a1 + 15);
  *(_QWORD *)(v4 + 408) = mdp;
  v7 = _drm_debug;
  *(_DWORD *)(v4 + 672) = v6;
  if ( (v7 & 4) == 0 )
    goto LABEL_12;
  if ( !*(_QWORD *)v4 )
  {
    v8 = -1;
    v9 = *(_QWORD *)(v4 + 424);
    if ( v9 )
      goto LABEL_8;
LABEL_10:
    v10 = -1;
    goto LABEL_11;
  }
  v8 = *(_DWORD *)(*(_QWORD *)v4 + 24LL);
  v9 = *(_QWORD *)(v4 + 424);
  if ( !v9 )
    goto LABEL_10;
LABEL_8:
  v10 = *(_DWORD *)(v9 + 32) - 1;
LABEL_11:
  _drm_dev_dbg(0, 0, 0, "enc%d intf%d \n", v8, v10);
LABEL_12:
  *(_QWORD *)(v4 + 32) = sde_encoder_phys_vid_is_master;
  *(_QWORD *)(v4 + 40) = sde_encoder_phys_vid_mode_fixup;
  *(_QWORD *)(v4 + 88) = sde_encoder_phys_vid_destroy;
  if ( (a2 & 1) != 0 )
  {
    v11 = 0;
  }
  else
  {
    *(_QWORD *)(v4 + 48) = sde_encoder_phys_vid_mode_set;
    *(_QWORD *)(v4 + 56) = sde_encoder_phys_vid_cont_splash_mode_set;
    *(_QWORD *)(v4 + 64) = &sde_encoder_phys_vid_enable;
    *(_QWORD *)(v4 + 72) = sde_encoder_phys_vid_disable;
    *(_QWORD *)(v4 + 96) = &sde_encoder_phys_vid_get_hw_resources;
    *(_QWORD *)(v4 + 104) = sde_encoder_phys_vid_control_vblank_irq;
    *(_QWORD *)(v4 + 112) = sde_encoder_phys_vid_control_esync_vsync_irq;
    *(_QWORD *)(v4 + 120) = sde_encoder_phys_vid_control_empulse_irq;
    *(_QWORD *)(v4 + 128) = sde_encoder_phys_vid_wait_for_commit_done;
    *(_QWORD *)(v4 + 136) = sde_encoder_phys_vid_wait_for_vblank;
    *(_QWORD *)(v4 + 224) = sde_encoder_phys_vid_irq_control;
    *(_QWORD *)(v4 + 144) = sde_encoder_phys_vid_wait_for_vblank_no_notify;
    *(_QWORD *)(v4 + 152) = &sde_encoder_phys_vid_prepare_for_kickoff;
    *(_QWORD *)(v4 + 248) = &sde_encoder_phys_vid_connect_te;
    *(_QWORD *)(v4 + 192) = sde_encoder_phys_needs_single_flush;
    *(_QWORD *)(v4 + 200) = &sde_encoder_helper_setup_misr;
    *(_QWORD *)(v4 + 160) = sde_encoder_phys_vid_handle_post_kickoff;
    *(_QWORD *)(v4 + 168) = &sde_encoder_helper_trigger_flush;
    *(_QWORD *)(v4 + 208) = sde_encoder_helper_collect_misr;
    *(_QWORD *)(v4 + 216) = &sde_encoder_helper_hw_reset;
    *(_QWORD *)(v4 + 272) = sde_encoder_phys_vid_get_line_count;
    *(_QWORD *)(v4 + 280) = &sde_encoder_phys_vid_wait_dma_trigger;
    *(_QWORD *)(v4 + 288) = &sde_encoder_phys_vid_wait_for_active;
    *(_QWORD *)(v4 + 296) = &sde_encoder_phys_vid_setup_vsync_source;
    *(_QWORD *)(v4 + 24) = sde_encoder_phys_vid_prepare_for_commit;
    *(_QWORD *)(v4 + 304) = sde_encoder_phys_vid_get_underrun_line_count;
    *(_QWORD *)(v4 + 312) = sde_encoder_phys_vid_add_enc_to_minidump;
    *(_QWORD *)(v4 + 336) = sde_encoder_phys_vid_cesta_ctrl_cfg;
    *(_QWORD *)(v4 + 344) = sde_encoder_phys_vid_idle_pc_enter;
    v11 = 2;
    *(_QWORD *)(v4 + 352) = sde_encoder_phys_vid_idle_pc_exit;
  }
  v13 = *a1;
  v12 = a1[1];
  v14 = 0;
  v15 = a1[4];
  v16 = a1[5];
  *(_DWORD *)(v4 + 668) = v11;
  *(_QWORD *)v4 = v12;
  v17 = a1[6];
  *(_QWORD *)(v4 + 384) = v15;
  *(_QWORD *)(v4 + 392) = v16;
  *(_QWORD *)(v4 + 400) = v17;
  v18 = a1[2];
  v19 = a1[3];
  *(_QWORD *)(v4 + 512) = v13;
  *(_QWORD *)(v4 + 368) = v18;
  *(_QWORD *)(v4 + 376) = v19;
  *(_DWORD *)(v4 + 664) = *((_DWORD *)a1 + 14);
  v20 = a1[9];
  *(_QWORD *)(v4 + 840) = a1[10];
  *(_QWORD *)(v4 + 824) = v20;
  LODWORD(v20) = *((_DWORD *)a1 + 17);
  *(_DWORD *)(v4 + 992) = 84;
  *(_DWORD *)(v4 + 800) = v20;
  do
  {
    v21 = (_QWORD *)(v4 + v14);
    v14 += 56;
    v21[128] = v21 + 128;
    v21[129] = v21 + 128;
    v21[127] = 0xFFFFFFEAFFFFFFEALL;
    v21[131] = v4;
  }
  while ( v14 != 1288 );
  if ( (a2 & 1) == 0 )
  {
    *(_QWORD *)(v4 + 1000) = "vsync_irq";
    *(_QWORD *)(v4 + 1008) = 9;
    *(_QWORD *)(v4 + 1040) = sde_encoder_phys_vid_vblank_irq;
    *(_QWORD *)(v4 + 2232) = "te_deassert";
    *(_QWORD *)(v4 + 1280) = "esync_vsync_irq";
    *(_QWORD *)(v4 + 2240) = 0x1600000022LL;
    *(_QWORD *)(v4 + 2272) = &sde_encoder_phys_vid_te_irq;
    *(_QWORD *)(v4 + 1168) = "wd_irq";
    *(_QWORD *)(v4 + 1176) = 0x300000010LL;
    *(_QWORD *)(v4 + 1288) = 0x500000028LL;
    *(_QWORD *)(v4 + 1208) = sde_encoder_phys_vid_wb_irq;
    *(_QWORD *)(v4 + 1112) = "underrun";
    *(_QWORD *)(v4 + 1120) = 0x200000008LL;
    *(_QWORD *)(v4 + 1152) = sde_encoder_phys_vid_underrun_irq;
    *(_QWORD *)(v4 + 1224) = "esync_irq";
    *(_QWORD *)(v4 + 1232) = 0x400000027LL;
    *(_QWORD *)(v4 + 1264) = sde_encoder_phys_vid_esync_emsync_irq;
    *(_QWORD *)(v4 + 1320) = sde_encoder_phys_vid_esync_emsync_irq;
    *(_DWORD *)(v4 + 848) = 0;
    *(_DWORD *)(v4 + 876) = 0;
    *(_DWORD *)(v4 + 880) = 0;
    *(_DWORD *)(v4 + 888) = 0;
    _init_waitqueue_head(v4 + 896, "&phys_enc->pending_kickoff_wq", &sde_encoder_phys_vid_init___key);
  }
  *(_DWORD *)(v4 + 832) = 1;
  hrtimer_init(v4 + 2416, 1, 1);
  *(_QWORD *)(v4 + 2456) = sde_encoder_phys_vid_freq_step_callback;
  hrtimer_init(v4 + 2480, 1, 1);
  *(_QWORD *)(v4 + 2520) = &sde_encoder_phys_vid_arp_transition_timer_cb;
  hrtimer_init(v4 + 2544, 1, 1);
  *(_QWORD *)(v4 + 2584) = sde_encoder_phys_phys_self_refresh_helper;
  hrtimer_init(v4 + 2616, 1, 1);
  *(_QWORD *)(v4 + 2656) = &sde_encoder_phys_backlight_timer_cb;
  hrtimer_init(v4 + 920, 1, 1);
  v22 = _drm_debug;
  *(_QWORD *)(v4 + 960) = sde_encoder_phys_vid_esync_backup_sim;
  if ( (v22 & 4) != 0 )
  {
    if ( *(_QWORD *)v4 )
    {
      v23 = *(_DWORD *)(*(_QWORD *)v4 + 24LL);
      v24 = *(_QWORD *)(v4 + 424);
      if ( v24 )
      {
LABEL_22:
        v25 = *(_DWORD *)(v24 + 32) - 1;
LABEL_25:
        _drm_dev_dbg(0, 0, 0, "enc%d intf%d created intf idx:%d\n", v23, v25, *((_DWORD *)a1 + 15));
        return v4;
      }
    }
    else
    {
      v23 = -1;
      v24 = *(_QWORD *)(v4 + 424);
      if ( v24 )
        goto LABEL_22;
    }
    v25 = -1;
    goto LABEL_25;
  }
  return v4;
}
