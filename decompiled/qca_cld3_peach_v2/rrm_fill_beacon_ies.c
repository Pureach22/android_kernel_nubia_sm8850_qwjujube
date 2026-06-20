__int64 __fastcall rrm_fill_beacon_ies(
        _DWORD *a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        char a4,
        unsigned __int8 a5,
        unsigned __int8 *a6,
        unsigned __int8 a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16,
        unsigned __int16 *a17)
{
  _DWORD *v18; // x22
  unsigned __int8 v20; // w25
  char v21; // w26
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  int v33; // w24
  unsigned int v34; // w24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  char v51; // w26
  unsigned __int8 v52; // w28
  void *v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 v62; // w24
  __int64 v63; // x25
  __int64 v64; // x0
  unsigned __int8 v65; // w10
  unsigned __int16 v66; // w26
  unsigned __int8 v67; // w9
  unsigned __int8 *v68; // x25
  __int64 v69; // x8
  _BOOL4 v70; // w9
  __int64 v71; // x24
  unsigned int v72; // w27
  int v73; // w8
  __int64 v74; // x10
  unsigned __int8 *v75; // x11
  unsigned __int8 *v76; // x12
  bool v77; // zf
  int v78; // w9
  int v79; // t1
  int v80; // w5
  _BOOL4 v81; // w8
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  __int64 v98; // x5
  unsigned __int8 v99; // w8
  __int64 v100; // x9
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  __int64 v110; // [xsp+8h] [xbp-58h]
  unsigned int n; // [xsp+14h] [xbp-4Ch]
  unsigned __int8 n_4; // [xsp+18h] [xbp-48h]
  const void *v113; // [xsp+20h] [xbp-40h]
  _BOOL4 v114; // [xsp+28h] [xbp-38h]
  int v115; // [xsp+30h] [xbp-30h]
  char v116; // [xsp+38h] [xbp-28h]
  __int64 v117; // [xsp+38h] [xbp-28h]
  char v119[4]; // [xsp+44h] [xbp-1Ch] BYREF
  __int64 v120; // [xsp+48h] [xbp-18h] BYREF
  const void *v121[2]; // [xsp+50h] [xbp-10h] BYREF

  v121[1] = *(const void **)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid parameters", a9, a10, a11, a12, a13, a14, a15, a16, "rrm_fill_beacon_ies");
    v34 = 0;
    goto LABEL_63;
  }
  v18 = a1;
  if ( a6 )
    v20 = a7;
  else
    v20 = 0;
  if ( a3 )
    v21 = a4;
  else
    v21 = 0;
  qdf_trace_msg(0x35u, 2u, "%s: extn_eids_count %d", a9, a10, a11, a12, a13, a14, a15, a16, "rrm_fill_beacon_ies", a7);
  v32 = *a17;
  v33 = v32 - 102;
  if ( (unsigned __int16)(v32 - 102) < (unsigned int)(unsigned __int16)a8 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid start offset %d Bcn IE len %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "rrm_fill_beacon_ies",
      (unsigned __int16)a8);
    v34 = 0;
    goto LABEL_63;
  }
  v116 = v21;
  v120 = 0;
  v121[0] = nullptr;
  v119[0] = 0;
  util_find_mlie(a17 + 52, (unsigned __int16)(v32 - 102), v121, &v120);
  v115 = v33;
  if ( !v121[0] )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: [802.11 BCN_RPT]: Not ML AP total_len:%d",
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      "rrm_check_ml_ie",
      (unsigned __int16)v33);
    goto LABEL_18;
  }
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: [802.11 BCN_RPT]: ML IE is present ml_ie_total_len:%zu",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "rrm_check_ml_ie",
    v120);
  util_get_mlie_common_info_len(v121[0], v120, v119);
  v51 = v119[0];
  v52 = v119[0] + 5;
  if ( v119[0] == -5 )
  {
LABEL_18:
    v65 = 0;
    v64 = 0;
    goto LABEL_19;
  }
  v53 = (void *)_qdf_mem_malloc((unsigned __int8)(v119[0] + 5), "rrm_check_ml_ie", 1447);
  if ( !v53 )
  {
    qdf_trace_msg(0x8Fu, 2u, "%s: malloc failed", v54, v55, v56, v57, v58, v59, v60, v61, "rrm_check_ml_ie");
    goto LABEL_18;
  }
  v62 = v20;
  v63 = (__int64)v53;
  qdf_mem_copy(v53, v121[0], v52);
  v64 = v63;
  v20 = v62;
  LOWORD(v33) = v115;
  v65 = v51 + 5;
  *(_BYTE *)(v64 + 1) = v51 + 3;
LABEL_19:
  v66 = v33 - a8;
  *a2 = 0;
  if ( !(_WORD)a8 )
  {
    *v18 = *((_DWORD *)a17 + 2);
    *a2 += 4;
    v18[1] = *((_DWORD *)a17 + 3);
    *a2 += 4;
    *((_WORD *)v18 + 4) = a17[8];
    *a2 += 2;
    *((_WORD *)v18 + 5) = a17[9];
    v18 += 3;
    *a2 += 2;
  }
  if ( (unsigned __int16)(v33 - a8) < 2u )
  {
    v34 = 0;
  }
  else
  {
    v67 = v20;
    n_4 = v65;
    v113 = (const void *)v64;
    v68 = (unsigned __int8 *)a17 + (unsigned __int16)a8 + 104;
    n = v65;
    LOBYTE(v69) = v67 + v116;
    v70 = v65 != 0;
    if ( !v64 )
      v70 = 0;
    v114 = v70;
    v110 = v65;
    if ( (v69 & 0xFE) != 0 )
      v69 = (unsigned __int8)v69;
    else
      v69 = 1;
    v117 = v69;
    while ( 1 )
    {
      v71 = v68[1];
      v72 = v71 + 2;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: EID = %d, len = %d total = %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "rrm_fill_beacon_ies",
        *v68,
        v71,
        (unsigned int)(v71 + 2));
      if ( *v68 == 255 && v68[2] )
        qdf_trace_msg(0x35u, 8u, "%s: Extended EID = %d", v43, v44, v45, v46, v47, v48, v49, v50, "rrm_fill_beacon_ies");
      if ( !(_DWORD)v71 || v72 > v66 )
        break;
      if ( a3 )
      {
        v73 = *v68;
        v74 = v117;
        v75 = a6;
        v76 = a3;
        if ( a6 )
          v77 = v73 == a5;
        else
          v77 = 0;
        v78 = v77;
        while ( 1 )
        {
          v79 = *v76++;
          if ( v73 == v79 || v78 && v68[2] == *v75 )
            break;
          --v74;
          ++v75;
          if ( !v74 )
            goto LABEL_32;
        }
      }
      v80 = *a2;
      if ( v72 + v80 > 0xD6 )
      {
        if ( (_WORD)a8 )
          v34 = v115 - a8 - v80;
        else
          v34 = v115 - a8 - v80 + 12;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: rem_len %d ies added %d",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "rrm_fill_beacon_ies",
          (unsigned __int16)v34);
        if ( (_WORD)v34 )
          goto LABEL_61;
      }
      else
      {
        v81 = v114;
        if ( !v18 )
          v81 = 0;
        if ( (unsigned int)*v68 - 255 <= 0xFFFFFF01 && v68[2] == 107 && v81 )
        {
          qdf_mem_copy(v18, v113, n);
          qdf_trace_msg(0x35u, 8u, "%s: Dump ML IE:", v82, v83, v84, v85, v86, v87, v88, v89, "rrm_copy_ml_ie");
          ((void (__fastcall *)(__int64, __int64, const void *, _QWORD))qdf_trace_hex_dump)(53, 8, v113, n);
          v98 = n;
          v99 = *a2 + n_4;
          v100 = v110;
        }
        else
        {
          qdf_mem_copy(v18, v68, v72);
          v98 = v72;
          v100 = v71 + 2;
          v99 = *a2 + v72;
        }
        v18 = (_DWORD *)((char *)v18 + v100);
        *a2 = v99;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: ies_filled_len:%d last_filled_ie_len:%d",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "rrm_fill_beacon_ies",
          v99,
          v98);
      }
LABEL_32:
      v66 -= v72;
      v68 += v72;
      if ( v66 <= 1u )
        goto LABEL_60;
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: RRM: Invalid IE len:%d exp_len:%d",
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49,
      v50,
      "rrm_fill_beacon_ies",
      v72,
      v66);
LABEL_60:
    v34 = 0;
LABEL_61:
    v64 = (__int64)v113;
  }
  _qdf_mem_free(v64);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Total length of Ies added = %d rem_len %d",
    v101,
    v102,
    v103,
    v104,
    v105,
    v106,
    v107,
    v108,
    "rrm_fill_beacon_ies",
    *a2,
    (unsigned __int16)v34);
LABEL_63:
  _ReadStatusReg(SP_EL0);
  return v34;
}
