__int64 __fastcall mlo_link_recfg_install_unicast_keys(__int64 a1)
{
  unsigned int v1; // w21
  unsigned int v2; // w19
  __int64 key; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w22
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x0
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  const char *v85; // x2
  unsigned int v86; // w1
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7

  v1 = *(unsigned __int8 *)(a1 + 168);
  v2 = *(unsigned __int8 *)(a1 + 93);
  wlan_crypto_aquire_lock();
  key = wlan_crypto_get_key(a1, 0, 0);
  if ( !key )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: crypto key not found",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "mlo_link_recfg_install_unicast_keys");
LABEL_5:
    v14 = wlan_crypto_get_key(a1, 0, 1u);
    if ( v14 )
    {
      if ( !*(_DWORD *)(v14 + 12) )
      {
        v13 = 1;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "mlo_link_recfg_install_unicast_keys");
    }
    v23 = wlan_crypto_get_key(a1, 0, 2u);
    if ( v23 )
    {
      if ( !*(_DWORD *)(v23 + 12) )
      {
        v13 = 2;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "mlo_link_recfg_install_unicast_keys");
    }
    v32 = wlan_crypto_get_key(a1, 0, 3u);
    if ( v32 )
    {
      if ( !*(_DWORD *)(v32 + 12) )
      {
        v13 = 3;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "mlo_link_recfg_install_unicast_keys");
    }
    v41 = wlan_crypto_get_key(a1, 0, 4u);
    if ( v41 )
    {
      if ( !*(_DWORD *)(v41 + 12) )
      {
        v13 = 4;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        "mlo_link_recfg_install_unicast_keys");
    }
    v50 = wlan_crypto_get_key(a1, 0, 5u);
    if ( v50 )
    {
      if ( !*(_DWORD *)(v50 + 12) )
      {
        v13 = 5;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        "mlo_link_recfg_install_unicast_keys");
    }
    v59 = wlan_crypto_get_key(a1, 0, 6u);
    if ( v59 )
    {
      if ( !*(_DWORD *)(v59 + 12) )
      {
        v13 = 6;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        v67,
        "mlo_link_recfg_install_unicast_keys");
    }
    v68 = wlan_crypto_get_key(a1, 0, 7u);
    if ( v68 )
    {
      if ( !*(_DWORD *)(v68 + 12) )
      {
        v13 = 7;
        goto LABEL_32;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: crypto key not found",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "mlo_link_recfg_install_unicast_keys");
    }
    wlan_crypto_release_lock();
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: No unicast key found for link_id %d",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "mlo_link_recfg_install_unicast_keys",
      v2);
    return mlo_disconnect();
  }
  if ( *(_DWORD *)(key + 12) )
    goto LABEL_5;
  v13 = 0;
LABEL_32:
  if ( (unsigned int)mlme_cm_osif_send_keys(a1, v13, 1) )
  {
    v85 = "%s: MLO: fail to send key for vdev_id %d link_id %d, key_idx %d, pairwise %d";
    v86 = 2;
  }
  else
  {
    v85 = "%s: MLO: send keys for vdev_id %d link_id %d, key_idx %d, pairwise %d";
    v86 = 8;
  }
  qdf_trace_msg(
    0x8Fu,
    v86,
    v85,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    "mlo_link_recfg_install_unicast_keys",
    v1,
    v2,
    v13,
    1);
  return wlan_crypto_release_lock();
}
