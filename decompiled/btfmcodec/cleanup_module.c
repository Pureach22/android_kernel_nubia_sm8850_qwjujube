__int64 cleanup_module()
{
  void *v0; // x0
  __int64 v1; // x19
  void *v2; // x0
  __int64 v3; // x19
  void *v4; // x0

  if ( (unsigned __int8)log_lvl <= 7u )
    v0 = &unk_CCBB;
  else
    v0 = &unk_CEDA;
  printk(v0, "btfmcodec_deinit");
  v1 = btfmcodec;
  if ( !btfmcodec )
  {
    v2 = &unk_CCE4;
LABEL_8:
    printk(v2, "btfmcodec_deinit");
    goto LABEL_10;
  }
  device_remove_file(btfmcodec, &dev_attr_btfmcodec_attributes);
  put_device(v1);
  v3 = *(_QWORD *)(btfmcodec + 976);
  if ( !v3 )
  {
    v2 = &unk_CB67;
    goto LABEL_8;
  }
  skb_queue_purge_reason(v3 + 320, 85);
  idr_remove(&dev_minor, *(int *)(v3 + 240));
  class_destroy(dev_class);
  unregister_chrdev_region((unsigned int)dev_major >> 20, 0);
  kfree(v3);
LABEL_10:
  kfree(btfmcodec);
  if ( (unsigned __int8)log_lvl <= 7u )
    v4 = &unk_D55A;
  else
    v4 = &unk_C90B;
  return printk(v4, "btfmcodec_deinit");
}
