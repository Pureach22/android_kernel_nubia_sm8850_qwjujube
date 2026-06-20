_QWORD *__fastcall mlo_allocate_and_copy_ies(_QWORD *result, __int64 a2)
{
  _QWORD *v3; // x20

  result[20] = 0;
  v3 = result;
  result[22] = 0;
  result[12] = 0;
  result[13] = 0;
  *((_WORD *)result + 56) = 0;
  if ( *(_QWORD *)(a2 + 176) )
  {
    result = (_QWORD *)_qdf_mem_malloc(*(unsigned int *)(a2 + 168), "mlo_allocate_and_copy_ies", 60);
    v3[22] = result;
    if ( !result )
    {
      *((_DWORD *)v3 + 42) = 0;
      if ( !*(_QWORD *)(a2 + 160) )
        return result;
      goto LABEL_5;
    }
    result = qdf_mem_copy(result, *(const void **)(a2 + 176), *(unsigned int *)(a2 + 168));
  }
  if ( !*(_QWORD *)(a2 + 160) )
    return result;
LABEL_5:
  result = (_QWORD *)_qdf_mem_malloc(*(unsigned int *)(a2 + 152), "mlo_allocate_and_copy_ies", 69);
  v3[20] = result;
  if ( result )
    return qdf_mem_copy(result, *(const void **)(a2 + 160), *(unsigned int *)(a2 + 152));
  *((_DWORD *)v3 + 38) = 0;
  return result;
}
