__int64 __fastcall hal_rx_get_fc_valid_be(__int64 a1)
{
  return *(_BYTE *)(a1 + 80) & 1;
}
