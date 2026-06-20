__int64 __fastcall sde_hw_wb_program_cwb_ctrl(__int64 result, int a2, int a3, char a4, char a5)
{
  unsigned int v5; // w19
  __int64 v6; // x20
  __int64 v8; // x0
  unsigned int v9; // w1
  unsigned int v10; // w2

  if ( result )
  {
    v5 = *(_DWORD *)(*(_QWORD *)(result + 32) + 19888LL) * (a2 - 1);
    v6 = result;
    if ( (a5 & 1) != 0 )
    {
      sde_reg_write(result + 600, v5, a3 - 1, "blk_base + CWB_CTRL_SRC_SEL");
      v8 = v6 + 600;
      v9 = v5 + 4;
      v10 = a4 & 1;
    }
    else
    {
      sde_reg_write(result + 600, v5, 0xFu, "blk_base + CWB_CTRL_SRC_SEL");
      v8 = v6 + 600;
      v9 = v5 + 4;
      v10 = 0;
    }
    return sde_reg_write(v8, v9, v10, "blk_base + CWB_CTRL_MODE");
  }
  return result;
}
