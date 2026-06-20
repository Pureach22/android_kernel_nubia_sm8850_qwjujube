__int64 __fastcall wma_peer_sta_kickout(
        __int64 a1,
        char a2,
        unsigned __int8 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 peer; // x0
  __int64 v25; // x19
  __int64 v26; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  unsigned __int8 *v35; // x25
  __int64 v36; // x22
  int v37; // w24
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x4
  __int64 v47; // x5
  __int64 v48; // x6
  __int64 v49; // x7
  int v50; // w8
  int v51; // w9
  int v52; // w10
  int v53; // w11
  const char *v54; // x2
  __int64 result; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  int v64; // w25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // [xsp+38h] [xbp-18h] BYREF
  int v74; // [xsp+40h] [xbp-10h]
  __int64 v75; // [xsp+48h] [xbp-8h]

  v75 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(54, (__int64)"wma_peer_sta_kickout", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !a1 || (v23 = (__int64)context) == 0 )
  {
    v54 = "%s: null wma or psoc";
LABEL_10:
    qdf_trace_msg(0x36u, 2u, v54, v15, v16, v17, v18, v19, v20, v21, v22, "wma_peer_sta_kickout");
    result = 4294967274LL;
    goto LABEL_17;
  }
  peer = wlan_objmgr_get_peer(a1, a2, a3, 8u);
  if ( !peer )
  {
    v54 = "%s: Failed to get peer";
    goto LABEL_10;
  }
  v25 = peer;
  v26 = _qdf_mem_malloc(0x14u, "wma_peer_sta_kickout", 512);
  if ( !v26 )
  {
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: QDF MEM Alloc Failed for struct del_sta_context",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wma_peer_sta_kickout");
    wlan_objmgr_peer_release_ref(v25, 8u, v56, v57, v58, v59, v60, v61, v62, v63);
    result = 4294967284LL;
    goto LABEL_17;
  }
  v35 = *(unsigned __int8 **)(v25 + 88);
  v36 = v26;
  v37 = v35[104];
  *(_BYTE *)(v26 + 18) = -96;
  *(_BYTE *)v26 = 0;
  *(_BYTE *)(v26 + 1) = v37;
  *(_WORD *)(v26 + 16) = 1;
  qdf_mem_copy((void *)(v26 + 10), a3, 6u);
  qdf_mem_copy((void *)(v36 + 4), v35 + 74, 6u);
  if ( !a3 )
  {
    v48 = 0;
    v46 = 0;
    v47 = 0;
    v49 = 0;
    if ( v35 != (unsigned __int8 *)-74LL )
      goto LABEL_7;
LABEL_13:
    v52 = 0;
    v50 = 0;
    v51 = 0;
    v53 = 0;
    goto LABEL_14;
  }
  v46 = *a3;
  v47 = a3[1];
  v48 = a3[2];
  v49 = a3[5];
  if ( v35 == (unsigned __int8 *)-74LL )
    goto LABEL_13;
LABEL_7:
  v50 = v35[74];
  v51 = v35[75];
  v52 = v35[76];
  v53 = v35[79];
LABEL_14:
  qdf_trace_msg(
    0x36u,
    4u,
    "%s: STA kickout for %02x:%02x:%02x:**:**:%02x, on mac %02x:%02x:%02x:**:**:%02x, vdev %d, reason:%d",
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    "wma_peer_sta_kickout",
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v37,
    *(unsigned __int16 *)(v36 + 16));
  v64 = *(unsigned __int16 *)(v36 + 16);
  v74 = 0;
  v73 = 0;
  qdf_mem_set(&v73, 0xCu, 0);
  LODWORD(v73) = v64;
  BYTE2(v74) = v37;
  if ( a3 )
    qdf_mem_copy((char *)&v73 + 4, a3, 6u);
  host_diag_event_report_payload(2873, 12, &v73);
  wma_send_msg(v23, 0x13C1u, v36, 0);
  wlan_objmgr_peer_release_ref(v25, 8u, v65, v66, v67, v68, v69, v70, v71, v72);
  result = 0;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
