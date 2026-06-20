_DWORD *__fastcall hal_set_link_desc_addr_be(_DWORD *result, int a2, __int64 a3, char a4)
{
  *result = a3;
  result[1] = BYTE4(a3) | ((a4 & 0xF) << 8) | (a2 << 12);
  return result;
}
