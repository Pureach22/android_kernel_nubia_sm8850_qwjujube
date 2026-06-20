void *__fastcall populate_dot11_tsrsie(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned __int8 a4)
{
  void *result; // x0

  a3[1] = *a2;
  result = qdf_mem_copy(a3 + 3, a2 + 1, a4);
  a3[2] = a4;
  *a3 = 1;
  return result;
}
