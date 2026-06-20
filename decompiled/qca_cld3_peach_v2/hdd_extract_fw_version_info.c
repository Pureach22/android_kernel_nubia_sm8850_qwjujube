_DWORD *__fastcall hdd_extract_fw_version_info(_DWORD *result)
{
  unsigned int v1; // w8
  unsigned int v2; // w9

  v1 = result[133];
  v2 = result[134];
  result[140] = v1 & 0x7FFF;
  result[135] = v1 >> 28;
  result[137] = (v1 >> 20) & 0xF;
  result[136] = HIBYTE(v1) & 0xF;
  result[138] = (v2 >> 6) & 0x70 | (v2 >> 28);
  result[139] = (v2 >> 23) & 0x1F;
  return result;
}
