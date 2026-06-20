__int64 __fastcall sec_etr_sram_dev_register(__int64 a1)
{
  __int64 v2; // x3
  unsigned int v3; // w20
  __int64 v4; // x1
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 16);
  v8 = 0;
  v3 = alloc_chrdev_region(&v8, 0, 1, v2);
  if ( !v3 )
  {
    cdev_init(a1 + 24, &secure_etr_fops);
    v4 = v8;
    *(_QWORD *)(a1 + 120) = &_this_module;
    v3 = cdev_add(a1 + 24, v4, 1);
    if ( !v3 )
    {
      v5 = class_create(*(_QWORD *)(a1 + 16));
      v3 = v5;
      *(_QWORD *)(a1 + 160) = v5;
      if ( v5 <= 0xFFFFFFFFFFFFF000LL )
      {
        v6 = device_create(v5, 0, *(unsigned int *)(a1 + 152), a1, *(_QWORD *)(a1 + 16));
        if ( v6 < 0xFFFFFFFFFFFFF001LL )
        {
          v3 = 0;
          goto LABEL_8;
        }
        v3 = v6;
        class_destroy(*(_QWORD *)(a1 + 160));
      }
      cdev_del(a1 + 24);
    }
    unregister_chrdev_region(*(unsigned int *)(a1 + 152), 1);
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v3;
}
