__int64 __fastcall hdd_update_tgt_ht_cap(__int64 a1, __int64 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  unsigned int v14; // w1
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 result; // x0
  unsigned int v24; // w8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  char v34; // w8
  unsigned int v35; // w21
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  bool v44; // zf
  __int16 v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x0
  __int64 v55; // x1
  __int64 v56; // x0
  _BYTE v57[4]; // [xsp+4h] [xbp-2Ch] BYREF
  unsigned __int16 v58[2]; // [xsp+8h] [xbp-28h] BYREF
  _BYTE v59[4]; // [xsp+Ch] [xbp-24h] BYREF
  size_t v60; // [xsp+10h] [xbp-20h] BYREF
  __int64 v61; // [xsp+18h] [xbp-18h] BYREF
  __int64 v62; // [xsp+20h] [xbp-10h]
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)a1;
  v60 = 0;
  v61 = 0;
  v59[0] = 0;
  v58[0] = 0;
  v62 = 0;
  v57[0] = 0;
  if ( (unsigned int)wlan_mlme_get_ht_mpdu_density(v4, v59) )
  {
    v13 = "%s: could not get HT MPDU Density";
    goto LABEL_9;
  }
  v14 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 && v14 < v59[0] && (unsigned int)wlan_mlme_set_ht_mpdu_density(*(_QWORD *)a1, v14) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: could not set HT capability to CCM",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "hdd_update_tgt_ht_cap");
  if ( (unsigned int)wlan_mlme_get_ht_cap_info(*(_QWORD *)a1, v58) )
  {
    v13 = "%s: could not get HT capability info";
    goto LABEL_9;
  }
  v24 = v58[0];
  if ( (v58[0] & 0x300) != 0 && (*(_BYTE *)(a2 + 4) & 1) == 0 )
  {
    v24 = v58[0] & 0xFCFF;
    v58[0] &= 0xFCFFu;
  }
  if ( (v24 & 1) != 0 && (*(_BYTE *)(a2 + 6) & 1) == 0 )
  {
    v24 &= 0xFFFEu;
    v58[0] = v24;
  }
  if ( (v24 & 0x20) != 0 && (*(_BYTE *)(a2 + 7) & 1) == 0 )
  {
    v24 &= 0xFFDFu;
    v58[0] = v24;
  }
  if ( (v24 & 0x40) != 0 && (*(_BYTE *)(a2 + 8) & 1) == 0 )
  {
    v24 &= 0xFFBFu;
    v58[0] = v24;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: gHtSMPS ini: %d, dynamic_smps fw cap: %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "hdd_update_tgt_ht_cap",
    (v24 >> 2) & 3,
    *(unsigned __int8 *)(a2 + 16));
  if ( (v58[0] & 0xC) == 4 && (*(_BYTE *)(a2 + 16) & 1) == 0 )
    v58[0] |= 0xCu;
  v25 = *(_QWORD *)a1;
  *(_DWORD *)(a1 + 1248) = *(_DWORD *)(a2 + 12);
  *(_BYTE *)(a1 + 1252) = *(_BYTE *)(a2 + 5);
  if ( (unsigned int)wlan_mlme_get_vht_mimo_cap(v25, v57) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: unable to get vht_enable2x2",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "hdd_update_tgt_ht_cap");
  v34 = v57[0];
  v35 = *(_DWORD *)(a2 + 12) - 1;
  if ( v35 < v57[0] )
  {
    if ( (unsigned int)wlan_mlme_set_vht_mimo_cap(*(_QWORD *)a1, v35) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: unable to set vht_mimo cap",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_update_tgt_ht_cap");
    else
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: update vht mimo ini value %d to %d",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "hdd_update_tgt_ht_cap",
        v57[0],
        v35);
    v34 = v35;
    v57[0] = v35;
  }
  v44 = v34 == 0;
  v45 = v58[0];
  if ( v44 || (*(_BYTE *)(a2 + 5) & 1) == 0 )
  {
    v45 = v58[0] & 0xFF7F;
    v58[0] &= ~0x80u;
  }
  result = wlan_mlme_set_ht_cap_info(*(_QWORD *)a1, v45);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: could not set HT capability to CCM",
               v46,
               v47,
               v48,
               v49,
               v50,
               v51,
               v52,
               v53,
               "hdd_update_tgt_ht_cap");
  if ( !v57[0] )
    goto LABEL_10;
  qdf_trace_msg(0x33u, 8u, "%s: Read MCS rate set", v46, v47, v48, v49, v50, v51, v52, v53, "hdd_update_tgt_ht_cap");
  v54 = *(_QWORD *)a1;
  v60 = 16;
  result = ucfg_mlme_get_supported_mcs_set(v54, &v61, &v60);
  if ( (_DWORD)result )
    goto LABEL_10;
  LOBYTE(v61) = -1;
  if ( !v57[0] )
    goto LABEL_56;
  BYTE1(v61) = -1;
  if ( v57[0] == 1 )
    goto LABEL_56;
  BYTE2(v61) = -1;
  if ( v57[0] == 2 )
    goto LABEL_56;
  BYTE3(v61) = -1;
  if ( v57[0] == 3 )
    goto LABEL_56;
  BYTE4(v61) = -1;
  if ( v57[0] == 4 )
    goto LABEL_56;
  BYTE5(v61) = -1;
  if ( v57[0] == 5 )
    goto LABEL_56;
  BYTE6(v61) = -1;
  if ( v57[0] == 6 )
    goto LABEL_56;
  HIBYTE(v61) = -1;
  if ( v57[0] == 7 )
    goto LABEL_56;
  LOBYTE(v62) = -1;
  if ( v57[0] == 8
    || (BYTE1(v62) = -1, v57[0] == 9)
    || (BYTE2(v62) = -1, v57[0] == 10)
    || (BYTE3(v62) = -1, v57[0] == 11)
    || (BYTE4(v62) = -1, v57[0] == 12)
    || (BYTE5(v62) = -1, v57[0] == 13)
    || (BYTE6(v62) = -1, v57[0] == 14)
    || (HIBYTE(v62) = -1, v57[0] == 15) )
  {
LABEL_56:
    v56 = *(_QWORD *)a1;
    BYTE4(v62) |= 1u;
    result = ucfg_mlme_set_supported_mcs_set(v56, &v61, v60);
    if ( !(_DWORD)result )
      goto LABEL_10;
    v13 = "%s: could not set MCS SET to CCM";
LABEL_9:
    result = qdf_trace_msg(0x33u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "hdd_update_tgt_ht_cap");
LABEL_10:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return hdd_update_tgt_vht_cap(result, v55);
}
