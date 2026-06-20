__int64 __fastcall populate_dot11f_6g_rnr(
        __int64 a1,
        __int64 a2,
        unsigned __int8 *a3,
        _WORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 session_by_vdev_id; // x0
  __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  const char *v38; // x2
  int v39; // [xsp+10h] [xbp-10h] BYREF
  char v40; // [xsp+14h] [xbp-Ch]
  __int64 v41; // [xsp+18h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 || !a3 || (v12 = *(_QWORD *)(a2 + 16)) == 0 )
  {
    v38 = "%s: Invalid params";
    goto LABEL_12;
  }
  v13 = *(_QWORD *)(v12 + 152);
  if ( !v13 || (v14 = *(_QWORD *)(v13 + 80)) == 0 )
  {
    v38 = "%s: Invalid psoc";
    goto LABEL_12;
  }
  v40 = -1;
  v39 = -1;
  result = wlan_objmgr_iterate_obj_list(v14, 2, lim_is_6g_vdev, (__int64)&v39, 1, 7u);
  if ( (unsigned __int8)v39 != 255 )
  {
    session_by_vdev_id = pe_find_session_by_vdev_id(a1, v39, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( session_by_vdev_id )
    {
      v29 = session_by_vdev_id;
      populate_dot11f_rnr_tbtt_info(a1, a2, session_by_vdev_id, (__int64)a3, 13);
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: vdev id %d populate RNR IE with 6G vdev id %d op class %d chan num %d tbtt_len %d",
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35,
                 v36,
                 v37,
                 "populate_dot11f_6g_rnr",
                 *(unsigned __int8 *)(*(_QWORD *)(a2 + 16) + 104LL),
                 *(unsigned __int8 *)(*(_QWORD *)(v29 + 16) + 104LL),
                 a3[3],
                 a3[4],
                 a3[2]);
      *a4 = 1;
      goto LABEL_13;
    }
    v38 = "%s: Invalid co located session";
LABEL_12:
    result = qdf_trace_msg(0x35u, 2u, v38, a5, a6, a7, a8, a9, a10, a11, a12, "populate_dot11f_6g_rnr");
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
