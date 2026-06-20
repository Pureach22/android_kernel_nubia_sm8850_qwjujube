__int64 __fastcall sde_hw_wb_program_dcwb_ctrl(__int64 result, unsigned int a2, int a3, unsigned int a4, char a5)
{
  __int64 v5; // x21
  unsigned int v7; // w19
  unsigned int v8; // w2

  if ( result )
  {
    v5 = result + 32LL * (a2 > 2);
    if ( (a5 & 1) == 0 )
      a4 = 0;
    v7 = *(_DWORD *)(*(_QWORD *)(result + 32) + 19888LL) * ((a2 & 1) == 0);
    if ( (a5 & 1) != 0 )
      v8 = a3 - 1;
    else
      v8 = 15;
    sde_reg_write(v5 + 632, v7, v8, "blk_base + CWB_CTRL_SRC_SEL");
    return sde_reg_write(v5 + 632, v7 + 4, a4, "blk_base + CWB_CTRL_MODE");
  }
  return result;
}
