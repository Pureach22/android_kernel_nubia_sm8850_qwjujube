__int64 __fastcall cm_check_and_prepare_roam_req(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 v6; // x8
  __int64 v7; // x22
  int v8; // w24
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20
  __int64 result; // x0
  char v36; // w0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 cmpt_obj; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  size_t v54; // x2
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 v63; // x4
  __int64 v64; // x6
  __int64 v65; // x0
  __int64 v66; // x22
  char is_macaddr_equal_3; // w0
  int *v68; // x8
  __int16 v69; // w9
  int v70; // w8
  int v71; // w9
  __int64 v72; // [xsp+0h] [xbp-60h]
  __int64 v73; // [xsp+8h] [xbp-58h]
  __int64 v74; // [xsp+10h] [xbp-50h]
  __int64 v75; // [xsp+18h] [xbp-48h]
  int v76; // [xsp+20h] [xbp-40h] BYREF
  unsigned __int16 v77; // [xsp+24h] [xbp-3Ch]
  int v78; // [xsp+28h] [xbp-38h] BYREF
  __int16 v79; // [xsp+2Ch] [xbp-34h]
  _QWORD v80[4]; // [xsp+30h] [xbp-30h] BYREF
  char v81; // [xsp+50h] [xbp-10h]
  __int64 v82; // [xsp+58h] [xbp-8h]

  v82 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(*a1 + 152);
  if ( v6 )
    v7 = *(_QWORD *)(v6 + 80);
  else
    v7 = 0;
  v77 = 0;
  v76 = 0;
  memset(v80, 0, sizeof(v80));
  v81 = 0;
  if ( (cm_roam_offload_enabled(v7) & 1) != 0 )
  {
    v8 = *(_DWORD *)(a2 + 68);
    if ( !v8 )
      v8 = *(_DWORD *)(a2 + 72);
    if ( !cm_is_connect_req_reassoc(a2 + 8) )
      goto LABEL_23;
    wlan_vdev_get_bss_peer_mac(*a1, &v76, v9, v10, v11, v12, v13, v14, v15, v16);
    if ( *(_DWORD *)(a2 + 22) != v76 || *(unsigned __int16 *)(a2 + 26) != v77 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: BSSID didn't matched: bssid: %02x:%02x:%02x:**:**:%02x prev bssid: %02x:%02x:%02x:**:**:%02x",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "cm_check_and_prepare_roam_req",
        (unsigned __int8)v76,
        BYTE1(v76),
        BYTE2(v76),
        HIBYTE(v77),
        *(unsigned __int8 *)(a2 + 22),
        *(unsigned __int8 *)(a2 + 23),
        *(unsigned __int8 *)(a2 + 24),
        *(unsigned __int8 *)(a2 + 27));
      LODWORD(v75) = *(unsigned __int8 *)(a2 + 27);
      LODWORD(v74) = *(unsigned __int8 *)(a2 + 24);
      LODWORD(v73) = *(unsigned __int8 *)(a2 + 23);
      LODWORD(v72) = *(unsigned __int8 *)(a2 + 22);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: BSSID didn't matched: bss mld: %02x:%02x:%02x:**:**:%02x prev bssid: %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "cm_check_and_prepare_roam_req",
        0,
        0,
        0,
        0,
        v72,
        v73,
        v74,
        v75);
LABEL_23:
      result = 16;
      goto LABEL_24;
    }
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*a1, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( !cmpt_obj || (v54 = *(unsigned __int8 *)(cmpt_obj + 162), !*(_BYTE *)(cmpt_obj + 162)) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: failed to get ssid",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "cm_check_and_prepare_roam_req");
      goto LABEL_23;
    }
    LOBYTE(v80[0]) = *(_BYTE *)(cmpt_obj + 162);
    qdf_mem_copy((char *)v80 + 1, (const void *)(cmpt_obj + 129), v54);
    v63 = LOBYTE(v80[0]);
    v64 = *(unsigned __int8 *)(a2 + 28);
    if ( LOBYTE(v80[0]) != (_DWORD)v64 )
    {
LABEL_21:
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: SSID didn't matched: self ssid: \"%.*s\", ssid in req: \"%.*s\"",
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        "cm_check_and_prepare_roam_req",
        v63,
        (char *)v80 + 1,
        v64,
        a2 + 29);
      goto LABEL_23;
    }
    if ( (unsigned int)qdf_mem_cmp((char *)v80 + 1, (const void *)(a2 + 29), LOBYTE(v80[0])) )
    {
      v63 = LOBYTE(v80[0]);
      v64 = *(unsigned __int8 *)(a2 + 28);
      goto LABEL_21;
    }
    v65 = _qdf_mem_malloc(0x380u, "cm_check_and_prepare_roam_req", 105);
    *a3 = v65;
    if ( v65 )
    {
      v66 = v65;
      v79 = 0;
      v78 = 0;
      is_macaddr_equal_3 = qdf_is_macaddr_equal_3(a2 + 16, &v78);
      v68 = (int *)(a2 + 61);
      if ( (is_macaddr_equal_3 & 1) == 0 )
        v68 = (int *)(a2 + 16);
      v69 = *((_WORD *)v68 + 2);
      v70 = *v68;
      *(_WORD *)(v66 + 44) = v69;
      *(_DWORD *)(v66 + 40) = v70;
      v71 = *(_DWORD *)(a2 + 22);
      *(_WORD *)(v66 + 50) = *(_WORD *)(a2 + 26);
      *(_DWORD *)(v66 + 46) = v71;
      cm_fill_vdev_crypto_params(a1, a2 + 8);
      *(_DWORD *)(v66 + 52) = v8;
      *(_DWORD *)(v66 + 36) = 1;
      qdf_mem_copy((void *)(v66 + 56), (const void *)(a2 + 80), 0x50u);
      cm_free_connect_req_mem((_QWORD *)a2);
      _qdf_mem_free(a2 - 24);
      result = 0;
    }
    else
    {
      result = 2;
    }
  }
  else
  {
    v34 = jiffies;
    if ( cm_is_roam_enabled___last_ticks - jiffies + 125 < 0 )
    {
      v36 = cm_roam_offload_enabled(v7);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: All roam mode (offload %d, host %d) are disabled",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "cm_is_roam_enabled",
        v36 & 1,
        0);
      cm_is_roam_enabled___last_ticks = v34;
    }
    result = 11;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}
