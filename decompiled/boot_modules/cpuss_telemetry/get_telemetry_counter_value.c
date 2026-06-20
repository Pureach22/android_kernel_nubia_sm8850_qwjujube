__int64 __fastcall get_telemetry_counter_value(unsigned int a1)
{
  if ( (*(_BYTE *)(telemetry + 8) & 1) != 0 )
  {
    while ( 1 )
      ;
  }
  return *(_QWORD *)(pvalue + 8LL * a1);
}
