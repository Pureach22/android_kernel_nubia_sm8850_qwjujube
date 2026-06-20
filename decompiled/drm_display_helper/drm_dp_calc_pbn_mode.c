unsigned __int64 __fastcall drm_dp_calc_pbn_mode(int a1, int a2)
{
  return ((unsigned int)((int)((unsigned int)drm_dp_bw_overhead(4, 4096, 0, a2, 5) << 6) >> 4)
        * (unsigned __int64)(unsigned int)(a2 * a1)
        + 0x649534DFFFLL)
       / 0x649534E000LL;
}
