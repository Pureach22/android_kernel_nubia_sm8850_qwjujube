__int64 __fastcall btfm_swr_probe(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v5; // w19
  __int64 v6; // x0

  printk(&unk_7767, "btfm_swr_probe");
  v2 = devm_kmalloc(a1 + 72, 48, 3520);
  pbtfmswr = v2;
  if ( v2 )
  {
    *(_QWORD *)(a1 + 224) = v2;
    *(_QWORD *)v2 = a1 + 72;
    *(_QWORD *)(v2 + 8) = a1;
    *(_BYTE *)(v2 + 16) = 0;
    v3 = btfm_swr_register_hw_ep();
    if ( (_DWORD)v3 )
    {
      v5 = v3;
      printk(&unk_7660, "btfm_swr_probe");
    }
    else
    {
      btfm_swr_major = _register_chrdev(v3, 0, 256, "btfm_swr", &bt_dev_fops);
      if ( btfm_swr_major < 0 )
      {
        v6 = printk(&unk_74A3, "btfm_swr_probe");
      }
      else
      {
        btfm_swr_class = class_create("btfmswr-dev");
        if ( (unsigned __int64)btfm_swr_class >= 0xFFFFFFFFFFFFF001LL )
        {
          printk(&unk_76FA, "btfm_swr_probe");
        }
        else
        {
          if ( device_create() )
            return 0;
          printk(&unk_74A3, "btfm_swr_probe");
          class_destroy(btfm_swr_class);
        }
        v6 = _unregister_chrdev((unsigned int)btfm_swr_major, 0, 256, "btfm_swr");
      }
      btfm_swr_unregister_hwep(v6);
      v5 = -1;
    }
    kfree(pbtfmswr);
    return v5;
  }
  else
  {
    printk(&unk_75E6, "btfm_swr_probe");
    return 4294967284LL;
  }
}
