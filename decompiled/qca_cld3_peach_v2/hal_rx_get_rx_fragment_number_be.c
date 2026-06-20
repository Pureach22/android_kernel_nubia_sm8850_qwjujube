__int64 __fastcall hal_rx_get_rx_fragment_number_be(__int64 a1)
{
  return (*(_DWORD *)(a1 + 80) >> 20) & 0xF;
}
