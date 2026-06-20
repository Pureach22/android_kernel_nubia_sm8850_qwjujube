__int64 __fastcall cfg_ini_section_handler(__int64 a1, const char *a2)
{
  qdf_trace_msg(80, 2, "%s: Unexpected section '%s'. Sections are not supported.", "cfg_ini_section_handler", a2);
  return 0;
}
