__int64 __fastcall policy_mgr_roam_invoke_on_sta_for_mcc(_QWORD *a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned __int8 v7; // w19
  unsigned int v8; // w20
  __int64 v9; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x24
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 assoc_link_vdev; // x0
  unsigned int v29; // w24
  int roam_state; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+0h] [xbp-10h] BYREF
  __int16 v50; // [xsp+4h] [xbp-Ch]
  __int64 v51; // [xsp+8h] [xbp-8h]

  v7 = a2;
  v8 = a2;
  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = ((__int64 (__fastcall *)(_QWORD))wlan_objmgr_get_vdev_by_id_from_psoc)(*a1);
  if ( v9 )
  {
    v18 = v9;
    if ( (wlan_vdev_mlme_is_mlo_vdev(v9, v10, v11, v12, v13, v14, v15, v16, v17) & 1) != 0 )
    {
      assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(v18);
      if ( assoc_link_vdev )
        v8 = *(unsigned __int8 *)(assoc_link_vdev + 168);
    }
    wlan_objmgr_vdev_release_ref(v18, 0x18u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
    v29 = (unsigned __int8)v8;
  }
  else
  {
    v29 = v7;
    qdf_trace_msg(
      0x4Fu,
      2u,
      "%s: vdev %d object is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "policy_mgr_get_assoc_link_vdev_id",
      v7);
  }
  roam_state = mlme_get_roam_state(*a1, v8);
  qdf_trace_msg(
    0x4Fu,
    8u,
    "%s: STA(%d) + SAP(%d) in MCC, try roam on sta vdev %d (RSO enabled %d)",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "policy_mgr_roam_invoke_on_sta_for_mcc",
    a3,
    a4,
    v29,
    roam_state == 2);
  result = mlme_get_roam_state(*a1, v8);
  if ( (_DWORD)result == 2 )
  {
    v40 = a1[1];
    v50 = -1;
    v49 = -1;
    result = wlan_cm_roam_invoke(v40, v8, &v49, 0, 20);
    if ( (_DWORD)result )
      result = qdf_trace_msg(
                 0x4Fu,
                 2u,
                 "%s: Vdev %d roam invoke failed",
                 v41,
                 v42,
                 v43,
                 v44,
                 v45,
                 v46,
                 v47,
                 v48,
                 "policy_mgr_roam_invoke_on_sta_for_mcc",
                 v7);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
