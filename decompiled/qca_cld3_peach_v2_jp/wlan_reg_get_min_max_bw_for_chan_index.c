__int64 __fastcall wlan_reg_get_min_max_bw_for_chan_index(
        __int64 a1,
        unsigned int a2,
        _WORD *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  return reg_get_min_max_bw_on_cur_chan_list(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}
