__int64 __fastcall dcc_sram_dev_init(__int64 a1)
{
  char *v2; // x0
  unsigned int v3; // w0
  __int64 v4; // x1
  unsigned int v5; // w0
  unsigned __int64 v6; // x0
  unsigned int v7; // w20
  unsigned __int64 v8; // x0
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (char *)devm_kmalloc(*(_QWORD *)(a1 + 16), 9, 3520);
  *(_QWORD *)(a1 + 160) = v2;
  if ( !v2 )
  {
    v7 = -12;
    goto LABEL_14;
  }
  v10 = 0;
  strcpy(v2, "dcc_sram");
  v3 = alloc_chrdev_region(&v10, 0, 1, v2);
  if ( v3 )
  {
    v7 = v3;
LABEL_13:
    dev_err(*(_QWORD *)(a1 + 16), "DCC: sram node not registered.\n");
    goto LABEL_14;
  }
  cdev_init(a1 + 168, &dcc_sram_fops);
  v4 = v10;
  *(_QWORD *)(a1 + 264) = &_this_module;
  v5 = cdev_add(a1 + 168, v4, 1);
  if ( v5 )
  {
    v7 = v5;
    unregister_chrdev_region(*(unsigned int *)(a1 + 296), 1);
    goto LABEL_13;
  }
  v6 = class_create(*(_QWORD *)(a1 + 160));
  v7 = v6;
  *(_QWORD *)(a1 + 304) = v6;
  if ( v6 <= 0xFFFFFFFFFFFFF000LL )
  {
    v8 = device_create(v6, 0, *(unsigned int *)(a1 + 296), a1, *(_QWORD *)(a1 + 160));
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      v7 = 0;
      goto LABEL_14;
    }
    v7 = v8;
    class_destroy(*(_QWORD *)(a1 + 304));
  }
  cdev_del(a1 + 168);
  unregister_chrdev_region(*(unsigned int *)(a1 + 296), 1);
  if ( v7 )
    goto LABEL_13;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v7;
}
