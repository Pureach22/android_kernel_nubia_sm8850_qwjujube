__int64 ipa3_teardown_apps_low_lat_data_pipes()
{
  __int64 v0; // x8
  int v1; // w3
  int v2; // w9
  void (__fastcall *v5)(_QWORD); // x9
  __int64 v6; // x0
  __int64 result; // x0
  char v8; // w9
  __int64 v9; // x8
  char v10; // w9
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w19
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0

  v0 = rmnet_ll_ipa3_ctx;
  v1 = *(_DWORD *)(rmnet_ll_ipa3_ctx + 56);
  v2 = *(unsigned __int8 *)(rmnet_ll_ipa3_ctx + 60);
  if ( (v1 & 0xFFFFFFFE) != 2 && v2 == 0 )
  {
    printk(&unk_3E21D8, "ipa3_teardown_apps_low_lat_data_pipes");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(
          v12,
          "ipa %s:%d rmnet_ll in bad state %d\n",
          "ipa3_teardown_apps_low_lat_data_pipes",
          593,
          *(_DWORD *)(rmnet_ll_ipa3_ctx + 56));
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
      {
        ipc_log_string(
          v13,
          "ipa %s:%d rmnet_ll in bad state %d\n",
          "ipa3_teardown_apps_low_lat_data_pipes",
          593,
          *(_DWORD *)(rmnet_ll_ipa3_ctx + 56));
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  if ( v1 != 3 && v2 != 2 )
    goto LABEL_14;
  v5 = *(void (__fastcall **)(_QWORD))(rmnet_ll_ipa3_ctx + 600);
  if ( !v5 )
  {
    printk(&unk_3ADC65, "ipa3_teardown_apps_low_lat_data_pipes");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Invalid stop_cb\n", "ipa3_teardown_apps_low_lat_data_pipes", 602);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
      {
        ipc_log_string(v16, "ipa %s:%d Invalid stop_cb\n", "ipa3_teardown_apps_low_lat_data_pipes", 602);
        return 4294967282LL;
      }
    }
    return 4294967282LL;
  }
  v6 = *(_QWORD *)(rmnet_ll_ipa3_ctx + 624);
  if ( *((_DWORD *)v5 - 1) != 251140989 )
    __break(0x8229u);
  v5(v6);
  v0 = rmnet_ll_ipa3_ctx;
  *(_DWORD *)(rmnet_ll_ipa3_ctx + 56) = *(_DWORD *)(rmnet_ll_ipa3_ctx + 56) != 2;
LABEL_14:
  if ( (*(_BYTE *)(v0 + 60) & 2) == 0 )
  {
    result = 0;
    if ( (*(_BYTE *)(v0 + 60) & 1) == 0 )
      return result;
LABEL_19:
    result = ipa_teardown_sys_pipe(*(_DWORD *)(v0 + 576));
    if ( (result & 0x80000000) == 0 )
    {
      v9 = rmnet_ll_ipa3_ctx;
      v10 = *(_BYTE *)(rmnet_ll_ipa3_ctx + 60);
      *(_DWORD *)(rmnet_ll_ipa3_ctx + 576) = -1;
      *(_BYTE *)(v9 + 60) = v10 & 0xFE;
    }
    return result;
  }
  result = ipa_teardown_sys_pipe(*(_DWORD *)(v0 + 580));
  if ( (result & 0x80000000) == 0 )
  {
    v0 = rmnet_ll_ipa3_ctx;
    v8 = *(_BYTE *)(rmnet_ll_ipa3_ctx + 60);
    *(_DWORD *)(rmnet_ll_ipa3_ctx + 580) = -1;
    v8 &= ~2u;
    *(_BYTE *)(v0 + 60) = v8;
    if ( (v8 & 1) == 0 )
      return result;
    goto LABEL_19;
  }
  v17 = result;
  printk(&unk_3B960C, "ipa3_teardown_apps_low_lat_data_pipes");
  v18 = ipa3_ctx;
  if ( !ipa3_ctx )
    return v17;
  v19 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v19 )
  {
    ipc_log_string(
      v19,
      "ipa %s:%d Failed to teardown APPS->IPA low lat data pipe\n",
      "ipa3_teardown_apps_low_lat_data_pipes",
      614);
    v18 = ipa3_ctx;
  }
  v20 = *(_QWORD *)(v18 + 34160);
  if ( !v20 )
    return v17;
  ipc_log_string(
    v20,
    "ipa %s:%d Failed to teardown APPS->IPA low lat data pipe\n",
    "ipa3_teardown_apps_low_lat_data_pipes",
    614);
  return v17;
}
