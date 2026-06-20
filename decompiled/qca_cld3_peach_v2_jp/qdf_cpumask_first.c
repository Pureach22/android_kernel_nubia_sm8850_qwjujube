__int64 __fastcall qdf_cpumask_first(_DWORD *a1)
{
  unsigned int v1; // w10

  v1 = __clz(__rbit64((unsigned int)*a1));
  if ( *a1 )
    return v1;
  else
    return 32;
}
