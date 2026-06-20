__int64 __fastcall cnss_mhi_write_reg(__int64 a1, unsigned int *a2, unsigned int a3)
{
  return writel_relaxed(a3, a2);
}
