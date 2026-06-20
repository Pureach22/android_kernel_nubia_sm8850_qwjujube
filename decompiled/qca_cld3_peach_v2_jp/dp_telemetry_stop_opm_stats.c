__int64 __fastcall dp_telemetry_stop_opm_stats(__int64 a1)
{
  if ( qdf_periodic_work_stop_sync(a1 + 3744) )
    return 0;
  else
    return 16;
}
