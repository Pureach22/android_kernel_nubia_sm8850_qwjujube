__int64 __fastcall regmap_qti_debugfs_add(__int64 a1, __int64 a2)
{
  _UNKNOWN **v4; // x8
  __int64 v5; // x20
  __int64 v6; // x0
  void *v7; // x2

  if ( a1 && a2 )
  {
    mutex_lock(&regmap_qti_debugfs_lock);
    v4 = &regmap_qti_debugfs_list;
    while ( 1 )
    {
      v4 = (_UNKNOWN **)*v4;
      if ( v4 == &regmap_qti_debugfs_list )
        break;
      if ( v4[2] == (_UNKNOWN *)a2 )
      {
        dev_err(a1, "%s: qti debugfs files already registered for regmap\n", "regmap_qti_debugfs_add");
        v5 = -22;
        goto LABEL_15;
      }
    }
    v6 = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 40);
    v5 = v6;
    if ( v6 )
    {
      *(_QWORD *)(v6 + 16) = a2;
      *(_QWORD *)(v6 + 24) = a1;
      v7 = regmap_qti_debugfs_list;
      *(_DWORD *)(v6 + 36) = 1;
      if ( v7 == (void *)v6 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)v7) != &regmap_qti_debugfs_list )
      {
        _list_add_valid_or_report(v6, &regmap_qti_debugfs_list);
      }
      else
      {
        *(_QWORD *)((char *)&unk_8 + (_QWORD)v7) = v6;
        *(_QWORD *)v6 = v7;
        *(_QWORD *)(v6 + 8) = &regmap_qti_debugfs_list;
        regmap_qti_debugfs_list = (_UNKNOWN *)v6;
      }
      debugfs_create_x32("address", 384, *(_QWORD *)(a2 + 280), v5 + 32);
      debugfs_create_u32("count", 384, *(_QWORD *)(a2 + 280), v5 + 36);
      debugfs_create_file_unsafe("data", 384, *(_QWORD *)(a2 + 280), v5, &regmap_data_fops);
    }
    else
    {
      v5 = -12;
    }
LABEL_15:
    mutex_unlock(&regmap_qti_debugfs_lock);
  }
  else
  {
    printk(&unk_7907, "regmap_qti_debugfs_add");
    return -22;
  }
  return v5;
}
