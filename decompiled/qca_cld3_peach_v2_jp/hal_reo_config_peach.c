__int64 __fastcall hal_reo_config_peach(__int64 a1, int a2, __int64 a3)
{
  int v5; // w0

  hal_write32_mb_1(a1, 10715136, a2 | 0xCu);
  v5 = hal_read32_mb_1(a1, 10718112);
  return hal_write32_mb_1(a1, 10718112, v5 & 0xFE01FFFF | ((*(_BYTE *)(a3 + 16) & 0xF) << 17));
}
