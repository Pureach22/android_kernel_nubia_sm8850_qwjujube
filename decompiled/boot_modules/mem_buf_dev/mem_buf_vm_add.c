__int64 __fastcall mem_buf_vm_add(const char **a1)
{
  const char **v2; // x0
  const char *v3; // x21
  __int64 v4; // x2
  unsigned __int64 v5; // x20
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x10
  const char *v9; // x2
  unsigned int v10; // w8
  unsigned __int64 v11; // x0
  __int64 v12; // x2
  __int64 v14; // [xsp+8h] [xbp-18h] BYREF
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v14 = 0;
  v2 = (const char **)xa_find(&mem_buf_vm_minors, &v14, -1, 8);
  if ( v2 )
  {
    while ( 1 )
    {
      v3 = *v2;
      if ( !strcmp(*v2, *a1) )
        break;
      v2 = (const char **)xa_find_after(&mem_buf_vm_minors, &v14, -1, 8);
      if ( !v2 )
        goto LABEL_4;
    }
    printk(&unk_136B6, v3, v4);
    LODWORD(v5) = -22;
  }
  else
  {
LABEL_4:
    raw_spin_lock(&mem_buf_vm_minors);
    LODWORD(v5) = _xa_alloc(&mem_buf_vm_minors, &v15, a1, 127, 3264);
    raw_spin_unlock(&mem_buf_vm_minors);
    if ( (v5 & 0x80000000) != 0 )
    {
      printk(&unk_13BAC, v6, v7);
      goto LABEL_10;
    }
    cdev_init(a1 + 2, &mem_buf_vm_fops);
    device_initialize(a1 + 19);
    v8 = mem_buf_vm_class;
    v9 = *a1;
    v10 = mem_buf_vm_devt & 0xFFF00000 | v15;
    a1[31] = nullptr;
    a1[120] = (const char *)mem_buf_vm_device_release;
    a1[118] = (const char *)v8;
    *((_DWORD *)a1 + 228) = v10;
    a1[38] = (const char *)a1;
    dev_set_name(a1 + 19, "%s", v9);
    v11 = xa_store(&mem_buf_vms, *((unsigned __int16 *)a1 + 4), a1, 3264);
    if ( v11 < 0xFFFFFFFFFFFFC006LL || (v11 & 3) != 2 || (v5 = v11 >> 2, !(unsigned int)(v11 >> 2)) )
    {
      LODWORD(v5) = cdev_device_add(a1 + 2, a1 + 19);
      if ( !(_DWORD)v5 )
        goto LABEL_10;
      printk(&unk_1306B, *a1, v12);
      xa_erase(&mem_buf_vms, *((unsigned __int16 *)a1 + 4));
    }
    xa_erase(&mem_buf_vm_minors, v15);
    put_device(a1 + 19);
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
