__int64 __fastcall hif_trigger_dump(__int64 a1, unsigned __int8 a2, char a3)
{
  switch ( a2 )
  {
    case 3u:
      return priv_dump_bbwatchdog();
    case 2u:
      if ( (a3 & 1) != 0 )
        return priv_start_cap_chaninfo();
      else
        return priv_dump_chaninfo();
    case 1u:
      if ( (a3 & 1) != 0 )
        return priv_start_agc();
      else
        return priv_dump_agc();
    default:
      return qdf_trace_msg(61, 2, "%s: Invalid htc dump command: %d", "hif_trigger_dump", a2);
  }
}
