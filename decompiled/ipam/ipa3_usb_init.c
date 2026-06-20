__int64 __fastcall ipa3_usb_init(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x0
  __int64 v3; // x1
  unsigned int v4; // w19
  _DWORD *v5; // x19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x1
  void *v15; // x0
  unsigned __int64 dir; // x0
  __int64 v17; // x1
  unsigned __int64 file; // x0
  __int64 v19; // x1
  unsigned int ready; // w0
  __int64 v21; // x1

  printk(&unk_3C5B00, a2);
  v2 = (_DWORD *)_kmalloc_cache_noprof(__ratelimit, 3520, 1400);
  ipa3_usb_ctx = (__int64)v2;
  if ( v2 )
  {
    v5 = v2;
    memset(v2, 0, 0x578u);
    v5[14] = 2;
    v5[32] = 2;
    v5[50] = 2;
    v5[68] = 2;
    v5[86] = 2;
    v5[104] = 2;
    v5[122] = 0;
    _init_swait_queue_head(v5 + 124, "&x->wait", &init_completion___key_7);
    v6 = ipa3_usb_ctx;
    v7 = ipa3_usb_ctx + 544;
    *(_QWORD *)(ipa3_usb_ctx + 520) = 0;
    *(_BYTE *)(v6 + 528) = 0;
    _mutex_init(v7, "&ipa3_usb_ctx->general_mutex", &ipa3_usb_init___key);
    v8 = ipa3_usb_ctx;
    *(_DWORD *)(ipa3_usb_ctx + 632) = -1;
    *(_DWORD *)(v8 + 1144) = -1;
    *(_DWORD *)(v8 + 888) = -1;
    *(_QWORD *)(v8 + 624) = &ipa3_usb_notify_remote_wakeup_work;
    *(_QWORD *)(v8 + 1136) = &ipa3_usb_notify_remote_wakeup_work;
    *(_QWORD *)(v8 + 880) = &ipa3_usb_dpl_notify_remote_wakeup_work;
    *(_QWORD *)(v8 + 648) = 0;
    *(_QWORD *)(v8 + 904) = 0;
    *(_QWORD *)(v8 + 1160) = 0;
    v9 = raw_spin_lock_irqsave(v8 + 524);
    v10 = ipa3_usb_ctx;
    v11 = v9;
    v12 = ipa3_usb_ctx + 524;
    *(_DWORD *)(ipa3_usb_ctx + 656) = 0;
    *(_DWORD *)(v10 + 912) = 0;
    *(_DWORD *)(v10 + 1168) = 0;
    raw_spin_unlock_irqrestore(v12, v11);
    v13 = alloc_workqueue("%s", (const char *)0x6000A);
    *(_QWORD *)(ipa3_usb_ctx + 536) = v13;
    if ( v13 )
    {
      dir = debugfs_create_dir("ipa_usb", 0);
      *(_QWORD *)(ipa3_usb_ctx + 1368) = dir;
      if ( dir < 0xFFFFFFFFFFFFF001LL )
      {
        file = debugfs_create_file("state_info", 292, dir, 0, &ipa3_ipa_usb_ops);
        *(_QWORD *)(ipa3_usb_ctx + 1360) = file;
        if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_3F3EF3, v19);
          debugfs_remove(*(_QWORD *)(ipa3_usb_ctx + 1368));
          *(_QWORD *)(ipa3_usb_ctx + 1368) = 0;
        }
      }
      else
      {
        printk(&unk_3ED4CC, v17);
      }
      ready = ipa_register_ipa_ready_cb((__int64)&ipa_ready_callback, (__int64)usb_ops);
      if ( (ready & 0x80000000) == 0 )
      {
        printk(&unk_3E80D1, v14);
        printk(&unk_3FCBCF, v21);
        return 0;
      }
      v4 = ready;
      v15 = &unk_3F3E37;
    }
    else
    {
      v4 = -14;
      v15 = &unk_3AB588;
    }
    printk(v15, v14);
    printk(&unk_3D138B, -v4);
    kfree(ipa3_usb_ctx);
  }
  else
  {
    printk(&unk_3B9AFB, v3);
    return (unsigned int)-12;
  }
  return v4;
}
