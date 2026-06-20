bool __fastcall hal_rx_is_unicast_be(__int64 a1)
{
  return (*(_BYTE *)(a1 + 80) & 4) == 0 || (*(_BYTE *)(a1 + 100) & 1) == 0;
}
