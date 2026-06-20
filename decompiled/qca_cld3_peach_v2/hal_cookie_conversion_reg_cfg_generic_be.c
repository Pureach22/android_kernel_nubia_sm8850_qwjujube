__int64 __fastcall hal_cookie_conversion_reg_cfg_generic_be(__int64 a1, unsigned int *a2)
{
  unsigned int v4; // w8
  int v5; // w2
  unsigned int v6; // w8
  unsigned int v7; // w8
  int v8; // w2
  int v9; // w2
  int v10; // w0

  hal_write32_mb_1(a1, "ardown -> Enable", *a2);
  v4 = a2[1];
  if ( (v4 & 1) != 0 )
    v5 = 1572864;
  else
    v5 = 0;
  hal_write32_mb_1(
    a1,
    "wn -> Enable",
    v5 & 0xFFF80000 | (v4 << 17) & 0x40000 | (v4 << 11) & 0x3E000 | (2 * v4) & 0x1F00 | (unsigned __int8)(v4 >> 12));
  hal_write32_mb_1(a1, "", *a2);
  hal_write32_mb_1(
    a1,
    " WMI_PEER_APSD: uapsd Mask %d",
    (a2[1] << 11) & 0x3E000 | (((a2[1] >> 1) & 1) << 18) | (2 * a2[1]) & 0x1F00 | (unsigned __int8)(a2[1] >> 12));
  v6 = a2[1];
  hal_write32_mb_1(
    a1,
    "te cfg param fail for vdevId %d",
    (v6 >> 13) & 0x80
  | ((v6 & 1) << 8)
  | (v6 >> 15) & 0x40
  | (v6 >> 17) & 0x20
  | (v6 >> 19) & 0x10
  | (v6 >> 21) & 8
  | (v6 >> 23) & 4
  | (v6 >> 25) & 2
  | (v6 >> 27) & 1);
  v7 = a2[1];
  if ( (v7 & 1) != 0 )
    v8 = 72;
  else
    v8 = 0;
  hal_write32_mb_1(a1, "Update cfg param fail for vdevId %d", v8 & 0xFFFFFFFC | (v7 >> 27) & 2 | (v7 >> 29) & 1);
  hal_read32_mb_1(a1, "an supported %d", v9);
  return hal_write32_mb_1(a1, "an supported %d", v10 | 0x20000u);
}
