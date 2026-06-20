__int64 __fastcall hal_rx_msdu_flow_idx_get_be(__int64 a1)
{
  return (*(_QWORD *)(a1 + 20) >> 38) & 0xFFFFFLL;
}
