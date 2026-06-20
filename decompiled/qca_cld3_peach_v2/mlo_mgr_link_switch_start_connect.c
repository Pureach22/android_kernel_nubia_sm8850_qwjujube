__int64 __fastcall mlo_mgr_link_switch_start_connect(__int64 a1)
{
  __int64 v2; // x21
  __int64 v3; // x22
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 assoc_link_vdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  unsigned int v21; // w8
  unsigned __int8 *v22; // x23
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  unsigned int started; // w20
  __int64 v35; // x21
  __int64 v36; // x20
  const void *v37; // x1
  char v38; // w8
  int v39; // w9
  char v40; // w8
  int v41; // w8
  __int16 v42; // w10
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 cmpt_obj; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  size_t v60; // x2
  unsigned int bss_peer_mld_mac; // w0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  _QWORD s[125]; // [xsp+28h] [xbp-3E8h] BYREF

  s[124] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x3E0u);
  v2 = *(_QWORD *)(a1 + 1360);
  v3 = *(_QWORD *)(v2 + 3880);
  assoc_link_vdev = wlan_mlo_get_assoc_link_vdev(a1, v4, v5, v6, v7, v8, v9, v10, v11);
  if ( !assoc_link_vdev )
  {
    v32 = "%s: Assoc VDEV not found";
LABEL_17:
    qdf_trace_msg(0x8Fu, 2u, v32, v13, v14, v15, v16, v17, v18, v19, v20, "mlo_mgr_link_switch_start_connect");
    goto LABEL_18;
  }
  if ( !v2 )
    goto LABEL_16;
  v21 = *(unsigned __int8 *)(v3 + 146);
  if ( v21 > 0xE )
    goto LABEL_16;
  v22 = *(unsigned __int8 **)(v2 + 3880);
  if ( v22[6] != v21 )
  {
    if ( v22[54] != v21 )
    {
      if ( v22[102] == v21 )
      {
        v22 += 96;
        if ( v22 )
          goto LABEL_8;
      }
      goto LABEL_16;
    }
    v22 += 48;
  }
  if ( !v22 )
  {
LABEL_16:
    v32 = "%s: New link ID not found";
    goto LABEL_17;
  }
LABEL_8:
  if ( *(_DWORD *)v22 != *(_DWORD *)(a1 + 86) || *((unsigned __int16 *)v22 + 2) != *(unsigned __int16 *)(a1 + 90) )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MAC address not equal for the new Link ID VDEV: %02x:%02x:%02x:**:**:%02x, MLO_LINK: %02x:%02x:%02x:**:**:%02x",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_mgr_link_switch_start_connect",
      *(unsigned __int8 *)(a1 + 86),
      *(unsigned __int8 *)(a1 + 87),
      *(unsigned __int8 *)(a1 + 88),
      *(unsigned __int8 *)(a1 + 91),
      *v22,
      v22[1],
      v22[2],
      v22[5]);
LABEL_18:
    started = 4;
    goto LABEL_19;
  }
  v35 = *(_QWORD *)(v2 + 2224);
  v36 = assoc_link_vdev;
  qdf_mutex_acquire(v35 + 40);
  v37 = *(const void **)(v35 + 32);
  if ( !v37 )
  {
    qdf_mutex_release(v35 + 40);
    goto LABEL_18;
  }
  qdf_mem_copy(s, v37, 0x3E0u);
  qdf_mutex_release(v35 + 40);
  v38 = *(_BYTE *)(v3 + 146);
  *(_BYTE *)(a1 + 93) = v38;
  v39 = *(_DWORD *)(v3 + 156);
  BYTE1(s[101]) = v38;
  v40 = *(_BYTE *)(a1 + 168);
  HIDWORD(s[7]) = v39;
  LOBYTE(s[0]) = v40;
  v41 = *((_DWORD *)v22 + 6);
  v42 = *((_WORD *)v22 + 14);
  HIDWORD(s[0]) = 17;
  LODWORD(s[1]) = v41;
  WORD2(s[1]) = v42;
  *(_WORD *)((char *)&s[7] + 1) = v42;
  *(_DWORD *)((char *)&s[6] + 5) = v41;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v36, v43, v44, v45, v46, v47, v48, v49, v50);
  if ( cmpt_obj )
  {
    v60 = *(unsigned __int8 *)(cmpt_obj + 178);
    if ( *(_BYTE *)(cmpt_obj + 178) )
    {
      BYTE4(s[2]) = *(_BYTE *)(cmpt_obj + 178);
      qdf_mem_copy((char *)&s[2] + 5, (const void *)(cmpt_obj + 145), v60);
    }
    else
    {
      BYTE4(s[2]) = 0;
    }
  }
  bss_peer_mld_mac = wlan_vdev_get_bss_peer_mld_mac(v36, (char *)&s[101] + 2, v52, v53, v54, v55, v56, v57, v58, v59);
  if ( bss_peer_mld_mac )
  {
    started = bss_peer_mld_mac;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: Get MLD addr failed",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "mlo_mgr_link_switch_start_connect");
  }
  else
  {
    HIDWORD(s[9]) = 0;
    memcpy(&s[102], (const void *)(v35 + 1168), 0xB0u);
    mlo_allocate_and_copy_ies(s, *(_QWORD *)(v35 + 32));
    started = wlan_cm_start_connect(a1, (__int64)s);
    if ( !started )
    {
      mlo_update_connected_links_0(a1, 1);
      wlan_cm_free_connect_req_param((__int64)s);
      goto LABEL_20;
    }
    wlan_cm_free_connect_req_param((__int64)s);
  }
LABEL_19:
  qdf_trace_msg(
    0x8Fu,
    2u,
    "%s: VDEV %d link switch connect request failed",
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    "mlo_mgr_link_switch_start_connect",
    *(unsigned __int8 *)(a1 + 168));
  mlo_mgr_remove_link_switch_cmd(a1);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return started;
}
