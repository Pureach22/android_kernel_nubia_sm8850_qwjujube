__int64 __fastcall wlan_t2lm_update_peer_mapping_for_add_link(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 first_vdev_by_ml_peer; // x0
  __int64 v11; // x19
  __int64 bsspeer; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w22
  const char *v31; // x2
  __int64 result; // x0
  unsigned int *v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // [xsp+0h] [xbp-40h] BYREF
  __int64 v59; // [xsp+8h] [xbp-38h]
  __int64 v60; // [xsp+10h] [xbp-30h]
  __int64 v61; // [xsp+18h] [xbp-28h]
  __int64 v62; // [xsp+20h] [xbp-20h]
  __int64 v63; // [xsp+28h] [xbp-18h]
  __int64 v64; // [xsp+30h] [xbp-10h]
  __int64 v65; // [xsp+38h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  LODWORD(v64) = 0;
  v62 = 0;
  v63 = 0;
  v60 = 0;
  v61 = 0;
  v58 = 0;
  v59 = 0;
  if ( !a1 )
  {
    v31 = "%s: ml peer is null";
LABEL_8:
    qdf_trace_msg(
      0x99u,
      2u,
      v31,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_t2lm_update_peer_mapping_for_add_link",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65);
    result = 29;
    goto LABEL_15;
  }
  first_vdev_by_ml_peer = mlo_get_first_vdev_by_ml_peer(a1);
  if ( !first_vdev_by_ml_peer )
  {
    v31 = "%s: VDEV is null";
    goto LABEL_8;
  }
  v11 = first_vdev_by_ml_peer;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(first_vdev_by_ml_peer, 0x5Au);
  if ( bsspeer )
  {
    v21 = bsspeer;
    if ( *(_BYTE *)(a1 + 328) == 1 )
    {
      qdf_trace_msg(
        0x99u,
        8u,
        "%s: Already default mapping",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "wlan_t2lm_update_peer_mapping_for_add_link",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65);
      v30 = 0;
    }
    else
    {
      wlan_t2lm_clear_peer_negotiation(bsspeer, v13, v14, v15, v16, v17, v18, v19, v20);
      *(_WORD *)(a1 + 216) = 0;
      LODWORD(v58) = 2;
      BYTE4(v58) = 1;
      BYTE1(v64) = 0;
      qdf_mem_copy((void *)(a1 + 324), &v58, 0x34u);
      v30 = wlan_send_tid_to_link_mapping(v11, a1 + 324, v42, v43, v44, v45, v46, v47, v48, v49);
      if ( v30 )
        qdf_trace_msg(
          0x99u,
          2u,
          "%s: sending t2lm wmi failed",
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          "wlan_t2lm_update_peer_mapping_for_add_link");
      wlan_mlo_dev_t2lm_notify_link_update(v11, a1 + 324, v50, v51, v52, v53, v54, v55, v56, v57);
    }
    wlan_objmgr_peer_release_ref(v21, 0x5Au, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      2u,
      "%s: peer is null",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wlan_t2lm_update_peer_mapping_for_add_link",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65);
    v30 = 29;
  }
  wlan_objmgr_vdev_release_ref(v11, 0x5Au, v33, v34, v35, v36, v37, v38, v39, v40, v41);
  result = v30;
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
