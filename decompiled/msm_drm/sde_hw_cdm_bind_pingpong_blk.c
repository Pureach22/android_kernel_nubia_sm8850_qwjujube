__int64 __fastcall sde_hw_cdm_bind_pingpong_blk(__int64 result, char a2, int a3)
{
  __int64 v3; // x2

  if ( result && ((unsigned int)(a3 - 14) > 0xFFFFFFF2 || (a2 & 1) == 0) )
  {
    if ( (a2 & 1) != 0 )
      v3 = ((_BYTE)a3 - 1) & 7;
    else
      v3 = 15;
    return sde_reg_write(result, 548, v3, "CDM_MUX");
  }
  return result;
}
