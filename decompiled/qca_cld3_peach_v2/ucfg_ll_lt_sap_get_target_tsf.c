__int64 __fastcall ucfg_ll_lt_sap_get_target_tsf(
        __int64 a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0

  result = wlan_ll_sap_get_target_tsf(a1, 2, a3, a4, a5, a6, a7, a8, a9, a10);
  *a2 = result;
  return result;
}
