__int64 __fastcall wlan_cp_stats_close(
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
  __int64 result; // x0
  void (__fastcall *v11)(_QWORD); // x8

  if ( a1 )
  {
    result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
    if ( result )
    {
      v11 = *(void (__fastcall **)(_QWORD))(result + 160);
      if ( v11 )
      {
        if ( *((_DWORD *)v11 - 1) != -770124015 )
          __break(0x8228u);
        v11(a1);
      }
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(0x62u, 2u, "%s: PSOC is null!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_close");
    return 4;
  }
  return result;
}
