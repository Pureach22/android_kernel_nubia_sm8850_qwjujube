__int64 __fastcall cm_handle_disconnect_resp(__int64 a1)
{
  unsigned __int8 *v1; // x19
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 peer_disconnect_ies; // x0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int *v37; // x8
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 result; // x0
  unsigned int *v47; // x8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // [xsp+0h] [xbp-30h] BYREF
  __int64 v57; // [xsp+8h] [xbp-28h]
  __int64 v58; // [xsp+10h] [xbp-20h]
  __int64 v59; // [xsp+18h] [xbp-18h]
  __int64 v60; // [xsp+20h] [xbp-10h]
  __int64 v61; // [xsp+28h] [xbp-8h]

  v61 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
    goto LABEL_11;
  v1 = *(unsigned __int8 **)(a1 + 8);
  if ( !v1 )
    goto LABEL_11;
  v59 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  v56 = 0;
  v2 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
         *((_QWORD *)v1 + 1),
         *v1,
         77);
  if ( !v2 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d : vdev not found",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "cm_handle_disconnect_resp",
      *v1);
    _qdf_mem_free((__int64)v1);
    result = 4;
    goto LABEL_12;
  }
  v11 = v2;
  qdf_mem_set(&v56, 0x28u, 0);
  if ( (cm_get_active_disconnect_req(v11, (__int64)&v56, v12, v13, v14, v15, v16, v17, v18, v19) & 1) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Active disconnect not found for vdev %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "cm_handle_disconnect_resp",
      *v1);
    _qdf_mem_free((__int64)v1);
    wlan_objmgr_vdev_release_ref(v11, 0x4Du, v47, v48, v49, v50, v51, v52, v53, v54, v55);
LABEL_11:
    result = 16;
    goto LABEL_12;
  }
  if ( (_DWORD)v57 == 6 )
  {
    peer_disconnect_ies = mlme_get_peer_disconnect_ies(v11, v20, v21, v22, v23, v24, v25, v26, v27);
    if ( peer_disconnect_ies )
    {
      LODWORD(v59) = *(_DWORD *)peer_disconnect_ies;
      v60 = *(_QWORD *)(peer_disconnect_ies + 8);
    }
  }
  wlan_cm_disconnect_rsp(v11, (unsigned int *)&v56, v20, v21, v22, v23, v24, v25, v26, v27);
  mlme_free_peer_disconnect_ies(v11, v29, v30, v31, v32, v33, v34, v35, v36);
  wlan_objmgr_vdev_release_ref(v11, 0x4Du, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  _qdf_mem_free((__int64)v1);
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
