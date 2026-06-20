__int64 __fastcall glink_adc_fwnode_xlate(__int64 a1, __int64 a2)
{
  __int64 v2; // x9
  __int64 result; // x0
  int *v5; // x10
  __int64 v6; // t1

  v2 = *(unsigned int *)(a1 + 1000);
  if ( (int)v2 < 1 )
    return 4294967274LL;
  result = 0;
  v5 = (int *)(*(_QWORD *)(a1 + 992) + 4LL);
  while ( 1 )
  {
    v6 = *v5;
    v5 += 40;
    if ( *(_QWORD *)(a2 + 16) == v6 )
      break;
    if ( v2 == ++result )
      return 4294967274LL;
  }
  return result;
}
