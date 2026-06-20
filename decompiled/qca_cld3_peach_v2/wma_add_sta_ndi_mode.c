__int64 __fastcall wma_add_sta_ndi_mode(
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
  __int64 v13; // x25
  _QWORD *v14; // x23
  unsigned int v15; // w22
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  _DWORD *v33; // x8
  __int64 v34; // x1
  __int64 v35; // x4
  __int64 v36; // x5
  const char *v37; // x2
  __int64 v38; // x8
  _DWORD *v39; // x8
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w24
  unsigned int peer; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x8
  _DWORD *v59; // x8
  __int64 v60; // x1
  __int64 v61; // x8
  _DWORD *v62; // x8
  unsigned int v63; // w2
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char v73; // w8
  __int64 v74; // [xsp+0h] [xbp-10h]

  context = _cds_get_context(71, (__int64)"wma_add_sta_ndi_mode", a3, a4, a5, a6, a7, a8, a9, a10);
  v13 = a1[65];
  v14 = context;
  v15 = *(unsigned __int8 *)(a2 + 143);
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: vdev: %d, peer_mac_addr: %02x:%02x:%02x:**:**:%02x",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wma_add_sta_ndi_mode",
    *(unsigned __int8 *)(a2 + 143),
    *(unsigned __int8 *)(a2 + 9),
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned __int8 *)(a2 + 11),
    *(unsigned __int8 *)(a2 + 14));
  if ( !v14 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "cdp_find_peer_exist_on_vdev");
LABEL_19:
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v24, v25, v26, v27, v28, v29, v30, v31, "cdp_find_peer_exist");
    goto LABEL_20;
  }
  if ( *v14 && (v32 = *(_QWORD *)(*v14 + 72LL)) != 0 )
  {
    v33 = *(_DWORD **)(v32 + 24);
    if ( v33 )
    {
      v34 = *(unsigned __int8 *)(a2 + 143);
      if ( *(v33 - 1) != 454466150 )
        __break(0x8228u);
      if ( (((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v33)(v14, v34, a2 + 9) & 1) != 0 )
      {
        v35 = *(unsigned __int8 *)(a2 + 9);
        v36 = *(unsigned __int8 *)(a2 + 10);
        v37 = "%s: NDI peer already exists, peer_addr %02x:%02x:%02x:**:**:%02x";
LABEL_17:
        qdf_trace_msg(
          0x36u,
          2u,
          v37,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wma_add_sta_ndi_mode",
          v35,
          v36,
          *(unsigned __int8 *)(a2 + 11),
          *(unsigned __int8 *)(a2 + 14));
        v48 = 14;
        *(_DWORD *)(a2 + 112) = 14;
        goto LABEL_37;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "cdp_find_peer_exist_on_vdev");
  }
  if ( !*v14 )
    goto LABEL_19;
  v38 = *(_QWORD *)(*v14 + 72LL);
  if ( !v38 )
    goto LABEL_19;
  v39 = *(_DWORD **)(v38 + 16);
  if ( v39 )
  {
    if ( *(v39 - 1) != 454466150 )
      __break(0x8228u);
    if ( (((__int64 (__fastcall *)(_QWORD *, _QWORD, __int64))v39)(v14, 0, a2 + 9) & 1) != 0 )
    {
      v35 = *(unsigned __int8 *)(a2 + 9);
      v36 = *(unsigned __int8 *)(a2 + 10);
      v37 = "%s: peer exists on other vdev with peer_addr %02x:%02x:%02x:**:**:%02x";
      goto LABEL_17;
    }
  }
LABEL_20:
  peer = wma_create_peer(
           (__int64)a1,
           (_BYTE *)(a2 + 9),
           0,
           4u,
           *(unsigned __int8 *)(a2 + 143),
           0,
           0,
           v24,
           v25,
           v26,
           v27,
           v28,
           v29,
           v30,
           v31);
  if ( peer )
  {
    v48 = peer;
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to create peer for %02x:%02x:%02x:**:**:%02x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_add_sta_ndi_mode",
      *(unsigned __int8 *)(a2 + 9),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 11),
      *(unsigned __int8 *)(a2 + 14));
    *(_DWORD *)(a2 + 112) = v48;
    goto LABEL_37;
  }
  if ( !v14 || !*v14 || (v58 = *(_QWORD *)(*v14 + 72LL)) == 0 )
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "cdp_find_peer_exist_on_vdev");
LABEL_36:
    qdf_trace_msg(
      0x36u,
      2u,
      "%s: Failed to find peer handle using peer mac %02x:%02x:%02x:**:**:%02x",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "wma_add_sta_ndi_mode",
      *(unsigned __int8 *)(a2 + 9),
      *(unsigned __int8 *)(a2 + 10),
      *(unsigned __int8 *)(a2 + 11),
      *(unsigned __int8 *)(a2 + 14));
    v63 = *(unsigned __int8 *)(a2 + 143);
    *(_DWORD *)(a2 + 112) = 16;
    wma_remove_peer(a1, (const void *)(a2 + 9), v63, 0, v64, v65, v66, v67, v68, v69, v70, v71);
    v48 = *(_DWORD *)(a2 + 112);
    goto LABEL_37;
  }
  v59 = *(_DWORD **)(v58 + 24);
  if ( !v59 )
    goto LABEL_36;
  v60 = *(unsigned __int8 *)(a2 + 143);
  if ( *(v59 - 1) != 454466150 )
    __break(0x8228u);
  if ( (((__int64 (__fastcall *)(_QWORD *, __int64, __int64))v59)(v14, v60, a2 + 9) & 1) == 0 )
    goto LABEL_36;
  LODWORD(v74) = 2;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Moving peer %02x:%02x:%02x:**:**:%02x to state %d",
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    "wma_add_sta_ndi_mode",
    *(unsigned __int8 *)(a2 + 9),
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned __int8 *)(a2 + 11),
    *(unsigned __int8 *)(a2 + 14),
    v74);
  if ( *v14 && (v61 = *(_QWORD *)(*v14 + 72LL)) != 0 )
  {
    v62 = *(_DWORD **)(v61 + 40);
    if ( v62 )
    {
      if ( *(v62 - 1) != 1499005600 )
        __break(0x8228u);
      ((void (__fastcall *)(_QWORD *, __int64, __int64))v62)(v14, a2 + 9, 2);
    }
  }
  else
  {
    qdf_trace_msg(0x45u, 1u, "%s invalid instance", v40, v41, v42, v43, v44, v45, v46, v47, "cdp_peer_state_update");
  }
  v48 = 0;
  v73 = *(_BYTE *)(v13 + 488LL * v15 + 236);
  *(_DWORD *)(a2 + 112) = 0;
  *(_BYTE *)(a2 + 163) = v73;
LABEL_37:
  LODWORD(v74) = v48;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: Sending add sta rsp to umac (mac:%02x:%02x:%02x:**:**:%02x, status:%d)",
    v40,
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    "wma_add_sta_ndi_mode",
    *(unsigned __int8 *)(a2 + 9),
    *(unsigned __int8 *)(a2 + 10),
    *(unsigned __int8 *)(a2 + 11),
    *(unsigned __int8 *)(a2 + 14),
    v74);
  wma_send_msg_high_priority((__int64)a1, 0x1022u, a2, 0);
  return v48;
}
