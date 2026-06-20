__int64 qcom_va_md_driver_remove()
{
  __int64 *v0; // x19
  __int64 *v1; // x22
  __int64 *v2; // x23
  __int64 *v3; // x28
  __int64 *v4; // x20
  __int64 **v5; // x8
  __int64 *v6; // x9
  __int64 **v7; // x8
  __int64 *v8; // x9
  __int64 **v9; // x8
  __int64 *v10; // x9

  mutex_lock(&va_md_lock);
  v0 = (__int64 *)qword_7800;
  if ( (__int64 *)qword_7800 != &qword_7800 )
  {
    do
    {
      v1 = v0 + 2;
      v2 = (__int64 *)v0[2];
      v3 = (__int64 *)*v0;
      if ( v2 != v0 + 2 )
      {
        do
        {
          v4 = (__int64 *)*v2;
          atomic_notifier_chain_unregister(v0 - 2, v2 - 3);
          v5 = (__int64 **)v2[1];
          if ( *v5 == v2 && (v6 = (__int64 *)*v2, *(__int64 **)(*v2 + 8) == v2) )
          {
            v6[1] = (__int64)v5;
            *v5 = v6;
          }
          else
          {
            _list_del_entry_valid_or_report(v2);
          }
          *v2 = 0xDEAD000000000100LL;
          v2[1] = 0xDEAD000000000122LL;
          kfree(v2 - 3);
          v2 = v4;
        }
        while ( v4 != v1 );
      }
      v7 = (__int64 **)v0[3];
      if ( *v7 == v1 && (v8 = (__int64 *)*v1, *(__int64 **)(*v1 + 8) == v1) )
      {
        v8[1] = (__int64)v7;
        *v7 = v8;
      }
      else
      {
        _list_del_entry_valid_or_report(v0 + 2);
      }
      v0[2] = 0xDEAD000000000100LL;
      v0[3] = 0xDEAD000000000122LL;
      sysfs_remove_group(v0 - 14, &va_md_s_attr_group);
      kobject_put(v0 - 14);
      v9 = (__int64 **)v0[1];
      if ( *v9 == v0 && (v10 = (__int64 *)*v0, *(__int64 **)(*v0 + 8) == v0) )
      {
        v10[1] = (__int64)v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v0);
      }
      *v0 = 0xDEAD000000000100LL;
      v0[1] = 0xDEAD000000000122LL;
      kfree(v0 - 14);
      v0 = v3;
    }
    while ( v3 != &qword_7800 );
  }
  mutex_unlock(&va_md_lock);
  kset_unregister(qword_7810);
  atomic_notifier_chain_unregister(&panic_notifier_list, &qcom_va_md_elf_panic_blk);
  atomic_notifier_chain_unregister(&panic_notifier_list, &qcom_va_md_panic_blk);
  return vunmap(qword_7788);
}
