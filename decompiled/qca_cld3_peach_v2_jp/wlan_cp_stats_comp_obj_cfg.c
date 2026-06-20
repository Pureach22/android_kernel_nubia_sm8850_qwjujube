__int64 __fastcall wlan_cp_stats_comp_obj_cfg(
        int a1,
        unsigned int a2,
        int a3,
        _QWORD *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x8
  const char *v14; // x2
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 comp_private_obj; // x0
  _DWORD *v23; // x8

  if ( !a4 )
  {
    v14 = "%s: common object is null!";
LABEL_10:
    qdf_trace_msg(0x62u, 2u, v14, a6, a7, a8, a9, a10, a11, a12, a13, "wlan_cp_stats_comp_obj_cfg");
    return 4;
  }
  if ( a3 != 11 )
  {
    v14 = "%s: Invalid UMAC id provided to cp_stats";
    goto LABEL_10;
  }
  if ( a1 > 1 )
  {
    if ( a1 == 2 )
    {
      v17 = a4[19];
      if ( !v17 )
        goto LABEL_24;
    }
    else
    {
      if ( a1 != 3 )
      {
LABEL_16:
        v14 = "%s: Invalid common object type";
        goto LABEL_10;
      }
      v16 = a4[11];
      if ( !v16 )
        goto LABEL_24;
      v17 = *(_QWORD *)(v16 + 152);
      if ( !v17 )
        goto LABEL_24;
    }
    v13 = *(_QWORD *)(v17 + 80);
    if ( v13 )
      goto LABEL_19;
LABEL_24:
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: cp_stats_context is null!",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "wlan_cp_stats_comp_obj_cfg");
    return 16;
  }
  v13 = (__int64)a4;
  if ( !a1 )
    goto LABEL_19;
  if ( a1 != 1 )
    goto LABEL_16;
  v13 = a4[10];
  if ( !v13 )
    goto LABEL_24;
LABEL_19:
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(v13, 0x1Bu);
  if ( !comp_private_obj )
    goto LABEL_24;
  v23 = *(_DWORD **)(comp_private_obj + 144);
  if ( !v23 )
    return 16;
  if ( *(v23 - 1) != -1601036097 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD *, __int64))v23)((unsigned int)a1, a2, 0, a4, a5);
}
