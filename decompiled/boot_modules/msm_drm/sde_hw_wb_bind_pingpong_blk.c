__int64 __fastcall sde_hw_wb_bind_pingpong_blk(__int64 result, char a2, char a3)
{
  unsigned int v3; // w2

  if ( result )
  {
    if ( (a2 & 1) != 0 )
      v3 = (a3 - 1) & 7;
    else
      v3 = 15;
    return sde_reg_write(result, 0x150u, v3, "WB_MUX");
  }
  return result;
}
