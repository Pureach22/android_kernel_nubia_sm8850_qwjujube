__int64 __fastcall mlme_twt_any_peer_cmd_in_progress(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w19
  unsigned __int8 v15; // w23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  _QWORD *v26; // x0
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x22
  int v37; // w9
  _BOOL4 v38; // w10
  _BOOL4 v39; // w9
  __int64 next_active_peer_of_vdev; // x23
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 comp_private_obj; // x0
  __int64 v50; // x1
  __int64 v51; // x2
  __int64 v52; // x3
  __int64 v53; // x6
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  _BOOL4 v63; // w19
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7

  v12 = a3;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: psoc is NULL, dialog_id: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlme_twt_any_peer_cmd_in_progress",
      a3);
    return 0;
  }
  v15 = a2;
  v16 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 2);
  if ( !v16 )
  {
    qdf_trace_msg(
      0x1Fu,
      2u,
      "%s: vdev is NULL, vdev_id: %d dialog_id: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "mlme_twt_any_peer_cmd_in_progress",
      v15,
      a3);
    return 0;
  }
  v25 = v16;
  v26 = wlan_vdev_peer_list_peek_active_head(v16, (_QWORD *)(v16 + 192), 2u);
  if ( !v26 )
  {
LABEL_17:
    wlan_objmgr_vdev_release_ref(v25, 2u, v27, v28, v29, v30, v31, v32, v33, v34, v35);
    return 0;
  }
  v36 = (__int64)v26;
  while ( 1 )
  {
    comp_private_obj = wlan_objmgr_peer_get_comp_private_obj(v36, 0);
    if ( comp_private_obj && *(_BYTE *)(comp_private_obj + 41) )
    {
      if ( v12 == 255 || *(unsigned __int8 *)(comp_private_obj + 44) == v12 )
      {
        v37 = *(_DWORD *)(comp_private_obj + 48);
        v38 = v37 == a4 || v12 != 255;
        v39 = v37 == a4;
        if ( v38 )
        {
          v63 = v39;
          wlan_objmgr_peer_release_ref(v36, 2u, v54, v55, v56, v57, v58, v59, v60, v61);
          wlan_objmgr_vdev_release_ref(v25, 2u, v64, v65, v66, v67, v68, v69, v70, v71, v72);
          return v63;
        }
      }
      if ( *(_BYTE *)(comp_private_obj + 41) != 1 )
        break;
    }
    next_active_peer_of_vdev = wlan_peer_get_next_active_peer_of_vdev(v25, (_QWORD *)(v25 + 192), v36, 2u);
    wlan_objmgr_peer_release_ref(v36, 2u, v41, v42, v43, v44, v45, v46, v47, v48);
    v36 = next_active_peer_of_vdev;
    if ( !next_active_peer_of_vdev )
      goto LABEL_17;
  }
  __break(0x5512u);
  if ( (v53 & 0x800000000000LL) == 0 )
    JUMPOUT(0x7158C4);
  return mlme_sap_twt_peer_is_cmd_in_progress(comp_private_obj, v50, v51, v52);
}
