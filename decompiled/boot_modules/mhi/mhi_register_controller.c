__int64 __fastcall mhi_register_controller(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x22
  __int64 v8; // x20
  unsigned int v9; // w21
  __int64 (__fastcall *v10)(); // x1
  __int64 v11; // x9
  int v12; // w10
  _QWORD *v13; // x9
  __int64 v14; // x10
  unsigned int v15; // w24
  __int64 v16; // x25
  unsigned int v17; // w9
  __int64 (__fastcall *v18)(); // x10
  __int64 (__fastcall *v19)(); // x9
  unsigned int v20; // w0
  __int64 v21; // x8
  unsigned int inited; // w21
  unsigned __int64 v23; // x0
  _QWORD *v24; // x20
  __int64 v25; // x8
  unsigned int v26; // w0
  __int64 v27; // x19

  if ( !a1 )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 8) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 32) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 512) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 528) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 480) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 568) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 576) )
    return 4294967274LL;
  if ( !*(_DWORD *)(a1 + 224) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 200) )
    return 4294967274LL;
  if ( !*(_QWORD *)(a1 + 144) )
    return 4294967274LL;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  if ( (unsigned int)parse_config() )
    return 4294967274LL;
  v3 = _kmalloc_cache_noprof(raw_read_unlock_bh, 3520, 104);
  v4 = a1;
  *(_QWORD *)(a1 + 256) = v3;
  if ( !v3 )
  {
    inited = -12;
LABEL_50:
    v27 = v4;
    kfree(*(_QWORD *)(v4 + 248));
    vfree(*(_QWORD *)(v27 + 176));
    return inited;
  }
  *(_QWORD *)(a1 + 376) = a1 + 376;
  *(_QWORD *)(a1 + 384) = a1 + 376;
  _mutex_init(a1 + 272, "&mhi_cntrl->pm_mutex", &mhi_register_controller___key);
  *(_QWORD *)(a1 + 320) = 0;
  *(_QWORD *)(a1 + 416) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(a1 + 392) = 0;
  *(_QWORD *)(a1 + 424) = a1 + 424;
  *(_QWORD *)(a1 + 432) = a1 + 424;
  *(_QWORD *)(a1 + 440) = mhi_pm_st_worker;
  _init_waitqueue_head(a1 + 456, "&mhi_cntrl->state_event", &mhi_register_controller___key_77);
  v5 = alloc_workqueue("mhi_hiprio_wq", 131090, 1);
  v6 = a1;
  *(_QWORD *)(a1 + 448) = v5;
  if ( !v5 )
  {
    dev_err(*(_QWORD *)(a1 + 8), "Failed to allocate workqueue\n");
    inited = -12;
    goto LABEL_49;
  }
  *(_DWORD *)(*(_QWORD *)(a1 + 256) + 96LL) = 0;
  if ( *(_DWORD *)(a1 + 212) )
  {
    v7 = *(_QWORD *)(a1 + 248);
    v8 = 0;
    v9 = 0;
    do
    {
      v11 = v7 + v8;
      if ( (*(_BYTE *)(v7 + v8 + 258) & 1) == 0 )
      {
        v12 = *(_DWORD *)(v11 + 32);
        *(_QWORD *)v11 = v6;
        *(_DWORD *)(v11 + 240) = 0;
        if ( v12 == 2 )
        {
          v13 = (_QWORD *)(v7 + v8);
          v14 = v7 + v8 + 216;
          v13[26] = 0xFFFFFFFE00000LL;
          v13[27] = v14;
          v13[28] = v14;
          v13[29] = mhi_process_ev_work;
        }
        else
        {
          if ( *(_DWORD *)(v7 + v8 + 36) == 1 )
            v10 = mhi_ctrl_ev_task;
          else
            v10 = mhi_ev_task;
          tasklet_init(v7 + v8 + 168, v10);
          v6 = a1;
        }
      }
      ++v9;
      v8 += 264;
    }
    while ( v9 < *(_DWORD *)(v6 + 212) );
  }
  if ( *(_DWORD *)(v6 + 208) )
  {
    v15 = 0;
    v16 = *(_QWORD *)(v6 + 176) + 372LL;
    do
    {
      _mutex_init(v16 - 84, "&mhi_chan->mutex", &mhi_register_controller___key_82);
      *(_DWORD *)(v16 - 36) = 0;
      _init_swait_queue_head(v16 - 28, "&x->wait", &init_completion___key);
      v17 = *(_DWORD *)(v16 - 168);
      *(_QWORD *)(v16 - 4) = 0;
      ++v15;
      v6 = a1;
      *(_DWORD *)(v16 - 164) = *(_DWORD *)(*(_QWORD *)(a1 + 248) + 264LL * v17 + 20);
      v16 += 400;
    }
    while ( v15 < *(_DWORD *)(a1 + 208) );
  }
  v18 = mhi_map_single_no_bb;
  v19 = mhi_unmap_single_use_bb;
  if ( *(_BYTE *)(v6 + 613) )
    v18 = mhi_map_single_use_bb;
  else
    v19 = mhi_unmap_single_no_bb;
  *(_QWORD *)(v6 + 552) = v18;
  *(_QWORD *)(v6 + 560) = v19;
  v20 = ida_alloc_range(&mhi_controller_ida, 0, 0xFFFFFFFFLL, 3264);
  v21 = a1;
  *(_DWORD *)(a1 + 608) = v20;
  if ( (v20 & 0x80000000) != 0 )
  {
    inited = v20;
    goto LABEL_48;
  }
  inited = mhi_init_irq_setup(a1);
  if ( inited )
  {
LABEL_45:
    ida_free(&mhi_controller_ida, *(unsigned int *)(a1 + 608));
    v21 = a1;
LABEL_48:
    destroy_workqueue(*(_QWORD *)(v21 + 448));
LABEL_49:
    kfree(*(_QWORD *)(a1 + 256));
    v4 = a1;
    goto LABEL_50;
  }
  v23 = mhi_alloc_device(a1);
  v24 = (_QWORD *)v23;
  if ( v23 >= 0xFFFFFFFFFFFFF001LL )
  {
    dev_err(*(_QWORD *)(a1 + 8), "Failed to allocate MHI device\n");
    inited = (unsigned int)v24;
    goto LABEL_44;
  }
  *(_QWORD *)(v23 + 16) = a1;
  *(_DWORD *)(v23 + 952) = 1;
  dev_set_name(v23 + 40, "mhi%d", *(_DWORD *)(a1 + 608));
  v25 = v24[19];
  if ( !v25 )
    v25 = v24[5];
  v24[1] = v25;
  device_set_wakeup_capable(v24 + 5, 1);
  device_wakeup_enable(v24 + 5);
  *(_QWORD *)(a1 + 16) = v24;
  v26 = mhi_misc_register_controller(a1);
  if ( v26 )
  {
    inited = v26;
    dev_err(*(_QWORD *)(a1 + 8), "Could not enable miscellaneous features\n");
    *(_QWORD *)(a1 + 16) = 0;
    goto LABEL_45;
  }
  inited = device_add(v24 + 5);
  if ( inited )
  {
LABEL_43:
    mhi_misc_unregister_controller(a1);
LABEL_44:
    mhi_deinit_free_irq(a1);
    goto LABEL_45;
  }
  if ( *(_QWORD *)(a1 + 592) && (inited = sysfs_create_file_ns(v24 + 5, &dev_attr_trigger_edl, 0)) != 0
    || (result = mhi_misc_sysfs_create(a1), (inited = result) != 0) )
  {
    device_del(v24 + 5);
    goto LABEL_43;
  }
  *(_QWORD *)(a1 + 16) = v24;
  return result;
}
