__int64 __fastcall qcom_va_md_unregister(__int64 a1, _QWORD *a2)
{
  unsigned __int8 v4; // w8
  __int64 obj; // x0
  _QWORD *v6; // x19
  _QWORD *v7; // x20
  _QWORD *v8; // x23
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  _QWORD *v11; // x8
  _QWORD *v12; // x9
  _QWORD *v13; // x8
  _QWORD *v14; // x0
  __int64 v15; // x9
  unsigned int v16; // w19

  if ( (msm_minidump_enabled() & 1) != 0 && (v4 = atomic_load((unsigned __int8 *)&byte_77FA), (v4 & 1) != 0) )
  {
    mutex_lock(&va_md_lock);
    obj = kset_find_obj(qword_7810, a1);
    if ( obj )
    {
      v6 = (_QWORD *)obj;
      kobject_put(obj);
      v7 = v6 + 16;
      v8 = v6 + 16;
      do
      {
        v8 = (_QWORD *)*v8;
        if ( v8 == v7 )
        {
          printk(&unk_7AA9, "qcom_va_md_unregister");
          v16 = -22;
          goto LABEL_19;
        }
      }
      while ( *(v8 - 3) != *a2 );
      atomic_notifier_chain_unregister(v6 + 12, v8 - 3);
      v9 = (_QWORD *)v8[1];
      if ( (_QWORD *)*v9 == v8 && (v10 = (_QWORD *)*v8, *(_QWORD **)(*v8 + 8LL) == v8) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v8);
      }
      *v8 = 0xDEAD000000000100LL;
      v8[1] = 0xDEAD000000000122LL;
      kfree(v8 - 3);
      v11 = (_QWORD *)*v7;
      if ( (_QWORD *)*v7 == v7 )
      {
        v12 = (_QWORD *)v6[17];
        if ( (_QWORD *)*v12 == v7 && (_QWORD *)v11[1] == v7 )
        {
          v11[1] = v12;
          *v12 = v11;
        }
        else
        {
          _list_del_entry_valid_or_report(v6 + 16);
        }
        v6[16] = 0xDEAD000000000100LL;
        v6[17] = 0xDEAD000000000122LL;
        sysfs_remove_group(v6, &va_md_s_attr_group);
        kobject_put(v6);
        v13 = (_QWORD *)v6[15];
        v14 = v6 + 14;
        if ( (_QWORD *)*v13 == v6 + 14 && (v15 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
        {
          *(_QWORD *)(v15 + 8) = v13;
          *v13 = v15;
        }
        else
        {
          _list_del_entry_valid_or_report(v14);
        }
        v6[14] = 0xDEAD000000000100LL;
        v6[15] = 0xDEAD000000000122LL;
        kfree(v6);
      }
      v16 = 0;
LABEL_19:
      mutex_unlock(&va_md_lock);
    }
    else
    {
      printk(&unk_781C, "qcom_va_md_unregister");
      mutex_unlock(&va_md_lock);
      return (unsigned int)-22;
    }
  }
  else
  {
    printk(&unk_79CC, "qcom_va_md_unregister");
    return (unsigned int)-19;
  }
  return v16;
}
