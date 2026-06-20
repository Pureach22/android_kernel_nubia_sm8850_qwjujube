__int64 __fastcall hfi_core_dbg_debugfs_unregister(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  _QWORD *v6; // x20
  _QWORD *v7; // x21
  _QWORD *v8; // x26
  _QWORD *v9; // x8
  _QWORD *v10; // x9
  __int64 result; // x0
  __int64 v12; // x3
  int v13; // w8
  __int64 v14; // x20

  if ( (~msm_hfi_core_debug_level & 0x10001) != 0 )
  {
    if ( !a1 )
      return printk(&unk_1905C, "hfi_core_dbg_debugfs_unregister", 2956, v4);
  }
  else
  {
    v14 = v4;
    printk(&unk_1E83A, "hfi_core_dbg_debugfs_unregister", 2953, a4);
    v4 = v14;
    if ( !a1 )
      return printk(&unk_1905C, "hfi_core_dbg_debugfs_unregister", 2956, v4);
  }
  v6 = *(_QWORD **)(a1 + 792);
  if ( !v6 )
    return printk(&unk_1905C, "hfi_core_dbg_debugfs_unregister", 2956, v4);
  if ( v6[14] )
    kthread_stop();
  v7 = (_QWORD *)v6[15];
  if ( v7 != v6 + 15 )
  {
    do
    {
      v8 = (_QWORD *)*v7;
      kfree(*(v7 - 2));
      v9 = (_QWORD *)v7[1];
      if ( (_QWORD *)*v9 == v7 && (v10 = (_QWORD *)*v7, *(_QWORD **)(*v7 + 8LL) == v7) )
      {
        v10[1] = v9;
        *v9 = v10;
      }
      else
      {
        _list_del_entry_valid_or_report(v7);
      }
      *v7 = 0xDEAD000000000100LL;
      v7[1] = 0xDEAD000000000122LL;
      kfree(v7 - 3);
      v7 = v8;
    }
    while ( v8 != v6 + 15 );
  }
  if ( *v6 )
    debugfs_remove(*v6);
  result = kfree(v6);
  v13 = msm_hfi_core_debug_level;
  *(_QWORD *)(a1 + 792) = 0;
  if ( (~v13 & 0x10001) == 0 )
    return printk(&unk_1C28B, "hfi_core_dbg_debugfs_unregister", 2977, v12);
  return result;
}
