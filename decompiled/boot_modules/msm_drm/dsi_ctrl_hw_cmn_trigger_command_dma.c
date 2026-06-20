__int64 __fastcall dsi_ctrl_hw_cmn_trigger_command_dma(__int64 a1)
{
  return writel_relaxed_16(1u, (unsigned int *)(*(_QWORD *)a1 + 144LL));
}
