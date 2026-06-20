__int64 __fastcall regulator_debug_add(__int64 a1, _QWORD *a2)
{
  __int64 v4; // x20
  void *v5; // x2
  __int64 v6; // x21
  _QWORD *v7; // x22
  unsigned int v8; // w9
  __int64 v9; // x1
  char v10; // w8
  __int64 v11; // x1
  _BOOL4 v12; // w8
  unsigned int v13; // w9
  __int64 v14; // x1
  __int64 v15; // x1

  if ( !a1 || !a2 )
  {
    printk(&unk_7CE6, "regulator_debug_add");
    return -22;
  }
  v4 = _kmalloc_cache_noprof(printk, 3520, 40);
  if ( !v4 )
    return -12;
  *(_QWORD *)(v4 + 24) = a1;
  *(_QWORD *)(v4 + 32) = a2;
  mutex_lock(&debug_reg_list_lock);
  v5 = debug_reg_list;
  if ( debug_reg_list == (_UNKNOWN *)v4 || *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)debug_reg_list) != &debug_reg_list )
  {
    _list_add_valid_or_report(v4, &debug_reg_list);
  }
  else
  {
    *(_QWORD *)((char *)&unk_8 + (_QWORD)debug_reg_list) = v4;
    *(_QWORD *)v4 = v5;
    *(_QWORD *)(v4 + 8) = &debug_reg_list;
    debug_reg_list = (_UNKNOWN *)v4;
  }
  mutex_unlock(&debug_reg_list_lock);
  v6 = a2[161];
  v7 = *(_QWORD **)(*a2 + 64LL);
  debugfs_create_file_unsafe("enable", 420, v6, v4, &reg_enable_fops);
  if ( v7[28] )
    debugfs_create_file_unsafe("bypass", 420, v6, v4, &reg_bypass_enable_fops);
  if ( *(_OWORD *)(v7 + 15) != 0 )
  {
    if ( v7[16] )
      v8 = 292;
    else
      v8 = 0;
    if ( v7[15] )
      v9 = v8 | 0x80;
    else
      v9 = v8;
    debugfs_create_file_unsafe("force_disable", v9, v6, v4, &reg_force_disable_fops);
  }
  if ( v7[4] || v7[5] )
  {
    v10 = 0;
    v11 = 292;
    if ( v7[1] )
    {
LABEL_24:
      v11 = (unsigned int)v11 | 0x80;
      goto LABEL_25;
    }
  }
  else
  {
    v11 = 0;
    v10 = 1;
    if ( v7[1] )
      goto LABEL_24;
  }
  if ( v7[3] )
    goto LABEL_24;
  if ( (v10 & 1) == 0 )
LABEL_25:
    debugfs_create_file_unsafe("voltage", v11, v6, v4, &reg_voltage_fops);
  if ( *(_OWORD *)(v7 + 17) == 0 )
  {
    v12 = 1;
    if ( v7[27] )
    {
LABEL_38:
      if ( v12 )
        v15 = 128;
      else
        v15 = 420;
      goto LABEL_41;
    }
  }
  else
  {
    if ( v7[18] )
      v13 = 292;
    else
      v13 = 0;
    if ( v7[17] )
      v14 = v13 | 0x80;
    else
      v14 = v13;
    debugfs_create_file_unsafe("mode", v14, v6, v4, &reg_mode_fops);
    v12 = v7[18] == 0;
    if ( v7[27] )
      goto LABEL_38;
  }
  if ( v7[26] && v7[17] )
    goto LABEL_38;
  if ( v12 )
    goto LABEL_42;
  v15 = 292;
LABEL_41:
  debugfs_create_file_unsafe("load", v15, v6, v4, &reg_set_load_fops);
LABEL_42:
  debugfs_create_file("consumers", 292, v6, a2, &reg_consumers_fops);
  return v4;
}
