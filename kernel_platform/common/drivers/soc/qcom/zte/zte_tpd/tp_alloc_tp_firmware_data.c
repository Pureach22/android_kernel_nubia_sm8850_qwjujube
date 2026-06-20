__int64 __fastcall tp_alloc_tp_firmware_data(int a1)
{
  __int64 v2; // x20
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x1
  __int64 v9; // x2
  _QWORD *v10; // x8

  v2 = tpd_cdev;
  v3 = *(_QWORD *)(tpd_cdev + 2720);
  if ( v3 )
  {
    v4 = *(_QWORD *)(v3 + 8);
    if ( v4 )
    {
      vfree(v4);
      *(_QWORD *)(*(_QWORD *)(v2 + 2720) + 8LL) = 0;
      **(_QWORD **)(v2 + 2720) = 0;
      v3 = *(_QWORD *)(v2 + 2720);
    }
    kfree(v3);
    *(_QWORD *)(v2 + 2720) = 0;
  }
  *(_DWORD *)(v2 + 1096) = 0;
  v5 = _kmalloc_cache_noprof(remove_proc_entry, 3520, 24);
  *(_QWORD *)(v2 + 2720) = v5;
  if ( v5 )
  {
    *(_QWORD *)(*(_QWORD *)(v2 + 2720) + 8LL) = vmalloc_noprof(a1 + 24LL);
    v10 = *(_QWORD **)(v2 + 2720);
    if ( v10[1] )
    {
      *v10 = a1;
      memset(*(void **)(*(_QWORD *)(v2 + 2720) + 8LL), 0, a1 + 24LL);
      return 0;
    }
    else
    {
      printk(unk_3B60C, v8, v9);
      kfree(*(_QWORD *)(v2 + 2720));
      return 4294967284LL;
    }
  }
  else
  {
    printk(unk_3224B, v6, v7);
    return 4294967284LL;
  }
}
