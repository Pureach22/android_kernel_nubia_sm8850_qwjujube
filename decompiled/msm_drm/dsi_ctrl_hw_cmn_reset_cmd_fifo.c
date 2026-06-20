__int64 __fastcall dsi_ctrl_hw_cmn_reset_cmd_fifo(__int64 a1)
{
  writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 348LL));
  writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 492LL));
  _const_udelay(4295);
  return writel_relaxed_16(0, (unsigned int *)(*(_QWORD *)a1 + 492LL));
}
