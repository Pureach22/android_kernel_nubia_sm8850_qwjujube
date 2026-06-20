__int64 __fastcall sde_encoder_phys_cmd_init(__int64 *a1)
{
  __int64 v2; // x19
  unsigned __int64 mdp; // x0
  __int64 v4; // x11
  __int64 v5; // x13
  int v6; // w8
  int v7; // w12
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x14
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x9
  unsigned int v16; // w8
  __int64 v17; // x8
  _QWORD *v18; // x10
  char v19; // w8
  int v20; // w4
  int v22; // w20
  unsigned __int64 StatusReg; // x22
  __int64 v24; // x23

  if ( (_drm_debug & 4) != 0 )
    _drm_dev_dbg(0, 0, 0, "intf %d\n", *((_DWORD *)a1 + 15) - 1);
  v2 = _kmalloc_cache_noprof(kthread_park, 3520, 2912);
  if ( v2 )
  {
    while ( 1 )
    {
      mdp = sde_rm_get_mdp(*a1 + 2144);
      if ( !mdp || mdp >= 0xFFFFFFFFFFFFF001LL )
      {
        v22 = mdp;
        printk(&unk_25AD8B, "sde_encoder_phys_cmd_init");
        kfree(v2);
        return v22;
      }
      v4 = a1[3];
      v5 = a1[4];
      *(_DWORD *)(v2 + 2680) = 0;
      v7 = *((_DWORD *)a1 + 14);
      v6 = *((_DWORD *)a1 + 15);
      v8 = *a1;
      v9 = a1[1];
      *(_QWORD *)(v2 + 376) = v4;
      *(_QWORD *)(v2 + 384) = v5;
      v11 = a1[5];
      v10 = a1[6];
      *(_DWORD *)(v2 + 664) = v7;
      *(_QWORD *)v2 = v9;
      v12 = a1[2];
      *(_QWORD *)(v2 + 400) = v10;
      *(_QWORD *)(v2 + 408) = mdp;
      v13 = a1[9];
      v14 = a1[10];
      *(_DWORD *)(v2 + 672) = v6;
      *(_QWORD *)(v2 + 392) = v11;
      *(_QWORD *)(v2 + 824) = v13;
      *(_DWORD *)(v2 + 668) = 1;
      *(_DWORD *)(v2 + 832) = 1;
      *(_QWORD *)(v2 + 840) = v14;
      *(_DWORD *)(v2 + 992) = 84;
      *(_QWORD *)(v2 + 24) = sde_encoder_phys_cmd_prepare_commit;
      *(_QWORD *)(v2 + 32) = sde_encoder_phys_cmd_is_master;
      *(_QWORD *)(v2 + 512) = v8;
      *(_QWORD *)(v2 + 40) = sde_encoder_phys_cmd_mode_fixup;
      *(_QWORD *)(v2 + 48) = sde_encoder_phys_cmd_mode_set;
      *(_QWORD *)(v2 + 56) = sde_encoder_phys_cmd_cont_splash_mode_set;
      *(_QWORD *)(v2 + 64) = sde_encoder_phys_cmd_enable;
      *(_QWORD *)(v2 + 72) = &sde_encoder_phys_cmd_disable;
      *(_QWORD *)(v2 + 88) = sde_encoder_phys_cmd_destroy;
      *(_QWORD *)(v2 + 96) = &sde_encoder_phys_cmd_get_hw_resources;
      *(_QWORD *)(v2 + 104) = sde_encoder_phys_cmd_control_vblank_irq;
      *(_QWORD *)(v2 + 128) = sde_encoder_phys_cmd_wait_for_commit_done;
      *(_QWORD *)(v2 + 136) = sde_encoder_phys_cmd_wait_for_tx_complete;
      *(_QWORD *)(v2 + 144) = sde_encoder_phys_cmd_wait_for_vblank;
      *(_QWORD *)(v2 + 152) = &sde_encoder_phys_cmd_prepare_for_kickoff;
      *(_QWORD *)(v2 + 176) = sde_encoder_phys_cmd_trigger_start;
      *(_QWORD *)(v2 + 224) = sde_encoder_phys_cmd_irq_control;
      *(_QWORD *)(v2 + 232) = sde_encoder_phys_cmd_dynamic_irq_control;
      *(_QWORD *)(v2 + 240) = sde_encoder_phys_cmd_update_split_role;
      *(_QWORD *)(v2 + 248) = sde_encoder_phys_cmd_connect_te;
      *(_QWORD *)(v2 + 256) = sde_encoder_phys_cmd_enable_helper;
      *(_QWORD *)(v2 + 264) = &sde_encoder_phys_cmd_is_autorefresh_enabled;
      *(_QWORD *)(v2 + 272) = &sde_encoder_phys_cmd_te_get_line_count;
      *(_QWORD *)(v2 + 288) = 0;
      *(_QWORD *)(v2 + 296) = &sde_encoder_phys_cmd_setup_vsync_source;
      *(_QWORD *)(v2 + 192) = sde_encoder_phys_needs_single_flush_0;
      *(_QWORD *)(v2 + 200) = &sde_encoder_helper_setup_misr;
      *(_QWORD *)(v2 + 208) = sde_encoder_helper_collect_misr;
      *(_QWORD *)(v2 + 216) = &sde_encoder_helper_hw_reset;
      *(_QWORD *)(v2 + 312) = sde_encoder_phys_cmd_add_enc_to_minidump;
      *(_QWORD *)(v2 + 320) = &sde_encoder_phys_disable_autorefresh;
      *(_QWORD *)(v2 + 160) = sde_encoder_phys_cmd_handle_post_kickoff;
      *(_QWORD *)(v2 + 168) = &sde_encoder_helper_trigger_flush;
      *(_QWORD *)(v2 + 328) = &sde_encoder_phys_cmd_store_ltj_values;
      *(_QWORD *)(v2 + 336) = sde_encoder_phys_cmd_cesta_ctrl_cfg;
      LODWORD(v14) = *((_DWORD *)a1 + 17);
      *(_QWORD *)(v2 + 360) = sde_encoder_phys_wait_for_vsync_on_autorefresh_busy;
      *(_QWORD *)(v2 + 368) = v12;
      *(_DWORD *)(v2 + 800) = v14;
      v15 = *(_QWORD *)(v8 + 152);
      if ( !v15 )
        break;
      v16 = v6 - 1;
      if ( v16 >= *(_DWORD *)(v15 + 13400) )
      {
        LOBYTE(v15) = 0;
        break;
      }
      if ( v16 < 0xC )
      {
        v15 = (*(_QWORD *)(v15 + 72LL * v16 + 13440) >> 2) & 1LL;
        break;
      }
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &sde_encoder_phys_cmd_init__alloc_tag;
      v2 = _kmalloc_cache_noprof(kthread_park, 3520, 2912);
      *(_QWORD *)(StatusReg + 80) = v24;
      if ( !v2 )
        goto LABEL_24;
    }
    *(_BYTE *)(v2 + 2288) = v15;
    v17 = 0;
    do
    {
      v18 = (_QWORD *)(v2 + v17);
      v17 += 56;
      v18[128] = v18 + 128;
      v18[129] = v18 + 128;
      v18[127] = 0xFFFFFFEAFFFFFFEALL;
      v18[131] = v2;
    }
    while ( v17 != 1288 );
    *(_QWORD *)(v2 + 1336) = "ctl_start";
    *(_QWORD *)(v2 + 1448) = "te_rd_ptr";
    *(_QWORD *)(v2 + 1344) = 0x60000001BLL;
    *(_QWORD *)(v2 + 1392) = "ctl_done";
    *(_QWORD *)(v2 + 1376) = 0;
    *(_QWORD *)(v2 + 1400) = 0x70000001CLL;
    *(_QWORD *)(v2 + 1432) = sde_encoder_phys_cmd_ctl_done_irq;
    *(_QWORD *)(v2 + 1056) = "pp_done";
    *(_QWORD *)(v2 + 1064) = 0x100000002LL;
    *(_QWORD *)(v2 + 1096) = sde_encoder_phys_cmd_pp_tx_done_irq;
    *(_DWORD *)(v2 + 1460) = 8;
    if ( (*(_BYTE *)(v2 + 2288) & 1) != 0 )
    {
      *(_QWORD *)(v2 + 1488) = sde_encoder_phys_cmd_te_rd_ptr_irq;
      *(_DWORD *)(v2 + 1456) = 29;
      *(_QWORD *)(v2 + 1504) = "autorefresh_done";
      *(_QWORD *)(v2 + 1512) = 0x90000001FLL;
      *(_QWORD *)(v2 + 1544) = sde_encoder_phys_cmd_autorefresh_done_irq;
      *(_QWORD *)(v2 + 2008) = "wr_ptr";
      *(_QWORD *)(v2 + 2016) = 0x120000001ELL;
      *(_QWORD *)(v2 + 2048) = sde_encoder_phys_cmd_wr_ptr_irq;
      *(_QWORD *)(v2 + 2120) = "te_tear_detect";
      *(_QWORD *)(v2 + 2128) = 0x1400000020LL;
      *(_QWORD *)(v2 + 2176) = "te_assert";
      *(_QWORD *)(v2 + 2184) = 0x1500000021LL;
      *(_QWORD *)(v2 + 2216) = sde_encoder_phys_cmd_te_assert_irq;
      *(_QWORD *)(v2 + 2232) = "te_deassert";
      *(_QWORD *)(v2 + 2240) = 0x1600000022LL;
      *(_QWORD *)(v2 + 2272) = sde_encoder_phys_cmd_te_deassert_irq;
    }
    else
    {
      *(_QWORD *)(v2 + 1488) = sde_encoder_phys_cmd_te_rd_ptr_irq;
      *(_DWORD *)(v2 + 1456) = 3;
      *(_QWORD *)(v2 + 1504) = "autorefresh_done";
      *(_QWORD *)(v2 + 1512) = 0x900000005LL;
      *(_QWORD *)(v2 + 1544) = sde_encoder_phys_cmd_autorefresh_done_irq;
      *(_QWORD *)(v2 + 2008) = "wr_ptr";
      *(_QWORD *)(v2 + 2016) = 0x1200000004LL;
      *(_QWORD *)(v2 + 2048) = sde_encoder_phys_cmd_wr_ptr_irq;
      *(_QWORD *)(v2 + 2120) = "te_tear_detect";
      *(_QWORD *)(v2 + 2128) = 0x1400000006LL;
    }
    *(_QWORD *)(v2 + 2160) = sde_encoder_phys_cmd_tear_detect_irq;
    *(_DWORD *)(v2 + 848) = 0;
    *(_DWORD *)(v2 + 876) = 0;
    *(_DWORD *)(v2 + 880) = 0;
    *(_DWORD *)(v2 + 2728) = 0;
    _init_waitqueue_head(v2 + 896, "&phys_enc->pending_kickoff_wq", &sde_encoder_phys_cmd_init___key);
    _init_waitqueue_head(v2 + 2736, "&cmd_enc->pending_vblank_wq", &sde_encoder_phys_cmd_init___key_11);
    *(_DWORD *)(v2 + 2696) = 0;
    _init_waitqueue_head(v2 + 2704, "&cmd_enc->autorefresh.kickoff_wq", &sde_encoder_phys_cmd_init___key_13);
    *(_QWORD *)(v2 + 2768) = v2 + 2768;
    *(_QWORD *)(v2 + 2776) = v2 + 2768;
    *(_QWORD *)(v2 + 2776) = v2 + 2784;
    *(_QWORD *)(v2 + 2784) = v2 + 2768;
    *(_QWORD *)(v2 + 2768) = v2 + 2784;
    *(_QWORD *)(v2 + 2808) = v2 + 2784;
    *(_QWORD *)(v2 + 2792) = v2 + 2808;
    *(_QWORD *)(v2 + 2768) = v2 + 2808;
    *(_QWORD *)(v2 + 2816) = v2 + 2832;
    *(_QWORD *)(v2 + 2832) = v2 + 2808;
    *(_QWORD *)(v2 + 2768) = v2 + 2832;
    *(_QWORD *)(v2 + 2856) = v2 + 2832;
    *(_QWORD *)(v2 + 2840) = v2 + 2856;
    *(_QWORD *)(v2 + 2768) = v2 + 2856;
    *(_QWORD *)(v2 + 2864) = v2 + 2880;
    *(_QWORD *)(v2 + 2880) = v2 + 2856;
    *(_QWORD *)(v2 + 2888) = v2 + 2768;
    *(_QWORD *)(v2 + 2768) = v2 + 2880;
    hrtimer_init(v2 + 2544, 1, 1);
    *(_QWORD *)(v2 + 2584) = sde_encoder_phys_phys_self_refresh_helper;
    hrtimer_init(v2 + 2616, 1, 1);
    v19 = _drm_debug;
    *(_QWORD *)(v2 + 2656) = &sde_encoder_phys_backlight_timer_cb;
    if ( (v19 & 4) != 0 )
    {
      if ( *(_QWORD *)v2 )
        v20 = *(_DWORD *)(*(_QWORD *)v2 + 24LL);
      else
        v20 = -1;
      _drm_dev_dbg(0, 0, 0, "enc%d intf%d created\n", v20, *(_DWORD *)(v2 + 672) - 1);
    }
  }
  else
  {
LABEL_24:
    printk(&unk_2350FF, "sde_encoder_phys_cmd_init");
    return -12;
  }
  return v2;
}
