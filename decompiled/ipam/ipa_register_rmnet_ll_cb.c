__int64 __fastcall ipa_register_rmnet_ll_cb(
        void (__fastcall *a1)(_QWORD),
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x8
  __int64 v13; // x8
  int v14; // w9
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x0
  __int64 v20; // x0
  int v21; // w9
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  int v25; // w0
  __int64 v26; // x8
  __int64 v27; // x0
  __int64 v28; // x0
  int v29; // w19
  __int64 v30; // x8
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  const char *v35[3]; // [xsp+8h] [xbp-28h] BYREF
  int v36; // [xsp+20h] [xbp-10h]
  int v37; // [xsp+24h] [xbp-Ch]
  __int64 v38; // [xsp+28h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_15:
    result = 4294967285LL;
    goto LABEL_16;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 48859) & 1) == 0 )
  {
    printk(&unk_3D0EC3, "ipa_register_rmnet_ll_cb");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d low lat data pipes are not supported", "ipa_register_rmnet_ll_cb", 295);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d low lat data pipes are not supported", "ipa_register_rmnet_ll_cb", 295);
    }
    result = 4294967290LL;
    goto LABEL_16;
  }
  if ( !rmnet_ll_ipa3_ctx )
  {
    v19 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v19 )
    {
      ipc_log_string(v19, "ipa %s:%d rmnet_ll_ctx haven't initialized\n", "ipa_register_rmnet_ll_cb", 300);
      v6 = ipa3_ctx;
    }
    v20 = *(_QWORD *)(v6 + 34160);
    if ( v20 )
      ipc_log_string(v20, "ipa %s:%d rmnet_ll_ctx haven't initialized\n", "ipa_register_rmnet_ll_cb", 300);
    goto LABEL_15;
  }
  mutex_lock(rmnet_ll_ipa3_ctx + 688);
  v13 = rmnet_ll_ipa3_ctx;
  v14 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 56);
  if ( (v14 | 2) != 2 )
  {
    v15 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v16 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d rmnet_ll registered already\n", "ipa_register_rmnet_ll_cb", 307);
        v15 = ipa3_ctx;
      }
      v17 = *(_QWORD *)(v15 + 34160);
      if ( v17 )
        ipc_log_string(v17, "ipa %s:%d rmnet_ll registered already\n", "ipa_register_rmnet_ll_cb", 307);
    }
    mutex_unlock(rmnet_ll_ipa3_ctx + 688);
    result = 4294967279LL;
    goto LABEL_16;
  }
  *(_QWORD *)(rmnet_ll_ipa3_ctx + 592) = a1;
  *(_QWORD *)(v13 + 616) = a2;
  *(_QWORD *)(v13 + 600) = a3;
  *(_QWORD *)(v13 + 624) = a4;
  *(_QWORD *)(v13 + 608) = a5;
  *(_QWORD *)(v13 + 632) = a6;
  if ( v14 )
  {
    if ( *((_DWORD *)a1 - 1) != 251140989 )
      __break(0x823Au);
    a1(a2);
    v13 = rmnet_ll_ipa3_ctx;
    v21 = 3;
  }
  else
  {
    v21 = 1;
  }
  *(_DWORD *)(v13 + 56) = v21;
  v35[0] = "rmnet_ll";
  v35[1] = nullptr;
  v35[2] = nullptr;
  v37 = 0;
  v36 = 1;
  v25 = ipa_pm_register((__int64)v35, (unsigned int *)(v13 + 672));
  if ( v25 )
  {
    v29 = v25;
    printk(&unk_3C6B8B, "ipa3_rmnet_ll_register_pm_client");
    v30 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v31 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v31 )
      {
        ipc_log_string(
          v31,
          "ipa %s:%d failed to create IPA PM client %d\n",
          "ipa3_rmnet_ll_register_pm_client",
          967,
          v29);
        v30 = ipa3_ctx;
      }
      v32 = *(_QWORD *)(v30 + 34160);
      if ( v32 )
        ipc_log_string(
          v32,
          "ipa %s:%d failed to create IPA PM client %d\n",
          "ipa3_rmnet_ll_register_pm_client",
          967,
          v29);
    }
  }
  else
  {
    printk(&unk_3B91F7, "ipa3_rmnet_ll_register_pm_client");
    v26 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v27 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v27 )
      {
        ipc_log_string(v27, "ipa %s:%d %s register done\n", "ipa3_rmnet_ll_register_pm_client", 971, v35[0]);
        v26 = ipa3_ctx;
      }
      v28 = *(_QWORD *)(v26 + 34160);
      if ( v28 )
        ipc_log_string(v28, "ipa %s:%d %s register done\n", "ipa3_rmnet_ll_register_pm_client", 971, v35[0]);
    }
  }
  mutex_unlock(rmnet_ll_ipa3_ctx + 688);
  v33 = ipa3_ctx;
  if ( !ipa3_ctx )
  {
LABEL_44:
    result = 0;
    goto LABEL_16;
  }
  v34 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v34 )
  {
    ipc_log_string(v34, "ipa %s:%d rmnet_ll registered successfually\n", "ipa_register_rmnet_ll_cb", 325);
    v33 = ipa3_ctx;
  }
  result = *(_QWORD *)(v33 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d rmnet_ll registered successfually\n", "ipa_register_rmnet_ll_cb", 325);
    goto LABEL_44;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}
