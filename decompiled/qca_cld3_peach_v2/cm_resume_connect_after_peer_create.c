__int64 __fastcall cm_resume_connect_after_peer_create(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x21
  __int64 req_by_cm_id_fl; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w8
  __int64 v15; // x22
  __int64 v16; // x20
  __int64 v17; // x25
  unsigned __int16 v18; // w8
  unsigned int v19; // w2
  int secure_akm_available; // w0
  unsigned int v21; // w24
  __int64 result; // x0
  unsigned int v23; // w8
  unsigned int v24; // w24
  char v25; // w10
  int v26; // w11
  char v27; // w8
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x9
  __int64 v31; // x10
  __int16 v32; // w8
  unsigned int v33; // w8
  __int64 v34; // x24
  __int64 v35; // x10
  __int64 v36; // x11
  __int64 v37; // x12
  char v38; // w8
  __int64 v39; // x8
  __int64 v40; // x22
  __int64 v41; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  unsigned int v50; // w23
  char v51; // w8
  int v52; // w0
  int v53; // w0
  int v54; // w8
  __int64 v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x11
  __int64 v65; // x7
  int v66; // w8
  int v67; // w9
  int v68; // w10
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int16 v77; // [xsp+64h] [xbp-19Ch] BYREF
  char v78; // [xsp+66h] [xbp-19Ah]
  _QWORD s[37]; // [xsp+70h] [xbp-190h] BYREF
  _BYTE v80[80]; // [xsp+198h] [xbp-68h] BYREF
  _QWORD v81[3]; // [xsp+1E8h] [xbp-18h]

  v81[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v4 = *(_QWORD *)(*(_QWORD *)(*a1 + 216) + 80LL);
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, *a2, "cm_resume_connect_after_peer_create", 2791);
  if ( !req_by_cm_id_fl )
  {
    result = 16;
    goto LABEL_54;
  }
  v14 = *(_DWORD *)(req_by_cm_id_fl + 104);
  v15 = *a1;
  v16 = req_by_cm_id_fl;
  if ( v14 )
  {
    v17 = *(_QWORD *)(*(_QWORD *)(req_by_cm_id_fl + 1040) + 24LL);
    v18 = *(_WORD *)(req_by_cm_id_fl + 152);
    if ( (v18 & *(_WORD *)(v17 + 1284) & 0x80) != 0 )
      v19 = *(unsigned __int16 *)(req_by_cm_id_fl + 152);
    else
      v19 = v18 & 0xBF3F;
    wlan_crypto_set_vdev_param(*a1, 5u, v19);
    secure_akm_available = wlan_crypto_get_secure_akm_available(*(_DWORD *)(v17 + 1268));
    if ( secure_akm_available == 30 )
      v21 = *(_DWORD *)(v17 + 1268);
    else
      v21 = 1 << secure_akm_available;
    wlan_crypto_set_vdev_param(v15, 7u, v21);
    v23 = *(_DWORD *)(v17 + 1272);
    *(_DWORD *)(v17 + 1268) = v21;
    if ( (v23 & 0x400) != 0 )
    {
      v24 = 1024;
    }
    else if ( (v23 & 0x80) != 0 )
    {
      v24 = 128;
    }
    else if ( (v23 & 0x200) != 0 )
    {
      v24 = 512;
    }
    else if ( (v23 & 8) != 0 )
    {
      v24 = 8;
    }
    else if ( (v23 & 2) != 0 )
    {
      v24 = 2;
    }
    else
    {
      v24 = v23;
    }
    wlan_crypto_set_vdev_param(v15, 1u, v24);
    *(_DWORD *)(v17 + 1272) = v24;
    LOBYTE(v14) = s[1];
    v15 = *a1;
  }
  v25 = *(_BYTE *)(v16 + 216);
  v26 = *a2;
  LOBYTE(s[0]) = *(_BYTE *)(v15 + 168);
  v27 = v14 & 0xF8 | v25 & 7;
  v28 = *(_QWORD *)(v16 + 184);
  v29 = *(_QWORD *)(v16 + 192);
  HIDWORD(s[0]) = v26;
  LOBYTE(s[1]) = v27;
  s[3] = v28;
  s[4] = v29;
  v30 = *(_QWORD *)(v16 + 208);
  v31 = *(_QWORD *)(v16 + 1040);
  s[5] = *(_QWORD *)(v16 + 200);
  s[6] = v30;
  LOWORD(v30) = *(_WORD *)(v16 + 226);
  s[7] = v31;
  s[8] = v16 + 240;
  v32 = *(_WORD *)(v16 + 228);
  LOBYTE(v31) = *(_BYTE *)(v16 + 840);
  WORD1(s[1]) = v30;
  WORD2(s[1]) = v32;
  LODWORD(v30) = *(_DWORD *)(v16 + 232);
  v33 = *(_DWORD *)(v16 + 236);
  LOBYTE(s[9]) = v31;
  s[2] = __PAIR64__(v33, v30);
  if ( (wlan_vdev_mlme_is_mlo_vdev(v15, v6, v7, v8, v9, v10, v11, v12, v13) & 1) != 0 )
    qdf_mem_copy(&s[10], (const void *)(v16 + 848), 0xB0u);
  v34 = *(_QWORD *)(*(_QWORD *)(v16 + 1040) + 24LL);
  if ( (((__int64 (__fastcall *)(_QWORD))util_scan_is_hidden_ssid)(*(_QWORD *)(*(_QWORD *)(s[7] + 24LL) + 1344LL)) & 1) != 0
    && (*(_BYTE *)(v34 + 1270) & 0x40) != 0 )
  {
    s[32] = *(_QWORD *)(v16 + 52);
    v35 = *(_QWORD *)(v16 + 76);
    v36 = *(_QWORD *)(v16 + 60);
    v37 = *(_QWORD *)(v16 + 68);
    LOBYTE(s[36]) = *(_BYTE *)(v16 + 84);
    s[34] = v37;
    s[35] = v35;
    s[33] = v36;
  }
  v38 = *(_BYTE *)(v34 + 1286);
  *(_QWORD *)((char *)v81 + 5) = 0;
  v81[0] = 0;
  BYTE1(s[36]) = v38;
  v39 = *(_QWORD *)(s[7] + 24LL);
  memset(v80, 0, sizeof(v80));
  v40 = *a1;
  v41 = *(_QWORD *)(v39 + 1344);
  v78 = 0;
  v77 = 0;
  if ( (((__int64 (__fastcall *)(__int64))util_scan_is_hidden_ssid)(v41) & 1) != 0 )
  {
    v50 = scnprintf(v80, 93, "[hidden]");
    if ( !LOBYTE(s[32]) )
    {
LABEL_34:
      v51 = s[1];
      if ( (s[1] & 2) == 0 )
      {
LABEL_37:
        if ( (v51 & 4) == 0 )
        {
LABEL_40:
          if ( (v51 & 1) == 0 )
          {
LABEL_43:
            v54 = BYTE1(s[36]);
            if ( BYTE1(s[36]) <= 1u )
              goto LABEL_46;
            if ( v50 > 0x5D )
              goto LABEL_63;
            goto LABEL_45;
          }
          if ( v50 > 0x5D )
            goto LABEL_63;
LABEL_42:
          v50 += scnprintf(&v80[v50], 93 - v50, "[RSN OVERRIDE]");
          goto LABEL_43;
        }
        if ( v50 > 0x5D )
          goto LABEL_63;
LABEL_39:
        v53 = scnprintf(&v80[v50], 93 - v50, "[OSEN]");
        v51 = s[1];
        v50 += v53;
        goto LABEL_40;
      }
      if ( v50 > 0x5D )
        goto LABEL_63;
LABEL_36:
      v52 = scnprintf(&v80[v50], 93 - v50, "[WPS]");
      v51 = s[1];
      v50 += v52;
      goto LABEL_37;
    }
    if ( v50 > 0x5D )
LABEL_63:
      __break(0x5512u);
LABEL_33:
    v50 += scnprintf(&v80[v50], 93 - v50, "[OWE wildcard ssid]");
    goto LABEL_34;
  }
  if ( LOBYTE(s[32]) )
  {
    v50 = 0;
    goto LABEL_33;
  }
  if ( (s[1] & 2) != 0 )
  {
    v50 = 0;
    goto LABEL_36;
  }
  if ( (s[1] & 4) != 0 )
  {
    v50 = 0;
    goto LABEL_39;
  }
  if ( (s[1] & 1) != 0 )
  {
    v50 = 0;
    goto LABEL_42;
  }
  v54 = BYTE1(s[36]);
  v50 = 0;
  if ( BYTE1(s[36]) > 1u )
LABEL_45:
    v50 += scnprintf(&v80[v50], 93 - v50, "[RSNO_%d]", v54 - 1);
LABEL_46:
  if ( (wlan_vdev_mlme_is_mlo_vdev(v40, v42, v43, v44, v45, v46, v47, v48, v49) & 1) != 0 )
  {
    v55 = *(_QWORD *)(s[7] + 24LL);
    if ( *(_DWORD *)(v55 + 1912) | *(unsigned __int16 *)(v55 + 1916) )
      scnprintf(
        &v80[v50],
        93 - v50,
        ", MLD %02x:%02x:%02x:**:**:%02x links %d",
        *(unsigned __int8 *)(v55 + 1912),
        *(unsigned __int8 *)(v55 + 1913),
        *(unsigned __int8 *)(v55 + 1914),
        *(unsigned __int8 *)(v55 + 1917),
        *(unsigned __int8 *)(v55 + 1918));
  }
  wlan_reg_get_cc_and_src(v4, &v77);
  v64 = *(_QWORD *)(s[7] + 24LL);
  if ( v64 == -1 )
  {
    v67 = 0;
    v65 = 0;
    v66 = 0;
    v68 = 0;
  }
  else
  {
    v65 = *(unsigned __int8 *)(v64 + 1);
    v66 = *(unsigned __int8 *)(v64 + 2);
    v67 = *(unsigned __int8 *)(v64 + 3);
    v68 = *(unsigned __int8 *)(v64 + 6);
  }
  qdf_trace_msg(
    0x68u,
    4u,
    "vdev %d cm_id 0x%x: Connecting to %.*s %02x:%02x:%02x:**:**:%02x rssi %d freq %d phymode %d akm 0x%x uc 0x%x mc 0x%x, CC: %c%c %s",
    v56,
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    LOBYTE(s[0]),
    HIDWORD(s[0]),
    *(unsigned __int8 *)(v16 + 52),
    v16 + 53,
    v65,
    v66,
    v67,
    v68,
    *(char *)(v64 + 60),
    *(_DWORD *)(v64 + 1192),
    *(_DWORD *)(v64 + 52),
    *(_DWORD *)(v34 + 1268),
    *(_DWORD *)(v34 + 1272),
    *(_DWORD *)(v34 + 1276),
    (unsigned __int8)v77,
    HIBYTE(v77),
    v80);
  cm_cp_stats_cstats_log_connecting_event(*a1, s, v16);
  result = mlme_cm_connect_req(*a1, s);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: connect request failed",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      "cm_resume_connect_after_peer_create",
      LOBYTE(s[0]),
      HIDWORD(s[0]));
    mlme_cm_bss_peer_delete_req(*a1);
    result = cm_send_connect_start_fail(a1, (unsigned int *)(v16 + 24), 5);
  }
LABEL_54:
  _ReadStatusReg(SP_EL0);
  return result;
}
