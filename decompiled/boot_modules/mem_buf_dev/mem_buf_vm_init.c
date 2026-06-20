__int64 __fastcall mem_buf_vm_init(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w0
  __int64 v4; // x2
  unsigned __int64 v5; // x19
  char **v6; // x0
  char ***v7; // x23
  __int64 v8; // x0
  __int64 v9; // x20
  int v10; // w0
  __int64 v12; // x0
  int v14; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 744);
  v14 = 0;
  v3 = of_property_read_variable_u32_array(v2, "qcom,vmid", &v14, 1, 0);
  if ( v3 < 0 )
  {
    LODWORD(v5) = v3;
    dev_err(a1, "missing qcom,vmid property\n", v4);
  }
  else
  {
    current_vmid = v14;
    LODWORD(v5) = alloc_chrdev_region(&mem_buf_vm_devt, 0, 128, "mem_buf_vm");
    if ( !(_DWORD)v5 )
    {
      v5 = class_create("mem_buf_vm");
      mem_buf_vm_class = v5;
      if ( v5 >= 0xFFFFFFFFFFFFF001LL )
      {
LABEL_18:
        unregister_chrdev_region((unsigned int)mem_buf_vm_devt, 128);
        goto LABEL_19;
      }
      v6 = pdata_array[0];
      *(_QWORD *)(v5 + 32) = mem_buf_vm_devnode;
      if ( v6 )
      {
        v7 = off_760;
        _ReadStatusReg(SP_EL0);
        do
        {
          v8 = kmemdup_noprof();
          v9 = v8;
          if ( !v8 )
            goto LABEL_16;
          v10 = mem_buf_vm_add(v8);
          if ( v10 )
          {
            LODWORD(v5) = v10;
            goto LABEL_15;
          }
        }
        while ( *v7++ );
      }
      v5 = xa_load(&mem_buf_vms, current_vmid);
      if ( v5 )
      {
        v12 = _kmalloc_cache_noprof(xa_find_after, 3520, 1064);
        v9 = v12;
        if ( v12 )
        {
          *(_QWORD *)v12 = "qcom,self";
          *(_WORD *)(v12 + 8) = *(_WORD *)(v5 + 8);
          *(_DWORD *)(v12 + 12) = *(_DWORD *)(v5 + 12);
          LODWORD(v5) = mem_buf_vm_add(v12);
          if ( !(_DWORD)v5 )
            goto LABEL_19;
LABEL_15:
          kfree(v9);
          goto LABEL_17;
        }
LABEL_16:
        LODWORD(v5) = -12;
LABEL_17:
        xa_destroy(&mem_buf_vms);
        xa_destroy(&mem_buf_vm_minors);
        class_for_each_device(mem_buf_vm_class, 0, 0, mem_buf_vm_put_class_device_cb);
        class_destroy(mem_buf_vm_class);
        goto LABEL_18;
      }
    }
  }
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}
