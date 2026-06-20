bool __fastcall wlan_reg_phybitmap_support_11be(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  return (unsigned int)reg_get_max_phymode(a1, 7u, 0, a2, a3, a4, a5, a6, a7, a8, a9) == 7;
}
