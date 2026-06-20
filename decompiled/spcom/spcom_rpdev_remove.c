__int64 __fastcall spcom_rpdev_remove(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  __int64 v5; // x19
  __int64 v6; // x2
  __int64 v7; // x2
  __int64 i; // x20
  unsigned int v15; // w9
  unsigned int v16; // w9

  if ( a1 )
  {
    dev_info();
    v5 = *(_QWORD *)(a1 + 152);
    if ( v5 )
    {
      mutex_lock(v5 + 32);
      if ( !strcmp((const char *)v5, "sp_kernel") )
      {
        for ( i = 0; i != 1440; i += 40 )
        {
          if ( *(_QWORD *)(v5 + i + 352) )
            spcom_dmabuf_unlock(v5 + i + 344, 0, v6);
        }
      }
      *(_QWORD *)(v5 + 160) = 0;
      *(_BYTE *)(v5 + 316) = 1;
      *(_DWORD *)(v5 + 80) = 0;
      complete_all(v5 + 168);
      result = mutex_unlock(v5 + 32);
      _X8 = (unsigned int *)(spcom_dev + 58424);
      __asm { PRFM            #0x11, [X8] }
      do
      {
        v15 = __ldxr(_X8);
        v16 = v15 - 1;
      }
      while ( __stlxr(v16, _X8) );
      __dmb(0xBu);
      if ( !v16 )
      {
        printk(&unk_10D60, "spcom_rpdev_remove", v7);
        ipc_log_string(
          spcom_ipc_log_context,
          "%sspcom:%s: Signal link down\n",
          "spcom_rpdev_remove",
          (const char *)&unk_F80E);
        return complete_all(spcom_dev + 58392);
      }
    }
    else
    {
      printk(&unk_E89A, "spcom_rpdev_remove", a1 + 912);
      return ipc_log_string(
               spcom_ipc_log_context,
               "%sspcom:%s: channel %s not found\n",
               "spcom_rpdev_remove",
               (const char *)&unk_F80E,
               (const char *)(a1 + 912));
    }
  }
  else
  {
    printk(&unk_ED45, "spcom_rpdev_remove", a3);
    return ipc_log_string(
             spcom_ipc_log_context,
             "%sspcom:%s: rpdev is NULL\n",
             "spcom_rpdev_remove",
             (const char *)&unk_F80E);
  }
  return result;
}
