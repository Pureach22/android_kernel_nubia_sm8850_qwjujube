__int64 __fastcall wlan_hdd_cfg80211_get_key(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned __int8 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        _DWORD *a8)
{
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w19
  const char *v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  const char *v49; // x2
  __int64 vdev_by_user; // x0
  __int64 v51; // x22
  __int64 vdev_by_link_id; // x23
  int v53; // w21
  unsigned int param; // w0
  unsigned __int8 v55; // w3
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned int *v64; // x8
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  __int64 v81; // [xsp+0h] [xbp-40h] BYREF
  int v82; // [xsp+Ch] [xbp-34h] BYREF
  _QWORD v83[3]; // [xsp+10h] [xbp-30h] BYREF
  __int64 v84; // [xsp+28h] [xbp-18h]
  __int64 v85; // [xsp+30h] [xbp-10h]
  __int64 v86; // [xsp+38h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v81 = 0;
  result = _osif_vdev_sync_op_start(a2, &v81, "wlan_hdd_cfg80211_get_key");
  if ( !(_DWORD)result )
  {
    v82 = 0;
    v22 = qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "__wlan_hdd_cfg80211_get_key");
    if ( (unsigned int)hdd_get_conparam(v22) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "__wlan_hdd_cfg80211_get_key");
      v31 = -22;
    }
    else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                              *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                              "__wlan_hdd_cfg80211_get_key") )
    {
      v31 = -22;
    }
    else
    {
      v32 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Device_mode %s(%d)",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "__wlan_hdd_cfg80211_get_key",
        v32,
        *(unsigned int *)(a2 + 2728));
      v84 = 0;
      v85 = 0;
      if ( a4 < 8u )
      {
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 55520), 6, "wlan_key_get_link_vdev");
        if ( vdev_by_user )
        {
          v51 = vdev_by_user;
          if ( (wlan_vdev_mlme_is_mlo_vdev(vdev_by_user, v41, v42, v43, v44, v45, v46, v47, v48) & 1) == 0
            || (vdev_by_link_id = mlo_get_vdev_by_link_id(v51, a3, 6),
                _hdd_objmgr_put_vdev_by_user(v51, 6, "wlan_key_get_link_vdev"),
                (v51 = vdev_by_link_id) != 0) )
          {
            v53 = 1;
            param = wlan_crypto_get_param(v51, 1u);
            sme_fill_enc_type(&v82, param);
            if ( (unsigned int)(v82 - 1) <= 0xD )
              v53 = dword_AF750C[v82 - 1];
            v55 = *(_BYTE *)(v51 + 168);
            HIDWORD(v84) = v53;
            qdf_mtrace(51, 51, 0x1Fu, v55, v53);
            memset(v83, 0, sizeof(v83));
            if ( *(a8 - 1) != -867534714 )
              __break(0x8233u);
            v56 = ((double (__fastcall *)(__int64, _QWORD *))a8)(a7, v83);
            if ( (wlan_vdev_mlme_is_mlo_vdev(v51, v56, v57, v58, v59, v60, v61, v62, v63) & 1) != 0 )
              wlan_objmgr_vdev_release_ref(v51, 6u, v64, v65, v66, v67, v68, v69, v70, v71, v72);
            else
              _hdd_objmgr_put_vdev_by_user(v51, 6, "wlan_key_put_link_vdev");
            qdf_trace_msg(0x33u, 8u, "%s: exit", v73, v74, v75, v76, v77, v78, v79, v80, "__wlan_hdd_cfg80211_get_key");
            v31 = 0;
            goto LABEL_21;
          }
        }
        v49 = "%s: Invalid vdev for link_id :%d";
      }
      else
      {
        v49 = "%s: Invalid key index: %d";
      }
      qdf_trace_msg(0x33u, 2u, v49, v41, v42, v43, v44, v45, v46, v47, v48, "__wlan_hdd_cfg80211_get_key");
      v31 = -22;
    }
LABEL_21:
    _osif_vdev_sync_op_stop(v81, "wlan_hdd_cfg80211_get_key");
    result = v31;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
