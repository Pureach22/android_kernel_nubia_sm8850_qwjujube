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
  _QWORD *v17; // x8
  __int64 vdev_by_user; // x0
  __int64 v26; // x19
  __int64 v27; // x2
  char v28; // w0
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
  unsigned int v46; // w20
  const char *v47; // x2

  v17 = *(_QWORD **)(a1 + 24);
  if ( !v17 )
  {
    v47 = "%s: hdd_ctx is null";
LABEL_12:
    qdf_trace_msg(0x48u, 2u, v47, a9, a10, a11, a12, a13, a14, a15, a16, "wlan_cfg80211_tdls_send_mgmt_on_active_link");
    return 4294967274LL;
  }
  if ( !*v17 )
  {
    v47 = "%s: psoc is null";
    goto LABEL_12;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(
                   *(_QWORD *)(a1 + 52824),
                   0x57u,
                   (__int64)"wlan_cfg80211_tdls_send_mgmt_on_active_link");
  if ( !vdev_by_user )
  {
    v47 = "%s: vdev is null";
    goto LABEL_12;
  }
  v26 = vdev_by_user;
  v27 = a3;
  if ( (unsigned __int8)a3 == 10
    && (v28 = ucfg_tdls_discovery_on_going(vdev_by_user, a9, a10, a11, a12, a13, a14, a15, a16), v27 = a3,
                                                                                                 (v28 & 1) != 0) )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: discovery request is going",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wlan_cfg80211_tdls_send_mgmt_on_active_link");
    v46 = -11;
  }
  else
  {
    v46 = wlan_cfg80211_tdls_mgmt(v26, a2, v27, a4, a5, a6, a7, a8, a17);
  }
  wlan_objmgr_vdev_release_ref(v26, 0x57u, v37, v38, v39, v40, v41, v42, v43, v44, v45);
  return v46;
}
