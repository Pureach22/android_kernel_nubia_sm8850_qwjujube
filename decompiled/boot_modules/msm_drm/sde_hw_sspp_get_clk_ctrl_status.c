__int64 __fastcall sde_hw_sspp_get_clk_ctrl_status(__int64 a1, int a2, _BYTE *a3)
{
  __int64 result; // x0
  char v6; // w8

  result = 4294967274LL;
  if ( a1 )
  {
    if ( (unsigned int)(a2 - 1) <= 0xD )
    {
      v6 = sde_reg_read(a1, 0x334u);
      *a3 = v6 & 1;
      return 0;
    }
  }
  return result;
}
