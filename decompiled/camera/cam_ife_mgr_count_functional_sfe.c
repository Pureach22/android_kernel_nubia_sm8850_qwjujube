__int64 cam_ife_mgr_count_functional_sfe()
{
  int v0; // w6
  __int64 result; // x0

  v0 = qword_3949D8 != 0;
  g_num_sfe_functional = v0;
  if ( qword_3949E0 )
  {
    if ( qword_3949D8 )
      v0 = 2;
    else
      v0 = 1;
    g_num_sfe_functional = v0;
  }
  if ( qword_3949E8 )
    g_num_sfe_functional = ++v0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_mgr_count_functional_sfe",
             3394,
             "counted %u functional SFEs",
             v0);
  return result;
}
