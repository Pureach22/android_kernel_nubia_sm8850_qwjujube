void *__fastcall convert_tim(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  unsigned int v3; // w8

  *a2 = a3[1];
  a2[1] = a3[2];
  a2[2] = a3[3];
  v3 = (unsigned __int8)a3[4];
  a2[3] = v3;
  return qdf_mem_copy(a2 + 4, a3 + 5, v3);
}
