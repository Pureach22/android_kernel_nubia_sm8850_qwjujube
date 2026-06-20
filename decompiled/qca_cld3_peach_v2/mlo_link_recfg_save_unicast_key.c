__int64 __fastcall mlo_link_recfg_save_unicast_key(
        __int64 *a1,
        __int64 a2,
        unsigned __int8 *a3,
        const void *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 assoc_link_vdev; // x0
  __int64 v18; // x23
  unsigned int v19; // w27
  const char *v20; // x2
  __int64 crypto_params; // x0
  int v23; // w8
  unsigned int v24; // w26
  unsigned int v25; // w24
  unsigned int v26; // w25
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
  _DWORD *key; // x27
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 ml_sta_link_key; // x28
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  char v62; // [xsp+Ch] [xbp-4h]

  if ( !a1 )
  {
    v20 = "%s: Link recfg ctx is null";
LABEL_9:
    qdf_trace_msg(0x8Fu, 2u, v20, a6, a7, a8, a9, a10, a11, a12, a13, "mlo_link_recfg_save_unicast_key");
    return 29;
  }
  if ( !a2 )
  {
    v20 = "%s: Vdev is null";
    goto LABEL_9;
  }
  assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(a2, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( !assoc_link_vdev )
  {
    v20 = "%s: assoc Vdev is null";
    goto LABEL_9;
  }
  v18 = assoc_link_vdev;
  if ( *(_DWORD *)(assoc_link_vdev + 16) )
    return 16;
  crypto_params = wlan_crypto_vdev_get_crypto_params(assoc_link_vdev);
  if ( !crypto_params )
  {
    v20 = "%s: crypto params is null";
    goto LABEL_9;
  }
  v23 = *(_DWORD *)(crypto_params + 4);
  v19 = 16;
  if ( v23 && (v23 & 0x20000) == 0 )
  {
    v24 = *(unsigned __int8 *)(v18 + 168);
    v25 = *(unsigned __int8 *)(v18 + 93);
    v26 = 0;
    v62 = 0;
    do
    {
      wlan_crypto_aquire_lock();
      key = (_DWORD *)wlan_crypto_get_key(v18, 0, v26);
      wlan_crypto_release_lock();
      if ( key && !key[3] )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: MLO: found unicast key for vdev_id %d link_id %d , key_idx %d",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "mlo_link_recfg_save_unicast_key",
          v24,
          v25,
          v26);
        wlan_crypto_aquire_lock();
        ml_sta_link_key = wlan_crypto_get_ml_sta_link_key(
                            *a1,
                            v26,
                            (__int64)a3,
                            a5,
                            v44,
                            v45,
                            v46,
                            v47,
                            v48,
                            v49,
                            v50,
                            v51);
        if ( !ml_sta_link_key )
        {
          wlan_crypto_release_lock();
          v53 = _qdf_mem_malloc(0x1B0u, "mlo_link_recfg_save_unicast_key", 6851);
          if ( !v53 )
          {
            v19 = 2;
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: malloc failed",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              "mlo_link_recfg_save_unicast_key");
            return v19;
          }
          ml_sta_link_key = v53;
          wlan_crypto_aquire_lock();
          v62 = 1;
        }
        qdf_mem_copy((void *)ml_sta_link_key, key, 0x1B0u);
        qdf_mem_copy((void *)(ml_sta_link_key + 16), a4, 6u);
        v19 = wlan_crypto_save_ml_sta_key(*a1, v26, ml_sta_link_key, a3, a5, v27, v28, v29, v30, v31, v32, v33, v34);
        wlan_crypto_release_lock();
        if ( v19 )
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Failed to save key",
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            "mlo_link_recfg_save_unicast_key");
          _qdf_mem_free(ml_sta_link_key);
          return v19;
        }
      }
      ++v26;
    }
    while ( v26 != 8 );
    if ( (v62 & 1) != 0 )
      return 0;
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: No key found for link_id %d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "mlo_link_recfg_save_unicast_key",
      v25);
    return 16;
  }
  return v19;
}
