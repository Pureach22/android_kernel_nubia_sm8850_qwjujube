size_t __fastcall cm_copy_rsp_from_rsp(__int64 a1, __int64 a2)
{
  size_t result; // x0

  result = (size_t)memcpy((void *)a1, (const void *)a2, 0xA0u);
  *(_QWORD *)(a1 + 80) = 0;
  *(_QWORD *)(a1 + 96) = 0;
  *(_QWORD *)(a1 + 112) = 0;
  *(_QWORD *)(a1 + 128) = 0;
  if ( !*(_QWORD *)(a2 + 80) || (result = *(unsigned int *)(a2 + 72), !(_DWORD)result) )
  {
LABEL_5:
    if ( !*(_QWORD *)(a2 + 96) )
      goto LABEL_12;
    goto LABEL_6;
  }
  result = _qdf_mem_malloc(result, "cm_fill_connect_ies_from_rsp", 2152);
  *(_QWORD *)(a1 + 80) = result;
  if ( result )
  {
    result = (size_t)qdf_mem_copy((void *)result, *(const void **)(a2 + 80), *(unsigned int *)(a2 + 72));
    goto LABEL_5;
  }
  *(_DWORD *)(a1 + 72) = 0;
  if ( !*(_QWORD *)(a2 + 96) )
    goto LABEL_12;
LABEL_6:
  result = *(unsigned int *)(a2 + 88);
  if ( (_DWORD)result )
  {
    result = _qdf_mem_malloc(result, "cm_fill_connect_ies_from_rsp", 2165);
    *(_QWORD *)(a1 + 96) = result;
    if ( result )
      result = (size_t)qdf_mem_copy((void *)result, *(const void **)(a2 + 96), *(unsigned int *)(a2 + 88));
    else
      *(_DWORD *)(a1 + 88) = 0;
  }
LABEL_12:
  if ( *(_QWORD *)(a2 + 112) )
  {
    result = *(unsigned int *)(a2 + 104);
    if ( (_DWORD)result )
    {
      result = _qdf_mem_malloc(result, "cm_fill_connect_ies_from_rsp", 2178);
      *(_QWORD *)(a1 + 112) = result;
      if ( !result )
      {
        *(_DWORD *)(a1 + 104) = 0;
        if ( !*(_QWORD *)(a2 + 128) )
          return result;
        goto LABEL_17;
      }
      result = (size_t)qdf_mem_copy((void *)result, *(const void **)(a2 + 112), *(unsigned int *)(a2 + 104));
    }
  }
  if ( !*(_QWORD *)(a2 + 128) )
    return result;
LABEL_17:
  result = *(unsigned int *)(a2 + 120);
  if ( (_DWORD)result )
  {
    result = _qdf_mem_malloc(result, "cm_fill_connect_ies_from_rsp", 2191);
    *(_QWORD *)(a1 + 128) = result;
    if ( result )
      return (size_t)qdf_mem_copy((void *)result, *(const void **)(a2 + 128), *(unsigned int *)(a2 + 120));
    else
      *(_DWORD *)(a1 + 120) = 0;
  }
  return result;
}
