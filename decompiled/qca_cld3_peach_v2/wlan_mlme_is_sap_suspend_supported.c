__int64 __fastcall wlan_mlme_is_sap_suspend_supported(
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
  return tgt_sap_is_suspend_supported(a1, a2, a3, a4, a5, a6, a7, a8, a9) & 1;
}
