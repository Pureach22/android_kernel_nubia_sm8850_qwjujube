__int64 zram_add()
{
  __int64 v0; // x19
  unsigned int v1; // w20
  _DWORD *v2; // x0
  unsigned int v3; // w0
  unsigned int v4; // w21
  char *v5; // x0
  _BYTE v7[200]; // [xsp+0h] [xbp-D0h] BYREF
  __int64 v8; // [xsp+C8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memcpy(v7, &off_BC20, sizeof(v7));
  v0 = _kmalloc_cache_noprof(raw_spin_lock_irq, 3520, 288);
  if ( !v0 )
  {
    v1 = -12;
    goto LABEL_13;
  }
  is_qpace_dev_available();
  v1 = idr_alloc(&zram_index_idr, v0, 0, 0, 3264);
  if ( (v1 & 0x80000000) != 0 )
    goto LABEL_7;
  _init_rwsem(v0 + 32, "&zram->init_lock", &zram_add___key);
  *(_DWORD *)(v0 + 248) = 0;
  v2 = (_DWORD *)_blk_alloc_disk(v7, 0xFFFFFFFFLL, &zram_add___key_33);
  *(_QWORD *)(v0 + 24) = v2;
  if ( (unsigned __int64)v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_B2D4);
    v4 = *(_DWORD *)(v0 + 24);
    goto LABEL_6;
  }
  *v2 = zram_major;
  *(_DWORD *)(*(_QWORD *)(v0 + 24) + 4LL) = v1;
  *(_DWORD *)(*(_QWORD *)(v0 + 24) + 8LL) = 1;
  *(_DWORD *)(*(_QWORD *)(v0 + 24) + 344LL) |= 4u;
  *(_QWORD *)(*(_QWORD *)(v0 + 24) + 72LL) = &zram_devops;
  *(_QWORD *)(*(_QWORD *)(v0 + 24) + 88LL) = v0;
  snprintf((char *)(*(_QWORD *)(v0 + 24) + 12LL), 0x10u, "zram%d", v1);
  set_capacity(*(_QWORD *)(v0 + 24), 0);
  v3 = device_add_disk(0, *(_QWORD *)(v0 + 24), &zram_disk_groups);
  if ( v3 )
  {
    v4 = v3;
    put_disk(*(_QWORD *)(v0 + 24));
LABEL_6:
    idr_remove(&zram_index_idr, v1);
    v1 = v4;
LABEL_7:
    kfree(v0);
    goto LABEL_13;
  }
  v5 = *(char **)(v0 + 224);
  if ( v5 != "lzo-rle" )
    kfree(v5);
  *(_QWORD *)(v0 + 224) = "lzo-rle";
  printk(&unk_B769);
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return v1;
}
