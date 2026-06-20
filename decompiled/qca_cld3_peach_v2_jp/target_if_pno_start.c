__int64 __fastcall target_if_pno_start(
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
  __int64 v11; // x19
  __int64 result; // x0

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
  {
    result = wmi_unified_pno_start_cmd(*(_QWORD *)(v10 + 16));
    if ( !(_DWORD)result )
    {
      if ( *(_BYTE *)(a2 + 20673) == 1 )
        return wmi_unified_nlo_mawc_cmd(v11, a2 + 20672);
      else
        return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x49u, 2u, "%s: Invalid WMI handle", a3, a4, a5, a6, a7, a8, a9, a10, "target_if_pno_start");
    return 16;
  }
  return result;
}
