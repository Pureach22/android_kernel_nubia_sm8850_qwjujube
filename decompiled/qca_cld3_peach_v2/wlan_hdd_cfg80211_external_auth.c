__int64 __fastcall wlan_hdd_cfg80211_external_auth(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // x0
  int v7; // w13
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 v26; // x0
  __int64 v27; // x8
  __int64 v28; // x22
  __int64 v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  int v38; // w9
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const void *v47; // x1
  unsigned int v48; // w19
  __int64 v49; // [xsp+0h] [xbp-60h]
  __int64 v50; // [xsp+8h] [xbp-58h]
  __int64 v51; // [xsp+28h] [xbp-38h] BYREF
  unsigned int v52; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int16 v53; // [xsp+34h] [xbp-2Ch]
  int v54; // [xsp+38h] [xbp-28h] BYREF
  unsigned __int16 v55; // [xsp+3Ch] [xbp-24h]
  _QWORD v56[3]; // [xsp+48h] [xbp-18h] BYREF

  v56[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v51 = 0;
  result = _osif_vdev_sync_op_start(a2, &v51, "wlan_hdd_cfg80211_external_auth");
  if ( (_DWORD)result )
  {
LABEL_20:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v53 = 0;
    v52 = 0;
    v56[0] = 0;
    v56[1] = 0;
    if ( (unsigned int)hdd_get_conparam(result) == 5 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Command not allowed in FTM mode",
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        "__wlan_hdd_cfg80211_external_auth");
      v16 = -1;
    }
    else if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                              *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
                              "__wlan_hdd_cfg80211_external_auth") )
    {
      v16 = -22;
    }
    else
    {
      v16 = _wlan_hdd_validate_context(a1 + 1536, "__wlan_hdd_cfg80211_external_auth");
      if ( !v16 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: vdev %d status: %d for peer %02x:%02x:%02x:**:**:%02x",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "__wlan_hdd_cfg80211_external_auth",
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
          *(unsigned __int16 *)(a3 + 48),
          *(unsigned __int8 *)(a3 + 4),
          *(unsigned __int8 *)(a3 + 5),
          *(unsigned __int8 *)(a3 + 6),
          *(unsigned __int8 *)(a3 + 9));
        v25 = *(_QWORD *)(a1 + 1552);
        qdf_mem_copy(&v52, (const void *)(a3 + 4), 6u);
        if ( *(_QWORD *)(a3 + 56) )
        {
          v26 = _qdf_mem_malloc(0x98u, "wlan_hdd_extauth_cache_pmkid", 32986);
          if ( v26 )
          {
            v27 = *(_QWORD *)(a2 + 2712);
            v28 = v26;
            v55 = 0;
            v29 = *(_QWORD *)(v27 + 16);
            v54 = 0;
            sme_pmkid_get_mld_addr(v29, a3 + 4, &v54);
            if ( v54 | v55 )
            {
              LODWORD(v50) = BYTE1(v54);
              LODWORD(v49) = (unsigned __int8)v54;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: bssid %02x:%02x:%02x:**:**:%02x new %02x:%02x:%02x:**:**:%02x",
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                "wlan_hdd_extauth_cache_pmkid",
                *(unsigned __int8 *)(a3 + 4),
                *(unsigned __int8 *)(a3 + 5),
                *(unsigned __int8 *)(a3 + 6),
                *(unsigned __int8 *)(a3 + 9),
                v49,
                v50,
                BYTE2(v54),
                HIBYTE(v55));
              v38 = v54;
              *(_WORD *)(v28 + 4) = v55;
              *(_DWORD *)v28 = v38;
            }
            else
            {
              qdf_mem_copy((void *)v28, (const void *)(a3 + 4), 6u);
            }
            qdf_mem_copy((void *)(v28 + 6), *(const void **)(a3 + 56), 0x10u);
            if ( (unsigned int)wlan_hdd_set_pmksa_cache(a2 + 2688, v28) )
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: external_auth: Failed to cache PMKID",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                "wlan_hdd_extauth_cache_pmkid");
            _qdf_mem_free(v28);
          }
          v47 = *(const void **)(a3 + 56);
          if ( v47 )
            qdf_mem_copy(v56, v47, 0x10u);
        }
        sme_handle_sae_msg(
          v25,
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
          *(unsigned __int8 *)(a3 + 48),
          v52 | ((unsigned __int64)v53 << 32),
          v56);
        v16 = 0;
      }
    }
    v48 = v16;
    _osif_vdev_sync_op_stop(v51, "wlan_hdd_cfg80211_external_auth");
    result = v48;
    goto LABEL_20;
  }
  __break(0x800u);
  if ( (v7 & 0x40000000) == 0 )
    JUMPOUT(0x3388C4);
  return wlan_hdd_cfg80211_tx_control_port();
}
