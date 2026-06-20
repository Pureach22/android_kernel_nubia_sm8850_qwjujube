__int64 __fastcall sub_29A7C8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  atomic_ushort *v8; // x19

  atomic_exchange_explicit(v8, a8, memory_order_acquire);
  return wlan_mlme_get_sap_chn_switch_bcn_count(a1, a2, a3, a4, a5, a6, a7, a8);
}
