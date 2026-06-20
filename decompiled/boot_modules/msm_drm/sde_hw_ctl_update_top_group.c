__int64 __fastcall sde_hw_ctl_update_top_group(__int64 result, char a2)
{
  __int64 v3; // x20
  int v4; // w0
  int v5; // w2

  if ( result )
  {
    v3 = result;
    v4 = sde_reg_read(result, 20);
    if ( (a2 & 1) != 0 )
      v5 = 0;
    else
      v5 = -268435456;
    return sde_reg_write(v3, 20, v5 & 0xF0000000 | v4 & 0xFFFFFFF, "CTL_TOP");
  }
  return result;
}
