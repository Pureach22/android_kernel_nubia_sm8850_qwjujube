__int64 __fastcall wlan_cfg80211_tdls_mgmt_mlo(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 a3,
        char a4,
        char a5,
        int a6,
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
        char a17)
{
  __int64 vdev_by_user; // x0
  __int64 v25; // x19
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x21
  unsigned int *v35; // x8
  __int64 v37; // x20
  unsigned int v38; // w20
  unsigned int *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7

  if ( !*(_QWORD *)(a1 + 24) )
  {
    v37 = jiffies;
    if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: hdd_ctx is null",
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        a16,
        "wlan_cfg80211_tdls_mgmt_mlo");
      wlan_cfg80211_tdls_mgmt_mlo___last_ticks = v37;
    }
    return 4294967274LL;
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a1 + 52824), 0x57u, (__int64)"wlan_cfg80211_tdls_mgmt_mlo");
  if ( !vdev_by_user )
    return 4294967274LL;
  v25 = vdev_by_user;
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v34 = jiffies;
    v35 = (unsigned int *)(wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 - jiffies);
    if ( wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: STA is not connected",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "wlan_cfg80211_tdls_mgmt_mlo");
      wlan_cfg80211_tdls_mgmt_mlo___last_ticks_38 = v34;
    }
    _hdd_objmgr_put_vdev_by_user(
      v25,
      0x57u,
      (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
      v35,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33);
    return 4294967285LL;
  }
  else
  {
    v38 = wlan_cfg80211_tdls_mgmt(v25, a2, a3, a4, a5, a6, a7, a8, a17);
    _hdd_objmgr_put_vdev_by_user(
      v25,
      0x57u,
      (__int64)"wlan_cfg80211_tdls_mgmt_mlo",
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47);
    return v38;
  }
}
