__int64 __fastcall dsi_ctrl_hw_cmn_get_hw_version(unsigned int **a1)
{
  return readl_relaxed_19(*a1);
}
