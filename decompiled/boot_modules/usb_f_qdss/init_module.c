__int64 init_module()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x9
  unsigned int v2; // w19

  v0 = ipc_log_context_create(10, "usb_qdss", 0);
  if ( v0 <= 0xFFFFFFFFFFFFF000LL )
    v1 = v0;
  else
    v1 = 0;
  qdss_ipc_log = v1;
  usb_qdss_ch_list = &usb_qdss_ch_list;
  off_A8 = &usb_qdss_ch_list;
  v2 = usb_function_register(&qdssusb_func);
  if ( v2 )
    printk(&unk_829C, "usb_qdss_init");
  return v2;
}
