__int64 __fastcall msm_vidc_open(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x25
  __int64 v6; // x21
  __int64 v7; // x23
  __int64 updated; // x0
  __int64 v9; // x4
  __int64 v10; // x4
  __int64 v11; // x4
  __int64 v12; // x20
  void *v13; // x0
  __int64 v14; // x0
  __int64 v15; // x4
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x3
  __int64 v19; // x4
  int v20; // w9
  __int64 v21; // x8
  int v22; // w0
  int v23; // w9
  __int64 inited; // x0
  __int64 v25; // x4

  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_90870, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_open");
  if ( a2 - 3 <= 0xFFFFFFFD )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_92275, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_open");
    return 0;
  }
  if ( (unsigned int)msm_vidc_core_init(a1) || (unsigned int)msm_vidc_core_init_wait(a1) )
    return 0;
  v4 = vzalloc_noprof(38720);
  if ( !v4 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8C985, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_open");
    return 0;
  }
  *(_QWORD *)(v4 + 320) = a1;
  *(_DWORD *)(v4 + 308) = a2;
  v5 = v4 + 37584;
  v6 = v4 + 340;
  *(_DWORD *)(v4 + 332) = HIDWORD(v4) ^ v4;
  v7 = v4;
  updated = msm_vidc_update_state();
  *(_DWORD *)(v7 + 176) = 0;
  *(_BYTE *)(v5 + 824) = 1;
  strcpy((char *)(v7 + 180), "SUB_STATE_NONE");
  *(_WORD *)(v6 + 3765) = 0;
  *(_BYTE *)(v7 + 1836) = 0;
  *(_BYTE *)(v6 + 3767) = 0;
  *(_BYTE *)(v5 + 1120) = 0;
  *(_BYTE *)(v5 + 1128) = 0;
  *(_DWORD *)(v5 + 1112) = 1966080;
  *(_QWORD *)(v5 + 840) = ktime_get(updated) / 0x3E8uLL;
  *(_DWORD *)(v7 + 328) = 1;
  _mutex_init(v7 + 16, "&inst->lock", &msm_vidc_open___key);
  _mutex_init(v7 + 64, "&inst->ctx_q_lock", &msm_vidc_open___key_41);
  _mutex_init(v7 + 112, "&inst->client_lock", &msm_vidc_open___key_43);
  msm_vidc_update_debug_str(v7);
  if ( (msm_vidc_debug & 2) != 0 )
    printk(&unk_922AD, "high", v6, a2, v9);
  if ( (unsigned int)msm_vidc_add_session(v7) )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_82074, "err ", v6, "msm_vidc_open", v10);
    goto LABEL_45;
  }
  if ( (unsigned int)msm_vidc_set_crc(a1) )
  {
    v12 = v7;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v13 = &unk_9772E;
LABEL_20:
      printk(v13, "err ", v6, "msm_vidc_open", v11);
LABEL_43:
      v12 = v7;
      goto LABEL_44;
    }
    goto LABEL_44;
  }
  if ( (unsigned int)msm_vidc_pools_init(v7) )
  {
    v12 = v7;
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v13 = &unk_8EF41;
      goto LABEL_20;
    }
LABEL_44:
    msm_vidc_remove_session(v12);
    msm_vidc_remove_dangling_session(v12);
LABEL_45:
    vfree(v7);
    return 0;
  }
  *(_QWORD *)(v7 + 4024) = v7 + 4024;
  *(_QWORD *)(v7 + 4032) = v7 + 4024;
  *(_QWORD *)(v7 + 3208) = v7 + 3208;
  *(_QWORD *)(v7 + 3216) = v7 + 3208;
  *(_QWORD *)(v7 + 3240) = v7 + 3240;
  *(_QWORD *)(v7 + 3248) = v7 + 3240;
  *(_QWORD *)(v7 + 2504) = v7 + 2504;
  *(_QWORD *)(v7 + 2512) = v7 + 2504;
  *(_QWORD *)(v7 + 2624) = v7 + 2624;
  *(_QWORD *)(v7 + 2632) = v7 + 2624;
  *(_QWORD *)(v7 + 2544) = v7 + 2544;
  *(_QWORD *)(v7 + 2552) = v7 + 2544;
  *(_QWORD *)(v7 + 2664) = v7 + 2664;
  *(_QWORD *)(v7 + 2672) = v7 + 2664;
  *(_QWORD *)(v7 + 2584) = v7 + 2584;
  *(_QWORD *)(v7 + 2592) = v7 + 2584;
  *(_QWORD *)(v7 + 2704) = v7 + 2704;
  *(_QWORD *)(v7 + 2712) = v7 + 2704;
  *(_QWORD *)(v7 + 2744) = v7 + 2744;
  *(_QWORD *)(v7 + 2752) = v7 + 2744;
  *(_QWORD *)(v7 + 2784) = v7 + 2784;
  *(_QWORD *)(v7 + 2792) = v7 + 2784;
  *(_QWORD *)(v7 + 2824) = v7 + 2824;
  *(_QWORD *)(v7 + 2832) = v7 + 2824;
  *(_QWORD *)(v7 + 2864) = v7 + 2864;
  *(_QWORD *)(v7 + 2872) = v7 + 2864;
  *(_QWORD *)(v7 + 2904) = v7 + 2904;
  *(_QWORD *)(v7 + 2912) = v7 + 2904;
  *(_QWORD *)(v7 + 2944) = v7 + 2944;
  *(_QWORD *)(v7 + 2952) = v7 + 2944;
  *(_QWORD *)(v7 + 2984) = v7 + 2984;
  *(_QWORD *)(v7 + 2992) = v7 + 2984;
  *(_QWORD *)(v7 + 3024) = v7 + 3024;
  *(_QWORD *)(v7 + 3032) = v7 + 3024;
  *(_QWORD *)(v7 + 3064) = v7 + 3064;
  *(_QWORD *)(v7 + 3072) = v7 + 3064;
  *(_QWORD *)(v7 + 3080) = v7 + 3080;
  *(_QWORD *)(v7 + 3088) = v7 + 3080;
  *(_QWORD *)(v7 + 3096) = v7 + 3096;
  *(_QWORD *)(v7 + 3104) = v7 + 3096;
  *(_QWORD *)(v7 + 3112) = v7 + 3112;
  *(_QWORD *)(v7 + 3120) = v7 + 3112;
  *(_QWORD *)(v7 + 3128) = v7 + 3128;
  *(_QWORD *)(v7 + 3136) = v7 + 3128;
  *(_QWORD *)(v7 + 3144) = v7 + 3144;
  *(_QWORD *)(v7 + 3152) = v7 + 3144;
  *(_QWORD *)(v7 + 3160) = v7 + 3160;
  *(_QWORD *)(v7 + 3168) = v7 + 3160;
  *(_QWORD *)(v7 + 3176) = v7 + 3176;
  *(_QWORD *)(v7 + 3184) = v7 + 3176;
  *(_QWORD *)(v7 + 3192) = v7 + 3192;
  *(_QWORD *)(v7 + 3200) = v7 + 3192;
  *(_QWORD *)(v7 + 4040) = v7 + 4040;
  *(_QWORD *)(v7 + 4048) = v7 + 4040;
  *(_QWORD *)(v7 + 4056) = v7 + 4056;
  *(_QWORD *)(v7 + 4064) = v7 + 4056;
  *(_QWORD *)(v7 + 3976) = v7 + 3976;
  *(_QWORD *)(v7 + 3984) = v7 + 3976;
  *(_QWORD *)(v7 + 3992) = v7 + 3992;
  *(_QWORD *)(v7 + 4000) = v7 + 3992;
  *(_QWORD *)(v7 + 4008) = v7 + 4008;
  *(_QWORD *)(v7 + 4016) = v7 + 4008;
  *(_QWORD *)(v7 + 4072) = v7 + 4072;
  *(_QWORD *)(v7 + 4080) = v7 + 4072;
  *(_QWORD *)(v7 + 4088) = v7 + 4088;
  *(_QWORD *)(v7 + 4096) = v7 + 4088;
  *(_DWORD *)v5 = 0;
  _init_swait_queue_head(v7 + 37592, "&x->wait", &init_completion___key);
  *(_DWORD *)(v5 + 32) = 0;
  _init_swait_queue_head(v7 + 37624, "&x->wait", &init_completion___key);
  *(_DWORD *)(v5 + 64) = 0;
  _init_swait_queue_head(v7 + 37656, "&x->wait", &init_completion___key);
  v14 = alloc_workqueue(&unk_89A74, 393226, 1, "workq");
  *(_QWORD *)(v7 + 3968) = v14;
  if ( !v14 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_88EC0, "err ", v6, "msm_vidc_open", v15);
    goto LABEL_42;
  }
  *(_QWORD *)(v7 + 3816) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 3824) = v7 + 3824;
  *(_QWORD *)(v7 + 3832) = v7 + 3824;
  *(_QWORD *)(v7 + 3840) = msm_vidc_stats_handler;
  init_timer_key(v7 + 3848, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_QWORD *)(v7 + 3920) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v7 + 3928) = v7 + 3928;
  *(_QWORD *)(v7 + 3936) = v7 + 3928;
  *(_QWORD *)(v7 + 3944) = msm_vidc_stability_handler;
  if ( (unsigned int)msm_vidc_v4l2_fh_init(v7) )
  {
LABEL_41:
    destroy_workqueue(*(_QWORD *)(v7 + 3968));
LABEL_42:
    msm_vidc_pools_deinit(v7);
    goto LABEL_43;
  }
  if ( (unsigned int)msm_vidc_vb2_queue_init(v7) )
  {
LABEL_40:
    msm_vidc_v4l2_fh_deinit(v7);
    goto LABEL_41;
  }
  v20 = *(_DWORD *)(v7 + 308);
  v21 = v7;
  if ( v20 == 1 )
  {
    v22 = msm_venc_inst_init(v7, v16, v17, v18, v19);
  }
  else
  {
    if ( v20 != 2 )
      goto LABEL_31;
    v22 = msm_vdec_inst_init(v7);
  }
  v21 = v7;
  if ( v22 )
    goto LABEL_39;
LABEL_31:
  if ( (unsigned int)msm_vidc_fence_init(v21) )
  {
LABEL_34:
    v23 = *(_DWORD *)(v7 + 308);
    if ( v23 == 1 )
    {
      msm_venc_inst_deinit(v7);
      goto LABEL_38;
    }
    v21 = v7;
    if ( v23 == 2 )
    {
      msm_vdec_inst_deinit(v7);
LABEL_38:
      v21 = v7;
    }
LABEL_39:
    msm_vidc_vb2_queue_deinit(v21);
    goto LABEL_40;
  }
  msm_vidc_reset_residency_stats(a1);
  msm_vidc_scale_power(v7, 1);
  if ( (unsigned int)msm_vidc_session_open(v7) )
  {
    msm_vidc_core_deinit(a1, 1);
    msm_vidc_fence_deinit(v7);
    goto LABEL_34;
  }
  inited = msm_vidc_debugfs_init_inst(v7, *(_QWORD *)(a1 + 3568));
  *(_QWORD *)(v7 + 4112) = inited;
  if ( inited || (msm_vidc_debug & 2) == 0 )
    return v7;
  printk(&unk_92D21, "high", v6, "msm_vidc_open", v25);
  return v7;
}
