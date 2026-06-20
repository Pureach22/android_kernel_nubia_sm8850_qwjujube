void wcd_usbss_enable_surge_kthread()
{
  unsigned __int64 v0; // x0
  unsigned __int64 v1; // x19

  if ( *(_BYTE *)(wcd_usbss_ctxt_ + 372) == 1 && !*(_QWORD *)(wcd_usbss_ctxt_ + 384) )
  {
    v0 = kthread_create_on_node(wcd_usbss_surge_kthread_fn, 0, 0xFFFFFFFFLL, "Surge kthread");
    v1 = v0;
    if ( v0 <= 0xFFFFFFFFFFFFF000LL )
      wake_up_process(v0);
    *(_QWORD *)(wcd_usbss_ctxt_ + 384) = v1;
    if ( !v1 )
      printk(&unk_BB30);
  }
}
