__int64 __fastcall sde_hdcp_1x_init(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x3
  __int64 v9; // x0
  void *v10; // x0
  _QWORD v12[2]; // [xsp+0h] [xbp-20h] BYREF
  int v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v12[0] = 0;
  v12[1] = 0;
  if ( !a1 || !*(_QWORD *)(a1 + 96) || !*(_QWORD *)(a1 + 80) || !*(_QWORD *)(a1 + 88) )
  {
    v10 = &unk_255B25;
LABEL_15:
    printk(v10, "sde_hdcp_1x_init");
LABEL_20:
    v3 = 0;
    goto LABEL_21;
  }
  if ( *(_BYTE *)(a1 + 124) == 1 && !*(_QWORD *)(a1 + 56) )
  {
    v10 = &unk_264451;
    goto LABEL_15;
  }
  v2 = _kmalloc_cache_noprof(kthread_should_park, 3520, 1456);
  v3 = v2;
  if ( !v2 )
    goto LABEL_21;
  memcpy((void *)(v2 + 872), (const void *)a1, 0x88u);
  *(_QWORD *)(v3 + 1008) = sde_hdcp_1x_init_ops;
  v4 = _kmalloc_cache_noprof(wake_up_process, 3520, 24);
  *(_QWORD *)(v3 + 1440) = v4;
  if ( !v4 )
    goto LABEL_19;
  snprintf((char *)v12, 0x14u, "hdcp_1x_%d", *(_DWORD *)(v3 + 1000));
  v5 = alloc_workqueue(&unk_23DEBE, 262152, 1, v12);
  *(_QWORD *)(v3 + 1432) = v5;
  if ( !v5 )
  {
    printk(&unk_21F7FB, "sde_hdcp_1x_init");
LABEL_19:
    kfree(*(_QWORD *)(v3 + 1440));
    kfree(v3);
    goto LABEL_20;
  }
  v9 = hdcp1_init(v5, v6, v7, v8);
  *(_QWORD *)(v3 + 1448) = v9;
  if ( !v9 )
  {
    printk(&unk_255B47, "sde_hdcp_1x_init");
    destroy_workqueue(*(_QWORD *)(v3 + 1432));
    goto LABEL_19;
  }
  if ( *(_DWORD *)(v3 + 1000) == 1 )
  {
    *(_QWORD *)(v3 + 1120) = 0x200000002LL;
    *(_QWORD *)(v3 + 1112) = 0x1000000020LL;
    *(_QWORD *)(v3 + 1104) = 0x1C00000018LL;
    *(_QWORD *)(v3 + 1096) = 0x1400000010LL;
    *(_QWORD *)(v3 + 1088) = 0xC00000008LL;
    *(_QWORD *)(v3 + 1080) = 0x4000000C4LL;
    *(_QWORD *)(v3 + 1072) = 0xC0000000A8LL;
    *(_QWORD *)(v3 + 1064) = 0xA4000000B0LL;
    *(_QWORD *)(v3 + 1056) = 0xC800000028LL;
    *(_QWORD *)(v3 + 1048) = 0x240000035CLL;
    *(_QWORD *)(v3 + 1040) = 0x35000000098LL;
    *(_QWORD *)(v3 + 1032) = 0x9C000000A0LL;
    *(_QWORD *)(v3 + 1024) = 0xD0000000ELL;
    *(_QWORD *)(v3 + 1016) = 0x10000000A4LL;
    memcpy((void *)(v3 + 1208), &off_27FD80, 0xE0u);
    *(_QWORD *)(v3 + 1144) = 0x8000000;
    *(_QWORD *)(v3 + 1152) = 0x1000000000000LL;
    *(_QWORD *)(v3 + 1176) = 0;
    *(_QWORD *)(v3 + 1200) = 0;
    *(_QWORD *)(v3 + 1160) = 0x20000000080000LL;
    *(_QWORD *)(v3 + 1168) = 0x400000000800000LL;
    *(_QWORD *)(v3 + 1184) = 0x4000000008000LL;
    *(_QWORD *)(v3 + 1192) = 0x200000000400000LL;
    *(_QWORD *)(v3 + 1128) = 0x2000000000024LL;
    *(_QWORD *)(v3 + 1136) = 0x100000000100000LL;
  }
  *(_QWORD *)(v3 + 704) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v3 + 712) = v3 + 712;
  *(_QWORD *)(v3 + 720) = v3 + 712;
  *(_QWORD *)(v3 + 728) = sde_hdcp_1x_auth_work;
  init_timer_key(v3 + 736, &delayed_work_timer_fn, 0x200000, 0, 0);
  *(_DWORD *)(v3 + 40) = 0;
  *(_DWORD *)(v3 + 808) = 0;
  _init_swait_queue_head(v3 + 816, "&x->wait", &init_completion___key);
  *(_DWORD *)(v3 + 840) = 0;
  _init_swait_queue_head(v3 + 848, "&x->wait", &init_completion___key);
  *(_BYTE *)(v3 + 35) = 0;
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return v3;
}
