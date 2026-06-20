__int64 __fastcall sde_hw_program_cwb_ppb_ctrl(__int64 a1, char a2, char a3)
{
  unsigned int v4; // w20
  __int64 result; // x0

  if ( (a3 & 1) != 0 )
    v4 = 4;
  else
    v4 = 0;
  result = sde_reg_write(a1, 0x370u, v4, "PPB2_CNTL");
  if ( (a2 & 1) != 0 )
    return sde_reg_write(a1, 0x374u, v4 | 1, "PPB3_CNTL");
  return result;
}
