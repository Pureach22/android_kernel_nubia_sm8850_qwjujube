unsigned int *__fastcall hal_rx_tlv_get_pn_num_be(unsigned int *result, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x8

  v2 = result[16];
  *a2 = v2;
  *a2 = v2 | ((unsigned __int64)result[17] << 32);
  a2[1] = result[18];
  return result;
}
