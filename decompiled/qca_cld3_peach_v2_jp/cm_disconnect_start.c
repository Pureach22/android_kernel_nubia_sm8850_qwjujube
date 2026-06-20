__int64 __fastcall cm_disconnect_start(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x0
  unsigned int v5; // w23
  __int64 v6; // x21
  _DWORD *v7; // x0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  unsigned int v26; // w20
  __int64 v27; // x0
  unsigned int v28; // w21
  unsigned int ref; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w22
  unsigned int v39; // w9
  __int64 v40; // x9
  unsigned int v41; // w0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x6
  bool v51; // cf
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w21
  unsigned int v62; // w20
  __int64 v63; // [xsp+8h] [xbp-38h] BYREF
  __int64 (__fastcall *v64)(); // [xsp+10h] [xbp-30h]
  __int64 v65; // [xsp+18h] [xbp-28h]
  __int64 v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+28h] [xbp-18h]
  __int64 v68; // [xsp+30h] [xbp-10h]
  __int64 v69; // [xsp+38h] [xbp-8h]

  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(*a1 + 152);
  if ( v4 )
  {
    v5 = a2[2];
    cm_vdev_scan_cancel(v4);
    mlme_cm_disconnect_start_ind(*a1, a2 + 1);
    v6 = *a1;
    v7 = (_DWORD *)_qdf_mem_malloc(0x30u, "cm_if_mgr_inform_disconnect_start", 277);
    if ( v7 )
    {
      v16 = (__int64)v7;
      *v7 = 0;
      if_mgr_deliver_event(v6, 2u, (__int64)v7, v8, v9, v10, v11, v12, v13, v14, v15);
      _qdf_mem_free(v16);
    }
    mlme_cm_osif_disconnect_start_ind(*a1, a2[2]);
    if ( v5 == 18 )
    {
      result = cm_sm_deliver_event(*a1, 15, 4, a2);
    }
    else
    {
      v27 = *a1;
      v67 = 0;
      v68 = 0;
      v65 = 0;
      v66 = 0;
      v28 = *(unsigned __int8 *)(v27 + 104);
      ref = wlan_objmgr_vdev_try_get_ref(v27, 0x4Du, v17, v18, v19, v20, v21, v22, v23, v24);
      if ( ref )
      {
        v38 = ref;
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: unable to get reference",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "cm_ser_disconnect_req",
          v28,
          *a2);
        result = v38;
      }
      else
      {
        v39 = *a2;
        LODWORD(v65) = 0;
        LODWORD(v63) = 24;
        HIDWORD(v63) = v39;
        v40 = *a1;
        LODWORD(v66) = 27000;
        v64 = cm_ser_disconnect_cb;
        v67 = v40;
        BYTE4(v65) = 2;
        v41 = wlan_serialization_request((unsigned int *)&v63, v30, v31, v32, v33, v34, v35, v36, v37);
        v50 = v41;
        v51 = v41 >= 2;
        result = 0;
        if ( v51 )
        {
          qdf_trace_msg(
            0x68u,
            2u,
            "%s: vdev %d cm_id 0x%x: ser cmd status %d",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "cm_ser_disconnect_req",
            v28,
            *a2,
            v50);
          wlan_objmgr_vdev_release_ref(*a1, 0x4Du, v52, v53, v54, v55, v56, v57, v58, v59, v60);
          result = 16;
        }
      }
    }
    if ( (_DWORD)result )
    {
      v61 = result;
      v62 = *a2;
      v66 = 0;
      v67 = 0;
      v64 = nullptr;
      v65 = 0;
      v63 = 0;
      qdf_mem_set(&v63, 0x28u, 0);
      if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(a1, v62, &v63) )
        cm_disconnect_complete(a1, (unsigned int *)&v63);
      result = v61;
    }
  }
  else
  {
    v26 = *a2;
    v66 = 0;
    v67 = 0;
    v64 = nullptr;
    v65 = 0;
    v63 = 0;
    qdf_mem_set(&v63, 0x28u, 0);
    if ( !(unsigned int)cm_fill_disconnect_resp_from_cm_id(a1, v26, &v63) )
      cm_disconnect_complete(a1, (unsigned int *)&v63);
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
