__int64 __fastcall tdls_set_current_mode(
        __int64 result,
        unsigned int a2,
        char a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  _QWORD *v15; // x20
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  __int64 v33; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x23
  unsigned int *v43; // x8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x4
  const char *v53; // x2
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int *v62; // x8
  __int64 comp_private_obj; // x0
  unsigned __int64 v70; // x10
  unsigned __int64 v73; // x10

  if ( !result )
    return result;
  v15 = (_QWORD *)result;
  qdf_trace_msg(0, 8u, "%s: mode %d source %d", a5, a6, a7, a8, a9, a10, a11, a12, "tdls_set_current_mode", a2, a4);
  if ( (a3 & 1) != 0 )
    *((_DWORD *)v15 + 3) = a2;
  if ( *((_DWORD *)v15 + 2) != a2 )
  {
    v33 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(*v15, 0, 17);
    if ( v33 )
    {
      v42 = v33;
      if ( wlan_cm_is_vdev_connected(v33, v34, v35, v36, v37, v38, v39, v40, v41) )
      {
        v52 = *(unsigned __int8 *)(v42 + 168);
        v53 = "%s: set mode in tdls STA vdev:%d";
        goto LABEL_17;
      }
      wlan_objmgr_vdev_release_ref(v42, 0x11u, v43, v44, v45, v46, v47, v48, v49, v50, v51);
    }
    result = ((__int64 (__fastcall *)(_QWORD, __int64, __int64))wlan_objmgr_get_vdev_by_opmode_from_psoc)(*v15, 2, 17);
    if ( !result )
    {
LABEL_20:
      if ( (a3 & 1) == 0 )
        *((_DWORD *)v15 + 3) = *((_DWORD *)v15 + 2);
      *((_DWORD *)v15 + 2) = a2;
      return result;
    }
    v42 = result;
    if ( !wlan_cm_is_vdev_connected(result, v54, v55, v56, v57, v58, v59, v60, v61) )
    {
LABEL_19:
      result = wlan_objmgr_vdev_release_ref(v42, 0x11u, v62, v44, v45, v46, v47, v48, v49, v50, v51);
      goto LABEL_20;
    }
    v52 = *(unsigned __int8 *)(v42 + 168);
    v53 = "%s: set mode in tdls P2P cli vdev:%d";
LABEL_17:
    qdf_trace_msg(0, 8u, v53, v44, v45, v46, v47, v48, v49, v50, v51, "tdls_set_current_mode", v52);
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(v42, 0xAu);
    if ( comp_private_obj )
      v44 = tdls_set_mode_in_vdev(comp_private_obj, v15, a2, a4);
    goto LABEL_19;
  }
  result = qdf_trace_msg(
             0,
             8u,
             "%s: already in mode %d",
             v16,
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             "tdls_set_current_mode",
             a2);
  if ( a2 - 2 < 3 )
  {
    _X9 = &v15[(a4 >> 6) + 3];
    __asm { PRFM            #0x11, [X9] }
    do
      v70 = __ldxr(_X9);
    while ( __stxr(v70 & ~(1LL << a4), _X9) );
    v32 = "%s: clear source mask:%d";
    return qdf_trace_msg(0, 8u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "tdls_set_current_mode", a4);
  }
  if ( !a2 )
  {
    _X9 = &v15[(a4 >> 6) + 3];
    __asm { PRFM            #0x11, [X9] }
    do
      v73 = __ldxr(_X9);
    while ( __stxr(v73 | (1LL << a4), _X9) );
    v32 = "%s: set source mask:%d";
    return qdf_trace_msg(0, 8u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "tdls_set_current_mode", a4);
  }
  return result;
}
