__int64 __fastcall ccid_cdev_init(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w19
  unsigned int v7; // w0
  __int64 v8; // x2
  unsigned __int64 v9; // x0
  unsigned int v10; // w22

  v6 = ida_alloc_range(&ccid_ida, 0, 3, 3264);
  if ( (v6 & 0x80000000) != 0 )
  {
    printk(&unk_8433, "ccid_cdev_init", v6);
    return v6;
  }
  cdev_init(a1, a2);
  v7 = cdev_add(a1, v6 | (major << 20), 1);
  if ( v7 )
  {
    v10 = v7;
    printk(&unk_83E4, a3, v8);
  }
  else
  {
    v9 = device_create(ccid_class, 0, v6 | (major << 20), 0, a3);
    if ( v9 < 0xFFFFFFFFFFFFF001LL )
      return 0;
    v10 = v9;
    cdev_del(a1);
  }
  ida_free(&ccid_ida, v6);
  return v10;
}
