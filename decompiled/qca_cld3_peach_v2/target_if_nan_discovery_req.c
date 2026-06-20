__int64 __fastcall target_if_nan_discovery_req(
        __int64 *a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x8
  const char *v13; // x2
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  const char *v17; // x2
  const char *v18; // x3

  if ( !a1 )
  {
    v13 = "%s: Invalid req.";
    goto LABEL_17;
  }
  if ( a2 )
  {
    if ( a2 != 1 )
    {
      if ( a2 == 2 )
      {
        if ( *a1 )
        {
          v10 = *(_QWORD *)(*a1 + 2800);
          if ( v10 )
          {
            v11 = *(_QWORD *)(v10 + 16);
            if ( v11 )
              return wmi_unified_nan_disable_req_cmd(v11);
          }
          v17 = "%s: wmi_handle is null.";
        }
        else
        {
          v17 = "%s: psoc is null.";
        }
        v18 = "target_if_nan_disable_req";
        goto LABEL_23;
      }
      v13 = "%s: Invalid NAN req type";
LABEL_17:
      qdf_trace_msg(0x49u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_nan_discovery_req");
      return 4;
    }
    v14 = *a1;
    if ( *a1 )
      goto LABEL_11;
  }
  else
  {
    v14 = *a1;
    if ( *a1 )
    {
LABEL_11:
      v15 = *(_QWORD *)(v14 + 2800);
      if ( v15 )
      {
        v16 = *(_QWORD *)(v15 + 16);
        if ( v16 )
          return wmi_unified_nan_req_cmd(v16);
      }
      v17 = "%s: wmi_handle is null.";
      goto LABEL_19;
    }
  }
  v17 = "%s: psoc is null.";
LABEL_19:
  v18 = "target_if_nan_generic_req";
LABEL_23:
  qdf_trace_msg(0x49u, 2u, v17, a3, a4, a5, a6, a7, a8, a9, a10, v18);
  return 29;
}
