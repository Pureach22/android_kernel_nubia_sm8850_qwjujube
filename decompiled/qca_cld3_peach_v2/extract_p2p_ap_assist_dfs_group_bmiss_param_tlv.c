__int64 __fastcall extract_p2p_ap_assist_dfs_group_bmiss_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  const char *v12; // x2

  if ( a10 )
  {
    if ( *(_QWORD *)a10 )
    {
      *a11 = *(_DWORD *)(*(_QWORD *)a10 + 4LL);
      return 0;
    }
    v12 = "%s: Invalid fixed param";
  }
  else
  {
    v12 = "%s: Invalid event data";
  }
  qdf_trace_msg(0x31u, 2u, v12, a1, a2, a3, a4, a5, a6, a7, a8, "extract_p2p_ap_assist_dfs_group_bmiss_param_tlv");
  return 4;
}
