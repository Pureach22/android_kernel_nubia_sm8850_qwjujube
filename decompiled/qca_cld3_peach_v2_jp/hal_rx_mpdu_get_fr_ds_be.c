__int64 __fastcall hal_rx_mpdu_get_fr_ds_be(__int64 a1)
{
  return HIWORD(*(_DWORD *)(a1 + 80)) & 1;
}
