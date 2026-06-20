unsigned int *__fastcall hal_rx_wbm_rel_buf_paddr_get_be(unsigned int *result, unsigned __int64 *a2)
{
  unsigned int v2; // w8
  unsigned int v3; // w9

  if ( (result[2] & 0x10000) != 0 )
  {
    v2 = result[6];
    v3 = result[7];
  }
  else
  {
    v2 = *result;
    LOBYTE(v3) = *((_BYTE *)result + 4);
  }
  *a2 = v2 | ((unsigned __int64)(unsigned __int8)v3 << 32);
  return result;
}
