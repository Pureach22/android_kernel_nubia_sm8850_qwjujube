__int64 __fastcall sde_hw_ctl_read_ctl_layers(__int64 a1, int a2)
{
  __int64 v2; // x1

  if ( a1 )
  {
    if ( a2 == 6 )
      v2 = 36;
    else
      v2 = (unsigned int)(4 * a2 - 4);
    return sde_reg_read(a1, v2);
  }
  else
  {
    printk(&unk_24D5AE, "sde_hw_ctl_read_ctl_layers");
    return 0;
  }
}
