__int64 __fastcall wlan_reg_modify_indoor_concurrency(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int a3,
        unsigned int a4,
        char a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  if ( (a5 & 1) != 0 )
    return reg_add_indoor_concurrency(a1, a2, a3, a4, a6, a7, a8, a9, a10, a11, a12, a13);
  else
    return reg_remove_indoor_concurrency(a1, a2, a3, a6, a7, a8, a9, a10, a11, a12, a13);
}
