__int64 __fastcall cfg_parse_to_psoc_store(__int64 a1, char *a2)
{
  unsigned int v3; // w20

  wlan_objmgr_psoc_get_comp_private_obj(a1, 7);
  v3 = qdf_ini_parse(a2);
  if ( v3 )
    qdf_trace_msg(80, 2, "%s: Failed to parse *.ini file @ %s; status:%d", "cfg_ini_parse_to_store", a2, v3);
  return v3;
}
