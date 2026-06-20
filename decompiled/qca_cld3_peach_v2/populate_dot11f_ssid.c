void *__fastcall populate_dot11f_ssid(__int64 a1, unsigned __int8 *a2, _BYTE *a3)
{
  unsigned int v3; // w8
  void *result; // x0

  *a3 = 1;
  v3 = *a2;
  a3[1] = v3;
  if ( v3 )
    return qdf_mem_copy(a3 + 2, a2 + 1, v3);
  return result;
}
