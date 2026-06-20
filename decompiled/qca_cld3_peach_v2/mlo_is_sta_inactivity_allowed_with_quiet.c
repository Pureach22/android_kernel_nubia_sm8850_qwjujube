bool __fastcall mlo_is_sta_inactivity_allowed_with_quiet(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        __int64 a4,
        unsigned __int8 a5,
        __int64 a6)
{
  __int64 v10; // x27
  __int64 v11; // x28
  unsigned __int64 v12; // x23
  bool v13; // w24
  __int64 v14; // x9
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x25
  char is_sta_in_quiet_status; // w26
  unsigned int *v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7

  if ( !a3 )
    return 0;
  v10 = 0;
  v11 = a5;
  v12 = a3;
  v13 = 1;
  while ( 1 )
  {
    if ( (_DWORD)v11 )
    {
      v14 = 0;
      while ( *(unsigned __int8 *)(a2 + *(unsigned __int8 *)(a4 + v10)) != *(unsigned __int8 *)(a6 + v14) )
      {
        if ( v11 == ++v14 )
          goto LABEL_12;
      }
      if ( (unsigned __int8)v14 != (_DWORD)v11 )
        goto LABEL_4;
    }
LABEL_12:
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            a1,
            *(unsigned __int8 *)(a2 + *(unsigned __int8 *)(a4 + v10)),
            78);
    if ( v15 )
      break;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: invalid vdev for id %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "mlo_is_sta_inactivity_allowed_with_quiet",
      *(unsigned __int8 *)(a2 + *(unsigned __int8 *)(a4 + v10)));
LABEL_4:
    v13 = ++v10 < v12;
    if ( v10 == v12 )
      return v13;
  }
  v24 = v15;
  is_sta_in_quiet_status = mlo_is_sta_in_quiet_status(
                             *(_QWORD *)(v15 + 1360),
                             *(_BYTE *)(v15 + 93),
                             v16,
                             v17,
                             v18,
                             v19,
                             v20,
                             v21,
                             v22,
                             v23);
  wlan_objmgr_vdev_release_ref(v24, 0x4Eu, v26, v27, v28, v29, v30, v31, v32, v33, v34);
  if ( (is_sta_in_quiet_status & 1) != 0 )
    goto LABEL_4;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: vdev id %d link id %d is not in quiet, allow partner link to trigger inactivity",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "mlo_is_sta_inactivity_allowed_with_quiet",
    *(unsigned __int8 *)(v24 + 168),
    *(unsigned __int8 *)(v24 + 93));
  return v13;
}
