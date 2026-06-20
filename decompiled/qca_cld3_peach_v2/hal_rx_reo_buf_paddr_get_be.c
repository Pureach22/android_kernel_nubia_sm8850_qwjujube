unsigned int *__fastcall hal_rx_reo_buf_paddr_get_be(unsigned int *result, __int64 a2)
{
  *(_QWORD *)a2 = *result | ((unsigned __int64)*((unsigned __int8 *)result + 4) << 32);
  *(_DWORD *)(a2 + 8) = result[1] >> 12;
  return result;
}
