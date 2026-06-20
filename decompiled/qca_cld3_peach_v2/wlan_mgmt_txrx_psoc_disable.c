__int64 __fastcall wlan_mgmt_txrx_psoc_disable(
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
  return tgt_mgmt_txrx_unregister_ev_handler(a1, a2, a3, a4, a5, a6, a7, a8, a9);
}
