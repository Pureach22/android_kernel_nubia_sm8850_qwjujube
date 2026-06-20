_DWORD *__fastcall dsi_phy_hw_v4_0_calc_hs_trail(_DWORD *result, _DWORD *a2)
{
  int v2; // w11

  v2 = a2[31];
  a2[32] = (8 * result[3] + *result * a2[30] - 1) / (unsigned int)(8 * result[3]) - 1;
  a2[33] = (unsigned int)(*result * v2) / (__int64)(8 * result[3]) - 1;
  return result;
}
