__int64 __fastcall cm_resume_connect_after_peer_create(__int64 *a1, unsigned int *a2)
{
  __int64 v4; // x1
  __int64 v5; // x8
  __int64 v6; // x21
  __int64 req_by_cm_id_fl; // x0
  __int64 v8; // x22
  __int64 v9; // x20
  __int64 v10; // x25
  unsigned __int16 v11; // w8
  unsigned int v12; // w2
  int secure_akm_available; // w0
  unsigned int v14; // w24
  __int64 result; // x0
  unsigned int v16; // w8
  unsigned int v17; // w24
  char v18; // w27
  __int64 v19; // x9
  __int64 v20; // x10
  __int64 v21; // x26
  unsigned int v22; // w22
  unsigned int v23; // w23
  __int64 v24; // x8
  __int64 v25; // x9
  __int64 v26; // x25
  __int64 v27; // x0
  __int64 v28; // x9
  __int64 v29; // x10
  __int64 v30; // x11
  unsigned int v31; // w28
  __int64 v32; // x8
  __int64 v33; // x0
  unsigned int v34; // w0
  unsigned int v35; // w24
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x11
  __int64 v45; // x7
  int v46; // w8
  int v47; // w9
  int v48; // w10
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int16 v57; // [xsp+6Ch] [xbp-E4h] BYREF
  char v58; // [xsp+6Eh] [xbp-E2h]
  __int64 v59; // [xsp+70h] [xbp-E0h] BYREF
  __int64 v60; // [xsp+78h] [xbp-D8h]
  __int64 v61; // [xsp+80h] [xbp-D0h]
  __int64 v62; // [xsp+88h] [xbp-C8h]
  __int64 v63; // [xsp+90h] [xbp-C0h]
  __int64 v64; // [xsp+98h] [xbp-B8h]
  __int64 v65; // [xsp+A0h] [xbp-B0h]
  __int64 v66; // [xsp+A8h] [xbp-A8h]
  __int64 v67; // [xsp+B0h] [xbp-A0h]
  _BYTE v68[40]; // [xsp+B8h] [xbp-98h] BYREF
  _QWORD v69[10]; // [xsp+E0h] [xbp-70h] BYREF
  _QWORD v70[4]; // [xsp+130h] [xbp-20h]

  v70[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a2;
  v5 = *(_QWORD *)(*a1 + 152);
  v67 = 0;
  memset(v68, 0, sizeof(v68));
  v65 = 0;
  v66 = 0;
  v6 = *(_QWORD *)(v5 + 80);
  v63 = 0;
  v64 = 0;
  v61 = 0;
  v62 = 0;
  v59 = 0;
  v60 = 0;
  req_by_cm_id_fl = cm_get_req_by_cm_id_fl(a1, v4, "cm_resume_connect_after_peer_create", 2791);
  if ( !req_by_cm_id_fl )
  {
    result = 16;
    goto LABEL_49;
  }
  v8 = *a1;
  v9 = req_by_cm_id_fl;
  if ( *(_DWORD *)(req_by_cm_id_fl + 104) )
  {
    v10 = *(_QWORD *)(*(_QWORD *)(req_by_cm_id_fl + 864) + 24LL);
    v11 = *(_WORD *)(req_by_cm_id_fl + 152);
    if ( (v11 & *(_WORD *)(v10 + 1156) & 0x80) != 0 )
      v12 = *(unsigned __int16 *)(req_by_cm_id_fl + 152);
    else
      v12 = v11 & 0xBF3F;
    wlan_crypto_set_vdev_param(*a1, 5u, v12);
    secure_akm_available = wlan_crypto_get_secure_akm_available(*(_DWORD *)(v10 + 1140));
    if ( secure_akm_available == 30 )
      v14 = *(_DWORD *)(v10 + 1140);
    else
      v14 = 1 << secure_akm_available;
    wlan_crypto_set_vdev_param(v8, 7u, v14);
    v16 = *(_DWORD *)(v10 + 1144);
    *(_DWORD *)(v10 + 1140) = v14;
    if ( (v16 & 0x400) != 0 )
    {
      v17 = 1024;
    }
    else if ( (v16 & 0x80) != 0 )
    {
      v17 = 128;
    }
    else if ( (v16 & 0x200) != 0 )
    {
      v17 = 512;
    }
    else if ( (v16 & 8) != 0 )
    {
      v17 = 8;
    }
    else if ( (v16 & 2) != 0 )
    {
      v17 = 2;
    }
    else
    {
      v17 = v16;
    }
    wlan_crypto_set_vdev_param(v8, 1u, v17);
    *(_DWORD *)(v10 + 1144) = v17;
    v8 = *a1;
  }
  v18 = *(_BYTE *)(v9 + 216);
  v19 = *(_QWORD *)(v9 + 184);
  v20 = *(_QWORD *)(v9 + 192);
  v21 = *(_QWORD *)(v9 + 864);
  v22 = *(unsigned __int8 *)(v8 + 104);
  v23 = *a2;
  LOBYTE(v60) = v18 & 7;
  v62 = v19;
  v63 = v20;
  v24 = *(_QWORD *)(v9 + 200);
  v25 = *(_QWORD *)(v9 + 208);
  LOBYTE(v59) = v22;
  HIDWORD(v59) = v23;
  v64 = v24;
  v65 = v25;
  LOWORD(v25) = *(_WORD *)(v9 + 226);
  v66 = v21;
  v67 = v9 + 240;
  LOBYTE(v24) = *(_BYTE *)(v9 + 840);
  WORD1(v60) = v25;
  LOWORD(v25) = *(_WORD *)(v9 + 228);
  v68[0] = v24;
  v26 = *(_QWORD *)(v21 + 24);
  WORD2(v60) = v25;
  LODWORD(v25) = *(_DWORD *)(v9 + 236);
  v27 = *(_QWORD *)(v26 + 1216);
  LODWORD(v61) = *(_DWORD *)(v9 + 232);
  HIDWORD(v61) = v25;
  if ( (((__int64 (__fastcall *)(__int64))util_scan_is_hidden_ssid)(v27) & 1) != 0
    && (*(_BYTE *)(v26 + 1142) & 0x40) != 0 )
  {
    *(_QWORD *)&v68[1] = *(_QWORD *)(v9 + 52);
    v28 = *(_QWORD *)(v9 + 76);
    v29 = *(_QWORD *)(v9 + 60);
    v30 = *(_QWORD *)(v9 + 68);
    v68[33] = *(_BYTE *)(v9 + 84);
    *(_QWORD *)&v68[25] = v28;
    *(_QWORD *)&v68[17] = v30;
    *(_QWORD *)&v68[9] = v29;
  }
  v31 = *(unsigned __int8 *)(v26 + 1158);
  *(_QWORD *)((char *)v70 + 5) = 0;
  v70[0] = 0;
  v68[34] = v31;
  v32 = *(_QWORD *)(v21 + 24);
  memset(v69, 0, sizeof(v69));
  v33 = *(_QWORD *)(v32 + 1216);
  v58 = 0;
  v57 = 0;
  if ( (((__int64 (__fastcall *)(__int64))util_scan_is_hidden_ssid)(v33) & 1) == 0 )
  {
    if ( !v68[1] )
    {
      if ( (v18 & 2) == 0 )
      {
        if ( (v18 & 4) == 0 )
        {
          if ( (v18 & 1) == 0 )
          {
            if ( v31 <= 1 )
              goto LABEL_44;
            v35 = 0;
            goto LABEL_43;
          }
          v35 = 0;
          goto LABEL_40;
        }
        v35 = 0;
        goto LABEL_37;
      }
      v35 = 0;
      goto LABEL_34;
    }
    v35 = 0;
    goto LABEL_31;
  }
  v34 = scnprintf(v69, 93, "[hidden]");
  v35 = v34;
  if ( v68[1] )
  {
    if ( v34 > 0x5D )
LABEL_58:
      __break(0x5512u);
LABEL_31:
    v35 += scnprintf((char *)v69 + v35, 93 - v35, "[OWE wildcard ssid]");
  }
  if ( (v18 & 2) == 0 )
    goto LABEL_35;
  if ( v35 > 0x5D )
    goto LABEL_58;
LABEL_34:
  v35 += scnprintf((char *)v69 + v35, 93 - v35, "[WPS]");
LABEL_35:
  if ( (v18 & 4) != 0 )
  {
    if ( v35 > 0x5D )
      goto LABEL_58;
LABEL_37:
    v35 += scnprintf((char *)v69 + v35, 93 - v35, "[OSEN]");
  }
  if ( (v18 & 1) == 0 )
    goto LABEL_41;
  if ( v35 > 0x5D )
    goto LABEL_58;
LABEL_40:
  v35 += scnprintf((char *)v69 + v35, 93 - v35, "[RSN OVERRIDE]");
LABEL_41:
  if ( v31 > 1 )
  {
    if ( v35 > 0x5D )
      goto LABEL_58;
LABEL_43:
    scnprintf((char *)v69 + v35, 93 - v35, "[RSNO_%d]", v31 - 1);
  }
LABEL_44:
  wlan_reg_get_cc_and_src(v6, &v57);
  v44 = *(_QWORD *)(v21 + 24);
  if ( v44 == -1 )
  {
    v47 = 0;
    v45 = 0;
    v46 = 0;
    v48 = 0;
  }
  else
  {
    v45 = *(unsigned __int8 *)(v44 + 1);
    v46 = *(unsigned __int8 *)(v44 + 2);
    v47 = *(unsigned __int8 *)(v44 + 3);
    v48 = *(unsigned __int8 *)(v44 + 6);
  }
  qdf_trace_msg(
    0x68u,
    4u,
    "vdev %d cm_id 0x%x: Connecting to %.*s %02x:%02x:%02x:**:**:%02x rssi %d freq %d phymode %d akm 0x%x uc 0x%x mc 0x%x, CC: %c%c %s",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    v22,
    v23,
    *(unsigned __int8 *)(v9 + 52),
    v9 + 53,
    v45,
    v46,
    v47,
    v48,
    *(char *)(v44 + 60),
    *(_DWORD *)(v44 + 1064),
    *(_DWORD *)(v44 + 52),
    *(_DWORD *)(v26 + 1140),
    *(_DWORD *)(v26 + 1144),
    *(_DWORD *)(v26 + 1148),
    (unsigned __int8)v57,
    HIBYTE(v57),
    v69);
  cm_cp_stats_cstats_log_connecting_event(*a1, &v59, v9);
  result = mlme_cm_connect_req(*a1, &v59);
  if ( (_DWORD)result )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: connect request failed",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "cm_resume_connect_after_peer_create",
      (unsigned __int8)v59,
      HIDWORD(v59));
    mlme_cm_bss_peer_delete_req(*a1);
    result = cm_send_connect_start_fail(a1, (unsigned int *)(v9 + 24), 5);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}
