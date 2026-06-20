__int64 __fastcall target_if_pmo_send_wow_patterns_to_fw(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x9
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x9
  const char *v14; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 152);
    if ( v9 && (v10 = *(_QWORD *)(v9 + 80)) != 0 )
    {
      v11 = *(_QWORD *)(v10 + 2800);
      if ( v11 )
      {
        v12 = *(_QWORD *)(v11 + 16);
        if ( v12 )
          return wmi_unified_wow_patterns_to_fw_cmd(v12, *(unsigned __int8 *)(a1 + 104));
      }
      v14 = "%s: Invalid wmi handle";
    }
    else
    {
      v14 = "%s: psoc handle is NULL";
    }
  }
  else
  {
    v14 = "%s: vdev ptr passed is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_pmo_send_wow_patterns_to_fw");
  return 4;
}
