__int64 __fastcall generic_get(unsigned int *a1, _QWORD *a2)
{
  __int64 v2; // x11
  __int64 v3; // x10

  v2 = telemetry;
  do
  {
    v3 = *(_QWORD *)(v2 + 8);
    while ( (v3 & 1) != 0 )
      ;
    *a2 = *(_QWORD *)(pvalue + 8LL * *a1);
    v2 = telemetry;
  }
  while ( *(_QWORD *)(telemetry + 8) != v3 );
  return 0;
}
