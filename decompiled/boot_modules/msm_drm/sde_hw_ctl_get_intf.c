__int64 __fastcall sde_hw_ctl_get_intf(__int64 a1)
{
  int v1; // w0

  if ( a1 )
  {
    v1 = sde_reg_read(a1, 20);
    if ( v1 )
      return (unsigned int)(1LL << ((unsigned __int8)v1 - 1));
    else
      return 0;
  }
  else
  {
    printk(&unk_24D5AE, "sde_hw_ctl_get_intf");
    return 0;
  }
}
