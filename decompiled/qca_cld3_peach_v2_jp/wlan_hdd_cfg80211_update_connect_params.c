__int64 __fastcall wlan_hdd_cfg80211_update_connect_params(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 *v17; // x25
  unsigned int v18; // w19
  __int64 v19; // x23
  __int64 v20; // x10
  __int64 v21; // x9
  __int64 v22; // x0
  __int64 v23; // x1
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int8 *v33; // x24
  int fils_auth_type; // w0
  __int64 v35; // x4
  const char *v36; // x2
  size_t v37; // x2
  const void *v38; // x1
  unsigned __int8 *v39; // x0
  unsigned int updated; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w0
  __int64 v58; // x4
  const char *v59; // x2
  unsigned int v60; // w1
  const void *v61; // x1
  const void *v62; // x1
  __int64 v63; // [xsp+0h] [xbp-20h] BYREF
  const void *v64; // [xsp+8h] [xbp-18h] BYREF
  __int64 v65; // [xsp+10h] [xbp-10h]
  __int64 v66; // [xsp+18h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v63 = 0;
  result = _osif_vdev_sync_op_start(a2, &v63, "wlan_hdd_cfg80211_update_connect_params");
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( a1 )
  {
    v64 = nullptr;
    v65 = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: enter(%s)",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "__wlan_hdd_cfg80211_update_connect_params",
      a2 + 296);
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                         *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                         "__wlan_hdd_cfg80211_update_connect_params") )
      goto LABEL_5;
    v17 = (__int64 *)(a1 + 1536);
    if ( (unsigned int)_wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_update_connect_params") )
      goto LABEL_5;
    v19 = *(_QWORD *)(a1 + 1552);
    if ( (a4 & 1) != 0 )
    {
      v20 = *(_QWORD *)(a3 + 64);
      v21 = *(_QWORD *)(a2 + 55512);
      v22 = *v17;
      v65 = *(_QWORD *)(a3 + 56);
      v23 = *(unsigned __int8 *)(v21 + 8);
      LODWORD(v64) = v20;
      cm_update_session_assoc_ie(v22, v23, &v64);
    }
    if ( (a4 & 6) == 0 )
      goto LABEL_45;
    v24 = _qdf_mem_malloc(0x258u, "hdd_update_connect_params_fils_info", 32756);
    if ( !v24 )
    {
LABEL_5:
      v18 = -22;
LABEL_6:
      _osif_vdev_sync_op_stop(v63, "wlan_hdd_cfg80211_update_connect_params");
      result = v18;
LABEL_7:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v33 = (unsigned __int8 *)v24;
    *(_BYTE *)v24 = 1;
    if ( (a4 & 2) != 0 )
    {
      v35 = (unsigned int)(*(_DWORD *)(a3 + 328) + *(_DWORD *)(a3 + 344) + 1);
      *(_DWORD *)(v24 + 4) = v35;
      if ( (unsigned int)v35 >= 0xFE )
      {
        v36 = "%s: Key NAI Length %d";
        goto LABEL_38;
      }
      v37 = *(_QWORD *)(a3 + 328);
      if ( v37 )
      {
        v38 = *(const void **)(a3 + 320);
        if ( v38 )
        {
          qdf_mem_copy((void *)(v24 + 8), v38, v37);
          v39 = &v33[*(_QWORD *)(a3 + 328) + 8];
          *v39 = 64;
          qdf_mem_copy(v39 + 1, *(const void **)(a3 + 336), *(unsigned int *)(a3 + 344));
        }
      }
      *((_WORD *)v33 + 262) = *(_WORD *)(a3 + 352) + 1;
      v35 = *(unsigned int *)(a3 + 368);
      *((_DWORD *)v33 + 132) = v35;
      if ( (unsigned int)v35 >= 0x41 )
      {
        v36 = "%s: r_rk_length is invalid %d";
        goto LABEL_38;
      }
      if ( *(_QWORD *)(a3 + 368) )
      {
        v61 = *(const void **)(a3 + 360);
        if ( v61 )
          qdf_mem_copy(v33 + 532, v61, (unsigned int)v35);
      }
      v35 = *(unsigned int *)(a3 + 344);
      *((_DWORD *)v33 + 66) = v35;
      if ( (unsigned int)v35 >= 0x100 )
      {
        v36 = "%s: Invalid fils realm len %d";
        goto LABEL_38;
      }
      if ( *(_QWORD *)(a3 + 344) )
      {
        v62 = *(const void **)(a3 + 336);
        if ( v62 )
          qdf_mem_copy(v33 + 268, v62, (unsigned int)v35);
      }
    }
    if ( (a4 & 4) != 0 )
    {
      fils_auth_type = osif_cm_get_fils_auth_type(*(_DWORD *)(a3 + 48));
      if ( fils_auth_type == 3 )
      {
        v35 = *(unsigned int *)(a3 + 48);
        v36 = "%s: invalid auth type for fils %d";
LABEL_38:
        qdf_trace_msg(
          0x33u,
          2u,
          v36,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "hdd_update_connect_params_fils_info",
          v35);
        _qdf_mem_free((__int64)v33);
        goto LABEL_5;
      }
      *((_DWORD *)v33 + 149) = fils_auth_type;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: fils conn update: changed %x is_fils %d keyname nai len %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_update_connect_params_fils_info",
      a4,
      *v33,
      *((unsigned int *)v33 + 1));
    updated = ucfg_cm_update_fils_config(*v17, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL), (__int64)v33);
    if ( updated )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Update FILS connect params failed %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_update_connect_params_fils_info",
        updated);
    _qdf_mem_free((__int64)v33);
    if ( (*(_BYTE *)(a1 + 4800) & 1) == 0 )
    {
      v59 = "%s: FILS roaming support %d";
      v60 = 8;
      v58 = 0;
    }
    else
    {
LABEL_45:
      if ( !a4 )
        goto LABEL_32;
      v57 = sme_send_rso_connect_params(v19, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL));
      if ( !v57 )
        goto LABEL_32;
      v58 = v57;
      v59 = "%s: Update connect params to fw failed %d";
      v60 = 2;
    }
    qdf_trace_msg(
      0x33u,
      v60,
      v59,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "__wlan_hdd_cfg80211_update_connect_params",
      v58);
LABEL_32:
    v18 = 0;
    goto LABEL_6;
  }
  __break(0x800u);
  return wlan_hdd_cfg80211_disconnect();
}
