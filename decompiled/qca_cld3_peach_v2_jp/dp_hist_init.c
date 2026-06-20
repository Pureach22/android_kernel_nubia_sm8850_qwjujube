void *__fastcall dp_hist_init(_DWORD *a1, int a2)
{
  void *result; // x0

  result = qdf_mem_set(a1, 0x80u, 0);
  a1[29] = 0x7FFFFFFF;
  *a1 = a2;
  return result;
}
