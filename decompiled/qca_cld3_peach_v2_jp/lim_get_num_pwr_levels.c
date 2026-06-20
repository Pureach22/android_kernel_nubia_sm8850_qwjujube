__int64 __fastcall lim_get_num_pwr_levels(
        char a1,
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
  unsigned int *v10; // x8
  __int64 v12; // x20
  __int64 v13; // x20

  if ( (a1 & 1) != 0 )
  {
    if ( a2 < 8 && ((0x8Fu >> a2) & 1) != 0 )
    {
      v10 = dword_A30050;
      return v10[a2];
    }
    v12 = jiffies;
    if ( lim_get_num_pwr_levels___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x35u, 2u, "%s: Invalid channel width", a3, a4, a5, a6, a7, a8, a9, a10, "lim_get_num_pwr_levels");
      lim_get_num_pwr_levels___last_ticks = v12;
      return 0;
    }
    return 0;
  }
  if ( a2 < 8 && ((0x8Fu >> a2) & 1) != 0 )
  {
    v10 = (unsigned int *)&unk_A30290;
    return v10[a2];
  }
  v13 = jiffies;
  if ( lim_get_num_pwr_levels___last_ticks_43 - jiffies + 125 >= 0 )
    return 0;
  qdf_trace_msg(0x35u, 2u, "%s: Invalid channel width", a3, a4, a5, a6, a7, a8, a9, a10, "lim_get_num_pwr_levels");
  lim_get_num_pwr_levels___last_ticks_43 = v13;
  return 0;
}
