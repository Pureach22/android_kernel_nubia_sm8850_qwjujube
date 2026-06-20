__int64 __fastcall scm_serialization_scan_rules_cb(
        _BYTE *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  const char *v10; // x2

  if ( !a2 )
  {
    if ( a1[3] == 1 )
    {
      qdf_trace_msg(
        0x15u,
        8u,
        "%s: Allow scan request from connect",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "scm_serialization_scan_rules_cb");
    }
    else if ( a1[2] == 1 )
    {
      v10 = "%s: Cancel scan. MLME operation in progress";
      goto LABEL_14;
    }
    return 1;
  }
  if ( a2 == 16 )
  {
    if ( *a1 == 1 )
    {
      v10 = "%s: Cancel scan. CAC in progress";
      goto LABEL_14;
    }
    return 1;
  }
  if ( a2 != 10 )
  {
    qdf_trace_msg(
      0x15u,
      8u,
      "%s: not handled comp_id %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "scm_serialization_scan_rules_cb",
      a2);
    return 1;
  }
  if ( a1[1] != 1 )
    return 1;
  v10 = "%s: Cancel scan. Tdls in progress";
LABEL_14:
  qdf_trace_msg(0x15u, 8u, v10, a3, a4, a5, a6, a7, a8, a9, a10, "scm_serialization_scan_rules_cb");
  return 0;
}
