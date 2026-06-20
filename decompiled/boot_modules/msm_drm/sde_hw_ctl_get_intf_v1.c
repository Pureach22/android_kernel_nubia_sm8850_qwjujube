__int64 __fastcall sde_hw_ctl_get_intf_v1(__int64 a1)
{
  if ( a1 )
    return sde_reg_read(a1, 244);
  printk(&unk_24D5AE, "sde_hw_ctl_get_intf_v1");
  return 0;
}
