__int64 __fastcall dbglog_parser_type_init(__int64 a1, int a2)
{
  if ( a2 > 3 )
    return 0xFFFFFFFFLL;
  dbglog_process_type = a2;
  gprint_limiter = 0;
  return 0;
}
