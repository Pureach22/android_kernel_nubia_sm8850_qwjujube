__int64 __fastcall ipa_pm_add_dummy_clients(unsigned __int8 a1)
{
  __int64 v1; // x1
  unsigned int v2; // w19
  unsigned int v3; // w0
  unsigned int v4; // w0
  __int64 v5; // x2
  __int64 v6; // x3
  __int64 v7; // x4
  __int64 v8; // x5
  __int64 v9; // x6
  __int64 v10; // x7
  unsigned int v11; // w0
  unsigned int v12; // w0
  unsigned int v13; // w0
  __int64 result; // x0
  unsigned int v15; // w19
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int v19; // w19
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x0
  unsigned int v23; // w19
  __int64 v24; // x8
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w19
  __int64 v28; // x8
  __int64 v29; // x0
  __int64 v30; // x0
  _QWORD v31[4]; // [xsp+0h] [xbp-50h] BYREF
  _QWORD v32[4]; // [xsp+20h] [xbp-30h] BYREF
  _QWORD v33[2]; // [xsp+40h] [xbp-10h] BYREF

  v1 = (unsigned int)(char)a1;
  v33[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33[0] = 0;
  v32[0] = "DummyModem";
  v32[1] = 0;
  v32[2] = 0;
  v32[3] = 2;
  v31[0] = "DummyApps";
  v31[1] = 0;
  v31[2] = 0;
  v31[3] = 1;
  if ( (a1 & 0x80) != 0 || *(_DWORD *)(ipa_pm_ctx + 1112) < (int)v1 )
  {
    printk(&unk_3F577D, v1);
LABEL_35:
    result = 4294967282LL;
    goto LABEL_36;
  }
  if ( a1 )
    v2 = *(_DWORD *)(*(_QWORD *)(ipa_pm_ctx + 1144) + 4LL * a1 - 4);
  else
    v2 = 0;
  v3 = ipa_pm_register((__int64)v32, (unsigned int *)v33 + 1);
  if ( v3 )
  {
    printk(&unk_3D5DE5, v3);
    goto LABEL_35;
  }
  v4 = ipa_pm_register((__int64)v31, (unsigned int *)v33);
  if ( v4 )
  {
    printk(&unk_3A7187, v4);
    goto LABEL_35;
  }
  dummy_hdl_1 = HIDWORD(v33[0]);
  dummy_hdl_2 = v33[0];
  tput_modem = *(_DWORD *)(ipa_pm_ctx + 1212);
  tput_apps = *(_DWORD *)(ipa_pm_ctx + 1208);
  v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, __int64, __int64, __int64, __int64, __int64))ipa_pm_set_throughput)(
          HIDWORD(v33[0]),
          v2,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10);
  if ( v11 )
  {
    v19 = v11;
    printk(&unk_3E9D15, "ipa_pm_add_dummy_clients");
    v20 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v21 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v21 )
      {
        ipc_log_string(v21, "ipa %s:%d fail to set tput for client 1 rc = %d\n", "ipa_pm_add_dummy_clients", 1651, v19);
        v20 = ipa3_ctx;
      }
      v22 = *(_QWORD *)(v20 + 34160);
      if ( v22 )
        ipc_log_string(v22, "ipa %s:%d fail to set tput for client 1 rc = %d\n", "ipa_pm_add_dummy_clients", 1651, v19);
    }
    goto LABEL_35;
  }
  v12 = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)((unsigned int)dummy_hdl_2, v2);
  if ( v12 )
  {
    v23 = v12;
    printk(&unk_3E69EA, "ipa_pm_add_dummy_clients");
    v24 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v25 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v25 )
      {
        ipc_log_string(v25, "ipa %s:%d fail to set tput for client 2 rc = %d\n", "ipa_pm_add_dummy_clients", 1657, v23);
        v24 = ipa3_ctx;
      }
      v26 = *(_QWORD *)(v24 + 34160);
      if ( v26 )
        ipc_log_string(v26, "ipa %s:%d fail to set tput for client 2 rc = %d\n", "ipa_pm_add_dummy_clients", 1657, v23);
    }
    goto LABEL_35;
  }
  v13 = ipa_pm_activate_sync(dummy_hdl_1);
  if ( v13 )
  {
    v27 = v13;
    printk(&unk_3F27FF, "ipa_pm_add_dummy_clients");
    v28 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v29 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d fail to activate sync for client 1 rc = %d\n",
          "ipa_pm_add_dummy_clients",
          1663,
          v27);
        v28 = ipa3_ctx;
      }
      v30 = *(_QWORD *)(v28 + 34160);
      if ( v30 )
        ipc_log_string(
          v30,
          "ipa %s:%d fail to activate sync for client 1 rc = %d\n",
          "ipa_pm_add_dummy_clients",
          1663,
          v27);
    }
    goto LABEL_35;
  }
  result = ipa_pm_activate_sync(dummy_hdl_2);
  if ( (_DWORD)result )
  {
    v15 = result;
    printk(&unk_3E6A1D, "ipa_pm_add_dummy_clients");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(
          v17,
          "ipa %s:%d fail to activate sync for client 2 rc = %d\n",
          "ipa_pm_add_dummy_clients",
          1669,
          v15);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(
          v18,
          "ipa %s:%d fail to activate sync for client 2 rc = %d\n",
          "ipa_pm_add_dummy_clients",
          1669,
          v15);
    }
    goto LABEL_35;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}
