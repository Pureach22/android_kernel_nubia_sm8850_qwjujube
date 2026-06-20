__int64 rmnet_ctl_remove()
{
  __int64 v0; // x1
  __int64 v1; // x2

  rmnet_ctl_endpoint_setdev(0);
  return printk(&unk_6A1C, v0, v1);
}
