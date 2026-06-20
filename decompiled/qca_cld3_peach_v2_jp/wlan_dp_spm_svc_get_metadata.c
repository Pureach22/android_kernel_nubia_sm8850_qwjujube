__int64 __fastcall wlan_dp_spm_svc_get_metadata(_QWORD *a1, __int64 a2, unsigned __int16 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  __int64 v5; // x9
  __int64 v6; // x8
  __int64 v7; // x26
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x20
  __int64 v14; // x8
  int v15; // w8
  bool v16; // zf
  int v17; // w8
  __int64 v18; // x11
  unsigned int v19; // w10
  unsigned int v20; // w9
  int v21; // w9
  _QWORD *v22; // x8
  __int64 v23; // x10
  unsigned __int8 *v24; // x9
  __int64 v25; // x10
  int v26; // w9
  unsigned __int64 v27; // x11
  unsigned __int64 v28; // x12
  unsigned __int16 *v29; // x8
  unsigned __int16 *v30; // x11
  unsigned int v31; // w12
  int v32; // w9
  int v33; // w9
  unsigned int v34; // w22
  unsigned int v35; // w8
  int v36; // w3
  unsigned __int16 v37; // w0
  unsigned __int16 v38; // w23
  __int16 v39; // w0
  __int16 v40; // w21
  __int16 v41; // w0
  unsigned __int16 v42; // w21
  __int16 v43; // w0
  unsigned __int16 v44; // w0
  unsigned __int16 v45; // w24
  __int16 v46; // w0
  __int16 v47; // w21
  __int16 v48; // w0
  unsigned __int16 v49; // w21
  __int16 v50; // w0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  int v59; // w8
  int v60; // w10
  __int64 v61; // x9
  unsigned __int64 v62; // x13
  unsigned int v63; // w14
  unsigned __int64 v64; // x10
  __int64 v65; // x12
  unsigned __int64 v66; // x15
  unsigned __int64 v67; // x11
  unsigned int v68; // w8
  int v69; // w16
  __int64 v70; // x1
  unsigned __int64 v71; // x8
  unsigned __int64 v72; // x9
  __int64 v73; // x13
  unsigned __int64 v74; // x8
  int v75; // w9
  int v76; // w8
  __int16 v77; // w8
  unsigned int v78; // [xsp+4h] [xbp-24Ch]
  _QWORD v80[32]; // [xsp+10h] [xbp-240h] BYREF
  __int64 v81; // [xsp+110h] [xbp-140h] BYREF
  __int64 v82; // [xsp+118h] [xbp-138h] BYREF
  __int64 v83; // [xsp+120h] [xbp-130h]
  __int64 v84; // [xsp+128h] [xbp-128h] BYREF
  __int64 v85; // [xsp+130h] [xbp-120h]
  __int64 v86; // [xsp+138h] [xbp-118h]
  __int64 v87; // [xsp+140h] [xbp-110h]
  __int64 v88; // [xsp+148h] [xbp-108h]
  __int64 v89; // [xsp+150h] [xbp-100h]
  __int64 v90; // [xsp+158h] [xbp-F8h]
  __int64 v91; // [xsp+160h] [xbp-F0h]
  __int64 v92; // [xsp+168h] [xbp-E8h]
  __int64 v93; // [xsp+170h] [xbp-E0h]
  __int64 v94; // [xsp+178h] [xbp-D8h]
  __int64 v95; // [xsp+180h] [xbp-D0h]
  __int64 v96; // [xsp+188h] [xbp-C8h]
  __int64 v97; // [xsp+190h] [xbp-C0h]
  __int64 v98; // [xsp+198h] [xbp-B8h]
  __int64 v99; // [xsp+1A0h] [xbp-B0h]
  __int64 v100; // [xsp+1A8h] [xbp-A8h]
  __int64 v101; // [xsp+1B0h] [xbp-A0h]
  __int64 v102; // [xsp+1B8h] [xbp-98h]
  __int64 v103; // [xsp+1C0h] [xbp-90h]
  __int64 v104; // [xsp+1C8h] [xbp-88h]
  __int64 v105; // [xsp+1D0h] [xbp-80h]
  __int64 v106; // [xsp+1D8h] [xbp-78h]
  __int64 v107; // [xsp+1E0h] [xbp-70h]
  __int64 v108; // [xsp+1E8h] [xbp-68h]
  __int64 v109; // [xsp+1F0h] [xbp-60h]
  __int64 v110; // [xsp+1F8h] [xbp-58h]
  __int64 v111; // [xsp+200h] [xbp-50h]
  __int64 v112; // [xsp+208h] [xbp-48h]
  _QWORD v113[2]; // [xsp+210h] [xbp-40h] BYREF
  _QWORD v114[2]; // [xsp+220h] [xbp-30h] BYREF
  __int64 v115; // [xsp+230h] [xbp-20h]
  __int64 v116; // [xsp+238h] [xbp-18h]
  __int64 v117; // [xsp+240h] [xbp-10h]

  v117 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a3 >= 0x41u )
    goto LABEL_67;
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = a1[467];
  *(_DWORD *)(StatusReg + 16) += 512;
  v6 = *(_QWORD *)(v5 + 8LL * a3);
  if ( !v6 || (v7 = v6 - 16, v6 == 16) )
  {
LABEL_7:
    local_bh_enable_7();
    result = 17;
    goto LABEL_60;
  }
  while ( *(_QWORD *)(v7 + 120) != a4 )
  {
    v9 = *(_QWORD *)(v7 + 16);
    if ( v9 )
    {
      v7 = v9 - 16;
      if ( v9 != 16 )
        continue;
    }
    goto LABEL_7;
  }
  v11 = local_bh_enable_7();
  v13 = sched_clock(v11, v12);
  ++*(_QWORD *)(v7 + 152);
  dp_get_context();
  v14 = *(_QWORD *)(a2 + 24);
  v115 = 0;
  v116 = 0;
  v114[0] = 0;
  v114[1] = 0;
  LOWORD(v14) = *(_WORD *)(v14 + 564);
  v113[0] = 0;
  v113[1] = 0;
  if ( (v14 & 0xFFFE) != 2
    || (*(_BYTE *)(v7 + 152) & 7) != 0 && (unsigned __int64)(v13 - *(_QWORD *)(v7 + 144)) < 0x3B9ACA01 )
  {
    goto LABEL_55;
  }
  v15 = *(unsigned __int16 *)(a2 + 180);
  LODWORD(v86) = 0;
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v81 = 0;
  if ( v15 == 56710 )
  {
    v22 = (_QWORD *)(*(_QWORD *)(a2 + 216) + *(unsigned __int16 *)(a2 + 184));
    v23 = v22[2];
    v82 = v22[1];
    v83 = v23;
    v25 = v22[4];
    v84 = v22[3];
    v85 = v25;
    v24 = (unsigned __int8 *)v22 + 6;
    for ( LOBYTE(v25) = 40; ; LOBYTE(v25) = v25 + 8 * v24[1] + 8 )
    {
      v26 = *v24;
      if ( v26 <= 42 )
      {
        if ( v26 )
        {
          if ( v26 != 6 )
          {
            if ( v26 == 17 )
            {
              v27 = *(unsigned int *)(a2 + 112);
              v25 = (unsigned __int8)v25;
              v28 = (unsigned __int8)v25 + 8LL;
              goto LABEL_29;
            }
            goto LABEL_30;
          }
          v27 = *(unsigned int *)(a2 + 112);
          v25 = (unsigned __int8)v25;
          v28 = (unsigned __int8)v25 + 20LL;
LABEL_29:
          if ( v28 > v27 )
          {
LABEL_30:
            v17 = 0;
            goto LABEL_35;
          }
          v29 = (unsigned __int16 *)((char *)v22 + v25);
          WORD1(v81) = bswap32(*v29) >> 16;
          LODWORD(v29) = v29[1];
          LOBYTE(v81) = v26;
          LOWORD(v115) = WORD1(v81);
          WORD2(v81) = bswap32((unsigned int)v29) >> 16;
          WORD1(v115) = WORD2(v81);
          qdf_mem_copy(v113, &v82, 0x10u);
          qdf_mem_copy(v114, &v84, 0x10u);
          v17 = (unsigned __int8)v81;
          v21 = v116 | 0x67;
LABEL_33:
          BYTE4(v115) = v17;
          goto LABEL_34;
        }
      }
      else if ( v26 != 60 && v26 != 43 )
      {
        goto LABEL_30;
      }
      v24 = (unsigned __int8 *)v22 + (unsigned __int8)v25;
    }
  }
  v16 = v15 == 8;
  v17 = 0;
  if ( v16 )
  {
    v18 = *(_QWORD *)(a2 + 224);
    v17 = *(unsigned __int8 *)(v18 + 23);
    v19 = *(_DWORD *)(v18 + 26);
    v20 = *(_DWORD *)(v18 + 30);
    if ( v17 != 17 && v17 != 6 )
      goto LABEL_30;
    if ( (*(_WORD *)(v18 + 20) & 0xFF1F) == 0 )
    {
      v30 = (unsigned __int16 *)(v18 + 14 + 4LL * (*(_BYTE *)(v18 + 14) & 0xF));
      v31 = *v30;
      LODWORD(v30) = v30[1];
      LODWORD(v113[0]) = bswap32(v19);
      LODWORD(v114[0]) = bswap32(v20);
      v21 = 31;
      LOWORD(v115) = bswap32(v31) >> 16;
      WORD1(v115) = bswap32((unsigned int)v30) >> 16;
      goto LABEL_33;
    }
    v17 = 0;
    v21 = 128;
LABEL_34:
    LODWORD(v116) = v21;
  }
LABEL_35:
  v32 = *(_DWORD *)(v7 + 92);
  if ( (v32 & 0x1F) != 0 )
  {
    if ( LODWORD(v113[0]) == *(_DWORD *)(v7 + 52)
      && LODWORD(v114[0]) == *(_DWORD *)(v7 + 68)
      && __PAIR64__(WORD1(v115), (unsigned __int16)v115) == __PAIR64__(
                                                              *(unsigned __int16 *)(v7 + 86),
                                                              *(unsigned __int16 *)(v7 + 84)) )
    {
      v33 = *(unsigned __int8 *)(v7 + 88);
      goto LABEL_44;
    }
  }
  else if ( (v32 & 0x60) != 0
         && !(unsigned int)qdf_mem_cmp(v114, (const void *)(v7 + 68), 0x10u)
         && !(unsigned int)qdf_mem_cmp(v114, (const void *)(v7 + 68), 0x10u) )
  {
    v17 = HIDWORD(v116);
    v33 = *(_DWORD *)(v7 + 96);
LABEL_44:
    if ( v17 == v33 )
      goto LABEL_55;
  }
  v112 = 0;
  v110 = 0;
  v111 = 0;
  v108 = 0;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  v98 = 0;
  v99 = 0;
  v96 = 0;
  v97 = 0;
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v88 = 0;
  v89 = 0;
  v86 = 0;
  v87 = 0;
  v81 = 0;
  v34 = *(_DWORD *)(v7 + 104);
  v35 = *(unsigned __int16 *)(v7 + 48);
  v36 = *(_DWORD *)(v7 + 52);
  v84 = 0;
  v85 = 0;
  v82 = 0;
  v83 = 0;
  v78 = v35;
  memset(v80, 0, sizeof(v80));
  scnprintf(&v81, 256, "0x%x", v36);
  v38 = v37;
  scnprintf((char *)&v81 + v37, 256 - v37, " 0x%x", *(_DWORD *)(v7 + 68));
  v40 = v39 + v38;
  scnprintf(
    (char *)&v81 + (unsigned __int16)(v39 + v38),
    256 - (unsigned __int16)(v39 + v38),
    " %u",
    *(unsigned __int16 *)(v7 + 84));
  v42 = v41 + v40;
  scnprintf((char *)&v81 + v42, 256 - v42, " %u", *(unsigned __int16 *)(v7 + 86));
  scnprintf(
    (char *)&v81 + (unsigned __int16)(v43 + v42),
    256 - (unsigned __int16)(v43 + v42),
    " %u",
    *(unsigned __int8 *)(v7 + 88));
  scnprintf(v80, 256, "0x%x", LODWORD(v113[0]));
  v45 = v44;
  scnprintf((char *)v80 + v44, 256 - v44, " 0x%x", LODWORD(v114[0]));
  v47 = v46 + v45;
  scnprintf(
    (char *)v80 + (unsigned __int16)(v46 + v45),
    256 - (unsigned __int16)(v46 + v45),
    " %u",
    (unsigned __int16)v115);
  v49 = v48 + v47;
  scnprintf((char *)v80 + v49, 256 - v49, " %u", WORD1(v115));
  v51 = scnprintf((char *)v80 + (unsigned __int16)(v50 + v49), 256 - (unsigned __int16)(v50 + v49), " %u", BYTE4(v115));
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: Flow %d mdata 0x%x old_tuple %s new_tuple %s",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    "dp_spm_check_n_update_flow_info",
    v78,
    v34,
    &v81,
    v80);
  qdf_mem_copy((void *)(v7 + 52), v113, 0x30u);
  v59 = *(_DWORD *)(v7 + 92);
  v60 = flow_guid_gen;
  *(_QWORD *)(v7 + 152) = 1;
  *(_QWORD *)(v7 + 136) = v13;
  *(_DWORD *)(v7 + 104) = v60;
  flow_guid_gen = v60 + 1;
  if ( (v59 & 8) != 0 )
  {
    v68 = *(_DWORD *)(v7 + 68);
    v63 = *(_DWORD *)(v7 + 52);
    v61 = 0;
    v62 = 0;
    v64 = 0;
    v65 = 0;
    v66 = 0;
    v67 = 0;
    *(_BYTE *)(v7 + 100) = 1;
  }
  else if ( (v59 & 0x20) != 0 )
  {
    v68 = *(_DWORD *)(v7 + 68);
    v61 = *(unsigned int *)(v7 + 76);
    v63 = *(_DWORD *)(v7 + 52);
    v65 = *(unsigned int *)(v7 + 60);
    v67 = (unsigned __int64)*(unsigned int *)(v7 + 72) << 32;
    v62 = (unsigned __int64)*(unsigned int *)(v7 + 80) << 32;
    v64 = (unsigned __int64)*(unsigned int *)(v7 + 56) << 32;
    v66 = (unsigned __int64)*(unsigned int *)(v7 + 64) << 32;
  }
  else
  {
    v61 = 0;
    v62 = 0;
    v63 = 0;
    v64 = 0;
    v65 = 0;
    v66 = 0;
    v67 = 0;
    v68 = 0;
  }
  v69 = *(unsigned __int8 *)(v7 + 88);
  v70 = 0xEA00000000LL;
  v71 = v67 | v68;
  v72 = (v62 | v61) ^ (v66 | v65) ^ (v64 | v63);
  v73 = 0x100000000LL;
  if ( v69 == 17 )
    v70 = 0;
  v74 = v72 ^ v71;
  if ( v69 != 6 )
    v73 = v70;
  *(_QWORD *)(v7 + 168) = v74
                        ^ 0x574C414E5F44505FLL
                        ^ (v73
                         | ((unsigned __int64)*(unsigned __int16 *)(v7 + 84) << 16)
                         | *(unsigned __int16 *)(v7 + 86));
LABEL_55:
  v75 = *(unsigned __int8 *)(v7 + 161);
  *(_QWORD *)(v7 + 144) = v13;
  if ( v75 && (*(_BYTE *)(a2 + 71) & 0x78) != 0x48 )
  {
    if ( *(unsigned __int16 *)(v7 + 48) < 0x101u )
    {
      if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
        v77 = *(_WORD *)(a2 + 66);
      else
        v77 = 0;
      wlan_dp_stc_track_flow_features(
        *(_QWORD *)(*a1 + 2936LL),
        a2,
        (unsigned __int64 *)(*(_QWORD *)(*(_QWORD *)(*a1 + 2936LL) + 6416LL) + 392LL * *(unsigned __int16 *)(v7 + 48)),
        *(unsigned __int8 *)(a1[458] + 24LL),
        *(unsigned __int16 *)(v7 + 108),
        *(_DWORD *)(a2 + 112) + v77 - 14,
        *(_DWORD *)(v7 + 104));
      goto LABEL_56;
    }
LABEL_67:
    __break(0x5512u);
  }
LABEL_56:
  if ( *(_BYTE *)(v7 + 163) == 2 && (v76 = *(unsigned __int8 *)(v7 + 184), v76 != 31) )
  {
    result = 0;
    *(_DWORD *)(a2 + 168) = v76 | 0xCAFD0000;
  }
  else
  {
    result = 9;
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}
