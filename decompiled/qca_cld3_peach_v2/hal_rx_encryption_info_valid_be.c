__int64 __fastcall hal_rx_encryption_info_valid_be(__int64 a1)
{
  return (*(_DWORD *)(a1 + 80) >> 9) & 1;
}
