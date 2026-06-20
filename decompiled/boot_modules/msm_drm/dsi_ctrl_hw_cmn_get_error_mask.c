__int64 __fastcall dsi_ctrl_hw_cmn_get_error_mask(__int64 a1)
{
  return readl_relaxed_19((unsigned int *)(*(_QWORD *)a1 + 268LL));
}
