__int64 __fastcall dp_telemetry_start_opm_stats(__int64 a1, unsigned int a2)
{
  if ( (qdf_periodic_work_start(a1 + 3744, a2) & 1) != 0 )
    return 0;
  else
    return 16;
}
