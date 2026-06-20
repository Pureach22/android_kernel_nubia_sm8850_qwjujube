__int64 __fastcall wlan_reg_get_keep_6ghz_sta_cli_connection(
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
  return reg_get_keep_6ghz_sta_cli_connection(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1;
}
