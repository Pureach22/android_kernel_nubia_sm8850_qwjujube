unsigned __int64 __fastcall sde_hw_ctl_read_active_status(__int64 a1, int a2, char a3)
{
  __int64 v3; // x1

  if ( !a1 )
  {
    printk(&unk_24D5AE, "sde_hw_ctl_read_active_status");
    return 0;
  }
  if ( a2 <= 8 )
  {
    if ( a2 == 6 )
    {
      v3 = 248;
      return ((unsigned __int64)(int)sde_reg_read(a1, v3) >> (a3 - 1)) & 1;
    }
    if ( a2 == 8 )
    {
      v3 = 244;
      return ((unsigned __int64)(int)sde_reg_read(a1, v3) >> (a3 - 1)) & 1;
    }
    goto LABEL_17;
  }
  if ( a2 == 9 )
  {
    v3 = 236;
    return ((unsigned __int64)(int)sde_reg_read(a1, v3) >> (a3 - 1)) & 1;
  }
  if ( a2 == 10 )
  {
    v3 = 232;
    return ((unsigned __int64)(int)sde_reg_read(a1, v3) >> (a3 - 1)) & 1;
  }
  if ( a2 != 12 )
  {
LABEL_17:
    printk(&unk_24D5D4, "sde_hw_ctl_read_active_status");
    return 0;
  }
  v3 = 228;
  return ((unsigned __int64)(int)sde_reg_read(a1, v3) >> (a3 - 1)) & 1;
}
