char *__fastcall dp_mst_sim_read_esi(char *result, __int64 a2)
{
  size_t v2; // x2
  __int64 v4; // x9
  char v5; // w8

  v2 = *(_QWORD *)(a2 + 16);
  v4 = (unsigned int)(*(_DWORD *)a2 - 8194);
  if ( v2 - v4 > 0xF )
  {
    v5 = 1;
LABEL_5:
    *(_BYTE *)(a2 + 5) = v5;
    return result;
  }
  if ( (unsigned int)v4 < 0x11 )
  {
    result = (char *)memcpy(*(void **)(a2 + 8), &result[v4 + 780], v2);
    v5 = 0;
    goto LABEL_5;
  }
  __break(0x5512u);
  return (char *)dp_mst_sim_update(result, a2, v2);
}
