__int64 __fastcall hal_tx_update_dscp_tid_peach(__int64 a1, unsigned __int8 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  char v5; // w21
  unsigned int v6; // w19
  int v7; // w22
  int v8; // w0

  v5 = 3 * (a4 % 0xAu);
  v6 = 4 * (a4 / 0xAu + a3) + 10764864;
  v7 = a2 << v5;
  v8 = hal_read32_mb_1(a1, v6);
  return hal_write32_mb_1(a1, v6, v8 & ~(7 << v5) | (unsigned int)v7);
}
