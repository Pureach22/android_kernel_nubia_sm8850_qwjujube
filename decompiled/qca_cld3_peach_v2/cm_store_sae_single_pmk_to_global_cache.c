__int64 __fastcall cm_store_sae_single_pmk_to_global_cache(int a1, __int64 a2, __int64 a3)
{
  unsigned int v6; // w22
  int param; // w20
  __int64 result; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x20
  double psk_pmk; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 pmksa; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // [xsp+0h] [xbp-30h] BYREF
  __int64 v44; // [xsp+8h] [xbp-28h]
  __int64 v45; // [xsp+10h] [xbp-20h]
  __int64 v46; // [xsp+18h] [xbp-18h]
  int v47; // [xsp+20h] [xbp-10h] BYREF
  __int16 v48; // [xsp+24h] [xbp-Ch]
  __int64 v49; // [xsp+28h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a3 + 168);
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v48 = 0;
  v47 = 0;
  param = wlan_crypto_get_param(a3, 7u);
  result = wlan_cm_roam_cfg_get_value(a1, v6, 25, (int)&v43);
  if ( (unsigned __int8)v44 == 1 && (param & 0x8000400) != 0 )
  {
    wlan_vdev_get_bss_peer_mac_for_pmksa(a3, (__int64)&v47, v9, v10, v11, v12, v13, v14, v15, v16);
    wlan_crypto_set_sae_single_pmk_bss_cap(a3, (__int64)&v47, 1);
    result = _qdf_mem_malloc(0x50u, "cm_store_sae_single_pmk_to_global_cache", 6118);
    if ( result )
    {
      v17 = result;
      psk_pmk = wlan_cm_get_psk_pmk(a2, v6, result, result + 64);
      pmksa = wlan_crypto_get_pmksa(a3, (__int64)&v47, psk_pmk, v19, v20, v21, v22, v23, v24, v25);
      if ( pmksa )
      {
        *(_WORD *)(v17 + 66) = *(_DWORD *)(pmksa + 124) * (unsigned int)*(unsigned __int8 *)(pmksa + 128) / 0x64;
        *(_QWORD *)(v17 + 72) = *(_QWORD *)(pmksa + 136);
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: spmk_ts:%ld spmk_timeout_prd:%d secs",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "cm_store_sae_single_pmk_to_global_cache",
          v43);
      }
      else
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: PMK entry not found for bss:%02x:%02x:%02x:**:**:%02x",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "cm_store_sae_single_pmk_to_global_cache",
          (unsigned __int8)v47,
          BYTE1(v47),
          BYTE2(v47),
          HIBYTE(v48),
          v43);
      }
      wlan_mlme_update_sae_single_pmk(a3, v17, v35, v36, v37, v38, v39, v40, v41, v42);
      qdf_mem_set((void *)v17, 0x50u, 0);
      result = _qdf_mem_free(v17);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
