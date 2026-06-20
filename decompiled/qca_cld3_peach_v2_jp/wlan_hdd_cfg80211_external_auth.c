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
  void *v26; // x0
  __int64 v27; // x22
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  const void *v36; // x1
  unsigned int v37; // w19
  __int64 v38; // [xsp+28h] [xbp-38h] BYREF
  unsigned int v39; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int16 v40; // [xsp+34h] [xbp-2Ch]
  int v41; // [xsp+38h] [xbp-28h]
  __int16 v42; // [xsp+3Ch] [xbp-24h]
  _QWORD v43[3]; // [xsp+48h] [xbp-18h] BYREF

  v43[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  result = _osif_vdev_sync_op_start(a2, &v38, "wlan_hdd_cfg80211_external_auth");
  if ( (_DWORD)result )
  {
LABEL_17:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( a1 )
  {
    v40 = 0;
    v39 = 0;
    v43[0] = 0;
    v43[1] = 0;
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
                              *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
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
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
          *(unsigned __int16 *)(a3 + 48),
          *(unsigned __int8 *)(a3 + 4),
          *(unsigned __int8 *)(a3 + 5),
          *(unsigned __int8 *)(a3 + 6),
          *(unsigned __int8 *)(a3 + 9));
        v25 = *(_QWORD *)(a1 + 1552);
        qdf_mem_copy(&v39, (const void *)(a3 + 4), 6u);
        if ( *(_QWORD *)(a3 + 56) )
        {
          v26 = (void *)_qdf_mem_malloc(0x98u, "wlan_hdd_extauth_cache_pmkid", 32986);
          if ( v26 )
          {
            v27 = (__int64)v26;
            v42 = 0;
            v41 = 0;
            qdf_mem_copy(v26, (const void *)(a3 + 4), 6u);
            qdf_mem_copy((void *)(v27 + 6), *(const void **)(a3 + 56), 0x10u);
            if ( (unsigned int)wlan_hdd_set_pmksa_cache(a2 + 2688, v27) )
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: external_auth: Failed to cache PMKID",
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                "wlan_hdd_extauth_cache_pmkid");
            _qdf_mem_free(v27);
          }
          v36 = *(const void **)(a3 + 56);
          if ( v36 )
            qdf_mem_copy(v43, v36, 0x10u);
        }
        sme_handle_sae_msg(
          v25,
          *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
          *(unsigned __int8 *)(a3 + 48),
          v39 | ((unsigned __int64)v40 << 32),
          v43);
        v16 = 0;
      }
    }
    v37 = v16;
    _osif_vdev_sync_op_stop(v38, "wlan_hdd_cfg80211_external_auth");
    result = v37;
    goto LABEL_17;
  }
  __break(0x800u);
  if ( (v7 & 0x40000000) == 0 )
    JUMPOUT(0x300A04);
  return wlan_hdd_cfg80211_tx_control_port();
}
