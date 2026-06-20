__int64 __fastcall sde_hw_ctl_setup_flush_sync(__int64 result, char a2, char a3)
{
  int v3; // w8
  int v4; // w9

  if ( result )
  {
    if ( (a3 & 1) != 0 )
      v3 = 5;
    else
      v3 = 0;
    if ( (a2 & 1) != 0 )
      v4 = 0;
    else
      v4 = 2;
    return sde_reg_write(result, 2560, v3 | (unsigned int)v4, "CTL_FLUSH_SYNC");
  }
  return result;
}
