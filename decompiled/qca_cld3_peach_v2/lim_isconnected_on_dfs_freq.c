__int64 __fastcall lim_isconnected_on_dfs_freq(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  return wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), a2, a3, a4, a5, a6, a7, a8, a9, a10) & 1;
}
