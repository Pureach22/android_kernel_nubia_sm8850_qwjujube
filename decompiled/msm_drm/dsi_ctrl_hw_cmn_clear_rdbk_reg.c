__int64 __fastcall dsi_ctrl_hw_cmn_clear_rdbk_reg(__int64 a1)
{
  __int64 result; // x0

  writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 468LL));
  __dsb(0xEu);
  result = writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 468LL));
  __dsb(0xEu);
  return result;
}
