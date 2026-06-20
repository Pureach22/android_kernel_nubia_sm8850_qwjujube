__int64 __fastcall target_if_send_ttlm_complete_cmd(
        __int64 a1,
        __int64 a2,
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
  const char *v12; // x2

  if ( a1 )
  {
    if ( a2 )
    {
      v10 = *(_QWORD *)(a1 + 2800);
      if ( v10 && *(_QWORD *)(v10 + 16) )
        return wmi_send_mlo_ttlm_complete_cmd();
      v12 = "%s: null wmi handle";
    }
    else
    {
      v12 = "%s: params is null";
    }
  }
  else
  {
    v12 = "%s: null pdev";
  }
  qdf_trace_msg(0x49u, 2u, v12, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_send_ttlm_complete_cmd");
  return 29;
}
