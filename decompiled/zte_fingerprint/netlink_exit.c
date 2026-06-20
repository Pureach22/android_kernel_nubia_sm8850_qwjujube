__int64 netlink_exit()
{
  if ( nl_sk )
  {
    netlink_kernel_release();
    nl_sk = 0;
  }
  return printk(&unk_932D);
}
