__int64 __fastcall wlan_hdd_send_key_vdev(
        __int64 a1,
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
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w22
  __int64 link_info_by_vdev; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 result; // x0
  const char *v36; // x2
  _QWORD *v37; // x25
  __int64 bsspeer; // x0
  __int64 v39; // x24
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int param; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  _QWORD *v57; // x0
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x8
  _DWORD *v67; // x8
  _QWORD *v68; // x0
  __int64 v69; // x25
  __int64 vdev_by_user; // x0
  __int64 v71; // x23
  int v72; // w24
  __int64 v73; // x0
  __int64 v74; // [xsp+0h] [xbp-10h] BYREF
  __int64 v75; // [xsp+8h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  WORD2(v74) = 0;
  LODWORD(v74) = 0;
  context = _cds_get_context(51, (__int64)"wlan_hdd_send_key_vdev", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
  {
    v36 = "%s: hdd_ctx is NULL";
LABEL_6:
    qdf_trace_msg(0x33u, 2u, v36, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_send_key_vdev", v74, v75);
LABEL_8:
    result = 29;
    goto LABEL_9;
  }
  v25 = *(unsigned __int8 *)(a1 + 168);
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: adapter is NULL for vdev %d",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_hdd_send_key_vdev",
      v25,
      v74,
      v75);
    goto LABEL_8;
  }
  if ( *(_DWORD *)(a1 + 16) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: vdev opmode is not STA mode",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_hdd_send_key_vdev",
      v74,
      v75);
    result = 4;
    goto LABEL_9;
  }
  v37 = (_QWORD *)link_info_by_vdev;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 6u);
  if ( !bsspeer )
  {
    v36 = "%s: Peer is null return";
    goto LABEL_6;
  }
  v39 = bsspeer;
  qdf_mem_copy(&v74, (const void *)(bsspeer + 48), 6u);
  wlan_objmgr_peer_release_ref(v39, 6u, v40, v41, v42, v43, v44, v45, v46, v47);
  param = wlan_crypto_get_param(a1, 4u);
  if ( (a3 & 1) != 0 )
    v49 = wma_set_peer_ucast_cipher(&v74, (unsigned int)(1 << a4), param);
  v57 = _cds_get_context(71, (__int64)"wlan_hdd_send_key_vdev", v49, v50, v51, v52, v53, v54, v55, v56);
  if ( v57 && *v57 && (v66 = *(_QWORD *)(*v57 + 72LL)) != 0 )
  {
    v67 = *(_DWORD **)(v66 + 176);
    if ( v67 )
    {
      if ( *(v67 - 1) != -187609570 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, _QWORD))v67)(v57, v25);
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      "cdp_peer_flush_frags",
      v74,
      v75);
  }
  v68 = v37;
  v69 = *v37;
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v68, 6, "wlan_hdd_add_key_sta");
  if ( vdev_by_user
    && (v71 = vdev_by_user,
        v72 = wlan_cfg80211_crypto_add_key(vdev_by_user, (__int64)&v74, (a3 & 1) == 0, a2, 1),
        v73 = _hdd_objmgr_put_vdev_by_user(v71, 6, "wlan_hdd_add_key_sta"),
        !v72) )
  {
    if ( *(_BYTE *)(v69 + 52208) == 1 )
    {
      ((void (__fastcall *)(__int64))wlan_hdd_send_mode_change_event)(v73);
      *(_BYTE *)(v69 + 52208) = 0;
    }
    wma_update_set_key(v25, a3 & 1, a2, &v74, a4);
    result = 0;
  }
  else
  {
    result = 16;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
