__int64 __fastcall wlan_hdd_get_link_info_from_objmgr(
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
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 608);
    if ( v11 )
      return *(_QWORD *)(v11 + 8);
    else
      return 0;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: null vdev object",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_hdd_get_link_info_from_objmgr",
      v9,
      v10);
    return 0;
  }
}
