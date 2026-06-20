__int64 __fastcall ipa_debugfs_control_flt_rt_stats(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x0
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  v5 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 24);
  v6 = v5;
  if ( !v5 )
    return -12;
  *(_DWORD *)(v5 + 4) = 16;
  v7 = _kmalloc_cache_noprof(scnprintf, 3520, 512);
  *(_QWORD *)(v6 + 16) = v7;
  if ( !v7 )
  {
    kfree(v6);
    return -12;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( a3 > 0xFFF
    || (_check_object_size(&dbg_buff_1, a3, 0),
        ((__int64 (__fastcall *)(__int64, unsigned __int64))inline_copy_from_user_1)(a2, a3)) )
  {
    a3 = -14;
  }
  else
  {
    *((_BYTE *)&dbg_buff_1 + a3) = 0;
    if ( dbg_buff_1 == 1702061426 && *(int *)((char *)&dbg_buff_1 + 3) == 685157 )
    {
      *(_BYTE *)(v6 + 2) = 1;
      *(_WORD *)v6 = 8193;
      ipa_get_flt_rt_stats((unsigned __int8 *)v6);
    }
    else
    {
      printk(&unk_3FB516, "ipa_debugfs_control_flt_rt_stats");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d unsupport flt_rt command\n", "ipa_debugfs_control_flt_rt_stats", 2580);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(v11, "ipa %s:%d unsupport flt_rt command\n", "ipa_debugfs_control_flt_rt_stats", 2580);
      }
    }
  }
  kfree(*(_QWORD *)(v6 + 16));
  kfree(v6);
  mutex_unlock(ipa3_ctx + 29472);
  return a3;
}
