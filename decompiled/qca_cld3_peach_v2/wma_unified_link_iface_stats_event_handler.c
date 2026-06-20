__int64 __fastcall wma_unified_link_iface_stats_event_handler(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  _DWORD *v21; // x22
  __int64 v22; // x24
  __int64 v23; // x4
  __int64 v24; // x25
  __int64 *v25; // x23
  unsigned int v26; // w8
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 v30; // x5
  _QWORD *v31; // x26
  void *v32; // x0
  __int64 v33; // x20
  int v34; // w8
  __int64 v35; // x8
  __int64 v36; // x9
  __int64 v37; // x9
  __int64 v38; // x10
  __int64 v39; // x11
  __int64 v40; // x9
  __int64 v41; // x10
  __int64 v42; // x11
  __int64 v43; // x9
  __int64 v44; // x11
  __int64 v45; // x10
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  char v54; // w0
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x5
  __int64 v64; // x6
  __int64 v65; // x7
  const char *v66; // x2
  int v67; // w9
  int v68; // w10
  unsigned int v69; // w8
  __int64 v70; // x9
  __int64 v71; // x10
  __int64 v72; // x12
  __int64 v73; // x13
  __int64 v74; // x11
  __int64 v75; // x13
  __int64 v76; // x12
  int v77; // w8
  unsigned int v78; // w8
  __int64 v79; // x9
  __int64 v80; // x11
  __int64 v81; // x12
  int v82; // w10
  __int64 *v83; // x8
  int v84; // w9
  __int64 v85; // x8
  void (__fastcall *v86)(__int64, __int64, __int64, __int64); // x8
  __int64 v87; // x0
  __int64 v88; // x3

  context = _cds_get_context(53, (__int64)"wma_unified_link_iface_stats_event_handler", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v27 = "%s: NULL mac ptr. Exiting";
LABEL_13:
    v28 = 8;
LABEL_16:
    qdf_trace_msg(0x36u, v28, v27, v13, v14, v15, v16, v17, v18, v19, v20, "wma_unified_link_iface_stats_event_handler");
    return 4294967274LL;
  }
  if ( !context[1628] )
  {
    v27 = "%s: HDD callback is null";
    goto LABEL_13;
  }
  if ( !a2 )
  {
    v27 = "%s: Invalid stats event";
    goto LABEL_15;
  }
  v21 = *(_DWORD **)a2;
  if ( !*(_QWORD *)a2
    || (v22 = *(_QWORD *)(a2 + 16)) == 0
    || (v23 = *(unsigned int *)(v22 + 40), v24 = *(_QWORD *)(a2 + 32), v25 = *(__int64 **)(a2 + 48), (_DWORD)v23)
    && !v24
    || (v26 = v21[3]) != 0 && !v25 )
  {
    v27 = "%s: Invalid param_tlvs for Iface Stats";
LABEL_15:
    v28 = 2;
    goto LABEL_16;
  }
  v30 = *(unsigned int *)(a2 + 40);
  if ( (unsigned int)v23 > 4 || (unsigned int)v23 > (unsigned int)v30 )
  {
    v66 = "%s: Excess data received from firmware num_ac %d, param_tlvs->num_ac %d";
LABEL_28:
    qdf_trace_msg(
      0x36u,
      2u,
      v66,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "wma_unified_link_iface_stats_event_handler",
      v23,
      v30);
    return 4294967274LL;
  }
  v30 = *(unsigned int *)(a2 + 56);
  if ( v26 > 8 || v26 > (unsigned int)v30 )
  {
    v66 = "%s: Excess num offload stats recvd from fw: %d, um_iface_offload_stats: %d";
    v23 = v26;
    goto LABEL_28;
  }
  v31 = context;
  v32 = (void *)_qdf_mem_malloc(0x2A4u, "wma_unified_link_iface_stats_event_handler", 3116);
  if ( !v32 )
    return 4294967284LL;
  v33 = (__int64)v32;
  qdf_mem_set(v32, 0x2A4u, 0);
  *(_DWORD *)v33 = 2;
  *(_DWORD *)(v33 + 8) = v21[1];
  *(_BYTE *)(v33 + 4) = v21[2];
  v34 = *(_DWORD *)(v22 + 32);
  *(_DWORD *)(v33 + 12) = 0;
  *(_DWORD *)(v33 + 20) = v34;
  *(_DWORD *)(v33 + 24) = 0;
  v36 = *(_QWORD *)(v22 + 8);
  v35 = *(_QWORD *)(v22 + 16);
  *(_QWORD *)(v33 + 108) = *(_QWORD *)v22;
  *(_QWORD *)(v33 + 124) = v35;
  *(_QWORD *)(v33 + 116) = v36;
  v37 = *(_QWORD *)(v22 + 40);
  v38 = *(_QWORD *)(v22 + 24);
  v39 = *(_QWORD *)(v22 + 32);
  *(_QWORD *)(v33 + 156) = *(_QWORD *)(v22 + 48);
  *(_QWORD *)(v33 + 148) = v37;
  *(_QWORD *)(v33 + 140) = v39;
  *(_QWORD *)(v33 + 132) = v38;
  v40 = *(_QWORD *)(v22 + 72);
  v41 = *(_QWORD *)(v22 + 56);
  v42 = *(_QWORD *)(v22 + 64);
  *(_QWORD *)(v33 + 188) = *(_QWORD *)(v22 + 80);
  *(_QWORD *)(v33 + 180) = v40;
  *(_QWORD *)(v33 + 172) = v42;
  *(_QWORD *)(v33 + 164) = v41;
  v44 = *(_QWORD *)(v22 + 96);
  v43 = *(_QWORD *)(v22 + 104);
  v45 = *(_QWORD *)(v22 + 88);
  *(_DWORD *)(v33 + 220) = *(_DWORD *)(v22 + 112);
  *(_QWORD *)(v33 + 212) = v43;
  *(_QWORD *)(v33 + 204) = v44;
  *(_QWORD *)(v33 + 196) = v45;
  v54 = wmi_service_enabled(*a1, 0xACu, v46, v47, v48, v49, v50, v51, v52, v53);
  v63 = *(unsigned int *)(v33 + 128);
  if ( (v54 & 1) != 0 )
  {
    v64 = *(unsigned int *)(v33 + 132);
    v65 = *(unsigned int *)(v33 + 136);
  }
  else
  {
    v63 = (unsigned int)(v63 - 96);
    v64 = (unsigned int)(*(_DWORD *)(v33 + 132) - 96);
    v65 = (unsigned int)(*(_DWORD *)(v33 + 136) - 96);
    *(_DWORD *)(v33 + 128) = v63;
    *(_DWORD *)(v33 + 132) = v64;
    *(_DWORD *)(v33 + 136) = v65;
  }
  v67 = *(_DWORD *)(v33 + 112);
  *(_DWORD *)(v33 + 36) = *(_DWORD *)(v22 + 44);
  v68 = (unsigned __int8)*(_DWORD *)(v22 + 108);
  *(_BYTE *)(v33 + 89) = *(_DWORD *)(v22 + 108);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: db2dbm: %d, rssi_mgmt: %d, rssi_data: %d, rssi_ack: %d, beacon_rx %u, time_slice_duty_cycle %u",
    v55,
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    "wma_unified_link_iface_stats_event_handler",
    v54 & 1,
    v63,
    v64,
    v65,
    v67,
    v68);
  if ( *(_DWORD *)(v22 + 40) )
  {
    v69 = 0;
    v70 = v33 + 224;
    do
    {
      ++v69;
      *(_QWORD *)v70 = *(_QWORD *)v24;
      v71 = *(_QWORD *)(v24 + 32);
      v72 = *(_QWORD *)(v24 + 8);
      v73 = *(_QWORD *)(v24 + 16);
      *(_QWORD *)(v70 + 24) = *(_QWORD *)(v24 + 24);
      *(_QWORD *)(v70 + 32) = v71;
      *(_QWORD *)(v70 + 8) = v72;
      *(_QWORD *)(v70 + 16) = v73;
      v75 = *(_QWORD *)(v24 + 48);
      v74 = *(_QWORD *)(v24 + 56);
      LODWORD(v71) = *(_DWORD *)(v24 + 64);
      v76 = *(_QWORD *)(v24 + 40);
      v24 += 68;
      *(_DWORD *)(v70 + 64) = v71;
      *(_QWORD *)(v70 + 48) = v75;
      *(_QWORD *)(v70 + 56) = v74;
      *(_QWORD *)(v70 + 40) = v76;
      v70 += 68;
    }
    while ( v69 < *(_DWORD *)(v22 + 40) );
  }
  v77 = v21[3];
  *(_DWORD *)(v33 + 496) = v77;
  if ( v77 )
  {
    v78 = 0;
    v79 = v33 + 500;
    do
    {
      v81 = *v25;
      v80 = v25[1];
      ++v78;
      v82 = *((_DWORD *)v25 + 4);
      v25 = (__int64 *)((char *)v25 + 20);
      *(_DWORD *)(v79 + 16) = v82;
      *(_QWORD *)v79 = v81;
      *(_QWORD *)(v79 + 8) = v80;
      v79 += 20;
    }
    while ( v78 < v21[3] );
  }
  v83 = *(__int64 **)(a2 + 64);
  if ( v83 )
  {
    v84 = *((_DWORD *)v83 + 2);
    v85 = *v83;
    *(_DWORD *)(v33 + 668) = v84;
    *(_QWORD *)(v33 + 660) = v85;
  }
  *(_BYTE *)(v33 + 672) = v21[2];
  v86 = (void (__fastcall *)(__int64, __int64, __int64, __int64))v31[1628];
  v87 = v31[1604];
  v88 = v31[1627];
  if ( *((_DWORD *)v86 - 1) != -2006529613 )
    __break(0x8228u);
  v86(v87, 4338, v33, v88);
  _qdf_mem_free(v33);
  return 0;
}
