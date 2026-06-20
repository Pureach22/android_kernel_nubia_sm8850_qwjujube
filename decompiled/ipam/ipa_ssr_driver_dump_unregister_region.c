__int64 __fastcall ipa_ssr_driver_dump_unregister_region(const char *a1)
{
  const char *v2; // x20
  __int64 v3; // x21
  unsigned int v4; // w19
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  if ( a1 )
  {
    mutex_lock(&region_list_mutex);
    v2 = (const char *)&dump_entry_list;
    v3 = 150;
    while ( strcmp(v2, a1) || !*((_QWORD *)v2 + 13) )
    {
      --v3;
      v2 += 128;
      if ( !v3 )
        goto LABEL_10;
    }
    if ( v2 )
    {
      v4 = 0;
      *((_QWORD *)v2 + 13) = 0;
      --num_of_regions_registered;
      goto LABEL_8;
    }
LABEL_10:
    printk(&unk_3B7CC8, "ipa_ssr_driver_dump_unregister_region");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d couldn't find entry: %s", "ipa_ssr_driver_dump_unregister_region", 312, a1);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d couldn't find entry: %s", "ipa_ssr_driver_dump_unregister_region", 312, a1);
    }
    v4 = -14;
LABEL_8:
    mutex_unlock(&region_list_mutex);
  }
  else
  {
    printk(&unk_3EC1F2, "ipa_ssr_driver_dump_unregister_region");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d null region_name", "ipa_ssr_driver_dump_unregister_region", 304);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d null region_name", "ipa_ssr_driver_dump_unregister_region", 304);
    }
    return (unsigned int)-14;
  }
  return v4;
}
