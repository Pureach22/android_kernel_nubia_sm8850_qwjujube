__int64 __fastcall hal_rx_phy_legacy_get_rssi_be(__int64 a1)
{
  return *(_QWORD *)(a1 + 160) >> 8;
}
