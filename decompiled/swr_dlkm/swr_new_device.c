__int64 __fastcall swr_new_device(__int64 a1, __int64 a2)
{
  __int64 v4; // x20
  __int64 v5; // x8
  size_t v6; // x0
  unsigned __int64 v7; // x2
  __int64 v8; // x8
  __int64 v9; // x2
  __int64 *v10; // x1
  int v11; // w0
  int v12; // w22
  _QWORD *v13; // x8
  __int64 v14; // x9

  if ( !a1 || !get_device() )
  {
    if ( (unsigned int)__ratelimit(&swr_new_device__rs, "swr_new_device") )
      printk(&unk_9B89, "swr_new_device");
    return 0;
  }
  v4 = _kmalloc_cache_noprof(of_get_next_available_child, 3520, 1016);
  if ( !v4 )
  {
    put_device(a1);
    return v4;
  }
  v5 = *(_QWORD *)(a2 + 40);
  *(_QWORD *)(v4 + 32) = a1;
  *(_QWORD *)(v4 + 984) = v5;
  v6 = strnlen((const char *)a2, 0x20u);
  if ( v6 >= 0x21 )
  {
    _fortify_panic(2, 32, v6 + 1);
LABEL_26:
    _fortify_panic(7, 32, v7);
    goto LABEL_27;
  }
  if ( v6 == 32 )
    v7 = 32;
  else
    v7 = v6 + 1;
  if ( v7 >= 0x21 )
    goto LABEL_26;
  sized_strscpy(v4, a2);
  *(_QWORD *)(v4 + 168) = a1;
  *(_QWORD *)(v4 + 192) = &swr_dev_type;
  *(_QWORD *)(v4 + 200) = &soundwire_type;
  v8 = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(v4 + 880) = swr_dev_release;
  *(_QWORD *)(v4 + 816) = v8;
  mutex_lock(a1 + 936);
  a2 = v4 + 48;
  v9 = a1 + 984;
  v10 = *(__int64 **)(a1 + 992);
  if ( v4 + 48 != a1 + 984 && v10 != (__int64 *)a2 && *v10 == v9 )
  {
    *(_QWORD *)(a1 + 992) = a2;
    *(_QWORD *)(v4 + 48) = v9;
    *(_QWORD *)(v4 + 56) = v10;
    *v10 = a2;
    goto LABEL_13;
  }
LABEL_27:
  _list_add_valid_or_report(a2, v10);
LABEL_13:
  mutex_unlock(a1 + 936);
  dev_set_name(v4 + 72, "%s.%llx", (const char *)v4, *(_QWORD *)(v4 + 984));
  v11 = device_register(v4 + 72);
  if ( v11 )
  {
    v12 = v11;
    if ( (unsigned int)__ratelimit(&swr_new_device__rs_4, "swr_new_device") )
      dev_err(a1, "device [%s] register failed err %d\n", (const char *)v4, v12);
    put_device(a1);
    v13 = *(_QWORD **)(v4 + 56);
    if ( *v13 == a2 && (v14 = *(_QWORD *)a2, *(_QWORD *)(*(_QWORD *)a2 + 8LL) == a2) )
    {
      *(_QWORD *)(v14 + 8) = v13;
      *v13 = v14;
    }
    else
    {
      _list_del_entry_valid_or_report(a2);
    }
    *(_QWORD *)(v4 + 48) = v4 + 48;
    *(_QWORD *)(v4 + 56) = a2;
    kfree(v4);
    return 0;
  }
  return v4;
}
