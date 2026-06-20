__int64 netlink_init()
{
  __int64 result; // x0
  _QWORD v1[6]; // [xsp+0h] [xbp-30h] BYREF

  v1[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 0;
  v1[1] = nl_data_ready;
  memset(&v1[2], 0, 24);
  nl_sk = _netlink_kernel_create(&init_net, 25, &_this_module, v1);
  if ( nl_sk )
  {
    result = 0;
  }
  else
  {
    printk(&unk_8C6F);
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
