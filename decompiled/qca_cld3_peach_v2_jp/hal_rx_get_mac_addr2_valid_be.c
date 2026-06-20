__int64 __fastcall hal_rx_get_mac_addr2_valid_be(__int64 a1)
{
  return (*(unsigned __int8 *)(a1 + 80) >> 3) & 1;
}
