_QWORD *__fastcall adsp_pds_detach(_QWORD *result, __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v5; // x8
  int v6; // w21

  if ( a3 )
  {
    result = (_QWORD *)*result;
    if ( result[74] )
      return (_QWORD *)_pm_runtime_disable();
  }
  if ( a3 )
  {
    v5 = 0;
    v6 = 1;
    do
    {
      result = (_QWORD *)dev_pm_domain_detach(*(_QWORD *)(a2 + 8 * v5), 0);
      v5 = v6++;
    }
    while ( v5 < a3 );
  }
  return result;
}
