_DWORD *__fastcall hal_rxdma_buff_addr_info_set_be(_DWORD *result, __int64 a2, int a3, char a4)
{
  *result = a2;
  result[1] = BYTE4(a2) | (a3 << 12) | ((a4 & 0xF) << 8);
  return result;
}
