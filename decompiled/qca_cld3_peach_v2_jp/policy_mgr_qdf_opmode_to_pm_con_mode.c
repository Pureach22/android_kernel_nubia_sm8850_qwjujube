__int64 __fastcall policy_mgr_qdf_opmode_to_pm_con_mode(
        __int64 a1,
        int a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w4

  v11 = a2;
  if ( a2 <= 1 )
  {
    if ( !a2 )
      return v11;
    if ( a2 != 1 )
      goto LABEL_11;
    if ( (policy_mgr_is_vdev_ll_lt_sap(a1, a3) & 1) != 0 )
      return 6;
    else
      return 1;
  }
  else if ( (unsigned int)(a2 - 2) >= 2 )
  {
    if ( a2 == 11 )
      return 4;
    if ( a2 == 16 )
      return 5;
LABEL_11:
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Unsupported mode (%d)",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "policy_mgr_qdf_opmode_to_pm_con_mode");
    return 7;
  }
  return v11;
}
