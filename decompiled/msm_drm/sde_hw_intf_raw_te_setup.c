__int64 __fastcall sde_hw_intf_raw_te_setup(__int64 result, char a2)
{
  __int64 v2; // x2

  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v2 = 2;
    else
      v2 = 0;
    return sde_reg_write(result, 208, v2, "INTF_RSCC_PANIC_CTRL");
  }
  return result;
}
