__int64 cam_ife_mgr_count_functional_ife()
{
  int v0; // w7
  int *v1; // x10
  int v2; // w6
  __int64 result; // x0

  g_num_ife_functional = 0;
  g_num_ife_lite_functional = 0;
  if ( qword_394998 )
  {
    v0 = (unsigned __int8)byte_3A8474;
    v1 = &g_num_ife_functional;
    v2 = (unsigned __int8)byte_3A8474 ^ 1;
    if ( byte_3A8474 )
      v1 = &g_num_ife_lite_functional;
    *v1 = 1;
  }
  else
  {
    v0 = 0;
    v2 = 0;
  }
  if ( qword_3949A0 )
  {
    if ( (byte_3A8484 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949A8 )
  {
    if ( (byte_3A8494 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949B0 )
  {
    if ( (byte_3A84A4 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949B8 )
  {
    if ( (byte_3A84B4 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949C0 )
  {
    if ( (byte_3A84C4 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949C8 )
  {
    if ( (byte_3A84D4 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( qword_3949D0 )
  {
    if ( (byte_3A84E4 & 1) != 0 )
      g_num_ife_lite_functional = ++v0;
    else
      g_num_ife_functional = ++v2;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             debug_mdl & 8,
             4,
             "cam_ife_mgr_count_functional_ife",
             3413,
             "counted functional %d IFE and %d IFE lite",
             v2,
             v0);
  return result;
}
