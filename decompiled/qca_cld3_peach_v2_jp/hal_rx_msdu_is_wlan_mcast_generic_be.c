__int64 __fastcall hal_rx_msdu_is_wlan_mcast_generic_be(__int64 a1)
{
  return (*(_QWORD *)(*(_QWORD *)(a1 + 224) + 52LL) >> 34) & 1LL;
}
