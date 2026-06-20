__int64 __fastcall hal_tx_update_tidmap_prty_generic_be(__int64 a1, unsigned __int8 a2)
{
  return hal_write32_mb_1(a1, 10766056, a2 & 0xEF);
}
