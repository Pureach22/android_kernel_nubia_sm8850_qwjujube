__int64 __fastcall lim_admit_control_add_ts(
        __int64 a1,
        const void *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        unsigned __int16 a13,
        unsigned __int8 a14,
        __int64 a15,
        _BYTE *a16,
        __int64 a17)
{
  int v24; // w26
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x20
  int v34; // w26
  int v35; // w26
  const char *v36; // x2
  __int64 v37; // x4
  unsigned int v38; // w1
  int *v39; // x26
  unsigned int v40; // w8
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  const char *v50; // x2
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int v68; // w1
  __int64 result; // x0
  int v70; // w4
  unsigned int v71; // w27
  __int64 v72; // x26
  __int16 v73; // w9
  __int16 v74; // w9
  unsigned int v75; // w20
  unsigned __int8 *hash_entry; // x0
  __int64 v77; // x4
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int v86; // w8
  int v87; // w8
  int v88; // w9
  unsigned int v89; // w4
  unsigned int v90; // w8
  unsigned int v91; // w24
  unsigned __int8 *v92; // x20
  __int64 v93; // [xsp+0h] [xbp-60h]
  __int64 v94; // [xsp+8h] [xbp-58h]
  int v95; // [xsp+2Ch] [xbp-34h]
  _BYTE *v96; // [xsp+30h] [xbp-30h]
  int v97; // [xsp+3Ch] [xbp-24h]
  unsigned int v98; // [xsp+4Ch] [xbp-14h]
  _QWORD v99[2]; // [xsp+50h] [xbp-10h] BYREF

  v99[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = a14;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tsid: %d directn: %d start: %d intvl: %d accPolicy: %d up: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_admit_control_add_ts",
    (*(unsigned __int16 *)(a3 + 4) >> 1) & 0xF,
    (*(unsigned __int16 *)(a3 + 4) >> 5) & 3,
    *(unsigned int *)(a3 + 27),
    *(unsigned int *)(a3 + 11),
    (*(unsigned __int16 *)(a3 + 4) >> 7) & 3,
    (*(unsigned __int16 *)(a3 + 4) >> 11) & 7);
  v99[0] = 0;
  v33 = a1 + 8920;
  if ( v24 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Trying to find tspec entry for assocId: %d pTsInfo->traffic.direction: %d pTsInfo->traffic.tsid: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_tspec_find_by_assoc_id",
      a13,
      (*(unsigned __int16 *)(a3 + 4) >> 5) & 3,
      (*(unsigned __int16 *)(a3 + 4) >> 1) & 0xF);
    v34 = 15;
    while ( !*(_BYTE *)v33
         || *(unsigned __int16 *)(v33 + 8) != a13
         || (unsigned int)qdf_mem_cmp((const void *)(a3 + 1), (const void *)(v33 + 10), 0x3Au) )
    {
      --v34;
      v33 += 163;
      if ( !v34 )
        goto LABEL_15;
    }
LABEL_13:
    v99[0] = v33;
    v36 = "%s: duplicate tspec index: %d";
    v37 = *(unsigned __int8 *)(v33 + 1);
    v38 = 2;
    goto LABEL_14;
  }
  v35 = 15;
  do
  {
    if ( *(_BYTE *)v33
      && !(unsigned int)qdf_mem_cmp(a2, (const void *)(v33 + 2), 6u)
      && !(unsigned int)qdf_mem_cmp((const void *)(a3 + 1), (const void *)(v33 + 10), 0x3Au) )
    {
      goto LABEL_13;
    }
    --v35;
    v33 += 163;
  }
  while ( v35 );
LABEL_15:
  if ( ((*(unsigned __int16 *)(a3 + 4) >> 7) & 3) != 1 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: AccessType: %d not supported",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_validate_tspec");
LABEL_35:
    v67 = "%s: tspec validation failed";
LABEL_36:
    v68 = 3;
    goto LABEL_37;
  }
  if ( a17 )
    v39 = (int *)(a17 + 7232);
  else
    v39 = (int *)(a1 + 4840);
  if ( *v39 == 1 )
    v40 = 11000000;
  else
    v40 = 54000000;
  if ( !*(_WORD *)(a3 + 7) || !*(_DWORD *)(a3 + 35) || !*(_WORD *)(a3 + 55) || *(_DWORD *)(a3 + 51) - 1 >= v40 )
  {
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Invalid EDCA Tspec: NomMsdu: %d meanDataRate: %d surplusBw: %d min_phy_rate: %d",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "lim_validate_tspec_edca");
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: return status: %d",
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      "lim_validate_tspec_edca",
      16);
    qdf_trace_msg(0x35u, 3u, "%s: EDCA tspec invalid", v59, v60, v61, v62, v63, v64, v65, v66, "lim_validate_tspec");
    goto LABEL_35;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: return status: %d",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "lim_validate_tspec_edca",
    0);
  v49 = *(_DWORD *)(a3 + 11);
  if ( !*(_QWORD *)(a3 + 11) )
  {
    if ( *(_WORD *)(a3 + 7) || *(_WORD *)(a3 + 9) )
    {
      if ( *(_DWORD *)(a3 + 35) || *(_DWORD *)(a3 + 39) || *(_DWORD *)(a3 + 31) )
        goto LABEL_69;
      v50 = "%s: DataRate not specified";
    }
    else
    {
      v50 = "%s: MsduSize not specified";
    }
    qdf_trace_msg(0x35u, 2u, v50, v41, v42, v43, v44, v45, v46, v47, v48, "lim_calculate_svc_int");
LABEL_69:
    v67 = "%s: SvcInt calculate failed";
    goto LABEL_36;
  }
  v70 = *(unsigned __int8 *)(a1 + 11365);
  if ( *(_DWORD *)(a3 + 15) )
    v49 = *(_DWORD *)(a3 + 15);
  v97 = v49;
  if ( *(_BYTE *)(a1 + 11365) )
  {
    if ( v70 == 1 )
    {
LABEL_65:
      v67 = "%s: tspec rejected by admit control policy";
      goto LABEL_36;
    }
    if ( v70 == 2 )
    {
      v96 = a16;
      v71 = 0;
      v98 = 0;
      v95 = *v39;
      v72 = a1 + 8920;
      do
      {
        if ( *(_BYTE *)v72 )
        {
          if ( dph_get_hash_entry(a1, *(_WORD *)(v72 + 8), a17 + 360) )
            v98 += *(_DWORD *)(v72 + 44);
          else
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Tspec: %d assocId: %d dphNode not found",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "lim_compute_mean_bw_used",
              v71,
              *(unsigned __int16 *)(v72 + 8));
        }
        ++v71;
        v72 += 163;
      }
      while ( v71 != 15 );
      a16 = v96;
      v87 = *(unsigned __int8 *)(a1 + 11366);
      if ( v95 == 1 )
        v88 = 11000000;
      else
        v88 = 54000000;
      v89 = v88 * v87;
      v90 = v88 * v87 - v98;
      if ( v89 < v98 )
        goto LABEL_64;
      if ( v90 < *(_DWORD *)(a3 + 35) )
      {
        qdf_trace_msg(
          0x35u,
          3u,
          "%s: Total BW: %d Used: %d Tspec request: %d not possible",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "lim_admit_policy_oversubscription");
LABEL_64:
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: rejected by BWFactor policy",
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          "lim_admit_policy");
        goto LABEL_65;
      }
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Admit Policy: %d unknown, admitting all traffic",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "lim_admit_policy");
    }
  }
  if ( a15 )
  {
    qdf_mem_set((void *)a15, 0x10u, 0);
    *(_DWORD *)(a15 + 4) = *(_DWORD *)(a3 + 27);
    *(_DWORD *)(a15 + 8) = v97;
    *(_WORD *)(a15 + 12) = v97;
    v73 = *(_WORD *)(a15 + 2);
    *(_WORD *)(a15 + 14) = 4096;
    v74 = v73 & 0xFF9F | (32 * ((*(_WORD *)(a3 + 4) >> 5) & 3));
    *(_WORD *)(a15 + 2) = v74;
    *(_WORD *)(a15 + 2) = v74 & 0xFFE0 | *(_WORD *)(a3 + 4) & 0x1E;
  }
  if ( !a14 )
  {
    result = 0;
    goto LABEL_39;
  }
  v75 = *(unsigned __int16 *)(a3 + 4);
  hash_entry = (unsigned __int8 *)dph_get_hash_entry(a1, a13, a17 + 360);
  if ( hash_entry && (v86 = *(unsigned __int16 *)hash_entry, (v86 & 1) != 0) )
  {
    v91 = (v75 >> 7) & 3;
    if ( v91 == 1 )
    {
      if ( (v86 & 0xC0) != 0 )
      {
        result = lim_tspec_add(a1, a2, a13, (__int64 *)(a3 + 1), v78, v79, v80, v81, v82, v83, v84, v85, v77, v99);
        if ( !(_DWORD)result )
        {
          *a16 = *(_BYTE *)(v99[0] + 1LL);
          goto LABEL_39;
        }
        v67 = "%s: no space in tspec list";
        v68 = 2;
LABEL_37:
        qdf_trace_msg(0x35u, v68, v67, v41, v42, v43, v44, v45, v46, v47, v48, "lim_admit_control_add_ts");
        goto LABEL_38;
      }
    }
    else
    {
      v92 = hash_entry;
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Invalid accessPolicy: %d",
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        v85,
        "lim_validate_access_policy",
        v91);
      v86 = *(unsigned __int16 *)v92;
      hash_entry = v92;
    }
    LODWORD(v94) = hash_entry[339];
    LODWORD(v93) = hash_entry[338];
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: accPol: %d lle: %d wme: %d wsm: %d sta mac %02x:%02x:%02x:**:**:%02x",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "lim_validate_access_policy",
      v91,
      (v86 >> 7) & 1,
      (v86 >> 6) & 1,
      (v86 >> 8) & 1,
      v93,
      v94,
      hash_entry[340],
      hash_entry[343]);
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: invalid station address passed",
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      v84,
      v85,
      "lim_validate_access_policy");
  }
  v36 = "%s: AccessPolicy: %d is not valid in current mode";
  v37 = (*(unsigned __int16 *)(a3 + 4) >> 7) & 3;
  v38 = 3;
LABEL_14:
  qdf_trace_msg(0x35u, v38, v36, v25, v26, v27, v28, v29, v30, v31, v32, "lim_admit_control_add_ts", v37);
LABEL_38:
  result = 16;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
