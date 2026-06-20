__int64 __fastcall ipa_ssr_driver_dump_retrieve_regions(__int64 a1, _QWORD *a2)
{
  int v3; // w19
  __int64 v4; // x27
  __int64 v5; // x12
  _QWORD *v6; // x24
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x11
  __int64 v14; // x12
  __int64 v15; // x9
  __int64 v16; // x8
  __int64 v17; // x11
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0

  if ( !a1 || !a2 )
  {
    printk(&unk_3F1E32, "ipa_ssr_driver_dump_retrieve_regions");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(
          v26,
          "ipa %s:%d null input_array or num_entries_loaded",
          "ipa_ssr_driver_dump_retrieve_regions",
          344);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
      {
        ipc_log_string(
          v27,
          "ipa %s:%d null input_array or num_entries_loaded",
          "ipa_ssr_driver_dump_retrieve_regions",
          344);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  mutex_lock(&region_list_mutex);
  v3 = 0;
  v4 = -19200;
  do
  {
    if ( *(_QWORD *)((char *)&dump_entry_list + v4 + 19304) )
    {
      v5 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19208);
      v6 = (_QWORD *)(a1 + ((__int64)v3 << 7));
      v7 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19216);
      v8 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19224);
      *v6 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19200);
      v6[1] = v5;
      v6[2] = v7;
      v6[3] = v8;
      v9 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19256);
      v10 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19232);
      v11 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19240);
      v6[6] = *(_QWORD *)((char *)&dump_entry_list + v4 + 19248);
      v6[7] = v9;
      v6[4] = v10;
      v6[5] = v11;
      v12 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19288);
      v13 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19264);
      v14 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19272);
      v6[10] = *(_QWORD *)((char *)&dump_entry_list + v4 + 19280);
      v6[11] = v12;
      v6[8] = v13;
      v6[9] = v14;
      v15 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19320);
      v17 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19296);
      v16 = *(_QWORD *)((char *)&dump_entry_list + v4 + 19304);
      v6[14] = *(_QWORD *)((char *)&dump_entry_list + v4 + 19312);
      v6[15] = v15;
      v6[12] = v17;
      v6[13] = v16;
      v18 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v19 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v19 )
        {
          ipc_log_string(
            v19,
            "ipa %s:%d input index %d, region name: %s, entry_num: %d\n",
            "ipa_ssr_driver_dump_retrieve_regions",
            357,
            v3,
            (const char *)(a1 + ((__int64)v3 << 7)),
            *((unsigned __int8 *)v6 + 120));
          v18 = ipa3_ctx;
        }
        v20 = *(_QWORD *)(v18 + 34160);
        if ( v20 )
          ipc_log_string(
            v20,
            "ipa %s:%d input index %d, region name: %s, entry_num: %d\n",
            "ipa_ssr_driver_dump_retrieve_regions",
            357,
            v3,
            (const char *)(a1 + ((__int64)v3 << 7)),
            *((unsigned __int8 *)v6 + 120));
      }
      ++v3;
    }
    v4 += 128;
  }
  while ( v4 );
  v21 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v22 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v22 )
    {
      ipc_log_string(
        v22,
        "ipa %s:%d input index %d, no of regions registered:%zu\n",
        "ipa_ssr_driver_dump_retrieve_regions",
        363,
        v3,
        num_of_regions_registered);
      v21 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v21 + 34160);
    if ( v23 )
      ipc_log_string(
        v23,
        "ipa %s:%d input index %d, no of regions registered:%zu\n",
        "ipa_ssr_driver_dump_retrieve_regions",
        363,
        v3,
        num_of_regions_registered);
  }
  if ( num_of_regions_registered != v3 )
  {
    printk(&unk_3AF5E8, "ipa_ssr_driver_dump_retrieve_regions");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d num entries mismatch index:%d num reg registered:%zu",
          "ipa_ssr_driver_dump_retrieve_regions",
          367,
          v3,
          num_of_regions_registered);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(
          v30,
          "ipa %s:%d num entries mismatch index:%d num reg registered:%zu",
          "ipa_ssr_driver_dump_retrieve_regions",
          367,
          v3,
          num_of_regions_registered);
    }
    mutex_unlock(&region_list_mutex);
    return 4294967282LL;
  }
  *a2 = v3;
  mutex_unlock(&region_list_mutex);
  return 0;
}
