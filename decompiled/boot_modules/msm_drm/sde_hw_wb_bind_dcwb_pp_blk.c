__int64 __fastcall sde_hw_wb_bind_dcwb_pp_blk(__int64 result, char a2, unsigned int a3)
{
  int v3; // w8
  unsigned int v4; // w2

  if ( result )
  {
    if ( a3 >= 0xB )
      v3 = 11;
    else
      v3 = 13;
    if ( (a2 & 1) != 0 )
      v4 = v3;
    else
      v4 = 15;
    return sde_reg_write(result, 0x150u, v4, "WB_MUX");
  }
  return result;
}
