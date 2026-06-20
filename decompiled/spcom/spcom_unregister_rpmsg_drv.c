__int64 __fastcall spcom_unregister_rpmsg_drv(__int64 a1, __int64 a2, __int64 a3)
{
  if ( *(_QWORD *)(a1 + 152) )
  {
    unregister_rpmsg_driver();
    mutex_lock(a1 + 32);
    kfree(**(_QWORD **)(a1 + 152));
    kfree(*(_QWORD *)(*(_QWORD *)(a1 + 152) + 176LL));
    kfree(*(_QWORD *)(a1 + 152));
    *(_QWORD *)(a1 + 152) = 0;
    *(_BYTE *)(a1 + 316) = 1;
    mutex_unlock(a1 + 32);
    return 0;
  }
  else
  {
    printk(&unk_11C93, "spcom_unregister_rpmsg_drv", a3);
    ipc_log_string(
      spcom_ipc_log_context,
      "%sspcom:%s: rpdev is NULL, can't unregister rpmsg drv\n",
      "spcom_unregister_rpmsg_drv",
      (const char *)&unk_F80E);
    return 4294967277LL;
  }
}
