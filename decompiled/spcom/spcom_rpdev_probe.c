__int64 __fastcall spcom_rpdev_probe(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x23
  __int64 v5; // x20
  __int64 v6; // x2
  __int64 v7; // x8
  unsigned int v15; // w9

  if ( a1 )
  {
    if ( *(_DWORD *)(spcom_dev + 58428) )
    {
      printk(&unk_112AE, "spcom_rpdev_probe", a1 + 912);
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: remove in progress, ignore rpmsg probe for ch %s\n",
        "spcom_rpdev_probe",
        (const char *)&unk_F80E,
        (const char *)(a1 + 912));
    }
    else
    {
      ipc_log_string(
        spcom_ipc_log_context,
        "%sspcom:%s: new channel %s rpmsg_device arrived\n",
        "spcom_rpdev_probe",
        (const char *)&unk_F80E,
        (const char *)(a1 + 912));
      v4 = 32;
      v5 = spcom_dev + 1200;
      while ( strcmp((const char *)v5, (const char *)(a1 + 912)) )
      {
        --v4;
        v5 += 1784;
        if ( !v4 )
          goto LABEL_12;
      }
      if ( !v5 )
      {
LABEL_12:
        printk(&unk_E89A, "spcom_rpdev_probe", a1 + 912);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: channel %s not found\n",
          "spcom_rpdev_probe",
          (const char *)&unk_F80E,
          (const char *)(a1 + 912));
        return 4294967277LL;
      }
      mutex_lock(v5 + 32);
      *(_QWORD *)(v5 + 160) = a1;
      *(_BYTE *)(v5 + 316) = 0;
      *(_DWORD *)(v5 + 80) = 305419896;
      complete_all(v5 + 200);
      mutex_unlock(v5 + 32);
      v7 = spcom_dev;
      *(_QWORD *)(a1 + 152) = v5;
      _X8 = (unsigned int *)(v7 + 58424);
      __asm { PRFM            #0x11, [X8] }
      do
        v15 = __ldxr(_X8);
      while ( __stxr(v15 + 1, _X8) );
      if ( *(_DWORD *)(spcom_dev + 58424) == 1 )
      {
        printk(&unk_119EC, "spcom_rpdev_probe", v6);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Signal link up\n",
          "spcom_rpdev_probe",
          (const char *)&unk_F80E);
        complete_all(spcom_dev + 58392);
      }
    }
    return 0;
  }
  else
  {
    printk(&unk_ED45, "spcom_rpdev_probe", a3);
    ipc_log_string(spcom_ipc_log_context, "%sspcom:%s: rpdev is NULL\n", "spcom_rpdev_probe", (const char *)&unk_F80E);
    return 4294967274LL;
  }
}
