__int64 __fastcall cm_check_and_prepare_roam_req(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x22
  int v9; // w24
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int *v26; // x25
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  bool v36; // zf
  __int64 v37; // x20
  __int64 result; // x0
  char v39; // w0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 cmpt_obj; // x0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  size_t v57; // x2
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x4
  __int64 v67; // x6
  __int64 v68; // x0
  __int64 v69; // x22
  char is_macaddr_equal_3; // w0
  int *v71; // x8
  __int16 v72; // w9
  int v73; // w8
  int v74; // w9
  __int64 v75; // [xsp+0h] [xbp-70h]
  __int64 v76; // [xsp+8h] [xbp-68h]
  __int64 v77; // [xsp+10h] [xbp-60h]
  __int64 v78; // [xsp+18h] [xbp-58h]
  int v79; // [xsp+28h] [xbp-48h] BYREF
  unsigned __int16 v80; // [xsp+2Ch] [xbp-44h]
  int v81; // [xsp+30h] [xbp-40h] BYREF
  unsigned __int16 v82; // [xsp+34h] [xbp-3Ch]
  int v83; // [xsp+38h] [xbp-38h] BYREF
  __int16 v84; // [xsp+3Ch] [xbp-34h]
  _QWORD v85[4]; // [xsp+40h] [xbp-30h] BYREF
  char v86; // [xsp+60h] [xbp-10h]
  __int64 v87; // [xsp+68h] [xbp-8h]

  v87 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a1;
  v80 = 0;
  v79 = 0;
  v7 = *(_QWORD *)(v6 + 216);
  if ( v7 )
    v8 = *(_QWORD *)(v7 + 80);
  else
    v8 = 0;
  v82 = 0;
  v81 = 0;
  memset(v85, 0, sizeof(v85));
  v86 = 0;
  if ( (cm_roam_offload_enabled(v8) & 1) != 0 )
  {
    v9 = *(_DWORD *)(a2 + 68);
    if ( !v9 )
      v9 = *(_DWORD *)(a2 + 72);
    if ( !cm_is_connect_req_reassoc(a2 + 8) )
      goto LABEL_28;
    wlan_vdev_get_bss_peer_mac(*a1, &v81, v10, v11, v12, v13, v14, v15, v16, v17);
    v26 = (int *)(a2 + 22);
    if ( *(_DWORD *)(a2 + 22) != v81 || *(unsigned __int16 *)(a2 + 26) != v82 )
    {
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: BSSID didn't matched: bssid: %02x:%02x:%02x:**:**:%02x prev bssid: %02x:%02x:%02x:**:**:%02x",
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        "cm_check_and_prepare_roam_req",
        (unsigned __int8)v81,
        BYTE1(v81),
        BYTE2(v81),
        HIBYTE(v82),
        *(unsigned __int8 *)(a2 + 22),
        *(unsigned __int8 *)(a2 + 23),
        *(unsigned __int8 *)(a2 + 24),
        *(unsigned __int8 *)(a2 + 27));
      if ( (unsigned int)wlan_vdev_get_bss_peer_mld_mac(*a1, &v79, v28, v29, v30, v31, v32, v33, v34, v35)
        || (*v26 == v79 ? (v36 = *(unsigned __int16 *)(a2 + 26) == v80) : (v36 = 0), !v36) )
      {
        LODWORD(v76) = *(unsigned __int8 *)(a2 + 23);
        LODWORD(v78) = *(unsigned __int8 *)(a2 + 27);
        LODWORD(v77) = *(unsigned __int8 *)(a2 + 24);
        LODWORD(v75) = *(unsigned __int8 *)(a2 + 22);
        qdf_trace_msg(
          0x68u,
          8u,
          "%s: BSSID didn't matched: bss mld: %02x:%02x:%02x:**:**:%02x prev bssid: %02x:%02x:%02x:**:**:%02x",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "cm_check_and_prepare_roam_req",
          (unsigned __int8)v79,
          BYTE1(v79),
          BYTE2(v79),
          HIBYTE(v80),
          v75,
          v76,
          v77,
          v78);
LABEL_28:
        result = 16;
        goto LABEL_29;
      }
    }
    cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(*a1, v18, v19, v20, v21, v22, v23, v24, v25);
    if ( !cmpt_obj || (v57 = *(unsigned __int8 *)(cmpt_obj + 178), !*(_BYTE *)(cmpt_obj + 178)) )
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: failed to get ssid",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "cm_check_and_prepare_roam_req");
      goto LABEL_28;
    }
    LOBYTE(v85[0]) = *(_BYTE *)(cmpt_obj + 178);
    qdf_mem_copy((char *)v85 + 1, (const void *)(cmpt_obj + 145), v57);
    v66 = LOBYTE(v85[0]);
    v67 = *(unsigned __int8 *)(a2 + 28);
    if ( LOBYTE(v85[0]) != (_DWORD)v67 )
    {
LABEL_26:
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: SSID didn't matched: self ssid: \"%.*s\", ssid in req: \"%.*s\"",
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        "cm_check_and_prepare_roam_req",
        v66,
        (char *)v85 + 1,
        v67,
        a2 + 29);
      goto LABEL_28;
    }
    if ( (unsigned int)qdf_mem_cmp((char *)v85 + 1, (const void *)(a2 + 29), LOBYTE(v85[0])) )
    {
      v66 = LOBYTE(v85[0]);
      v67 = *(unsigned __int8 *)(a2 + 28);
      goto LABEL_26;
    }
    v68 = _qdf_mem_malloc(0x9F0u, "cm_check_and_prepare_roam_req", 105);
    *a3 = v68;
    if ( v68 )
    {
      v69 = v68;
      v84 = 0;
      v83 = 0;
      is_macaddr_equal_3 = qdf_is_macaddr_equal_3(a2 + 16, &v83);
      v71 = (int *)(a2 + 61);
      if ( (is_macaddr_equal_3 & 1) == 0 )
        v71 = (int *)(a2 + 16);
      v72 = *((_WORD *)v71 + 2);
      v73 = *v71;
      *(_WORD *)(v69 + 44) = v72;
      *(_DWORD *)(v69 + 40) = v73;
      v74 = *v26;
      *(_WORD *)(v69 + 50) = *(_WORD *)(a2 + 26);
      *(_DWORD *)(v69 + 46) = v74;
      cm_fill_vdev_crypto_params(a1, a2 + 8);
      *(_DWORD *)(v69 + 52) = v9;
      *(_DWORD *)(v69 + 36) = 1;
      qdf_mem_copy((void *)(v69 + 56), (const void *)(a2 + 80), 0x50u);
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
    v37 = jiffies;
    if ( cm_is_roam_enabled___last_ticks - jiffies + 125 < 0 )
    {
      v39 = cm_roam_offload_enabled(v8);
      qdf_trace_msg(
        0x68u,
        8u,
        "%s: All roam mode (offload %d, host %d) are disabled",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "cm_is_roam_enabled",
        v39 & 1,
        0);
      cm_is_roam_enabled___last_ticks = v37;
    }
    result = 11;
  }
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}
