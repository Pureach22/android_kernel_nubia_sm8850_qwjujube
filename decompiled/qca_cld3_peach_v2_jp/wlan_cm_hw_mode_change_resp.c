__int64 __fastcall wlan_cm_hw_mode_change_resp(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  if ( (~a3 & 0xF000000) != 0 )
    return cm_hw_mode_change_resp(result, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
  return result;
}
