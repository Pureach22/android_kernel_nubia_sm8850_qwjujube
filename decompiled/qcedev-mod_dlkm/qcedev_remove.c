__int64 __fastcall qcedev_remove(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  int v3; // w8
  unsigned int v4; // w0
  __int64 v5; // x3

  v1 = *(_QWORD *)(result + 168);
  if ( !v1 )
    return result;
  qcedev_ce_high_bw_req(*(_QWORD *)(result + 168), 1);
  v2 = *(_QWORD *)(v1 + 224);
  if ( v2 )
    qce_close(v2);
  mutex_lock(&qcedev_sent_bw_req);
  v3 = *(_DWORD *)(v1 + 20);
  if ( v3 != 1 )
    goto LABEL_8;
  v4 = qce_set_irqs(*(_QWORD *)(v1 + 224), 0);
  if ( v4 )
  {
    printk(&unk_11FE7, "qcedev_ce_high_bw_req", v4, v5);
    goto LABEL_9;
  }
  if ( !(unsigned int)qcedev_control_clocks(v1, 0) )
  {
    v3 = *(_DWORD *)(v1 + 20);
LABEL_8:
    *(_DWORD *)(v1 + 20) = v3 - 1;
  }
LABEL_9:
  mutex_unlock(&qcedev_sent_bw_req);
  if ( *(_QWORD *)(v1 + 64) )
    icc_put();
  tasklet_kill(v1 + 280);
  cdev_del(v1 + 80);
  device_destroy(driver_class, (unsigned int)qcedev_device_no);
  class_destroy(driver_class);
  return unregister_chrdev_region((unsigned int)qcedev_device_no, 1);
}
