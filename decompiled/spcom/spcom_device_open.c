__int64 __fastcall spcom_device_open(__int64 a1, __int64 a2, __int64 a3)
{
  const char *v4; // x21
  __int64 v5; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v7; // x23
  unsigned int v8; // w19
  __int64 v9; // x2
  __int64 v10; // x2
  __int64 v11; // x22
  unsigned int v13; // w0
  int v14; // w8
  int v15; // w9
  int v16; // w10
  int v17; // w11
  int v18; // w12
  unsigned int v19; // w14
  __int64 v20; // x8
  __int64 v21; // x0
  __int64 v22; // x10
  int v23; // w5
  _DWORD *v24; // x11
  int v25; // w12
  bool v26; // nf
  unsigned int *v27; // x8
  unsigned int v28; // w19
  __int64 v29; // x2

  v4 = "unknown";
  if ( a2 )
  {
    v5 = *(_QWORD *)(a2 + 72);
    if ( v5 )
      v4 = (const char *)(v5 + 56);
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v7 = spcom_dev;
  v8 = *(_DWORD *)(StatusReg + 1804);
  if ( *(_DWORD *)(spcom_dev + 58428) )
  {
    printk(&unk_1146C, "spcom_device_open", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: module remove in progress\n",
      "spcom_device_open",
      (const char *)&unk_F80E);
    return 4294967277LL;
  }
  if ( !strcmp(v4, "unknown") )
  {
    printk(&unk_118C7, "spcom_device_open", v9);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: name is unknown\n", "spcom_device_open", &unk_F80E);
    return 4294967274LL;
  }
  if ( !strcmp(v4, "sp_ssr") )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: sp_ssr dev node skipped\n",
      "spcom_device_open",
      (const char *)&unk_F80E);
    return 0;
  }
  if ( !v8 )
  {
    printk(&unk_10736, "spcom_device_open", v10);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: unknown PID\n", "spcom_device_open", &unk_F80E);
    return 4294967274LL;
  }
  if ( !strcmp(v4, "spcom") )
  {
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: control channel is opened by pid %u\n",
      "spcom_device_open",
      (const char *)&unk_F80E,
      v8);
    v21 = mutex_lock(spcom_dev + 58344);
    v22 = 0;
    v23 = -1;
    v24 = (_DWORD *)(spcom_dev + 58484);
    do
    {
      v25 = *(v24 - 1);
      if ( v25 == v8 )
      {
        ++*v24;
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Control channel for pid %u already exists, ref_cnt=%u\n",
          "spom_control_channel_add_client",
          &unk_F80E,
          v8);
        goto LABEL_42;
      }
      v24 += 2;
      if ( v25 )
        v26 = 0;
      else
        v26 = v23 < 0;
      if ( v26 )
        v23 = v22;
      ++v22;
    }
    while ( v22 != 32 );
    if ( v23 < 0 )
    {
      mutex_unlock(spcom_dev + 58344);
      printk(&unk_1236E, "spom_control_channel_add_client", v29);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: Too many open control channels\n",
        "spom_control_channel_add_client",
        (const char *)&unk_F80E);
      return 4294967272LL;
    }
    else
    {
      if ( (unsigned int)v23 <= 0x20 )
      {
        v27 = (unsigned int *)(spcom_dev + 58480 + 8LL * (unsigned int)v23);
        *v27 = v8;
        v27[1] = 1;
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Add pid %u at index %u\n",
          "spom_control_channel_add_client",
          &unk_F80E,
          v8);
LABEL_42:
        mutex_unlock(spcom_dev + 58344);
        return 0;
      }
      __break(0x5512u);
      return spcom_device_release(v21);
    }
  }
  else
  {
    v11 = 32;
    while ( strcmp((const char *)(v7 + 1200), v4) )
    {
      --v11;
      v7 += 1784;
      if ( !v11 )
        goto LABEL_47;
    }
    if ( v7 == -1200 )
    {
LABEL_47:
      printk(&unk_10272, "spcom_device_open", v4);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: ch[%s] doesn't exist, load app first\n",
        "spcom_device_open",
        (const char *)&unk_F80E,
        v4);
      return 4294967277LL;
    }
    mutex_lock(v7 + 1232);
    if ( *(_QWORD *)(v7 + 1352)
      || (*(_DWORD *)(v7 + 1400) = 0, v13 = spcom_register_rpmsg_drv(v7 + 1200), (v13 & 0x80000000) == 0) )
    {
      if ( (*(_BYTE *)(v7 + 1432) & 1) != 0 )
      {
        printk(&unk_120DA, "spcom_device_open", v4);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: channel [%s] is BUSY and has %d of clients, already in use\n",
          "spcom_device_open",
          (const char *)&unk_F80E,
          v4,
          *(unsigned __int8 *)(v7 + 1444));
        mutex_unlock(v7 + 1232);
        return 4294967280LL;
      }
      v14 = *(_DWORD *)(v7 + 1496);
      if ( v14 == v8
        || (v15 = *(_DWORD *)(v7 + 1500), v15 == v8)
        || (v16 = *(_DWORD *)(v7 + 1504), v16 == v8)
        || (v17 = *(_DWORD *)(v7 + 1508), v17 == v8)
        || (v18 = *(_DWORD *)(v7 + 1512), v18 == v8) )
      {
        printk(&unk_12F2E, "spcom_device_open", v8);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: client with pid [%d] is already registered with channel[%s]\n",
          "spcom_device_open",
          (const char *)&unk_F80E,
          v8,
          v4);
        mutex_unlock(v7 + 1232);
        return 4294967274LL;
      }
      if ( (*(_BYTE *)(v7 + 1433) & 1) != 0 )
      {
        v19 = (unsigned __int8)++*(_BYTE *)(v7 + 1444);
        *(_BYTE *)(v7 + 1432) = v19 > 4;
        if ( !v14 )
        {
          v20 = 0;
          goto LABEL_55;
        }
        if ( !v15 )
        {
          v20 = 1;
          goto LABEL_55;
        }
        if ( !v16 )
        {
          v20 = 2;
          goto LABEL_55;
        }
        if ( !v17 )
        {
          v20 = 3;
          goto LABEL_55;
        }
        if ( !v18 )
        {
          v20 = 4;
LABEL_55:
          *(_DWORD *)(v7 + 4 * v20 + 1496) = v8;
        }
      }
      else
      {
        *(_DWORD *)(v7 + 1496) = v8;
        *(_BYTE *)(v7 + 1444) = 1;
        *(_BYTE *)(v7 + 1432) = 1;
      }
      mutex_unlock(v7 + 1232);
      *(_QWORD *)(a2 + 32) = v7 + 1200;
      return 0;
    }
    v28 = v13;
    printk(&unk_11C2C, "spcom_device_open", v13);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: register rpmsg driver failed %d\n",
      "spcom_device_open",
      (const char *)&unk_F80E,
      v28);
    mutex_unlock(v7 + 1232);
    return v28;
  }
}
