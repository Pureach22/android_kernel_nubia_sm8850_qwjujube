__int64 __fastcall hal_rx_wbm_err_info_get_generic_be(__int64 result, unsigned int *a2)
{
  unsigned int v2; // w9
  unsigned int v3; // w9
  unsigned int v4; // w9
  unsigned int v5; // w9

  v2 = *a2 & 0xFFFFFFF8 | *(_DWORD *)(result + 8) & 7;
  *a2 = v2;
  v3 = v2 & 0xFCFFFFFF | ((HIBYTE(*(_DWORD *)(result + 8)) & 3) << 24);
  *a2 = v3;
  v4 = v3 & 0x83FFFFFF | (((*(_DWORD *)(result + 8) >> 26) & 0x1F) << 26);
  *a2 = v4;
  v5 = v4 & 0xFFF9FFFF | (((*(_DWORD *)(result + 8) >> 17) & 3) << 17);
  *a2 = v5;
  *a2 = v5 & 0xFF07FFFF | (((*(_DWORD *)(result + 8) >> 19) & 0x1F) << 19);
  return result;
}
