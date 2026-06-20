__int64 __fastcall wlan_cfg80211_tdls_send_mgmt_on_active_link(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7,
        __int64 a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        int a17)
{
  _QWORD *v17; // x22
  __int64 vdev_by_user; // x0
  __int64 v24; // x19
  char is_mlo_vdev; // w20
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x27
  unsigned int active_vdev_id; // w28
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x2
  char v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned int *v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  unsigned int v63; // w21
  const char *v64; // x2
  unsigned int *v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int *v75; // x8
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7

  v17 = *(_QWORD **)(a1 + 24);
  if ( !v17 )
  {
    v64 = "%s: hdd_ctx is null";
LABEL_13:
    qdf_trace_msg(0x48u, 2u, v64, a9, a10, a11, a12, a13, a14, a15, a16, "wlan_cfg80211_tdls_send_mgmt_on_active_link");
    return 4294967274LL;
  }
  if ( !*v17 )
  {
    v64 = "%s: psoc is null";
    goto LABEL_13;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(a1 + 52832),
                   0x57u,
                   (__int64)"wlan_cfg80211_tdls_send_mgmt_on_active_link");
  if ( !vdev_by_user )
  {
    v64 = "%s: vdev is null";
    goto LABEL_13;
  }
  v24 = vdev_by_user;
  is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, a9, a10, a11, a12, a13, a14, a15, a16);
  v34 = v24;
  if ( (is_mlo_vdev & 1) == 0 )
    goto LABEL_7;
  active_vdev_id = (unsigned __int8)ucfg_mlo_get_active_vdev_id(v24);
  if ( active_vdev_id == 255 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: vdev id is not valid",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_cfg80211_tdls_send_mgmt_on_active_link");
LABEL_22:
    wlan_objmgr_vdev_release_ref(v24, 0x57u, v75, v76, v77, v78, v79, v80, v81, v82, v83);
    return 4294967274LL;
  }
  v34 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *v17,
          active_vdev_id,
          87);
  if ( !v34 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: vdev is not found for id %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_cfg80211_tdls_send_mgmt_on_active_link",
      active_vdev_id);
    goto LABEL_22;
  }
LABEL_7:
  v44 = a3;
  if ( (unsigned __int8)a3 == 10
    && (v45 = ucfg_tdls_discovery_on_going(v34, v26, v27, v28, v29, v30, v31, v32, v33), v44 = a3, (v45 & 1) != 0) )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: discovery request is going",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_cfg80211_tdls_send_mgmt_on_active_link");
    v63 = -11;
  }
  else
  {
    v63 = wlan_cfg80211_tdls_mgmt(v34, a2, v44, a4, a5, a6, a7, a8, a17);
  }
  wlan_objmgr_vdev_release_ref(v24, 0x57u, v54, v55, v56, v57, v58, v59, v60, v61, v62);
  if ( (is_mlo_vdev & 1) != 0 )
    wlan_objmgr_vdev_release_ref(v34, 0x57u, v66, v67, v68, v69, v70, v71, v72, v73, v74);
  return v63;
}
