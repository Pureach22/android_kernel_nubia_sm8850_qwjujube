__int64 __fastcall hal_rx_msdu_start_msdu_len_get_be(__int64 a1)
{
  return *(_DWORD *)(a1 + 40) & 0x3FFF;
}
