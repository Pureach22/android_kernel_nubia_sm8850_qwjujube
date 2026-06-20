__int64 __fastcall dp_soc_srng_init(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  const char *v10; // x2
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  const char *v19; // x3
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w20
  unsigned __int64 v63; // x20
  __int64 v64; // x21
  __int64 v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  __int64 (__fastcall *v74)(_QWORD); // x8

  dp_enable_verbose_debug(a1);
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed for wbm_desc_rel_ring";
LABEL_5:
    v19 = "dp_soc_srng_init";
LABEL_6:
    qdf_trace_msg(0x7Cu, 2u, v10, v2, v3, v4, v5, v6, v7, v8, v9, v19, a1);
    goto LABEL_7;
  }
  dp_ssr_dump_srng_register("wbm_desc_rel_ring", a1 + 7768, -1);
  wlan_minidump_log(
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    *(_QWORD *)(a1 + 7776),
    *(unsigned int *)(a1 + 7808),
    *(_QWORD *)(a1 + 16));
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed - reo_exception";
    goto LABEL_5;
  }
  dp_ssr_dump_srng_register("reo_exception_ring", a1 + 6400, -1);
  wlan_minidump_log(
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    *(_QWORD *)(a1 + 6408),
    *(unsigned int *)(a1 + 6440),
    *(_QWORD *)(a1 + 16));
  v29 = *(_QWORD *)(a1 + 40);
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed for reo_reinject_ring";
LABEL_17:
    v19 = "dp_srng_init_non_bn_rings";
    goto LABEL_6;
  }
  dp_ssr_dump_srng_register("reo_reinject_ring", a1 + 6480, -1);
  wlan_minidump_log(
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    *(_QWORD *)(a1 + 6488),
    *(unsigned int *)(a1 + 6520),
    *(_QWORD *)(a1 + 16));
  wlan_cfg_get_rx_rel_ring_id(v29);
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed for rx_rel_ring";
    goto LABEL_17;
  }
  dp_ssr_dump_srng_register("rx_rel_ring", a1 + 6720, -1);
  wlan_minidump_log(
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    *(_QWORD *)(a1 + 6728),
    *(unsigned int *)(a1 + 6760),
    *(_QWORD *)(a1 + 16));
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed for reo_cmd_ring";
    goto LABEL_17;
  }
  dp_ssr_dump_srng_register("reo_cmd_ring", a1 + 6560, -1);
  wlan_minidump_log(
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    *(_QWORD *)(a1 + 6568),
    *(unsigned int *)(a1 + 6600),
    *(_QWORD *)(a1 + 16));
  hal_reo_init_cmd_ring(*(_QWORD *)(a1 + 1128), *(_QWORD *)(a1 + 6560));
  *(_QWORD *)(a1 + 13208) = 0;
  *(_DWORD *)(a1 + 13224) = 0;
  *(_QWORD *)(a1 + 13216) = a1 + 13208;
  *(_QWORD *)(a1 + 13232) = 0;
  if ( (unsigned int)dp_srng_init(a1) )
  {
    v10 = "%s: %pK: dp_srng_init failed for reo_status_ring";
    goto LABEL_17;
  }
  dp_ssr_dump_srng_register("reo_status_ring", a1 + 6640, -1);
  wlan_minidump_log(
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    *(_QWORD *)(a1 + 6648),
    *(unsigned int *)(a1 + 6680),
    *(_QWORD *)(a1 + 16));
  if ( *(_BYTE *)(a1 + 7201) )
  {
    v62 = 0;
    while ( !(unsigned int)dp_init_tx_ring_pair_by_index(a1, v62) )
    {
      if ( *(unsigned __int8 *)(a1 + 7201) <= (unsigned int)(unsigned __int8)++v62 )
        goto LABEL_22;
    }
    goto LABEL_7;
  }
LABEL_22:
  if ( (wlan_cfg_is_ipa_enabled(*(_QWORD *)(a1 + 40)) & 1) != 0 && (unsigned int)dp_init_tx_ring_pair_by_index(a1, 4) )
  {
LABEL_7:
    ((void (__fastcall *)(__int64))dp_soc_srng_deinit)(a1);
    return 16;
  }
  qdf_event_create((_DWORD *)(a1 + 18632));
  if ( *(_BYTE *)(a1 + 12896) )
  {
    v63 = 0;
    v64 = a1 + 5760;
    while ( 1 )
    {
      if ( (unsigned int)dp_srng_init(a1) )
      {
        v10 = "%s: %pK: dp_srng_init failed for reo_dest_ringn";
        goto LABEL_5;
      }
      v65 = dp_ssr_dump_srng_register("reo_dest_ring", v64, v63);
      if ( v63 == 8 )
        break;
      wlan_minidump_log(
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        *(_QWORD *)(v64 + 8),
        *(unsigned int *)(v64 + 40),
        *(_QWORD *)(a1 + 16));
      ++v63;
      v64 += 80;
      if ( v63 >= *(unsigned __int8 *)(a1 + 12896) )
        goto LABEL_29;
    }
    __break(0x5512u);
    return dp_soc_disable_unused_mac_intr_mask(v65);
  }
  else
  {
LABEL_29:
    v74 = *(__int64 (__fastcall **)(_QWORD))(a1 + 1184);
    if ( !v74 )
      return 0;
    if ( *((_DWORD *)v74 - 1) != -1941278151 )
      __break(0x8228u);
    result = v74(a1);
    if ( (_DWORD)result )
    {
      v10 = "%s: %pK: dp_srng_init failed for arch rings";
      goto LABEL_5;
    }
  }
  return result;
}
