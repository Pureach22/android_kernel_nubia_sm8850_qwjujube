__int64 cleanup_module()
{
  qrtr_ns_remove();
  sock_unregister(42);
  proto_unregister(&qrtr_proto);
  cancel_work_sync(&qrtr_backup_work);
  skb_queue_purge_reason(&qrtr_backup_lo, 85);
  return skb_queue_purge_reason(&qrtr_backup_hi, 85);
}
