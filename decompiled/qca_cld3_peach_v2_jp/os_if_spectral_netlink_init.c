__int64 __fastcall os_if_spectral_netlink_init(
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
  const char *v10; // x2
  unsigned int v11; // w1
  __int64 v12; // x0
  __int64 result; // x0
  _DWORD *v14; // x8
  _QWORD v15[9]; // [xsp+8h] [xbp-48h] BYREF

  v15[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v10 = "%s: PDEV is NULL!";
LABEL_12:
    v11 = 2;
    goto LABEL_13;
  }
  if ( wlan_spectral_is_feature_disabled_pdev(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
  {
    v10 = "%s: Spectral feature is disabled";
    v11 = 8;
LABEL_13:
    result = qdf_trace_msg(0x48u, v11, v10, a2, a3, a4, a5, a6, a7, a8, a9, "os_if_spectral_netlink_init");
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(a1 + 80);
  if ( !v12 || (result = wlan_objmgr_psoc_get_comp_private_obj(v12, 0x13u)) == 0 )
  {
    v10 = "%s: Spectral context is NULL!";
    goto LABEL_12;
  }
  v15[0] = os_if_spectral_prep_skb;
  v15[1] = os_if_spectral_nl_bcast_msg;
  v15[2] = os_if_spectral_nl_unicast_msg;
  v15[3] = os_if_spectral_free_skb;
  v15[4] = wlan_cfg80211_get_nl80211_chwidth;
  v15[5] = wlan_cfg80211_get_phy_ch_width;
  v14 = *(_DWORD **)(result + 192);
  v15[6] = os_if_spectral_nl_reset_tbuff;
  v15[7] = os_if_spectral_netlink_get_buff_size;
  if ( v14 )
  {
    if ( *(v14 - 1) != 1392633911 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD *))v14)(a1, v15);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
