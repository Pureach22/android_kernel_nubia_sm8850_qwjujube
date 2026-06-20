__int64 __fastcall dsi_ctrl_hw_cmn_error_intr_ctrl(__int64 a1, char a2)
{
  unsigned int v4; // w8
  unsigned int v5; // w0
  __int64 result; // x0

  v4 = readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 272LL)) & 0x2022AA02;
  if ( (a2 & 1) != 0 )
    v5 = v4 | 0x3000000;
  else
    v5 = v4;
  result = writel_relaxed_16(v5, (unsigned int *)(*(_QWORD *)a1 + 272LL));
  __dsb(0xEu);
  return result;
}
