__int64 __fastcall wlan_hdd_cfg80211_get_key(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _DWORD *a8)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  const char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 vdev_by_user; // x0
  __int64 v49; // x22
  int v50; // w21
  unsigned int param; // w0
  unsigned __int8 v52; // w3
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w19
  __int64 v62; // [xsp+0h] [xbp-40h] BYREF
  int v63; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v64[3]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v65; // [xsp+28h] [xbp-18h]
  __int64 v66; // [xsp+30h] [xbp-10h]
  __int64 v67; // [xsp+38h] [xbp-8h]

  v67 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62 = 0;
  result = _osif_vdev_sync_op_start(a2, &v62, "wlan_hdd_cfg80211_get_key");
  if ( !(_DWORD)result )
  {
    v63 = 0;
    v21 = qdf_trace_msg(0x33u, 8u, "%s: enter", v13, v14, v15, v16, v17, v18, v19, v20, "__wlan_hdd_cfg80211_get_key");
    if ( (unsigned int)hdd_get_conparam(v21) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "__wlan_hdd_cfg80211_get_key");
    }
    else if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                               *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                               "__wlan_hdd_cfg80211_get_key") )
    {
      v30 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Device_mode %s(%d)",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "__wlan_hdd_cfg80211_get_key",
        v30,
        *(unsigned int *)(a2 + 2728));
      v65 = 0;
      v66 = 0;
      if ( a4 < 8u )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55512), 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v49 = vdev_by_user;
          v50 = 1;
          param = wlan_crypto_get_param(vdev_by_user, 1u);
          sme_fill_enc_type(&v63, param);
          if ( (unsigned int)(v63 - 1) <= 0xD )
            v50 = dword_A0556C[v63 - 1];
          v52 = *(_BYTE *)(v49 + 104);
          HIDWORD(v65) = v50;
          qdf_mtrace(51, 51, 0x1Fu, v52, v50);
          memset(v64, 0, sizeof(v64));
          if ( *(a8 - 1) != -867534714 )
            __break(0x8233u);
          ((void (__fastcall *)(__int64, _QWORD *))a8)(a7, v64);
          _hdd_objmgr_put_vdev_by_user(v49, 6, "wlan_key_put_link_vdev");
          qdf_trace_msg(0x33u, 8u, "%s: exit", v53, v54, v55, v56, v57, v58, v59, v60, "__wlan_hdd_cfg80211_get_key");
          v61 = 0;
          goto LABEL_16;
        }
        v47 = "%s: Invalid vdev for link_id :%d";
      }
      else
      {
        v47 = "%s: Invalid key index: %d";
      }
      qdf_trace_msg(0x33u, 2u, v47, v39, v40, v41, v42, v43, v44, v45, v46, "__wlan_hdd_cfg80211_get_key");
    }
    v61 = -22;
LABEL_16:
    _osif_vdev_sync_op_stop(v62, "wlan_hdd_cfg80211_get_key");
    result = v61;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
