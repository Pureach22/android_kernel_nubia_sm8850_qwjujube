__int64 __fastcall sg_add_device(__int64 a1)
{
  __int64 v1; // x22
  _QWORD *v3; // x26
  __int64 v4; // x0
  __int64 v5; // x20
  __int64 v6; // x27
  unsigned __int64 v7; // x19
  __int64 v8; // x25
  int v9; // w24
  __int64 v10; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x9
  unsigned __int64 v13; // x24
  __int64 v14; // x22

  v1 = *(_QWORD *)(a1 + 96);
  v3 = (_QWORD *)(v1 - 456);
  if ( (blk_get_queue(*(_QWORD *)(v1 - 456)) & 1) == 0 )
  {
    printk(&unk_B5B7, "sg_add_device");
    LODWORD(v7) = -19;
    return (unsigned int)v7;
  }
  v4 = cdev_alloc();
  if ( !v4 )
  {
    printk(&unk_B456, "sg_add_device");
    LODWORD(v7) = -12;
    goto LABEL_17;
  }
  v5 = v4;
  *(_QWORD *)(v4 + 96) = &_this_module;
  *(_QWORD *)(v4 + 104) = &sg_fops;
  v6 = *v3;
  v7 = _kmalloc_cache_noprof(idr_preload, 3520, 176);
  if ( !v7 )
  {
    sdev_prefix_printk(&unk_B6E3, v1 - 464, 0, "%s: kmalloc Sg_device failure\n", "sg_alloc");
    LODWORD(v7) = -12;
    goto LABEL_31;
  }
  idr_preload(3264);
  v8 = raw_write_lock_irqsave(&sg_index_lock);
  v9 = idr_alloc(&sg_index_idr, v7, 0, 0x100000, 10240);
  if ( v9 < 0 )
  {
    if ( v9 == -28 )
    {
      sdev_prefix_printk(
        &unk_B6E3,
        v1 - 464,
        0,
        "Unable to attach sg device type=%d, minor number exceeds %d\n",
        *(unsigned __int8 *)(v1 - 288),
        0xFFFFF);
      v9 = -19;
    }
    else
    {
      sdev_prefix_printk(&unk_B6E3, v1 - 464, 0, "%s: idr allocation Sg_device failure: %d\n", "sg_alloc", v9);
    }
  }
  else
  {
    sprintf((char *)(v7 + 125), "sg%d", v9);
    *(_QWORD *)v7 = v1 - 464;
    _mutex_init(v7 + 32, "&sdp->open_rel_lock", &sg_alloc___key);
    *(_QWORD *)(v7 + 88) = v7 + 88;
    *(_QWORD *)(v7 + 96) = v7 + 88;
    _init_waitqueue_head(v7 + 8, "&sdp->open_wait", &sg_alloc___key_37);
    *(_DWORD *)(v7 + 112) = 0;
    *(_QWORD *)(v7 + 104) = 0;
    *(_DWORD *)(v7 + 80) = *(unsigned __int16 *)(v6 + 260);
    *(_DWORD *)(v7 + 84) = v9;
    v9 = 0;
    *(_DWORD *)(v7 + 168) = 1;
  }
  v10 = raw_write_unlock_irqrestore(&sg_index_lock, v8);
  _ReadStatusReg(TPIDR_EL1);
  StatusReg = _ReadStatusReg(SP_EL0);
  v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v12;
  if ( v12 && *(_QWORD *)(StatusReg + 16) )
  {
    if ( !v9 )
      goto LABEL_13;
    goto LABEL_12;
  }
  preempt_schedule(v10);
  if ( v9 )
  {
LABEL_12:
    kfree(v7);
    v7 = v9;
  }
LABEL_13:
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
LABEL_31:
    printk(&unk_B432, "sg_add_device");
    goto LABEL_16;
  }
  LODWORD(v13) = cdev_add(v5, *(_DWORD *)(v7 + 84) | 0x1500000u, 1);
  if ( !(_DWORD)v13 )
  {
    *(_QWORD *)(v7 + 160) = v5;
    if ( sg_sysfs_valid == 1 )
    {
      v13 = device_create(
              &sg_sysfs_class,
              *(_QWORD *)(a1 + 96),
              *(_DWORD *)(v7 + 84) | 0x1500000u,
              v7,
              "%s",
              (const char *)(v7 + 125));
      if ( v13 > 0xFFFFFFFFFFFFF000LL )
      {
        printk(&unk_B532, "sg_add_device");
        goto LABEL_15;
      }
      if ( (unsigned int)sysfs_create_link(v1, v13, "generic") )
        printk(&unk_B3F0, "sg_add_device");
    }
    else
    {
      printk(&unk_B56A, "sg_add_device");
    }
    sdev_prefix_printk(
      &unk_B4F1,
      v1 - 464,
      0,
      "Attached scsi generic sg%d type %d\n",
      *(_DWORD *)(v7 + 84),
      *(unsigned __int8 *)(v1 - 288));
    *(_QWORD *)(a1 + 152) = v7;
    LODWORD(v7) = 0;
    return (unsigned int)v7;
  }
LABEL_15:
  v14 = raw_write_lock_irqsave(&sg_index_lock);
  idr_remove(&sg_index_idr, *(unsigned int *)(v7 + 84));
  raw_write_unlock_irqrestore(&sg_index_lock, v14);
  kfree(v7);
  LODWORD(v7) = v13;
LABEL_16:
  cdev_del(v5);
LABEL_17:
  blk_put_queue(*v3);
  return (unsigned int)v7;
}
