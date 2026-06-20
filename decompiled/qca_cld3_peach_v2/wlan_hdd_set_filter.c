__int64 __fastcall wlan_hdd_set_filter(__int64 *a1, unsigned __int8 *a2)
{
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  int v19; // w4
  __int64 v20; // x0
  __int64 v21; // x1
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x19
  unsigned int v31; // w4
  const char *v32; // x2
  __int64 v34; // x0
  __int64 v35; // x24
  unsigned __int64 v36; // x23
  unsigned __int8 *v37; // x28
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
  __int64 v54; // x9
  __int16 v55; // w8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  size_t v72; // x27
  __int64 v73; // x1
  unsigned int v74; // w20
  __int64 v75; // [xsp+0h] [xbp-10h]
  __int64 v76; // [xsp+0h] [xbp-10h]
  __int64 v77; // [xsp+8h] [xbp-8h]
  __int64 v78; // [xsp+8h] [xbp-8h]

  if ( (ucfg_pmo_is_pkt_filter_enabled(*a1) & 1) == 0 )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: Packet filtering disabled in ini",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "wlan_hdd_set_filter");
    return 0;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Packet Filter Request : FA %d params %d",
    v3,
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    "wlan_hdd_set_filter",
    *a2,
    a2[2]);
  v19 = *a2;
  if ( v19 == 2 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Clear Packet Filter Request for Id: %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_set_filter",
      a2[1]);
    v34 = _qdf_mem_malloc(0x14u, "wlan_hdd_set_filter", 219);
    if ( v34 )
    {
      v30 = v34;
      *(_BYTE *)(v34 + 4) = a2[1];
      if ( (unsigned int)ucfg_pmo_clear_pkt_filter() )
      {
        v32 = "%s: Failure to execute Clear Filter";
        goto LABEL_25;
      }
LABEL_27:
      v74 = 0;
LABEL_28:
      _qdf_mem_free(v30);
      return v74;
    }
    return 2;
  }
  if ( v19 != 1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Packet Filter Request: Invalid %d",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "wlan_hdd_set_filter");
    return 4294967274LL;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Set Packet Filter Request for Id: %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "wlan_hdd_set_filter",
    a2[1]);
  v20 = _qdf_mem_malloc(0x134u, "wlan_hdd_set_filter", 116);
  if ( !v20 )
    return 2;
  v30 = v20;
  *(_BYTE *)v20 = a2[1];
  v31 = a2[2];
  if ( v31 >= 5 )
  {
    v32 = "%s: Number of Params exceed Max limit %d";
    goto LABEL_25;
  }
  *(_DWORD *)(v20 + 8) = v31;
  *(_DWORD *)(v20 + 12) = 0;
  *(_DWORD *)(v20 + 4) = 1;
  if ( !a2[2] )
  {
LABEL_23:
    if ( (unsigned int)ucfg_pmo_set_pkt_filter() )
    {
      v32 = "%s: Failure to execute Set Filter";
LABEL_25:
      qdf_trace_msg(0x33u, 2u, v32, v22, v23, v24, v25, v26, v27, v28, v29, "wlan_hdd_set_filter");
LABEL_26:
      v74 = 4;
      goto LABEL_28;
    }
    goto LABEL_27;
  }
  v35 = 0;
  v36 = 0;
  v37 = a2 + 10;
  while ( v35 != 140 )
  {
    v54 = v30 + v35;
    *(_DWORD *)(v54 + 28) = *(v37 - 7);
    *(_DWORD *)(v54 + 32) = *(v37 - 6);
    *(_BYTE *)(v54 + 38) = *(v37 - 5);
    v55 = *(v37 - 4);
    *(_BYTE *)(v54 + 39) = 0;
    *(_WORD *)(v54 + 36) = v55;
    if ( *(v37 - 5) >= 0xC9u )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Invalid data offset %u for param %d (max = %d)",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "wlan_hdd_set_filter");
      goto LABEL_26;
    }
    if ( *(v37 - 4) >= 9u )
    {
      v32 = "%s: Error invalid data length %d";
      goto LABEL_25;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Proto %d Comp Flag %d Filter Type %d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wlan_hdd_set_filter",
      *(v37 - 7),
      *(v37 - 6),
      *(unsigned int *)(v30 + 4));
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Data Offset %d Data Len %d",
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      "wlan_hdd_set_filter",
      *(v37 - 5),
      *(v37 - 4));
    if ( *(v37 - 4) >= 9u )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Error invalid data length %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "wlan_hdd_set_filter");
      goto LABEL_26;
    }
    memcpy((void *)(v30 + v35 + 40), v37 - 3, *(v37 - 4));
    v72 = *(v37 - 4);
    if ( v72 >= 9 && (wlan_hdd_set_filter___already_done_13 & 1) == 0 )
    {
      v73 = *(v37 - 4);
      wlan_hdd_set_filter___already_done_13 = 1;
      _warn_printk(
        "memcpy: detected field-spanning write (size %zu) of single %s (size %zu)\n",
        v73,
        "field \"&pmo_set_pkt_fltr_req->params_data[i].data_mask\" at ../vendor/qcom/opensource/wlan/qcacld-3.0/core/hdd/"
        "src/wlan_hdd_packet_filter.c:183",
        8u);
      __break(0x800u);
    }
    memcpy((void *)(v30 + v35 + 48), v37 + 5, v72);
    LODWORD(v77) = v37[2];
    LODWORD(v75) = v37[1];
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: CData %d CData %d CData %d CData %d CData %d CData %d",
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      "wlan_hdd_set_filter",
      *(v37 - 3),
      *(v37 - 2),
      *(v37 - 1),
      *v37,
      v75,
      v77);
    LODWORD(v78) = v37[10];
    LODWORD(v76) = v37[9];
    v20 = qdf_trace_msg(
            0x33u,
            8u,
            "%s: MData %d MData %d MData %d MData %d MData %d MData %d",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "wlan_hdd_set_filter",
            v37[5],
            v37[6],
            v37[7],
            v37[8],
            v76,
            v78);
    ++v36;
    v35 += 28;
    v37 += 20;
    if ( v36 >= a2[2] )
      goto LABEL_23;
  }
  __break(0x5512u);
  return hdd_disable_default_pkt_filters(v20, v21);
}
