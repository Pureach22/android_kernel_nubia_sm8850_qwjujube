__int64 __fastcall cfg_parse_to_global_store(char *a1)
{
  unsigned int v2; // w20

  if ( _cfg_global_store )
  {
    v2 = qdf_ini_parse(a1);
    if ( v2 )
      qdf_trace_msg(80, 2, "%s: Failed to parse *.ini file @ %s; status:%d", "cfg_ini_parse_to_store", a1, v2);
  }
  else
  {
    v2 = 2;
    qdf_trace_msg(80, 2, "%s: Global INI store is not valid", "cfg_parse_to_global_store");
  }
  return v2;
}
