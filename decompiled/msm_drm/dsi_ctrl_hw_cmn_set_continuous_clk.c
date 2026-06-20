__int64 __fastcall dsi_ctrl_hw_cmn_set_continuous_clk(__int64 a1, char a2)
{
  int v4; // w10
  int v5; // w8
  __int64 result; // x0

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 172LL)) & 0xEFFFFFFF;
  if ( (a2 & 1) != 0 )
    v5 = 0x10000000;
  else
    v5 = 0;
  result = writel_relaxed_16(v4 | (unsigned int)v5, (unsigned int *)(*(_QWORD *)a1 + 172LL));
  __dsb(0xEu);
  return result;
}
