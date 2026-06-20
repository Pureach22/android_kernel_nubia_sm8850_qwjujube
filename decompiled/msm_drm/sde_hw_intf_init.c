__int64 __fastcall sde_hw_intf_init(int a1, __int64 a2, int *a3)
{
  __int64 v6; // x0
  int v7; // w8
  __int64 v8; // x8
  unsigned __int64 v9; // x1
  int v10; // w8
  unsigned int v11; // w2
  int v12; // w9
  __int64 v13; // x8
  __int64 v14; // x10
  __int64 (__fastcall *v15)(); // x11
  __int64 (__fastcall *v16)(); // x11
  __int64 v17; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v20; // x23

  v6 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1400);
  if ( !v6 )
    return -12;
  while ( 1 )
  {
    v7 = a3[3350];
    if ( !v7 )
      goto LABEL_92;
    if ( a3[3356] == a1 && a3[3364] )
    {
      v8 = 3352;
      goto LABEL_50;
    }
    if ( v7 == 1 )
      goto LABEL_92;
    if ( a3[3374] == a1 && a3[3382] )
    {
      v8 = 3370;
      goto LABEL_50;
    }
    if ( v7 == 2 )
      goto LABEL_92;
    if ( a3[3392] == a1 && a3[3400] )
    {
      v8 = 3388;
      goto LABEL_50;
    }
    if ( v7 == 3 )
      goto LABEL_92;
    if ( a3[3410] == a1 && a3[3418] )
    {
      v8 = 3406;
      goto LABEL_50;
    }
    if ( v7 == 4 )
      goto LABEL_92;
    if ( a3[3428] == a1 && a3[3436] )
    {
      v8 = 3424;
      goto LABEL_50;
    }
    if ( v7 == 5 )
      goto LABEL_92;
    if ( a3[3446] == a1 && a3[3454] )
    {
      v8 = 3442;
      goto LABEL_50;
    }
    if ( v7 == 6 )
      goto LABEL_92;
    if ( a3[3464] == a1 && a3[3472] )
    {
      v8 = 3460;
      goto LABEL_50;
    }
    if ( v7 == 7 )
      goto LABEL_92;
    if ( a3[3482] == a1 && a3[3490] )
    {
      v8 = 3478;
      goto LABEL_50;
    }
    if ( v7 == 8 )
      goto LABEL_92;
    if ( a3[3500] == a1 && a3[3508] )
    {
      v8 = 3496;
      goto LABEL_50;
    }
    if ( v7 == 9 )
      goto LABEL_92;
    if ( a3[3518] == a1 && a3[3526] )
    {
      v8 = 3514;
      goto LABEL_50;
    }
    if ( v7 == 10 )
      goto LABEL_92;
    if ( a3[3536] == a1 && a3[3544] )
    {
      v8 = 3532;
      goto LABEL_50;
    }
    if ( v7 == 11 )
      goto LABEL_92;
    if ( a3[3554] == a1 && a3[3562] )
      break;
    if ( v7 == 12 )
      goto LABEL_92;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v20 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &sde_hw_intf_init__alloc_tag;
    v6 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1400);
    *(_QWORD *)(StatusReg + 80) = v20;
    if ( !v6 )
      return -12;
  }
  v8 = 3550;
LABEL_50:
  v9 = (unsigned __int64)&a3[v8];
  v10 = *a3;
  v11 = *(_DWORD *)(v9 + 20);
  v12 = *(_DWORD *)(v9 + 24);
  *(_QWORD *)v6 = a2;
  *(_DWORD *)(v6 + 20) = v10;
  *(_DWORD *)(v6 + 24) = 8;
  *(_DWORD *)(v6 + 8) = v11;
  *(_DWORD *)(v6 + 12) = v12;
  if ( v9 && v9 < 0xFFFFFFFFFFFFF001LL )
  {
    v13 = *(_QWORD *)(v9 + 32);
    *(_QWORD *)(v6 + 80) = sde_hw_intf_setup_timing_engine;
    *(_QWORD *)(v6 + 104) = sde_hw_intf_setup_prg_fetch;
    *(_QWORD *)(v6 + 176) = sde_hw_intf_enable_timing_engine;
    *(_QWORD *)(v6 + 224) = sde_hw_intf_setup_misr;
    *(_QWORD *)(v6 + 248) = sde_hw_intf_collect_misr;
    *(_QWORD *)(v6 + 272) = sde_hw_intf_get_line_count;
    *(_QWORD *)(v6 + 296) = sde_hw_intf_get_underrun_line_count;
    *(_QWORD *)(v6 + 1184) = sde_hw_intf_get_intr_status;
    *(_QWORD *)(v6 + 680) = sde_hw_intf_avr_setup;
    *(_QWORD *)(v6 + 704) = sde_hw_intf_avr_trigger;
    *(_QWORD *)(v6 + 752) = sde_hw_intf_avr_ctrl;
    *(_QWORD *)(v6 + 776) = sde_hw_intf_avr_enable;
    v14 = *((_QWORD *)a3 + 85);
    *(_QWORD *)(v6 + 1064) = sde_hw_intf_enable_compressed_input;
    *(_DWORD *)(v6 + 32) = a1;
    *(_QWORD *)(v6 + 1160) = sde_hw_intf_enable_wide_bus;
    *(_QWORD *)(v6 + 40) = v9;
    *(_QWORD *)(v6 + 48) = a3;
    *(_QWORD *)(v6 + 1232) = sde_hw_intf_is_te_32bit_supported;
    if ( (v13 & 0x200000) != 0 )
    {
      *(_QWORD *)(v6 + 728) = sde_hw_intf_raw_te_setup;
      *(_QWORD *)(v6 + 1328) = sde_hw_intf_setup_panic_ctrl;
    }
    v15 = sde_hw_intf_v1_get_status;
    if ( (v13 & 0x80) == 0 )
      v15 = sde_hw_intf_get_status;
    *(_QWORD *)(v6 + 200) = v15;
    if ( (v13 & 2) != 0 )
    {
      *(_QWORD *)(v6 + 416) = sde_hw_intf_bind_pingpong_blk;
      if ( (v13 & 0x40) == 0 )
      {
LABEL_58:
        if ( (v13 & 0x1000) == 0 )
          goto LABEL_59;
        goto LABEL_65;
      }
    }
    else if ( (v13 & 0x40) == 0 )
    {
      goto LABEL_58;
    }
    *(_QWORD *)(v6 + 320) = sde_hw_intf_setup_vsync_source;
    if ( (v13 & 0x1000) == 0 )
    {
LABEL_59:
      if ( (v13 & 0x100000) == 0 )
        goto LABEL_60;
      goto LABEL_66;
    }
LABEL_65:
    *(_QWORD *)(v6 + 824) = sde_hw_intf_get_avr_status;
    if ( (v13 & 0x100000) == 0 )
    {
LABEL_60:
      if ( (v13 & 0x2000) == 0 )
        goto LABEL_61;
      goto LABEL_67;
    }
LABEL_66:
    *(_QWORD *)(v6 + 848) = sde_hw_intf_set_num_avr_step;
    *(_QWORD *)(v6 + 872) = sde_hw_intf_get_cur_num_avr_step;
    if ( (v13 & 0x2000) == 0 )
    {
LABEL_61:
      if ( (v13 & 4) == 0 )
        goto LABEL_75;
      goto LABEL_68;
    }
LABEL_67:
    *(_QWORD *)(v6 + 896) = sde_hw_intf_prepare_esync;
    *(_QWORD *)(v6 + 920) = sde_hw_intf_enable_esync;
    *(_QWORD *)(v6 + 944) = sde_hw_intf_prepare_backup_esync;
    *(_QWORD *)(v6 + 968) = sde_hw_intf_enable_backup_esync;
    *(_QWORD *)(v6 + 992) = sde_hw_intf_wait_for_esync_src_switch;
    *(_QWORD *)(v6 + 1016) = sde_hw_intf_enable_infinite_vfp;
    *(_QWORD *)(v6 + 1040) = sde_hw_intf_get_esync_timestamp;
    if ( (v13 & 4) == 0 )
      goto LABEL_75;
LABEL_68:
    *(_QWORD *)(v6 + 464) = sde_hw_intf_setup_te_config;
    *(_QWORD *)(v6 + 488) = sde_hw_intf_enable_te;
    *(_QWORD *)(v6 + 512) = sde_hw_intf_update_te;
    *(_QWORD *)(v6 + 536) = sde_hw_intf_connect_external_te;
    *(_QWORD *)(v6 + 560) = sde_hw_intf_get_vsync_info;
    *(_QWORD *)(v6 + 584) = sde_hw_intf_setup_autorefresh_config;
    *(_QWORD *)(v6 + 608) = sde_hw_intf_get_autorefresh_config;
    *(_QWORD *)(v6 + 440) = sde_hw_intf_get_autorefresh_status;
    *(_QWORD *)(v6 + 632) = sde_hw_intf_poll_timeout_wr_ptr;
    *(_QWORD *)(v6 + 656) = sde_hw_intf_vsync_sel;
    *(_QWORD *)(v6 + 1088) = sde_hw_intf_v1_check_and_reset_tearcheck;
    *(_QWORD *)(v6 + 1208) = sde_hw_intf_override_tear_rd_ptr_val;
    *(_QWORD *)(v6 + 1352) = sde_hw_intf_update_tearcheck_vsync_count;
    if ( (v13 & 0x200000) != 0 )
      *(_QWORD *)(v6 + 1304) = sde_hw_intf_setup_panic_wakeup;
    if ( (v13 & 0x80000) != 0 )
    {
      v16 = sde_hw_intf_enable_te_level_mode;
    }
    else
    {
      if ( (v13 & 0x40000) == 0 )
        goto LABEL_75;
      v16 = sde_hw_intf_enable_te_level_trigger;
    }
    *(_QWORD *)(v6 + 800) = v16;
LABEL_75:
    if ( (v13 & 0x100) != 0 )
      *(_QWORD *)(v6 + 1112) = sde_hw_intf_reset_counter;
    if ( (v13 & 0x600) != 0 )
      *(_QWORD *)(v6 + 1136) = sde_hw_intf_get_vsync_timestamp;
    if ( (v14 & 0x4000) != 0 )
    {
      *(_QWORD *)(v6 + 1256) = sde_hw_intf_setup_dpu_sync_prog_intf_offset;
      *(_QWORD *)(v6 + 1280) = sde_hw_intf_enable_dpu_sync_ctrl;
      if ( (v13 & 0x4000) == 0 )
      {
LABEL_81:
        if ( (v13 & 0x8000) == 0 )
          goto LABEL_82;
        goto LABEL_88;
      }
    }
    else if ( (v13 & 0x4000) == 0 )
    {
      goto LABEL_81;
    }
    *(_QWORD *)(v6 + 344) = sde_hw_intf_configure_wd_timer_jitter;
    if ( (v13 & 0x8000) == 0 )
    {
LABEL_82:
      if ( (v14 & 0x8000) == 0 )
        goto LABEL_83;
      goto LABEL_89;
    }
LABEL_88:
    *(_QWORD *)(v6 + 392) = sde_hw_intf_read_wd_ltj_ctl;
    if ( (v14 & 0x8000) == 0 )
    {
LABEL_83:
      if ( (v13 & 0x800000) == 0 )
      {
LABEL_85:
        v17 = v6;
        sde_dbg_reg_register_dump_range((__int64)"sde", (const char *)v9, v11, v12 + v11, *(_DWORD *)(v6 + 16));
        return v17;
      }
LABEL_84:
      *(_QWORD *)(v6 + 128) = sde_hw_intf_setup_prog_dynref;
      goto LABEL_85;
    }
LABEL_89:
    *(_QWORD *)(v6 + 1376) = sde_hw_intf_flush_snapshot_setup;
    if ( (v13 & 0x800000) == 0 )
      goto LABEL_85;
    goto LABEL_84;
  }
LABEL_92:
  kfree(v6);
  printk(&unk_23915A, "sde_hw_intf_init");
  return -22;
}
