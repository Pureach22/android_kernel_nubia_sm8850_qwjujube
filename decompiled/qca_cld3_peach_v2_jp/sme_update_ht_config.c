__int64 __fastcall sme_update_ht_config(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        _BOOL4 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _BOOL4 v15; // w22
  const char *v16; // x2
  __int64 v18; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  __int64 cmpt_obj; // x0
  unsigned int *v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w8
  unsigned int v39; // w9
  unsigned int *v40; // x8

  if ( (unsigned __int8)a2 > 5u || !(*(_QWORD *)(a1 + 17224) + 96LL * (unsigned __int8)a2) )
  {
    v16 = "%s: pSession is NULL";
    goto LABEL_6;
  }
  v15 = a4;
  if ( (unsigned int)wma_set_htconfig(a2, a3, a4) )
  {
    v16 = "%s: Failed to set ht capability in target";
LABEL_6:
    qdf_trace_msg(0x34u, 2u, v16, a5, a6, a7, a8, a9, a10, a11, a12, "sme_update_ht_config");
    return 4294967291LL;
  }
  v18 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21552),
          a2,
          11);
  if ( !v18 )
    return 4294967291LL;
  v27 = v18;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v18, v19, v20, v21, v22, v23, v24, v25, v26);
  if ( !cmpt_obj )
  {
    wlan_objmgr_vdev_release_ref(v27, 0xBu, v29, v30, v31, v32, v33, v34, v35, v36, v37);
    return 4294967291LL;
  }
  v38 = *(_DWORD *)(cmpt_obj + 60);
  v39 = v38 & 0xFFFF0000;
  if ( (unsigned __int16)a3 <= 5u )
  {
    if ( (_WORD)a3 )
    {
      if ( (unsigned __int16)a3 == 5 )
      {
        v15 = v15;
        LOWORD(v38) = v38 & 0xFFDF | (32 * v15);
      }
    }
    else
    {
      LOWORD(v38) = v38 & 0xFFFE | v15;
    }
  }
  else
  {
    switch ( (unsigned __int16)a3 )
    {
      case 6u:
        LOWORD(v38) = v38 & 0xFFBF | (v15 << 6);
        v15 = v15;
        break;
      case 7u:
        LOWORD(v38) = v38 & 0xFF7F | (v15 << 7);
        break;
      case 8u:
        LOWORD(v38) = v38 & 0xFCFF | ((v15 & 3) << 8);
        break;
    }
  }
  v40 = (unsigned int *)((unsigned __int16)v38 | v39);
  *(_DWORD *)(cmpt_obj + 60) = (_DWORD)v40;
  wlan_objmgr_vdev_release_ref(v27, 0xBu, v40, v30, v31, v32, v33, v34, v35, v36, v37);
  csr_roam_update_config(a1, a2, a3, v15);
  return 0;
}
