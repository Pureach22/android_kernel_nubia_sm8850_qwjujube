__int64 __fastcall wlan_cp_stats_open(
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
  __int64 comp_private_obj; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 (__fastcall *v19)(_QWORD); // x8
  __int64 v20; // x19
  __int64 result; // x0

  if ( a1 )
  {
    comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x1Bu);
    if ( comp_private_obj )
    {
      v19 = *(__int64 (__fastcall **)(_QWORD))(comp_private_obj + 152);
      v20 = comp_private_obj;
      if ( v19 )
      {
        if ( *((_DWORD *)v19 - 1) != -770124015 )
          __break(0x8228u);
        result = v19(a1);
      }
      else
      {
        result = 16;
      }
      *(_DWORD *)v20 = 0;
      *(_QWORD *)(v20 + 8) = 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: cp_stats_context is null!",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "wlan_cp_stats_open");
      return 16;
    }
  }
  else
  {
    qdf_trace_msg(0x62u, 2u, "%s: PSOC is null!", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cp_stats_open");
    return 4;
  }
  return result;
}
