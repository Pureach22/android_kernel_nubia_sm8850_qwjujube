__int64 __fastcall hal_rx_get_flow_agg_continuation_be(__int64 a1)
{
  return *(_BYTE *)(a1 + 37) & 1;
}
