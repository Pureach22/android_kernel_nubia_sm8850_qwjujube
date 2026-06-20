__int64 __fastcall hal_tx_update_pcp_tid_generic_be(__int64 a1, char a2, unsigned __int8 a3)
{
  char v4; // w20
  int v5; // w21
  int v6; // w0

  v4 = 3 * a2;
  v5 = a3 << (3 * a2);
  v6 = hal_read32_mb_1(a1, 10766016);
  return hal_write32_mb_1(a1, 10766016, (v6 & ~(7 << v4) | v5) & 0xFFFFFF);
}
