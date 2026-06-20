_DWORD *__fastcall wma_update_vdev_he_ops(_DWORD *result, __int64 a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w8
  unsigned int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  int v7; // w8

  v2 = *result & 0xFFFFFFF8;
  *result &= 0xC0FFFFFF;
  v3 = v2 & 0xC0FFFFFF | ((*(_BYTE *)(a2 + 5) & 0x3F) << 24);
  *result = v3;
  v4 = v3 & 0xFFFFFFF0 | *(_DWORD *)(a2 + 1) & 7;
  *result = v4;
  v5 = v4 & 0xFFFFC007 | *(_DWORD *)(a2 + 1) & 8;
  *result = v5;
  v6 = v5 & 0xBFFFFFFF | (*(_DWORD *)(a2 + 1) >> 4) & 0x3FF0;
  *result = v6;
  v7 = v6 & 0x3FFFFFFF | (((*(unsigned __int8 *)(a2 + 5) >> 6) & 1) << 30);
  *result = v7;
  *result = v7 & 0x7FFFFFFF | (*(_BYTE *)(a2 + 5) >> 7 << 31);
  return result;
}
