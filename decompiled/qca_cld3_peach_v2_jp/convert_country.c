void *__fastcall convert_country(int a1, _BYTE *a2, _BYTE *a3)
{
  void *result; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  unsigned __int64 v8; // x8
  _BYTE *v9; // x9
  char *v10; // x10
  char v11; // t1

  result = qdf_mem_copy(a2, a3 + 1, 3u);
  a2[3] = a3[7];
  a2[4] = a3[4];
  a2[5] = a3[5];
  a2[6] = a3[6];
  if ( a3[7] )
  {
    v8 = 0;
    v9 = a2 + 9;
    v10 = a3 + 10;
    while ( v8 != 80 )
    {
      ++v8;
      *(v9 - 2) = *(v10 - 2);
      *(v9 - 1) = *(v10 - 1);
      v11 = *v10;
      v10 += 3;
      *v9 = v11;
      v9 += 3;
      if ( v8 >= (unsigned __int8)a3[7] )
        return result;
    }
    __break(0x5512u);
    return (void *)convert_wmm_params(result, v6, v7);
  }
  return result;
}
