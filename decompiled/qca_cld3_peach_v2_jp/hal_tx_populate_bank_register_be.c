__int64 __fastcall hal_tx_populate_bank_register_be(__int64 a1, _DWORD *a2, unsigned __int8 a3)
{
  return hal_write32_mb_1(a1, 4 * (unsigned int)a3 + 10764428, *a2 & 0x1FFFF | (((*a2 >> 19) & 0x3Fu) << 17));
}
