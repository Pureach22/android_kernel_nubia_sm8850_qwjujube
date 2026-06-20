__int64 __fastcall cfg_valid_ini_check(char *a1)
{
  qdf_trace_msg(80, 8, "%s: enter", "cfg_valid_ini_check");
  return qdf_valid_ini_check(a1) & 1;
}
