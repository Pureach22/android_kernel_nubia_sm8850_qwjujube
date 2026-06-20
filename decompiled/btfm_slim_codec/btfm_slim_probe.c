__int64 __fastcall btfm_slim_probe(__int64 *a1)
{
  __int64 v1; // x2
  __int64 v3; // x2
  __int64 v4; // x2
  _QWORD *v5; // x0
  __int64 v6; // x2
  _QWORD *v7; // x19
  unsigned int v8; // w0
  unsigned int v9; // w20

  v1 = a1[14];
  if ( !v1 )
    v1 = *a1;
  printk(&unk_8FC4, "btfm_slim_probe", v1);
  *((_BYTE *)a1 + 933) = 1;
  is_registered = 0;
  dev_set_name(a1, &unk_8856, "btfmslim");
  v3 = a1[14];
  if ( !v3 )
    v3 = *a1;
  printk(&unk_8FC4, "btfm_slim_probe", v3);
  printk(&unk_8F20, "btfm_slim_probe", v4);
  if ( a1[115] )
  {
    v5 = (_QWORD *)_kmalloc_cache_noprof(btfmcodec_unregister_hw_ep, 3520, 1136);
    v7 = v5;
    if ( !v5 )
    {
      printk(&unk_8D91, "btfm_slim_probe", v6);
      return (unsigned int)-12;
    }
    v5[137] = &slave_rxport;
    v5[138] = &slave_txport;
    v5[139] = btfm_slim_slave_hw_init;
    v5[1] = a1;
    v5[140] = btfm_slim_slave_enable_port;
    _mutex_init(v5 + 122, "&btfm_slim->io_lock", &btfm_slim_probe___key);
    _mutex_init(v7 + 128, "&btfm_slim->xfer_lock", &btfm_slim_probe___key_49);
    a1[19] = (__int64)v7;
    *v7 = a1;
    v8 = btpower_register_slimdev(a1);
    if ( (v8 & 0x80000000) != 0 )
    {
      v9 = -517;
LABEL_18:
      btfm_slim_unregister_hwep();
      kfree(v7);
      return v9;
    }
    v9 = v8;
    btfm_slim_drv_data = (__int64)v7;
    btfm_slim_major = _register_chrdev(0, 0, 256, "btfm_slim", &bt_dev_fops);
    if ( btfm_slim_major < 0 )
    {
      printk(&unk_899D, "btfm_slim_probe", "btfm_slim_probe");
LABEL_17:
      v9 = -1;
      goto LABEL_18;
    }
    btfm_slim_class = class_create("btfmslim-dev");
    if ( (unsigned __int64)btfm_slim_class >= 0xFFFFFFFFFFFFF001LL )
    {
      printk(&unk_8DBB, "btfm_slim_probe", "btfm_slim_probe");
      goto LABEL_16;
    }
    if ( !device_create() )
    {
      printk(&unk_899D, "btfm_slim_probe", "btfm_slim_probe");
      class_destroy(btfm_slim_class);
LABEL_16:
      _unregister_chrdev((unsigned int)btfm_slim_major, 0, 256, "btfm_slim");
      goto LABEL_17;
    }
  }
  else
  {
    return (unsigned int)-22;
  }
  return v9;
}
