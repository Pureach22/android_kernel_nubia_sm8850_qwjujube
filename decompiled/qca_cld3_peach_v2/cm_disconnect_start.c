__int64 __fastcall cm_disconnect_start(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x21
  unsigned int v5; // w23
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x21
  _DWORD *v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x22
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 result; // x0
  unsigned int v34; // w20
  __int64 v35; // x0
  unsigned int v36; // w21
  unsigned int ref; // w0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  unsigned int v46; // w22
  unsigned int v47; // w9
  __int64 v48; // x9
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x6
  bool v59; // cf
  unsigned int *v60; // x8
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  unsigned int v69; // w21
  unsigned int v70; // w20
  __int64 v71; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v72)(); // [xsp+10h] [xbp-30h]
  __int64 v73; // [xsp+18h] [xbp-28h]
  __int64 v74; // [xsp+20h] [xbp-20h]
  __int64 v75; // [xsp+28h] [xbp-18h]
  __int64 v76; // [xsp+30h] [xbp-10h]
  __int64 v77; // [xsp+38h] [xbp-8h]

  v77 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*a1 + 216);
  if ( v4 )
  {
    v5 = a2[2];
    v6 = mlo_link_recfg_abort_if_in_progress();
    if ( (wlan_vdev_mlme_is_mlo_vdev(*a1, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 && v5 != 18 )
      mlo_internal_disconnect_links(*a1);
    cm_vdev_scan_cancel(v4);
    mlme_cm_disconnect_start_ind(*a1, a2 + 1);
    v14 = *a1;
    v15 = (_DWORD *)_qdf_mem_malloc(0x38u, "cm_if_mgr_inform_disconnect_start", 277);
    if ( v15 )
    {
      v24 = (__int64)v15;
      *v15 = 0;
      if_mgr_deliver_event(v14, 2u, (__int64)v15, v16, v17, v18, v19, v20, v21, v22, v23);
      _qdf_mem_free(v24);
    }
    mlme_cm_osif_disconnect_start_ind(*a1, a2[2]);
    if ( v5 == 18 )
    {
      result = cm_sm_deliver_event(*a1, 15, 4, a2);
    }
    else
    {
      v35 = *a1;
      v75 = 0;
      v76 = 0;
      v73 = 0;
      v74 = 0;
      v36 = *(unsigned __int8 *)(v35 + 168);
      ref = wlan_objmgr_vdev_try_get_ref(v35, 0x4Du, v25, v26, v27, v28, v29, v30, v31, v32);
      if ( ref )
      {
        v46 = ref;
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: unable to get reference",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "cm_ser_disconnect_req",
          v36,
          *a2);
        result = v46;
      }
      else
      {
        v47 = *a2;
        LODWORD(v73) = 0;
        LODWORD(v71) = 24;
        HIDWORD(v71) = v47;
        v48 = *a1;
        LODWORD(v74) = 27000;
        v72 = cm_ser_disconnect_cb;
        v75 = v48;
        BYTE4(v73) = 2;
        v49 = wlan_serialization_request((unsigned int *)&v71, v38, v39, v40, v41, v42, v43, v44, v45);
        v58 = v49;
        v59 = v49 >= 2;
        result = 0;
        if ( v59 )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: ser cmd status %d",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "cm_ser_disconnect_req",
            v36,
            *a2,
            v58);
          wlan_objmgr_vdev_release_ref(*a1, 0x4Du, v60, v61, v62, v63, v64, v65, v66, v67, v68);
          result = 16;
        }
      }
    }
    if ( (_DWORD)result )
    {
      v69 = result;
      v70 = *a2;
      v74 = 0;
      v75 = 0;
      v72 = nullptr;
      v73 = 0;
      v71 = 0;
      qdf_mem_set(&v71, 0x28u, 0);
      if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(a1, v70, &v71) )
        cm_disconnect_complete(a1, (unsigned int *)&v71);
      result = v69;
    }
  }
  else
  {
    v34 = *a2;
    v74 = 0;
    v75 = 0;
    v72 = nullptr;
    v73 = 0;
    v71 = 0;
    qdf_mem_set(&v71, 0x28u, 0);
    if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(a1, v34, &v71) )
      cm_disconnect_complete(a1, (unsigned int *)&v71);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
