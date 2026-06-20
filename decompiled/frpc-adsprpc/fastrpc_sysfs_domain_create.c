__int64 __fastcall fastrpc_sysfs_domain_create(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  int v8; // w9
  __int64 v9; // x0
  void *v10; // x1
  unsigned int v11; // w0
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  unsigned int v18; // w20

  if ( fastrpc_kset )
  {
    v8 = *(unsigned __int8 *)(a1 + 51);
    *(_QWORD *)(a1 + 112) = fastrpc_kset;
    v9 = a1 + 80;
    if ( v8 )
      v10 = &frpc_legacy_kobj_type;
    else
      v10 = &frpc_kobj_type;
    v11 = kobject_init_and_add(v9, v10, 0, a1 + 20);
    if ( v11 )
    {
      v18 = v11;
      printk(&unk_23C2A, "fastrpc_sysfs_domain_create", a1 + 20, v12, v13, v14);
      kobject_put(a1 + 80);
      return v18;
    }
    else
    {
      kobject_uevent(a1 + 80, 0);
      printk(&unk_268E9, "fastrpc_sysfs_domain_create", a1 + 20, v15, v16, v17);
      return 0;
    }
  }
  else
  {
    printk(&unk_268BF, "fastrpc_sysfs_domain_create", a1 + 20, a4, a5, a6);
    return 4294967274LL;
  }
}
