__int64 __fastcall hal_rx_desc_is_first_msdu_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 12) >> 60) & 1LL;
}
