__int64 __fastcall uaudio_disconnect(__int64 a1)
{
  __int64 v1; // x27
  int v3; // w20
  _QWORD *v4; // x20
  __int64 result; // x0
  const char *v6; // x19
  __int64 v7; // x8
  int v8; // w9
  int v9; // w0
  __int64 v10; // x0
  __int64 v11; // x21
  int v12; // w8
  bool v13; // zf
  _QWORD v14[5]; // [xsp+0h] [xbp-F0h] BYREF
  _QWORD v15[23]; // [xsp+28h] [xbp-C8h] BYREF
  __int64 v16; // [xsp+E0h] [xbp-10h]
  __int64 v17; // [xsp+E8h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = uaudio_svc;
  v16 = 0;
  memset(v15, 0, sizeof(v15));
  if ( !a1 )
  {
    v6 = "%s%s: chip is NULL\n";
    ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: chip is NULL\n", &unk_B13E, "uaudio_disconnect");
LABEL_12:
    result = printk(v6, &unk_B45D);
    goto LABEL_9;
  }
  v3 = **(_DWORD **)(a1 + 16);
  if ( v3 >= 32 )
  {
    v6 = "%s%s: invalid card number\n";
    ipc_log_string(*(_QWORD *)(uaudio_svc + 24), "%s%s: invalid card number\n", &unk_B13E, "uaudio_disconnect");
    goto LABEL_12;
  }
  mutex_lock(a1 + 160);
  if ( (unsigned int)v3 >= 0x21 )
  {
    __break(0x5512u);
    JUMPOUT(0xA9B4);
  }
  v4 = &uadev[11 * (unsigned int)v3];
  if ( !*v4 )
  {
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: no clean up required\n",
      (const char *)&unk_B13E,
      "uaudio_disconnect");
    printk("%s%s: no clean up required\n", &unk_B8A7);
    if ( !v4[7] )
      goto LABEL_8;
    goto LABEL_7;
  }
  if ( *((_DWORD *)v4 + 6) )
  {
    mutex_unlock(a1 + 160);
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: sending qmi indication disconnect\n",
      (const char *)&unk_B13E,
      "uaudio_disconnect");
    printk("%s%s: sending qmi indication disconnect\n", &unk_B8A7);
    ipc_log_string(
      *(_QWORD *)(uaudio_svc + 24),
      "%s%s: sq->sq_family:%x sq->sq_node:%x sq->sq_port:%x\n",
      (const char *)&unk_B13E,
      "uaudio_disconnect",
      *(unsigned __int16 *)(v1 + 8),
      *(_DWORD *)(v1 + 12),
      *(_DWORD *)(v1 + 16));
    printk("%s%s: sq->sq_family:%x sq->sq_node:%x sq->sq_port:%x\n", &unk_B8A7);
    v7 = *v4;
    v8 = *((_DWORD *)v4 + 5);
    BYTE2(v16) = 1;
    LODWORD(v7) = *(_DWORD *)(v7 + 1488);
    BYTE3(v16) = v8;
    LODWORD(v15[0]) = 1;
    HIDWORD(v15[0]) = v7;
    v9 = qmi_send_indication(*(_QWORD *)v1, v1 + 8, 1, 181, &qmi_uaudio_stream_ind_msg_v01_ei, v15);
    if ( v9 < 0 )
    {
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: qmi send failed with err: %d\n",
        (const char *)&unk_B13E,
        "uaudio_disconnect",
        v9);
      printk("%s%s: qmi send failed with err: %d\n", &unk_B45D);
      if ( !*((_DWORD *)v4 + 6) )
        goto LABEL_33;
    }
    else if ( !*((_DWORD *)v4 + 6) )
    {
LABEL_33:
      mutex_lock(a1 + 160);
      goto LABEL_6;
    }
    memset(v14, 0, sizeof(v14));
    init_wait_entry(v14, 0);
    v10 = prepare_to_wait_event(v4 + 4, v14, 1);
    if ( *((_DWORD *)v4 + 6) )
    {
      v11 = 2500;
      while ( !v10 )
      {
        v11 = schedule_timeout(v11);
        v10 = prepare_to_wait_event(v4 + 4, v14, 1);
        v12 = *((_DWORD *)v4 + 6);
        if ( v11 )
          v13 = 0;
        else
          v13 = v12 == 0;
        if ( v13 )
          v11 = 1;
        if ( !v12 || !v11 )
          goto LABEL_30;
      }
    }
    else
    {
      LODWORD(v11) = 2500;
LABEL_30:
      finish_wait(v4 + 4, v14);
      LODWORD(v10) = v11;
    }
    if ( (_DWORD)v10 )
    {
      if ( (v10 & 0x80000000) == 0 )
        goto LABEL_33;
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: failed with ret %d\n",
        (const char *)&unk_B13E,
        "uaudio_disconnect",
        v10);
      printk("%s%s: failed with ret %d\n", &unk_B45D);
    }
    else
    {
      ipc_log_string(
        *(_QWORD *)(uaudio_svc + 24),
        "%s%s: timeout while waiting for dev_release\n",
        (const char *)&unk_B13E,
        "uaudio_disconnect");
      printk("%s%s: timeout while waiting for dev_release\n", &unk_B45D);
    }
    *((_DWORD *)v4 + 6) = 0;
    goto LABEL_33;
  }
LABEL_6:
  uaudio_dev_cleanup((__int64)v4);
  if ( v4[7] )
LABEL_7:
    xhci_sideband_unregister();
LABEL_8:
  v4[10] = 0;
  v4[7] = 0;
  result = mutex_unlock(a1 + 160);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
