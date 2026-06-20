__int64 __fastcall hal_rx_get_to_ds_flag_be(__int64 a1)
{
  return (*(_DWORD *)(a1 + 80) >> 17) & 1;
}
