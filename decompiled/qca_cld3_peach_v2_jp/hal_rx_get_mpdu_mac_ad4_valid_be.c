__int64 __fastcall hal_rx_get_mpdu_mac_ad4_valid_be(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 80) >> 5) & 1;
}
