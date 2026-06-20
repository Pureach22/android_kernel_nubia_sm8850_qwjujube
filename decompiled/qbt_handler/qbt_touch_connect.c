__int64 __fastcall qbt_touch_connect(__int64 a1, __int64 a2)
{
  _QWORD *v4; // x0
  _QWORD *v6; // x20
  unsigned int v7; // w0
  unsigned int v8; // w0
  unsigned int v9; // w19

  v4 = (_QWORD *)_kmalloc_cache_noprof(_kmalloc_cache_noprof, 3520, 88);
  if ( !v4 )
    return 4294967284LL;
  v4[3] = a2;
  v4[4] = a1;
  v4[2] = "qbt_touch";
  v6 = v4;
  v7 = input_register_handle();
  if ( v7 )
  {
    v9 = v7;
    printk(&unk_A112, "qbt_touch_connect");
  }
  else
  {
    v8 = input_open_device(v6);
    if ( !v8 )
    {
      printk(&unk_957D, "qbt_touch_connect");
      return 0;
    }
    v9 = v8;
    printk(&unk_9DA4, "qbt_touch_connect");
    input_unregister_handle(v6);
  }
  kfree(v6);
  return v9;
}
