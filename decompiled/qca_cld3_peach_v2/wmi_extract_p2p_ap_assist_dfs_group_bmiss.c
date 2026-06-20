__int64 __fastcall wmi_extract_p2p_ap_assist_dfs_group_bmiss(
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
  __int64 (*v9)(void); // x8

  if ( a1 )
  {
    v9 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 728) + 2904LL);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != 1128280642 )
        __break(0x8228u);
      return v9();
    }
    else
    {
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: wmi handle is null",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wmi_extract_p2p_ap_assist_dfs_group_bmiss");
    return 4;
  }
}
