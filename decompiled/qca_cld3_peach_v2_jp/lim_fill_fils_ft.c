_QWORD *__fastcall lim_fill_fils_ft(_QWORD *result, __int64 a2)
{
  __int64 v2; // x8
  int v3; // w8

  v2 = result[1247];
  if ( v2 )
  {
    v3 = *(unsigned __int8 *)(v2 + 971);
    if ( v3 )
    {
      *(_BYTE *)(*(_QWORD *)(a2 + 9976) + 971LL) = v3;
      return qdf_mem_copy(
               (void *)(*(_QWORD *)(a2 + 9976) + 923LL),
               (const void *)(result[1247] + 923LL),
               *(unsigned __int8 *)(result[1247] + 971LL));
    }
  }
  return result;
}
