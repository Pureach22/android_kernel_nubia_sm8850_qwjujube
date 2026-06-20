__int64 __fastcall sme_stop_roaming(
        _QWORD *a1,
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
  unsigned int v15; // w23
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x22
  unsigned int *v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int *v36; // x8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7

  if ( (unsigned __int8)a2 <= 5u && a1[2153] + 96LL * (unsigned __int8)a2 )
  {
    v15 = (unsigned __int8)a2;
    v17 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1[2694], a2, 77);
    if ( v17 )
    {
      v26 = v17;
      if ( wlan_cm_is_vdev_roaming(v17, v18, v19, v20, v21, v22, v23, v24, v25) )
      {
        mlme_set_rso_pending_disable_req_bitmap(a1[2694], a2, a4, 0);
        wlan_objmgr_vdev_release_ref(v26, 0x4Du, v36, v37, v38, v39, v40, v41, v42, v43, v44);
        return 0;
      }
      else
      {
        wlan_objmgr_vdev_release_ref(v26, 0x4Du, v27, v28, v29, v30, v31, v32, v33, v34, v35);
        return wlan_cm_disable_rso(a1[2695], a2, a4, a3, v46, v47, v48, v49, v50, v51, v52, v53);
      }
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: vdev object is NULL for vdev %d",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "sme_stop_roaming",
        v15);
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(0x34u, 2u, "%s: ROAM: incorrect vdev ID %d", a5, a6, a7, a8, a9, a10, a11, a12, "sme_stop_roaming");
    return 16;
  }
}
