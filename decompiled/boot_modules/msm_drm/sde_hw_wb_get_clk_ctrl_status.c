__int64 __fastcall sde_hw_wb_get_clk_ctrl_status(__int64 a1, int a2, _BYTE *a3)
{
  __int64 result; // x0
  char v6; // w8

  result = 4294967274LL;
  if ( a1 )
  {
    if ( (unsigned int)(a2 - 15) <= 2 )
    {
      v6 = sde_reg_read(a1, 0x17Cu);
      *a3 = v6 & 1;
      return 0;
    }
  }
  return result;
}
