void *__fastcall populate_dot11f_non_inheritance(
        int a1,
        __int64 a2,
        const void *a3,
        const void *a4,
        unsigned __int8 a5,
        unsigned __int8 a6)
{
  unsigned __int8 *v10; // x0
  char v11; // w8
  void *result; // x0

  *(_WORD *)a2 = 257;
  *(_BYTE *)(a2 + 2) = a5;
  qdf_mem_copy((void *)(a2 + 3), a3, a5);
  v10 = (unsigned __int8 *)(a2 + 3 + a5);
  v11 = *(_BYTE *)(a2 + 1) + a5;
  *v10 = a6;
  *(_BYTE *)(a2 + 1) = v11 + 1;
  result = qdf_mem_copy(v10 + 1, a4, a6);
  *(_BYTE *)(a2 + 1) += a6;
  return result;
}
