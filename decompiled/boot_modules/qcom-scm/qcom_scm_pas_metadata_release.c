_QWORD *__fastcall qcom_scm_pas_metadata_release(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x9

  if ( result && *result )
  {
    v2 = result;
    v3 = *(_QWORD *)_scm;
    if ( a2 )
      v3 = a2;
    result = (_QWORD *)dma_free_attrs(v3, result[2], *result, result[1], 0);
    v2[1] = 0;
    v2[2] = 0;
    *v2 = 0;
  }
  return result;
}
