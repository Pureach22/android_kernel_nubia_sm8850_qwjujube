__int64 __fastcall hal_rx_tlv_msdu_done_get_be(__int64 a1)
{
  return *(_DWORD *)(a1 + 60) >> 31;
}
