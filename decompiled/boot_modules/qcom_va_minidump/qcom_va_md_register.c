__int64 __fastcall qcom_va_md_register(__int64 a1, _QWORD *a2)
{
  unsigned __int8 v4; // w8
  _QWORD *v5; // x19
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 obj; // x0
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x2
  unsigned int v12; // w0
  unsigned int group; // w0
  __int64 *v14; // x0
  __int64 **v15; // x1
  _QWORD *v16; // x22
  _QWORD *v17; // x8
  unsigned int v18; // w20
  _QWORD *v19; // x0
  _QWORD *v20; // x1
  void *v22; // x0

  if ( (msm_minidump_enabled() & 1) == 0 || (v4 = atomic_load((unsigned __int8 *)&byte_77FA), (v4 & 1) == 0) )
  {
    printk(&unk_79CC, "qcom_va_md_register");
    return 4294967277LL;
  }
  v5 = (_QWORD *)_kmalloc_cache_noprof(sysfs_create_group, 3520, 40);
  if ( !v5 )
    return 4294967284LL;
  v6 = a2[1];
  v7 = a2[2];
  *v5 = *a2;
  v5[1] = v6;
  v5[2] = v7;
  mutex_lock(&va_md_lock);
  obj = kset_find_obj(qword_7810, a1);
  if ( obj )
  {
    v10 = obj;
    printk(&unk_7CA6, "qcom_va_md_register");
    kobject_put(v10);
    goto LABEL_12;
  }
  v9 = _kmalloc_cache_noprof(mutex_lock, 3520, 152);
  v10 = v9;
  if ( v9 )
  {
    v11 = qword_7810 + 24;
    *(_QWORD *)(v9 + 32) = qword_7810;
    v12 = kobject_init_and_add(v9, &va_md_kobj_type, v11, a1);
    if ( v12 )
    {
      v18 = v12;
      v22 = &unk_7A77;
    }
    else
    {
      kobject_uevent(v10, 0);
      group = sysfs_create_group(v10, &va_md_s_attr_group);
      if ( !group )
      {
        *(_DWORD *)(v10 + 96) = 0;
        v14 = (__int64 *)(v10 + 112);
        *(_QWORD *)(v10 + 104) = 0;
        *(_QWORD *)(v10 + 128) = v10 + 128;
        *(_QWORD *)(v10 + 136) = v10 + 128;
        v15 = (__int64 **)qword_7808;
        *(_BYTE *)(v10 + 144) = 0;
        if ( (__int64 *)(v10 + 112) == &qword_7800 || v15 == (__int64 **)v14 || *v15 != &qword_7800 )
        {
          _list_add_valid_or_report();
        }
        else
        {
          qword_7808 = v10 + 112;
          *(_QWORD *)(v10 + 112) = &qword_7800;
          *(_QWORD *)(v10 + 120) = v15;
          *v15 = v14;
        }
LABEL_12:
        v16 = (_QWORD *)(v10 + 128);
        v17 = (_QWORD *)(v10 + 128);
        while ( 1 )
        {
          v17 = (_QWORD *)*v17;
          if ( v17 == v16 )
            break;
          if ( *(v17 - 3) == *v5 )
          {
            printk(&unk_7B86, "qcom_va_md_register");
            kfree(v5);
            v18 = -17;
            goto LABEL_29;
          }
        }
        atomic_notifier_chain_register(v10 + 96, v5);
        v19 = v5 + 3;
        v20 = *(_QWORD **)(v10 + 136);
        if ( v5 + 3 == v16 || v20 == v19 || (_QWORD *)*v20 != v16 )
        {
          _list_add_valid_or_report();
          v18 = 0;
        }
        else
        {
          v18 = 0;
          *(_QWORD *)(v10 + 136) = v19;
          v5[3] = v16;
          v5[4] = v20;
          *v20 = v19;
        }
        goto LABEL_29;
      }
      v18 = group;
      v22 = &unk_7A0B;
    }
    printk(v22, "qcom_va_md_register");
    kobject_put(v10);
    kfree(v5);
  }
  else
  {
    kfree(v5);
    v18 = -12;
  }
LABEL_29:
  mutex_unlock(&va_md_lock);
  return v18;
}
