__int64 __fastcall populate_dot11f_he_bss_color_change(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  if ( a2[9776] )
  {
    *a3 = 1;
    a3[1] = a2[8766];
    a3[2] = a3[2] & 0xC0 | a2[8767] & 0x3F;
    lim_log_he_bss_color(a4, a5, a6, a7, a8, a9, a10, a11, a1, (__int64)a3);
    return 0;
  }
  else
  {
    *a3 = 0;
    return 0;
  }
}
