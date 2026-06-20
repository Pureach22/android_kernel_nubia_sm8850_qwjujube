__int64 __fastcall ucfg_nan_check_and_disable_unsupported_ndi(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v12; // w20
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w0
  __int64 result; // x0
  unsigned int v23; // w0

  if ( !a1 )
  {
    qdf_trace_msg(
      0x53u,
      2u,
      "%s: psoc object is NULL, no action will be taken",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "ucfg_nan_check_and_disable_unsupported_ndi");
    return 4;
  }
  v12 = policy_mgr_mode_specific_connection_count(a1, 4, nullptr);
  if ( (a2 & 1) == 0 )
  {
    if ( v12 > 1 )
    {
      v23 = policy_mgr_mode_specific_vdev_id(a1, 4);
      return ucfg_nan_disable_ndi(a1, v23);
    }
    qdf_trace_msg(
      0x53u,
      8u,
      "%s: No more than one NDI is active, nothing to do...",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "ucfg_nan_check_and_disable_unsupported_ndi");
    return 0;
  }
  qdf_trace_msg(
    0x53u,
    8u,
    "%s: Force disable all NDPs",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "ucfg_nan_check_and_disable_unsupported_ndi");
  if ( !v12 )
    return 0;
  while ( 1 )
  {
    v21 = policy_mgr_mode_specific_vdev_id(a1, 4);
    result = ucfg_nan_disable_ndi(a1, v21);
    if ( (_DWORD)result )
      break;
    if ( !--v12 )
      return 0;
  }
  return result;
}
