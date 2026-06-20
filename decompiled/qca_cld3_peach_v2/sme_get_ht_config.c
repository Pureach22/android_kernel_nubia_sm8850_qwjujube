__int64 __fastcall sme_get_ht_config(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int16 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  __int64 cmpt_obj; // x0
  unsigned int *v23; // x8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w20
  const char *v34; // x2

  if ( a2 > 5u || !(*(_QWORD *)(a1 + 17296) + 96LL * a2) )
  {
    v34 = "%s: pSession is NULL";
LABEL_11:
    qdf_trace_msg(0x34u, 2u, v34, a4, a5, a6, a7, a8, a9, a10, a11, "sme_get_ht_config");
    return 65531;
  }
  v12 = ((__int64 (__fastcall *)(_QWORD))wlan_objmgr_get_vdev_by_id_from_psoc)(*(_QWORD *)(a1 + 21624));
  if ( v12 )
  {
    v21 = v12;
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v12, v13, v14, v15, v16, v17, v18, v19, v20);
    if ( !cmpt_obj )
    {
      wlan_objmgr_vdev_release_ref(v21, 0xBu, v23, v24, v25, v26, v27, v28, v29, v30, v31);
      return 65531;
    }
    v32 = *(_DWORD *)(cmpt_obj + 60);
    wlan_objmgr_vdev_release_ref(v21, 0xBu, v23, v24, v25, v26, v27, v28, v29, v30, v31);
    if ( a3 <= 5u )
    {
      if ( !a3 )
        return v32 & 1;
      if ( a3 == 5 )
        return (v32 >> 5) & 1;
    }
    else
    {
      switch ( a3 )
      {
        case 6u:
          return (v32 >> 6) & 1;
        case 7u:
          return (v32 >> 7) & 1;
        case 8u:
          return (v32 >> 8) & 3;
      }
    }
    v34 = "%s: invalid ht capability";
    goto LABEL_11;
  }
  return 65531;
}
