__int64 __fastcall wlan_cm_init_score_config(__int64 a1, unsigned __int8 *a2)
{
  int v4; // w9
  __int64 values; // x0
  int v6; // w9
  int v7; // w21
  int v8; // w28
  int v9; // w23
  int v10; // w24
  int v11; // w26
  int v12; // w25
  int v13; // w27
  int v14; // w8
  int v15; // w22
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w8
  unsigned int v26; // w8
  unsigned int v27; // w9
  int v28; // w8
  unsigned int v29; // w9
  int v30; // w8
  unsigned int v31; // w9
  int v32; // w8
  unsigned int v33; // w9
  int v34; // w8
  unsigned int v35; // w9
  int v36; // w8
  unsigned int v37; // w9
  int v38; // w8
  unsigned int v39; // w9
  int v40; // w8
  unsigned int v41; // w9
  int v42; // w8
  char v43; // w8
  unsigned __int8 v44; // w9
  unsigned int v45; // w9
  int v46; // w8
  unsigned int v47; // w9
  int v48; // w8
  unsigned int v49; // w9
  int v50; // w8
  unsigned int v51; // w9
  int v52; // w8
  unsigned int v53; // w9
  int v54; // w8
  unsigned int v55; // w9
  int v56; // w8
  unsigned int v57; // w9
  int v58; // w8
  unsigned int v59; // w9
  int v60; // w8
  unsigned int v61; // w9
  int v62; // w8
  unsigned int v63; // w9
  int v64; // w8
  __int64 result; // x0
  unsigned int v66; // w9
  unsigned int v67; // w8
  int v68; // [xsp+0h] [xbp-20h]
  int v69; // [xsp+4h] [xbp-1Ch]
  int v70; // [xsp+8h] [xbp-18h]
  int v71; // [xsp+Ch] [xbp-14h]
  int v72; // [xsp+10h] [xbp-10h]
  int v73; // [xsp+14h] [xbp-Ch]
  int v74; // [xsp+18h] [xbp-8h]
  int v75; // [xsp+1Ch] [xbp-4h]

  *a2 = *(_DWORD *)(cfg_psoc_get_values(a1) + 872);
  a2[1] = *(_DWORD *)(cfg_psoc_get_values(a1) + 876);
  a2[2] = *(_DWORD *)(cfg_psoc_get_values(a1) + 880);
  a2[3] = *(_DWORD *)(cfg_psoc_get_values(a1) + 884);
  a2[4] = *(_DWORD *)(cfg_psoc_get_values(a1) + 888);
  a2[5] = *(_DWORD *)(cfg_psoc_get_values(a1) + 892);
  a2[6] = *(_DWORD *)(cfg_psoc_get_values(a1) + 896);
  a2[7] = *(_DWORD *)(cfg_psoc_get_values(a1) + 900);
  a2[8] = *(_DWORD *)(cfg_psoc_get_values(a1) + 904);
  a2[9] = *(_DWORD *)(cfg_psoc_get_values(a1) + 908);
  a2[10] = *(_DWORD *)(cfg_psoc_get_values(a1) + 912);
  a2[11] = *(_DWORD *)(cfg_psoc_get_values(a1) + 916);
  a2[12] = *(_DWORD *)(cfg_psoc_get_values(a1) + 920);
  v4 = *(_DWORD *)(cfg_psoc_get_values(a1) + 924);
  a2[25] = 4;
  a2[13] = v4;
  values = cfg_psoc_get_values(a1);
  v6 = a2[7];
  v7 = *(_DWORD *)(values + 928);
  v8 = *a2;
  v9 = a2[2];
  v68 = a2[1];
  v10 = a2[5];
  v11 = a2[6];
  v12 = a2[10];
  v13 = a2[11];
  v73 = a2[3];
  v14 = a2[4];
  v15 = a2[12];
  a2[26] = v7;
  v75 = v14;
  v71 = v6;
  v72 = a2[8];
  v74 = a2[9];
  v69 = a2[13];
  v70 = a2[25];
  a2[14] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1040);
  *((_DWORD *)a2 + 4) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1088);
  a2[24] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1096);
  a2[20] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1052);
  a2[23] = a2[23] & 0xFE | *(_BYTE *)(cfg_psoc_get_values(a1) + 1058);
  a2[21] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1044);
  a2[23] = a2[23] & 0xFD | (2 * *(_BYTE *)(cfg_psoc_get_values(a1) + 1056));
  a2[22] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1048);
  a2[23] = a2[23] & 0xFB | (4 * *(_BYTE *)(cfg_psoc_get_values(a1) + 1057));
  v16 = cfg_psoc_get_values(a1);
  v25 = v8
      + (unsigned __int8)v7
      + v68
      + v9
      + v73
      + v75
      + v10
      + v11
      + v71
      + v72
      + v74
      + v12
      + v13
      + v15
      + v69
      + v70
      + a2[14]
      + a2[24];
  a2[136] = *(_DWORD *)(v16 + 1092);
  if ( v25 >= 0xC9 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Total weight greater than %d, using default weights",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "wlan_cm_init_score_config",
      200);
    a2[14] = 2;
    a2[24] = 2;
    *((_DWORD *)a2 + 2) = 84018442;
    *(_QWORD *)a2 = 0x214020C02010214LL;
    *((_WORD *)a2 + 6) = 7683;
    a2[26] = 20;
  }
  a2[28] = *(_DWORD *)(cfg_psoc_get_values(a1) + 932);
  a2[29] = *(_DWORD *)(cfg_psoc_get_values(a1) + 936);
  a2[30] = *(_DWORD *)(cfg_psoc_get_values(a1) + 940);
  a2[31] = *(_DWORD *)(cfg_psoc_get_values(a1) + 944);
  a2[32] = *(_DWORD *)(cfg_psoc_get_values(a1) + 948);
  a2[33] = *(_DWORD *)(cfg_psoc_get_values(a1) + 952);
  a2[34] = *(_DWORD *)(cfg_psoc_get_values(a1) + 956);
  a2[35] = *(_DWORD *)(cfg_psoc_get_values(a1) + 960);
  a2[36] = *(_DWORD *)(cfg_psoc_get_values(a1) + 964);
  a2[40] = *(_DWORD *)(cfg_psoc_get_values(a1) + 980);
  v26 = *(_DWORD *)(cfg_psoc_get_values(a1) + 984);
  if ( (unsigned __int8)v26 > 0x64u )
    v26 = v26 & 0xFFFFFF00 | 0x64;
  if ( (v26 & 0xFF00) > 0x6400 )
    v26 = v26 & 0xFFFF00FF | 0x6400;
  if ( (v26 & 0xFF0000) > 0x640000 )
    v26 = v26 & 0xFF00FFFF | 0x640000;
  if ( HIBYTE(v26) > 0x64u )
    v26 = v26 & 0xFFFFFF | 0x64000000;
  *((_DWORD *)a2 + 11) = v26;
  v27 = *(_DWORD *)(cfg_psoc_get_values(a1) + 988);
  if ( (unsigned __int8)v27 > 0x64u )
    v27 = v27 & 0xFFFFFF00 | 0x64;
  if ( (v27 & 0xFF00) > 0x6400 )
    v27 = v27 & 0xFFFF00FF | 0x6400;
  if ( (v27 & 0xFF0000) > 0x640000 )
    v27 = v27 & 0xFF00FFFF | 0x640000;
  v28 = v27 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v27) <= 0x64u )
    v28 = v27;
  *((_DWORD *)a2 + 12) = v28;
  v29 = *(_DWORD *)(cfg_psoc_get_values(a1) + 992);
  if ( (unsigned __int8)v29 > 0x64u )
    v29 = v29 & 0xFFFFFF00 | 0x64;
  if ( (v29 & 0xFF00) > 0x6400 )
    v29 = v29 & 0xFFFF00FF | 0x6400;
  if ( (v29 & 0xFF0000) > 0x640000 )
    v29 = v29 & 0xFF00FFFF | 0x640000;
  v30 = v29 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v29) <= 0x64u )
    v30 = v29;
  *((_DWORD *)a2 + 13) = v30;
  v31 = *(_DWORD *)(cfg_psoc_get_values(a1) + 996);
  if ( (unsigned __int8)v31 > 0x64u )
    v31 = v31 & 0xFFFFFF00 | 0x64;
  if ( (v31 & 0xFF00) > 0x6400 )
    v31 = v31 & 0xFFFF00FF | 0x6400;
  if ( (v31 & 0xFF0000) > 0x640000 )
    v31 = v31 & 0xFF00FFFF | 0x640000;
  v32 = v31 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v31) <= 0x64u )
    v32 = v31;
  *((_DWORD *)a2 + 14) = v32;
  a2[60] = *(_DWORD *)(cfg_psoc_get_values(a1) + 1000);
  v33 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1004);
  if ( (unsigned __int8)v33 > 0x64u )
    v33 = v33 & 0xFFFFFF00 | 0x64;
  if ( (v33 & 0xFF00) > 0x6400 )
    v33 = v33 & 0xFFFF00FF | 0x6400;
  if ( (v33 & 0xFF0000) > 0x640000 )
    v33 = v33 & 0xFF00FFFF | 0x640000;
  v34 = v33 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v33) <= 0x64u )
    v34 = v33;
  *((_DWORD *)a2 + 16) = v34;
  v35 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1008);
  if ( (unsigned __int8)v35 > 0x64u )
    v35 = v35 & 0xFFFFFF00 | 0x64;
  if ( (v35 & 0xFF00) > 0x6400 )
    v35 = v35 & 0xFFFF00FF | 0x6400;
  if ( (v35 & 0xFF0000) > 0x640000 )
    v35 = v35 & 0xFF00FFFF | 0x640000;
  v36 = v35 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v35) <= 0x64u )
    v36 = v35;
  *((_DWORD *)a2 + 17) = v36;
  v37 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1012);
  if ( (unsigned __int8)v37 > 0x64u )
    v37 = v37 & 0xFFFFFF00 | 0x64;
  if ( (v37 & 0xFF00) > 0x6400 )
    v37 = v37 & 0xFFFF00FF | 0x6400;
  if ( (v37 & 0xFF0000) > 0x640000 )
    v37 = v37 & 0xFF00FFFF | 0x640000;
  v38 = v37 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v37) <= 0x64u )
    v38 = v37;
  *((_DWORD *)a2 + 18) = v38;
  v39 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1016);
  if ( (unsigned __int8)v39 > 0x64u )
    v39 = v39 & 0xFFFFFF00 | 0x64;
  if ( (v39 & 0xFF00) > 0x6400 )
    v39 = v39 & 0xFFFF00FF | 0x6400;
  if ( (v39 & 0xFF0000) > 0x640000 )
    v39 = v39 & 0xFF00FFFF | 0x640000;
  v40 = v39 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v39) <= 0x64u )
    v40 = v39;
  *((_DWORD *)a2 + 19) = v40;
  v41 = *(_DWORD *)(cfg_psoc_get_values(a1) + 976);
  if ( (unsigned __int8)v41 > 0x64u )
    v41 = v41 & 0xFFFFFF00 | 0x64;
  if ( (v41 & 0xFF00) > 0x6400 )
    v41 = v41 & 0xFFFF00FF | 0x6400;
  if ( (v41 & 0xFF0000) > 0x640000 )
    v41 = v41 & 0xFF00FFFF | 0x640000;
  v42 = v41 & 0xFFFFFF | 0x64000000;
  if ( HIBYTE(v41) <= 0x64u )
    v42 = v41;
  *((_DWORD *)a2 + 31) = v42;
  a2[128] = a2[128] & 0xFE | *(_BYTE *)(cfg_psoc_get_values(a1) + 1020) & 1;
  v43 = *(_BYTE *)(cfg_psoc_get_values(a1) + 1024);
  v44 = a2[128];
  if ( v43 )
    a2[26] = 0;
  a2[128] = v44 & 0xFB | (4 * v43) | 2;
  a2[128] = a2[128] & 0xF7 | (8 * *(_BYTE *)(cfg_psoc_get_values(a1) + 1025));
  *((_DWORD *)a2 + 33) = *(_DWORD *)(cfg_psoc_get_values(a1) + 1028);
  v45 = *(_DWORD *)(cfg_psoc_get_values(a1) + 968);
  if ( (unsigned __int8)v45 > 0x64u )
    v45 = v45 & 0xFFFFFF00 | 0x64;
  if ( (v45 & 0xFF00) > 0x6400 )
    v45 = v45 & 0xFFFF00FF | 0x6400;
  if ( (v45 & 0xFF0000) > 0x640000 )
    v45 = v45 & 0xFF00FFFF | 0x640000;
  v46 = v45 & 0xFFFFFF | 0x64000000;
  if ( v45 <= 0x64FFFFFF )
    v46 = v45;
  *((_DWORD *)a2 + 20) = v46;
  v47 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1032);
  if ( (unsigned __int8)v47 > 0x64u )
    v47 = v47 & 0xFFFFFF00 | 0x64;
  if ( (v47 & 0xFF00) > 0x6400 )
    v47 = v47 & 0xFFFF00FF | 0x6400;
  if ( (v47 & 0xFF0000) > 0x640000 )
    v47 = v47 & 0xFF00FFFF | 0x640000;
  v48 = v47 & 0xFFFFFF | 0x64000000;
  if ( v47 <= 0x64FFFFFF )
    v48 = v47;
  *((_DWORD *)a2 + 21) = v48;
  v49 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1036);
  if ( (unsigned __int8)v49 > 0x64u )
    v49 = v49 & 0xFFFFFF00 | 0x64;
  if ( (v49 & 0xFF00) > 0x6400 )
    v49 = v49 & 0xFFFF00FF | 0x6400;
  if ( (v49 & 0xFF0000) > 0x640000 )
    v49 = v49 & 0xFF00FFFF | 0x640000;
  v50 = v49 & 0xFFFFFF | 0x64000000;
  if ( v49 <= 0x64FFFFFF )
    v50 = v49;
  *((_DWORD *)a2 + 22) = v50;
  v51 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1060);
  if ( (unsigned __int8)v51 > 0x64u )
    v51 = v51 & 0xFFFFFF00 | 0x64;
  if ( (v51 & 0xFF00) > 0x6400 )
    v51 = v51 & 0xFFFF00FF | 0x6400;
  if ( (v51 & 0xFF0000) > 0x640000 )
    v51 = v51 & 0xFF00FFFF | 0x640000;
  v52 = v51 & 0xFFFFFF | 0x64000000;
  if ( v51 <= 0x64FFFFFF )
    v52 = v51;
  *((_DWORD *)a2 + 23) = v52;
  v53 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1064);
  if ( (unsigned __int8)v53 > 0x64u )
    v53 = v53 & 0xFFFFFF00 | 0x64;
  if ( (v53 & 0xFF00) > 0x6400 )
    v53 = v53 & 0xFFFF00FF | 0x6400;
  if ( (v53 & 0xFF0000) > 0x640000 )
    v53 = v53 & 0xFF00FFFF | 0x640000;
  v54 = v53 & 0xFFFFFF | 0x64000000;
  if ( v53 <= 0x64FFFFFF )
    v54 = v53;
  *((_DWORD *)a2 + 24) = v54;
  v55 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1068);
  if ( (unsigned __int8)v55 > 0x64u )
    v55 = v55 & 0xFFFFFF00 | 0x64;
  if ( (v55 & 0xFF00) > 0x6400 )
    v55 = v55 & 0xFFFF00FF | 0x6400;
  if ( (v55 & 0xFF0000) > 0x640000 )
    v55 = v55 & 0xFF00FFFF | 0x640000;
  v56 = v55 & 0xFFFFFF | 0x64000000;
  if ( v55 <= 0x64FFFFFF )
    v56 = v55;
  *((_DWORD *)a2 + 25) = v56;
  v57 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1072);
  if ( (unsigned __int8)v57 > 0x64u )
    v57 = v57 & 0xFFFFFF00 | 0x64;
  if ( (v57 & 0xFF00) > 0x6400 )
    v57 = v57 & 0xFFFF00FF | 0x6400;
  if ( (v57 & 0xFF0000) > 0x640000 )
    v57 = v57 & 0xFF00FFFF | 0x640000;
  v58 = v57 & 0xFFFFFF | 0x64000000;
  if ( v57 <= 0x64FFFFFF )
    v58 = v57;
  *((_DWORD *)a2 + 26) = v58;
  v59 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1076);
  if ( (unsigned __int8)v59 > 0x64u )
    v59 = v59 & 0xFFFFFF00 | 0x64;
  if ( (v59 & 0xFF00) > 0x6400 )
    v59 = v59 & 0xFFFF00FF | 0x6400;
  if ( (v59 & 0xFF0000) > 0x640000 )
    v59 = v59 & 0xFF00FFFF | 0x640000;
  v60 = v59 & 0xFFFFFF | 0x64000000;
  if ( v59 <= 0x64FFFFFF )
    v60 = v59;
  *((_DWORD *)a2 + 27) = v60;
  v61 = *(_DWORD *)(cfg_psoc_get_values(a1) + 1080);
  if ( (unsigned __int8)v61 > 0x64u )
    v61 = v61 & 0xFFFFFF00 | 0x64;
  if ( (v61 & 0xFF00) > 0x6400 )
    v61 = v61 & 0xFFFF00FF | 0x6400;
  if ( (v61 & 0xFF0000) > 0x640000 )
    v61 = v61 & 0xFF00FFFF | 0x640000;
  v62 = v61 & 0xFFFFFF | 0x64000000;
  if ( v61 <= 0x64FFFFFF )
    v62 = v61;
  *((_DWORD *)a2 + 28) = v62;
  v63 = *(_DWORD *)(cfg_psoc_get_values(a1) + 972);
  if ( (unsigned __int8)v63 > 0x64u )
    v63 = v63 & 0xFFFFFF00 | 0x64;
  if ( (v63 & 0xFF00) > 0x6400 )
    v63 = v63 & 0xFFFF00FF | 0x6400;
  if ( (v63 & 0xFF0000) > 0x640000 )
    v63 = v63 & 0xFF00FFFF | 0x640000;
  v64 = v63 & 0xFFFFFF | 0x64000000;
  if ( v63 <= 0x64FFFFFF )
    v64 = v63;
  *((_DWORD *)a2 + 29) = v64;
  result = cfg_psoc_get_values(a1);
  v66 = *(_DWORD *)(result + 1084);
  *((_DWORD *)a2 + 36) = 6566425;
  v67 = v66 & 0xFFFFFF00 | 0x64;
  if ( (unsigned __int8)v66 <= 0x64u )
    v67 = v66;
  if ( (v67 & 0xFF00) > 0x6400 )
    v67 = v67 & 0xFFFF00FF | 0x6400;
  if ( (v67 & 0xFF0000) > 0x640000 )
    v67 = v67 & 0xFF00FFFF | 0x640000;
  if ( v67 > 0x64FFFFFF )
    v67 = v67 & 0xFFFFFF | 0x64000000;
  *((_DWORD *)a2 + 30) = v67;
  a2[137] = 2;
  return result;
}
